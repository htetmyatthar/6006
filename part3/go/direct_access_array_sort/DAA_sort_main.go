package main

import (
	"fmt"
	"log"
)

func main() {
	givenArray := []int{5, 2, 7, 0, 4}
	fmt.Println("Original: \n", givenArray)
	err := DAASort(givenArray)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Sorted: \n", givenArray)

	givenArray = []int{}
	fmt.Println("Testing error happening.")
	err = DAASort(givenArray)
	if err != nil {
		fmt.Println("This is the error:\n", err)
	}
}
