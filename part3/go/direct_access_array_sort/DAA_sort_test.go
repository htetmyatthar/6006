package main

import (
	"reflect"
	"testing"
)

func TestDAASort(t *testing.T) {
	// Test case with a non-empty array
	testCase := []int{67, 13, 49, 24, 40, 33, 58}
	expectedResult := []int{13, 24, 33, 40, 49, 58, 67}

	err := DAASort(testCase)
	if err != nil {
		t.Errorf("Unexpected error: %v", err)
	}

	if !reflect.DeepEqual(testCase, expectedResult) {
		t.Errorf("Sorting failed. Expected: %v, Got: %v", expectedResult, testCase)
	}

	// Test case with an empty array
	emptyArray := []int{}
	err = DAASort(emptyArray)
	if err == nil {
		t.Error("Expected error for an empty array, but no error occurred.")
	}
}

func TestDAASortEdgeCases(t *testing.T) {
	// Test case with a single element
	singleElement := []int{5}
	expectedResult := []int{5}

	err := DAASort(singleElement)
	if err != nil {
		t.Errorf("Unexpected error: %v", err)
	}

	if !reflect.DeepEqual(singleElement, expectedResult) {
		t.Errorf("Sorting failed. Expected: %v, Got: %v", expectedResult, singleElement)
	}

	// Test case with all elements being the same
	sameElements := []int{7, 7, 7, 7, 7}
	expectedResultSame := []int{7, 7, 7, 7, 7}

	err = DAASort(sameElements)
	if err != nil {
		t.Errorf("Unexpected error: %v", err)
	}

	if !reflect.DeepEqual(sameElements, expectedResultSame) {
		t.Errorf("Sorting failed. Expected: %v, Got: %v", expectedResultSame, sameElements)
	}
}

/*
func TestDAASortNegativeNumbers(t *testing.T) {
	// Test case with negative numbers
	negativeNumbers := []int{-5, -2, -8, -1, -10}
	expectedResultNegative := []int{-10, -8, -5, -2, -1}

	err := DAASortAll(negativeNumbers)
	if err != nil {
		t.Errorf("Unexpected error: %v", err)
	}

	if !reflect.DeepEqual(negativeNumbers, expectedResultNegative) {
		t.Errorf("Sorting failed. Expected: %v, Got: %v", expectedResultNegative, negativeNumbers)
	}
}
*/
