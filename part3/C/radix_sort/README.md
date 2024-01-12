# Introduction

This is the section for creating radix sort after facing all the struggles in [DAA sort](./direct_access_array_sort), [tuple sort](./tuple_sort), and multiple [counting sort](./counting_sort). This section is inspire by [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec5/)

## File structure

- main.c file contains the usage of radix sort.

- utils.c file contains the functions to creat radix sort and helper functions for main.c file.

- utils.h file contains the header functions for main.c file.

- Makefile contains the command line configuration for the whole program.

    - this one is different since we have to use math library.

## Specification

- Implement radix sort.

## Implementation notes

- Using counting sort as a auxillary sort so that we can have the benefits of stable sorting algorithms.

- Sort from least significant to most significant, so that we will have the benefits of previous sortings.

- Becareful when sorting the array of pointers to arrays.

## Interface

- radix_sort function sorts the given arrays with the given length in linear time complexity $O(nc) = O(n)$ if $c$ is constant.

- counting_sort function sorts the given array of pointers to the array in linear time complexity $O(n + u) = O(n)$ if $u \le O(n)$. This function act as an helper function for radix_sort function.

- free_arrays frees the memory that is allocated during the creation of array of pointers to the arrays in linear time complexity $O(n)$. In the process frees the memory of the arrays that is being pointed.

- print_array prints the array's values using comma as a seperator in linear time complexity $O(n)$.

You can compile the souce code using the `Makefile`.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./radix_sort
```
Running the machine code is like running the tests.
```bash
./radix_sort
```
Depending on your os, and your computer, the commands might be a little bit different.

## Limitations

- In this implementation we just consider the sorting of decimal values. We have to change the FORMAT in utils.c for wanting to sort other formats such as hex, octet.

- Cavaet is only if c is constant, radix sort will run in linear time.

## Note 

- This sorting algorithm solves *all* the problems that the other sorting algorithms faced.
    - [direct_access_array_sort](./direct_access_array_sort),

        which cannot sorts the keys efficiently when values of arrays are more than $n^2$.

    - [tuple_sort](./tuple_sort), 

        which cannot sorts the given array guareentee stablity, repeated keys

    - [counting_sort](./counting_sort)

        - counting_sort_trie which cannot sort large number of values efficiently due to too much memory usage.

        - counting_sort_chaining which cannot sort larger keys that are more than $n^2$ due to chaining.

        - counting_sort_summing is pretty good but we wanted more than that.

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
