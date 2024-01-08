#include "utils.h"

// Using DAA_sort assumes your keys(i.e. you values in your given array) is unique.
// and also the keys as non-negative integers.
// Otherwise you shouldn't use it.
void DAA_sort(int values[], int length)
{
	// find the largest keys with linear search.
	int largest_key = -1;
	for(int i = 0; i < length; i++)
	{
		if (values[i] > largest_key)
		{
			largest_key = values[i];
		}
	}

	int max_key = largest_key + 1;


	// this is the set interface for sorting. Another way of doing this is just 
	int *bucket_array = malloc(sizeof(int) * (max_key));
	if (bucket_array == NULL)
	{
		printf("Not enough memory for keys.");
		exit(1);
	}

	// initialized items to negative number(empty).
	for(int i = 0; i < max_key; i++)
	{
		bucket_array[i] = -1;
	}

	// add the keys in the buckets.
	for (int i = 0; i < length; i++)
	{
		// add the values' value in bucket's index.
		// resulting in a sorted list.
		bucket_array[values[i]] = values[i];
	}

	// write to the array the sorted order.
	for (int i = 0, j = 0; i < max_key; i++)
	{
		// not empty.
		if (bucket_array[i] > -1)
		{
			values[j] = bucket_array[i];
			j++;
		}
	}

	free(bucket_array);
}
