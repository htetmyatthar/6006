# Introduction

This is the section for creating simple hash function problem that is in the problem session 3 of [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_prob3/).

## File structure

- hash_it_main.go file contains the usage of hash map while implementing.

- hash_it_helpers.go file contains *all* the function to create a hashmap and extra functions that is related to hashmap.

- hash_it_test.go file contains the test cases for insertion sort.

## Specification

- Using the given array:
    
    **[67, 13, 49, 24, 40, 33, 58]**

- Using the given hash function:

    $h(k) = (11k + 14) mod 9$

- Implement a hash map.

- Resolving the collisions using chaining method.


## Interface

- hashFunction function hashes the given integer input using the hash function that is given by the problem. Returns the hashed value of the given input.

- NewHashMap function initialize a new HashMap struct using the given arraySize.

- HashMap.Create method creates a new underlying hashmap using the given input values as the nodes of the created hashmap in **expected linear time complexity $O(n_e)$**.

- HashMap.Find method finds the given value in the hashmap in **expected constant time complexity $O(1_e)$**.

- HashMap.PrintElements method prints the values of the hashmap in linear time complexity $O(n)$.

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/hash_it_out_problem$*

*To compile source code*
```bash
go build .
```

*Running go binary*
```bash
./hash_it_out_problem
```

*To compile the tests*
```bash
go test -c
```

*Running test binary*
```bash
./hash_it_out_problem.test -test.v
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

# Reference

Erik Demaine, Json Ku, Justin Solomon. MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCourseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
