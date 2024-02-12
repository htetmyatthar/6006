#include "DAG_relaxation.h"

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
  dup_graph_level_vertice
      *vertex_out_neighbor; // pointer to the out neighbor vertex.
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
  topological_node
      *head; // head of the topological order(last in topological sort)
  topological_node
      *tail; // tail of the topological order(first in topological sort)
} topological_order;

// Bellman_Ford returns the shortest paths if there's no negative weight cycles.
// Exit code(2) if the graph has negative cycles.
// Exit code(1) if there's not enough memory for shortest_distances or
// shortest_distances->data.
shortest_distances *Bellman_Ford(graph *graph, char source, char parents[]);

shortest_distances *Bellman_Ford_modified(graph *graph, char source, char parents[]);

void dup_graph_dfs_recursion(dup_graph_head *graph, char source,
                             int source_level,
                             char parent[MAX_CHAR + 1][MAX_CHAR],
                             topological_order *order, bool empty_parent);

topological_order *init_topo_queue(void);

bool topo_enqueue(topological_order *queue, char vertex, int level);

void free_topo_queue(topological_order *queue);

void print_topo_order(topological_order *queue);

void print_dup_graph(dup_graph_head *heads, int org_count);

void print_distances_matrix(double distances[MAX_CHAR + 1][MAX_CHAR], char vertices[], int length);

void print_parent_matrix(char parents[MAX_CHAR + 1][MAX_CHAR], char vertices[], int length);

void free_dup_graph(dup_graph_head heads[], char vertices[], int length);
