package main

import (
	"errors"
	//"math"
	//"math/bits"
)

type Tuple struct {
	Digits        []int // digits of a number base n
	OriginalValue int   // original value of the number
}

// RadixSort sorts the given values array using the log_n{u} keys.
// Returns an error if the given values is empty.
// Returns an error if the given array's largest value is larger than len^log_n{u}.
// Returns an error if the given array's length is 1.
func RadixSort(values []int) error {
	length := len(values)

	if length == 0 {
		return errors.New("Given array to sort is empty.")
	} else if length == 1 {
		return errors.New("Given array is already sorted.")
	}

	largestKey := -1
	for _, value := range values {
		if value > largestKey {
			largestKey = value
		}
	}
	maxKey := largestKey + 1

	/*
		maximun number of digits needed to represent the maxKey in base length.
		function find maxDigits is the same.
		maxDigits := ((bits.Len(uint(maxKey)) / bits.Len(uint(length))) + 1)
		if maxKey >= int(math.Pow(float64(length), float64(maxDigits))){
			return errors.New("Given array largest value is breaking the constraint.")
		}
		this is the same implementation but using bits are wayy better rather than loops when values[i] < length^maxDigits.
	*/

	// If that constraint is not working then using findMaxDigits is better
	//considering loop's constant factors.
	maxDigits := findMaxDigits(maxKey, length)

	// prepare to sort the digits of base length.
	arrayToSort := make([]*Tuple, length)
	// for every item in the values
	for i, value := range values {

		newTuple := &Tuple{
			Digits:        make([]int, maxDigits),
			OriginalValue: value,
		}

		// store the least to most significant digits from first index to maxDigits-1 index.
		high := value
		for j := 0; j < maxDigits; j++ {
			low := high % length
			newTuple.Digits[j] = low
			high = high / length
		}
		arrayToSort[i] = newTuple
	}

	// for every digits
	for i := 0; i < maxDigits; i++ {
		countingSort(arrayToSort, i)
	}

	// copy the sorted order.
	for i := range values {
		values[i] = arrayToSort[i].OriginalValue
	}
	return nil
}

// countingSort sorts the given array of tuples acting as an auxillary sort to RadixSort.
// Use the 6006/part3/go/counting_sort if you are trying to sort and array of itegers using counting sort.
func countingSort(tuples []*Tuple, place int) {
	largestKey := -1
	for _, value := range tuples {
		if value.Digits[place] > largestKey {
			largestKey = value.Digits[place]
		}
	}
	maxKey := largestKey + 1

	// counting the occurence
	countArray := make([]int, maxKey)
	for _, value := range tuples {
		countArray[value.Digits[place]]++
	}

	// calculating cummulative sum
	for i := 1; i < maxKey; i++ {
		countArray[i] += countArray[i-1]
	}

	// sort the least significant digits.
	sortedArray := make([]*Tuple, len(tuples))
	// we have to reverse the order.
	for i := len(tuples) - 1; i >= 0; i-- {
		sortedArray[countArray[tuples[i].Digits[place]]-1] = tuples[i]
		countArray[tuples[i].Digits[place]]--
	}

	// copy the sorted order.
	for i := range tuples {
		tuples[i] = sortedArray[i]
	}
}

// Alternative understanding of how to find the maxdigits but using loops
// findMaxDigits returns the number of digits that will need to represent in the base form for maxKey.
func findMaxDigits(maxKey int, base int) int {
	count := 1
	for maxKey > 0 {
		count++
		maxKey = maxKey / base
	}
	return count
}
