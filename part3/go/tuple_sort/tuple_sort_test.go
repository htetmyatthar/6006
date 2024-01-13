package main

import(
	"testing"
)

func TestTupleSort(t *testing.T){
	inputArray := []int{17, 3, 24, 5, 11}
	expectedArray := []int{3, 5, 11, 17, 24}
	// testing correctness.
	err := TupleSort(inputArray)
	if err != nil {
		t.Errorf("No error should occured, but one occured:\n %v\n", err)
	}
	for i := 0; i < len(inputArray); i++{
		if inputArray[i] != expectedArray[i]{
			t.Errorf("Index: %v, Expected: %v, Result: %v\n", i, expectedArray[i], inputArray[i])
		}
	}

	// testing with empty array.
	emptyArray := []int{}
	err = TupleSort(emptyArray)
	if err == nil{
		t.Errorf("Expected error, but none occured.\n")
	}

	// testing with larger keys that are larger than n^2, n is length
	largeKeysArray := []int{10, 20, 30, 40}
	err = TupleSort(largeKeysArray)
	if err == nil{
		t.Errorf("Expected error, but none occured.\n")
	} 
}

func TestTupleSortEdgeCases(t *testing.T){
	singleElement := []int{1}
	expectedResult := []int{1}

	// checking correctness
	err := TupleSort(singleElement)
	if err == nil {
		t.Errorf("No error should occured, but one occured:\n %v\n", err)
	}
	for i := 0; i < len(singleElement); i++{
		if singleElement[i] != expectedResult[i]{
			t.Errorf("Index: %v, Expected: %v, Result: %v\n", i, expectedResult[i], singleElement[i])
		}
	}
}
