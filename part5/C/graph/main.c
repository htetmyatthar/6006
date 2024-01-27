#include "utils.h"

void print_char_array(char array[], int length);

int main(void)
{
	printf("Testing hash function\n");
	printf("1 -> %i, A-> %i, a-> %i, $ -> %i\n",hash_function('1'), hash_function('A'), hash_function('a'), hash_function('$'));
	print_hr();

	printf("Creating a new graph.\n");
	char vertices[] = {'a', 'b', 'c', 'd', 'E', 'F'};
	int length = sizeof(vertices) / sizeof(vertices[0]);
	graph* Graph = create_graph(vertices, length);
	print_adjancency_list(Graph);
	print_hr();

	printf("Adding edges one by one.\n");
	add_edge(Graph, 'a', 'c');
	add_edge(Graph, 'b', 'a');
	add_edge(Graph, 'E', 'd');
	add_edge(Graph, 'F', 'b');
	print_adjancency_list(Graph);
	print_hr();

	printf("Adding many edges in once.\n");
	char dest_vertices[] = {'d', 'E', 'F'};
	int length_dest = sizeof(dest_vertices) / sizeof(dest_vertices[0]);
	add_edges(Graph, 'c', dest_vertices, length_dest);
	print_adjancency_list(Graph);
	print_hr();

	printf("Checking in degrees.\n");
	for (int i = 0; i < length; i++)
	{
		printf("%c, %i\n", vertices[i], vertex_in_degree(Graph, vertices[i]));
	}
	printf("\n");

	printf("Checking out degrees.\n");
	for (int i = 0; i < length; i++)
	{
		printf("%c, %i\n", vertices[i], vertex_out_degree(Graph, vertices[i]));
	}
	print_hr();

	printf("Printing out going neighbors.\n");
	for(int i = 0; i < length; i++)
	{
		char *neighbors = out_neighbors(Graph, vertices[i]);
		printf("Neighbors of %c: ", vertices[i]);
		print_char_array(neighbors, vertex_out_degree(Graph, vertices[i]));
		free(neighbors);
	}

	printf("Printing in coming neighbors.\n");
	for(int i = 0; i < length; i++)
	{
		char *neighbors = in_neighbors(Graph, vertices[i]);
		printf("Neighbors of %c: ", vertices[i]);
		print_char_array(neighbors, vertex_in_degree(Graph, vertices[i]));
		free(neighbors);
	}
	print_hr();

	printf("Completed.....\n");
	print_hr();
	free_graph(Graph);
	return 0;
}

void print_char_array(char array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf(" %c ", array[i]);
	}
	printf("\n");
}

