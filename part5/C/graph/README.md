# Introduction
This is a section for understanding graphs and implementing some operations.

## File structure

- main.c file contains the usage of graph's interface during implementation.

- utils.c file contains the implementations of the below [interface](#Interface).

- utils.h file contains the header functions for graph.

- Makefile contains the command line configuration for the whole program. Uses [Clang 17.0.6](https://clang.llvm.org).

## Specification

- Create a graph using the concept of adjacency list and hash tables.

## Interface

- create_graph function creates a graph with just the vertices in linear time $O(|V|)$.

- hash_function function hashes the given char to an integer in constant time complexity $O(1)$.

- create_node function creates a node for edges(specifically destination nodes) in constant time compelxity $O(1)$.

- add_edge function adds a new edge(add a new node to the hash map of vertices) in constant time compelxity $O(1)$.

- add_edges function adds new edges(add a new node to the hash map of vertices) in linear time compelxity $O(|V|)$.

- vertex_in_degree function returns the in degree of the given vertex in constant time complexity $O(1)$, by augmenting in hashmap.

- vertex_out_degree function returns the out degree of the given vertex in constant time complexity $O(1)$, by augmenting in hashmap.

- in_neighbors function returns the (source) neighbors of the given (destination) vertex in linear time complexity $O(|V| + |E|)$.

- out_neighbors function returns the (destination) neighbors of the given (source) vertex in linear time complexity $O(|E|)$.

- free_graph function frees the memory that is allocated during the creation of graph.

- print_adjacency_list function prints the given graph's adjacency list in linear time complexity $O(|V| + |E|)$.

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
