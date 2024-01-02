#include "utils.h"

// doubly linked-list will not maintain the length of the list.

// print_list function prints out the given doubly linked-list's item numbers.
void print_list(dll *list, char* context, bool line)
{
	printf("%s", context);
	node *finger = list->head;
	while(finger != NULL)
	{
		printf("%i->", finger->number);
		finger = finger->next;
	}
	printf("\n");
	if (line == true)
	{
		print_hr();
	}
}

void print_hr()
{
	for (int i = 0; i < 10; i++)
	{
		printf("----");
	}
	printf("\n");
}

node* get_at(dll *list, int index)
{
	node *current = list->head;
	index--;
	for (int i = 0; i < index; i++)
	{
		if (current == NULL || current->next == NULL)
		{
			return NULL;
		}
		current = current->next;
	}
	return current;
}

// free_list free the 
void free_list(dll *list)
{
	if (list == NULL)
	{
		return;
	}
	node *finger = list->head;
	while (finger != NULL)
	{
		node *next = finger->next;
		free(finger);
		finger = next;
	}
}

dll* build(int values[], int length)
{
	dll *list = malloc(sizeof(dll));
	if (list == NULL)
	{
		return NULL;
	}
	list->head = NULL;
	list->tail = NULL;

	for (int i = 0; i < length; i++)
	{
		node *new_node = create_node(values[i]);
		if(new_node == NULL)
		{
			free_list(list);
			return NULL;
		}
		// we will use append
		// if the list is empty
		if (list->tail == NULL)
		{
			list->head = new_node;
		}
		else 
		{
			list->tail->next = new_node;
			new_node->prev = list->tail;
		}
		list->tail = new_node;
	}

	return list;
}

node* create_node(int value)
{
	node *new_node = malloc(sizeof(node));
	if(new_node == NULL)
	{
		return NULL;
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->number = value;
	return new_node;
}

// part (a), constant operations
// insert_first(x), insert_last(x), delete_first(), delete_last()

dll* insert_first(dll *list, int value)
{
	node *new_node = create_node(value);
	if (new_node == NULL)
	{
		return NULL;
	}
	new_node->prev = NULL;
	new_node->next = list->head;
	list->head = new_node;
	return list;
}


dll* insert_last(dll *list, int value)
{
	node *new_node = create_node(value);
	if (new_node == NULL)
	{
		return NULL;
	}
	// linking the two nodes.
	list->tail->next = new_node;
	new_node -> prev = list->tail;

	// updaing the tail
	list->tail = new_node;
	new_node -> next = NULL;

	return list;
}


int delete_first(dll *list)
{
	node *first_node = list->head;
	list->head = first_node->next;
	first_node->prev = NULL;

	int value = first_node->number;
	free(first_node);
	return value;
}

int delete_last(dll *list)
{
	node *last_node = list->tail;
	list->tail = last_node->prev;
	list->tail->next = NULL;

	int value = last_node->number;
	free(last_node);
	return value;
}


// part(b) Given two nodes x1 and x2 from dll. consider x1 occurs before x2
// constant time algorithm to remove all nodes from x1 to x2 inclsive.
// return them as a new doubly linked list.
dll* remove_nodes(dll *list, node *start, node *end)
{
	if (list->head == NULL)
	{
		printf("The list is empty");
		return NULL;
	}

	dll *removed_dll = malloc(sizeof(dll));
	// linking for the remove item.
	removed_dll->head = start;
	removed_dll->tail = end;

	if (list->head == start)
	{
		list->head = end->next;
	}
	else 
	{
		start->prev->next = end->next;
	}

	if (list->tail == end)
	{
		// relinking the original
		list->tail = start->prev;
	}
	else 
	{
		end->next->prev = start->prev;
	}

	start->prev = NULL;
	end->next = NULL;
	return removed_dll;
}


//part(c) Given node x from a doubly linked-list and second doubly linked-list
//constatnt time algorithm to splice second dll into first dll
//frist dll should contain all items previously in either list
// second dll should be empty
void splice_list(dll *list, node *list_index_node, dll *another_list)
{
	if (list->head == NULL || list_index_node == NULL || another_list->head == NULL)
	{
		return;
	}

	// link the another list to the original list
	another_list->tail->next = list_index_node->next;
	another_list->head->prev = list_index_node;
	// link the node to the another_list
	list_index_node->next = another_list->head;

	// empty the another_list
	another_list->head = NULL;
	another_list->tail = NULL;
	return;
}
