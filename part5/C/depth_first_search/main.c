#include "utils.h"

void print_parents(char array[], int length);

void print_roots(char array[], int length);

void adding_edges(graph* graph_adj);

int main(void)
{
	printf("Hello, world\n");

	printf("Creating a graph.\n");
	char vertices[] = {'a', 'b', 'd', 'e', 'c', 'f'};
	int length = sizeof(vertices) / sizeof(vertices[0]);
	graph* Graph = create_graph(vertices, length);
	print_adjancency_list(Graph);
	print_hr();
	
	printf("Adding edges.\n");
	adding_edges(Graph);
	print_adjancency_list(Graph);
	print_hr();

	printf("Visualizing the given graph.\n");
	printf("d <-- e <-- c --> f\n^\\    ^\n| \\   |\n|  \\  |\n|   \\ |\na --> b\n");

	printf("Printing the gotten parent pointers, using 'a' as source.\nExpected: a -> b -> e -> d ->\n");
	char* parent_array = calloc(MAX_CHAR, sizeof(char));
	if(parent_array == NULL)
	{
		free_graph(Graph);
		fprintf(stderr, "Not enough memory for creating parent array.\n");
		exit(1);
	}

	queue_list *order = dfs(Graph, 'a', parent_array);
	printf("Result: ");
	print_queue_list(order);
	print_hr();
	free_queue_list(order);

	printf("Parents(Root node has the same value for parent):\n");
	print_parents(parent_array, MAX_CHAR);
	print_hr();
	free(parent_array);

	printf("Printing the gotten parent pointers, using full dfs.\n");
	char* parent_new_array = calloc(MAX_CHAR, sizeof(char));
	if (parent_new_array == NULL)
	{
		free_graph(Graph);
		exit(1);
	}
	order = full_dfs(Graph, parent_new_array);
	printf("Result: ");
	print_queue_list(order);
	printf("Root nodes: \n");
	print_roots(parent_new_array, MAX_CHAR);
	print_hr();
	free_queue_list(order);

	printf("Parents(Root node has the same value for parent):\n");
	print_parents(parent_new_array, MAX_CHAR);
	print_hr();
	free(parent_new_array);

	free_graph(Graph);
}

void adding_edges(graph* graph_adj)
{
	char a_neighbors[] = {'d', 'b'};
	int length_a = sizeof(a_neighbors) /sizeof(a_neighbors[0]);
	add_edges(graph_adj, 'a', a_neighbors, length_a);

	char c_neighbors[] = {'e', 'f'};
	int length_c = sizeof(c_neighbors) /sizeof(c_neighbors[0]);
	add_edges(graph_adj, 'c', c_neighbors, length_c);

	add_edge(graph_adj, 'b', 'e');
	add_edge(graph_adj, 'd', 'b');
	add_edge(graph_adj, 'e', 'd');
}

void print_parents(char array[], int length)
{
	// divided for plusing.
	for(int i = 0; i < length / 2; i++)
	{
		if (array[i] != '\0')
		{
			printf("vertex: %c -> parent: %c\n", i+65, array[i]);
		}
	}
	for(int i = length / 2; i < length; i++)
	{
		if (array[i] != '\0')
		{
			printf("vertex: %c -> parent: %c\n", i+71, array[i]);
		}
	}
}

void print_roots(char array[], int length)
{
	// divided for plusing.
	for(int i = 0; i < length / 2; i++)
	{
		if (array[i] != '\0' && array[i] == i + 65)
		{
			printf("root vertex: %c\n", array[i]);
		}
	}
	for(int i = length / 2; i < length; i++)
	{
		if (array[i] != '\0' && array[i] == i + 71)
		{
			printf("root vertex: %c\n", array[i]);
		}
	}
}
