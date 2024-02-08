#include "DAG_relaxation.h"

// THIS IS FOR BELLMAN-FORD graph duplication.
typedef struct graph_dup_adj_vertex
{
	char* adj_vertices;		// pointer to other vertecies
	char vertex;			// vertex value
}graph_dup_adj_vertex;

// to track the duplicated graph while implementing.
typedef struct graph_dup_vertex
{
	char vertex;			// vertex's value or char
	int out_degree;			// out degree of the vertex
	char** vertex_array;	// pointer to the array of vertex arrays.
}graph_dup_vertex;

//IDEA: add another edge to the graph_dup_adj_vertex.


// Bellman_Ford returns the shortest paths if there's no negative weight cycles.
// Exit code(2) if the graph has negative cycles.
// Exit code(1) if there's not enough memory for shortest_distances or shortest_distances->data.
shortest_distances* Bellman_Ford(graph *graph, char source);
