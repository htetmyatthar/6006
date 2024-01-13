package main

import "errors"


// bubble_sort sort sorts the given array.
// returns error if the given array is empty.
func BubbleSort(array []int) error {
	length := len(array)

	if length == 0 {
		return errors.New("The given array is empty.")
	}

	for i := 0; i < length; i++{
		for j := 0 ; j < length - i - 1; j++{
			if array[j] > array[j + 1]{
				temp := array[j]
				array[j] = array[j + 1]
				array[j + 1] = temp
			}
		}
	}
	return nil;
}
