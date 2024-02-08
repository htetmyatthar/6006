#include "utils.h"

void adding_edges(graph* graph_adj);

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
	free(parent_pointers);
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
