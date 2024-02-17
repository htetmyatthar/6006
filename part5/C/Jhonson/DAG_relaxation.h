#include "dfs.h"
#include <math.h>
#include <assert.h>
#include <stdbool.h>

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

// DAG_relaxation returns the shortest_distances for the given source in the given graph.
// Returns NULL if the given graph is NULL or the source is invalid.
shortest_distances* DAG_relaxation(graph *graph, char source);

// find_weight returns the weigth of the source from destination in the given graph.
// Returns 0 if the source and the destination are the same meaning the given path is for s,s
// Assertion error if the graph is NULL or the source is invalid.
// exit code (1) if the given source to destination edge doesn't exit.
double find_weight(graph *graph,char source, char destination);

// trye_to_relax acts as a helper function for the DAG_relaxation. Don't have any error checking.
// relax the edges according to the given graph and the source and destination considering estimate distances.
bool try_to_relax(graph *graph, shortest_distances *distances, char source, char destination);

// free_shortest_distances frees the memory that is allocated during the creation of given shortest_distances.
void free_shortest_distances(shortest_distances *distances);
