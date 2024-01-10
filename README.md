# Introduction
This is my repository for playing with algorithms using the study materials of[ MIT 6006](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020) Introduction to Algorithms course.

I will use Python and Golang for this and occassionally C if I am really bored.
I am trying to learn Golang using this course as my guide.

# Testing
Everything will be tested. And you can find that in seperate test files.
For C, memory leaks are detected by valgrind. For Golang, go fmt tool is used to format.
For Python, black formatter is used.

# Model of Computation
Specification for what operations on the machine can be performed in O(1) time.

In this code base, the WORD-RAM is used.

- Machine word: block of a bits(a is word size of a a-bit WORD-RAM)

- Memory: Addressable sequence of machine words

- Processor supports many constant time operations on a O(1) number of words(integer):
    - integer arithmethic:(+, -, *, //, %)

    - logical operators:(&&, ||, !, ==, <, >, <=, =>)

    - bitwise arithmetic: (&, |, <<, >>, ...)

    - Given word n, can read word at address n, write word to address n

- Memory address must be able to access every place in memory

    - Requirement: a >= # bits to represent largest memory address, i.e., log base 2 of n
    
    - 32-bit words --> max\~**4GB** memory, 

    - 64-bit words --> max\~**16exabytes** of memory

# Cautions

**Constants matter in algorithms**, you should never assume how fast or slow just judging by their runtimes on worst case(upper bound) ($O$), best cases(lower bound) ($\Omega$), or average cases(tight bound) ($\theta$).

**Don't get fooled by the runtimes, cruch the numbers**

All algorithms and data structures implemented in this are **not** fully optimized, but good enough for introducing the concepts and using it a bit.

All algorithms and data strucutures should be implement, build and use **differently** based on **different use cases**.
