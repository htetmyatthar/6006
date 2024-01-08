#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// singly linked list node for chaining.
typedef struct node
{
	int value;			// value store in the node
	struct node *next;	// pointer to the next node.
}node;

// hash_map create a hash map with the given table_size 
// using values and length to return the address of created map.
node** hash_map(int values[], int table_size, int length);

// hash_function hashes the input by the given problem.
int hash_function(int input);

// print_map prints out the all the values and their hash table index in the hash map.
void print_map(node** hash_table, int length);

// find finds the given value in the given hash function and returns true if presence.
// else return false.
bool find(node** hash_table, int value);

// free map frees the hash_table for the table_size.
void free_map(node** hash_table, int table_size);
