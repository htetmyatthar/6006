# Insertion sort
This is the section for creating insertion sort.

## File structure
- main.c file contains the usage of insertion sort.
- utils.c file contains implementation for insertion sort.
- utils.h file contains the header functions for the main.c file.
- Makefile contains the command line configuration of the whole program.

## Specification
- implement a sorting algorithm that has the runtime of O($n^2$).

## Pseudocode
```
For i from 1 to n - 1
	j = i
	If there's still items to check(j > 0) and those items are bigger than the current item.
		Swap the current item and the 
		Decrement j
```

## Interface

- insertion_sort function sorts the given array.

## Implementation

You can compile the source code using the `Makefile`.
```bash
make
```
will compile the source file to the machine code.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./insertion_sort
```

Running the machine code is like running the tests.
```bash
./insertion_sort
``` 
Depending on your os, and your computer, the commands might be a little different.
