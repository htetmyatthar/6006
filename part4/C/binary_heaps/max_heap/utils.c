#include "utils.h"

// heap_sort

int parent_index(int index)
{
	int parent = (index - 1) / 2;
	if(index > 0)
	{
		return parent;
	}
	return index;
}

int left_child_index(int index, int n)
{
	int left = (index * 2) + 1;
	if(left < n)
	{
		return left;
	}
	return index;
}

int right_child_index(int index, int n)
{
	int right = (index * 2) + 2;
	if(right < n)
	{
		return right;
	}
	return index;
}

void max_heapify_up(heap **heap, int child)
{
	int parent = parent_index(child);
	if ((*heap)->base[parent] < (*heap)->base[child])
	{
		dynamic_swap(*heap, parent, child);
		max_heapify_up(heap, parent);
	}
	return;
}

void max_heapify_down(heap **heap, int parent)
{
	int left_child = left_child_index(parent, (*heap)->size);
	int right_child = right_child_index(parent, (*heap)->size);

	int bigger_index = left_child;
	// compare the values decide the bigger index.
	if((*heap)->base[right_child] > (*heap)->base[left_child])
	{
		bigger_index = right_child;
	}

	// compare the values swap if necessary.
	if((*heap)->base[parent] < (*heap)->base[bigger_index])
	{
		dynamic_swap(*heap, parent, bigger_index);
		max_heapify_down(heap, bigger_index);
	}
	return;
}

void insert_to_heap(heap **heap, int value)
{
	dynamic_array_append(heap, value);
	max_heapify_up(heap, (*heap)->size - 1);
}

int delete_max_heap(heap **heap)
{
	dynamic_swap(*heap, 0, (*heap)->size - 1);
	int deleted_value = dynamic_array_pop(heap);
	max_heapify_down(heap, 0);
	return deleted_value;
}

void build_heap_linear(dynamic_array **array)
{
	for (int i = ((*array)->size / 2) - 1; i >= 0; i--)
	{
		max_heapify_down(array, i);
	}
}

void heap_sort(int values[], int length)
{
	for(int i = (length / 2) - 1; i >= 0; i--)
	{
		heapify_down(values, i, length);
	}
	sort_max (values, length);
}

void sort_max(int values[], int length)
{
	if(length == 1)
	{
		return;
	}
	//swap
	int temp = values[0];
	values[0] = values[length - 1];
	values[length - 1] = temp;

	heapify_down(values, 0, length - 1);

	sort_max(values, length - 1);
}

void heapify_down(int values[], int parent, int length)
{
	int left_index = left_child_index(parent, length);
	int right_index = right_child_index(parent, length);

	int bigger_value_index = left_index;

	// compare the values and determine which index's value is bigger
	if(values[right_index] > values[left_index])
	{
		bigger_value_index = right_index;
	}

	// compare the values and swap if necessary.
	if(values[parent] < values[bigger_value_index])
	{
		// swap
		int temp = values[parent];
		values[parent] = values[bigger_value_index];
		values[bigger_value_index] = temp;
		heapify_down(values, bigger_value_index, length);
	}
	return;
}

void print_heap(heap *heap)
{
	print_array(heap);
}
