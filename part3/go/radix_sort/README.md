# Introduction

This is the section for creating radix sort after facing all the struggles in [DAA sort](./direct_access_array_sort), [tuple sort](./tuple_sort), and multiple [counting sort](./counting_sort). This section is inspire by [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec5/)

## File structure

- radix_sort_main.go file contains the usage of radix sort while implementing.

- radix_sort_helpers.go file contains *all* the functions to create RadixSort.

- radix_sort_test.go file contains test cases for RadixSort.


## Specification

- Implement radix sort.

## Implementation notes

- Using counting sort as a auxillary sort so that we can have the benefits of stable sorting algorithms.

- Sort from least significant to most significant, so that we will have the benefits of previous sortings.

- Becareful when sorting the array of pointers to arrays.

- Becareful when calculating the max digits.

## Interface

- RadixSort function sorts the given array in linear time complexity $O(n + nlog_n{u}) = O(n)$ if $c$ is constant and $u = O(n^c)$ meaning if $u \le n^c$.

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/radix_sort$*

*To compile source code*
```bash
go build .
```

*Running go binary*
```bash
./radix_sort
```

*To compile the tests*
```bash
go test -c
```

*Running test binary*
```bash
./radix_sort.test -test.v
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

## Limitation

- Only if $c$ is constant, radix sort will run in linear time complexity.

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
