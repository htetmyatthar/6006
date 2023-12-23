package main

import (
	"fmt"
	"log"
	"github.com/htetmyatthar/6006/ps1-template/doubly_linked_list"
)

func main() {
	newLinkedList := &doubly_linked_list.DoublyLinkedList{First: nil, Last: nil}
	values := []int{1, 3, 5, 2, 5}
	newLinkedList.Build(values)
	fmt.Print("build 1, 3, 5, 2, 5\n")
	fmt.Print("Created: ")
	err := newLinkedList.PrintValues()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Print("Get index 2")
	value, err := newLinkedList.GetAt(2)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("\n%d\n", value)

	fmt.Print("Set index 2 with value 10\n")
	newLinkedList.SetAt(2, 10)
	err = newLinkedList.PrintValues()
	if err != nil {
		fmt.Println(err)
	}

	fmt.Print("Insert Last the value 7\n")
	newLinkedList.InsertLast(7)
	err = newLinkedList.PrintValues()
	if err != nil {
		fmt.Println(err)
	}

	fmt.Print("Insert first the value 8\n")
	newLinkedList.InsertFirst(8)
	err = newLinkedList.PrintValues()
	if err != nil {
		fmt.Println(err)
	}

	fmt.Print("Delete first and get back the value\n")
	deletedValue, err := newLinkedList.DeleteFirst()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println("Value: ", deletedValue)
	// show again the current situation of the list
	err = newLinkedList.PrintValues()
	if err != nil {
		fmt.Println(err)
	}

	fmt.Print("Delete last and get back the value\n")
	// reassign to the existing one.
	deletedValue, err = newLinkedList.DeleteLast()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println("Value: ", deletedValue)
	// show again the current situation of the list
	err = newLinkedList.PrintValues()
	if err != nil {
		fmt.Println(err)
	}

	fmt.Println("Removed from 1st to 3rd element and return the the items in a new DLinkedList")
	RemovedList := newLinkedList.Remove(newLinkedList.LaterNode(1),newLinkedList.LaterNode(3))
	err = RemovedList.PrintValues()
	if err != nil {
		fmt.Println(err)
	}

	fmt.Println("Removed results of original Doubly Linked List.")
	err = newLinkedList.PrintValues()
	if err != nil {
		fmt.Println(err)
	}

	spliceNode := newLinkedList.LaterNode(1)
	fmt.Println("Splice Index Node's Value: ", spliceNode.Value)

	spliceDLinkedList := &doubly_linked_list.DoublyLinkedList{First: nil, Last: nil}
	spliceValues := []int{11, 14, 16, 1, 9}
	spliceDLinkedList.Build(spliceValues)
	fmt.Print("build 11, 14, 1, 9\n")
	fmt.Print("Created: ")
	err = spliceDLinkedList.PrintValues()
	if err != nil {
		fmt.Println(err)
	}

	newLinkedList.Splice(spliceNode, spliceDLinkedList)
	fmt.Println("Spliced doubly linked list join start from value 5")
	err = newLinkedList.PrintValues()
	if err != nil {
		fmt.Println(err)
	}
}
