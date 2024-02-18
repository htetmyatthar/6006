# Introduction

This is a section for finding all pairs hortest paths(APSP) in a general graph.

![Dijkstra test graph photo](Dijkstra_test_graph.png)

## File structure

- `main.c` file contains the usage of Dijkstra's algorithm during implementation.

- `utils.c` file contains the implementations for Jhonson's algorithm.

- `Bellman-Ford.c` file contains the implementations for Bellman-Ford algorithm.

- `Dijkstra.c` file contains the implementations for Dijkstra's algorithm

- `DAG_relaxation.c` file contains the implementations for DAG RELAXATION.

- `dfs.c` file contains the implementations for depth first search algorithm.

- `graph.c` file contains the implementations for graph.

- `graph.h` file contains the header functions for graph.

- `dfs.h` file contains the header functions for depth first search algorithm.

- `DAG_relaxation.h` file contains the header functions for DAG RELAXATION.

- `Dijkstra.h` file contains the header functions for Dijkstra's algorithm

- `Bellman-Ford.h` file contains the header functions for Bellman-Ford algorithm.

- `utils.h` file contains the header functions for Jhonson's algorithm.

- `Makefile` contains the command line configuration for the whole program. Uses [Clang 17.0.6](https://clang.llvm.org) compiler.

## Specification

- Implement Jhonson's algorithm for calculating all pairs shortest paths.

## Interface

- `Jhonson` function returns the all pairs shortest in $O(|V|.|E|log|V|)$ since the underlying Dijkstra algorithm is using min heaps.

You can compile the source code using the `Makefile`.

```bash
make
```
will compile and link all the source file to main executable.

Unlike python and go, we have to check memory leaks and other memory related issues using `valgrind`'s memcheck tool.

```bash
valgrind ./Jhonson
```

or 

```bash
make valgrind
```

Running the machine code is like outputting the results of the implementations. You can check if your implementations are correct or not.

```bash
./Jhonson
```

or 

```bash
make run
```
Depending on your os, and your computer, the commands might be a little different.

## Limitations

- In this example the underlying Dijkstra's algorithm uses min heap.

# References
Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
