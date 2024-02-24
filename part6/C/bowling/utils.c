#include "utils.h"

#define NUMBER_OF_CHOICES 3

double bowl_recursive_recursion(double memo[], int length, int i, int values[]);

int bowl_recursive(int values[], int length)
{
	double *memo = malloc(sizeof(double) * length);
	if(memo == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating memo table\n");
		exit(1);
	}
	// since we are trying to maximize we're gonna use -INFINITY
	for(int i = 0; i < length; i++)
	{
		memo[i] = -INFINITY;
	}
	int point = (int) bowl_recursive_recursion(memo, length, 0, values);
	free(memo);
	return point;
}

double bowl_recursive_recursion(double memo[], int length, int i, int values[])
{
	if(i >= length)
	{
		return 0.0;
	}
	if(memo[i] == -INFINITY)
	{
		double *choices_points = malloc(sizeof(double) * NUMBER_OF_CHOICES);
		if(choices_points == NULL)
		{
			fprintf(stderr, "ERROR: not enough memory for creating choices points array.\n");
			exit(1);
		}

		// skip the pin
		choices_points[0] = bowl_recursive_recursion(memo, length, i + 1, values);
		// bowl pin i seperately
		choices_points[1] = bowl_recursive_recursion(memo, length, i + 1, values) + values[i];
		// bowl pins i and i + 1 together
		choices_points[2] = bowl_recursive_recursion(memo, length, i + 2, values) + (values[i] * values[i + 1]);

		// find the maximum
		double largest_point = -INFINITY;
		for(int j = 0; j < NUMBER_OF_CHOICES; j++)
		{
			if(choices_points[j] > largest_point)
			{
				largest_point = choices_points[j];
			}
		}
		memo[i] = largest_point;
		free(choices_points);
	}
	return memo[i];
}

int bowl_iterative(int values[], int length)
{
	int *points = calloc(length + 2, sizeof(int));
	if(points == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating memo.\n");
		exit(1);
	}

	// base cases for last two bowls
	points[length] = 0;
	points[length + 1] = 0;
	for(int i = length - 1; i >= 0; i--)
	{
		int *choices_points = malloc(sizeof(int) * NUMBER_OF_CHOICES);
		if(choices_points == NULL)
		{
			fprintf(stderr, "ERROR: not enough memory for creating choices points array.\n");
			exit(1);
		}
		// skip the pin
		choices_points[0] = points[i + 1];
		// bowl pin i seperately
		choices_points[1] = points[i + 1] + values[i];
		// bowl pins i and i + 1 together
		choices_points[2] = points[i + 2] + (values[i] * values[i + 1]);

		// find the maximum
		double largest_point = -INFINITY;
		for(int j = 0; j < NUMBER_OF_CHOICES; j++)
		{
			if(choices_points[j] > largest_point)
			{
				largest_point = choices_points[j];
			}
		}
		points[i] = largest_point;
		free(choices_points);
	}
	int result = points[0];
	free(points);
	return result;
}
