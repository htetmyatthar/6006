#include "graph.h"
#include <stdbool.h>

// node for queue_list.
typedef struct queue_node
{
	char value;					// queue_node's vertix value(char).
	struct queue_node *next;	// queue_node's pointer to next node.
	struct queue_node *prev;	// queue_node's pointer to previous node.
}queue_node;

// minimal queue using linked list to use in dfs search
typedef struct
{
	int size;			// queue's size.
	queue_node *head;			// queue's start node.
	queue_node *tail;			// queue's last node.
}queue_list;

// full_dfs explore the given graph fully while storing the parent values
// of the visited vertices and returns the explored path.
// Returns NULL if the given graph is NULL or the given parent array is NULL.
// Also returns NULL if there's not enough memory for initializing queue_list to return.
queue_list* full_dfs(graph *graph, char parent[]);

// dfs explore the given graph with the given source while storing the parent values
// of the visited vertices and returns the explored path.
// Returns NULL if the graph is NULL or the given parent array is NULL.
// Also returns NULL if there's not enough memory for initializing queue_list to return.
queue_list* dfs(graph *graph, char source, char parent[]);

// dfs_recursion acts as a helper function to dfs function.
// Explore the given graph with the given source maintaining the parent values of the visited vertices.
// Returns queue_list of path that is being explored for the source vertex.
// If empty_parent is true the source will be marked as root node.
queue_list* dfs_recursion(graph *graph, char source, char parent[], queue_list *order, bool empty_parent);

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
// will print from tail to head.
void print_queue_list(queue_list *queue);
