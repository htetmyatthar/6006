package main

import "fmt"

func main(){
	test_slice := []int{6, 2, 5, 1, 8}
	fmt.Println("Original: \n", test_slice)
	MergeSort(test_slice)
	fmt.Println("Sorted: \n", test_slice)

	test_slice1 := []int{17, 94, 9, 8, 33, 42, 75, 14, 48, 23, 98, 79, 16, 67, 96, 82, 66, 81, 76, 39, 73, 70, 58, 64, 29, 43, 68, 86, 7, 5, 38, 88, 32, 11, 40, 84, 41, 46, 57, 18, 62, 59, 22, 1, 37, 44, 21, 63, 80, 93, 61, 6, 15, 30, 85, 65, 71, 49, 13, 87, 45, 99, 91, 74, 31, 25, 12, 97, 36, 34, 60, 53, 54, 56, 83, 100, 95, 26, 90, 47, 77, 24, 4, 3, 20, 28, 89, 69, 72, 35, 27, 78, 55, 2, 52, 92, 51, 50, 19, 10}
	fmt.Println("Original: \n", test_slice1)
	MergeSort(test_slice1)
	fmt.Println("Sorted: \n", test_slice1)
}
