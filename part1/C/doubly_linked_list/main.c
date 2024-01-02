#include <stdlib.h>
#include "stdio.h"
#include "utils.h"

void print_results(int values[], int length);

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
	
	dll *list = build(values, length);
	print_list(list, "Results: \n", true);

	dll *new_list = insert_last(list, 3);
	print_list(new_list, "Inserting last: value 3\n", true);

	int deleted_first = delete_first(new_list);
	print_list(new_list, "", false);
	printf("Deleted first: %i\n", deleted_first);
	print_hr();

	int deleted_last = delete_last(new_list);
	print_list(new_list, "", false);
	printf("Deleted last: %i\n", deleted_last);
	print_hr();

	print_list(new_list, "original: \n", false);
	dll *removed_list = remove_nodes(new_list, get_at(new_list, 3), get_at(new_list, 4));
	print_list(new_list, "Removed original list from 3 to 4: \n", false);
	print_list(removed_list, "Removed list: \n", true);

	print_list(new_list, "original: \n", false);
	dll *remove_end_list = remove_nodes(new_list, get_at(new_list, 4), get_at(new_list, 4));
	print_list(new_list, "Removed original list from 4 to 4: \n", false);
	print_list(remove_end_list, "Removed end list: \n", true);

	print_list(new_list, "original list and removed part: \n", false);
	print_list(remove_end_list, "\t", false);
	splice_list(new_list, get_at(new_list, 1), remove_end_list);
	print_list(new_list, "Splice the latest remove part to index 1:\n", true);

	// free the memory that is used during the program.
	// order matters , we free the list first, then the struct that is marking the list.
	free_list(list);
	free(list);

	free_list(removed_list);
	free(removed_list);
	
	free_list(remove_end_list);
	free(remove_end_list);
}

