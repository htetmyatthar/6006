package main

import "fmt"

func main(){
	fmt.Println("Building a tree.")
	givenValues := [][]int{
		{1, 2},
		{3, 4},
		{5, 6},
		{7, 8},
		{9, 10},
	}
	var newTree *BinaryNode
	newTree.BuildTree(givenValues)
	fmt.Println(newTree)
}
