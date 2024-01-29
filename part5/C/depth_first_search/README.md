# Introduction

This is a section for creating breath first search.

## File structure

- main.c file contains the usage of depth first search during implementation.

- utils.c file contains the implementations for depth first search.

- graph.c file contains the implementations for graph.

- utils.h file contains the header functions for the depth first search.

- graph.h file contains the header functions for graph.

- Makefile contains the command line configuration for the whole program. Uses [Clang 17.0.6](https://clang.llvm.org) compiler.

## Specification

- Implement depth first search. Including full dfs.

## Interface

- `full_dfs` function explore the given graph's all vertices in linear time complexity $O(|V|+|E|)$.

- `dfs function` explore the given graph using single source in lineat time complexity $O(|E|)$. Same as dfs_recursion but has more error handling.

- `dfs_recursion` explore the given graph using single source in linear time complexity $O(|E|)$.

- `init_queue` function initialize the linked list queue in constant time complexity $O(1)$.

- `enqueue` function enqueue the given vertex in the given queue_list in constant time complexity $O(1)$.

- `dequeue` function dequeue the given vertex in the given queue_list in constant time complexity $O(1)$.

- `free_queue_list` function frees the memory that is allocated during the creation of given queue_list in linear time complexity $O(|V|)$.

- `print_queue_list` funciton prints the vertices in the given queue_list in lineat time complexity $O(|V|)$.

You can compile the source code using the `Makefile`.

```bash
make
```
will compile and link all the source file to main executable.

Unlike python and go, we have to check memory leaks and other memory related issues using `valgrind`'s memcheck tool.

```bash
valgrind ./depth_first_search
```

or 

```bash
make valgrind
```

Running the machine code is like outputting the results of the implementations. You can check if your implementations are correct or not.

```bash
./graph
```

or 

```bash
make run
```
Depending on your os, and your computer, the commands might be a little different.

# References
Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
