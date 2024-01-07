# Introduction

This is the section for creating binary search.

## File structure

- main.c file contains the usage of binary search.

- utils.c file contains the implementation of binary search.

- utils.h file contains the header functions for the main.c file.

- Makefile contains the command line configuration for the whole program.

## Specification

- implement a search algorithm that has the runtime of $O(log n)$.

## Pseudocode
```txt
if no doors
    return false
if 50 is behind doors[middle]
    return true
else if 50 < door[middle]
    search doors[0] through doors[middle - 1]
else if 50 > door[middle]
    search doors[middle + 1] trough doors[n - 1]
```
Reference: [CS50](https://cs50.harvard.edu/x/2023/notes/3/#algorithms)

## Interface

- binary_search function search the function using divide and conquer method and has time complexity of $(O(log n)$.

Note: Due to the nature of usefulness on searching large amount of items with binary search. I used the technique that won't cause integer overflow when calculating middle index.

## Implementation

You can compile the source code using the `Makefile`.
```bash
make
```
will compile the source file to the machine code.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrid --leak-check=full ./binary_search
```

Running the machine code is like running the tests.
```bash
./binary_search
``` 
Depending on your os, and your computer, the commands might be a little different.

# References
David J. Malan. CS50 Introduction to computer science. 2023. Harvard University: CS50,https://cs50.harvard.edu/x/
