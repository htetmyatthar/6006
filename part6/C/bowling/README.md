# Introduction
This is the gentle introduction to dynamic programming which is finding the maximum points one can obtained by playing bolwing by a set of rules..

## File structure

- `main.c` file contains the usage of finding maximum points that can obtained by bowling.
- `utils.c` file contains the implementation of finding maximum points that can obtained by bowling.
- `utils.h` file contains the header functions for implementation.
- `Makefile` file contains the command line customizations for the whole program.

## Specification
Implement a function that can computer the best score we can get by the following rules:
    - Given $n$ pins labeled $0, 1, ..., n - 1$.
    - Pin i has value $v_i$.
    - Ball of size similar to pin can hit either
        - $1$ pin $i$, in which case we get $v_i$ points.
        - $2$ adjacent pins $i$ and $i + 1$, in which case we get $v_i . v_{i + 1}$ points.
    - Or skip the pin
    - Once a pin is hit, it can't be hit again(removed)

Goal: Throw zero or more balls to maximize total points.

e.g. $[-1, {1}, {1}, {1}, {9, 9}, {3}, {-3, -5}, {2, 2}]$

Curly braces as the pins that will hit together by a bowling ball.

## Interface

- `bowling_recursive` finds the maximum point using the recursive approach(top down) in linear time complexity $O(n)$.

- `bowling_iterative` finds the maximum point using the iterative approach(bottom up) in linear time complexity $O(n)$.

You can compile the source code using the `Makefile`.

```bash
make
```
will compile and link all the source file to main executable.

Unlike python and go, we have to check memory leaks and other memory related issues using `valgrind`'s memcheck tool.

```bash
valgrind ./bowling
```
or
```bash
make valgrind
```

Running the executable is like outputting the results of the implementations. You can check if your implementations are correct or not.

```bash
./bowling
```
or
```bash
make run
```
Depending on your os and your computer, the commands might be a little different.

# References
Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
