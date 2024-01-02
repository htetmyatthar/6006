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

### Edge Cases
- No error handling of index out of range error in MergeSortRange.
