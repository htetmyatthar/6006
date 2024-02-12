#include "utils.h"

void adding_edges(graph* graph_adj);

void print_parents(char parents[]);

void print_shortest_paths(shortest_distances *distances);

int main(void)
{
	printf("Creating a graph.\n");
	char vertices[] = {'a', 'b', 'c', 'd', 's'};
	int length = sizeof(vertices) / sizeof(vertices[0]);
	graph* Graph = create_graph(vertices, length);
	print_adjancency_list(Graph);
	print_hr();

	printf("Adding edges to form a graph with no negative weight edges.\n");
	adding_edges(Graph);
	print_adjancency_list(Graph);
	print_hr();

	printf("Shortest paths\n");
	char *parent_pointers = calloc(MAX_CHAR, sizeof(char));
	shortest_distances *distances = Dijkstra(Graph, 's', parent_pointers);
	if(distances != NULL)
	{
		print_shortest_paths(distances);
	}
	print_hr();

	printf("Parent pointers from source 's'\n");
	print_parents(parent_pointers);
	print_hr();

	free_shortest_distances(distances);
	free_graph(Graph);
	free(parent_pointers);
}

void adding_edges(graph* graph_adj)
{
	add_edge(graph_adj, 's', 'a', 10);
	add_edge(graph_adj, 's', 'c', 3);
	add_edge(graph_adj, 'a', 'b', 2);
	add_edge(graph_adj, 'a', 'c', 1);
	add_edge(graph_adj, 'c', 'a', 4);
	add_edge(graph_adj, 'c', 'b', 8);
	add_edge(graph_adj, 'c', 'd', 2);
	add_edge(graph_adj, 'b', 'd', 7);
	add_edge(graph_adj, 'd', 'b', 5);
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
