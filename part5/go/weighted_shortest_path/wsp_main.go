package main

import (
	"fmt"
	"log"
)

func main() {
	fmt.Println("Initialized graph.")
	graph, err := InitGraph('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h')
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	fmt.Println("Adding edges to the graph.")
	addEdges(graph, 'a', map[rune]int{
		'b': -5,
		'e': 7,
	})
	addEdges(graph, 'b', map[rune]int{
		'c': -1,
		'f': -4,
		'e': 6,
	})
	graph.AddEdge(5, 'd', 'c')
	graph.AddEdge(3, 'e', 'f')
	addEdges(graph, 'f', map[rune]int{
		'c': 8,
		'g': 2,
	})
	addEdges(graph, 'g', map[rune]int{
		'c': 1,
		'h': -2,
	})
	addEdges(graph, 'h', map[rune]int{
		'c': 9,
		'd': 4,
	})
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	sd, err := graph.DAGRelaxation('a')
	if err != nil {
		log.Fatal(err)
	}
	printShortestPaths(sd)
	fmt.Println("-----------------------------------")
	printPaths(sd)
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
