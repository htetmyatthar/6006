package main

import (
	"fmt"
	"testing"
)

func TestSinglyLinkedList(t *testing.T) {
	list := &SinglyLinkedList{}

	// Test Case 1: Test PrintValues() method on an empty list
	err := list.PrintValues()
	if err != nil {
		t.Errorf("PrintValues() on an empty list should return an error, got: %v", err)
	}

	// Test Case 2: Test LaterNode() method on an empty list
	laterNode, err := list.laterNode(2)
	if laterNode != nil {
		t.Errorf("LaterNode() on an empty list should return nil, got: %v", laterNode)
	}

	// Test Case 3: Test Build() method
	valuesToBuild := []int{1, 2, 3}
	length := len(valuesToBuild)
	list.Build(valuesToBuild)
	var finger *SinglyLinkedListNode = list.First
	for i, v := range valuesToBuild {
		if finger.Value != valuesToBuild[(length-1)-i] {
			t.Errorf("Build() did not set the correct value at index %d, expected: %d, got: %d", i, v, finger.Value)
		}
		finger = finger.Next
	}

	// Test Case 4: Test SetAt() method
	err = list.SetAt(10, 44)
	if err == nil {
		t.Errorf("SetAt() should return an error for an index out of range")
	}

	// Test Case 6: Test GetAt() method
	value, err := list.GetAt(100)
	if err == nil {
		t.Errorf("GetAt() should return an error for an index out of range")
	}
	if value != 0 {
		t.Errorf("GetAt() should return 0 for an index out of range, got: %d", value)
	}

	// Test Case 7: Test DeleteFirst() method on an empty list
	_, err = list.DeleteFirst()
	if err != nil {
		t.Errorf("DeleteFirst() should not return an error")
	}

	// Test Case 8: Test InsertFirst() method
	list.InsertFirst(5)
	if list.First.Value != 5 {
		t.Errorf("InsertFirst() did not set the correct value, expected: 5, got: %d", list.First.Value)
	}

	// Test Case 9: Test SetAt() method on a non-empty list
	newList := &SinglyLinkedList{}
	newList.InsertFirst(10)
	err = newList.SetAt(0, 20)
	if err != nil {
		t.Errorf("SetAt() on a non-empty list should not return an error, got: %v", err)
	}
	// Check if the value is updated at the specified index
	if newList.First.Value != 20 {
		t.Errorf("SetAt() did not set the correct value, expected: 20, got: %d", list.First.Value)
	}

	// Test Case 10: Test DeleteFirst() method on a non-empty list
	newList1 := &SinglyLinkedList{}
	newList1.InsertFirst(10)
	deletedValue, err := newList1.DeleteFirst()
	if err != nil {
		t.Errorf("DeleteFirst() on a non-empty list should not return an error, got: %v", err)
	}
	// Check if the correct value is deleted
	if deletedValue != 10 {
		t.Errorf("DeleteFirst() did not return the correct value, expected: 10, got: %d", deletedValue)
	}
	// Check if the list is empty after deletion
	if newList1.First != nil {
		t.Errorf("DeleteFirst() did not empty the list, expected: nil, got: %v", list.First)
	}

	// Test Case 11: Test InsertFirst() method on an existing list
	newList2 := &SinglyLinkedList{}
	newList2.InsertFirst(10)
	newList2.InsertFirst(20)
	// Check if the head is correctly updated
	if newList2.First.Value != 20 {
		t.Errorf("InsertFirst() did not set the correct value at the head, expected: 20, got: %d", list.First.Value)
	}
	// Check if the rest of the list is correctly linked
	if newList2.First.Next.Value != 10 {
		t.Errorf("InsertFirst() did not correctly link the rest of the list, expected: 10, got: %d", list.First.Next.Value)
	}

	// Test Case 12: Test Values() method on a non-empty list
	newList3 := &SinglyLinkedList{}
	newList3.InsertFirst(10)
	newList3.InsertFirst(20)
	values := []int{}
	var finger1 *SinglyLinkedListNode = newList3.First
	for finger1 != nil {
		fmt.Println(finger1)
		values = append(values, finger1.Value)
		finger1 = finger1.Next
	}
	if len(values) != 2 || values[0] != 20 || values[1] != 10 {
		t.Errorf("Values() did not return the correct slice, expected: [20 10], got: %v", values)
	}
}
