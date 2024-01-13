# Introduction

This is the section for creating bubble sort.

## File structure

- bubble_sort_main.go file contains the usage of bubble sort while implementing.

- bubble_sort_helpers.go file contains the function of bubble sort.

- bubble_sort_test.go file contains the test cases for bubble sort.

## Specification

- implement bubble sort algorithm.

## Pseudocode

```
Repeat n - 1 times
For i from 0 to n - 2
    If numbers[i] and numbers[i + 1] out of order
        Swap them
```
Reference: [CS50](https://cs50.harvard.edu/x/2023/notes/3/#sorting)

## Interface

- BubbleSort function sorts the given array in $O(n^2)$. Returns error if the given array is empty.

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/bubble_sort$*

*To compile source code*
```bash
go build .
```

*Running go binary*
```bash
./bubble_sort
```

*To compile the tests*
```bash
go test -c
```

*Running test binary*
```bash
./bubble_sort.test -test.v
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
