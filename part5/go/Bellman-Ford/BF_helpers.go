package main

import (
	"errors"
	"fmt"
	"math"
)

var ErrNegativeWeightCycle = errors.New("There's negative weight cycle in the graph.")

// BellmanFord is the Bellman-Ford graph algorithm for finding out
// negative weight cycle in a graph in the path of the src vertex.
// Returns an error if there's a negative weight cycle in the caller graph.
func (G *Graph) BellmanFord(src rune) (*ShortestDistance, error) {
	if G == nil {
		return nil, ErrGraphNil
	}
	var exists bool
	if _, exists = G.adjList[src]; !exists {
		return nil, ErrVertexNotFound
	}

	sd := &ShortestDistance{Src: src, Distances: make(map[rune]*DistanceNode, G.totalVertices)}
	// initialize everything to +infinity. -infinity is for negative weight cycles.
	for vertex := range G.adjList {
		sd.Distances[vertex] = &DistanceNode{Distance: math.Inf(0)}
	}
	sd.Distances[src] = &DistanceNode{ParentVertex: src, Distance: 0.0}

	// NOTE: relax all edges in (|V| - 1) rounds.
	for range G.totalVertices - 1 { // need go 1.22 for this syntax. see go.mod
		for vertex := range G.adjList {
			for e := G.adjList[vertex].edges.Front(); e != nil; e = e.Next() {
				G.tryToRelax(sd, vertex, e.Value.(*Edge))
			}
		}
	}

	// NOTE: relax |V| round
	for vertex := range G.adjList {
		for e := G.adjList[vertex].edges.Front(); e != nil; e = e.Next() {
			dest := e.Value.(*Edge)
			// if d[v] > d[u] + w(u, v)
			if sd.Distances[dest.vertixName].Distance > (sd.Distances[vertex].Distance + float64(dest.weight)) {
				return nil, ErrNegativeWeightCycle
			}
		}
	}
	return sd, nil
}

// BellmanFordModified is the modified Bellman-Ford graph algorithm that can returns
// the negative weight cycle in the graph instead of just returning error for presence of
// negative weight cycle.
//
// Returns the shortest distances and if there's a negative weight cycle, marks -infinity to all
// those vertices that are in the negative weight cycle.
//
// Also returns the negative weight cycle vertices as a slice of rune(vertices' names).
//
// Returns an error if there's any.
func (G *Graph) BellmanFordModified(src rune) (*ShortestDistance, []rune, error) {
	if G == nil {
		return nil, nil, ErrGraphNil
	}
	var exists bool
	if _, exists = G.adjList[src]; !exists {
		return nil, nil, ErrVertexNotFound
	}
	// NOTE: duplicate the graph and transformed it into the versioned one.
	dupG, err := G.UpgradeToVersionGraph()
	if err != nil {
		return nil, nil, err
	}
	// uncomment to see the duplicated (and also versioned) graph.
	// dupG.PrintVersionedGraph()

	// NOTE: run DAG relaxation on the versioned graph.
	sdMatrix, err := dupG.DAGRelaxation(src)
	if err != nil {
		return nil, nil, err
	}
	sd := &ShortestDistance{Src: src, Distances: make(map[rune]*DistanceNode, G.totalEdges)}
	for vertexName := range G.adjList {
		sd.Distances[vertexName] = &DistanceNode{}
	}

	// NOTE: set the shortest distance to be the |V|th version shortest distances.
	totalVertices := G.totalVertices
	for vertexName := range G.adjList {
		sd.Distances[vertexName].Distance = sdMatrix[totalVertices-1][vertexName].Distance
		sd.Distances[vertexName].ParentVertex = sdMatrix[totalVertices-1][vertexName].ParentVertex
	}
	negativeWeightCycle := make([]rune, 0, G.totalVertices/2) // intialization
	// NOTE: finding the negative weight cycle witness and marking every reachable vertices from it as -infinity.
	for vertexName := range G.adjList {
		// if the |V| + 1 layer vertices has any negative weight cycle witness.
		if sdMatrix[totalVertices][vertexName].Distance < sdMatrix[totalVertices-1][vertexName].Distance {
			// mark all reachable vertices from that witness as negative infinity.
			_, reachableVertices, err := G.Dfs(vertexName)
			if err != nil {
				return nil, nil, err
			}
			for _, reachableVertex := range reachableVertices {
				sd.Distances[reachableVertex].Distance = math.Inf(-1)
				sd.Distances[reachableVertex].ParentVertex = 0 // set there's no parent for this.
				negativeWeightCycle = append(negativeWeightCycle, reachableVertex)
			}
		}
	}
	return sd, negativeWeightCycle, nil
}

// VersionedVertices is a duplicate vertices of the same vertices.
// index is the version identifier of the vertex.
//
// see also VersionedGraph.
type VersionedVertices []*VersionedVertex

// VersionedVertex is a duplicate vertex of the same vertex.
//
// see also VersionedVertices
type VersionedVertex struct {
	InDegree   int              // in degree of the VersionedVertex
	OutDegree  int              // out degree of the VersionedVertex
	VertexName rune             // name of the VersionedVertex
	Edges      []*VersionedEdge // edges of the VersionedVertex
}

// VersionedEdge is an edge that also stores the version or level
// of the edge of the duplciated VersionedGraph.
//
// see also VersionedVertex
type VersionedEdge struct {
	Version    int  // version or level of the edge.
	Weight     int  // weight of the edge.
	VertexName rune // name of the dest VersionedVertex.
}

// VersionedGraph is a duplicated graph of the original graph
// duplicated(versioned) in the following way:
//
// 1. There'll be |V| + 1 version for every vertex.
//
// 2. There'll be zero weight edges from version to version.
//
// 3. Vertices from the same version will not have edges to each other.
//
// 4. Every edge of one version will be connected to the next version.
//
// 5. Each vertices will have own adj list.
type VersionedGraph map[rune]VersionedVertices

// UpgradeToVersionGraph upgrades the caller graph to a new VersionedGraph(graph with levels).
// In the process the caller graph doesn't changed, and a new VersionedGraph is returned.
// Returns an error if there's any.
func (G *Graph) UpgradeToVersionGraph() (VersionedGraph, error) {
	// allocate the heads first
	vg := make(VersionedGraph, G.totalVertices)
	for vertexName, vertex := range G.adjList {
		// allocated |V| + 1 layer
		vg[vertexName] = make(VersionedVertices, G.totalVertices+1, G.totalVertices+1) // index out of bound careful
		// for the first |V| version of the graph, index i is the version
		for i := range G.totalVertices {
			verEdges := make([]*VersionedEdge, 0, vertex.outDegree)
			verEdges = append(verEdges, &VersionedEdge{ // adding zero weight edges.
				Version:    i + 1,
				VertexName: vertexName,
				Weight:     0,
			})

			// duplicate the edges from 0 up to |V| version
			for e := vertex.edges.Front(); e != nil; e = e.Next() {
				// adding the edges of one's version to point to the another version.
				edge := e.Value.(*Edge)
				verEdge := &VersionedEdge{
					Version:    i + 1,
					Weight:     edge.weight,
					VertexName: edge.vertixName,
				}
				verEdges = append(verEdges, verEdge)
			}
			vg[vertexName][i] = &VersionedVertex{ // copy the in and out degrees and name.
				VertexName: vertexName,
				InDegree:   vertex.indegree,
				OutDegree:  vertex.outDegree,
				Edges:      verEdges,
			}
		}

		// for the first version of the graph indegree is zero.
		vg[vertexName][0].InDegree = 0

		// for the last version of the graph the out degree is zero.
		vg[vertexName][G.totalVertices] = &VersionedVertex{ // we allocated G.totalVertices+1 so last is G.totalVertices
			VertexName: vertexName,
			InDegree:   vertex.indegree,
			OutDegree:  0,
			Edges:      nil,
		}
	}
	return vg, nil
}

// DAGRelaxation relax the edges of the caller VersionedGraph returning the
// shortest distances but in a versioned way. In the returning a slice of map,
// index of the slice is the version and the map is the shortest distance of each
// vertex from the src.
func (vg VersionedGraph) DAGRelaxation(src rune) ([]map[rune]*DistanceNode, error) {
	queue, err := vg.Dfs(src)
	if err != nil {
		return nil, err
	}

	// uncomment to see the topological order.
	// for _, node := range queue { fmt.Printf("node level: %d, node vertex: %c\n", node.Level, node.VertexName) }

	totalVersions := len(vg) + 1
	sd := make([]map[rune]*DistanceNode, totalVersions, totalVersions)
	for i := range sd { // intialize to infinity
		sd[i] = make(map[rune]*DistanceNode, len(vg))
		for vertexName := range vg {
			sd[i][vertexName] = &DistanceNode{Distance: math.Inf(0)}
		}
	}
	// initliazation
	sd[0][src].Distance = 0.0
	sd[0][src].ParentVertex = src

	// for every vertices in the topo sort order.
	for i := len(queue) - 1; i >= 0; i-- {
		// if there's edges to relax for the vertex.
		srcName := queue[i].VertexName
		srcLevel := queue[i].Level
		vertex := vg[srcName][srcLevel]
		if vertex.Edges != nil {
			// for every edges in the vertex.
			for i := range vertex.Edges {
				// weight of the edge.
				weight := float64(vertex.Edges[i].Weight)
				destName := vertex.Edges[i].VertexName
				destLevel := vertex.Edges[i].Version
				// d[v] > d[u] + w(u, v)
				if sd[destLevel][destName].Distance > (sd[srcLevel][srcName].Distance + weight) {
					sd[destLevel][destName].Distance = sd[srcLevel][srcName].Distance + weight
					sd[destLevel][destName].ParentVertex = srcName
				}
			}
		}
	}
	return sd, nil
}

// topoNode is to store the topological order of the versioned graph's dfs algorithm.
type TopoNode struct {
	VertexName rune // name of the vertex of the TopoNode
	Level      int  // level(version) of the TopoNode
}

// Dfs method returns the topological order of the caller VersionedGraph,
// returning the topological order. Returns an error if there's any.
// see also DAGRelaxation method.
func (vg VersionedGraph) Dfs(src rune) ([]TopoNode, error) {
	if vg == nil {
		return nil, ErrGraphNil
	}
	var verVertices VersionedVertices
	var exists bool
	if verVertices, exists = vg[src]; !exists {
		return nil, ErrVertexNotFound
	}
	// leastCap is at least the number of edges of the src addition to
	// zero weight edges multiply by the level.
	leastCap := len(vg) + 1*(len(verVertices[0].Edges)+len(vg))
	queue := make([]TopoNode, 0, leastCap)
	parentVertices := make([]map[rune]rune, len(vg)+1, leastCap) // index as the level
	for i := range parentVertices {                              // initialize all the maps.
		parentVertices[i] = make(map[rune]rune)
	}

	queue = vg.dfsRecursion(&TopoNode{VertexName: src, Level: 0}, queue, parentVertices)

	return queue, nil
}

// dfsRecursion method is the helper method for the Dfs method of the VersionedGraph.
// this method runs the depth first seach algorihm for the VersionedGraph returning
// the topological order of the VersionedGraph.
func (vg VersionedGraph) dfsRecursion(srcNode *TopoNode, queue []TopoNode, parentVertices []map[rune]rune) []TopoNode {
	srcVertex := vg[srcNode.VertexName][srcNode.Level]
	// only explore till there are things to be explored.
	if srcVertex.Edges != nil {
		// for every outgoing edges including the zero weight edges.
		for i := range srcVertex.OutDegree + 1 {
			edgeLevel := srcVertex.Edges[i].Version
			edgeName := srcVertex.Edges[i].VertexName
			// if there's an edge with this.
			if _, exists := parentVertices[edgeLevel][edgeName]; !exists {
				parentVertices[edgeLevel][edgeName] = srcNode.VertexName
				queue = vg.dfsRecursion(&TopoNode{VertexName: edgeName, Level: edgeLevel}, queue, parentVertices)
			}
		}
	}
	queue = append(queue, *srcNode)
	return queue
}

// PrintVersionedGraph method prints out the VersionedGraph.
func (vg VersionedGraph) PrintVersionedGraph() {
	// for every vertices.
	fmt.Println("This is the versioned duplicated graph.")
	for vertexName, vertex := range vg {
		// for every level of a vertex
		for level, levelVertex := range vertex {
			fmt.Printf("vertiex %c with level %d\n", vertexName, level)
			// for every edges of that levelVertex
			for i := len(levelVertex.Edges) - 1; i >= 0; i-- {
				edge := levelVertex.Edges[i]
				fmt.Printf("outneighbor: %c, level: %d, weight: %d\t", edge.VertexName, edge.Version, edge.Weight)
			}
			fmt.Println()
		}
		fmt.Println("-----------------------------------")
	}
}
