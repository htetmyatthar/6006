package main

import (
	"container/list"
	"errors"
	"math"
)

var ErrNegativeWeightCycle = errors.New("There's negative weight cycle in the graph.")

// returns the shortest paths for every vertices by calculating each vertex as a source.
func (G *Graph) Jhonson() (map[rune]*ShortestDistance, error) {
	if G == nil {
		return nil, ErrGraphNil
	}

	// NOTE: creating the super node and adding edges to it.

	// creating a super node.
	superName := '@'
	superNode := &Vertix{
		indegree:   0,
		outDegree:  G.totalVertices,
		vertixName: superName,
		edges:      list.New(),
	}

	// newTotalVertices is the number of total vertices after creating the super node.
	// don't ever touch this variable.
	newTotalVertices := G.totalVertices + 1

	sd := &ShortestDistance{Src: superName, Distances: make(map[rune]*DistanceNode, newTotalVertices)}
	for vertexName := range G.adjList {
		// add the zero weight edges from super to every vertices to
		// get the shortest path tree with potentials.
		superNode.edges.PushBack(&Edge{
			vertixName: vertexName,
			weight:     0,
		})
		// initialize everything to +infinity
		sd.Distances[vertexName] = &DistanceNode{Distance: math.Inf(0)}
	}
	// init the source(super)
	sd.Distances[superName] = &DistanceNode{Distance: 0, ParentVertex: superName}

	// NOTE: Bellman-Ford for early exists if there are negative weight cycles.
	// and getting the shortest path tree to use as potentials.

	// relax all the edges |v| - 1 rounds where v is the newTotalVertices.
	// small v for indicating this is not G.totalVertices
	for range newTotalVertices - 1 {
		// relax every adj+ in the superNode
		for e := superNode.edges.Front(); e != nil; e = e.Next() {
			edge := e.Value.(*Edge)
			estDistance := sd.Distances[superName].Distance + float64(edge.weight)
			if sd.Distances[edge.vertixName].Distance > estDistance {
				sd.Distances[edge.vertixName].Distance = estDistance
				sd.Distances[edge.vertixName].ParentVertex = superName
			}
		}
		// relax every adj+ in the graph
		for srcName, vertex := range G.adjList {
			for e := vertex.edges.Front(); e != nil; e = e.Next() {
				edge := e.Value.(*Edge)
				destName := edge.vertixName
				estDistance := sd.Distances[srcName].Distance + float64(edge.weight)
				if sd.Distances[destName].Distance > estDistance {
					sd.Distances[destName].Distance = estDistance
					sd.Distances[destName].ParentVertex = srcName
				}
			}
		}
	}

	// relax |v|th round of all the adj+ of supernode. early exists.
	for e := superNode.edges.Front(); e != nil; e = e.Next() {
		edge := e.Value.(*Edge)
		if sd.Distances[edge.vertixName].Distance > sd.Distances[superName].Distance+float64(edge.weight) {
			return nil, ErrNegativeWeightCycle
		}
	}

	// relax |v|th round of all the adj+ of the graph.
	for srcName, vertex := range G.adjList {
		for e := vertex.edges.Front(); e != nil; e = e.Next() {
			edge := e.Value.(*Edge)
			if sd.Distances[edge.vertixName].Distance > sd.Distances[srcName].Distance+float64(edge.weight) {
				return nil, ErrNegativeWeightCycle
			}
		}
	}

	// NOTE: reweight the edges by adding the potentials.
	for vertexName, vertex := range G.adjList {
		for e := vertex.edges.Front(); e != nil; e = e.Next() {
			edge := e.Value.(*Edge)
			edge.weight = edge.weight + int(sd.Distances[vertexName].Distance) - int(sd.Distances[edge.vertixName].Distance)
			// fmt.Println("src:", vertexName, "dest", edge.vertixName, int(sd.Distances[vertexName].Distance), int(sd.Distances[edge.vertixName].Distance))
		}
	} // don't forget to change this graph to normal.

	// whatever happens inside this function make the graph back to normal.
	return func(G *Graph) (map[rune]*ShortestDistance, error) {
		// NOTE: reweight the edges by removing the potentials to get back to normal.
		defer func() {
			for vertexName, vertex := range G.adjList {
				for e := vertex.edges.Front(); e != nil; e = e.Next() {
					edge := e.Value.(*Edge)
					edge.weight = edge.weight - int(sd.Distances[vertexName].Distance) + int(sd.Distances[edge.vertixName].Distance)
					// fmt.Println("reversed", int(sd.Distances[vertexName].Distance), int(sd.Distances[edge.vertixName].Distance))
				}
			}
		}()

		sdMatrix := make(map[rune]*ShortestDistance, G.totalVertices)
		// NOTE: running Dijkstra algorithm for every vertices.
		for srcName := range G.adjList {
			var err error
			sdMatrix[srcName], err = G.Dijkstra(srcName)
			if err != nil {
				return nil, err
			}
			// remove the potentials to get the real weights for shortest paths.
			for destName := range G.adjList {
				sdMatrix[srcName].Distances[destName].Distance = sdMatrix[srcName].Distances[destName].Distance - sd.Distances[srcName].Distance + sd.Distances[destName].Distance
				// fmt.Println("must src: ", srcName, "dest: ", destName, int(sd.Distances[destName].Distance), int(sd.Distances[srcName].Distance))
			}
		}
		return sdMatrix, nil
	}(G)
}
