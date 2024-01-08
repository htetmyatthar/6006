#include "utils.h"

int main(void)
{
	// numbers that are no coliding when divide or mod by 5.
	int given_array[] = {17, 3, 24, 5, 11};
	int length = sizeof(given_array) / sizeof(given_array[0]);

	printf("Unsorted array: ");
	for(int i = 0; i < length; i++)
	{
		printf("%d, ", given_array[i]);
	}
	printf("\n");

	printf("Sorted array: ");
	tuple_sort(given_array, length);
	for(int i = 0; i < length; i++)
	{
		printf("%d, ", given_array[i]);
	}
	printf("\n");
}
