#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "doubly.h"

// build create a new doubly linked-list and returns the list
dll* build(int values[], int length);

// remove_nodes removes the nodes between start and end.
// returns the removed nodes as a doubly linked-list.
dll* remove_nodes(dll *list, node *start, node *end);

// delete_last deletes the tail node of the doubly linked-list.
int delete_last(dll *list);

// delete_first deletes the head node of the doubly linked-list.
int delete_first(dll *list);

// insert_last inserts the node with the value to the doubly linked-list's tail.
dll* insert_last(dll *list, int value);

// insert_first inserts the node with the value to the doubly linked-list's head.
dll* insert_first(dll *list, int value);

// print_list prints out all the items in the doubly linked-list.
void print_list(dll *list, char* context, bool line);

// free_list frees all the memory that is allocated during the build process of the doubly linked-list.
void free_list(dll *list);

// get_at gets the node of the given index.
node* get_at(dll *list, int index);

// splice_list connect the another_list to the list's list_index_node emptying the another list.
void splice_list(dll *list, node *list_index_node, dll *another_list);

// create_node creates a new node with the given value.
node* create_node(int value);

// prints the line for visual.
void print_hr();
