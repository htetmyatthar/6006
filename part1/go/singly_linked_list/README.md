# Introduction
This is the section for creating singly linked-list in GO.

## File structure
- sll_demonstration.go file contains the main function and we can use it as the testing during implementation.
- singly_linked_list.go file contains *all* the functions to create the singly linked-list.
- singly_linked_list_test.go file contains test cases for singly linked-list.

## Interface
SLinkedList = singly linked list's head.
- SLinkedList.Build build a singly linked-list in linear time complexity O(n).
- SLinkedList.DeleteFirst deletes the head of the singly linked-list in constant time complexity O(1).
- SLinkedList.GetAt gets the given index in linear time complexity O(n).
- SLinkedList.InsertFirst inserts the node with the given value in constant time complexity O(1).
- SLinkedList.PrintValues prints the nodes' values of the given singly linked-list in linear time complexity O(n).
- SLinkedList.SetAt sets the given index and value to the given singly linked-list in linear time complexity O(n).

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/singly_linked_list$*

*To compile source code*
```bash
go build .
```
*To run the source binary*
```bash
./singly_linked_list
```

*To compile the tests*
```bash
go test -c
```
*To run the test binary*
```bash
./singly_linked_list.test
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
