#include "utils.h"

// builds the new singly linked-list.
node* build(int values[], int length)
{
	node *list = NULL;
	for(int i = 0; i < length; i++)
	{
		node *new_node = malloc(sizeof(node));
		if (new_node == NULL)
		{
			return NULL;
		}
		new_node->value = values[i];
		new_node->next = NULL;

		new_node->next = list;
		list = new_node;
	}
	return list;
}

// frees the memeory that is allocated during the process of creating the given singly-linked-list.
void free_list(node *list)
{
	node* finger = list;
	while(finger != NULL)
	{
		node* temp = finger->next;
		free(finger);
		finger = temp;
	}
	return;
}

// reverse the last half of the given singly linked-list.
void half_reverse(node *list, int length)
{
	if(length < 1 || list == NULL)
	{
		return;
	}
	int n = 0;
	int middle = (length / 2);

	node *current = list;
	while(n < middle - 1)
	{
		current = current->next;
		n++;
	}
	//  Reminder! current is the last element of the first half 
	
	// create 3 fingers for reverse linking.
	node *pre_node = current->next;
	node *reverse_node = pre_node->next;
	node *post_node = reverse_node->next;

	// reversing the second_half
	while(post_node != NULL)
	{
		reverse_node->next = pre_node;

		pre_node = reverse_node;
		reverse_node = post_node;
		post_node = post_node->next;
	}

	// if this is the last pair.
	reverse_node->next = pre_node;
	
	// clean up the mess
	// this is to make the first element of the second half as the last element.
	// post_node is already NULL by the loop 
	// we can also make
	// current->next->next= post_node;
	current->next->next = NULL;
	// this is to link between reversed and first half.
	current->next = reverse_node;
	return;
}

// prints out the item's value in the given  singly linked-list with the prefixed context.
void print_list(node* list, char* context)
{
	printf("%s", context);
	node *finger = list;
	while(finger != NULL)
	{
		printf("%d->", finger->value);
		finger = finger->next;
	}
	printf("\n");
}
