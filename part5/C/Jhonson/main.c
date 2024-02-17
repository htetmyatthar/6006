#include "utils.h"

void print_all(shortest_distances *distances);

void adding_edges(graph* graph_adj);

void print_shortest_paths(shortest_distances *distances);

void print_parents(char parents[]);

void print_super_adjcency(hash_node *super_node);

int main(void)
{
	printf("Creating a graph.\n");
	char vertices[] = {'a', 'b', 'c', 'x', 'y', 'z'};
	int length = sizeof(vertices) / sizeof(vertices[0]);
	graph* Graph = create_graph(vertices, length);
	print_adjancency_list(Graph);
	print_hr();

	printf("Adding edges to form a graph.\n");
	adding_edges(Graph);
	print_adjancency_list(Graph);
	print_hr();

	printf("Testing with a graph that does not contain negative weight cycles: \n");
	// running Jhonson
	shortest_distances_matrix *distances = Jhonson(Graph);
	if(distances != NULL)
	{
		//print_all(distances);
		for(int i = 0; i < length; i++)
		{
			printf("distances and parent pointers from source %c\n", distances->vertices[i]);
			print_shortest_paths(distances->distance_matrix[i]);
			print_parents(distances->parent_matrix[i]);
			print_hr();
		}
	}

	printf("Check the graph still has the original weights.\n");
	print_adjancency_list(Graph);
	print_hr();

	// freeing the memory.
	for(int i = 0; i < length; i++)
	{
		free(distances->distance_matrix[i]->data);
		free(distances->distance_matrix[i]);
		free(distances->parent_matrix[i]);
	}
	free(distances->distance_matrix);
	free(distances->parent_matrix);
	free(distances->vertices);
	free(distances);
	free_graph(Graph);
}

void adding_edges(graph* graph_adj)
{
	add_edge(graph_adj, 'a', 'b', -2);
	add_edge(graph_adj, 'b', 'c', -1);
	add_edge(graph_adj, 'c', 'a', 4);
	add_edge(graph_adj, 'c', 'x', 2);
	add_edge(graph_adj, 'c', 'y', -3);
	add_edge(graph_adj, 'z', 'x', 1);
	add_edge(graph_adj, 'z', 'y', -4);
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

void print_all(shortest_distances *distances)
{
	printf("this is all.\n");
	for(int i = 0; i < MAX_CHAR + 1; i++)
	{
		printf("(%f, %d)\n", distances->data[i].shortest_distance, distances->data[i].parent_vertex);
	}
	printf("\n");
}

void print_super_adjcency(hash_node *super_node)
{
	printf("Adjacency list of super_node %c\n", super_node->value);
	node *finger = super_node->next;
	while(finger != NULL)
	{
		printf("(%c %.1f)-> ", finger->value, finger->weight);
		finger = finger->next;
	}
	printf("\n");
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

