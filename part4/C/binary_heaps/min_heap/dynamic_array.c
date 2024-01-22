#include "dynamic_array.h"

dynamic_array* build_dynamic_array(int values[], int length)
{
	if(length < 1)
	{
		fprintf(stderr, "Can't create an empty dynamic array.\n");
		exit(2);
	}
	else if (values == NULL)
	{
		fprintf(stderr , "Given values array is empty.\n");
		exit(2);
	}
	
	// create a tracker
	dynamic_array *new_dynamic_array = malloc(sizeof(dynamic_array));
	if(new_dynamic_array == NULL)
	{
		fprintf(stderr, "Not enough memory for creating new dynamic array.\n");
		exit(2);
	}

	// create a new space for dynamic array
	int capacity = length * 2;
	int *space = calloc(capacity, sizeof(values[0]));
	if(space == NULL)
	{
		free(new_dynamic_array);
		fprintf(stderr, "Not enough memory for creating space for new dynamic array values.\n");
		exit(2);
	}

	// copy the array to the allocate space.
	for(int i = 0; i < length; i++)
	{
		space[i] = values[i];
	}

	// prepare for return
	new_dynamic_array->base = space;
	new_dynamic_array->size = length;
	new_dynamic_array->capacity = capacity;

	return new_dynamic_array;
}

void free_dynamic_array(dynamic_array *d_array)
{
	if(d_array == NULL)
	{
		fprintf(stderr, "Given dynamic array doesn't exits.");
		exit(1);
	}
	free(d_array->base);
	free(d_array);
	return;
}

void dynamic_array_append(dynamic_array **d_array, int value)
{
	if(d_array == NULL)
	{
		fprintf(stderr, "Given dynamic array doesn't exits.");
		exit(1);
	}

	// create a new one and expand if there's not enough space.
	if(((*d_array)->capacity - (*d_array)->size) < 1)
	{
		dynamic_array* new_dynamic_array = build_dynamic_array((*d_array)->base, (*d_array)->size);
		
		// free the old one.
		free_dynamic_array(*d_array);

		// append in the new one.
		dynamic_array_append(&new_dynamic_array, value);
		*d_array = new_dynamic_array;
		return;
	}

	// there's enough space
	(*d_array)->base[(*d_array)->size] = value;
	(*d_array)->size++;
	return;
}

int dynamic_array_pop(dynamic_array **d_array)
{
	if (d_array == NULL)
	{
		fprintf(stderr, "Given dynamic array doesn't exits.");
		exit(1);
	}
	// if the current size is lower than 50% of capacity, shrink
	// we made the least capacity of 7 so that when we shrink the minimum will be 4 byte size.
	if(((*d_array)->capacity > 7) && ((*d_array)->size <= ((*d_array)->capacity / 2)))
	{
		// create new one
		dynamic_array *new_dynamic_array = build_dynamic_array((*d_array)->base, (*d_array)->size);

		// free the old one.
		free_dynamic_array(*d_array);

		// pop the last item.
		new_dynamic_array->size--;
		*d_array = new_dynamic_array;
		return (*d_array)->base[(*d_array)->size];
	}
	else if((*d_array)->size > 0)
	{
		(*d_array)->size--;
		return (*d_array)->base[(*d_array)->size];
	}
	else
	{
		fprintf(stderr, "Index out of range.\n");
		exit(2);
	}
}

void dynamic_swap(dynamic_array *d_array, int first_index,int second_index)
{
	if(d_array == NULL)
	{
		fprintf(stderr, "Given dynamic array doesn't exits.");
		exit(1);
	}
	else if(first_index == second_index)
	{
		fprintf(stderr, "Swapping the same index is not allowed.\n");
		exit(2);
	}
	else if (first_index > d_array->size || second_index > d_array->size || first_index < 0 || second_index < 0)
	{
		fprintf(stderr, "Array index out of range.\n");
		exit(3);
	}

	int temp = d_array->base[first_index];
	d_array->base[first_index] = d_array->base[second_index];
	d_array->base[second_index] = temp;
	return;
}

void print_underlying(dynamic_array *d_array)
{
	if (d_array == NULL)
	{
		printf("Empty dynamic array.\n");
		return;
	}
	for(int i = 0; i < d_array->capacity; i++)
	{
		printf("%d, ", d_array->base[i]);
	}
	printf("\n");
	return;
}

void print_array(dynamic_array *d_array)
{
	if (d_array == NULL)
	{
		printf("Empty dynamic array.\n");
		return;
	}
	for(int i = 0; i < d_array->size; i++)
	{
		printf("%d, ", d_array->base[i]);
	}
	printf("\n");
	return;
}

void print_both(dynamic_array *d_array)
{
	if (d_array == NULL)
	{
		printf("Empty dynamic array.\n");
		return;
	}
	printf("Inside: ");
	print_array(d_array);
	printf("Underlying: ");
	print_underlying(d_array);
	return;
}
