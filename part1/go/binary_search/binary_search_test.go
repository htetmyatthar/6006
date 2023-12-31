package main

import "testing"

func TestBinarySearch(t *testing.T) {
	values := []int{0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 30, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100}

	// Tesing True positive.
	result, err := BinarySearch(values, 3)
	expected := true
	if result != expected && err != nil {
		t.Errorf("Expected: %v, result: %v, err: %v", expected, result, err)
	}

	// Testing False positive
	result1, err := BinarySearch(values, 9693)
	expected1 := false
	if result1 != expected1 && err != nil {
		t.Errorf("Expected: %v, result: %v, err: %v", expected1, result1, err)
	}

	// Testing error.
	result2, err := BinarySearch([]int{}, 4)
	if err == nil && result2 != false {
		t.Errorf("Expected to have an error. Result: %v, err: %v", result2, err)
	}
}
