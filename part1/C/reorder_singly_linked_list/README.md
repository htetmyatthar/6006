# Reordering Singly Linked List
This is a section of reordering the linked list using the practice problem from the [6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_prob1sol/)

## Specification

- There's $2n$ number of students waiting in line.
- Wants to reverse the linked list such that $n + 1$ to $2n$ is in reverse order.
- Time complexity should be O(n).
- No new linked list nodes or instantiate any new non-constant-sized data structures during it's operation.
**If you interested in the question you can read it at the bottom of this file.**

## File structure
- main.c file contains most of the usage of the reorder linked list code.
- utils.c file contains *all* of the functions to create the singly linked list and reversing the half.
- utils.h file contains the header functions for the main.c file.
- Makefile contains the command line configuration of the whole program.

## Interface
- build function builds a new singly linked-list with linear time complexity O(n).
- print_list function prints the items inside the given singly linked-list in linear time complexity O(n).
- free_list function frees the memory that is being allocated during the build process of the given singly linked-list.
- half_reverse function reverses the later half of the given singly linked-list in linear time complexity O(n).

You can compile the souce code using the `Makefile`.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./reorder_singly_linked_list
```
Running the machine code is like running the tests.
```bash
./reorder_singly_linked_list
```
Depending on your os, and your computer, the commands might be a little bit different.

## Limitation
- In this program the half-reverse function assume that the given singly linked-list has exactly even number of items in it. So that when we half it we can get the middle point predictably.

## Question

*This is the direct copy of the question that is in MIT 6006 Spring 2020*

Jen drives her ice cream truck to her local elementary school at recess. All the kids rush to line up
in front of her truck. Jen is overwhelmed with the number of students (there are 2n of them), so
she calls up her associate, Berry, to bring his ice cream truck to help her out. Berry soon arrives
and parks at the other end of the line of students. He offers to sell to the last student in line, but the
other students revolt in protest: “The last student was last! This is unfair!”
The students decide that the fairest way to remedy the situation would be to have the back half of
the line (the n kids furthest from Jen) reverse their order and queue up at Berry’s truck, so that the
last kid in the original line becomes the last kid in Berry’s line, with the (n + 1)st kid in the original
line becoming Berry’s first customer.

Given a linked list containing the names of the 2n kids, in order of the original line
formed in front of Jen’s truck (where the first node contains the name of the first kid
in line), describe an O(n)-time algorithm to modify the linked list to reverse the order
of the last half of the list. Your algorithm should not make any new linked list nodes
or instantiate any new non-constant-sized data structures during its operatio
Reference: [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_prob1sol/)


# References
Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
