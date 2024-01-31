# Introduction

This is a section for finding weighted shortest path in a DAG.

## File structure

- `main.c` file contains the usage of depth first search during implementation.

- `utils.c` file contains the implementations for depth first search.

- `graph.c` file contains the implementations for graph.

- `dfs.c` file contains the implementations of depth first search.

- `dfs.h` file contains the header functions for dfs.

- `graph.h` file contains the header functions for graph.

- `utils.h` file contains the header functions for the depth first search.

- `Makefile` contains the command line configuration for the whole program. Uses [Clang 17.0.6](https://clang.llvm.org) compiler.

## Specification

- Implement an algorithm that can calculates the weighted shortest paths, using dfs.

## Interface

You can compile the source code using the `Makefile`.

```bash
make
```
will compile and link all the source file to main executable.

Unlike python and go, we have to check memory leaks and other memory related issues using `valgrind`'s memcheck tool.

```bash
valgrind ./weighted_shortest_path
```

or 

```bash
make valgrind
```

Running the machine code is like outputting the results of the implementations. You can check if your implementations are correct or not.

```bash
./weighted_shortest_path
```

or 

```bash
make run
```
Depending on your os, and your computer, the commands might be a little different.

# References
Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
