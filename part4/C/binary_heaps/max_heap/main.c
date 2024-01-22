#include "utils.h"

void print_hr();

void print_normal_array(int values[], int length);

int main(void)
{
	int values[] = {1, 2, 3, 4, 5};
	int length = sizeof(values) / sizeof(values[0]);
	dynamic_array *new_dynamic_array = build_dynamic_array(values, length);
	printf("building heap.\n");
	build_heap_linear(&new_dynamic_array);
	print_heap(new_dynamic_array);
	print_hr();

	printf("inserting value 55 to heap.\n");
	insert_to_heap(&new_dynamic_array, 55);
	print_heap(new_dynamic_array);
	print_hr();

	printf("deleting max from heap.\n");
	printf("Deleted max value: %d\n", delete_max_heap(&new_dynamic_array));
	print_heap(new_dynamic_array);
	print_hr();

	printf("trying heap sort: \n");
	int values1[] = {10,52,45,41,54,53,47,49,78,75};
	int length1 = sizeof(values1) / sizeof(values1[0]);
	print_normal_array(values1, length1);
	heap_sort(values1, length1);
	print_normal_array(values1, length1);

	free_dynamic_array(new_dynamic_array);
	return 0;
}

void print_hr()
{
	for(int i = 0; i < 10; i++)
	{
		printf("-------");
	}
	printf("\n");
}

void print_normal_array(int values[], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d, ", values[i]);
	}
	printf("\n");
}
