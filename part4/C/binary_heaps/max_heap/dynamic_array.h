#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// one sided dynamic array optimized for end.
typedef struct
{
	int *base;			// base is the pointer to underlying base array's first item.
	int capacity;		// capacity is the length the underlying base array.
	int size;			// size is length of the inside array.
} dynamic_array;

// build_dynamic_array builds a new dynamic array for only dynamic in the end.
// dynamic_array has extra n items at the end of the array, having 2n capacity where n is size.
dynamic_array* build_dynamic_array(int values[], int length);

// free_dynamic_array frees all the memory that is allocated during the creation of dynamic array.
// exit code (1) if the given dynamic array is NULL.
void free_dynamic_array(dynamic_array *d_array);

// dynamic_swap will swap the values of the two indexes.
// Expects the zero-indexed indexes.
// exit code (1) if the dynamic array is NULL.
// exit code (2) if the given indexes are the same.
// exit code (3) if the given indexes are out of range.
void dynamic_swap(dynamic_array *d_array, int first_index,int second_index);

// dynamic_array_append appends a new value to the given dynamic array resizing if needed.
// Resize only when there are no spaces left to append.
// exit code (1) if the given dynamic array is NULL.
void dynamic_array_append(dynamic_array **d_array, int value);

// dynamic_array_pop pops the last item in the given dynamic array resizing if needed.
// Returns the deleted item's value.
// Resize only when the capacity is larger than 7. Resize if half of space is blank.
// exit code (1) if the given dynamic array is NULL.
// exit code (2) if there's no items to pop.
int dynamic_array_pop(dynamic_array **d_array);

// print_underlying prints the all values of the given dynamic array.
// print empty dynamic array if d_array is NULL.
void print_underlying(dynamic_array *d_array);

// print_array prints the only the inside values of the given dynamic array.
// print empty dynamic array if d_array is NULL.
void print_array(dynamic_array *d_array);

// print_both prints seperately using print_underlying and print_array.
// prints all the values of the dynamic array and prints only the values inside seperately.
// print empty dynamic array if d_array is NULL.
void print_both(dynamic_array *d_array);
