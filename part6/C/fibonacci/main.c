#include "utils.h"
#define NUM_OF_FUNCTION 3

typedef int(*fib_function)(int);

void print_hr(void);

double time_function(fib_function fib_func, int n);

int parse_int(char* string);

void time_results(double results[], int count, int n);

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("ERROR: need more arguments\nUsage: ./fibonacci [nth number] [time to find repeatedly]\n");
		return 0;
	}
	int nth_number = parse_int(argv[1]);
	int count = atoi(argv[2]);
	if(count < 1)
	{
		printf("Provide valid repitition time starting from 1\n");
		return 0;
	}
	else if(nth_number < 1)
	{
		printf("Please provide valid flags.\nBETWEEN '0' and '46' inclusivly.\n");
		return 0;
	}
	double *results = malloc(sizeof(double) * (nth_number * NUM_OF_FUNCTION));
	if(results == 0)
	{
		fprintf(stderr, "ERROR: not enough memory for profiling.\n");
		return 1;
	}
	printf("Executing for %d time\n", count);
	for(int i = 0; i < count; i++)
	{
		int test_number = nth_number;
		// printf("Timing naive function.\n");
		double time = time_function(fibonacci_plain, test_number);
		results[i] = time;
		// printf("Time taken: %f\n", time);
		// printf("Timing recursive approach(top down).\n");
		time = time_function(fibonacci_recursive, test_number);
		// printf("Time taken: %f\n", time);
		results[i + nth_number] = time;
		// printf("Timing iterative approach(bottom up).\n");
		time = time_function(fibonacci_iterative, test_number);
		results[i + nth_number + nth_number] = time;
		// printf("Time taken: %f\n", time);
	}
	print_hr(); print_hr();
	time_results(results, count, nth_number);
	print_hr(); print_hr();
	return 0;
}

double time_function(fib_function fib_func, int n)
{
	clock_t start, end;
	start = clock();
	int third_number = fib_func(n);
	printf("%ith fibonacci number is %d\n", n, third_number);
	end = clock();
	double cpu_time_used =((double) (end - start) / CLOCKS_PER_SEC);
	return cpu_time_used;
}

void time_results(double results[], int count, int n)
{
	double time = 0;
	// for naive one
	for(int i = 0; i < n; i++)
	{
		time = time + results[i];
	}
	printf("Total time taken for naive for %i repitition: %f\n", count, time);
	time /= count;
	printf("Average time taken for naive: %f\n", time);
	time = 0;

	// for recursive memo one(top down)
	int new_n = n * 2;
	for(int i = n; i < new_n; i++)
	{
		time = time + results[i];
	}
	printf("Total time taken for memo for %i repitition: %f\n", count, time);
	time /= count;
	printf("Average time taken for memo: %f\n", time);
	time = 0;
	
	// for iterative one(bottom up)
	int start_count = new_n;
	new_n += n;
	for(int i = start_count; i < new_n; i++)
	{
		time = time + results[i];
	}
	printf("Total time taken for iterative for %i repitition: %f\n", count, time);
	time /= count;
	printf("Average time taken for iterative: %f\n", time);
}


// parse a valid string that is the value for 0 to 46;
// I think upperbound n 46 by n time repetition is enough for seeing difference.
int parse_int(char* string)
{
	int length = strlen(string);
	if(length == 2)
	{
		// between 0 and 4 inclusive
		if(string[0] < 53 && string[0] > 47)
		{
			// between 0 and 9 inclusive
			if(string[1] < 58 && string[1] > 47)
			{
				return (((string[0] - 48) * 10) + (string[1] - 48));
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}
	else if(length == 1)
	{
		// between 0 and 9 inclusive
		if(string[0] < 58 && string[0] > 47)
		{
			return string[0] - 48;
		}
	}
	return -1;
}

/**
 *	print a visual line for terminal
 */
void print_hr(void)
{
	for(int i = 0; i < 10; i++)
	{
		printf("----------");
	}
	printf("\n");
}
