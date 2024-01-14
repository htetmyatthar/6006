package main

import "testing"

func TestHashMapCreate(t *testing.T) {
	givenArray := []int{67, 13, 49, 24, 40, 33, 58}
	hm := NewHashMap(SizeOfHashMapArray)

	expectedNumElements := len(givenArray)
	err := hm.Create(givenArray)
	if err != nil {
		t.Errorf("Unexpected error: %v\n", err)
	}

	if hm.NumElements != expectedNumElements {
		t.Errorf("Numelements, expected: %v, result: %v", expectedNumElements, hm.NumElements)
	}

	// Chech that each value in the array is in the hashmap
	for _, value := range givenArray {
		found, _ := hm.Find(value)
		if !found {
			t.Errorf("Value %d not found in the hashmap.\n", value)
		}
	}

	// Test case with an empty array
	emptyArray := []int{}
	hm = NewHashMap(SizeOfHashMapArray)
	err = hm.Create(emptyArray)
	if err == nil {
		t.Error("Expected error for an empty array, but no error occured.\n")
	}
}

func TestHashMapFind(t *testing.T) {
	givenArray := []int{67, 13, 49, 24, 40, 33, 58}
	hm := NewHashMap(SizeOfHashMapArray)
	err := hm.Create(givenArray)
	if err != nil {
		t.Errorf("Unexpected error: %v\n", err)
	}

	expectedNumElements := len(givenArray)
	if hm.NumElements != expectedNumElements {
		t.Errorf("Numelements, expected: %v, result: %v", expectedNumElements, hm.NumElements)
	}

	// Test Existing values
	for _, value := range givenArray {
		found, _ := hm.Find(value)
		if !found {
			t.Errorf("Value %d not found in the hashmap.\n", value)
		}
	}

	// Test non-existing value
	nonExistingValue := 99
	found, _ := hm.Find(nonExistingValue)
	if found {
		t.Errorf("Non-existing value %d found in the hashmap\n", nonExistingValue)
	}

	// Test case with empty hashmap
	emptyHashMap := NewHashMap(SizeOfHashMapArray)
	found, _ = emptyHashMap.Find(43)
	if found {
		t.Error("Found a value in an empty hashmap.\n")
	}
}

func TestHashFunction(t *testing.T) {
	// testing the hash function with the value 0.
	givenInput := 0
	expected := 5
	hashedResult := hashFunction(givenInput)
	if hashedResult != expected {
		t.Errorf("Expected: %v, hashed result: %v\n", expected, hashedResult)
	}

	// testing the hash function with the average value.
	givenInput = 43
	expected = 1
	hashedResult = hashFunction(givenInput)
	if hashedResult != expected {
		t.Errorf("Expected: %v, hashed result: %v\n", expected, hashedResult)
	}
}
