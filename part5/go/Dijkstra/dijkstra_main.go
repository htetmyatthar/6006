package main

import (
	"fmt"
	"log"
)

func main() {
	fmt.Println("Initialized graph.")
	graph, err := InitGraph('a', 'b', 'c', 'd', 's')
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	fmt.Println("Adding edges to the graph.")
	addEdges(graph, 's', map[rune]int{
		'a': 10,
		'c': 3,
	})
	addEdges(graph, 'a', map[rune]int{
		'b': 2,
		'c': 1,
	})
	addEdges(graph, 'c', map[rune]int{
		'a': 4,
		'b': 8,
		'd': 2,
	})
	graph.AddEdge(7, 'b', 'd')
	graph.AddEdge(5, 'd', 'b')
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	sd, err := graph.Dijkstra('s')
	if err != nil {
		log.Fatal(err)
	}
	printShortestPaths(sd)
	fmt.Println("-----------------------------------")
}

// printParents prints out the parents of the vertices.
// no error checking included
func printParents(ParentVertices map[rune]rune) {
	for vertex, parent := range ParentVertices {
		fmt.Printf("Vertex: %c, parent: %c\n", vertex, parent)
	}
}

func printOrder(ParentVertices []rune) {
	length := len(ParentVertices)
	for i := length - 1; i >= 0; i-- {
		fmt.Printf("Vertex: %c\n", ParentVertices[i])
	}
}

// addEdges add the edges to the given graph with the given values.
// no error checking included
func addEdges(G *Graph, src rune, edges map[rune]int) error {
	var err error
	for dest, weight := range edges {
		if err = G.AddEdge(weight, src, dest); err != nil {
			return err
		}
	}
	return nil
}

func printShortestPaths(sd *ShortestDistance) {
	fmt.Printf("Shortest paths from the source %c\n", sd.Src)
	for dest, dn := range sd.Distances {
		fmt.Printf("vertex: %c, path length: %f\n", dest, dn.Distance)
	}
}

func printPaths(sd *ShortestDistance) {
	for vertex := range sd.Distances {
		sd.PrintPath(vertex)
	}
}
