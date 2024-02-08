#include "utils.h"

shortest_distances* Bellman_Ford(graph *graph, char source, char parents[])
{
	if(graph == NULL)
	{
		return NULL;
	}
	int source_hash = hash_function(source);
	if(source_hash == -1)
	{
		return NULL;
	}

	shortest_distances *distances = calloc(1, sizeof(shortest_distances));
	if(distances == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating shortest_distances struct.\n");
		exit(1);
	}
	distances->data = calloc(MAX_CHAR, sizeof(distance_node));
	if(distances->data == NULL)
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

	// number of vertices
	distances->size = graph->total_vertices;

	// relax all edges in (V - 1) rounds
	for(int i = 0; i < distances->size - 1; i++)
	{
		// for every vertices
		for(int j = 0; j < MAX_CHAR; j++)
		{
			if(graph->hash_table[j].value != '\0')
			{
				// for every outgoing edges.
				for(node* adj_node = graph->hash_table[j].next; adj_node != NULL; adj_node = adj_node->next)
				{
					// relax that vertex and it's adjacency
					bool relaxed = try_to_relax(graph, distances, graph->hash_table[j].value, adj_node->value);
					if(relaxed == true)
					{
						parents[hash_function(adj_node->value)] = graph->hash_table[j].value;
					}
				}
			}
		}
	}

	// relax edges in (Vth) round to detect negative weight cycles for every vertices
	for(int i = 0; i < MAX_CHAR; i++)
	{
		if(graph->hash_table[i].value != '\0')
		{
			for(node* adj_node = graph->hash_table[i].next; adj_node != NULL; adj_node = adj_node->next)
			{
				int source_hash = hash_function(graph->hash_table[i].value);
				int destination_hash = hash_function(adj_node->value);
				double edge_weight = find_weight(graph, graph->hash_table[i].value, adj_node->value);
				if(distances->data[destination_hash].shortest_distance > (distances->data[source_hash].shortest_distance + edge_weight))
				{
					fprintf(stderr, "ERROR: the graph contains a negative weight cycle.!");
					exit(2);
				}
			}
		}
	}
	return distances;
}

graph* duplicate_graph(graph* graph)
{
	// for the given graph
		// array of vertices. with zero weight. total vertices is already known.
		// out degree is already know use that to create array.
	
	// first create the array to keep track of the vertices array.
	graph_dup_vertex* vertices = malloc(sizeof(graph_dup_vertex) * graph->total_vertices);
	if(vertices == NULL)
	{
		exit(1);
	}
	
	// creating V+1 vertices array first.
	// iterate through all the vertices.
	// here using MAX_CHAR due to graph's basic hash map implementation.
	for(int i = 0, j = 0; i < MAX_CHAR; i++)
	{
		// if this vertix exist.
		if(graph->hash_table[i].value != '\0')
		{
			// create the V + 1 array
			char** vertex_array = malloc(sizeof(char*) * graph->total_vertices + 1);
			if(vertex_array == NULL)
			{
				exit(1);
			}
			vertices[j].vertex_array = vertex_array;
			vertices[j].vertex = graph->hash_table[i].value;
			vertices[j].out_degree = graph->hash_table[i].out_degree;
			j++;
		}
	}

	// create the array for the out degrees for every vertices
	for(int i = 0; i < graph->total_vertices; i++)
	{
		// for every dup vertices just to the one before last.
		for(int j = 0; j < graph->total_vertices; j++)
		{
			char* adj_out = malloc(sizeof(graph_dup_adj_vertex) * vertices[i].out_degree);
			if(adj_out == NULL)
			{
				exit(1);
			}
			// copy the adjacencies and pointing to differt level.
			char* adj_out_vertices = out_neighbors(graph, vertices[i].vertex);
			for(int c = 0; c < vertices[i].out_degree; c++)
			{
			}
			vertices[i].vertex_array[j] = adj_out;
		}
	}
	return NULL;
}
