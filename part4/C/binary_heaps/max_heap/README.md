# Introduction

This is a part of creating binary heaps, which is max heap. Creating a heap that satisfies max-heap property.

## File structure

- main.c file contains the usage of binary max heap while implementing.

- utils.c file contains the implementations of binary max heap.

- utils.h file contains the header functions for **main.c** file, binary max heap.

- dynamic_array_test.c file contains the test cases for underlying dynamic array implementation inside binary max heap.

- dynamic_array.c file contains the implementations of dynamic array to use in binary max heap.

- dynamic_array.h file contains the header functions for **dynamic_array_test.c** file, dynamic array testing.

- Makefile contains the command line configuration for the whole program.

## Specification

- Impelement binary max heap and it's interface.

- Implement heap sort for array of integers.

## Interface

- parent_index function returns the parent index of the given index in constant time complexity $O(1)$.

- left_child_index function returns the left child index of the given index in constant time complexity $O(1)$.

- right_child_index function returns the right child index of the given index in constant time complexity $O(1)$.

- max_heapify_up function makes the given child index's value to satisfies the max heap property in logarithmic time complexity $O(h) = O(log{n})$.

- max_heapify_down function makes the given parent index's value to satisfies the max heap property in logarithmic time complexity $O(h) = O(log{n})$.

- insert_to_heap functino inserts a new values into the given heap array in logarithmic time complexity $O(h) = O(log{n})$.

- delete_max_heap function deletes the maximum value inside the given heap array in logarithmic time complexity $O(h) = O(log{n})$.

- build_heap_linear function builds a new heap array from the given dynamic array in linear time complexity $O(n)$.

- heapify_down function makes the parent index's value to satisfies max heap property in logarithmic time complexity $O(log{n})$. This interface uses the normal array.

- sort_max function sort the given heap array(normal not dynamic) in linear time complexity $O(n)$.

- heap_sort function sort the given heap array in linearithmic time complexity $O(nlog{n})$.

**Note: compiler changes using clang from now on.**

You can compile the souce code using the `Makefile` for max_heap.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. Memory related problems are already checked in the runtime since I changed the compiler and uses clang.

Running the machine code is like running the tests.
```bash
./max_heap
```

**or**

```bash
make run
```

Depending on your os, and your computer, the commands might be a little bit different.

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
