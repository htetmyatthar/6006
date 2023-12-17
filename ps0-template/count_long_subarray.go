package count_long_subarray

// Input:  A     | Golang array of positive integers
// Output: count | number of longest increasing subarrays of A
func CountLongSubarray(A []int) int {
	currentCount := 0
	currentLength := 0
	iterateLength := 1

	// iterate through the array
	for i := 0; i < len(A); i++ {
		// if this is not the last element and such
		if (i+1) != len(A) && A[i] < A[i+1] {
			iterateLength += 1
		// either it was list index out of range or the first element is bigger than the second element
		} else {
			// if current checking longest length is bigger than the existing longest length
			if iterateLength > currentLength {
				currentCount = 1
				currentLength = iterateLength
			// elif current checking longest length is equal to the existing logest length
			} else if iterateLength == currentLength {
				currentCount++
			}
			iterateLength = 1
		}
	}
	return currentCount
}
