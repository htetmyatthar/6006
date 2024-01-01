#include "utils.h"

void selection_sort(int array[], int length)
{
/*	
	For i from 0 to n–1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]
*/
	for (int i = 0; i < length - 1; i++)
	{
		for(int j = i + 1; j < length; j++)
		{
			if(array[i] > array[j])
			{
				int temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	return;
}
