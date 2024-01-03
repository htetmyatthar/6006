package main

import "fmt"

func main() {
	values := []int{1, 2, 3, 4, 5, 6}
	list := &SinglyLinkedList{Head: nil}
	list.Build(values)
	finger := list.Head
	for finger != nil {
		fmt.Printf("%v->", finger.Value)
		finger = finger.Next
	}
	fmt.Println()

	list.HalfReverse(5)
	finger = list.Head
	for finger != nil {
		fmt.Printf("%v->", finger.Value)
		finger = finger.Next
	}
	fmt.Println()
}
