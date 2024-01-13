package main

import (
	"fmt"
	"log"
)

const SizeOfHashMapArray int = 9;

func main(){
	givenArray := []int{67, 13, 49, 24, 40, 33, 58}
	fmt.Println(givenArray)
	hm := NewHashMap(SizeOfHashMapArray)
	hm.Create(givenArray)
	fmt.Println("Created hashmap.")
	hm.PrintElements()

	fmt.Println("Finding 67 in the hashmap.")
	found, err := hm.Find(67)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Expected: True, Result: ", found)
}
