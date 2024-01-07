#include <stdio.h>
#include "utils.h"

// naive_damage computes the damage for every item in the array.
int* naive_damage(int input[], int length)
{
	int* damage_array = malloc(sizeof(int) * length);
	if (damage_array == NULL)
	{
		return NULL;
	}
	for(int i = 0; i < length; i++)
	{
		damage_array[i] = 1;
		for(int j = i + 1; j < length; j++)
		{
			if (input[i] > input[j])
			{
				damage_array[i]++;
			}
		}
	}
	return damage_array;
}
