package main

import "testing"

func TestCountingSortSum(t *testing.T) {
	testCase := []int{7, 4, 9, 5, 2, 1, 8}
	expectedResult := []int{1, 2, 4, 5, 7, 8, 9}

	err := CountingSortSum(testCase)
	if err != nil {
		t.Errorf("Unexpected error: %v\n", err)
	}

	// checking sorting
	for i := 0; i < len(testCase); i++ {
		if testCase[i] != expectedResult[i] {
			t.Errorf("Sorting Failed. Index: %v, Expected: %v, Result: %v\n", i, expectedResult[i], testCase[i])
		}
	}

	// checking error
	emptyArray := []int{}
	err = CountingSortSum(emptyArray)
	if err == nil {
		t.Error("Expected error for an empty array, but no error occurred.\n")
	}
}

func TestCountingSortChain(t *testing.T) {
	testCase := []int{7, 4, 9, 5, 2, 1, 8}
	expectedResult := []int{1, 2, 4, 5, 7, 8, 9}
	err := CountingSortChain(testCase)
	if err != nil {
		t.Errorf("Unexpected error: %v\n", err)
	}

	// checking sorting
	for i := 0; i < len(testCase); i++ {
		if testCase[i] != expectedResult[i] {
			t.Errorf("Sorting Failed. Index: %v, Expected: %v, Result: %v\n", i, expectedResult[i], testCase[i])
		}
	}

	// checking error
	emptyArray := []int{}
	err = CountingSortChain(emptyArray)
	if err == nil {
		t.Error("Expected error for an empty array, but no error occurred.\n")
	}
}

func TestDupKeys(t *testing.T) {
	// testinc countingsortsum with repeated keys.
	repeatedElements := []int{3, 3, 1, 2, 2, 1}
	expectedResult := []int{1, 1, 2, 2, 3, 3}
	err := CountingSortChain(repeatedElements)
	if err != nil {
		t.Errorf("Unexpected error: %v\n", err)
	}

	// checking sorting
	for i := 0; i < len(repeatedElements); i++ {
		if repeatedElements[i] != expectedResult[i] {
			t.Errorf("Sorting Failed. Index: %v, Expected: %v, Result: %v\n", i, expectedResult[i], repeatedElements[i])
		}
	}

	// testinc countingsortsum with repeated keys.
	repeatedElements = []int{3, 3, 1, 2, 2, 1}
	err = CountingSortSum(repeatedElements)
	if err != nil {
		t.Errorf("Unexpected error: %v\n", err)
	}

	// checking sorting
	for i := 0; i < len(repeatedElements); i++ {
		if repeatedElements[i] != expectedResult[i] {
			t.Errorf("Sorting Failed. Index: %v, Expected: %v, Result: %v\n", i, expectedResult[i], repeatedElements[i])
		}
	}
}

func TestGiven(t *testing.T) {
	// checking countingSortSum with the given array of values.
	givenArray := []int{17, 3, 24, 22, 12}
	expectedResult := []int{3, 12, 17, 22, 24}
	err := CountingSortSum(givenArray)
	if err != nil {
		t.Errorf("Unexpected error: %v\n", err)
	}

	for i := 0; i < len(givenArray); i++ {
		if givenArray[i] != expectedResult[i] {
			t.Errorf("Sorting Failed. Index: %v, Expected: %v, Result: %v\n", i, expectedResult[i], givenArray[i])
		}
	}

	// checking countingSortChain with the given array of values.
	givenArray = []int{17, 3, 24, 22, 12}
	err = CountingSortChain(givenArray)
	if err != nil {
		t.Errorf("Unexpected error: %v\n", err)
	}

	for i := 0; i < len(givenArray); i++ {
		if givenArray[i] != expectedResult[i] {
			t.Errorf("Sorting Failed. Index: %v, Expected: %v, Result: %v\n", i, expectedResult[i], givenArray[i])
		}
	}
}
