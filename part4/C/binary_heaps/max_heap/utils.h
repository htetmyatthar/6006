#include <stdio.h>
#include "dynamic_array.h"

typedef dynamic_array heap;

// parent_index returns the parent of the given index.
int parent_index(int index);

// left_child_index returns the left child of the given index.
int left_child_index(int index, int n);

// right_child_index returns the right child of the given index.
int right_child_index(int index, int n);

// max_heapify_up makes the child index's value to satisfies max heap property.
void max_heapify_up(dynamic_array **d_array, int child);

// max_heapify_down makes the parent index's value to satisfies max heap property.
void max_heapify_down(dynamic_array **d_array, int parent);

// insert_to_heap appends the given value to the array.
void insert_to_heap(dynamic_array **d_array, int value);

// delete_max_heap returns the value of the maximum value of the 
int delete_max_heap(dynamic_array **d_array);

// build_heap_linear builds a new heap from the given array in linear time complexity.
void build_heap_linear(dynamic_array **array);

// heapify_down makes the parent index's value to satisfies max heap property.
// this works only on simple arrays.
// this is a healper function for heap_sort.
void heapify_down(int values[], int parent, int length);

// sort_max sorts the given heap array.
// this is a helper function for heap_sort.
void sort_max(int values[], int length);

// heap sort sorts the given values array in place.
void heap_sort(int values[], int length);

// print_heap prints out the values of the items in the given heap.
void print_heap(heap *heap);
