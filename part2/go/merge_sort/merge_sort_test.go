package main

import (
	"reflect"
	"testing"
)

func TestMergeSort(t *testing.T){
	// Test Case 1: Random unsorted integers
	input1 := []int{38, 27, 43, 3, 9, 82, 10}
	expected1 := []int{3, 9, 10, 27, 38, 43, 82}
	testCase(t, input1, expected1)

	// Test Case 2: Already sorted integers
	input2 := []int{1, 2, 3, 4, 5, 6, 7}
	expected2 := []int{1, 2, 3, 4, 5, 6, 7}
	testCase(t, input2, expected2)

	// Test Case 3: Reverse sorted integers
	input3 := []int{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	expected3 := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	testCase(t, input3, expected3)

	// Test Case 4: Duplicate integers
	input4 := []int{5, 2, 9, 2, 0, 5}
	expected4 := []int{0, 2, 2, 5, 5, 9}
	testCase(t, input4, expected4)

	// Test Case 5: Empty slice
	input5 := []int{}
	expected5 := []int{}
	testCase(t, input5, expected5)
}

func testCase(t *testing.T, input []int, expected []int){
	MergeSort(input)
	if !reflect.DeepEqual(input, expected){
		t.Errorf("Expected: %v but got %v", expected, input)
	}
}

func TestMergeSortRange(t *testing.T){
	// Test Case 1: Random unsorted integers
	input1 := []int{38, 27, 43, 3, 9, 82, 10}
	expected1 := []int{38, 27, 3, 9, 43, 82, 10}
	testCase1(t, input1, expected1, 2, 5)

	// Test Case 2: Already sorted integers
	input2 := []int{1, 2, 3, 4, 5, 6, 7}
	expected2 := []int{1, 2, 3, 4, 5, 6, 7}
	testCase1(t, input2, expected2, 2, 6)

	// Test Case 3: Reverse sorted integers
	input3 := []int{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	expected3 := []int{10, 9, 1, 2, 3, 4, 5, 6, 7, 8}
	testCase1(t, input3, expected3, 2, 9)

	// Test Case 4: Duplicate integers
	input4 := []int{5, 2, 9, 2, 0, 5}
	expected4 := []int{5, 2, 0, 2, 5, 9}
	testCase1(t, input4, expected4, 2, 5)

	/*
	// Test Case 5: Empty slice
	input5 := []int{}
	expected5 := []int{}
	testCase1(t, input5, expected5, 2, 5)
	*/
}

func testCase1(t *testing.T, input []int, expected []int, left int, right int){
	MergeSortRange(input, left, right)
	if !reflect.DeepEqual(input, expected){
		t.Errorf("Expected: %v, Result: %v", expected, input)
	}
}
