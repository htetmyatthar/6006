#include <stdio.h>
#include "dynamic_array.h"

typedef dynamic_array heap;

// parent_index returns the parent of the given index.
int parent_index(int index);

// left_child_index returns the left child of the given index.
int left_child_index(int index,int length);

// right_child_index returns the right child of the given index.
int right_child_index(int index,int length);

// min_heapify_up makes the child indes's value to satisfies min heap property.
void min_heapify_up(int *heap, int child);

// min_heapify_down makes the parent index's value to satisfies min heap property.
void min_heapify_down(int *heap, int parent, int length);

// heap_insert appends the given value to the heap.
void heap_insert(heap **heap, int value);

// heap_delete_min returns the value of the deleted min value in heap.
int heap_delete_min(heap **heap);

// build_heap_linear builds a new heap from the given array of values.
void build_heap_linear(int values[], int length);

// sort max sorts the given heap array, kicking out the min to the end.
// this is a helper function for heap sort.
void sort_max(int values[], int length);

// heap_sort sorts the given values array in place.
void heap_sort(int values[], int length);
