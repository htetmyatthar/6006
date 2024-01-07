#include <stdio.h>
#include "utils.h"

int main(void)
{
	printf("Part (a) Processing.\n");
	int part_a[] = {34, 57, 70, 19, 48, 2, 94, 7, 63, 75};
	int length = sizeof(part_a) / sizeof(part_a[0]);
	int *part_a_damage = naive_damage(part_a, length);
	int part_a_solution[] = {4, 5, 6, 3, 3, 1, 4, 1, 1, 1};
	for (int i = 0; i < length; i++)
	{
		assert(part_a_damage[i] == part_a_solution[i]);
	}
	printf("Part (a) Correct.\n");
	print_hr();
}
