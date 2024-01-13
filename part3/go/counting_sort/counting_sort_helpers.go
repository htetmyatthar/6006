package main

import "errors"

type Tuple struct {
	OriginalValue int
	First int
	Second int
	Next *Tuple
}

// CountingSortChain sorts the given values array using chaining method.
// Returns error if the given values array is empty.
func CountingSortChain(values []int) error {
	length := len(values)
	if length == 0{
		return errors.New("Given array to sort is empty.\n")
	}

	// transformed from decimal values to tuple values.
	tupleArray := make([]*Tuple, length)
	for i, value := range values{
		newTuple := &Tuple{
			OriginalValue: value,
			First: value / length,
			Second: value % length,
			Next: nil,
		}
		tupleArray[i] = newTuple
	}

	// since we moded with length the max key would be length.
	maxKey := length
	countArrayLeast := make([]int, maxKey)
	// count the least significant digits.
	for _, value := range tupleArray{
		countArrayLeast[value.Second]++
	}

	// cummulative sum least significant digits.
	for i := 1; i < maxKey; i++{
		countArrayLeast[i] += countArrayLeast[i - 1]
	}

	// sort the least significant digit.
	sortedArrayLeast := make([]*Tuple, length)
	// we have to brough up i because we have to mess with the original array of tuples not just the copy value.
	for i, value := range tupleArray{
		sortedArrayLeast[countArrayLeast[value.Second] - 1] = tupleArray[i]
		countArrayLeast[value.Second]--
	}

	// find the largest key in more significant digits
	largestMoreSignificant := -1
	for _, value := range sortedArrayLeast{
		if value.First > largestMoreSignificant{
			largestMoreSignificant = value.First
		}
	}

	// chain with a sequence data structure using hashing like practices.
	maxKeyMoreSignificant := largestMoreSignificant + 1
	sortedArrayFully := make([]*Tuple, maxKeyMoreSignificant)
	// we have to brough up i because we have to mess with the original array tuples not just the copy value.
	for i ,value := range sortedArrayLeast {
		// linking hash array and nodes like linked list.
		sortedArrayLeast[i].Next = sortedArrayFully[value.First]
		sortedArrayFully[value.First] = sortedArrayLeast[i]
	}

	// overwriting the sorted array.
	for i, j := maxKeyMoreSignificant - 1, length - 1; i >= 0; i--{
		finger := sortedArrayFully[i]
		for finger != nil {
			values[j] = finger.OriginalValue
			finger = finger.Next
			j--;
		}
	}
	return nil
}

// CountingSortSum sorts the given values array using cummulative summing method.
// Returns error if the given values array is empty.
func CountingSortSum(values []int) error{
	length := len(values)
	if length == 0{
		return errors.New("Given array to sort is empty.\n")
	}
	// find the largest key
	largestKey := -1
	for _, value := range values{
		if value > largestKey{
			largestKey = value
		}
	}

	maxKey := largestKey + 1
	// already initialize to zeros.
	countArray := make([]int, maxKey)
	// count the occurence.
	for _, value := range values{
		countArray[value]++
	}

	// calculate cummulative sum
	for i := 1; i < maxKey; i++{
		countArray[i] += countArray[i - 1]
	}

	// store the sorted orders.
	sortedArray := make([]int, length)
	// we have to brought up i because we have to mess with the original array not just the copy value.
	for i, value := range values {
		sortedArray[countArray[value] - 1] = values[i]
		countArray[value]--
	}

	// overwrite to the original array.
	for i := range values {
		values[i] = sortedArray[i]
	}

	return nil
}
