# Introduction

This is the section for creating insertion sort.

## File structure

- insertion_sort_main.go file contains the usage of insertion sort while implementing.

- insertion_sort_helpers.go file contains the function of insertion sort.

- insertion_sort_test.go file contains the test cases for insertion sort.

## Specification

- implement insertion sort algorithm.

## Pseudocode

```
For i from 1 to n - 1
	j = i
	If there's still items to check(j > 0) and those items are bigger than the current item.
		Swap the current item and the 
		Decrement j
```

## Interface

- InsertionSort function sorts the given array in $O(n^2)$. Returns error if the given array is empty.

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/insertion_sort$*

*To compile source code*
```bash
go build .
```

*Running go binary*
```bash
./insertion_sort
```

*To compile the tests*
```bash
go test -c
```

*Running test binary*
```bash
./insertion_sort.test -test.v
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
