#include "utils.h"

// a hash function for the table of size
int hash_function(int input)
{
	int output = ((11 * input) + 4) % 9;
	return output;
}

node** hash_map(int values[],int table_size, int length)
{
	// pointer to the array of pointers.
	// size of pointer multiply by the number of items.
	// don't cast the return value of malloc().
	// uses calloc so that the array of pointers will be initialized to NULL.
	node **result_map = calloc(table_size, sizeof(node*));
	if (result_map == NULL)
	{
		return NULL;
	}
	for(int i = 0; i < length; i++)
	{
		// allocate for new node.
		node *new_node = malloc(sizeof(node));
		if (new_node == NULL)
		{
			return NULL;
		}
		// hashing
		int hashed_value = hash_function(values[i]);

		// initalized
		new_node->value = values[i];

		// linking 1)first point to the first element of the linked list.
		// 2) and the array items points to the new node.
		new_node->next = result_map[hashed_value];
		result_map[hashed_value] = new_node;
	}
	return result_map;
}

void free_map(node** hash_table, int table_size)
{
	for(int i = 0; i < table_size; i++)
	{
		node *finger = hash_table[i];
		while(finger != NULL)
		{
			node* temp = finger->next;
			free(finger);
			finger = temp;
		}
	}
	free(hash_table);
}

bool find(node** hash_table, int value)
{
	int hashed_value = hash_function(value);
	node *finger = hash_table[hashed_value];
	while(finger != NULL)
	{
		if (finger->value == value)
		{
			return true;
		}
		finger = finger->next;
	}
	return false;
}

void print_map(node** hash_table, int length)
{
	for (int i = 0; i < length; i++)
	{
		node* finger = hash_table[i];
		while( finger != NULL)
		{
			printf("table index: %d, value: %d\n", i, finger->value);
			finger = finger->next;
		}
	}
}
