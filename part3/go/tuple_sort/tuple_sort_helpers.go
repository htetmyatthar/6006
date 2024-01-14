package main

import (
	"errors"
	"math"
)

type Tuple struct {
	OriginalValue int
	First         int
	Second        int
}

// TupleSort sorts the given values array.
// Returns error when the given values array is empty or the values(key) inside the values array
// is more than length^2.
func TupleSort(values []int) error {
	length := len(values)
	if length == 0 {
		return errors.New("Given array to sort is empty.")
	}

	// checking constraint.maxKey
	maxKey := int(math.Pow(float64(length), 2)) - 1
	for i := 0; i < length; i++ {
		if values[i] > maxKey {
			return errors.New("TupleSort can't sort keys that are larger than n^2 where n is length.\n")
		}
	}

	// transforming data from decimals to tuples.
	tempArray1 := make([]*Tuple, length)
	for i := 0; i < length; i++ {
		newTuple := &Tuple{
			OriginalValue: values[i],
			First:         values[i] / length,
			Second:        values[i] % length,
		}
		tempArray1[i] = newTuple
	}

	// sort the least significant digit.
	tempArray2 := make([]*Tuple, length)
	for i, value := range tempArray1 {
		tempArray2[value.Second] = tempArray1[i]
	}

	// sort the more significant digit.
	tempArray3 := make([]*Tuple, length)
	for i, value := range tempArray2 {
		tempArray3[value.First] = tempArray2[i]
	}

	// copy the sorted order.
	for i := range values {
		// we don't need to check anything values array and
		// tempArray3 are just differently storing the same data in different format.
		values[i] = tempArray3[i].OriginalValue
	}
	return nil
}
