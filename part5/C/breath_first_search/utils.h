#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

// node for queue_list.
typedef struct queue_node
{
	char value;					// queue_node's vertix value(char).
	struct queue_node *next;	// queue_node's pointer to next node.
	struct queue_node *prev;	// queue_node's pointer to previous node.
}queue_node;

// minimal queue using linked list to use in bfs search
typedef struct
{
	int size;			// queue's size.
	queue_node *head;			// queue's start node.
	queue_node *tail;			// queue's last node.
}queue_list;

// bfs explore the given graph in breath first manner.
// returns the char array such that indexes are the vertex,
// and the values are its' one of the parents.
// Single Source Shortest Path.
char* bfs(graph *graph, char start_vertex);

// find_path finds one of the shortest path from source to destination using
// breath first searh algorithm.
// The resulted path is not the shortest path. It's one of many.
// Returns the shortest path queue list.
// Returns NULL if the given graph is NULL or the source is the same as destination.
queue_list* find_path(graph *graph, char source, char destination);

// init_queue initialize a new doubly linked list to be used as a queue.
// exit code (1) if there's not enough memory for creating queue_list.
queue_list* init_queue(void);

// enqueue insert a queue_node with the given vertex to the last place
// of the given quque_list.
// Caution: Not checking valid vertex or not, since this will only be used for queue_list.
// Returns true if everything's okay.
// Returns false if there's not enough memory for creating queueu_node.
bool enqueue(queue_list *queue, char vertex);

// dequeueu deletes and frees the first node of the given queue_list.
// Returns true if everything's okay.
// Returns false if there's no node to dequeue.
char dequeue(queue_list *queue);

// free_queue_list frees memory of the given queue_list.
void free_queue_list(queue_list *queue);

// print_queue_list prints out the chars in the given queue_list.
void print_queue_list(queue_list *queue);
