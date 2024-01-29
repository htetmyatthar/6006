# Introduction

This is a section for creating breath first search.

## File structure

- main.c file contains the usage of breath first search during implementation.

- utils.c file contains the implementations for breath first search.

- graph.c file contains the implementations for graph.

- utils.h file contains the header functions for the breath first search.

- graph.h file contains the header functions for graph.

- Makefile contains the command line configuration for the whole program. Uses [Clang 17.0.6](https://clang.llvm.org)

## Specification

- Implement breath first search.

## Interface

- bfs function explore the given graph with the given starting point in linear time compelxity $O(|V|+|E|)$.

- find_path function finds one of the shortest path from given source to given destination in linear time complexity $O(|V|+|E|)$.

- init_queue function initialize the linked list queue in constant time complexity $O(1)$.

- enqueue function enqueue the given vertex in the given queue_list in constant time complexity $O(1)$.

- dequeue function dequeue the given vertex in the given queue_list in constant time complexity $O(1)$.

- free_queue_list function frees the memory that is allocated during the creation of given queue_list in linear time complexity $O(|V|)$.

- print_queue_list funciton prints the vertices in the given queue_list in lineat time complexity $O(|V|)$.

You can compile the source code using the `Makefile`.

```bash
make
```
will compile and link all the source file to main executable.

Unlike python and go, we have to check memory leaks and other memory related issues.

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
