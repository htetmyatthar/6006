# Introduction

This is the section for impelementing counting sort in 2 different ways. In these parts I played with the way that I wanted to tried. So these sorting algorithms are not fully optimized. These algorithms are inspire by[MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_r05/)

## File structure

- counting_sort_main.go file contains the usage of different counting_sort while implementing.

- counting_sort_helpers.go file contains the multiple counting sort algorithms using different approaches and methods.

- counting_sort_test.go file contains the test cases for different counting_sort

## Specification

- Supposing all keys are non-negative integers in range $0,......,u - 1$ , so $n \le u$.

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
**IDEA**: This might good for strings, due to 2 dimensional array.

**Caution**: Although pseudocodes are for C programming language, you can reference it to implement it in golang.

## Implementation notes

- Using an auxilliary **sorting algorithms** to separately sort each key in CountingSortChain.

- Sort from least significant to most significants, so that we will have the benifits of sorting.

## Interface

- CountingSortChain sorts the given values array using CountingSortSum as auxilliary sorting algorithm for least significant keys. This can sorts an array in linear time complexity, $O(n + u) = O(n)$ if $u \le O(n)$.

- CountingSortSum sorts the given values array using the cummulative summing in linear time complexity $O(n + u) =  O(n)$ if $u \le  O(n)$.

    **These implementations have limitations.**

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/counting_sort$*

*To compile source code*
```bash
go build .
```

*Running go binary*
```bash
./counting_sort
```

*To compile the tests*
```bash
go test -c
```

*Running test binary*
```bash
./counting_sort.test -test.v
```

*To run the source code without compiling*
```bash
go run .
```

*To run the tests without compiling*
```bash
go test -v .
```

*To check the documentation*
```bash
go doc -all
```
Depending on your os, and your computer, the commands might be a little different.

## Limitations

- CountingSortChain uses too much time for chaining and sorting compare to CountingSortSum.

- CountingSortTrie uses too much space for sorting.

- Although these chaining sorts solve the problems of the tuple sort which is stability for colliding keys and repeated keys, we still being hold back by the keys' sizes.

    - Consider the following case: what if keys are larger than $n^2$ ?

        IDEA: Sort using the auxillary counting sort to sort tuples (a, b)

- Then we should use [radix_sort](./go/radix_sort) for that.

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons B
