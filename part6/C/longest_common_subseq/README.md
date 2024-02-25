# Introduction
This is the gentle introduction to dynamic programming which is finding longest common subsequence in constant number of sequences. 

## File structure

- `main.c` file contains the usage of finding length of the longest common subsequence in constant sequences.
- `utils.c` file contains the implementation of finding length of the longest common subsequence in constant sequences.
- `utils.h` file contains the header functions for implementation.
- `Makefile` file contains the command line customizations for the whole program.

## Specification

- Given two strings A and B, find a longest(**not necessarily contiguous**) subsequence of A that is also a subsequence of B.

- E.g.:  A = hieroglyphology, B = michaelangelo

- Solution: hello or heglo or iello or ieglo, all length 5.

- NOTE: MAXIMIZATION problem on length of subsequence.

## Interface

- `longest_common_subseq_recursive` finds the length of longest common subsequence using recursive approach(top down) in quadratic time complexity $O(|A|. |B|)$.

- `longest_common_subseq_iterative` finds the length of longest common subsequence using itrative approach(bottom up) in quadratic time complexity $O(|A|. |B|)$

You can compile the source code using the `Makefile`.

```bash
make
```
will compile and link all the source file to main executable.

Unlike python and go, we have to check memory leaks and other memory related issues using `valgrind`'s memcheck tool.

```bash
valgrind ./lcs
```
or
```bash
make valgrind
```

Running the executable is like outputting the results of the implementations. You can check if your implementations are correct or not.

```bash
./lcs
```
or
```bash
make run
```
Depending on your os and your computer, the commands might be a little different.

# References
Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
