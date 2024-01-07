package main

import "errors"

func BinarySearch(values []int, value int)(bool, error){
	if len(values) == 0{
		return false, errors.New("Can't operate on empty slice.")
	}
	left := 0;
	right := len(values) - 1;

	for(left <= right) {
		middle := left + ((right - left) / 2)
		if values[middle] == value{
			return true, nil
		} else if values[middle] < value {
			left = middle + 1;
		} else if values[middle] > value {
			right = middle - 1;
		}
	}
	return false, nil
}
