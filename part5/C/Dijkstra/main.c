#include "utils.h"

void adding_edges(graph* graph_adj);

void adding_edges_more(graph *graph_adj);

void print_parents(char parents[]);

void print_shortest_paths(shortest_distances *distances);

int main(void)
{
	printf("Creating a graph.\n");
	//char vertices[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};
	char vertices[] = {'a', 'b', 'c', 'd', 's'};
	int length = sizeof(vertices) / sizeof(vertices[0]);
	graph* Graph = create_graph(vertices, length);
	print_adjancency_list(Graph);
	print_hr();

	printf("Adding edges to form a graph with no negative weight edges.\n");
	//adding_edges_more(Graph);
	adding_edges(Graph);
	print_adjancency_list(Graph);
	print_hr();

	printf("Shortest paths\n");
	char *parent_pointers = calloc(MAX_CHAR, sizeof(char));
	//shortest_distances *distances = Dijkstra(Graph, 'S', parent_pointers);
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

void adding_edges_more(graph *graph_adj)
{
	add_edges(graph_adj, 'A', (char[]){'B', 'C', 'D', 'E'}, (int[]){1, 2, 3, 4}, 4);
	add_edges(graph_adj, 'B', (char[]){'A', 'C', 'D', 'E', 'F'}, (int[]){1, 2, 3, 4, 5}, 5);
	add_edges(graph_adj, 'C', (char[]){'A', 'B', 'D', 'E', 'F'}, (int[]){2, 2, 3, 4, 5}, 5);
	add_edges(graph_adj, 'D', (char[]){'A', 'B', 'C', 'E', 'F'}, (int[]){3, 3, 3, 4, 5}, 5);
	add_edges(graph_adj, 'E', (char[]){'A', 'B', 'C', 'D', 'F', 'G'}, (int[]){4, 4, 4, 4, 5, 6}, 6);
	add_edges(graph_adj, 'F', (char[]){'B', 'C', 'D', 'E', 'G', 'H'}, (int[]){5, 5, 5, 5, 6, 7}, 6);
	add_edges(graph_adj, 'G', (char[]){'E', 'F', 'H', 'I'}, (int[]){6, 6, 7, 8}, 4);
	add_edges(graph_adj, 'H', (char[]){'F', 'G', 'I', 'J'}, (int[]){7, 7, 8, 9}, 4);
	add_edges(graph_adj, 'I', (char[]){'G', 'H', 'J', 'K'}, (int[]){8, 8, 9, 10}, 4);
	add_edges(graph_adj, 'J', (char[]){'H', 'I', 'K', 'L'}, (int[]){9, 9, 10, 11}, 4);
	add_edges(graph_adj, 'K', (char[]){'I', 'J', 'L', 'M'}, (int[]){10, 10, 11, 12}, 4);
	add_edges(graph_adj, 'L', (char[]){'J', 'K', 'M', 'N'}, (int[]){11, 11, 12, 13}, 4);
	add_edges(graph_adj, 'M', (char[]){'K', 'L', 'N', 'O'}, (int[]){12, 12, 13, 14}, 4);
	add_edges(graph_adj, 'N', (char[]){'L', 'M', 'O', 'P'}, (int[]){13, 13, 14, 15}, 4);
	add_edges(graph_adj, 'O', (char[]){'M', 'N', 'P', 'Q'}, (int[]){14, 14, 15, 16}, 4);
	add_edges(graph_adj, 'P', (char[]){'N', 'O', 'Q', 'R'}, (int[]){15, 15, 16, 17}, 4);
	add_edges(graph_adj, 'Q', (char[]){'O', 'P', 'R', 'S'}, (int[]){16, 16, 17, 18}, 4);
	add_edges(graph_adj, 'R', (char[]){'P', 'Q', 'S', 'T'}, (int[]){17, 17, 18, 19}, 4);
	add_edges(graph_adj, 'S', (char[]){'Q', 'R', 'T'}, (int[]){18, 18, 19}, 3);
	add_edges(graph_adj, 'T', (char[]){'R', 'S'}, (int[]){19, 19}, 2);
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
