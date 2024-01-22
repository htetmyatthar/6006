#include "dynamic_array.h"

void test_build();
void test_append();
void test_pop();
void test_swap();

int main(void)
{
	test_build();
	test_append();
	test_pop();
	test_swap();
	printf("Test complete.\n");
}

void test_build()
{
	int given[] = {1, 2};
	int length = sizeof(given) / sizeof(given[0]);
	dynamic_array* d_array = build_dynamic_array(given, length);
	printf("testing inside array.\n");
	for(int i = 0; i < d_array->size; i++)
	{
		assert(given[i] == d_array->base[i]);
	}

	printf("testing underlying array.\n");
	int expected_values[] = {1, 2, 0, 0};
	for(int i = 0; i < d_array->capacity; i++)
	{
		assert(expected_values[i] == d_array->base[i]);
	}
	assert(d_array->size == 2);
	assert(d_array->capacity == 4);
	free_dynamic_array(d_array);
}

void test_append()
{
	int given[] = {1, 2};
	int length = sizeof(given) / sizeof(given[0]);
	dynamic_array* d_array = build_dynamic_array(given, length);
	printf("testing append\n");
	dynamic_array_append(&d_array, 99);
	dynamic_array_append(&d_array, 88);
	int expected_values[] = {1, 2, 99, 88};
	for(int i = 0; i < d_array->capacity; i++)
	{
		assert(expected_values[i] == d_array->base[i]);
	}
	assert(d_array->size == 4);
	assert(d_array->capacity == 4);

	printf("testing bigger resize.\n");
	dynamic_array_append(&d_array, 7);
	int expected_values1[] = {1, 2, 99, 88, 7};
	for(int i = 0; i < d_array->size; i++)
	{
		assert(expected_values1[i] == d_array->base[i]);
	}
	assert(d_array->size == 5);
	assert(d_array->capacity == 8);
	free_dynamic_array(d_array);
}

void test_pop()
{
	int given[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int length = sizeof(given) / sizeof(given[0]);
	dynamic_array* d_array = build_dynamic_array(given, length);
	printf("testing pop\n");
	int deleted_value = dynamic_array_pop(&d_array);
	int deleted_value1 = dynamic_array_pop(&d_array);
	assert(deleted_value == 8);
	assert(deleted_value1 == 7);
	int expected_values[] = {1, 2, 3, 4, 5, 6};
	for(int i = 0; i < d_array->size; i++)
	{
		assert(expected_values[i] == d_array->base[i]);
	}
	assert(d_array->size == 6);
	assert(d_array->capacity == 14);
	free_dynamic_array(d_array);
}

void test_swap()
{
	int given[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int length = sizeof(given) / sizeof(given[0]);
	dynamic_array* d_array = build_dynamic_array(given, length);
	printf("testing swap.\n");
	dynamic_swap(d_array, 2, 4);
	assert(d_array->base[2] == 5);
	assert(d_array->base[4] == 3);
	free_dynamic_array(d_array);
}
