#include "utils.h"

void adding_edges(graph* graph_adj);

void adding_edges_modified(graph* graph_adj);

void print_shortest_paths(shortest_distances *distances);

void print_parents(char parents[]);

int main(void)
{
	printf("Creating a graph.\n");
	char vertices[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 's'};
	int length = sizeof(vertices) / sizeof(vertices[0]);
	graph* Graph = create_graph(vertices, length);
	print_adjancency_list(Graph);
	print_hr();

	printf("Adding edges to form a graph.\n");
	adding_edges(Graph);
	print_adjancency_list(Graph);
	print_hr();

	printf("Testing with a graph that does not contain negative weight cycles: \n");
	char *parent_pointers = calloc(MAX_CHAR, sizeof(char));
	if(parent_pointers == NULL)
	{
		free_graph(Graph);
		fprintf(stderr, "ERROR: not enough memory for creating new parent pointers.\n");
		exit(1);
	}
	shortest_distances *distances = Bellman_Ford(Graph, 's', parent_pointers);
	if(distances != NULL)
	{
		print_shortest_paths(distances);
	}
	print_hr();

	printf("Parent pointers from source 's'.\n");
	print_parents(parent_pointers);

	free_shortest_distances(distances);
	free_graph(Graph);
	print_hr();

	print_hr();
	printf("Creating a graph that contains negative weight cycles: \n");
	char vertices_modified[] = {'a', 'b', 'c', 'd'};
	//char vertices_modified[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	int length_modified = sizeof(vertices_modified) / sizeof(vertices_modified[0]);
	graph* Graph_modified = create_graph(vertices_modified, length_modified);
	print_adjancency_list(Graph_modified);
	print_hr();

	printf("Testing with a graph that does contain negative weight cycles: \n");
	// refresh the parent pointers.
	for(int i = 0; i < MAX_CHAR; i++)
	{
		parent_pointers[i] = '\0';
	}

	printf("Adding edges to form a graph.\n");
	adding_edges_modified(Graph_modified);
	print_adjancency_list(Graph_modified);
	print_hr();

	printf("Finding negative weight cycles in the given graph with source 'a'.\n");
	shortest_distances *mod_deltas = Bellman_Ford_modified(Graph_modified, 'a', parent_pointers);
	if(mod_deltas != NULL)
	{
		print_shortest_paths(mod_deltas);
	}
	print_hr();
	
	printf("Parent pointers from source 'a'.\n");
	print_parents(parent_pointers);

	free_shortest_distances(mod_deltas);
	free_graph(Graph_modified);
	
	// refresh the parent pointers.
	for(int i = 0; i < MAX_CHAR; i++)
	{
		parent_pointers[i] = '\0';
	}
	free(parent_pointers);
	return 0;
}

void adding_edges_modified(graph* graph_adj)
{
	add_edge(graph_adj, 'a', 'b', -5);
	add_edge(graph_adj, 'a', 'c', 6);
	add_edge(graph_adj, 'b', 'c', -4);
	add_edge(graph_adj, 'c', 'd', 3);
	add_edge(graph_adj, 'd', 'b', -1);
	
	// add_edge(graph_adj, 'a', 'b', -5);
	// add_edge(graph_adj, 'a', 'e', 7);
	// add_edge(graph_adj, 'c', 'b', -1);
	// add_edge(graph_adj, 'b', 'f', -4);
	// add_edge(graph_adj, 'b', 'e', 6);
	// add_edge(graph_adj, 'd', 'c', 5);
	// add_edge(graph_adj, 'e', 'f', 3);
	// add_edge(graph_adj, 'f', 'c', 8);
	// add_edge(graph_adj, 'f', 'g', 2);
	// add_edge(graph_adj, 'g', 'c', 1);
	// add_edge(graph_adj, 'g', 'h', -2);
	// add_edge(graph_adj, 'h', 'c', 9);
	// add_edge(graph_adj, 'h', 'd', 4);
}

void adding_edges(graph* graph_adj)
{
	add_edge(graph_adj, 's', 'e', 5);
	add_edge(graph_adj, 's', 'f', 1);
	add_edge(graph_adj, 's', 'g', 3);
	add_edge(graph_adj, 'e', 'f', -1);
	add_edge(graph_adj, 'e', 'a', 5);
	add_edge(graph_adj, 'e', 'g', 3);
	add_edge(graph_adj, 'f', 'e', 2);
	add_edge(graph_adj, 'f', 'g', 8);
	add_edge(graph_adj, 'g', 'b', 7);
	add_edge(graph_adj, 'a', 'b', 1);
	add_edge(graph_adj, 'b', 'c', -2);
	add_edge(graph_adj, 'b', 'e', -5);
	add_edge(graph_adj, 'c', 'd', 5);
	add_edge(graph_adj, 'd', 'b', 3);
}

// print_shortest_paths prints out the values of the shortest paths to the vertices.
void print_shortest_paths(shortest_distances *distances)
{
	for(int i = 0; i < MAX_CHAR / 2; i++)
	{
		if(distances->data[i].parent_vertex != '\0' && distances->data[i].shortest_distance != INFINITY)
		{
			printf("(distance: %.3f, destination: %c)\n", distances->data[i].shortest_distance, i + 65);
		}
	}
	for(int i = MAX_CHAR / 2; i < MAX_CHAR; i++)
	{
		if(distances->data[i].parent_vertex != '\0' && distances->data[i].shortest_distance != INFINITY)
		{
			printf("(distance: %.3f, destination: %c)\n", distances->data[i].shortest_distance, i + 71);
		}
	}
}

void print_parents(char parents[])
{
	for(int i = 0; i < MAX_CHAR / 2;i++)
	{
		if(parents[i] != '\0')
		{
			 printf("(vertex: %c -> parent: %c)\n", i + 65, parents[i]);
		}
	}

	for(int i = MAX_CHAR / 2; i < MAX_CHAR; i++)
	{
		if(parents[i] != '\0')
		{
			 printf("(vertex: %c -> parent: %c)\n", i + 71, parents[i]);
		}
	}
}
