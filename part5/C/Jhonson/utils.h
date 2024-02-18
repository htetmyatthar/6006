#include "Bellman-Ford.h"

// an array of all shortest paths. vertices array's indexes are the same as the other array.
typedef struct
{
	shortest_distances **distance_matrix;	// array of shortest paths for every vertices in the graph.
	char **parent_matrix;	// array of parent pointers for every vertices in the graph.
	char *vertices;		// array of vertices to reference the indecies.
}shortest_distances_matrix;

// Jhonson returns the all pairs shortest paths using the given graph.
// exit code (1) if there are memory related issues.
// exit code (2) if there is negative weight cycle.
shortest_distances_matrix *Jhonson(graph *graph);
