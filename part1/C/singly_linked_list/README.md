# Creating a singly linked-list
This is the section of singly linked-list.

## File structure
- main.c file contains most of the implemetation of the datastructure code.
- utils.c file contains *all* of the functions to create the singly linked-list.
- utils.h file contains the header functions for the main.c file.
- singly.h file contains the composite structures that will need to use through out the program
- Makefile contains the command line configuration of the whole program.

## Interface
- bulid function builds a new singly linked-list with linear time complexity, O(n).

- create_node function create a node and initialize the value with it and return the node.O(1)

- print_list function prints the items inside the given singly linked-list in linear time complexity, O(n).

- free_list function frees the memory that is being allocated during the build process of the given singly linked-list.

- set_at function set the given value to the given singly linked-list's index in linear time complexity, O(n).

- get_at function gets the given singly linked-list's indexd node in linear time complexity, O(n).

- delete_first function deletes the first item in the given singly linked-list in constant time complexity, O(1).

You can compile the source code using the `Makefile`.
```bash
make
```
will compile the source file to the machine code.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./singly_linked_list
```

Running the machine code is like running the tests.
```bash
./singly_linked_list
``` 
Depending on your os, and your computer, the commands might be a little different.

## Implementation
Uses pointers as the links to one data to another. Has the limitation of the linked-list which is linear timecomplexity for searching and replacing. Good to use if the datastructre should be **stack** like one.

We can make the delete_last, insert_last efficiently if we use the first node to store a pointer to the end of the singly linked-list.
