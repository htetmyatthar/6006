package main

import (
	"errors"
	"testing"
)

func TestRadixSort(t *testing.T) {
	tests := []struct {
		name   string
		values []int
		sorted []int
		err    error
	}{
		{
			name:   "Empty array",
			values: []int{},
			sorted: []int{},
			err:    errors.New("Given array to sort is empty."),
		},
		{
			name:   "Array with one element",
			values: []int{5},
			sorted: []int{5},
			err:    errors.New("Given array is already sorted."),
		},
		{
			name:   "Array with repeated elements",
			values: []int{4, 2, 4, 1, 2, 1},
			sorted: []int{1, 1, 2, 2, 4, 4},
			err:    nil,
		},
		{
			name:   "Array with multiple digits",
			values: []int{123, 45, 678, 90, 543},
			sorted: []int{45, 90, 123, 543, 678},
			err:    nil,
		},
		// Add more test cases as needed
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			err := RadixSort(tt.values)

			if err != nil {
				if tt.err == nil || err.Error() != tt.err.Error() {
					t.Errorf("Unexpected error. Expected: %v, Got: %v", tt.err, err)
				}
				return
			}

			if tt.err != nil {
				t.Errorf("Expected an error, but got nil.")
				return
			}

			// Check if the array is sorted
			for i, v := range tt.sorted {
				if tt.values[i] != v {
					t.Errorf("Mismatch at index %d. Expected: %d, Got: %d", i, v, tt.values[i])
				}
			}
		})
	}
}
