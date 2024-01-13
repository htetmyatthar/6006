package main

import "errors"

func InsertionSort(array []int) error{
	length := len(array)

	if length == 0{
		return errors.New("The given array is empty.")
	}

	for i := 1; i < length; i++{
		j := i;
		for j > 0 && (array[j - 1] > array[j]) {
			temp := array[j]
			array[j] = array[j - 1]
			array[j - 1] = temp
			
			j = j - 1
		}
	}
	return nil
}
