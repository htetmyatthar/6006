# Introduction

This is the section for creating selection sort.

## File structure

- selection_sort_main.go file contains the usage of selection sort while implementing.

- selection_sort_helpers.go file contains the function of selection sort.

- selection_sort_test.go file contains the test cases for selection sort.

## Specification

- implement selection sort algorithm.

## Pseudocode

```
For i from 0 to n–1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]
```
Reference: [CS50](https://cs50.harvard.edu/x/2023/notes/3/#sorting)

## Interface

- SelectionSort function sorts the given array in $O(n^2)$. Returns error if the given array is empty.

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/selection_sort$*

*To compile source code*
```bash
go build .
```

*Running go binary*
```bash
./selection_sort
```

*To compile the tests*
```bash
go test -c
```

*Running test binary*
```bash
./selection_sort.test -test.v
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
