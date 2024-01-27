#include "utils.h"

graph* create_graph(char vertices[], int total_vertices)
{
	// allocate memory for a new graph
	graph *new_graph = malloc(sizeof(graph));
	if (new_graph == NULL)	
	{
		fprintf(stderr, "Not enough memory for initializing a new graph.\n");
		exit(1);
	}
	// allocate memory for new graph's hash map.
	hash_node* new_graph_map = calloc(MAX_CHAR, sizeof(hash_node));
	if (new_graph_map == NULL)
	{
		free(new_graph);
		fprintf(stderr, "Not enough memory for creating a new graph map.\n");
		exit(1);
	}

	// add the vertices and other data.
	new_graph->hash_table = new_graph_map;
	new_graph->total_vertices = total_vertices;
	for (int i = 0;  i < total_vertices; i++)
	{
		// add the vertexes. next pointers are already initialized.
		int hashed_value = hash_function(vertices[i]);
		if (hashed_value == -1)
		{
			free(new_graph_map);
			free(new_graph);
			fprintf(stderr, "Invalid vertice.\n");
			exit(2);
		}
		new_graph_map[hashed_value].value = vertices[i];
	}
	return new_graph;
}

int hash_function(char value)
{
	if (value >= 'A' && value <= 'Z')
	{
		// 'A' to 'Z' mapped to [0, 25]
		return value - 'A';
	}
	else if (value >= 'a' && value <= 'z')
	{
		return value - 'a' + 26;
	}
	return -1;
}

node* create_node(char value)
{
	node *new_node = malloc(sizeof(node));
	if (new_node == NULL)
	{
		return NULL;
	}
	new_node->next = NULL;
	new_node->value = value;
	return new_node;
}

void add_edge(graph *graph, char source, char destination)
{
	if (graph == NULL)
	{
		fprintf(stderr, "Given graph doesn't exits.\n");
		exit(2);
	}
	else if (source == destination)
	{
		free_graph(graph);
		fprintf(stderr, "Can't make an edge to itself.\n");
		exit(2);
	}

	int source_hashed_value = hash_function(source);
	int dest_hashed_value = hash_function(destination);
	if (source_hashed_value == -1 || dest_hashed_value == -1)
	{
		free_graph(graph);
		fprintf(stderr, "Invalid vertices.\n");
		exit(2);
	}

	node *created_node = create_node(destination);
	if (created_node == NULL)
	{
		free_graph(graph);
		fprintf(stderr, "Not  enough memory for creating edge nodes.\n");
		exit(1);
	}

	// add the edge.
	created_node->next = graph->hash_table[source_hashed_value].next;
	graph->hash_table[source_hashed_value].next = created_node;

	// update the augmented degrees.
	graph->hash_table[source_hashed_value].out_degree++;
	graph->hash_table[dest_hashed_value].in_degree++;
}

void add_edges(graph *graph, char source, char values[], int length)
{
	for (int i = 0; i < length; i++)
	{
		add_edge(graph, source, values[i]);
	}
}

int vertex_in_degree(graph *graph, char vertex)
{
	if (graph == NULL)
	{
		fprintf(stderr, "Given graph doesn't exit.\n");
		exit(2);
	}
	int hashed_value = hash_function(vertex);
	if(hashed_value == -1)
	{
		free_graph(graph);
		fprintf(stderr, "Invalid vertex.\n");
		exit(2);
	}
	return graph->hash_table[hashed_value].in_degree;
}

int vertex_out_degree(graph *graph, char vertex)
{
	if (graph == NULL)
	{
		fprintf(stderr, "Given graph doesn't exit.\n");
		exit(2);
	}
	int hashed_value = hash_function(vertex);
	if(hashed_value == -1)
	{
		free_graph(graph);
		fprintf(stderr, "Invalid vertex.\n");
		exit(2);
	}
	return graph->hash_table[hashed_value].out_degree;
}

char* out_neighbors(graph *graph, char vertex)
{
	int hashed_value = hash_function(vertex);
	if(hashed_value == -1)
	{
		free_graph(graph);
		fprintf(stderr, "Invalid vertex.\n");
		exit(2);
	}
	int neighbors_count = graph->hash_table[hashed_value].out_degree;

	// allocate enough memory to return out neighbors.
	char *neighbors = malloc(sizeof(char) * neighbors_count);
	if (neighbors == NULL)
	{
		free_graph(graph);
		fprintf(stderr, "Not enough memory for creating neighbors array.\n");
		exit(1);
	}

	// copy the neighbors value
	int j = 0;
	node *finger = graph->hash_table[hashed_value].next;
	while(finger != NULL)
	{
		neighbors[j] = finger->value;
		finger = finger->next;
		j++;
	}

	// insanity check
	if (j != neighbors_count)
	{
		free_graph(graph);
		free(neighbors);
		fprintf(stderr, "Neighbors count and the number of real exiting neighbors are not the same.\n");
		exit(3);
	}

	return neighbors;
}

char* in_neighbors(graph *graph, char vertex)
{
	int hashed_value = hash_function(vertex);
	if(hashed_value == -1)
	{
		free_graph(graph);
		fprintf(stderr, "Invalid vertex.\n");
		exit(2);
	}
	int neighbors_count = graph->hash_table[hashed_value].in_degree;

	char *neighbors = malloc(sizeof(char) * neighbors_count);
	if (neighbors == NULL)
	{
		free_graph(graph);
		fprintf(stderr, "Not enough memory for creating neighbors array.\n");
		exit(1);
	}

	int j = 0;
	// loop all the vertixes other than hashed_value one.
	// made it like this so that we don't have overhead for one more comparison.
	for(int i = 0; i < hashed_value; i++)
	{
		if (graph->hash_table[i].out_degree > 0 && graph->hash_table[i].value != '\0')
		{
			node* finger = graph->hash_table[i].next;
			while(finger != NULL)
			{
				if (finger->value == vertex)
				{
					neighbors[j] = graph->hash_table[i].value;
					j++;
				}
				finger = finger->next;
			}
		}
	}
	for(int i = hashed_value + 1; i < MAX_CHAR; i++)
	{
		if (graph->hash_table[i].out_degree > 0 && graph->hash_table[i].value != '\0')
		{
			node* finger = graph->hash_table[i].next;
			while(finger != NULL)
			{
				if (finger->value == vertex)
				{
					neighbors[j] = graph->hash_table[i].value;
					j++;
				}
				finger = finger->next;
			}
		}
	}

	// insanity check
	if(j != neighbors_count)
	{
		free_graph(graph);
		free(neighbors);
		fprintf(stderr, "Neighbors count and the number of real exiting neighbors are not the same.\n");
		exit(3);
	}
	return neighbors;
}

void print_adjancency_list(graph *graph)
{
	for(int i = 0; i < MAX_CHAR; i++)
	{
		if(graph->hash_table[i].value != '\0')
		{
			printf("Adjacency list of vertex %c\n", graph->hash_table[i].value);
			node *finger = graph->hash_table[i].next;
			while(finger != NULL)
			{
				printf("%c -> ", finger->value);
				finger = finger->next;
			}
			printf("\n");
		}
	}
}

void free_graph(graph *graph)
{
	if (graph == NULL)
	{
		fprintf(stderr, "Given graph is NULL.\n");
		exit(1);
	}

	// free the nodes.
	for(int i = 0; i < MAX_CHAR; i++)
	{
		node *finger = graph->hash_table[i].next;
		while(finger != NULL)
		{
			node* temp = finger->next;
			free(finger);
			finger = temp;
		}
	}
	// free the hash table array
	free(graph->hash_table);
	// free the graph struct
	free(graph);
}

void print_hr()
{
	for(int i = 0; i < 10; i++)
	{
		printf("--------");
	}
	printf("\n");
}
