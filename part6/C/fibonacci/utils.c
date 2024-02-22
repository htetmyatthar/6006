#include "utils.h"

int fibonacci_recursive_recursion(int* memo, int i);

/**
 *	limit is up to 46th fibonacci number.
 */

int fibonacci_plain(int n)
{
	if(n > 46)
	{
		fprintf(stderr, "ERROR: can't calculate more than that the upper bound for this function is 46.\n");
		exit(2);
	}
	if (n < 2)
	{
		return n;
	}
	return (fibonacci_plain(n - 1) + fibonacci_plain(n - 2));
}

int fibonacci_recursive(int n)
{
	if(n > 46)
	{
		fprintf(stderr, "ERROR: can't calculate more than that the upper bound for this function is 46.\n");
		exit(2);
	}
	int *memo = malloc(sizeof(int) * (n + 1));
	if(memo == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating ");
		exit(1);
	}
	// intialized for all
	for(int i = 0; i < n + 1; i++)
	{
		memo[i] = -1;
	}
	int result = fibonacci_recursive_recursion(memo, n);
	free(memo);
	return result;
}

int fibonacci_recursive_recursion(int memo[], int i)
{
	if (i < 2)
	{
		return i;
	}
	if(memo[i] == -1)
	{
		memo[i] = fibonacci_recursive_recursion(memo, i - 1) + fibonacci_recursive_recursion(memo, i - 2);
	}
	return memo[i];
}

int fibonacci_iterative(int n)
{
	if(n > 46)
	{
		fprintf(stderr, "ERROR: can't calculate more than that the upper bound for this function is 46.\n");
		exit(2);
	}
	int *fib_numbers = malloc(sizeof(int) * (n + 1));
	if(fib_numbers == NULL)
	{
		fprintf(stderr, "ERROR: not enough fib_numbersry for creating ");
		exit(1);
	}
	// intialized for up to n.
	for(int i = 0; i < n + 1; i++)
	{
		fib_numbers[i] = -1;
	}
	fib_numbers[0] = 0;
	fib_numbers[1] = 1;
	for(int i = 2; i < n + 1; i++)
	{
		fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
	}
	int result = fib_numbers[n];
	free(fib_numbers);
	return result;
}
