#include "utils.h"

void adding_edges(graph* graph_adj);

// used when testing for creating duplicated graph.
//void adding_edges_more(graph* graph_adj);

void print_roots(char array[], int length);

void print_shortest_paths(shortest_distances *distances);

int main(void)
{
	printf("Creating a DAG.\n");
	char vertices[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	/*
	*	used when testing for creating duplicated graph.
	*	char vertices[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
	*/
	int length = sizeof(vertices) / sizeof(vertices[0]);
	graph* Graph = create_graph(vertices, length);
	print_adjancency_list(Graph);
	print_hr();

	printf("Adding edges to form a graph.\n");
	//adding_edges(Graph);
	adding_edges(Graph);
	print_adjancency_list(Graph);
	print_hr();

	printf("Printing the gotten parent pointers, using full dfs.\nBelow is reversed topological order.\n");
	char* parent_new_array = calloc(MAX_CHAR, sizeof(char));
	if (parent_new_array == NULL)
	{
		free_graph(Graph);
		exit(1);
	}
	// from tail to head is the topological sort order
	queue_list *order = full_dfs(Graph, parent_new_array);
	printf("Result: ");
	print_queue_list(order);
	printf("Root nodes: \n");
	print_roots(parent_new_array, MAX_CHAR);
	print_hr();

	/*
	* used when testing for creating duplicated graph.
	* printf("Shortest paths from source 'a': \n");
	*/
	printf("Shortest paths from source 'a': \n");
	shortest_distances *e_shortest_paths = DAG_relaxation(Graph, 'a');
	printf("Number of vertices that can reach from source: %i\n", e_shortest_paths->size);
	print_shortest_paths(e_shortest_paths);
	print_hr();

	free_shortest_distances(e_shortest_paths);
	free_queue_list(order);
	free(parent_new_array);
	free_graph(Graph);
}

void adding_edges(graph* graph_adj)
{
	add_edge(graph_adj, 'a', 'b', -5);
	add_edge(graph_adj, 'a', 'e', 7);
	add_edge(graph_adj, 'b', 'c', -1);
	add_edge(graph_adj, 'b', 'f', -4);
	add_edge(graph_adj, 'b', 'e', 6);
	add_edge(graph_adj, 'd', 'c', 5);
	add_edge(graph_adj, 'e', 'f', 3);
	add_edge(graph_adj, 'f', 'c', 8);
	add_edge(graph_adj, 'f', 'g', 2);
	add_edge(graph_adj, 'g', 'c', 1);
	add_edge(graph_adj, 'g', 'h', -2);
	add_edge(graph_adj, 'h', 'c', 9);
	add_edge(graph_adj, 'h', 'd', 4);
}

// used for when creating duplicated graph in Bellman-Ford-Modified
void adding_edges_more(graph* graph_adj)
{
	add_edge(graph_adj, 'a', 'b', 0);
	add_edge(graph_adj, 'b', 'c', 0);
	add_edge(graph_adj, 'c', 'd', 0);
	add_edge(graph_adj, 'd', 'e', 0);

	add_edge(graph_adj, 'a', 'f', -5);
	add_edge(graph_adj, 'b', 'g', -5);
	add_edge(graph_adj, 'c', 'h', -5);
	add_edge(graph_adj, 'd', 'i', -5);

	add_edge(graph_adj, 'a', 'j', 6);
	add_edge(graph_adj, 'b', 'k', 6);
	add_edge(graph_adj, 'c', 'l', 6);
	add_edge(graph_adj, 'd', 'm', 6);

	add_edge(graph_adj, 'j', 'n', 3);
	add_edge(graph_adj, 'k', 'o', 3);
	add_edge(graph_adj, 'l', 'p', 3);

	add_edge(graph_adj, 'f', 'k', -4);
	add_edge(graph_adj, 'g', 'l', -4);
	add_edge(graph_adj, 'h', 'm', -4);

	add_edge(graph_adj, 'n', 'h', -1);
	add_edge(graph_adj, 'o', 'i', -1);
}

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

// print_roots prints out the root vertex looking up the parent array
// which can get by using full dfs.
// roots nodes are the nodes that has the same parent as the vertex.
void print_roots(char array[], int length)
{
	// divided for plusing.
	for(int i = 0; i < length / 2; i++)
	{
		if (array[i] != '\0' && array[i] == i + 65)
		{
			printf("\troot vertex: %c\n", array[i]);
		}
	}
	for(int i = length / 2; i < length; i++)
	{
		if (array[i] != '\0' && array[i] == i + 71)
		{
			printf("\troot vertex: %c\n", array[i]);
		}
	}
}
