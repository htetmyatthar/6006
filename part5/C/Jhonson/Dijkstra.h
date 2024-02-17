#include "DAG_relaxation.h"

// a node of the chanagable priority queue
typedef struct 
{
	char vertix;				// vertix name
	double distance_estimate;	// distance estimate from source to vertix
}changable_queue_node;

// changable priority queue array implementation
typedef struct 
{
	changable_queue_node* queue_vertix;		// queue vertix array
	changable_queue_node** queue_map;			// map to vertix array for changing distance (key)
	int size;
}changable_PQ_array;

// changable priority queue min heap implementation
typedef struct
{
	changable_queue_node* queue_vertex;	// queue vertex array
	changable_queue_node** queue_map;		// map to vertex array for changin distace(priority key)
	int size;
}changable_PQ_min_heap;

// Dijkstra finds SSSP using the given graph from the given source and update the parent pointers in
// given parents array, returns the shortest_distances.
// Returns NULL if the graph is NULL or parent array is NULL or the given source is invalid.
// Exit code (1) if there are memory related issues.
shortest_distances* Dijkstra(graph *graph, char source, char parent[]);

// changable_PQ_array_build will build an priority queue using array to use in Dijkstra's algorithm.
// Returns the chanageable prioriy queue implemented with array.
// Exit code(1) if there are memory related issues.
changable_PQ_array* changable_PQ_array_build(graph *graph, shortest_distances *distances);

// chahgable_PQ_array_delete_min deletes the minimum priority and return the deleted vertex.
char changable_PQ_array_delete_min(changable_PQ_array *queue);

// changable_PQ_array_decrease_key replace the priority(distance) of the given vertex node with the given distance.
void changable_PQ_array_decrease_key(changable_PQ_array *queue, char vertex, double distance);

// free_PQ_array frees the memory that is allocated during the creation of given changable_PQ_array.
void free_PQ_array(changable_PQ_array *queue);

// changable_PQ_heap_build will build an priority queue using array to use in Dijkstra's algorithm.
// Returns the changable priority queue implemented with min heap.
// Exit code(1) if there are memory related issues.
changable_PQ_min_heap* changable_PQ_heap_build(graph *graph, shortest_distances *distances);

// changeable_PQ_heap_delete_min deletes the minimum priority and return the deleted vertex.
char changable_PQ_heap_delete_min(changable_PQ_min_heap *queue);

// changable_PQ_heap_decrease_key replace the priority(distance) of the given vertex node with the given distance.
void changable_PQ_heap_decrease_key(changable_PQ_min_heap *queue, char vertex, double distance);

// free_PQ_heap frees the memory that is allocated during the creation of given changable_PQ_min_heap.
void free_PQ_heap(changable_PQ_min_heap* queue);
