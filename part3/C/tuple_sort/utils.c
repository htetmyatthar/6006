#include "utils.h"

void tuple_sort(int values[], int length)
{
	// checking for key's values.
	int max_key = pow(length, 2) - 1;
	for (int i = 0; i < length; i++)
	{
		if (values[i] > max_key)
		{
			printf("Can't handle keys that are larger than n^2 where n is length.\n");
			exit(2);
		}
	}

	// I think I should use DAA sort for this since this week's topic is that.
	// we have to sort two times and allocate three array.
	// first for least significant then for more significant.
	// first for storing tuples, second for sorted leasts, third for sorted more.

	// to store the tuples. we can ensure that will not more than 5.
	tuple **temp_array1 = malloc(sizeof(tuple*) * length);
	if (temp_array1 == NULL)
	{
		printf("Not enough memory for bucket array.\n");
		exit(1);
	}

	// create the tuples and then store them in the temp_array1 for sorting.
	for (int i = 0; i < length; i++)
	{
		// k = an + b where 0 <= b < n 
		// so to get a , (k / n). and to get b, (k mod n).
		tuple *new_tuple = malloc(sizeof(tuple));
		if (new_tuple == NULL)
		{
			printf("Not enough memory for tuples.\n");
			exit(1);
		}
		new_tuple->first = values[i] / length;
		new_tuple->second = values[i] % length;

		// storing in temp_array1.
		temp_array1[i] = new_tuple;
	}

	// to store the least significant sorted tuples.
	tuple **temp_array2 = calloc(length, sizeof(tuple*));
	if (temp_array2 == NULL)
	{
		free_tuple_array(temp_array1, length);
		printf("Not enough memory for temporary space.");
		exit(1);
	}

	// store the sorted least significants in the temp_array2.
	// After that we don't need temp_array1 anymore.
	for(int i = 0; i < length; i++)
	{
		temp_array2[temp_array1[i]->second] = temp_array1[i];
	}
	free(temp_array1);

	// to store the more significant sorted tuples.
	tuple **temp_array3 = calloc(length, sizeof(tuple*));
	if (temp_array3 == NULL)
	{
		free_tuple_array(temp_array2, length);
		printf("Not enough memory for temporary space.");
		exit(1);
	}
	
	// store the sorted more significants in the temp_array2.
	// After that we don't need temp_array2 anymore.
	for(int i = 0; i < length; i++)
	{
		temp_array3[temp_array2[i]->first] = temp_array2[i];
	}
	free(temp_array2);

	// replace the sorted values with the orginal array back.
	for(int i = 0; i < length; i++)
	{
		// k = an + b where 0 <= b < n 
		values[i] = (temp_array3[i]->first * length) + temp_array3[i]->second;
	}
	free_tuple_array(temp_array3, length);
}

// frees the tuple arrays.
void free_tuple_array(tuple **tuple_array, int length)
{
	for(int i = 0; i < length; i++)
	{
		free(tuple_array[i]);
	}
	free(tuple_array);
}
