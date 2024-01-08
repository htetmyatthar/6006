# Introduction

This is the section for creating simple hash function problem that is in the problem session 3 of [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_prob3/).

## Specification

- Using the given array:
    **[67, 13, 49, 24, 40, 33, 58]**

- Using the given hash functions:
    **$h(k) = (11k + 14)  mod  9$**

- Resolve the collisions using chaining method.

## File structure

- main.c file contains the usage of hash table that is created per the problem set.

- utils.c file contains *all* the functions to create a hash map.

- utils.h file contains the header functions and product data type for chaining.

- Makefile contains the command line configuration of the whole program.


## Interface

- hash_map function creates a hash map in the heap returning the address of the created hash map in **expected linear time complexity** $O(n_e)$.

- print_map function prints out the values in the hash map in linear time complexity $O(n)$

- hash_function function hashes the input value to the hashed value in constant time complexity $O(1)$.

- find function finds the given value in the given hash table in**expected constant time complexity** $O(1_e)$.

You can compile the souce code using the `Makefile`.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./hash_it_out
```
Running the machine code is like running the tests.
```bash
./hash_it_out
```
Depending on your os, and your computer, the commands might be a little bit different.
