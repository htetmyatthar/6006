# Introduction

This section is for creating tuple sort using the direct access array sort as auxillary sorting method. This section is inspire by [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_lec5/)

## File structure

- tuple_sort_main.go file contains the usage of tuple sort while implementing.

- tuple_sort_helpers.go file contains the function for tuple sort algorithm.

- tuple_sort_test.go file contains the test cases for tuple sort.

## Specification

- Supposing all keys are unique non-negative integers in range ${0, ....., u - 1}$, so $n \le u$.

- Since using larger keys $u$ in direct access array sort is bad for $u = \Omega(n^2) < n^2$.

- While representing the each key by tuple $(a, b)$ where $k = an + b$ and $0 \le b < n$.

    - **This will result in $2$ digit base $n$. $a = k / 2 < n \quad and \quad b = (k\quad mod\quad n)$**

- Using the given array which there are no collisions of $a$ and $b$ for $a, b = divmod(k, n)$.

    - **[17, 3, 24, 5, 11]**

- Implement tuple sort.

## Implementation notes

- Using an auxillary sorting algorithm to seperately sort each key.

- Sort from least significant to more significant, so that we will have the benifits of previous sorts.

## Interface

- TupleSort function sorts the given values array using the direct access array method in average linear time complexity $\theta(u) = \theta(n)$ if $u = \theta(n)$
    
    **This implementation has limitations.**

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/tuple_sort$*

*To compile source code*
```bash
go build .
```

*Running go binary*
```bash
./tuple_sort
```

*To compile the tests*
```bash
go test -c
```

*Running test binary*
```bash
./tuple_sort.test -test.v
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

TupleSort sorts the given values array using the formula $a, b = divmod(k, n)$

If the given values has:
    
    1)colliding values for $(a)$.
    2)colliding values for $(b)$.

    - If there are colliding values for both $a$ and $b$ in the given array, the program will crash since the auxillary sorts that are implemented are using the dynamic access array sort method.

## Note

- In this tuple sorting algorithm due to the nature of it, many integers could have the same $a$ and $b$ value, even if the input keys are distinct.

- Consider the following array:

    **[17, 3, 24, 22, 12]**

    **[(3, 2), (0, 2), (4, 4), (4, 2), (2, 2)]**

- Since we used the DAASort as the auxiliary sorting algorithm we will crash if we sort this array.

- **So we need to sort allowing *repeated keys* which preverses input order**.

- **And we also want our sort to be *stable*: repeated keys appear in output in same order as input.**

- **So we can't use DAASort anymore since it can't even sort arrays that are having repeated keys.**

- **We should chain them instead of storing one by on just like hashing.**

# Reference

Erik Demaine, Json Ku, Justin Solomon. MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCourseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
