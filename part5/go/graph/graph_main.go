package main

import "fmt"

func main() {
	fmt.Println("Hello, world");
	graph, err := InitGraph()
	if err != nil {
		fmt.Println(err)
	}
	graph.AddEdge(3, 'a', 'b')
}

// AddEdges add the edges in the given
func (G *Graph) addEdges(src rune, edges map[rune]int){
	for dest, weight := range edges{
		G.AddEdge(weight, src, dest)
	}
}
