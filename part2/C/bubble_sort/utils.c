#include "utils.h"

void bubble_sort(int array[], int length)
{
	/*
	Repeat n - 1 times
	For i from 0 to n - 2
		If numbers[i] and numbers[i + 1] out of order
			Swap them
	*/
	for(int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	return;
}
