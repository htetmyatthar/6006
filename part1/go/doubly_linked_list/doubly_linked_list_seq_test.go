package main

import (
	"testing"
)

var testStartValue = []int{1, 2, 3, 4, 5}

func TestDllBuild(t *testing.T) {
	dll := prepare()
	result := dll.Values()
	expected := testStartValue
	if !compareSlices(result, expected) {
		t.Errorf("returned %d, expected %d", result, expected)
	}
}

func TestDeleteFirst(t *testing.T) {
	dll := prepare()
	result, err := dll.DeleteFirst()
	if err != nil {
		t.Error(err)
	}
	expected := 1
	if result != expected {
		t.Errorf("returned %d, expected %d", result, expected)
	}
	result1 := dll.Values()
	expected1 := []int{2, 3, 4, 5}
	if !compareSlices(result1, expected1) {
		t.Errorf("returned %d, expected %d", result, expected)
	}
}

func TestDeleteLast(t *testing.T) {
	dll := prepare()
	result, err := dll.DeleteLast()
	if err != nil {
		t.Error(err)
	}
	expected := 5
	if result != expected {
		t.Errorf("returned %d, expected %d", result, expected)
	}
	result1 := dll.Values()
	expected1 := []int{1, 2, 3, 4}
	if !compareSlices(result1, expected1) {
		t.Errorf("returned %d, expected %d", result, expected)
	}
}

func TestInsertFirst(t *testing.T) {
	dll := prepare()
	dll.InsertFirst(10)
	result := dll.Values()
	expected := []int{10, 1, 2, 3, 4, 5}
	if !compareSlices(result, expected) {
		t.Errorf("returned %d, expected %d", result, expected)
	}
}

func TestInsertLast(t *testing.T) {
	dll := prepare()
	dll.InsertLast(8)
	result := dll.Values()
	expected := []int{1, 2, 3, 4, 5, 8}
	if !compareSlices(result, expected) {
		t.Errorf("returned %d, expected %d", result, expected)
	}
}

func TestGetAt(t *testing.T) {
	dll := prepare()
	value, err := dll.GetAt(2)
	if err != nil {
		t.Error(err)
	}
	expected := testStartValue[2]
	if value != expected {
		t.Errorf("returned %d, expected %d", value, expected)
	}
}

func TestSetAt(t *testing.T) {
	dll := prepare()
	err := dll.SetAt(2, 11)
	if err != nil {
		t.Error(err)
	}
	result, err := dll.GetAt(2)
	if err != nil {
		t.Error(err)
	}
	expected := 11
	if result != expected {
		t.Errorf("returned %d, expected %d", result, expected)
	}
}

func TestRemove(t *testing.T) {
	dll := prepare()
	removedDll := dll.Remove(dll.LaterNode(2), dll.LaterNode(3))
	result := removedDll.Values()
	expected := []int{3, 4}
	if !compareSlices(result, expected) {
		t.Errorf("returned %d, expected %d", result, expected)
	}
}

func TestSplice(t *testing.T) {
	dll := prepare()
	spliceDll := prepare()
	dll.Splice(dll.LaterNode(2), spliceDll)
	result := dll.Values()
	result1 := spliceDll.Values()
	expected := []int{1, 2, 3, 1, 2, 3, 4, 5}
	expected1 := []int{}
	if !compareSlices(result, expected) {
		t.Errorf("returned %d, expected %d", result, expected)
	}
	if !compareSlices(result1, expected1) {
		t.Errorf("returned %d, expected %d", result1, expected1)
	}
}

func compareSlices(first []int, second []int) bool {
	for i, value := range first {
		if value != second[i] {
			return false
		}
	}
	return true
}

func prepare() *DoublyLinkedList {
	dll := &DoublyLinkedList{}
	dll.Build(testStartValue)
	return dll
}
