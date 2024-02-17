#include "Dijkstra.h"

typedef struct dup_adj_node dup_adj_node;

// duplicated vertices from the original graph such that |V| + 1
typedef struct dup_graph_level_vertice {
  char vertex;                  // out going neighbor's vertex.
  int level;                    // the level of the current vertex. O(MAX_CHAR)
  dup_adj_node *adj_out_vertex; // pointer to array of adj list.
} dup_graph_level_vertice;

// dup_adj_node keeps the pointers acting as a edge, storing out going neighbor.
struct dup_adj_node {
  int weight; // edge weight of the out_neighbor.
  dup_graph_level_vertice *vertex_out_neighbor; // pointer to the out neighbor vertex.
};

// head that tracks the duplicated vertices and graph.
typedef struct {
  int out_degree; // out degree will be the same for every level of the graph.
  dup_graph_level_vertice *dup_vertices; // duplicated vertices array.
} dup_graph_head;

// topological queue node
typedef struct topological_node {
  char value;                    // vertex name value
  int level;                     // vertex level
  struct topological_node *next; // next vertex
  struct topological_node *prev; // previous vertex
} topological_node;

// topological order doubly linked list.
typedef struct {
  int size; // number of vertices in topological order
  topological_node *head; // head of the topological order(last in topological sort)
  topological_node *tail; // tail of the topological order(first in topological sort)
} topological_order;

// Bellman_Ford returns the shortest paths if there's no negative weight cycles.
// Returns NULL if the given graph or parents is NULL or the given source is invalid.
// Exit code(1) if there's not enough memory
// Exit code(2) if the graph has negative cycles.
shortest_distances *Bellman_Ford(graph *graph, char source, char parents[]);

// Bellman_Ford_modified returns the shortest paths and the negative weight cycles if there are any.
// Returns NULL if the given graph or parents is NULL or the given source is invalid.
// Exit code(1) if there's not enough memory.
shortest_distances *Bellman_Ford_modified(graph *graph, char source, char parents[]);

// dup_graph_dfs_recursion modify the given parent matrix and order for finding topological order
// inside the duplicated graph.
void dup_graph_dfs_recursion(dup_graph_head *graph, char source, int source_level, char parent[MAX_CHAR + 1][MAX_CHAR], topological_order *order, bool empty_parent);

// init_topo_queue initialize a minimal queue that keep tracks of levels for duplicated graphs.
// CAUTION: ONLY FOR DUPLICATED GRAPHS.
topological_order *init_topo_queue(void);

// topo_enququeu insert a topological_node with the given vertex and the level
// to the last place(tail) of the given topological_order.
// CAUTION: ONLY FOR DUPLICATED GRAPHS, Not checking valid vertex or not, since this will only be used for
// topological_order.
// Returns true if everything's okay
// Returns false if there's not enough memory for creating topological_node.
bool topo_enqueue(topological_order *queue, char vertex, int level);

// free_topo_queue frees memory of the given topological_order.
// CAUTION: ONLY FOR DUPLICATED GRAPHS.
topological_order *init_topo_queue(void);

// print_topo_order prints out the chars in the given topological_order.
// will print from tail to head.
// CAUTION: ONLY FOR DUPLICATED GRAPHS.
void print_topo_order(topological_order *queue);

// free_topo_queue will frees the memory that is allocated during the creation of given queue.
void free_topo_queue(topological_order *queue);

// print_dup_graph will prints out the given duplicated graph using the given original
// vertices count.
// CAUTION: ONLY FOR DUPLICATED GRAPHS DEBUGGING PURPOSES.
void print_dup_graph(dup_graph_head *heads, int org_count);

// print_distances_matrix will prints out the distances of the duplicated graph's vertices from predefined source
// using the given original vertices count and given original vertices.
// CAUTION: ONLY FOR DUPLICATED GRAPHS DEBUGGING PURPOSES.
void print_distances_matrix(double distances[MAX_CHAR + 1][MAX_CHAR], char vertices[], int length);

// print_parent_matrix will prints out the parent of the duplicated graph's vertices from predifined source
// using the given original vertices count and given original vertices.
// CAUTION: ONLY FOR DUPLICATED GRAPHS DEBUGGING PURPOSES.
void print_parent_matrix(char parents[MAX_CHAR + 1][MAX_CHAR], char vertices[], int length);

// free_dup_graph frees the memory that is allocated during the creation of the duplicated graph
// using the given original vertices count and given original vertices.
void free_dup_graph(dup_graph_head heads[], char vertices[], int length);
