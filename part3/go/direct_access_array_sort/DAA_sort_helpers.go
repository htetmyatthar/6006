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
	for _, value := range values{
		if value > largestKey{
			largestKey = value
		}
	}

	maxKey := largestKey + 1

	// initialized to empty buckets.
	bucketArray := make([]int, maxKey)
	for i := 0; i < maxKey; i++ {
		bucketArray[i] = -1
	}

	// sort the values's items.
	for _, value := range values{
		bucketArray[value] = value
	}

	// overwrite to original array the sorted order.
	j := 0
	for i := range bucketArray{
		if bucketArray[i] > -1 {
			values[j] = bucketArray[i]
			j++
		}
	}
	return nil
}
