# Introduction

This is the section for creating direct access array sort, that is described in [MIT 6006, Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec5/)

## File structure

- main.c file contains the usage of direct access array sort.

- utils.c file contains the direct access array sort function.

- utils.h file contains the header functions for the main.c file.

- Makefile file contains command line configuration for the whole program.

## Specification

- Implement a sorting algorithm that has the running time of $O(u)$.

## Pseudocode

1. Store the keys $u$ of $n$ items in the bucket array $u + 1$.

2. While storing the keys maintain the sorted order.

3. Go through the bucket array.

4. If the $i^{th}$ element has value(not empty), add the $i^{th}$ item to the original array resulting in sorted order.

## Interface

- DAA_sort function sorts the given array using the dirrect access array method in average linear time complexity $\theta(u) = \theta(n) if u = \theta(n)$.

You can compile the souce code using the `Makefile`.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./DAA_sort
```
Running the machine code is like running the tests.
```bash
./DAA_sort
```
Depending on your os, and your computer, the commands might be a little bit different.

## Limitation

- This sorting algorithm is only good if the key $u$ is equal to $n$.

- if keys are in larger range, like $u = \omega(n^2) < n^2$ this sorting algorithm will take qudractic time complexity which is bad.

    - Consider the following $n$ items of array with keys $u$.

        - [17, 3, 24, 22, 12]
    This example show that we have to create a very large array that has atleast *24 + 1* items and we have to walk through it to sort.

- we should use tuple sort or other kind of sort for that kind of problem.

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
