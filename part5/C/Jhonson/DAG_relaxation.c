#include "DAG_relaxation.h"

double find_weight(graph *graph,char source, char destination)
{
	assert(graph != NULL);
	int source_hash = hash_function(source);
	assert(source_hash != -1);
	if (source == destination)
	{
		return 0.0;
	}

	node *finger = graph->hash_table[source_hash].next;
	while(finger != NULL && finger->value != destination)
	{
		finger = finger->next;
	}
	if (finger == NULL)
	{
		fprintf(stderr, "ERROR: cannot find the weight of the non-exitstent destination vertex from the source.\n");
		exit(1);
	}

	return finger->weight;
}

bool try_to_relax(graph *graph, shortest_distances *distances, char source, char destination)
{
	// dont need to check source and destination any more these are come directly from the graphs.
	int source_hash = hash_function(source);
	int destination_hash = hash_function(destination);
	double edge_weight = find_weight(graph, source, destination);

	// if d[v] > d[u] + w(u, v)
	if(distances->data[destination_hash].shortest_distance > (distances->data[source_hash].shortest_distance + edge_weight))
	{
		// relax
		distances->data[destination_hash].shortest_distance = distances->data[source_hash].shortest_distance + edge_weight;
		distances->data[destination_hash].parent_vertex = source;
		return true;
	}
	return false;
}

void free_shortest_distances(shortest_distances *distances)
{
	free(distances->data);
	free(distances);
}
