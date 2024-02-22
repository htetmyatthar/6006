# Introduction
This is the gentle introduction to dynamic programming which is finding nth number of the fibonacci sequence.

## File structure

- `main.c` file contains the usage of finding nth fibonacci number functions.
- `utils.c` file contains the implementation of finding nth fibonacci number functions.
- `utils.h` file contains the header functions for implementation.
- `Makefile` file contains the command line customizations for the whole program.

## Specification
Implement a function that can find nth number of the fibonacci sequence.

## Interface

NOTE: in this program the nth is upper bound to 46 for easier implementation.

- `fibonacci_plain` function returns the nth number in fibonacci sequence in exponential time complexity $O(2^{n/2})$.

- `fibonacci_recursive` function returns the nth number in fibonacci sequence in linear time complexity $O(n)$.

- `fibonacci_iterative` function returns the nth number in fibonacci sequence in linear time complexity $O(n)$.

You can compile the source code using the `Makefile`.

```bash
make
```
will compile and link all the source file to main executable.

Unlike python and go, we have to check memory leaks and other memory related issues using `valgrind`'s memcheck tool.

```bash
valgrind ./fibonacci
```
or
```bash
make valgrind
```

Running the executable is like outputting the results of the implementations. You can check if your implementations are correct or not.

```bash
./fibonacci
```
or
```bash
make run
```
Depending on your os and your computer, the commands might be a little different.

## Limitation

- If the nth number is not upper bounded by 46, the running time for the below two functions will become as follows:
    $O(n + n^{2} / w)$
This is due to the fact that Fibonacci numbers grow to $\theta(n)$ bits long, potentially $\gg$ word size $w$.

# References
Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
