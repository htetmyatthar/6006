package main

import (
	"errors"
	"fmt"
)

// hashFunction hashes the given integer input into hashed value
// using the h(k) = (11k + 14) mod 9 as the hash function.
func hashFunction(input int) int{
	// hash function h(k) = (11k + 14) mod 9
	hashedValue := ((11 * input) + 14) % 9
	return hashedValue
}

// hashmap nodes
type Node struct{
	Value int		// Value of the node.
	Next *Node		// Pointer to the next node.
}

// hashmap struct
type HashMap struct{
	ArraySize int	// size of the underlying HashMap's array.
	NumElements int	// number of elements in the current HashMap.
	Data []*Node	// the underlying hashmap.
}

// NewHashMap function initialize a new HashMap using the arraySize.
func NewHashMap(arraySize int) *HashMap{
	return &HashMap{
		ArraySize: arraySize,
		NumElements: 0,
		Data: make([]*Node,arraySize),
	}
}

// hm.Create method create a new hashmap and attach to a newly initiated hm struct's Data field.
// Returns error if the given values array is empty or the caller hm is nil.
func (hm *HashMap) Create(values []int) error{
	length := len(values)

	if length == 0{
		return errors.New("The given array data is empty.")
	}

	if hm == nil {
		return errors.New("You have to initialize HashMap struct first.")
	}

	for i := 0; i < length; i++{
		// hashing
		hashedValue := hashFunction(values[i])

		// linking
		newNode := &Node{values[i], hm.Data[hashedValue]}
		hm.Data[hashedValue] = newNode

		// update the element count
		hm.NumElements++;
	}
	return nil
}

// hm.Find method finds the given value in the hm.Data.
// Returns error if hm.Data is empty or the caller hm is nil.
// Returns true if the given value is indeed in hm.Data.
func (hm *HashMap) Find(value int) (bool, error){
	if hm.ArraySize == 0 || hm.Data == nil{
		return false, errors.New("The hashmap is empty.")
	}

	if hm == nil {
		return false,errors.New("You have to initialize HashMap struct first.")
	}
	
	hashedKey := hashFunction(value)
	finger := hm.Data[hashedKey]
	for(finger != nil){
		if finger.Value == value{
			return true, nil
		}
		finger = finger.Next
	}
	return false, nil
}

func (hm *HashMap) PrintElements(){
	for i := 0; i < hm.ArraySize; i++{
		finger := hm.Data[i]
		for finger != nil{
			fmt.Printf("Index: %v, value: %v,\n",i, finger.Value)
			finger = finger.Next
		}
	}
	fmt.Println()
	return;
}
