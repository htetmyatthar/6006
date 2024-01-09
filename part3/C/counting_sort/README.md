# Introduction

This is the section for impelementing counting sort in 2 different ways. In these parts I played with the way that I wanted to tried. So these sorting algorithms are not fully optimized. These algorithms are inspire by[MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_r05/)

## File structure

- main.c file contains usage of counting_sort_chaining and counting_sort_cumulative.

- utils.c file contains the function for both sorting algorithms.

- utils.h file contains the header functions for the main.c file.

- Makefile contains the command line configuration for the whole program.

## Specification

- Supposing all keys are non-negative integers in range$0,......,u - 1$, so $n \le u$.

- Since using tuple sort can't handle the non-colliding keys,

- Implement a sorting algorithm(counting sort) that can sort the given array, that might collide.

    **[17, 3, 24, 22, 12]**

## Pseudocode

### Counting sort using cumulative sum (easier way, more memory efficient)

```
1. find largest key u
    2. allocate memory A that can hold keys u for counting
3. add counts to A, the occurence of original array value n_i
4. calculate the cumulative sum, A[i] = A[i] + A[i - 1]
    5. allocate memory B that can hold the sorted values n
6. sort to B, using the original values and A.
```
We return the sorted array in this, so we didn't free.

### Counting sort using chaining. (bucket sort, hashing sort, harder.)

```
    1. allocate memory A that can hold n for tuples
2. calculate the tuple values
    3. allocate memory B that can hold length for counting
4. add counts to B, the occurence of tuples' least significant value A[i]->least.
5. calculate the cumulative sum, B[i] = B[i] + B[i - 1]
    6. allocate memory C, that can hold n for tuples
7. sort to C, using the A and B.
8. find largest key u_m for more significant values
    9. free(A and B)
    10. allocate memory H, that can hold u_m for sorting more significant values
11. sort to H, using C.
12. copy the sorted hash table to original array. k = an + b
    13. free(H)
```
Memory B is the one to use counting the least significant. Least significant is **upper bounded by length**.(mod)

### Counting sort using trie. (use tons of memory, but mid, the one that is in lecture.)
```
    1. allocate memory A that can hold n for tuples
2. calculate the tuple values
    2. allocate memory B that can hold largest key of more significant (u + 1) * n for sorting
3. place the A[i]->more in B[u], A[i]->least in B[n]
4. sort to original array, using B. k = an + b
    5. free(A, B)
```
IDEA: this might good for strings, due to 2 dimensional array.

## Implementation notes

- Using an auxilliary **sorting algorithms** to separately sort each key in counting_sort_chaining.

- Sort from least significant to most significants, so that we will have the benifits of sorting.

## Interface

- counting_sort_chaining sorts the given values array using auxillary sorting as counting_sort_summing for least significant keys. This sort can sorts an array in linear time complexity, $O(n + u) = O(n)$ if  $u \le O(n)$.

- counting_sort_summing sorts the given values array using the cummulative summing in linear time complexity, $O(n + u) = O(n)$ if $u \le O(n)$.

- print_array prints the values in the given array in linear time complexity $O(n)$.

- free_tuple_array frees the memory that is allocated during the creation of tuple_array in linear time complexity, $O(n)$.This is due to the fact that we have to frees the tuples, not just the array.

- free_tuple_array_chain frees the memory that is allocated during the creation of tuple_array_chain in linear time complexity, $O(n + u) = O(n)$. This is due to the fact that we have to go through every index of the array and all the chains.

- print_hr prints a visual line in constant time complexity $O(1)$.

    - **please do mind the limitations**

You can compile the souce code using the `Makefile`.
```bash
make
```
will compile and link all the source file to the executable.

Unlike python and go, we have to do memory management manually. You can use **valgrind** tool to check the memory leaks while running the program as follows:
```bash
valgrind --leak-check=full ./counting_sort
```
Running the machine code is like running the tests.
```bash
./counting_sort
```
Depending on your os, and your computer, the commands might be a little bit different.

## Limitations

- counting_sort_chaining uses too much time freeing and chaining and sorting.

- counting_sort_trie uses too much space for sorting.

- Although these chaining sorts solves the problems of the tuple sort which is stability for colliding keys and repeated keys, we still being hold back by the keys sizes. Consider the following case: what if keys are larger than $n^2$?

    - sort using the auxillary counting sort to sort tuples(a, b)

- We should use [**radix sort**](../radix_sort/) for that.

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons B
