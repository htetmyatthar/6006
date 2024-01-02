#include <stdio.h>
#include "utils.h"

int TESTCASECOUNT = 5;

int main(void)
{
	int array[] = {11, 16, 10, 19, 20, 18, 3, 19, 2, 1, 8, 17, 7, 13, 1, 11, 1, 18, 19, 9, 7, 19, 24, 2, 12};
	int array1[] = {2, 2, 4, 1, 4};
	int array2[] = {7, 8, 5, 7, 7, 3, 2, 8};
	int array3[] = {7, 7, 9, 1, 2, 11, 9, 6, 2, 8, 9};
	int array4[] = {4, 18, 10, 8, 13, 16, 18, 1, 9, 6, 11, 13, 12, 5, 7, 17, 13, 3};

	int length = sizeof(array) / sizeof(array[0]);
	int length1 = sizeof(array1) / sizeof(array1[0]);
	int length2 = sizeof(array2) / sizeof(array2[0]);
	int length3 = sizeof(array3) / sizeof(array3[0]);
	int length4 = sizeof(array4) / sizeof(array4[0]);

	// gotcha if you didn't declare explicitly you will get
	// the array of size 0 in the compile time for length_results.
	int results[TESTCASECOUNT]; 
	results[0]= count_long_sub_array(array, length); 
	results[1] = count_long_sub_array(array1, length1); 
	results[2] = count_long_sub_array(array2, length2);
	results[3] = count_long_sub_array(array3, length3);
	results[4] = count_long_sub_array(array4, length4);

	int wants[] = {4, 2, 3, 2, 1};

	int count = 0;
	int length_results = sizeof(results) / sizeof(results[0]);
	for (int j = 0; j < length_results; j++)
	{
		printf("Running: Testcase %d\n", j);
		if (wants[j] != results[j])
		{
			printf("Expected: %d, Result: %d\n", wants[j], results[j]);
			count++;
		}
	}
	printf("5 Tests run. %i good.\n", TESTCASECOUNT - count );
	return 0;
}
