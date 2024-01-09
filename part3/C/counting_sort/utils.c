#include "utils.h"
#include <stdlib.h>

// FOR FUNCTION API DOCUMENTATION SEE utils.h FILE.

void counting_sort_chaining(int values[], int length)
{
	// to store the values that transformed as tuples.
	// change the normal values to tuples to get the base **length** digits.
	tuple **tuple_array = calloc(length, sizeof(tuple*));
	if (tuple_array == NULL)
	{
		printf("Not enough memory for count array.\n");
		exit(1);
	}
	for(int i = 0; i < length; i++)												//O(n)
	{
		tuple *new_tuple = malloc(sizeof(tuple));
		if (new_tuple == NULL)
		{
			printf("Not enough memory for creating tuples.\n");
			exit(1);
		}
		new_tuple->first = values[i] / length;
		new_tuple->second = values[i] % length;
		new_tuple->next = NULL;

		tuple_array[i] = new_tuple;
	}

	// to count the number of keys in the least siginificant.
	// the keys for the least significant won't be larger than length
	// since we use the value that is mod by the length.
	int max_key_least = length;
	int *count_array_least = calloc(max_key_least, sizeof(int));
	if(count_array_least == NULL)
	{
		free_tuple_array(tuple_array, length);
		printf("Not enough memory for counting array.");
		exit(1);
	}

	// iterate through the tuple_array, to count the least siginificant values.
	for(int i = 0; i < length; i++)											//O(n)
	{
		count_array_least[tuple_array[i]->second]++;
	}

	// iterate though the count_array_least, to calculate the cumulative sum.
	for(int i = 1; i < max_key_least; i++)									//O(u_1)
	{
		count_array_least[i] += count_array_least[i - 1];
	}

	// prepare to store the sorted orders of least siginificant from tuple_array.
	// so the same size as the tuple_array.
	tuple **tuple_array1 = calloc(length, sizeof(tuple*));
	if (tuple_array1 == NULL)
	{
		free_tuple_array(tuple_array, length);
		free(count_array_least);
		printf("Not enough memory for least significant keys of tuples.\n");
		exit(1);
	}

	// iterate through the tuple_array and sort the least significant values
	// using the cumulative sum as keys.
	for(int i = 0; i < length; i++)											//O(n)
	{
		// store the respective places.
		tuple_array1[count_array_least[tuple_array[i]->second] - 1] = tuple_array[i];
		// lower the counts.
		count_array_least[tuple_array[i]->second]--;
	}


	// find largest keys for first to help sorting the more significant.
	int largest_key = -1;
	for(int i = 0; i < length; i++)											//O(n)
	{
		if (tuple_array[i]->first > largest_key)
		{
			largest_key = tuple_array[i]->first;
		}
	}

	// we've sorted the tuple values in tuple_array1 and got the largest keys of the more significant.
	// we can free this memory.
	// noticed I just free the array. **I left the tuples**
	free(tuple_array);
	free(count_array_least);

	// prepare another array to store the sorted more significant keys.
	// we have to sort up to keys which is the (largest keys + 1) > length,
	largest_key++;	
	tuple **tuple_array_chain = calloc(largest_key, sizeof(tuple*));
	if (tuple_array_chain == NULL)
	{
		free_tuple_array(tuple_array1, length);
		printf("Not enough memory for more significant keys of tuples.\n");
		exit(1);
	}

	// iterate through the tuple_array1 to sort the more significant values.
	for(int i = 0; i < length; i++)										//O(n)
	{
		// link like hashing using the keys as the more siginificant values.
		tuple_array1[i]->next = tuple_array_chain[tuple_array1[i]->first];
		tuple_array_chain[tuple_array1[i]->first] = tuple_array1[i];
	}

	// we have sorted the tuples the most significant keys.
	// we can free this memory
	// noticed I just free the array. **I left the tuples**.
	free(tuple_array1);

	// iterate through the tuple_array_chain (sorted in both values)to build with values
	// also iterate through the original array reversely to add the result values.
	// this is due to a property of linked list.
	for (int i = largest_key - 1, j = length - 1; i >= 0; i--)			//O(n)
	{
		tuple *finger = tuple_array_chain[i];

		// iterate through all the tuple linked list node.
		while(finger != NULL)
		{
			values[j] = (finger->first * length) + finger->second;
			finger = finger->next;
			j--;
		}
	}
	// after everything's done we will free all.
	free_tuple_array_chain(tuple_array_chain, largest_key);				//O(n)
	// O(6n + u_1) = O(n) we can do better than this if we can afford more space using trie datastructure.
}

int* counting_sort_summing(int values[], int length)
{
	// finding the max key
	int largest_key = -1;
	for(int i = 0; i < length; i++)							//O(n)
	{
		if (values[i] > largest_key)
		{
			largest_key = values[i];
		}
	}

	// initializing count array with max_key
	// we have to sort up to keys which is the (largest keys + 1) > length,
	largest_key++;
	int *count_array = calloc(largest_key, sizeof(int));
	if (count_array == NULL)
	{
		printf("Not enough memory for count array.");
		exit(1);
	}

	// counting the keys with respect to the indexes.
	// iterate through the values.
	int max_key = largest_key + 1;
	for(int i = 0; i < length; i++)							//O(n)
	{
		count_array[values[i]]++;
	}

	// changes from key counts to cumulative sums.
	// calculating cumulative sum.
	// iterate through the count_array.
	for(int i = 1; i < max_key; i++)						//O(u)
	{
		count_array[i] += count_array[i - 1];
	}

	// create a new array for sorted orders.
	int *sorted_array = malloc(sizeof(int) * length);
	if(sorted_array == NULL)
	{
		printf("Not enough memory for sorted array.");
		exit(1);
	}

	// store the sorted orders.
	for (int i = 0; i < length; i++)						//O(n)
	{
		// sort the original array's values using the 
		// original array's values as keys to the count array
		// and using that keys as the index to the sorted array.
		sorted_array[count_array[values[i]] - 1] = values[i];

		// reduce the count.
		count_array[values[i]]--;
	}

	free(count_array);

	return sorted_array;				//O(3n + u) = O(n) if not precomputed.
}

void print_array(int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
}

void free_tuple_array(tuple **array, int length)
{
	for(int i = 0; i < length; i++)
	{
		free(array[i]);
	}
	free(array);
}

void free_tuple_array_chain(tuple **array, int length)
{
	for(int i = 0; i < length; i++)
	{
		tuple *finger = array[i];
		while(finger != NULL)
		{
			tuple *temp_finger = finger->next;
			free(finger);
			finger = temp_finger;
		}
	}
	free(array);
}

void print_hr()
{
	for(int i = 0; i < 10;i++ )
	{
		printf("---------");
	}
	printf("\n");
}
