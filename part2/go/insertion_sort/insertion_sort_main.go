package main

import "fmt"

func main(){
	given_array := []int{1,10,5,9,2,4,8,7,6,0}
	fmt.Println("Original: \n", given_array)
	InsertionSort(given_array)
	fmt.Println("Sorted: \n", given_array)
}
