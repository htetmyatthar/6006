#include "utils.h"

int main(void)
{
	int values[] = {-1, 1, 1, 1, 9, 9, 3, -3, -5, 2, 2};
	// int values[] = {1, 1};
	int length = sizeof(values) / sizeof(values[0]);

	printf("Answer for recursive method is %i\n", bowl_recursive(values, length));
	printf("Answer for iterative method is %i\n", bowl_iterative(values, length));
}
