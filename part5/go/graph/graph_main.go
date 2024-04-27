package main

import (
	"fmt"
	"log"
)

func main() {
	fmt.Println("initializing a new graph")
	graph, err := InitGraph('a', 'b', 'c')
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-------------------------")

	fmt.Println("Adding edges to the graph.")
	edges := map[rune]int{
		'b': 3,
		'c': -1,
	}
	err = addEdges(graph, 'a', edges)
	if err != nil {
		log.Fatal(err)
	}
	edges = map[rune]int{
		'a': 30,
		'b': 0,
	}
	err = addEdges(graph, 'c', edges)
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-------------------------")

	fmt.Println("Adding vertices to the graph.")
	err = graph.AddVertix('d')
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-------------------------")

	fmt.Println("Removing an edge from the graph.")
	err = graph.RemoveEdge('a', 'b')
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-------------------------")

	fmt.Println("Removing a vertix from the graph.")
	err = graph.RemoveVertix('a')
	if err != nil {
		log.Fatal(err)
	}
	graph.PrintAdjList()
	fmt.Println("-------------------------")
}

type Person struct {
	name string
	age  int
}

// AddEdges add the edges in the given
func addEdges(G *Graph, src rune, edges map[rune]int) error {
	var err error
	for dest, weight := range edges {
		if err = G.AddEdge(weight, src, dest); err != nil{
			return err
		}
	}
	return nil
}
