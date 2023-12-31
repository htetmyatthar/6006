#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

// create_node create a singly linked-list's node and returns it
node* create_node(int number)
{
	node *new_node = malloc(sizeof(node));
	if (new_node == NULL)
	{
		return NULL;
	}
	new_node->number = number;
	new_node->next = NULL;
	return new_node;
}

// build create a linked-list and returns it.
node* build(int numbers[], int length)
{
	if (length == 0)
	{
		return NULL;
	}
	node *list = NULL;
	for (int i = 0; i < length; i++)
	{
		// create a new node.
		node *new_node = create_node(numbers[i]);

		// prepend the node.
		new_node->next = list;
		list = new_node;
	}
	return list;
}

// print_list print the list till the NULL.
void print_list(node *list)
{
	node *finger = list;
	while (finger != NULL)
	{
		printf("%i->", finger->number);
		finger = finger->next;
	}
	printf("\n");
}

// free_list frees the memory that is allocated during the build
// process of the given list.
void free_list(node *list)
{
	node *finger = list;
	while (finger != NULL)
	{
		node *next = finger->next;
		free(finger);
		finger = next;
	}
}

// get_at returns the index-th node in the linked-list.
node* get_at(node *list, int index)
{
	node *current = list;

	for (int i = 0; i < index; i++)
	{
		if (current == NULL || current->next == NULL)
		{
			printf("linked-list index out of range.");
			return NULL;
		}
		current = current->next;
	}
	return current;
}

// set at set the given singly linked-list's index with the new_value.
void set_at(node *list, int index, int new_value)
{
	node *current = list;
	index--;

	for(int i = 0; i < index; i++)
	{
		if (current == NULL || current->next == NULL)
		{
			printf("linked-list index out of range.");
			return;
		}
		current = current->next;
	}
	current->number = new_value;
}

// delete the first item, in other words last inputted item in constant time.
node* delete_first(node *list)
{
	node *tmp = list;
	list = tmp->next;
	free(tmp);
	return list;
}

// create a function that can append to the end of the singly linked-list in constant time.
// have to change the data struct for node.
