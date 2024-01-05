#include <assert.h>
#include "utils.h"

void check_append(dynamic_array_track *d_array);
void check_pop(dynamic_array_track *d_array);

int main(void)
{
	// creating dynamic array with even number of items
	printf("Creating dynamic array with even numbers:\n");
	int values[] = {1, 2, 3, 4, 5, 6};
	dynamic_array_track *array = build_d_array(values, 6);
	Print_both(array);
	printf("Size: %d, Capacity: %d\n", array->size, array->capacity);
	print_hr();
	
	// creating dynamic array with odd number of items
	printf("Creating dynamic array with odd numbers:\n");
	int values1[] = {1, 2, 3, 4, 5};
	dynamic_array_track *array1 = build_d_array(values1, 5);
	Print_both(array1);
	printf("Size: %d, Capacity: %d\n", array->size, array->capacity);
	print_hr();

	// append the 9 to both odd and even 
	printf("Append 9 to the d_arrays\n");
	printf("Original sizes: [%d] and [%d]\n", array->size, array1->size);
	dynamic_array_track *return_array = d_array_append(array, 9);
	if (return_array != NULL)
	{
		array = return_array;
	}
	dynamic_array_track *return_array1 = d_array_append(array1, 9);
	if (return_array1 != NULL)
	{
		array1 = return_array1;
	}
	printf("After appending: \n");
	Print_both(array);
	Print_both(array1);
	printf("Changed sizes: [%d] and [%d]\n", array->size, array1->size);
	print_hr();

	// prepend the 9 to both odd and even
	printf("Prepend 9 to the d_arrays\n");
	printf("Original sizes:[%d] and [%d]\n", array->size, array1->size);
	dynamic_array_track *return_array2 = d_array_prepend(array, 9);
	if (return_array != NULL)
	{
		array = return_array2;
	}
	dynamic_array_track *return_array3 = d_array_prepend(array1, 9);
	if (return_array1 != NULL)
	{
		array1 = return_array3;
	}
	printf("After prepending: \n");
	Print_both(array);
	Print_both(array1);
	printf("Changed sizes: [%d] and [%d]\n", array->size, array1->size);
	print_hr();

	// deque the first element.
	printf("Dequeue\n");
	printf("Original sizes:[%d] and [%d]\n", array->size, array1->size);
	dynamic_array_track *return_array4 = d_array_dequeue(array);
	if (return_array != NULL)
	{
		array = return_array4;
	}
	dynamic_array_track *return_array5 = d_array_dequeue(array1);
	if (return_array1 != NULL)
	{
		array1 = return_array5;
	}
	printf("After dequeueing: \n");
	Print_both(array);
	Print_both(array1);
	printf("Changed sizes: [%d] and [%d]\n", array->size, array1->size);
	print_hr();

	// pop the last element
	printf("Original sizes: [%d] and [%d]\n", array->size, array1->size);
	dynamic_array_track *return_array6 = d_array_pop(array);
	if (return_array != NULL)
	{
		array = return_array6;
	}
	dynamic_array_track *return_array7 = d_array_pop(array1);
	if (return_array1 != NULL)
	{
		array1 = return_array7;
	}
	printf("After poping: \n");
	Print_both(array);
	Print_both(array1);
	printf("Changed: [%d] and [%d]\n", array->size, array1->size);
	print_hr();

	// set at 
	printf("Set at 3rd item of the dynamic array with 77\n");
	set_at(array, 3, 77);
	set_at(array1, 3, 77);
	printf("After: \n");
	print_d_array(array);
	print_d_array(array1);
	assert(array->base[array->start + 2] == 77 && array1->base[array1->start + 2] == 77);
	printf("Assserting 3rd item of dynamic array with 77 TRUE.\n");
	print_hr();

	// get at
	printf("Get the 5th item in the dynamic array which should be the same.\n");
	int item1 = get_at(array, 5);
	int item2 = get_at(array1, 5);
	print_d_array(array);
	print_d_array(array1);
	assert(item1 == item2);
	printf("Asserting comparing two item TRUE.\n");
	print_hr();

	// free the memory
	free_d_array(array);
	free_d_array(array1);

	printf("Append it 10 times: \n");
	int something[] = {1, 2, 3, 4};
	int range = sizeof(something) / sizeof(something[0]);
	dynamic_array_track *something_array = build_d_array(something, range);
	check_append(something_array);
	print_hr();

	printf("Shrink it till index out of range. At least 10 times.\n");
	int something1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int range1 = sizeof(something1) / sizeof(something1[0]);
	dynamic_array_track *something_array1 = build_d_array(something1, range1);
	check_pop(something_array1);
	print_hr();

	printf("Testing the delete at 3rd item. Expecting 1, 2, 4, 5, 6\n");
	int something2[] = {1, 2, 3, 4, 5, 6};
	int range2 = sizeof(something2) / sizeof(something2[0]);
	dynamic_array_track *something_array2 = build_d_array(something2, range2);
	printf("Original: \n");
	Print_both(something_array2);
	dynamic_array_track *deleted_new_array = delete_at(something_array2, 3);
	printf("After delete at operation: \n");
	Print_both(deleted_new_array);
	print_hr();

	// free the newly created array.
	free_d_array(deleted_new_array);

	return 0;
}

void check_append(dynamic_array_track *d_array)
{
	printf("Original: \n");
	Print_both(d_array);
	print_hr();
	for (int i = 0; i < 10; i++)
	{
		dynamic_array_track *new_return = d_array_append(d_array, 10 + i);
		if (new_return != NULL)
		{
			d_array = new_return;
		}
		printf("After appened: Size: [%d], Capacity: [%d]\n", d_array->size, d_array->capacity);
		Print_both(d_array);
		print_hr();
	}
	//if we don't free here it'll lose this last memory
	//cause it ani't the same address as before.
	free_d_array(d_array);
	print_hr();
}

void check_pop(dynamic_array_track *d_array)
{
	printf("Original: \n");
	Print_both(d_array);
	print_hr();
	for (int i = 0; i < 2; i++)
	{
		dynamic_array_track *new_return1 = d_array_pop(d_array);
		if (new_return1 != NULL)
		{
			d_array = new_return1;
		}
		printf("After Popping: Size: [%d], Capacity: [%d]\n", d_array->size, d_array->capacity);
		Print_both(d_array);
		print_hr();
	}
	//if we don't free here it'll lose this last memory
	//cause it ani't the same address as before.
	free_d_array(d_array);
	print_hr();
}
