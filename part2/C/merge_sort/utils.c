#include "utils.h"

void merge_sort(int array[], int length)
{
	merge_sort_recursion(array, 0, length-1);
}

void merge_sort_recursion(int array[], int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		// divide and conqure
		merge_sort_recursion(array, left, middle);
		merge_sort_recursion(array, middle + 1, right);

		// merge the two arrays
		merge(array, left, middle, right);
	}
}

void merge(int array[], int left, int middle, int right)
{
	int i, j, k;
	// for creating temporary arrays
	int left_length = middle - left + 1;
	int right_length = right - middle;

	int temp_left[left_length], temp_right[right_length];


	// copy the array into two temp arrays.
	for(i = 0; i < left_length; i++)
	{
		temp_left[i] = array[left + i];
	}

	for(j = 0; j < right_length; j++)
	{
		temp_right[j] = array[middle + 1 + j];
	}

	i = 0; j = 0; k = left;

	// Untill we reach either end of either temporary array, place the right order.
	while(i < left_length && j < right_length)
	{
		if(temp_left[i] <= temp_right[j])
		{
			array[k] = temp_left[i];
			i++;
		}
		else 
		{
			array[k] = temp_right[j];
			j++;
		}
		k++;
	}

	// if the elements in either array is completely replaced.
	while(i < left_length)
	{
		array[k] = temp_left[i];
		i++;
		k++;
	}

	while(j < right_length)
	{
		array[k] = temp_right[j];
		j++;
		k++;
	}
}
