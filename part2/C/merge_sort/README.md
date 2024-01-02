# Insertion sort
This is the section for creating merge sort.

## File structure
- main.c file contains the usage of merge sort.
- utils.c file contains implementation for merge sort.
- utils.h file contains the header functions for the main.c file.
- Makefile contains the command line configuration of the whole program.

## Specification
- implement a sorting algorithm that has the runtime of O(nlogn).

## Pseudocode
```
If only one number
    Quit
Else
    Sort left half of number
    Sort right half of number
    Merge sorted halves
```
Reference: [CS50](https://cs50.harvard.edu/x/2023/notes/3/#merge-sort)

## Interface

- merge_sort function sorts the given array.

## Implementation

You can compile the source code using the `Makefile`.
```bash
make
```
will compile the source file to the machine code.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./merge_sort
```

Running the machine code is like running the tests.
```bash
./merge_sort
``` 
Depending on your os, and your computer, the commands might be a little different.
