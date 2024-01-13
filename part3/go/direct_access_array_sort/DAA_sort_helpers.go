package main

import "errors"

// DAASort sorts the given slice. Returns error if the given values slice is empty.
// Only the values n_i >= 0 can be sorted with DAASort.
func DAASort(values []int) error{
	length := len(values)

	if length == 0 {
		return errors.New("The given array to sort is empty.")
	}

	// find the largest key in the values slice.
	largestKey := -1;
	for i := 0; i < length; i++{
		if values[i] > largestKey{
			largestKey = values[i]
		}
	}

	maxKey := largestKey + 1

	// initialized to empty buckets.
	bucketArray := make([]int, maxKey)
	for i := 0; i < maxKey; i++ {
		bucketArray[i] = -1
	}

	// sort the values's items.
	for i := 0; i < length; i++{
		bucketArray[values[i]] = values[i]
	}

	// overwrite to original array the sorted order.
	for i, j := 0, 0; i < maxKey; i++{
		if bucketArray[i] > -1 {
			values[j] = bucketArray[i]
			j++
		}
	}
	return nil
}
