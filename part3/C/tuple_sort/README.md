# Introduction

This section is for creating tuple sort using the direct access array sort as auxillary sorting method. This section is inspire by the [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec5/)

## File structure

- main.c file contains the usage of tuple sort.

- utils.c file contains the functions for tuple sort.

- utils.h file contains the header functions for the main.c file.

- Makefile file contains the command line configuration for the whole program.

    - **this one is different since we have to math library.**

## Specification

- Supposing all keys are unique non-negative integers in range ${0, ....., u - 1}$, so $n \le u$.

- Since using larger keys $u$ in direct access array sort is bad for $u = \Omega(n^2) < n^2$.

- While representing the each key by tuple $(a, b)$ where $k = an + b$ and $0 \le b < n$.

    - **This will result in $2$ digit base $n$. $a = k / 2 < n \quad and \quad b = (k\> mod\> n)$**

- Using the given array which there are no collisions of $a$ and $b$ for $a, b = divmod(k, n)$.

    - **[17, 3, 24, 5, 11]**

- Implement tuple sort.

## Implementation

- Using an **auxiliary sorting algorithms** to separately sort each key.

- Sort from least significant to most significants, so that we will have the benifits of sorting.

## Interface

- tuple_sort function sorts the given array using the dirrect access array method in average linear time complexity $\theta(u) = \theta(n) \quad if \quad u = \theta(n)$.

    - **please do mind the limitations**

- free_tuple_sort function frees the array of pointers to tuple in linear time complexity $O(n)$.

You can compile the souce code using the `Makefile`.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./tuple_sort
```
Running the machine code is like running the tests.
```bash
./tuple_sort
```
Depending on your os, and your computer, the commands might be a little bit different.

## Limitations

tuple_sort sorts the given values array using the a, b = divmod(k, n)

if the given values has:
1. **NO COLLIDING VALUES FOR (a).**
2. **NO COLLIDING VALUES FOR (b).**

- if there are colliding values of a and b in the given array the program will crash since 
- the auxillary sorts are implemented using the dynamic access array sort method.
- if the values in the given array are not less than length^2 the program will crash resulting in error.

## Note

- Many integers could have the same $a$ and $b$ value, even if input keys distinct.

- Consider the following array:

    **[17, 3, 24, 22, 12]**
    
    **[(3, 2), (0, 2), (4, 4), (4, 2), (2, 2)]

- Since we used the direct access array sort as the **auxiliary sorting algorithm** we will crash if we sort this array.

- **So we need to sort allowing *repeated keys* which preserves input order**.

- **And we also want our sort to be *stable*: repeated keys appear in output in same order as input**.

- **So we cannot use direct access array sort anymore since it cannot even sort arrays having repeated keys**.

- **We should chain them instead of storing one by one just like hashing.**

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
