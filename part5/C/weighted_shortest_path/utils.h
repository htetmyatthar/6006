#include "dfs.h"
#include <math.h>
#include <assert.h>

// distance_node is to use in creating shortest distance array from some source.
// had to use double to get access to INFINITY.
typedef struct 
{
	char parent_vertex;			// parent vertex of the vertex.
	double shortest_distance;	// shortest distance from some source.
}distance_node;

// shortest_distances is to store the vertices and their shortest distances.
typedef struct
{
	distance_node* data;		// array of distance node.
	int size;					// number of vertices that are reachable from source.
	char source;				// source vertex for the shortest_distances.
}shortest_distances;

shortest_distances* DAG_relaxation(graph *graph, char source);

double find_weight(graph *graph,char source, char destination);

void try_to_relax(graph *graph, shortest_distances *distances, char source, char destination);

void free_shortest_distances(shortest_distances *distances);
