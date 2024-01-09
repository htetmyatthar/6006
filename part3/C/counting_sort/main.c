#include "utils.h"

int main(void)
{
	int given_array[] = {4, 2, 1, 0, 3, 4, 0, 1};
	int given_array1[] = {17, 3, 24, 0, 22, 700, 12};
	int length = sizeof(given_array) / sizeof(given_array[0]);
	int length1 = sizeof(given_array1) / sizeof(given_array1[0]);

	// using counting_sort summing
	printf("First Orignal: \n");
	print_array(given_array, length);

	printf("Sorted: \n");
	int* sorted_array = counting_sort_summing(given_array, length);
	print_array(sorted_array, length);

	print_hr();

	printf("Second Orignal: \n");
	print_array(given_array1, length1);

	printf("Sorted: \n");
	int* sorted_array1 = counting_sort_summing(given_array1, length1);
	print_array(sorted_array1, length1);

	print_hr();

	// using counting_sort_chaining
	printf("First Orignal: \n");
	print_array(given_array, length);

	printf("Sorted: \n");
	counting_sort_chaining(given_array, length);
	print_array(given_array, length);

	print_hr();

	printf("Second Orignal: \n");
	print_array(given_array1, length1);

	printf("Sorted: \n");
	counting_sort_chaining(given_array1, length1);
	print_array(given_array1, length1);

	// try implementing counting_sort_trie

	free(sorted_array);
	free(sorted_array1);
	return 0;
}
