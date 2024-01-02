#include "utils.h"

int main(void)
{
	int test_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length = sizeof(test_array) / sizeof(test_array[0]);

	node *linked_list = build(test_array,length);
	print_list(linked_list, "Built: \n");

	half_reverse(linked_list, length);
	print_list(linked_list, "Halved And Reversed: \n");

	free_list(linked_list);

	int test_array1[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 ,11 ,12 ,13 ,14 ,15 ,16 ,17 ,18 ,20};
	int length1 = sizeof(test_array1) / sizeof(test_array1[0]);

	node *linked_list1 = build(test_array1,length1);
	print_list(linked_list1, "Built: \n");

	half_reverse(linked_list1, length1);
	print_list(linked_list1, "Halved And Reversed: \n");

	free_list(linked_list1);
}

