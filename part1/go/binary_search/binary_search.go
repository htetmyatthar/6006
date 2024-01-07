package main

import "errors"

// Search the value in values slice, and returns a boolean.
// if the given values slice is empty Can't operate on empty slice error is returned.
func BinarySearch(values []int, value int) (bool, error) {
	if len(values) == 0 {
		return false, errors.New("Can't operate on empty slice.")
	}
	left := 0
	right := len(values) - 1

	for left <= right {
		// for preventing integer overflow, although go optimized for not overflowing.
		middle := left + ((right - left) / 2)
		if values[middle] == value {
			return true, nil
		} else if values[middle] < value {
			left = middle + 1
		} else if values[middle] > value {
			right = middle - 1
		}
	}
	return false, nil
}
