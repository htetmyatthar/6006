package main

import (
	"fmt"
	"log"
)

func main() {
	values := []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	newSinglyLinkedList := &SinglyLinkedList{First: nil}
	err := newSinglyLinkedList.Build(values)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("original: %v\n", values)
	err = newSinglyLinkedList.PrintValues()
	if err != nil {
		log.Fatal(err)
	}
	printHr()

	node, err := newSinglyLinkedList.laterNode(3)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Node at index 3: %v\n", node.Value)
	printHr()

	fmt.Printf("SetAt: index 4 value 30\n")
	err = newSinglyLinkedList.SetAt(4, 30)
	if err != nil {
		log.Fatal(err)
	}
	err = newSinglyLinkedList.PrintValues()
	if err != nil {
		log.Fatal(err)
	}

	value, err := newSinglyLinkedList.GetAt(3)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Node at index GetAt(3)\n%v\n", value)

	value, err = newSinglyLinkedList.DeleteFirst()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Delete first:\n%v\n", value)

	fmt.Printf("Insert first 66:\n")
	newSinglyLinkedList.InsertFirst(66)
	err = newSinglyLinkedList.PrintValues()
	if err != nil {
		log.Fatal(err)
	}
	printHr()
}

func printHr() {
	for i := 0; i < 10; i++ {
		fmt.Printf("-------")
	}
	fmt.Println()
}
