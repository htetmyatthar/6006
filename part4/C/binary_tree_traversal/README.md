# Introduction

This is the section for creating binary tree and it's interface using sources from [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec6/).

## File structure

- main.c file contains the usage of binary tree while implementing.

- utils.c file contains the implementations of binary tree's interface.

- utils.h file contains the header functions for binary tree.

- Makefile contains the command line configuration for the whole program.

## Specification

- Implment binary tree interface.

- finding, inserting, deleting, building, various traversal order.

## Interface

- _build_tree_recursion function builds a new tree in traversal order as the index of the given values array using first and last indexes, in linear time complexity $O(n)$.

- build_tree function builds a new tree in linear time complexity $O(n)$.

- first_tree_node function finds the first tree node of the in-order traversal in linear time complexity $O(h) = O(n)$.

- last_tree_node function finds the last tree node of the in-order traversal in linear time complexity $O(h) = O(n)$.

- tree_successor function gives the successor node of the in-order traversal in linear time complexity $O(h) = O(n)$.

- tree_predecessor function gives the predecessor node of the in-order traversal linear time complexity $O(h) = O(n)$.

- insert_after_node function inserts a new node as successor with the given value in linear time complexity $O(h) = O(n)$.

- insert_before_node function inserts a new node as predecessor with the given value in linear time complexity $O(h) = O(n)$.

- delete_tree_node function deletes the given node in linear time complexity $O(h) = O(n)$.

- print_tree_traversal function prints the values of the nodes of subtree of the given root node in linear time complexity $O(n)$.
This uses iterative method (finding next successor).

- in_order_traversal function prints the values of the nodes of subtree of the given root node in linear time complexity $O(n)$.
This uses recursive method (prints the left subtree, prints root, prints the right subtree).

- print_pre_order function prints the values of the nodes of the subtree of the given root node in linear time complexity $O(n)$.

- free_tree_recursive function frees the memory of the given node's subtree in linear time complexity $O(n)$.

- print_hr function prints the visual line in linear time complexity.

You can compile the souce code using the `Makefile`.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./binary_tree
```
**or**

```bash
make valgrind
```

Running the machine code is like running the tests.
```bash
./binary_tree
```

**or**

```bash
make run
```

Depending on your os, and your computer, the commands might be a little bit different.

## Limitations

- We are bound to $O(h)$ in this implementation we have to do better than this, which is $h = O(log n)$. Then we will get $O(log n)$.

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
