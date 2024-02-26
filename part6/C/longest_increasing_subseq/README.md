# Introduction
This is the gentle introduction to dynamic programming which is finding longest increasing subsequence in a sequence.

## File structure

- `main.c` file contains the usage of finding longest increasing subsequence in a sequence.
- `utils.c` file contains the implementation of finding longest increasing subsequence in a sequence.
- `utils.h` file contains the header functions for implementation.
- `Makefile` file contains the command line customizations for the whole program.

## Specification

- Given a string, A, find a longest(not necessarily contiguous) subsequence of A that strictly increases(lexicographically).

- E.g.: A = carbohydrate

- Solution: abort, of length 5

- MAXIMIZATION of problem on length of subsequence.

## Interface

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
