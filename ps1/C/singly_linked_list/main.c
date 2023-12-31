#include "utils.h"
#include <stdio.h>

void print_results(int array[], int length);

int ELEMENTCOUNT = 7;

int main(void)
{
	int test_cases[][7] = {
		{1, 2, 3, 4, 5, 6, 7},
		{11, 12, 13, 14, 15, 16, 17},
		{9, 8, 7, 6, 5, 4, 3}
	};

	for (int i = 0; i < 3; i++)
	{
		print_results(test_cases[i], ELEMENTCOUNT);
	}
}

// print_results prints build the linked_list and prints out the results.
// input: array and it's length
// return: results
void print_results(int array[], int length)
{
	node *list = build(array, length);

	//print the input array
	printf("Expected: \n");
	length--;
	for (int i = 0; i <= length; length--)
	{
		printf("%i->", array[length]);
	}

	// print the linked_list
	printf("\nResults: \n");
	print_list(list);

	// free the memory
	free_list(list);
}
