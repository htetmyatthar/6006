#include "utils.h"

void insertion_sort(int array[], int length)
{
/*
For i from 1 to n - 1
	j = i
	If there's still items to check(j > 0) and those items are bigger than the current item.
		Swap the current item and the 
		Decrement j
*/
	for(int i = 1; i < length; i++)
	{
		int j = i;
		while(j > 0 && array[j - 1] > array[j])
		{
			// swap
			int temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;

			j = j - 1;
		}
	}
	return;

	/*
	*	for(int i = 1; i < length; i++)
	*	{
	*		for(int j = i; j > 0; j--)
	*		{
	*			int temp = array[j];
	*			array[j] = array[j - 1];
	*			array[j - 1] = temp;
	*		}
	*	}
	*/
}
