# Introduction

This is one of the problems of problem session from [MIT 6006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/mit6_006s20_prob2sol/).

## Specification

- Houses go from left to right $n$ of houses.

    - An array that contains the $n$ numbers.

- If the wolf blows a house containing $b$ bricks from left, that house will fall down, along with every house right of it containing strictly fewer than b bricks.

    - If we take any number $b$ in the array, the numbers to the right that are in $n$ which are less than the chosen number will be marked as **damaged**.

- For every house in the array, the wolf wants to know it's damage.

    - How many damaged?

### Part (a)

- Suppose $n$ = 10, compute for damage for **all item $n_i$** that is chosen in the below array.

**[34, 57, 70, 19, 48, 2, 94, 7, 63, 75]**

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
