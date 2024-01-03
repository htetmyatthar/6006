# Introduction 
This is the section for doubly linked-list in GO. The below specification part is from the problem set of [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_ps1-questions/).
Create a doubly linked list with the below specification.

## Specification
- Each node of this linked list maintains previous pointer and next pointer.
- This linked list should not maintain their length.
- The list is pointed by a pointer having head and tail of the list in it.# Specification

### Support of constant time operation O(1)
* insert_first(x), insert_last(x), delete_first(), delete_last()
* remove all nodes from x1 to x2 inclusive from L, return them as a new doubly linked list.
* splice anoter list L2 to the original list L1 after node x. After the splice operation, L1 should contain all items previously in either list, and L2 should be empty.

## File structure
- dll_demonstration.go file contains the general usage of doubly linked-list.
- doubly_linked_list.go file contains *all* of the methods and functions to create doubly linked-list.
- doubly_linked_list_test.go file contains test cases for doubly linked-list.

## Interface
DLinkedList = doubly linked list's head
- DLinkedList.Build method builds a new doubly linked-list in linear time complexity O(n).
- DLinkedList.CreateNode method create a new doubly linked-list node in constant time complexity O(1).
- DLinkedList.DeleteFirst method deletes the head of the doubly linked-list in constant time complexity O(1).
- DLinkedList.DeleteLast method deletes the tail of the doubly linked-list in constant time complexity O(1).
- DLinkedList.GetAt method gets the value of the given index in linear time complexity O(n).
- DLinkedList.SetAt method sets the value to the given index in linear time complexity O(n).
- DLinkedList.InsertFirst method inserts the new node with the given value to the head of the doubly linked-list in constant time complexity O(1).
- DLinkedList.InsertLast method inserts the new node with the given value to the tail of the doubly linked-list in constant time complexity O(1).
- DLinkedList.LaterNode method gets the gets the index node with linear time complexity O(n).
- DLinkedList.PrintValues method prints out the nodes' values of the doubly linked-list in linear time complexity O(n).
- DLinkedList.Remove method removes the nodes from start to end and returns as a new doubly linked list in constant time complexity O(1).
- DLinkedList.Splice method splice the nodes from another doubly linked-list to the current one in constant time complexity O(1), making the another doubly linked-list empty.

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/singly_linked_list$*

*To compile source code*
```bash
go build .
```

*Running go binary*
```bash
./doubly_linked_list
```

*To compile the tests*
```bash
go test -c
```

*Running test binary*
```bash
./doubly_linked_list.test
```

*To run the source code without compiling*
```bash
go run .
```

*To run the tests without compiling*
```bash
go test .
```

*To check the documentation*
```bash
go doc -all
```
Depending on your os, and your computer, the commands might be a little different.

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY
