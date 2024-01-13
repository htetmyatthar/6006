# Merge sort
This is the section for creating merge sort.

## File structure
- merge_sort_main.go file contains the general usage of merge sort.
- merge_sort_test.go file contains the test cases for merge sort.
- utils.go file contains implementation for merge sort.

## Specification
- implement a sorting algorithm that has the runtime of O(nlogn).Merge sort.

## Pseudocode
```
If only one number
    Quit
Else
    Sort left half of number
    Sort right half of number
    Merge sorted halves
```
Reference: [CS50](https://cs50.harvard.edu/x/2023/notes/3/#merge-sort)

## Interface

- MergeSort function sorts the given array.
- MergeSortRange function sorts the given array of given range.

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/merge_sort$*

*To compile source code*
```bash
go build .
```

*Running go binary*
```bash
./merge_sort
```

*To compile the tests*
```bash
go test -c
```

*Running test binary*
```bash
./merge_sort.test
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


### Edge Cases
- No error handling of index out of range error in MergeSortRange.
