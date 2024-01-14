package main

import (
	"fmt"
	"log"
)

func main() {
	// testing with a non-empty array
	given_array := []int{1, 10, 5, 9, 2, 4, 8, 7, 6, 0}
	fmt.Println("Original: \n", given_array)
	err := SelectionSort(given_array)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Sorted: \n", given_array)

	// testing with empty array
	given_array1 := []int{}
	fmt.Println("Original: \n", given_array1)
	err = SelectionSort(given_array1)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Sorted: \n", given_array1)
}
