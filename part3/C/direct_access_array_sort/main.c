#include "utils.h"
#include <stdio.h>

int main(void)
{
	int given_array[] = {5, 2, 7, 0, 4};
	int length = sizeof(given_array) / sizeof(given_array[0]);
	printf("given_array: ");
	for (int i = 0; i < length; i++)
	{
		printf("%d, ", given_array[i]);
	}
	printf("\n");

	//  given array  is sorted.
	DAA_sort(given_array, length);

	printf("sorted_array: ");
	int expected_array[] = {0, 2, 4, 5, 7};
	for (int i = 0; i < length; i++)
	{
		printf("%d, ", given_array[i]);
		assert(expected_array[i] == given_array[i]);
	}
	printf("\n");

	return 0;
}
