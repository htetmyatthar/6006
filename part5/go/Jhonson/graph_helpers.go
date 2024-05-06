package main

import (
	l "container/list"
	"errors"
	"fmt"
)

var (
	ErrDuplicateVertix   = errors.New("Invalid vertix name. There's a duplicate name.")
	ErrVertexNotFound    = errors.New("Invalid vertix name. There's no vertix with the given name.")
	ErrEdgeNotFound      = errors.New("Invalid edge (dest) name. There's no edge with the given (dest) name from source.")
	ErrSelfEdge          = errors.New("Invalid edge. Self edges are not allowed.")
	ErrGraphNil          = errors.New("Nil graph can't call this method.")
	ErrSuperNodeOccupied = errors.New("Can't use '@' as node. '@' is a unique identifier for super nodes.")
)

// FIX: HOW TO KNOW WHICH TYPE OF ELEMENT IN THE LIST.ELEMENT.VALUE?? HOW TO USE LIST PROPERLY?
// NOTE: You can do type assertions to the empty interface{} or any as follows:
// e.(*Edge).weight, where e is any or empty interface{}
// this means extracting the Edge from the empty interface if it is, else panic.

// Graph represents a graph that has |V| of vertices
// and |E| number of edges. A graph is represented in a adjacency
// list, using linked list to store the edges as values of adj map and
// vertices as keys of the adj map. This graph implementation is
// the directed graph implementation.
type Graph struct {
	totalVertices int
	totalEdges    int
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

	nameMap := make(map[rune]struct{}, nVertices)
	for _, name := range names {
		if _, exists := nameMap[name]; exists {
			return nil, ErrDuplicateVertix
		} else if name == '@' {	// added only for the JHONSON's algorithm.
			return nil, ErrSuperNodeOccupied
		}
		nameMap[name] = struct{}{}
	}

	graph := &Graph{
		totalVertices: nVertices,
		adjList:       make(map[rune]*Vertix, nVertices),
	}

	for _, name := range names {
		graph.adjList[name] = &Vertix{vertixName: name, edges: l.New()}
	}
	return graph, nil
}

// Density returns the current directed graph's density.
// The greater it approaches to the 1 the denser and vice versa.
func (G *Graph) Density() (float32, error) {
	if G == nil {
		return 0.0, ErrGraphNil
	}
	maxEdges := G.totalVertices * (G.totalVertices - 1)
	return float32(G.totalEdges) / float32(maxEdges), nil
}

// AddVertix create a vertix and adds that to the graph
func (G *Graph) AddVertix(name rune) error {
	if G == nil {
		return ErrGraphNil
	}
	if _, exists := G.adjList[name]; exists {
		return ErrDuplicateVertix
	}
	G.totalVertices++
	G.adjList[name] = &Vertix{vertixName: name, edges: l.New()}
	return nil
}

// RemoveVertix removes a vertix from the graph and the edges that is realted to the vertix.
func (G *Graph) RemoveVertix(name rune) error {
	if G == nil {
		return ErrGraphNil
	}
	var vertix *Vertix
	var exists bool

	if vertix, exists = G.adjList[name]; !exists {
		return ErrVertexNotFound
	}

	// for every outgoing edges from this vertix
	for e := vertix.edges.Front(); e != nil; e = e.Next() {
		G.adjList[e.Value.(*Edge).vertixName].indegree--
		G.totalEdges--
	}
	G.totalVertices--
	// NOTE: removing a vertix effectively removes every edge that is associated with it.
	delete(G.adjList, name)

	// for every incoming edges to this vertix
	for _, value := range G.adjList {
		for e := value.edges.Front(); e != nil; e = e.Next() {
			if e.Value.(*Edge).vertixName == name {
				value.outDegree--
				G.totalEdges--
				value.edges.Remove(e)
			}
		}
	}
	return nil
}

// AddEdge adds an edge to the given graph
func (G *Graph) AddEdge(weight int, src, dest rune) error {
	if G == nil {
		return ErrGraphNil
	}
	var srcVertix *Vertix
	var destVertix *Vertix
	var exists bool

	if src == dest {
		return ErrSelfEdge
	} else if srcVertix, exists = G.adjList[src]; !exists {
		return ErrVertexNotFound
	} else if destVertix, exists = G.adjList[dest]; !exists {
		return ErrVertexNotFound
	}
	G.totalEdges++
	destVertix.indegree++
	srcVertix.outDegree++
	srcVertix.edges.PushBack(&Edge{weight: weight, vertixName: dest})
	return nil
}

func (G *Graph) RemoveEdge(src, dest rune) error {
	if G == nil {
		return ErrGraphNil
	}
	var srcVertix *Vertix
	var destVertix *Vertix
	var exists bool

	if src == dest {
		return ErrSelfEdge
	} else if destVertix, exists = G.adjList[dest]; !exists {
		return ErrVertexNotFound
	} else if srcVertix, exists = G.adjList[src]; !exists {
		return ErrVertexNotFound
	}
	for e := srcVertix.edges.Front(); e != nil; e = e.Next() {
		if e.Value.(*Edge).vertixName == dest {
			srcVertix.edges.Remove(e)
			break
		}
	}
	G.totalEdges--
	destVertix.indegree--
	srcVertix.outDegree--
	return nil
}

// GetIndegree gets the indegree of the given vertix
func (G *Graph) GetIndegree(name rune) (int, error) {
	if G == nil {
		return 0, ErrGraphNil
	}
	var vertix *Vertix
	var ok bool
	if vertix, ok = G.adjList[name]; !ok {
		return 0, ErrVertexNotFound
	}
	return vertix.indegree, nil
}

// GetOutdegree gets the indegree of the given vertix
func (G *Graph) GetOutdegree(name rune) (int, error) {
	if G == nil {
		return 0, ErrGraphNil
	}
	var vertix *Vertix
	var ok bool
	if vertix, ok = G.adjList[name]; !ok {
		return 0, ErrVertexNotFound
	}
	return vertix.outDegree, nil
}

// GetInNeighbors gets the incoming neighbors of the given vertix
func (G *Graph) GetInNeighbors(name rune) ([]rune, error) {
	if G == nil {
		return nil, ErrGraphNil
	}
	var vertix *Vertix
	var ok bool
	if vertix, ok = G.adjList[name]; !ok {
		return nil, ErrVertexNotFound
	}
	neighbors := make([]rune, 0, vertix.indegree)
	for key, value := range G.adjList {
		for e := value.edges.Front(); e != nil; e = e.Next() {
			if e.Value.(*Edge).vertixName == name {
				neighbors = append(neighbors, key)
				break
			}
		}
	}
	return neighbors, nil
}

// GetOutNeighbors gets the outgoing neighbors of the given vertix
func (G *Graph) GetOutNeighbors(name rune) ([]rune, error) {
	if G == nil {
		return nil, ErrGraphNil
	}
	var vertix *Vertix
	var ok bool
	if vertix, ok = G.adjList[name]; !ok {
		return nil, ErrVertexNotFound
	}
	neighbors := make([]rune, 0, vertix.outDegree)
	for e := vertix.edges.Front(); e != nil; e = e.Next() {
		neighbors = append(neighbors, e.Value.(*Edge).vertixName)
	}
	return neighbors, nil
}

// PrintAdjList prints out the adjacency list to the stdout.
func (G *Graph) PrintAdjList() error {
	if G == nil {
		return ErrGraphNil
	}
	density, err := G.Density()
	if err != nil {
		return err
	}
	fmt.Println("Density:", density)
	for key, value := range G.adjList {
		fmt.Printf("Vertix: %c, InDeg: %v, OutDeg: %v\n Edges:", key, value.indegree, value.outDegree)
		for e := value.edges.Front(); e != nil; e = e.Next() {
			edge := e.Value.(*Edge)
			fmt.Printf(" %c(w: %v),", edge.vertixName, edge.weight)
		}
		fmt.Println()
	}
	return nil
}

// GetWeight gets the weight of the edge from src to the dest vertex in O(n).
// returns 0 if src and dest is the same and it's O(1).
// returns an error if src or dest vertice(s) is not in the caller Graph.
func (G *Graph) GetWeight(src, dest rune) (int, error) {
	var srcVertex *Vertix
	var exists bool
	if _, exists = G.adjList[dest]; !exists {
		fmt.Println("error happened.")
		return 0, ErrVertexNotFound
	} else if srcVertex, exists = G.adjList[src]; !exists { // you idiot you laid dest instead of src in here.
		fmt.Println("error happened.")
		return 0, ErrVertexNotFound
	}

	if src == dest {
		fmt.Println("error happened.")
		return 0, nil
	}

	e := srcVertex.edges.Front()
	for e != nil && e.Value.(*Edge).vertixName != dest {
		e = e.Next()
	}

	if e == nil {
		return 0, ErrEdgeNotFound
	}
	return e.Value.(*Edge).weight, nil
}
