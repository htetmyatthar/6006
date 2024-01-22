#include "utils.h"

int parent_index(int index)
{
	int parent = (index - 1) / 2;
	if (index > 0)
	{
		return parent;
	}
	return index;
}

int left_child_index(int index,int length)
{
	int left_child = (index * 2) + 1;
	if(left_child < length)
	{
		return left_child;
	}
	return index;
}

int right_child_index(int index,int length)
{
	int right_child = (index * 2) + 2;
	if(right_child < length)
	{
		return right_child;
	}
	return index;
}

void min_heapify_up(int *heap, int child)
{
	int parent = parent_index(child);
	printf("%d, ", parent);
	if(heap[parent] > heap[child])
	{
		int temp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = temp;

		min_heapify_up(heap, parent);
	}
	return;
}

void min_heapify_down(int *heap, int parent, int length)
{
	int left_child = left_child_index(parent, length);
	int right_child = right_child_index(parent, length);

	int smaller_index = left_child;

	if(heap[right_child] < heap[smaller_index])
	{
		smaller_index = right_child;
	}

	if(heap[parent] > heap[smaller_index])
	{
		int temp = heap[parent];
		heap[parent] = heap[smaller_index];
		heap[smaller_index] = temp;

		min_heapify_down(heap, smaller_index, length);
	}
	return;
}

void heap_insert(heap **heap, int value)
{
	dynamic_array_append(heap, value);
	min_heapify_up((*heap)->base, (*heap)->size - 1);
}

int heap_delete_min(heap **heap)
{
	dynamic_swap(*heap, 0, (*heap)->size - 1);
	int deleted_value = dynamic_array_pop(heap);
	min_heapify_down((*heap)->base, 0, (*heap)->size);
	return deleted_value;
}

void build_heap_linear(int values[], int length)
{
	for(int i = (length / 2) - 1; i >= 0; i--)
	{
		min_heapify_down(values, i, length);
	}
}

void sort_max(int values[], int length)
{
	if(length == 1)
	{
		return;
	}

	int temp = values[0];
	values[0] = values[length - 1];
	values[length - 1] = temp;

	min_heapify_down(values, 0, length - 1);
	sort_max(values, length - 1);
}

void heap_sort(int values[], int length)
{
	for(int i = (length / 2) - 1; i >= 0; i--)
	{
		min_heapify_down(values, i, length);
	}
	sort_max(values, length);
}
