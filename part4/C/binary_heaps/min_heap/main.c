#include "utils.h"

void print_normal_array(int array[], int length);

void print_hr();

int main(void)
{
	int values[] = {12, 16, 9, 4, 7, 10};
	int length = sizeof(values) / sizeof(values[0]);
	print_normal_array(values, length);

	printf("building:\n");
	heap *new_heap = build_dynamic_array(values, length);
	build_heap_linear((new_heap)->base, new_heap->size);
	print_both(new_heap);
	print_hr();

	printf("inserting\n");
	print_both(new_heap);
	heap_insert(&new_heap, 3);
	print_both(new_heap);
	heap_insert(&new_heap, 1);
	print_both(new_heap);
	print_hr();

	printf("deleting min\n");
	print_both(new_heap);
	printf("deleted value: %d", heap_delete_min(&new_heap));
	print_both(new_heap);
	printf("deleted value: %d", heap_delete_min(&new_heap));
	print_both(new_heap);
	print_hr();

	printf("sorting\n");
	print_normal_array(values, length);
	heap_sort(values, length);
	print_normal_array(values, length);
	print_hr();

	free_dynamic_array(new_heap);
	return 0;
}

void print_normal_array(int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
}

void print_hr()
{
	for(int i = 0; i < 10; i++)
	{
		printf("--------");
	}
	printf("\n");
}
