package main

import (
	"fmt"
	"log"
)

func main() {
	fmt.Println("Building a tree.")
	givenValues := [][]int{
		{1, 2},
		{3, 4},
		{5, 6},
		{7, 8},
		{9, 10},
		{11, 12},
		{13, 14},
	}
	var newTree *BinaryNode
	newTree, err := newTree.BuildTree(givenValues)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Inorder traversal order: ")
	newTree.PrintTraversal()
	fmt.Println("---------------------------------------------")
	fmt.Println("Preorder traversal order: ")
	newTree.PrintPreOrder()
	fmt.Println("---------------------------------------------")

	fmt.Println("Finding the node with the key 1.")
	node, err := newTree.Find(1)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Found Node: \nvalue: %d, key: %d, height: %d\n", node.Value, node.Key, node.Height)
	fmt.Println("---------------------------------------------")

	fmt.Println("First node for in-order traversal order:")
	firstNode := newTree.SubtreeFirst()
	fmt.Printf("Found Node: \nvalue: %d, key: %d, height: %d\n", firstNode.Value, firstNode.Key, firstNode.Height)
	fmt.Println("---------------------------------------------")

	fmt.Println("last node for in-order traversal order:")
	lastNode := newTree.SubtreeLast()
	fmt.Printf("Found Node: \nvalue: %d, key: %d, height: %d\n", lastNode.Value, lastNode.Key, lastNode.Height)
	fmt.Println("---------------------------------------------")

	rootSkew, err := newTree.Skew()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Skew and Height of the root node: %d, %d \n", rootSkew, newTree.Height)
	fmt.Println("---------------------------------------------")

	fmt.Println("Right rotating the root tree:")
	fmt.Println("Org tree: ")
	newTree.PrintPreOrder()
	newRoot, err := newTree.SubtreeRotateRight()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("\nRight Rotated tree: ")
	newRoot.PrintPreOrder()
	fmt.Println("---------------------------------------------")

	fmt.Println("Left rotating the root tree:")
	fmt.Println("Org tree: ")
	newRoot.PrintPreOrder()
	newTree, err = newRoot.SubtreeRotateLeft()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("\nLeft Rotated tree: ")
	newTree.PrintPreOrder()
	fmt.Println("---------------------------------------------")

	fmt.Println("Inserting a new node with the key 8 and value 99 after node with key 7.")
	node, err = newTree.Find(7)
	if err != nil {
		log.Fatal(err)
	}
	err = newTree.InsertAfter(node, 99, 8)
	if err != nil {
		log.Fatal(err)
	}
	newTree.PrintPreOrder()
	fmt.Println("---------------------------------------------")

	fmt.Println("Inserting a new node with the key 10 and value 77 before node with key 11.")
	node, err = newTree.Find(11)
	if err != nil {
		log.Fatal(err)
	}
	err = newTree.InsertBefore(node, 77, 10)
	if err != nil {
		log.Fatal(err)
	}
	newTree.PrintPreOrder()
	fmt.Println("---------------------------------------------")

	fmt.Println("Deleting nodes with the key of 1 and 5.")
	newTree, value, err := newTree.Delete(1)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("\ndeleted node's value:", value)
	newTree, value, err = newTree.Delete(5)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("\ndeleted node's value:", value)
	fmt.Println("\ndeleted final tree:")
	newTree.PrintPreOrder()
	fmt.Println("---------------------------------------------")

	fmt.Println("Inserting a new node automatically and maintain balance")
	newTree, err = newTree.Insert(4, 1000)
	if err != nil {
		log.Fatal(err)
	}
	newTree.PrintPreOrder()
	fmt.Println("---------------------------------------------")
}
