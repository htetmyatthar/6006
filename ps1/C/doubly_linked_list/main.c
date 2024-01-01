#include <stdlib.h>
#include "stdio.h"
#include "utils.h"

void print_results(int values[], int length);
void print_hr();

int TESTCASECOUNT = 3;

int main(void)
{
	int values[][7] = {
		{1, 2, 3, 4, 5, 6, 7},
		{11, 12, 13, 14, 15, 16, 17},
		{31, 14, 16, 17, 13, 15, 8}
	};
	for (int i = 0; i < TESTCASECOUNT; i++)
	{
		print_results(values[i], 7);
	}
}

void print_results(int values[], int length)
{
	printf("Expected: \n");
	for (int i = 0; i < length; i++)
	{
		printf("%i->", values[i]);
	}
	printf("\n");
	
	printf("Results: \n");
	dll *list = build(values, length);
	print_list(list);
	print_hr();

	printf("Inserting last: value 3\n");
	dll *new_list = insert_last(list, 3);
	print_list(new_list);
	print_hr();

	int deleted_first = delete_first(new_list);
	print_list(new_list);
	printf("Deleted first: %i\n", deleted_first);
	print_hr();

	int deleted_last = delete_last(new_list);
	print_list(new_list);
	printf("Deleted last: %i\n", deleted_last);
	print_hr();

	printf("original: \n");
	print_list(new_list);
	dll *removed_list = remove_nodes(new_list, get_at(new_list, 3), get_at(new_list, 4));
	printf("Removed original list from 3 to 4: \n");
	print_list(new_list);
	printf("Removed list: \n");
	print_list(removed_list);
	print_hr();

	printf("original: \n");
	print_list(new_list);
	dll *remove_end_list = remove_nodes(new_list, get_at(new_list, 4), get_at(new_list, 4));
	printf("Removed original list from 4 to 4: \n");
	print_list(new_list);
	printf("Removed end list: \n");
	print_list(remove_end_list);
	print_hr();

	printf("original list and removed part: \n");
	print_list(new_list);
	printf("\t");
	print_list(remove_end_list);
	printf("Splice the latest remove part to index 1:\n");
	splice_list(new_list, get_at(new_list, 1), remove_end_list);
	print_list(new_list);
	print_hr();

	// free the memory that is used during the program.
	// order matters , we free the list first, then the struct that is marking the list.
	free_list(list);
	free(list);

	free_list(removed_list);
	free(removed_list);
	
	free_list(remove_end_list);
	free(remove_end_list);
}

void print_hr()
{
	for (int i = 0; i < 10; i++)
	{
		printf("----");
	}
	printf("\n");
}
