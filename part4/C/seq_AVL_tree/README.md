# Introduction

This is the section for creating **seq AVL tree** which is the hight balanced seq binary tree representation and it's interface using sources from [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec6/).

This one is a little bit complicated and long.

## File structure

- main.c file contains the usage of seq AVL tree's interface while implementing.

- utils.c file contains the implementations of seq AVL tree's interface.

- utils.h file contains the header functions for binary tree.

- Makefile contains the command line configuration for the whole program.

## Specification

- Implment set AVL tree interface.

- finding, inserting, deleting, building, various traversal order.

- rotation, heigh balancing, augmentation

## Interface

- **cal_height** function returns the height of the node in constant time complexity $O(1)$.(without it everything will be slower, augemntation of height).

- **skew** function calculates the skew of the node in constant time complexity $O(1)$.

- **subtree_update** updates height augmentation and size augmentation of the given node in constant time complexity $O(1)$.

- **subtree_rotate_right** right rotates the given node's subtree in constant time compelxity $O(1)$.

- **subtree_rotate_left** left rotates the given node's subtree in constant time complexity $O(1)$.

- **rebalance** balances the given node's height in constant time complexity $O(1)$.

- **maintain** maintains height balance of the given subtree's node and it's ancestors in logarithmic time complexity $O(h) = O(log{n})$.

- **subtree_insert_after** inserts after the given node with a new node created with given key and value, in logarithmic time complexity $O(h) = O(log{n})$.(overhead from maintaining the height balance)

- **subtree_insert_before** inserts before the givenn node with a new node created with given key and value, in logarithmic time complexity $O(h) = O(log{n})$.(overhead for maintaining the height balance).

- **build_seq_avl_sorted** builds a new sorted seq avl tree for in-order traversal order in linear time complexity $O(n)$.

    - Mind the limitations.    

- **build_seq_avl** builds a new seq avl tree for in-order traversal order in linear time complexity $O(n)$.

- **build_set_avl_tree_recursion** builds set avl tree with the given start and end index of the sorted keys_values arrays of array in linear time complexity $O(n)$.

- **insert_at** function insert the given value in the given index of the given tree in logarithmic time complexity $O(h)$.

- **subtree_delete_node** deletes the node and update the given root with the maintained root in logarithmic time complexity $O(h) = O(log{n})$.(plus overhead for maintaining the height balance)

- **delete_at** function deletes the given index's node in the given tree in logarithmic time complexity $O(h) = O(log{n})$.(plus overhead for maintaining height balance)

- **insert_first** function inserts a new node with the given value as first node in the in-order traversal of the given tree in logarithmic time complexity $O(h) = O(log{n})$.(plus overhead for maintaining height balance)

- **insert_last** function inserts a new node with the given value as last node in the in-order traversal of the given tree in logarithmic time complexity $O(h) = O(log{n})$.(plus overhead for maintaining height balance)

- **delete_first** function deletes the first node of the given tree's in-order traversal in logarithmic time complexity $O(h) = O(log{n})$.(plus overhead for maintaining height balance)

- **delete_last** function deletes the last node of the given tree's in-order traversal in logarithmic time complexity $O(h) = O(log{n})$.(plus overhead for maintaining height balance)

- **subtree_first** function finds the first node in the in-order traversal order in logarithmic time complexity $O(h) = O(log{n})$.

- **subtree_last** functions finds the last node in the in-order traversal order in logarithmic time complexity $O(h) = O(log{n})$.

- **successor** function finds the successor node of the given node in logarithmic time complexity $O(h) = O(log{n})$.

- **predecessor** function finds the predecessor node of the given node in logarithmic time complexity $O(h) = O(log{n})$.

- **subtree_at** function finds the given index in the given tree in logarithmic time complexity $O(h) = O(log{n})$.

- **get_at** function gets the value of the given index in logarithmic time complexity $O(h) = O(log{n})$.

- **set_at** function sets the value of the given index with a new value in logarithmic time complexity $O(h) = O(log{n})$.

- **subtree_iter** function prints the given subtree's nodes' key, value, height in in-order traversal order in linear time complexity $O(n)$.

- **print_pre_order** function prints the given subtree's nodes' key, value, height in pre-order traversal order in linear time complexity $O(n)$.

- **free_tree** function frees the given subtree in linear time complexity $O(n)$.

- **print_hr** function prints the visual line in constant time complexity $O(1)$.

- **print_array** function prints the array in linear time complexity $O(n)$.

You can compile the souce code using the `Makefile`.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./seq_avl_tree
```
**or**

```bash
make valgrind
```

Running the machine code is like running the tests.
```bash
./seq_avl_tree
```

**or**

```bash
make run
```

Depending on your os, and your computer, the commands might be a little bit different.

## Limitations

- Remember that we used the DAA sort for sorting the values of array before creating a new tree.

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
