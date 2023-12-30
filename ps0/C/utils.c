#include "utils.h"

// special case we need size in if we don't want to pass by value.
// add size parameter
int count_long_sub_array(int array[], int array_size){
	int current_count = 0;
	int current_length = 0;
	int iterate_length = 1;
	for (int i = 0; i < array_size; i++)
	{
		if ( i+1 != array_size && array[i] < array[i + 1]) 
		{
			iterate_length += 1;
		}
		else 
		{
			if (iterate_length > current_length)
			{
				current_count = 1;
				current_length = iterate_length;
			}
			else if (iterate_length == current_length)
			{
				current_count++;
			}
			iterate_length = 1;
		}
	}
	return current_count;
}
