#include "utils.h"

#define FORMAT 10

void radix_sort(int values[], int length)
{
	// find the largest number
	int largest_key = -1;
	for(int i = 0; i < length; i++)
	{
		if (values[i] > largest_key)
		{
			largest_key = values[i];
		}
	}

	// find the number of digits of the largest number
	int count = 0;
	while(largest_key > 0)
	{
		count++;
		largest_key = largest_key / FORMAT;
	}

	// store into digits array the digits.
	int **array_pointers = malloc(sizeof(int*) * length);
	if (array_pointers == NULL)
	{
		printf("Not enough memory for creating array of array pointers.\n");
		exit(1);
	}
	for (int i = 0; i < length; i++)
	{
		// we will work with a copy if we use reference to array that can hurt us in future.
		int number = values[i];
		// create digit array that will never be exceed count.
		int *digits = calloc(count, sizeof(int));
		// iterate untill all the digits are store in the digits array.
		for(int j = count - 1; number > 0; j--)
		{
			digits[j] = number % FORMAT;
			number = number / FORMAT;
		}
		array_pointers[i] = digits;
	}

	//counting sort from least significant to more siginificant
	for (int i = count - 1; i >= 0; i--)
	{
		counting_sort(array_pointers, length, i, FORMAT);
	}

	// overwrite the sorted order to the original value.
	for(int i = 0; i < length; i++)
	{
		int number = 0;
		for(int j = count - 1, power = 0; j >= 0; j--, power++)
		{
			number += (array_pointers[i][j] * pow(10, power));
		}
		values[i] = number;
	}
	free_arrays(array_pointers, length);
}

void counting_sort(int* values[], int length, int index, int max_key_size)
{
	// counting
	int *count_array = calloc(max_key_size, sizeof(int));
	if(count_array == NULL)
	{
		free_arrays(values, length);
		printf("Not enough memory for creating counting array.\n");
		exit(1);
	}
	// iterate through all the pointers to the digit arrays to count
	for(int i = 0; i < length; i++)
	{
		count_array[values[i][index]]++;
	}

	// cumulative sum
	// iterate through the count_array
	for(int i = 1; i < max_key_size; i++)
	{
		count_array[i] += count_array[i - 1];
	}

	// sorting
	int **sorted_array = malloc(sizeof(int*) * length);
	if(sorted_array == NULL)
	{
		free(count_array);
		free_arrays(values, length);
		printf("Not enough memory for creating sorted array for counting sort.\n");
		exit(1);
	}
	// iterate through all the pointers to the digit arrays
	// reverse for getting the advantage of previously sorted.
	for(int i = length - 1; i >= 0; i--)
	{
		// look through the values[i][index] in count array
		// and index it to the sorted_array.
		sorted_array[count_array[values[i][index]] - 1] = values[i];

		// I f***ed up a lot here.
		count_array[values[i][index]]--;
	}
	// free the no longer necessary memory.
	free(count_array);

	// copying the sorted order.
	for(int i = 0; i < length; i++)
	{
		values[i] = sorted_array[i];
	}
	// we just have to free the array of pointers not the whole.
	free(sorted_array);
}

void free_arrays(int **values, int length)
{
	for(int i = 0; i < length; i++)
	{
		free(values[i]);
	}
	free(values);
}

void print_array(int values[], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d, ", values[i]);
	}
	printf("\n");
}
