package main

import (
	"fmt"
	"log"
)

func main(){
	fmt.Println("Initialized graph.")
	graph, err := InitGraph('a', 'b', 'c', 'd', 'e', 'f')
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	fmt.Println("Adding edges to the graph.")
	addEdges(graph, 'a', map[rune]int{
		'd': 0,
		'b': 0,
	})

	addEdges(graph, 'c', map[rune]int{
		'e': 0,
		'f': 0,
	})
	graph.AddEdge(0, 'b', 'e')
	graph.AddEdge(0, 'd', 'b')
	graph.AddEdge(0, 'e', 'd')
	graph.PrintAdjList()
	fmt.Println("-----------------------------------")

	fmt.Println("This is the dfs with source vertex a results.")
	parentVertices, order, err := graph.Dfs('a')
	if err != nil {
		log.Fatal(err)
	}
	printParents(parentVertices)
	fmt.Println("-----------------------------------")

	fmt.Println("This is the list of order from the source 'a'.")
	printOrder(order)
	fmt.Println("-----------------------------------")

	fmt.Println("This is the full dfs implementation results.")
	parentVertices, order, err = graph.FullDfs()
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("This is the list of parent vertices.")
	printParents(parentVertices)
	fmt.Println("-----------------------------------")

	fmt.Println("This is the list of order.")
	printOrder(order)
	fmt.Println("-----------------------------------")
}

// printParents prints out the parents of the vertices.
// no error checking included
func printParents(ParentVertices map[rune]rune){
	for vertex, parent := range ParentVertices{
		fmt.Printf("Vertex: %c, parent: %c\n", vertex, parent)
	}
}

func printOrder(ParentVertices []rune){
	length := len(ParentVertices)
	for i := length - 1; i >= 0; i--{
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
