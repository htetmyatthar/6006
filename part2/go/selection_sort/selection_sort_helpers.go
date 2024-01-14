package main

import "errors"

// SelectionSort sorts the given array.
// Returns error if the given array is empty.
func SelectionSort(array []int) error {
	length := len(array)

	if length == 0 {
		return errors.New("The given array is empty.")
	}

	for i := 0; i < length-1; i++ {
		for j := i + 1; j < length; j++ {
			if array[i] > array[j] {
				temp := array[j]
				array[j] = array[i]
				array[i] = temp
			}
		}
	}
	return nil
}
