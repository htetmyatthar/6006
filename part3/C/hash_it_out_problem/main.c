#include <assert.h>
#include "utils.h"

// given table size
// remeber global and static variables are initialized to 0
int TABLE_SIZE = 9;

int main(void)
{
	int given_array[] = {67, 13, 49, 24, 40, 33, 58};
	int length = sizeof(given_array) / sizeof(given_array[0]);
	node** hash_table = hash_map(given_array, TABLE_SIZE, length);

	// existing one
	bool result = find(hash_table, 49);
	// non existing one
	bool result1 = find(hash_table, 10);
	// they should not equal.
	assert(result != result1);

	// print the hash map
	print_map(hash_table, TABLE_SIZE);

	// free the memory
	free_map(hash_table, TABLE_SIZE);
}
