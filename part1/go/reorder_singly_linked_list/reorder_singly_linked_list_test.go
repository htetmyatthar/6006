package main

import (
	"reflect"
	"testing"
)

func TestSinglyLinkedList_Build(t *testing.T) {
	// Test case 1: Build with non-empty values
	values := []int{1, 2, 3, 4, 5}
	sLinkedList := &SinglyLinkedList{Head: nil}
	err := sLinkedList.Build(values)
	if err != nil {
		t.Errorf("Unexpected error: %v", err)
	}
	result := []int{}
	finger := sLinkedList.Head
	for finger != nil {
		result = append(result, finger.Value)
		finger = finger.Next
	}
	for i, value := range values {
		if value != result[(len(result)-1)-i] {
			t.Errorf("Build method did not produce the expected linked list. Got %v, expected %v", value, result[i])
		}
	}

	// Test case 2: Build with empty values
	emptyValues := []int{}
	expectedEmptyList := SinglyLinkedList{Head: nil}

	var emptySLinkedList SinglyLinkedList
	err = emptySLinkedList.Build(emptyValues)
	if err == nil {
		t.Errorf("Unexpected error: %v", err)
	}

	if !reflect.DeepEqual(emptySLinkedList, expectedEmptyList) {
		t.Errorf("Build method did not produce the expected empty linked list. Got %v, expected %v", emptySLinkedList, expectedEmptyList)
	}
}

type twoFinger struct {
	first  *SinglyLinkedListNode
	second *SinglyLinkedListNode
}

func TestSinglyLinkedList_HalfReverse(t *testing.T) {
	// Test case 1: HalfReverse with a valid length
	values := []int{1, 2, 3, 4, 5, 6}
	expectedList := SinglyLinkedList{Head: &SinglyLinkedListNode{Value: 6, Next: &SinglyLinkedListNode{Value: 5, Next: &SinglyLinkedListNode{Value: 4, Next: &SinglyLinkedListNode{Value: 1, Next: &SinglyLinkedListNode{Value: 2, Next: &SinglyLinkedListNode{Value: 3, Next: nil}}}}}}}

	var sLinkedList SinglyLinkedList
	sLinkedList.Build(values)

	err := sLinkedList.HalfReverse(6)
	if err != nil {
		t.Errorf("Unexpected error: %v", err)
	}

	finger := twoFinger{first: sLinkedList.Head, second: expectedList.Head}
	for finger.first != nil {
		if finger.first.Value != finger.second.Value {
			t.Errorf("HalfReverse method did not produce the expected linked list. Got %v, expected %v", finger.first.Value, finger.second.Value)
		}
		finger.first = finger.first.Next
		finger.second = finger.second.Next
	}

	// Test case 2: HalfReverse with an invalid length
	invalidLength := -1
	expectedListAfterInvalid := SinglyLinkedList{Head: &SinglyLinkedListNode{Value: 1, Next: &SinglyLinkedListNode{Value: 2, Next: &SinglyLinkedListNode{Value: 3, Next: &SinglyLinkedListNode{Value: 4, Next: &SinglyLinkedListNode{Value: 5, Next: nil}}}}}}

	err = expectedListAfterInvalid.HalfReverse(invalidLength)
	if err == nil {
		t.Error("Expected error for invalid length, but got none")
	}
}
