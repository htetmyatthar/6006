#include <stdio.h>
#include "utils.h"

void print_array(int array[], int length);
void print_hr();

int main(void){
	int test_array[] = {8, 4, 5, 6, 9, 3, 7, 2, 1, 0};
	int length = sizeof(test_array) / sizeof(test_array[0]);
	printf("original: \n");
	print_array(test_array, length);
	bubble_sort(test_array, length);
	printf("sorted: \n");
	print_array(test_array, length);
	print_hr();

	int test_array1[] = {91, 40, 89, 55, 39, 28, 59, 23, 7, 65, 49, 94, 57, 52, 19, 5, 76, 93, 3, 9, 18, 64, 96, 43, 42, 90, 72, 56, 50, 46, 83, 99, 41, 20, 15, 36, 16, 61, 35, 45, 34, 26, 81, 11, 74, 84, 12, 8, 68, 30, 66, 95, 29, 58, 80, 4, 38, 85, 22, 53, 86, 79, 51, 48, 17, 13, 24, 98, 63, 2, 71, 47, 31, 82, 33, 37, 54, 75, 44, 70, 67, 1, 77, 92, 32, 78, 97, 6, 62, 87, 73, 100, 14, 27, 69, 88, 60, 10, 21, 25};
	int length1 = sizeof(test_array1) / sizeof(test_array1[0]);
	printf("original: \n");
	print_array(test_array1, length1);
	bubble_sort(test_array1, length1);
	printf("sorted: \n");
	print_array(test_array1, length1);
	print_hr();
}

void print_array(int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%i, ", array[i]);
	}
	printf("\n");
}

void print_hr()
{
	for (int i = 0; i < 10; i++)
	{
		printf("-----");
	}
	printf("\n");
}
