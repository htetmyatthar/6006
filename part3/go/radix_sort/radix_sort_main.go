package main

import (
	"fmt"
)

func main() {
	fmt.Println("Hello, world")
	givenArray := []int{170, 45, 75, 90, 802, 24, 2, 66}
	fmt.Println("Original: \n", givenArray)
	err := RadixSort(givenArray)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println("Sorted: \n", givenArray)

	givenArray1 := []int{410, 666, 251, 775, 480, 351, 681, 786, 472, 284,
		242, 269, 875, 322, 793, 90, 791, 396, 113, 107, 883, 490, 520, 556,
		154, 613, 218, 323, 970, 734, 0, 20, 01, 1, 0000, 21}
	fmt.Println("Original: \n", givenArray1)
	err = RadixSort(givenArray1)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println("Sorted: \n", givenArray1)

	givenArray2 := []int{123, 45, 678, 90, 543}
	fmt.Println("Original: \n", givenArray2)
	err = RadixSort(givenArray2)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println("Sorted: \n", givenArray2)

	givenArray3 := []int{4, 2, 4, 1, 2, 1}
	fmt.Println("Original: \n", givenArray3)
	err = RadixSort(givenArray3)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println("Sorted: \n", givenArray3)

	givenArray4 := []int{}
	fmt.Println("Original: \n", givenArray4)
	err = RadixSort(givenArray4)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println("Sorted: \n", givenArray4)

	givenArray5 := []int{5}
	fmt.Println("Original: \n", givenArray5)
	err = RadixSort(givenArray5)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println("Sorted: \n", givenArray5)
}
