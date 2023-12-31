package main

import (
	"errors"
	"fmt"
)

// definition of a doubly linked-list node
type DoublyLinkedListNode struct {
	Value int
	Next  *DoublyLinkedListNode
	Prev  *DoublyLinkedListNode
}

// linked-list identifier
type DoublyLinkedList struct {
	First *DoublyLinkedListNode
	Last  *DoublyLinkedListNode
}

// just for testing only.
func (DLinkedList *DoublyLinkedList) Values() []int {
	valuesList := []int{}
	current := DLinkedList.First
	for current != nil {
		valuesList = append(valuesList, current.Value)
		current = current.Next
    }
	fmt.Print(valuesList)
	return valuesList
}

// Print out the values of the Doubly Linked list
// returns error if the list is not exists or the list is not connected
func (DLinkedList *DoublyLinkedList) PrintValues() error {
	// if the list is the empty
	if DLinkedList == nil {
		err := errors.New("DoublyLinkedList not exists.")
		return err
		// if the list is not connected
	} else if DLinkedList.First == nil {
		err := errors.New("DoublyLinkedList index out of range.")
		return err
	} else {
		current := DLinkedList.First
		for current != nil {
			fmt.Print(current.Value, " ")
			current = current.Next
		}
		fmt.Println()
	}
	return nil
}

// Create a new node with the value n and return the address of it.
func (DoublyLinkedList *DoublyLinkedList) CreateNode(n int) *DoublyLinkedListNode {
	return &DoublyLinkedListNode{
		Value: n,
		Next:  nil,
		Prev:  nil,
	}
}

// This function is for doubly linked list that store first and last in a struct
// this function iterates through the list and returns the nth node.
// returns nil if the linked list is nil or the linked list is index out of range
func (DoublyLinkedList *DoublyLinkedList) LaterNode(n int) *DoublyLinkedListNode {
	current := DoublyLinkedList.First
	for i := 0; i < n; i++ {
		if current == nil || current.Next == nil {
			return nil
		}
		current = current.Next
	}
	return current
}

// Add a new DoublyLinkedListNode to the DoublyLinkedList.
// Takes a parameter to add as a value.
func (DLinkedList *DoublyLinkedList) InsertLast(i int) {
	newNode := DLinkedList.CreateNode(i)
	// if the list is an empty one just make the list first to the added node.
	if DLinkedList.Last == nil {
		DLinkedList.First = newNode
	} else {
		DLinkedList.Last.Next = newNode
		newNode.Prev = DLinkedList.Last
	}
	DLinkedList.Last = newNode
}

// Build a new DoublyLinkedList for the given int slice if the DoublyLinkedList is
// not created yet create a new DoublyLinkedList identifier
func (DLinkedList *DoublyLinkedList) Build(values []int) *DoublyLinkedList {
	firstNode := DoublyLinkedListNode{Value: values[0], Next: nil, Prev: nil}
	DLinkedList.First = &firstNode
	DLinkedList.Last = DLinkedList.First
	// add the values to it
	length := len(values)
	for i := 1; i < length; i++ {
		DLinkedList.InsertLast(values[i])
	}
	return DLinkedList
}

// Set newValue in DoublyLinkedList's Index returns error if there's no node
// at the given Index.
func (DLinkedList *DoublyLinkedList) SetAt(Index int, newValue int) error {
	node := DLinkedList.LaterNode(Index)
	if node == nil {
		err := errors.New("DoublyLinkedList index out of range")
		return err
	}
	node.Value = newValue
	return nil
}

// Get the value of DoublyLinkedList's Index.
// returns an error if the Index is out of range
func (DLinkedList *DoublyLinkedList) GetAt(Index int) (int, error) {
	node := DLinkedList.LaterNode(Index)
	if node == nil {
		err := errors.New("DoublyLinkedList index out of range")
		return 0, err
	}
	return node.Value, nil
}

// This function insert the number i in to the first of DLinkedList
func (DLinkedList *DoublyLinkedList) InsertFirst(i int) {
	newNode := DLinkedList.CreateNode(i)
	// if the list is an empty one just make the list first to the added node.
	if DLinkedList.First == nil {
		DLinkedList.Last = newNode
	} else {
		DLinkedList.First.Prev = newNode
		newNode.Next = DLinkedList.First
	}
	DLinkedList.First = newNode
}

// DeleteFirst delete the first element of the doubly linked list
// and returns the deleted value.
func (DLinkedList *DoublyLinkedList) DeleteFirst() (int, error) {
	if DLinkedList.First == nil {
		err := errors.New("DoublyLinkedList index out of range")
		return 0, err
	}
	x := DLinkedList.First.Value
	DLinkedList.First = DLinkedList.First.Next
	// if this is the end of the list the last element pointer should also be nil.
	// which is empty.
	if DLinkedList.First == nil {
		DLinkedList.Last = nil
	} else {
		// this is the start of the list.
		DLinkedList.First.Prev = nil
	}
	return x, nil
}

// DeleteLast delete the last element of the doubly linked list
// and returns the deleted value.
func (DLinkedList *DoublyLinkedList) DeleteLast() (int, error) {
	if DLinkedList.Last == nil {
		err := errors.New("DoublyLinkedList index out of range")
		return 0, err
	}
	x := DLinkedList.Last.Value
	DLinkedList.Last = DLinkedList.Last.Prev
	// if there's no first element in the list the first element pointer should also be nil
	// which is empty
	if DLinkedList.Last == nil {
		DLinkedList.First = nil
	} else {
		// this is the end of the list
		DLinkedList.Last.Next = nil
	}
	return x, nil
}

// Remove the elements between the startNode and endNode inclusively using memory address.
// and returns the removed elements in a new doubly linked list
// in the process removed the elements from the original doubly linked list
func (DLinkedList *DoublyLinkedList) Remove(startNode *DoublyLinkedListNode, endNode *DoublyLinkedListNode) *DoublyLinkedList {
	// initialize a new doubly linked list
	NewDlinkedList := &DoublyLinkedList{First: DLinkedList.First, Last: DLinkedList.Last}
	NewDlinkedList.First = startNode
	NewDlinkedList.Last = endNode

	// if this is the startNode is the first element
	// there's nothing left before the startNode
	if startNode == DLinkedList.First {
		DLinkedList.First = endNode.Next
		// else something left, join the node before
		// startNode to the endNode's Next
	} else {
		startNode.Prev.Next = endNode.Next
	}

	// If this is the endNode is the last element
	// there's nothing left after the endNode
	if endNode == DLinkedList.Last {
		DLinkedList.Last = startNode.Prev
		// there's something left after the endNode
		// Join endnode's next to the startNode's previous
	} else {
		endNode.Next.Prev = startNode.Prev
	}

	// to make the startNode and endNode as the first and last element
	// of the new DLinkedList
	startNode.Prev = nil
	endNode.Next = nil

	return NewDlinkedList
}

// Splice the two doubly linked list in the node of the original doubly linked list
// expects a doubly linked list that needs to splice.
// In the process the parameter list will be empty and caller list contains all the elements
// in the order.
func (DLinkedList *DoublyLinkedList) Splice(node *DoublyLinkedListNode, NewDLinkedList *DoublyLinkedList) {
	startSplit := node.Next

	a := NewDLinkedList.First
	b := NewDLinkedList.Last
	NewDLinkedList.First = nil
	NewDLinkedList.Last = nil

	a.Prev = node
	node.Next = a
	// if the next element exists
	if startSplit != nil {
		startSplit.Prev = nil
	}
	DLinkedList.Last = b
}
