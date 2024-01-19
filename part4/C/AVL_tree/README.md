# Introduction

This is the section for creating **set AVL tree** which is the hight balanced set binary tree representation and it's interface using sources from [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec6/).

Set AVL tree is also known as binary search tree (**BST**).(for the sake of consistency we will use the term set AVL tree).

This one is a little bit complicated and long.

## File structure

- main.c file contains the usage of set AVL tree's interface while implementing.

- utils.c file contains the implementations of set AVL tree's interface.

- utils.h file contains the header functions for binary tree.

- Makefile contains the command line configuration for the whole program.

## Specification

- Implment set AVL tree interface.

- finding, inserting, deleting, building, various traversal order.

- rotation, heigh balancing, augmentation

## Interface

- build_set_avl_tree builds set avl tree with the given keys_values arrays of array in linearithmic time complexity $O(nh) = O(n log n)$.(overhead for sorting the keys)

- _build_set_avl_tree_recursion builds set avl tree with the given start and end index of the sorted keys_values arrays of array in linear time complexity $O(n)$.

- DAA_sort function sorts the given values in linear time compelxity $\theta(u) = \theta(n)$ if $u = \theta(n)$.

    - Mind the limitations.    

- cal_height function returns the height of the node in constant time complexity $O(1)$.(without it everything will be slower, augemntation of height).

- skew function calculates the skew of the node in constant time complexity $O(1).$.

- subtree_update updates height augmentation of the given node in constant time complexity $O(1)$.

- subtree_rotate_right right rotates the given node's subtree in constant time compelxity $O(1)$.

- subtree_rotate_left left rotates the given node's subtree in constant time complexity $O(1)$.

- rebalance balances the given node's height in constant time complexity $O(1)$.

- maintain maintains height balance of the given subtree's node and it's ancestors in logarithmic time complexity $O(h) = O(log n)$.

- subtree_insert_after inserts after the given node with a new node created with given key and value, in logarithmic time complexity $O(h) = O(log n)$.(overhead from maintaining the height balance)

- subtree_insert_before inserts before the givenn node with a new node created with given key and value, in logarithmic time complexity $O(h) = O(log n)$.(overhead for maintaining the height balance).

- subtree_delete_node deletes the nodes and update the given root with the maintained root in logarithmic time complexity $O(h) = O(log n)$.(overhead for maintaining the height balance)

- subtree_find function finds the given key in the given subtree in logarithmic time complexity $O(h) = O(log n)$.

- subtree_first function finds the first node in the in-order traversal order in logarithmic time complexity $O(h) = O(log n)$.

- subtree_last functions finds the last node in the in-order traversal order in logarithmic time complexity $O(h) = O(log n)$.

- successor function finds the successor node of the given node in logarithmic time complexity $O(h) = O(log n)$.

- predecessor function finds the predecessor node of the given node in logarithmic time complexity $O(h) = O(log n)$.

- subtree_iter function prints the given subtree's nodes' key, value, height in in-order traversal order in linear time complexity $O(n)$.

- print_pre_order function prints the given subtree's nodes' key, value, height in pre-order traversal order in linear time complexity $O(n)$.

- free_tree function frees the given subtree in linear time complexity $O(n)$.

- print_hr function prints the visual line in constant time complexity $O(1)$.

- print_array function prints the keys_values arrays of arrays in linear time complexity $O(n)$.

You can compile the souce code using the `Makefile`.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./avl_tree
```
**or**

```bash
make valgrind
```

Running the machine code is like running the tests.
```bash
./avl_tree
```

**or**

```bash
make run
```

Depending on your os, and your computer, the commands might be a little bit different.

## Limitations

- Remember we used DAA sort for the sorting algorithm for the keys of the tree's nodes. We are bound to it don't forget about it.

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
