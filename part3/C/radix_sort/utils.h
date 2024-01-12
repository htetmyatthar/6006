#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// radix_sort sorts the given values and rewrite the original values with the sorted values.
// when rewriting all the leading zeros will be removed.
void radix_sort(int values[], int length);

// counting_sort sorts the given array of pointers to the array using the indexes of pointed arrays.
// this counting sort is used as a auxillary sort in the radix sort.
// That's why counting sort will sort the array of pointers.
void counting_sort(int* values[], int length, int index, int max_key_size);

// free_arrays frees the memory that is allocated during the creation of array of pointers to the arrays.
// also freeing the arrays that is being pointed.
void free_arrays(int **values, int length);

// print_array prints the array's values using comma as a separator.
void print_array(int values[], int length);
