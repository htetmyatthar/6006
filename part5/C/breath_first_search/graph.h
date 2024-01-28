#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 52

/*Node type of the graph hashtable.*/
typedef struct node 
{
	char value;         // value of the node.
	struct node *next; // pointer to the next node.
} node;

/* hash array node of the graph hash map.*/
typedef struct
{
	char value;			// value of the hash table arrays's node.
	node *next;			// next pointer to the normal node.
	int out_degree;		// outdegree of the given value vertex
	int in_degree;		// indegree of the given value vertex

}hash_node;

/*Graph hash table*/
typedef struct graph 
{
	int total_vertices; // number of total vertices
	hash_node *hash_table;   // pointer to the hashtable.
} graph;

// create_node create a new node with the given value.
// return NULL if there's not enough memory for creating node.
node* create_node(char value);

// hash_function returns a hashed value for indexing in graph's hash map of vertices.
// return -1 if the given value is invalid for the graph hashmap.
// valid char [a-zA-Z]
int hash_function(char value);

// create_graph creates a new graph with the given vertices count using the concept of adjacency list.
// Note: allocated memory enough to support all the english alphabaticals,
// both lower and upper case. Meaning a hash map of size 52 is created.
// Assumming all the vertices would not have any conflict.
// valid char[a-zA-Z]
// Returns the newly created graph.
// exit code (1) whether there's not enough memory for hashmap array or the graph.
// exit code (2) if a given vertice is invalid.
graph* create_graph(char vertices[], int total_vertices);

// add_edge adds a new edge to the given graph with the given source and destination.
// exit code (1) if there's not enough memory for creating node.
// exit code (2) if the given graph is NULL or the source and the desitination is the same.
// Caution: Although in the lesson we would want to consider the graphs as simple,
// meaning we don't care for the duplicates destination from one source.
// add_edge function will add many edges as you ask.
void add_edge(graph *graph, char source, char destination);

// add_edges adds new edges with the given graph with the source and the given destination values.
void add_edges(graph *graph, char source, char values[], int length);

// vertex_in_degree returns the number of incoming edges of the given vertex in the given graph.
// exit code (2) if the given graph is NULL or the given vertex is invalid.
int vertex_in_degree(graph *graph, char vertex);

// vertex_out_degree returns the number of outgoing edges of the given vertex in the given graph.
// exit code (2) if the given graph is NULL or the given vertex is invalid.
int vertex_out_degree(graph *graph, char vertex);

// in_neighbors returns an array of vertexes that the edges are to the given vertex from the them. 
// exit code (1) if there's not enough memory for creating neighbors array.
// exit code (2) if the given vertex is invalid.
// exit code (3) if the neighbors count is not the same as in degrees of the given vertex.
char* in_neighbors(graph *graph, char vertex);

// out_neighbors returns an array of vertexes that the edges are from the given vertex to the them. 
// exit code (1) if there's not enough memory for creating neighbors array.
// exit code (2) if the given vertex is invalid.
// exit code (3) if the neighbors count is not the same as out degrees of the given vertex.
char* out_neighbors(graph *graph, char vertex);

// print_adjacency_list prints out the adjacency list of the given graph.
void print_adjancency_list(graph *graph);

// free_graph frees the entire graph of the given graph.
void free_graph(graph *graph);

// print_hr prints a visual line.
void print_hr();
