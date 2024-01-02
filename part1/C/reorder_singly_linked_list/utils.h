#include <stdio.h>
#include <stdlib.h>
// singly linked-list node
typedef struct node 
{
	int value;
	struct node* next;
}node;

// build builds a new singly linked-list given the values and length of the list.
node* build(int values[], int length);

// free_list frees the memory that is allocated during the process creating the given singly linked-list.
void free_list(node *list);

// half_reverse reverse the second half of the given singly_linked list.
void half_reverse(node *list, int length);

// print_list prints the items that is inside the singly linked-list with the prefix context.
void print_list(node* list, char* context);
