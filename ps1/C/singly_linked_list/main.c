#include "utils.h"
#include <stdio.h>

void print_results(int array[], int length);
void print_hr();

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
	print_hr();

	// testing the set_at function
	printf("Set the 5th index number 0");
	set_at(list, 5, 0);
	printf("\nResults: \n");
	print_list(list);
	print_hr();

	// testing the get_at function
	printf("Get the 6th index number");
	node *node_acquire = get_at(list, 6);
	printf("\nResults: %i\n", node_acquire->number);
	print_list(list);
	print_hr();

	// testing the delete first function
	printf("Delete first item");
	node *new_list = delete_first(list);
	printf("\nResults: \n");
	print_list(new_list);
	print_hr();

	// free the memory
	free_list(new_list);
}

void print_hr()
{
	for (int i = 0; i < 10; i++)
	{
		printf("------");
	}
	printf("\n");
}
