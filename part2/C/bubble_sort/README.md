# Bubble sort
This is the section for creating bubble sort.

## File structure
- main.c file contains the usage of bubble sort.
- utils.c file contains implementation for bubble sort.
- utils.h file contains the header functions for the main.c file.
- Makefile contains the command line configuration of the whole program.

## Specification
- impelement a sorting algorithm that has the runtime of O(n^2).

## Pseudocode

```
Repeat n - 1 times
For i from 0 to n - 2
    If numbers[i] and numbers[i + 1] out of order
        Swap them
```

Reference: [CS50](https://cs50.harvard.edu/x/2023/notes/3/#sorting)

## Interface
- bubble_sort function sorts the given array.

## Implementation
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
