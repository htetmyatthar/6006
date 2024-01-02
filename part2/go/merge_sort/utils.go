package main

// MergeSort sorts the given array or slice.
func MergeSort(array []int){
	MergeSortRange(array, 0, len(array) - 1)
}

// MergeSortRange sorts the given array or slice with the given range.
// Rnage should be 0 indexed.
func MergeSortRange(array []int, left int, right int){
	if left < right {
		middle := (left + right) / 2;
		
		MergeSortRange(array, left, middle)
		MergeSortRange(array, middle + 1, right)

		merge(array, middle, left, right)
	}
}

// merge function merge the given array used in MergeSort and MergeSortRange
func merge(array []int, middle int, left int, right int){
	left_length := middle - left + 1;
	right_length := right - middle;

	left_array := make([]int, left_length)
	right_array := make([]int, right_length)
	
	// copy the arrays;
	for i := 0; i < left_length; i++ {
		left_array[i] = array[left + i]
	}
	for j := 0; j < right_length; j++ {
		right_array[j] = array[middle + 1 + j]
	}

	var i, j int
	k := left
	for (i < left_length && j < right_length){
		if left_array[i] <= right_array[j]{
			array[k] = left_array[i]
			i++
		} else {
			array[k] = right_array[j]
			j++
		}
		k++
	}

	for i < left_length {
		array[k] = left_array[i]
		i++
		k++
	}

	for j < right_length {
		array[k] = right_array[j]
		j++
		k++
	}
}

