// Sinly linked list related operations and interface.
package main

import (
	"errors"
	"fmt"
)

// definition of a singly linked-list node
type SinglyLinkedListNode struct {
	Value int
	Next  *SinglyLinkedListNode
}

// head of the singly linked-list
// we didn't make any augmentation, things like storing length or pointer to right most node
type SinglyLinkedList struct {
	First *SinglyLinkedListNode
}

// PrintValues prints out all the items' values of the SLinkedList
// Returns List is empty error if the SLinkedList is nil
func (SLinkedList *SinglyLinkedList) PrintValues() error {
	if SLinkedList == nil {
		return errors.New("List is empty.")
	}
	var finger *SinglyLinkedListNode = SLinkedList.First
	for finger != nil {
		fmt.Printf("%v->", finger.Value)
		finger = finger.Next
	}
	fmt.Println()
	return nil
}

// laterNode returns the node that is index of the SLinkedList with zero indexed.
// Returns the index's node and error. If SLinkedList is nil returns List is empty error.
// if the index is out of range List index out of range error is returned.
func (SLinkedList *SinglyLinkedList) laterNode(index int) (*SinglyLinkedListNode, error) {
	if SLinkedList == nil {
		return nil, errors.New("List is empty.")
	}

	counter := 0
	var node *SinglyLinkedListNode = SLinkedList.First
	for counter < index {
		if node == nil {
			return nil, errors.New("List index out of range.")
		}
		node = node.Next
		counter++
	}
	return node, nil
}

// Build method builds a new singly linked list
// Returns No values to buiild a linked list error  if the values is empty.
func (SLinkedList *SinglyLinkedList) Build(values []int) error {
	if SLinkedList == nil {
		return errors.New("Create a new struct to build.")
	}
	if len(values) < 0 {
		return errors.New("No values to build a linked list.")
	}
	for _, value := range values {
		newNode := &SinglyLinkedListNode{Value: value, Next: SLinkedList.First}
		SLinkedList.First = newNode
	}
	return nil
}

// SetAt method sets newValue at the index. Indexing starts from 0. This method depends on laterNode method.
// Returns List is empty if SLinkedList is nil, and List index out of range error if the index is out of range.
func (SLinkedList *SinglyLinkedList) SetAt(index int, newValue int) error {
	if SLinkedList == nil {
		return errors.New("List is empty.")
	}
	node, err := SLinkedList.laterNode(index)
	if err != nil {
		return err
	}
	node.Value = newValue
	return nil
}

// GetAt metod gets the value of the index of the SLinkedList.
// Returns List is empty error if SLinkedList is nil.
func (SLinkedList *SinglyLinkedList) GetAt(index int) (int, error) {
	if SLinkedList == nil {
		return 0, errors.New("List is empty.")
	}
	node, err := SLinkedList.laterNode(index)
	if err != nil {
		return 0, err
	}
	return node.Value, nil
}

// DeleteFirst method deletes the head of the list and returns the value of the deleted node.
// Returns List is empty error if SLinkedList is nil.
func (SLinkedList *SinglyLinkedList) DeleteFirst() (int, error) {
	if SLinkedList == nil {
		return 0, errors.New("List is empty.")
	}
	deleted_value := SLinkedList.First.Value
	SLinkedList.First = SLinkedList.First.Next
	return deleted_value, nil
}

// InsertFirst method inserts the node with the value i.
func (SLinkedList *SinglyLinkedList) InsertFirst(i int) {
	newNode := &SinglyLinkedListNode{Value: i, Next: SLinkedList.First}
	SLinkedList.First = newNode
}
