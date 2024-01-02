# Creating doubly linked-list
This is the section of creating doubly linked list. The below specification part is from the problem set of [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_ps1-questions/).
Create a doubly linked list with the below specification.

## Specification
- Each node of this linked list maintains previous pointer and next pointer.
- This linked list should not maintain their length.
- The list is pointed by a pointer having head and tail of the list in it.

### Support of constant time operation O(1)
* insert_first(x), insert_last(x), delete_first(), delete_last()
* remove all nodes from x1 to x2 inclusive from L, return them as a new doubly linked list.
* splice anoter list L2 to the original list L1 after node x. After the splice operation, L1 should contain all items previously in either list, and L2 should be empty.

## File structure
- main.c file contains most of the implementation of the data structure code.
- utils.c file contains *all* of the functions to create the doubly linked-list.
- utils.h file contains the header functions for the main.c file.
- doubly.h file contains the composite structures that will need to use through out the program
- Makefile contains the command line confuguration of the whole program.

## Interface
- build function builds a new doubly linked-list with linear time complexity O(n).
- print_list function prints the items inside the given doubly linked-list in linear time complexity, O(n).
- free_list function frees the memory that is being allocated during the build process of the given doubly linked-list.
- create_node function create a node and initialize the value with it and return the node.O(1)
- get_at function gets the given doubly linked-list's indexed node in linear time complexity, O(n).
- set_at function set the given value to the given doubly linked-list's index in linear time complexity, O(n).
- insert_first function insert the node with the given value to the given doubly linked-list's head in constant time complexity, O(1).
- insert_last function insert the node with the given value to the given doubly linked-list's tails in constant time complexity, O(1).
- delete_first function deletes the head node of the given doubly linked-list in constant time complexity, O(1).
- delete_last function deletes the tail node of the given doubly linked-list in constant time complexity, O(1).
- remove_nodes function removes the nodes between the given start and end node of the given doubly linked-list in constant time complexity, O(1). Assuming the given start node comes before the end node.
- splice_list function connects the given another doubly linked-list to the given doubly linked-list's index in constant time complexity, O(1). 
You can compile the souce code using the `Makefile`.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./doubly_linked_list
```
Running the machine code is like running the tests.
```bash
./doubly_linked_list
```
Depending on your os, and your computer, the commands might be a little bit different.

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
