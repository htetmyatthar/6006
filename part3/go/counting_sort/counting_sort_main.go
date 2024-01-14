package main

import (
	"fmt"
	"log"
)

func main() {
	givenArray := []int{17, 3, 24, 22, 12}
	fmt.Println("Counting sorting using cumulative sum: \n", givenArray)
	err := CountingSortSum(givenArray)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Sorted: \n", givenArray)

	givenArray1 := []int{4, 2, 1, 0, 3, 4, 0, 1}
	fmt.Println("Counting sorting using chaining: \n", givenArray1)
	err = CountingSortChain(givenArray1)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Sorted: \n", givenArray1)

	givenArray = []int{4, 2, 1, 0, 3, 4, 0, 1}
	fmt.Println("Counting sorting using cumulative sum: \n", givenArray)
	err = CountingSortSum(givenArray)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Sorted: \n", givenArray)

	givenArray1 = []int{17, 3, 24, 22, 12}
	fmt.Println("Counting sorting using chaining: \n", givenArray1)
	err = CountingSortChain(givenArray1)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Sorted: \n", givenArray1)
}
