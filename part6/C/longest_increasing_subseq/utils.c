#include "utils.h"

// TODO: track parent pointers to also return the actual subseq.

int longest_increasing_subseq_iterative(char A[], int length)
{
	int* result = malloc(sizeof(int) * length);
	if(result == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating result array.\n");
		exit(1);
	}
	for(int i = 0; i < length; i++)
	{
		result[i] = 1;
	}

	for(int i = length - 1; i >= 0; i--)
	{
		for(int j = i; j < length; j++)
		{
			if(A[j] > A[i])
			{
				int largest = result[i];
				if((result[j] + 1) > largest)	// careful in here.
				{
					largest = result[j] + 1;
				}
				result[i] = largest;
			}
		}
	}
	int real_largest = -INFINITY;
	for(int i = 0; i < length ; i++)
	{
		if(result[i] > real_largest)
		{
			real_largest = result[i];
		}
	}
	free(result);
	return real_largest;
}
