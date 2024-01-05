# Introduction
This is the section for creating dynamic array. This is a naiive implementation of dynamic array that preallocate the memory on both the end and the start of the array.

## File structure
- main.c file contains most of the usage of dynamic array library.

- utils.c file contains *all* of the functions to create a dynamic array.

- utils.h file contains the header functions for the main.c file.

- Makefile contains the command line configuration of the whole program.

## Interface

- build_d_array function builds a new dynamic array with the given values and the length(number of items) in linear time complexity $O(n)$.

- free_d_array function frees the memory that is being allocated during the build process of the given dynamic array in linear time constant time complexity $O(1)$.

- Print_both function prints both the underlying allocated memory and the items of the dynamic array in linear time complexity $O(n)$.

- print_d_array function prints the items of the dynamic array linear time complexity $O(n)$.

- print_all_d_array function prints all the underlying allocated memory in linear time complexity $O(n)$.

- d_array_append function appends to the given dynamic array with the given value in **amortized constant time complexity** $O(1_{(a)})$.

- d_array_prepend function prepends to the given dynamic array with the given value in **amortized constant time complexity** $O(1_{(a)})$.

- d_array_deque function deques the first element of the given dynamic array in **amortized constant time complexity** $O(1_{(a)})$.

- d_array_pop function pops the last element of the given dynamic array in **amortized constant time complexity** $O(1_{(a)})$.

- set_at function sets the index of the given dynamic array with value in constant time complexity $O(1)$.

- get_at function gets the item of the given dynamic array's index in constant time complexity $O(1)$. 

- delete_at functions deletes the given dynamic array's item with the given index and returns a new array if the index is neither first or last element of the dynamic array in linear time complexity $O(n)$.

You can compile the souce code using the `Makefile`.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./dynamic_array
```
Running the machine code is like running the tests.
```bash
./dynamic_array
```
Depending on your os, and your computer, the commands might be a little bit different.

## Limitations

### Resizing to be bigger
The dynamic array created in this library is resize according to the size of the dynamic_array_track. When there's no space for adding or deleting the item, it'll automatically resize bigger such that the **capacity** is twice as big as **size** of the dynamic array.

### Resizing to be smaller
The dynamic array created in this library is resize according to the size of the dynamic_array_track. If the current size is larger than **7** and the size is one fourth($\frac{1}{4}$) of the current capacity, it'll automatically resize smaller such that the **capacity** is twice as big as **current size** of the dynamic array.

NOTE: By making the current size to be larger than **7** as the we are making sure that the dynamic array is at least **2** capacity at all time before the free_d_array function is called, making it easier to add the items back.

### Preallocating
Preallocation is done by using calloc which might get overhead for very large dataset.

### Operation
Dynamic operation of the end is more suitable,  since the dynamic array allocate more memory (actually just one more item **see build_d_array and delete_at**) on the end rather than start of the array. This is due to the division by 2 on even number of length and odd number of length.
