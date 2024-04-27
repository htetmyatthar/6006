package main

import (
	l "container/list"
	"errors"
)

// FIX: HOW TO KNOW WHICH TYPE OF ELEMENT IN THE LIST.ELEMENT.VALUE?? HOW TO USE LIST PROPERLY?
// NOTE: You can do type assertions to the empty interface{} or any as follows:
// e.(Edge).weight, where e is any or empty interface{}
// this means extracting the Edge from the empty interface if it is, else panic.

// Graph represents a graph that has |V| of vertices
// and |E| number of edges. A graph is represented in a adjacency
// list, using linked list to store the edges as values of adj map and
// vertices as keys of the adj map.
type Graph struct {
	totalVertices int
	adjList       map[rune]*Vertix
}

// Vertix represents a vertix in a graph.
// This type is used as a key for the adjacency list map in the Graph.
type Vertix struct {
	indegree   int
	outDegree  int
	vertixName rune
	edges      *l.List
}

// Edge represents an edge between two vertices.
// This type is used as a value inside Edges linked list, which
// are the list of edges of a vertix in the adjacency list map in the Graph
type Edge struct {
	weight     int
	vertixName rune
}

// Init initialize a graph with the given vertices if there are any.
func InitGraph(names ...rune) (*Graph, error) {
	nVertices := len(names)
	// checking the duplicate vertix names.
	nameMap := make(map[rune]struct{}, nVertices)
	for _, name := range names {
		if _, ok := nameMap[name]; ok {
			return nil, errors.New("Invalid vertix names. There's a duplicate name.")
		}
		nameMap[name] = struct{}{}
	}
	// init graph with the given vertices.
	graph := &Graph{
		totalVertices: nVertices,
		adjList:       make(map[rune]*Vertix, nVertices),
	}
	for _, name := range names {
		vertix := &Vertix{vertixName: name, edges: l.New()}
		graph.adjList[name] = vertix
	}
	return graph, nil
}

// AddVertix create a vertix and adds that to the graph
// and returns the modified graph
func (G *Graph) AddVertix(name rune) error {
	// check that the name is already in the graph
	if _, exists := G.adjList[name]; exists {
		return errors.New("Invalid vertix name. There's already a vertix with the given name.")
	}
	G.totalVertices++
	vertix := &Vertix{vertixName: name, edges: l.New()}
	G.adjList[name] = vertix
	return nil
}

func (G *Graph) RemoveVertix(name rune) error {
	if _, exists := G.adjList[name]; !exists {
		return errors.New("Invalid vertix name. There's no vertix with the given dest.")
	}
	// TODO: remove the vertix
	return nil
}

// AddEdge adds an edge to the given graph
func (G *Graph) AddEdge(weight int, src, dest rune) error {
	if _, exists := G.adjList[src]; !exists {
		return errors.New("Invalid src vertix name. There's no vertix with the given src.")
	} else if _, exists = G.adjList[dest]; !exists {
		return errors.New("Invalid dest vertix name. There's no vertix with the given dest.")
	}
	edge := &Edge{weight: weight, vertixName: dest}
	G.adjList[dest].indegree++
	G.adjList[src].outDegree++
	G.adjList[src].edges.PushBack(edge)
	return nil
}

func (G *Graph) RemoveEdge(src, dest rune) error {
	if _, exists := G.adjList[src]; !exists {
		return errors.New("Invalid vertix name. There's no vertix with the given dest.")
	} 
	for e := G.adjList[src].edges.Front(); e != nil; e.Next(){
		// FIND THE ELEMENT FIRST.
	}
	return nil
}

// GetIndegree gets the indegree of the given vertix
func (G *Graph) GetIndegree(name rune) (int, error) {
	var vertix *Vertix
	var ok bool
	if vertix, ok = G.adjList[name]; !ok {
		return 0, errors.New("Invalid vertix name. There's no vertix with the given name.")
	}
	return vertix.indegree, nil
}

// GetOutdegree gets the indegree of the given vertix
func (G *Graph) GetOutdegree(name rune) (int, error) {
	var vertix *Vertix
	var ok bool
	if vertix, ok = G.adjList[name]; !ok {
		return 0, errors.New("Invalid vertix name. There's no vertix with the given name.")
	}
	return vertix.outDegree, nil
}

// GetInNeighbors gets the incoming neighbors of the given vertix
func (G *Graph) GetInNeighbors(vertix rune)

// GetOutNeighbors gets the outgoing neighbors of the given vertix
func (G *Graph) GetOutNeighbors(vertix rune)

// PrintAdjList prints out the adjacency list to the stdout.
func (G *Graph) PrintAdjList()
