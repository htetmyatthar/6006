#include "utils.h"

// d_array builds a new dynamic array with the given array of values and length(no. of elements in values).
// exit if the length is less than 1.
// exit if there's not enough space when memory allocating.
// returns dynamic_array. 
// CAUTIONS: Memory is no cleaned immediately after poping or dequeuing.
// Uses calloc for inisitalizing.
dynamic_array_track*  build_d_array(int values[], int length)
{
	if (length < 1)
	{
		printf("Array is empty.\n");
		exit(1);
	}


	// didn't use calloc, for more efficiency.
	dynamic_array_track* dynamic_array = malloc(sizeof(dynamic_array_track));
	if (dynamic_array == NULL)
	{
		printf("No space for the head.\n");
		exit(2);
	}

	int capacity = length * 2;
	int* space = calloc(capacity, sizeof(int));
	if (space == NULL)
	{
		free(dynamic_array);
		printf("Didn't have enough space.\n");
		exit(2);
	}

	// we can guarentee that start_index will always round down for odd numbers.
	//  we want to have more empty spaces for prepend. I think prepend is more common.
	int start_index = length / 2;

	// copy the array to the allocated space.
	for (int i = 0; i < length; i++)
	{
		space[start_index + i] = values[i];
	}

	// set the values to the corresponding one.
	dynamic_array->base = space;
	dynamic_array->size = length;
	dynamic_array->capacity = capacity;
	// start is zero indexing.
	dynamic_array->start = start_index;
	return dynamic_array;
}

void Print_both(dynamic_array_track *d_array)
{
	printf("Inside: ");
	print_d_array(d_array);
	printf("Underlying: ");
	print_all_d_array(d_array);
}

// print_d_array prints the values of all the d_array items.
void print_d_array(dynamic_array_track *d_array)
{
	for (int i = 0; i < d_array->size ; i++)
	{
		printf("%d,", d_array->base[d_array->start + i]);
	}
	printf("\n");
	return;
}

// prind_all_d_array prints the values of all the space items.
// CAUTION: garbage variables will exists in this printing.
// JUST FOR TESTING PURPOSE.
void print_all_d_array(dynamic_array_track *d_array)
{
	for(int i = 0; i < d_array->capacity; i++)
	{
		printf("%d,", d_array->base[i]);
	}
	printf("\n");
	return;
}


// d_array_append appends value to the end of the d_array
// resize if there's not enough space.
// Returns a new dynamic array if resized, else return NULL.
dynamic_array_track* d_array_append(dynamic_array_track *d_array, int value)
{
	// if there's no more space to append
	if ((d_array->capacity - (d_array->start + d_array->size)) < 1 )
	{
		// build a new one
		dynamic_array_track *new_d_array = build_d_array(d_array->base + d_array->start, d_array->size);
		// free the old one
		free_d_array(d_array);
		// try to append again.
		d_array_append(new_d_array, value);
		
		return new_d_array;
	}
	
	// append after the last element
	d_array->base[d_array->start + d_array->size] = value;
	d_array->size++;
	return NULL;
}

// d_array_prepend prepends value to the start of the d_array
// resize if there's not enough space.
// Returns a new dynamic array if resized, else return NULL.
dynamic_array_track* d_array_prepend(dynamic_array_track *d_array, int value)
{
	// if there's no more space to prepend
	if (d_array->start < 1)
	{
		// build a new one
		dynamic_array_track *new_d_array = build_d_array(d_array->base + d_array->start, d_array->size);
		// free the old one
		free_d_array(d_array);
		// try to prepend again
		d_array_prepend(new_d_array, value);
		
		return new_d_array;
	}
	
	// prepend will affect the array indexing.
	d_array->base[d_array->start - 1] = value;
	d_array->size++;
	d_array->start--;
	return NULL;
}

// d_array_pop pops the last element of the d_array
// resize if there is too much empty space.
dynamic_array_track* d_array_pop(dynamic_array_track *d_array)
{

	// if the current size is lower than 25% of capacity, shrink
	//  we made the least capacity of 7 so that when we shrink the minimum will be 2 byte size.
	if ((d_array->capacity > 7) && (d_array->size <= (d_array->capacity / 4)))
	{
		// build a new one
		dynamic_array_track *new_d_array = build_d_array(d_array->base + d_array->start, d_array->size);
		// free the old one
		free_d_array(d_array);

		// pop the last item
		new_d_array->size--;

		return new_d_array;

	}
	else if (d_array->size > 0) 
	{
		// pop the last item
		d_array->size--;
		return NULL;
	}
	else 
	{
		printf("Index out of range.\n");
		free_d_array(d_array);
		exit(1);
	}
	
	return NULL;
}

// d_array_dequeue removes the first element of the d_array
// resize if there is too much empty space.
// Returns a new dynamic array if resized, else return NULL.
dynamic_array_track* d_array_dequeue(dynamic_array_track *d_array)
{
	//////////////////////////////////////////// NOT FINISHED////////////////////////////////////////////

	// if the current size is lower than 25% of capacity, shrink
	if ((d_array->capacity > 7) && (d_array->size < (d_array->capacity / 4)))
	{
		// build a new one
		dynamic_array_track *new_d_array = build_d_array(d_array->base + d_array->start, d_array->size);
		// free the old one
		free_d_array(d_array);

		// dequeue the first item
		new_d_array->size--;
		new_d_array->start++;

		return new_d_array;

	}
	else if (d_array->size > 0)
	{
		// dequeue the first item
		d_array->size--;
		d_array->start++;
		return NULL;
	}
	else 
	{
		printf("Index out of range.\n");
		free_d_array(d_array);
		exit(1);
	}
	return NULL;
}

// set_at sets the index of the d_array with the value
// exit if the index is larger than number of elements or less than zero
void set_at(dynamic_array_track *d_array, int index, int value)
{
	if (index > d_array->size || index < 0) 
	{
		// free memory and exit the program.
		free_d_array(d_array);
		printf("Index out of range.\n");
		exit(1);
	}
	d_array->base[d_array->start + (index - 1)] = value;
}

// get_at gets the index^th item of the d_array
// exit if the index is larger than number of elements or less than zero
int get_at(dynamic_array_track *d_array, int index)
{
	if (index > d_array->size || index < 0)
	{
		// free memory and exit the program.
		free_d_array(d_array);
		printf("This happened.Index out of range.\n");
		exit(1);
	}
	return d_array->base[d_array->start + (index - 1)];
}

// delete_at deletes the item at the index and returns a new dynamic array ocassionally.
// If the d_array-> size is less than 1 we end the program.
// Calls the d_array_dequeue if the given index is the first index of the d_array.
// Calls the d_array_pop if the given index is the last index of the d_array.
// Returns the same sized dynamic array after the delete operation.
dynamic_array_track* delete_at(dynamic_array_track *d_array, int index)
{

	if (d_array->size < 1)
	{
		return NULL;
	}
	// if this is the first element
	else if (index == 1)
	{
		dynamic_array_track *new_array = d_array_dequeue(d_array);
		if (new_array != NULL)
		{
			d_array = new_array;
		}
		return d_array;
	}
	// if this is the last element
	else if (index == d_array->size - 1)
	{
		dynamic_array_track *new_array = d_array_pop(d_array);
		if (new_array != NULL)
		{
			d_array = new_array;
		}
		return d_array;
	}
	else 
	{
		// allocate new array, we can use the build_d_array but that will be painful for performance when the dataset is larger.
		// because it'll be O(n*n) because we have to overwrite the items that is later in the index, copy pasting will be O(n).

		// didn't use calloc, for more efficiency.
		int length = d_array->size;
		dynamic_array_track* new_dynamic_array = malloc(sizeof(dynamic_array_track));
		if (new_dynamic_array == NULL)
		{
			printf("No space for the head.\n");
			exit(2);
		}

		int capacity = length * 2;
		// the same size as the elements of the original array.
		int* space = calloc(capacity, sizeof(d_array->base));
		if (space == NULL)
		{
			free(new_dynamic_array);
			printf("Didn't have enough space.\n");
			exit(2);
		}

		// we dont have to calculate start_index, we will use the original's.

		// copy the array to the allocated space till the index.
		for (int i = 0; i < (length - index - 1); i++)
		{
			space[d_array->start + i] = d_array->base[d_array->start + i];
		}

		// copy the later items that are after the index.
		for (int j = index; j < length; j++)
		{
			space[d_array->start + j - 1] = d_array->base[d_array->start + j];
		}

		// set the values to the corresponding one.
		new_dynamic_array->base = space;
		new_dynamic_array->size = length;
		new_dynamic_array->capacity = capacity;
		// start is zero indexing.
		new_dynamic_array->start = d_array->start;

		// free the original array that is no longer needed.
		free_d_array(d_array);
		return new_dynamic_array;
	}
}

// free_d_array frees the memory that is allocated during the creation of d_array.
void free_d_array(dynamic_array_track *d_array)
{
	free(d_array->base);
	free(d_array);
}

// print_hr prints a visual line.
void print_hr(void)
{
	for(int i = 0; i < 10; i++)
	{
		printf("------");
	}
	printf("\n");
}
