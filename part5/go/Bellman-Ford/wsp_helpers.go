package main

import (
	"fmt"
	"math"
)

type ShortestDistance struct {
	Src       rune                   // src vertex for this shortest distances.
	Distances map[rune]*DistanceNode // distances from the src to the reachable vertices.
}

// Len method returns the number of vertices reachable from the src vertex.
func (s *ShortestDistance) Len() int {
	return len(s.Distances)
}

func (s *ShortestDistance) PrintPath(dest rune) error {
	var dn *DistanceNode
	var exists bool
	if dn, exists = s.Distances[dest]; !exists {
		return ErrVertexNotFound
	}

	fmt.Printf("Path from %c to %c:\n", s.Src, dest)
	var print func(node *DistanceNode)
	// print the parents until it's the source.
	print = func(node *DistanceNode) {
		if node == nil || node.ParentVertex == s.Src {
			fmt.Printf("%c", node.ParentVertex)
			return
		}
		print(s.Distances[node.ParentVertex])
		fmt.Printf(" -> %c", node.ParentVertex)
		return
	}
	print(dn)
	fmt.Printf(" -> %c", dest)
	fmt.Println() // blank line to skip
	return nil
}

// DistanceNode is to use with [ShortestDistance].
type DistanceNode struct {
	ParentVertex rune    // parent vertex of the vertex.
	Distance     float64 // distance from the src to the dest.
}

// DAGRelaxation finds the weighted shortest paths
// from the src vertex.
func (G *Graph) DAGRelaxation(src rune) (*ShortestDistance, error) {
	if G == nil {
		return nil, ErrGraphNil
	}
	var exists bool
	if _, exists = G.adjList[src]; !exists {
		return nil, ErrVertexNotFound
	}
	// run dfs from the src.
	_, topoOrder, err := G.Dfs(src)
	printOrder(topoOrder)
	if err != nil {
		return nil, err
	}
	sd := &ShortestDistance{Src: src, Distances: make(map[rune]*DistanceNode, len(topoOrder))}

	// initialize the shortest distances to the inf for every vertices in topoOrder.
	// -infinity is for negative weight cycles and in DAG there's no negative weight cycles.
	for _, vertex := range topoOrder {
		sd.Distances[vertex] = &DistanceNode{Distance: math.Inf(0)}
	}

	// add the source vertex.
	sd.Distances[src] = &DistanceNode{ParentVertex: src, Distance: 0.0}

	// for every vertices in topo sort.
	for i := len(topoOrder) - 1; i >= 0; i-- {
		// for every adj^+ of current vertex
		for e := G.adjList[topoOrder[i]].edges.Front(); e != nil; e = e.Next() {
			G.tryToRelax(sd, topoOrder[i], e.Value.(*Edge))
		}
	}
	return sd, nil
}

func (G *Graph) tryToRelax(sd *ShortestDistance, src rune, destNode *Edge) bool {

	// find the edgeweight from src to dest.
	// vertices exists or not are already checked in dfs.
	var edgeWeight float64
	dest := destNode.vertixName
	if src == dest {
		edgeWeight = 0.0
	} else {
		edgeWeight = float64(destNode.weight)
	}

	// if d[v] > d[u] + w(u, v)
	if sd.Distances[dest].Distance > (sd.Distances[src].Distance + edgeWeight) {
		sd.Distances[dest].Distance = sd.Distances[src].Distance + edgeWeight
		sd.Distances[dest].ParentVertex = src
		return true // relaxation happened.
	}
	return false // no relaxation happened
}
