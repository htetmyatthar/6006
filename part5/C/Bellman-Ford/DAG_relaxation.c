#include "DAG_relaxation.h"

shortest_distances* DAG_relaxation(graph *graph, char source)
{
	if (graph == NULL)
	{
		return NULL;
	}
	int source_hash = hash_function(source);
	// invalid source
	if (source_hash == -1)
	{
		return NULL;
	}

	// just a dummy allocation necessary for dfs.
	char* parent_array = calloc(MAX_CHAR, sizeof(char));
	if (parent_array == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating parent array for dfs.\n");
		exit(1);
	}

	// from tail to head is the topological sort order.
	// from head to tail is reversed topological order.
	queue_list *order = dfs(graph, source, parent_array);
	free(parent_array);

	shortest_distances *distances = calloc(1, sizeof(shortest_distances));
	if (distances == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating shortest_distances struct.\n");
		exit(1);
	}
	distances->data = calloc(MAX_CHAR, sizeof(distance_node));
	if (distances->data == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating shortest_distances data array.\n");
		exit(1);
	}

	// initialize everything to +infinity
	// -infinity is for negative weight cycles and in DAG there's no negative weight cycles.
	for (int i = 0; i < MAX_CHAR; i++)
	{
		distances->data[i].shortest_distance = INFINITY;
	}

	// already initialized no parent as '\0' using calloc.
	// indecies of distances->data are the destination vertices of the source.
	// will use hash_function from the graph.
	
	// initialize the source.
	distances->data[source_hash].parent_vertex = source;
	distances->data[source_hash].shortest_distance = 0;
	distances->source = source;

	// number of vertices that can reach from the source
	distances->size = order->size;

	// for every vertices in topo sort.
	for(queue_node *finger = order->tail; finger != NULL; finger = finger->prev)
	{
		// for every adj^+ of finger's vertex(char)
		for (node *adj_node = graph->hash_table[hash_function(finger->value)].next; adj_node != NULL; adj_node = adj_node->next)
		{
			try_to_relax(graph, distances, finger->value, adj_node->value);
		}
	}

	free_queue_list(order);
	return distances;
}

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
