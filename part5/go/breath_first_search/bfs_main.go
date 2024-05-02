package main

import (
	"fmt"
	"log"
)

func main() {
	graph, err := InitGraph('a', 'x', 'c', 'd', 'v', 'f', 's', 'z')
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	addEdges(graph, 's', map[rune]int{
		'a': 0,
		'x': 0,
	})

	addEdges(graph, 'a', map[rune]int{
		's': 0,
		'z': 0,
	})

	addEdges(graph, 'z', map[rune]int{
		'a': 0,
	})

	addEdges(graph, 'x', map[rune]int{
		's': 0,
		'd': 0,
		'c': 0,
	})

	addEdges(graph, 'd', map[rune]int{
		'x': 0,
		'f': 0,
	})

	addEdges(graph, 'c', map[rune]int{
		'f': 0,
		'x': 0,
		'v': 0,
	})

	addEdges(graph, 'f', map[rune]int{
		'd': 0,
		'c': 0,
		'v': 0,
	})

	addEdges(graph, 'v', map[rune]int{
		'f': 0,
		'c': 0,
	})
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	parentVertices, err := graph.Bfs('s')
	if err != nil {
		log.Fatal(err)
	}
	printParents(parentVertices)
	fmt.Println("-----------------------------------")

	findPaths(graph, map[rune]rune{
		's' : 'c',
		'z' : 'f',
		'f' : 's',
		'v' : 's',
	})
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

// printParents prints out the parents of the vertices.
// no error checking included
func printParents(ParentVertices map[rune]rune){
	for vertex, parent := range ParentVertices{
		fmt.Printf("Vertex: %c, parent: %c\n", vertex, parent)
	}
}

// findPaths finds one of the shortest path from src(key) to the dest(value).
// no error checking included
func findPaths(G *Graph, vertexMap map[rune]rune){
	for key, value := range vertexMap{
		path, err := G.FindPath(key, value)
		if err != nil {
			log.Fatal(err)
		}
		for _, value := range path{
			fmt.Printf("%c -> ", value)
		}
		fmt.Println()
		fmt.Println("-----------------------------------")
	}
}
