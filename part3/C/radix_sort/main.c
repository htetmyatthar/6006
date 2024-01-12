#include "utils.h"

int main(void)
{
	int given_array[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int length = sizeof(given_array) / sizeof(given_array[0]);
	printf("Original: \n");
	print_array(given_array, length);
	radix_sort(given_array, length);
	printf("Sorted: \n");
	print_array(given_array, length);

	int test_array[] = {
410, 666, 251, 775, 480, 351, 681, 786, 472, 284, 242, 269, 875, 322, 793, 90, 791, 396, 113, 107, 883, 490, 520, 556, 154, 613, 218, 323, 970, 734, 0, 20, 01, 1, 0000, 21
	};
	int test_length = sizeof(test_array) / sizeof(test_array[0]);
	printf("Original: \n");
	print_array(test_array, test_length);
	radix_sort(test_array, test_length);
	printf("Sorted: \n");
	print_array(test_array, test_length);
}
