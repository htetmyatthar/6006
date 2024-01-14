package main

import (
	"reflect"
	"testing"
)

func TestBubbleSort(t *testing.T) {
	testCases := []struct {
		name     string
		input    []int
		expected []int
	}{
		{
			name:     "Empty array",
			input:    []int{},
			expected: []int{},
		},
		{
			name:     "Already sorted array",
			input:    []int{1, 2, 3, 4, 5},
			expected: []int{1, 2, 3, 4, 5},
		},
		{
			name:     "Reverse-sorted array",
			input:    []int{5, 4, 3, 2, 1},
			expected: []int{1, 2, 3, 4, 5},
		},
		{
			name:     "Array with duplicate elements",
			input:    []int{3, 2, 1, 2, 3},
			expected: []int{1, 2, 2, 3, 3},
		},
		{
			name:     "Random order array",
			input:    []int{4, 1, 7, 3, 9, 2},
			expected: []int{1, 2, 3, 4, 7, 9},
		},
	}

	for _, tc := range testCases {
		t.Run(tc.name, func(t *testing.T) {
			// Make a copy of the input array to compare the result
			inputCopy := make([]int, len(tc.input))
			copy(inputCopy, tc.input)

			BubbleSort(tc.input)

			if !reflect.DeepEqual(tc.input, tc.expected) {
				t.Errorf("BubbleSort(%v) = %v, expected %v", inputCopy, tc.input, tc.expected)
			}
		})
	}
}

func TestBubbleSortError(t *testing.T) {
	// Test case with an empty array
	testCase := []int{}
	err := BubbleSort(testCase)
	if err == nil {
		t.Error("Expected error but the error doesn't happened.")
	}

	// Test case with a non-empty array
	testCase1 := []int{3, 1, 2}
	err = BubbleSort(testCase1)
	if err != nil {
		t.Errorf("Expected no error but the error happened %v", err)
	}
}
