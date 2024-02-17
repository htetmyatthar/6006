#include "utils.h"

// hash_function to use if there the graph contains one super node with the value of '@'
int super_hash_function(char value)
{
	if (value >= '@' && value <= 'Z')
	{
		// '@' to 'Z' mapped to [0, 25]
		return value - '@';
	}
	else if (value >= 'a' && value <= 'z')
	{
		return value - 'a' + 27;	// +1 for @ symbol supernode.
	}
	return -1;
}

shortest_distances_matrix* Jhonson(graph *graph)
{
	/*
	 *	MAKE A SUPER NODE AND CONNECT TO EVERY VERTICES IN THE GRAPH WITH ZERO WEIGHT EDGES.
	 */

	// for tracking the vertices
	char *vertices = calloc(MAX_CHAR, sizeof(char));
	if(vertices == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for tracking the vertices.\n");
		exit(1);
	}

	// for creating super_node
	hash_node *super_node = calloc(1, sizeof(hash_node));
	if(super_node == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating super node.\n");
		exit(1);
	}
	super_node->value = '@';	// choose @ because this came before the A. sementic as super node.

	int j = 0;
	for(int i = 0; i < MAX_CHAR; i++)
	{
		if(graph->hash_table[i].value != '\0')
		{
			// add an edge to this vertice from the super_node with weight 0.
			node *new_edge = create_node(graph->hash_table[i].value, 0);
			if (new_edge == NULL)
			{
				fprintf(stderr, "Not  enough memory for creating edge nodes.\n");
				exit(1);
			}
			// add the edge.
			new_edge->next = super_node->next;
			super_node->next = new_edge;

			// keep track of vertices.
			vertices[j] = graph->hash_table[i].value;
			j++;
		}
	}
	// number of vertices that is outgoing from super node.
	super_node->out_degree = j;	

	/*
	 *	RUN BELLMAN-fORD TO FIND THE POTENTIALS AND THE NEGATIVE WEIGHT CYCLES TO REWEIGHT THE GRAPH.
	 */
	shortest_distances *distances = calloc(1, sizeof(shortest_distances));
	if(distances == NULL)
	{
		fprintf(stderr, "Not enough memory for storing potentials.\n");
		exit(1);
	}
	distances->data = calloc(MAX_CHAR + 1, sizeof(distance_node));
	if(distances->data ==  NULL)
	{
		fprintf(stderr, "Not enough memory for storing potentials.\n");
		exit(1);
	}
	int super_hash = super_hash_function(super_node->value);

	// initialize everything to infinity
	for(int i = 0; i < MAX_CHAR + 1; i++)
	{
		distances->data[i].shortest_distance = INFINITY;
	}
	distances->data[super_hash].parent_vertex = super_node->value;
	distances->data[super_hash].shortest_distance = 0;
	distances->source = super_node->value;
	distances->size = graph->total_vertices + 1;

	// relax all edges in (V - 1) rounds
	for(int i = 0; i < distances->size - 1; i++)
	{
		// adj+ from super node
		for(node *adj_node = super_node->next; adj_node != NULL; adj_node = adj_node->next)
		{
			int destination_hash = super_hash_function(adj_node->value);
			if(distances->data[destination_hash].shortest_distance > (distances->data[super_hash].shortest_distance + adj_node->weight))
			{
				distances->data[destination_hash].shortest_distance = distances->data[super_hash].shortest_distance + adj_node->weight;
				distances->data[destination_hash].parent_vertex = super_node->value;
			}
		}
		// all vertices in the graph
		for(int j = 0; j < super_node->out_degree; j++)
		{
			int source_org_hash = hash_function(vertices[j]);
			for(node* adj_node = graph->hash_table[source_org_hash].next; adj_node != NULL; adj_node = adj_node->next)
			{
				int source_hash = super_hash_function(vertices[j]);
				int destination_hash = super_hash_function(adj_node->value);
				int weight = find_weight(graph, vertices[j], adj_node->value);
				if(distances->data[destination_hash].shortest_distance > (distances->data[source_hash].shortest_distance + weight))
				{
					distances->data[destination_hash].shortest_distance = distances->data[source_hash].shortest_distance + weight;
					distances->data[destination_hash].parent_vertex = vertices[j];
				}
			}
		}
	}

	// relax all edges Vth round to find negative weight cycle.
	// adj+ from super node
	for(node *adj_node = super_node->next; adj_node != NULL; adj_node = adj_node->next)
	{
		int destination_hash = super_hash_function(adj_node->value);
		if(distances->data[destination_hash].shortest_distance > (distances->data[super_hash].shortest_distance + adj_node->weight))
		{
			fprintf(stderr, "This graph contains a negative weight cycle.");
			exit(2);
		}
	}
	// all vertices in the graph
	for(int j = 0; j < super_node->out_degree; j++)
	{
		int source_org_hash = hash_function(vertices[j]);
		for(node* adj_node = graph->hash_table[source_org_hash].next; adj_node != NULL; adj_node = adj_node->next)
		{
			int source_hash = super_hash_function(vertices[j]);
			int destination_hash = super_hash_function(adj_node->value);
			int weight = find_weight(graph, vertices[j], adj_node->value);
			if(distances->data[destination_hash].shortest_distance > (distances->data[source_hash].shortest_distance + weight))
			{
				fprintf(stderr, "This graph contains a negative weight cycle.");
				exit(2);
			}
		}
	}

	/*
	 *	IF THERE ARE NO NEGATIVE WEIGHT CYCLES, REWEIGHT EDGES.
	 */
	for(int i = 0; i < super_node->out_degree; i++)
	{
		int source_hash = hash_function(vertices[i]);
		for(node *adj_node = graph->hash_table[source_hash].next; adj_node != NULL; adj_node = adj_node->next)
		{
			adj_node->weight = (
				adj_node->weight 
				+ distances->data[super_hash_function(vertices[i])].shortest_distance 
				- distances->data[super_hash_function(adj_node->value)].shortest_distance);
		}
	}

	/*
	 *	COMPUTE SHORTEST PATHS delta(u, v) FOR ALL v IN V IN G prime, WHILE ALSO CALCULATIG THE REAL SHORTEST PATH.
	 */
	shortest_distances_matrix *distances_matrix = malloc(sizeof(shortest_distances_matrix));
	if(distances_matrix == NULL)
	{
		fprintf(stderr, "Not enough memory for all pairs shortest paths.\n");
		exit(1);
	}
	shortest_distances **shortest_paths = malloc(sizeof(shortest_distances*) * super_node->out_degree);
	if(distances == NULL)
	{
		fprintf(stderr, "Not enough memory for storing all pairs distances.\n");
		exit(1);
	}
	char **parent_matrix = malloc(sizeof(char*) * super_node->out_degree);
	if(parent_matrix == NULL)
	{
		fprintf(stderr, "Not enough memory for storing all pairs parent vertices.\n");
		exit(1);
	}

	distances_matrix->distance_matrix = shortest_paths;
	distances_matrix->parent_matrix = parent_matrix;
	distances_matrix->vertices = &vertices[0];

	for(int i = 0; i < super_node->out_degree; i++)
	{
		char *parents = calloc(MAX_CHAR, sizeof(char));
		if(parents == NULL)
		{
			fprintf(stderr, "Not enough memory for storing parent vertices.\n");
			exit(1);
		}
		distances_matrix->distance_matrix[i] = Dijkstra(graph, vertices[i], parents);
		distances_matrix->parent_matrix[i] = parents;
		// computer actual shortest paths.
		for(int j = 0; j < super_node->out_degree; j++)
		{
			distances_matrix->distance_matrix[i]->data[hash_function(vertices[j])].shortest_distance = (
				distances_matrix->distance_matrix[i]->data[hash_function(vertices[j])].shortest_distance
				- distances->data[super_hash_function(vertices[i])].shortest_distance 
				+ distances->data[super_hash_function(vertices[j])].shortest_distance);
		}
	}

	// recalculate the original weights to the graph.
	for(int i = 0; i < super_node->out_degree; i++)
	{
		int source_hash = hash_function(vertices[i]);
		for(node *adj_node = graph->hash_table[source_hash].next; adj_node != NULL; adj_node = adj_node->next)
		{
			adj_node->weight = (
				adj_node->weight 
				- distances->data[super_hash_function(vertices[i])].shortest_distance 
				+ distances->data[super_hash_function(adj_node->value)].shortest_distance);
		}
	}
	
	node *finger = super_node->next;
	while(finger != NULL)
	{
		node* temp = finger->next;
		free(finger);
		finger = temp;
	}
	free(super_node);
	free(distances->data);
	free(distances);
	return distances_matrix;
}
