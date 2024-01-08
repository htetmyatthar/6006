#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
	int first;	// more significant part
	int second;	// least significant part 
}tuple;

// tuple_sort sorts the given values array using the a, b = divmod(k, n)
// if the given values has
// 1. NO COLLIDING VALUES FOR (a).
// 2. NO COLLIDING VALUES FOR (b).
// if there are colliding values of a and b in the given array the program will crash since 
// the auxillary sorts are implemented using the dynamic access array sort method.
// if the values in the given array are not less than length^2 the program will crash resulting in error.
void tuple_sort(int values[], int length);

// free_tuple_array frees the array of pointers to tuples.
void free_tuple_array(tuple **tuple_array, int length);

