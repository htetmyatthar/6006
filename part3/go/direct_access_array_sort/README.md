# Introduction

This is the section for creating direct access array sort in golang, that is described in [MIT 6006, Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec5/)

## File Structure

- DAA_sort_main.go file contains the usage of direct access array sort when implementing.

- DAA_sort_helpers.go file contains the direct access array sort function.

- DAA_sort_test.go file contains the test cases for the DAASort function.

## Specification

- Given the array: 

    **[5, 2, 7, 0, 4]**

- Suppose all keys are unique non-negative integers in range $0, ..., u - 1$ so $n \le u$.

- Implement a sorting algorithm that has the running time of $O(u) = O(n)$.

## Pseudocode

1. Store the keys $u$ of $n$ items in the bucket array $u + 1$.

2. While storing the keys maintain the sorted order.

3. Go through the bucket array.

4. If the $i^{th}$ element has value (which is not empty), add the $i^{th}$ element to the original array resulting in sorted order.

## Interface

- DAASort function sorts the given values array in linear time complexity $\theta(u) = \theta(n)$ if $u = \theta(n)$.


You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/direct_access_array_sort$*

*To compile source code*
```bash
go build .
```

*Running go binary*
```bash
./direct_access_array_sort
```

*To compile the tests*
```bash
go test -c
```

*Running test binary*
```bash
./direct_access_array_sort.test -test.v
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

- This sorting algorithm is only good if the key $u$ is less than or equal to n.

- If keys are in larger range, like $u = \Omega(n^2) < n^2$, this sorting algorithm will take quadratic time complexity which is bad.

    - Consider the following $n$ items of array with keys $u$:

        **[17, 3, 24, 5, 11]**

    This example shows that we have to create a very large bucket array that has at least $24 + 1$ items and we have to walk through all of it to sort.

- For that cases we should use tuple sort or other kind of sorting algorithms for this specific problem.

# References

Erik Demaine, Json Ku, Justin Solomon. MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCourseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
