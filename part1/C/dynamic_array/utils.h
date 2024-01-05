#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Pointer that will track of the dynamic array
typedef  struct 
{
	int *base;		// start of the larger(underlying) array
	int capacity;	// the capacity of the array
	int size;		// the current number of items
	int start;		// start of the small array
}dynamic_array_track;

dynamic_array_track*  build_d_array(int values[], int length);

void free_d_array(dynamic_array_track *d_array);

void Print_both(dynamic_array_track *d_array);

void print_d_array(dynamic_array_track *d_array);

void print_all_d_array(dynamic_array_track *d_array);

dynamic_array_track* d_array_append(dynamic_array_track *d_array, int value);

dynamic_array_track* d_array_prepend(dynamic_array_track *d_array, int value);

dynamic_array_track* d_array_pop(dynamic_array_track *d_array);

dynamic_array_track* d_array_dequeue(dynamic_array_track *d_array);

void set_at(dynamic_array_track *d_array, int index, int value);

int get_at(dynamic_array_track *d_array, int index);

dynamic_array_track* delete_at(dynamic_array_track *d_array, int index);

void print_hr(void);
