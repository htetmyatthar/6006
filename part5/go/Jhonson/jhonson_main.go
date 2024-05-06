package main

import (
	"fmt"
	"log"
	"math"
)

func main() {
	fmt.Println("Initialized graph.")
	graph, err := InitGraph('a', 'b', 'c', 'x', 'y', 'z')
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	fmt.Println("Adding edges to the graph.")
	graph.AddEdge(-2, 'a', 'b')
	graph.AddEdge(-1, 'b', 'c')
	addEdges(graph, 'c', map[rune]int{
		'a': 4,
		'x': 2,
		'y': -3,
	})
	addEdges(graph, 'z', map[rune]int{
		'x': 1,
		'y': -4,
	})
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	sdMatrix, err := graph.Jhonson()
	if err != nil {
		log.Fatal(err)
	}
	for vertex, sd := range sdMatrix {
		if vertex != '@' {
			// printPaths(sd)
			printShortestPaths(sd)
			fmt.Println("-----------------------------------")
		}
	}

	fmt.Println("checking that the edges are the original weights.")
	graph.PrintAdjList()
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
		if dn.Distance != math.Inf(0) {
			fmt.Printf("vertex: %c, path length: %f\n", dest, dn.Distance)
		}
	}
}

func printPaths(sd *ShortestDistance) {
	for vertex := range sd.Distances {
		sd.PrintPath(vertex)
	}
}
