package main

import (
	"fmt"
	"log"
)

func main() {
	fmt.Println("Initialized graph that doesn't contain negative weight cycles.")
	graph, err := InitGraph('a', 'b', 'c', 'd', 'e', 'f', 'g', 's')
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	fmt.Println("Adding edges to the graph.")
	addEdges(graph, 's', map[rune]int{
		'e': 5,
		'f': 1,
		'g': 3,
	})

	addEdges(graph, 'e', map[rune]int{
		'f': -1,
		'a': 5,
		'g': 3,
	})

	addEdges(graph, 'f', map[rune]int{
		'e': 2,
		'g': 8,
	})

	graph.AddEdge(7, 'g', 'b')
	graph.AddEdge(1, 'a', 'b')
	addEdges(graph, 'b', map[rune]int{
		'c': -2,
		'e': -5,
	})
	graph.AddEdge(5, 'c', 'd')
	graph.AddEdge(3, 'd', 'b')
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	fmt.Println("Printing shortest path after bellman ford.")
	sd, err := graph.BellmanFord('s')
	if err != nil {
		log.Fatal("program ended.", err)
	}
	printShortestPaths(sd)
	fmt.Println("-----------------------------------")

	fmt.Println("Initialized graph that contains negative weight cycle")
	graph, err = InitGraph('a', 'b', 'c', 'd')
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	fmt.Println("Adding edges to the graph.")
	addEdges(graph, 'a', map[rune]int{
		'b': -5,
		'c': 6,
	})
	graph.AddEdge(-4, 'b', 'c')
	graph.AddEdge(3, 'c', 'd')
	graph.AddEdge(-1, 'd', 'b')
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	sd, err = graph.BellmanFord('a')
	if err != nil {
		log.Println(err)
	} else {
		printShortestPaths(sd)
	}
	fmt.Println("-----------------------------------")

	sd, cycle, err := graph.BellmanFordModified('a')
	if err != nil {
		log.Fatal(err)
	}
	printShortestPaths(sd)
	fmt.Println("Negative weight cycle vertices : ")
	for _, vertex := range cycle {
		fmt.Printf("| %c ", vertex)
	}
	fmt.Println()
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
