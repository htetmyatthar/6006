#include "utils.h"

void adding_edges(graph* graph_adj);

void print_parents(char array[], int length);

void find_paths(graph* graph);

int main(void)
{
	printf("HELLO, WORLD.\n");

	printf("Creating a graph.\n");
	char vertices[] = {'a', 'x', 'c', 'd', 'v', 'f', 's', 'z'};
	int length = sizeof(vertices) / sizeof(vertices[0]);
	graph* Graph = create_graph(vertices, length);
	print_adjancency_list(Graph);
	print_hr();

	printf("Adding edges.\n");
	adding_edges(Graph);
	print_adjancency_list(Graph);
	print_hr();

	printf("Printing the gotten parent pointers, using s as source.\n");
	char* path_parents = bfs(Graph, 's');
	print_parents(path_parents, MAX_CHAR);
	print_hr();

	printf("VISUALIZING THE CREATED GRAPH.\nz  <--> a <--> s <--> x <--> c <-->v\n                      \\       \\    /\n                       \\       \\   / \n                       d  <-->   f \n");

	find_paths(Graph);
	print_hr();

	free_graph(Graph);
	free(path_parents);
	return 0;
}

void find_paths(graph* graph)
{
	char from_to[][2] = {
		{'s', 'c'},
		{'s', 'f'},
		{'s', 'z'},
		{'v', 's'},
		{'z', 'f'}
	};
	int length = sizeof(from_to) / sizeof(from_to[0]);
	for (int i = 0; i < length; i++)
	{
		printf("One of the shortest path from %c to %c.\n", from_to[i][0], from_to[i][1]);
		queue_list *path = find_path(graph, from_to[i][0], from_to[i][1]);
		print_queue_list(path);
		free_queue_list(path);
	}
}

void print_parents(char array[], int length)
{
	for(int i = 0; i < length / 2; i++)
	{
		printf("vertex: %c, parent: %c -> \n", i+65, array[i]);
	}
	for(int i = length / 2; i < length; i++)
	{
		printf("vertex: %c, parent: %c -> \n", i+71, array[i]);
	}
}

void adding_edges(graph* graph_adj)
{
	char s_neighbors[] = { 'a' , 'x' };
	int length_s = sizeof(s_neighbors) / sizeof(s_neighbors[0]);
	add_edges(graph_adj, 's', s_neighbors, length_s);

	char a_neighbors[] = { 's' , 'z' };
	int length_a = sizeof(a_neighbors) / sizeof(a_neighbors[0]);
	add_edges(graph_adj, 'a', a_neighbors, length_a);

	char z_neighbors[] = { 'a' };
	int length_z = sizeof(z_neighbors) / sizeof(z_neighbors[0]);
	add_edges(graph_adj, 'z', z_neighbors, length_z);

	char x_neighbors[] = { 's' , 'd', 'c' };
	int length_x = sizeof(x_neighbors) / sizeof(x_neighbors[0]);
	add_edges(graph_adj, 'x', x_neighbors, length_x);

	char d_neighbors[] = { 'x' , 'f'};
	int length_d = sizeof(d_neighbors) / sizeof(d_neighbors[0]);
	add_edges(graph_adj, 'd', d_neighbors, length_d);

	char c_neighbors[] = { 'f' , 'x', 'v' };
	int length_c = sizeof(c_neighbors) / sizeof(c_neighbors[0]);
	add_edges(graph_adj, 'c', c_neighbors, length_c);

	char f_neighbors[] = { 'd' , 'c', 'v' };
	int length_f = sizeof(f_neighbors) / sizeof(f_neighbors[0]);
	add_edges(graph_adj, 'f', f_neighbors, length_f);

	char v_neighbors[] = { 'f' , 'c'};
	int length_v = sizeof(v_neighbors) / sizeof(v_neighbors[0]);
	add_edges(graph_adj, 'v', v_neighbors, length_v);
}
