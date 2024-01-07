#include "utils.h"

bool binary_search(int array[], int length, int value)
{
	int left = 0;
	int right = length - 1;

	while (left <= right)
	{
		int middle = left + ((right - left) / 2);
		if (array[middle] == value)
		{
			return true;
		}
		else if (array[middle] < value)
		{
			left = middle + 1;
		}
		else if (array[middle] > value)
		{
			right = middle - 1;
		}
	}
	return false;
}
