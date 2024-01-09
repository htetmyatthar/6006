#include <stdlib.h>
#include <stdio.h>

// tuple node for linked_list like behavior.
typedef struct tuple
{
	int first;				// to store the more significant.
	int second;				// to store the least significant
	struct tuple *next;		// pointer to the next tuple.
}tuple;

// sorts the values using chaining method, sort like hashing.
// overwrite the sorted values to the given values.
// only allow values that are larger than zero.
void counting_sort_chaining(int values[], int length);

// sorts the values using cumulative sum method.
// returns an array that is sorted.
// only allow values that are larger than zero.
int* counting_sort_summing(int values[], int length);

// prints out the values inside the given array.
void print_array(int array[], int length);

// frees the memory that is allocated during the creation of tuple_array including the tuples.
void free_tuple_array(tuple **array, int length);

// frees the memory that is allocated during the creation of tuple_array_chain.
void free_tuple_array_chain(tuple **array, int length);

// prints out a visual line.
void print_hr();

