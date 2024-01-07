# Introduction

This is the section for creating binary search using golang.

## File structure
- binary_search_demonstration.go file contains the usage of binary_search algorithm.
- binary_search.go file contains the binary_search algorithm.

## Specification

- implement a searching algorithm that has the $O(log n) time complexity.

## Pseudocode
```txt
if no doors
    return false
if 50 is behind doors[middle]
    return true
else if 50 < door[middle]
    search doors[0] through doors[middle - 1]
else if 50 > door[middle]
    search doors[middle + 1] trough doors[n - 1]
```
Reference: [CS50](https://cs50.harvard.edu/x/2023/notes/3/#algorithms)

## Interface
- binary_search search the value in the given slice in $O(log n)$ time complexity.

Note: Due to the nature of usefulness on searching large amount of items with binary search. I used the technique that won't cause integer overflow when calculating middle index.

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/binary_search$*

*To compile source code*
```bash
go build .
```
*To run the source binary*
```bash
./binary_search
```

*To compile the tests*
```bash
go test -c
```
*To run the test binary*
```bash
./binary_search.test
```

*To run the source code without compiling*
```bash
go run .
```

*To run the tests without compiling*
```bash
go test .
```

*To check the documentation*
```bash
go doc -all
```
Depending on your os, and your computer, the commands might be a little different.

# References
David J. Malan. CS50 Introduction to computer science. 2023. Harvard University: CS50,https://cs50.harvard.edu/x/
