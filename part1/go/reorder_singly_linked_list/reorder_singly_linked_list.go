package main

import "errors"

// node definition of singly linked list node
type SinglyLinkedListNode struct {
	Value int
	Next  *SinglyLinkedListNode
}

// head of the singly linked list.
type SinglyLinkedList struct {
	Head *SinglyLinkedListNode
}

// SLinkedList.Build method builds the singly linked list with the given slice of values
// Returns No values to build singly linked list if the value is empty.
func (SLinkedList *SinglyLinkedList) Build(values []int) error {
	if len(values) < 1 || values == nil {
		return errors.New("No values to build singly linked list.")
	}
	for _, value := range values {
		newNode := &SinglyLinkedListNode{Value: value, Next: SLinkedList.Head}
		SLinkedList.Head = newNode
	}
	return nil
}

// SLinkedList.HalfReverse method reverse the later half of the SLinkedList.
// Returns The linked list is empty if SLinkedList.Head is nil.
// Returns The given length can't be reversed if length is < 1.
func (SLinkedList *SinglyLinkedList) HalfReverse(length int) error {
	if SLinkedList.Head == nil {
		return errors.New("The linked list is empty.")
	}
	if length < 1 {
		return errors.New("The given length can't be reversed.")
	}

	middle := (length / 2)

	current := SLinkedList.Head
	for n := 0; n < middle-1; n++ {
		current = current.Next
	}
	// current is now the last element of the first half

	pre_node := current.Next
	rev_node := pre_node.Next
	post_node := rev_node.Next

	// reverse the array until the post node gone after the last.
	for post_node != nil {
		rev_node.Next = pre_node

		pre_node = rev_node
		rev_node = post_node
		post_node = post_node.Next
	}

	// reverse the last 2 pointer.
	rev_node.Next = pre_node

	// clean up the mess relink the linked list.order is important
	current.Next.Next = nil
	current.Next = rev_node
	return nil
}
