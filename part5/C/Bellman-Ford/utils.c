#include "utils.h"

shortest_distances* Bellman_Ford(graph *graph, char source, char parents[])
{
	if(graph == NULL)
	{
		return NULL;
	}
	int source_hash = hash_function(source);
	if(source_hash == -1)
	{
		return NULL;
	}

	shortest_distances *distances = calloc(1, sizeof(shortest_distances));
	if(distances == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating shortest_distances struct.\n");
		exit(1);
	}
	distances->data = calloc(MAX_CHAR, sizeof(distance_node));
	if(distances->data == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating shortest_distances data array.\n");
		exit(1);
	}

	// initialize everything to +infinity
	// -infinity is for negative weight cycles and in DAG there's no negative weight cycles.
	for (int i = 0; i < MAX_CHAR; i++)
	{
		distances->data[i].shortest_distance = INFINITY;
	}

	// already initialized no parent as '\0' using calloc.
	// indecies of distances->data are the destination vertices of the source.
	// will use hash_function from the graph.

	// initialize the source.
	distances->data[source_hash].parent_vertex = source;
	distances->data[source_hash].shortest_distance = 0;
	distances->source = source;

	// number of vertices
	distances->size = graph->total_vertices;

	// relax all edges in (V - 1) rounds
	for(int i = 0; i < distances->size - 1; i++)
	{
		// for every vertices
		for(int j = 0; j < MAX_CHAR; j++)
		{
			if(graph->hash_table[j].value != '\0')
			{
				// for every outgoing edges.
				for(node* adj_node = graph->hash_table[j].next; adj_node != NULL; adj_node = adj_node->next)
				{
					// relax that vertex and it's adjacency
					bool relaxed = try_to_relax(graph, distances, graph->hash_table[j].value, adj_node->value);
					if(relaxed == true)
					{
						parents[hash_function(adj_node->value)] = graph->hash_table[j].value;
					}
				}
			}
		}
	}

	// relax edges in (Vth) round to detect negative weight cycles for every vertices
	for(int i = 0; i < MAX_CHAR; i++)
	{
		if(graph->hash_table[i].value != '\0')
		{
			for(node* adj_node = graph->hash_table[i].next; adj_node != NULL; adj_node = adj_node->next)
			{
				int source_hash = hash_function(graph->hash_table[i].value);
				int destination_hash = hash_function(adj_node->value);
				double edge_weight = find_weight(graph, graph->hash_table[i].value, adj_node->value);
				if(distances->data[destination_hash].shortest_distance > (distances->data[source_hash].shortest_distance + edge_weight))
				{
					fprintf(stderr, "ERROR: the graph contains a negative weight cycle.!");
					exit(2);
				}
			}
		}
	}
	return distances;
}

shortest_distances* Bellman_Ford_modified(graph* graph, char source, char parents_modified[])
{
	/*
	 *	VALID PARAMETER ERROR CHECKING
	 */
	if(graph == NULL || parents_modified == NULL)
	{
		return NULL;
	}
	int source_hash = hash_function(source);
	if(source_hash == -1)
	{
		return NULL;
	}

	/*
	 *	PREPARING FOR RETURN VALUES.
	 */
	shortest_distances *distances = calloc(1, sizeof(shortest_distances));
	if(distances == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for preparing the returning values.\n");
		exit(1);
	}
	distances->data = calloc(MAX_CHAR, sizeof(distance_node));
	if(distances->data == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for preparing the returning values.\n");
		exit(1);
	}
	distances->source = source;

	/*
	 *	DUPLICATING THE GRAPH.
	 */
	int new_graph_size = graph->total_vertices;

	// will start operates from the heads.
	dup_graph_head *heads = malloc(sizeof(dup_graph_head) * MAX_CHAR);
	if(heads == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating graph heads.\n");
		exit(1);
	}
	for(int i = 0; i < MAX_CHAR; i++)
	{
		heads[i].dup_vertices = NULL;
	}

	// to track the vertices so that loop faster.
	char *vertices = malloc(sizeof(char) * MAX_CHAR);
	if(vertices == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for tracking vertices.\n");
		exit(1);
	}
	int vertices_size = 0;

	// copy the out_degree from the original graph and make space for adj+ list.
	for(int i = 0; i < MAX_CHAR; i++)
	{
		if(graph->hash_table[i].value != '\0')
		{
			// heads is the same as hash_table so we can reuse the 'i'.
			heads[i].out_degree = graph->hash_table[i].out_degree;

			// space for duplicated vertices. |V| + 1 number of vertices.
			heads[i].dup_vertices = malloc(sizeof(dup_graph_level_vertice) * (new_graph_size + 1));
			if(heads[i].dup_vertices == NULL)
			{
				fprintf(stderr, "ERROR: not enough memory for duplicated vertices.\n");
				exit(1);
			}

			dup_graph_level_vertice *level_vertex;
			// space for adj+ list pointers for all duplicated vertices but not the last one while also adding vertex.
			// additional space + 1 for self points zero weight edge.
			for(int j = 0; j < new_graph_size; j++)
		    {
				level_vertex = &heads[i].dup_vertices[j];	// have to be first.
				// reduce pointer jumping by creating new variable. outdegree + 1 for self zero edge weight.
				level_vertex->adj_out_vertex = malloc(sizeof(dup_adj_node) * (heads[i].out_degree + 1));
				if(level_vertex->adj_out_vertex == NULL)
				{
					fprintf(stderr, "ERROR: not enough memory for storing adj list for duplicated vertices.\n");
					exit(1);
				}
				level_vertex->vertex = graph->hash_table[i].value;
				level_vertex->level = j;
			}
			// add vertex && pointer for the last duplicated vertex.
			level_vertex = &heads[i].dup_vertices[new_graph_size];	// have to be first. becareful of indexing.
			level_vertex->adj_out_vertex = NULL;
			level_vertex->vertex = graph->hash_table[i].value;
			level_vertex->level = new_graph_size;	// becareful level.

			// know which vertices.
			vertices[vertices_size] = graph->hash_table[i].value;
			vertices_size++;
		}
	}

	// for every vertices.
	for(int i = 0; i < vertices_size; i++)
	{
		// no need to check error since we are using from the original graph.
		int vertex_hash = hash_function(vertices[i]);

		// for every duplicated vertices. |V| level.
		for(int j = 0; j < new_graph_size; j++)
		{
			// pointer to another level self with zero weight edge. vertices are alrady added.
			dup_adj_node* adj_node = &heads[vertex_hash].dup_vertices[j].adj_out_vertex[0];
			adj_node->vertex_out_neighbor = &heads[vertex_hash].dup_vertices[j + 1];
			adj_node->weight = 0;

			// copy the adj list and point to different level for every duplicated vertices but not the last one
			int k = 1;	// kth outgoing vertices
			for(node* finger = graph->hash_table[vertex_hash].next; finger != NULL; finger = finger->next, k++) 
			{
				int finger_hash = hash_function(finger->value);
				adj_node = &heads[vertex_hash].dup_vertices[j].adj_out_vertex[k];
				adj_node->vertex_out_neighbor = &heads[finger_hash].dup_vertices[j + 1];
				adj_node->weight = finger->weight;
			}
		}
	}
	// UNCOMMENT to print the duplicated graph.
	// print_dup_graph(heads, new_graph_size);

	/*
	 *	CALCULATING SHORTEST PATHS FROM THE DUPLICATED GRAPH. RUNNING DAG RELAXATION ON DUP GRAPH.
	 */

	// make the two dimensional array to track distances and parents. column is number of levels, row is the vertices.
	double distances_k[MAX_CHAR + 1][MAX_CHAR];
	char parents_matrix[MAX_CHAR + 1][MAX_CHAR];
	for(int i = 0; i < MAX_CHAR + 1; i++)	// have to initialize since this is being depend on conditional.
	{
		for(int j = 0; j < MAX_CHAR; j++)
		{
			parents_matrix[i][j] = '\0';
		}
	}

	// find topological order to run DAG_Relaxation
	topological_order *order = calloc(1, sizeof(topological_order));
	if (order == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for initializing topological order.\n");
		exit(1);
	}
	char *parents = calloc(MAX_CHAR, sizeof(char));
	if(parents == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating parents array for final dfs.\n");
		exit(1);
	}

	// initialize everything to +infinity
	// for every level
	for(int i = 0; i < new_graph_size + 1; i++)
	{
		// for every duplicated vertices.
		for(int j = 0; j < vertices_size; j++)
		{
			distances_k[i][hash_function(vertices[j])] = INFINITY;
		}
	}

	dup_graph_dfs_recursion(heads, source, 0, parents_matrix, order, false); // order is now storing topological order.
	// UNCOMMENT to print the topological order.
	//print_topo_order(order);

	// initialize the source.
	distances_k[0][source_hash] = 0;
	parents_matrix[0][source_hash] = source;
	
	// every vertices in topo sort.
	for(topological_node *topo_source = order->tail; topo_source != NULL; topo_source = topo_source->prev)
	{
		int topo_source_hash = hash_function(topo_source->value);
		dup_adj_node* neighbors = heads[topo_source_hash].dup_vertices[topo_source->level].adj_out_vertex;
		if(neighbors != NULL)
		{
			// for every outgoing edges in adjacency list.
			for(int i = 0; i < heads[topo_source_hash].out_degree + 1; i++)
			{
				int adj_topo_out_hash = hash_function(neighbors[i].vertex_out_neighbor->vertex);
				if (distances_k[topo_source->level + 1][adj_topo_out_hash] > distances_k[topo_source->level][topo_source_hash] + neighbors[i].weight)
				{
					// relax the edge
					distances_k[topo_source->level + 1][adj_topo_out_hash] = distances_k[topo_source->level][topo_source_hash] + neighbors[i].weight;
					parents_matrix[topo_source->level + 1][adj_topo_out_hash] = topo_source->value;
					// track the parent in the way
					parents_modified[adj_topo_out_hash] = topo_source->value;
				}
			}
		}
	} // distances_k has all the shortest paths now. parent_matrix has all the parents now.
	free_topo_queue(order);
	free_dup_graph(heads, vertices, vertices_size);
	
	/*
	 *	SET SHORTEST PATH DISTANCES FOR EVERY VERTICES FOR USING |V| - 1 edges.
	 */
	for(int i = 0; i < vertices_size; i++)
	{
		int vertex_hash = hash_function(vertices[i]);
		distances->data[vertex_hash].shortest_distance = distances_k[vertices_size - 1][vertex_hash];
		distances->data[vertex_hash].parent_vertex = parents_matrix[vertices_size - 1][vertex_hash];
	}

	/*
	 *	MAKE ALL THE VERTICES THAT ARE REACHABLE FROM EVERY WITNESS AS NEGATIVE INFINITY.
	 */
	for(int i = 0; i < vertices_size; i++)
	{
		int vertex_hash = hash_function(vertices[i]);
		if(distances_k[vertices_size][vertex_hash] < distances_k[vertices_size - 1][vertex_hash])
		{
			queue_list *visited = dfs(graph, vertices[i], parents);	// don't mess with the parents with the org parents.
			// for every vertices that is reachable from a witness
			for(queue_node *finger = visited->head; finger != NULL; finger = finger->next)
			{
				distances->data[hash_function(finger->value)].shortest_distance = -INFINITY;
				parents_modified[hash_function(finger->value)] = '\0';
			}
			free_queue_list(visited);
		}
	}
	free(parents);
	free(vertices);
	return distances;
}

void dup_graph_dfs_recursion(dup_graph_head *heads, char source, int source_level, char parent[MAX_CHAR + 1][MAX_CHAR], topological_order* order, bool empty_parent)
{
	// check if this is the first recursive stack
	if(empty_parent == false)
	{
		parent[source_level][hash_function(source)] = source;
	}

	int source_hash = hash_function(source);
	// only explore if there are things to explore.
	if(heads[source_hash].dup_vertices[source_level].adj_out_vertex != NULL)
	{
		// for every outgoing edges.
		for(int i = 0; i < heads[source_hash].out_degree + 1; i++)
		{
			char neighbor_vertex = heads[source_hash].dup_vertices[source_level].adj_out_vertex[i].vertex_out_neighbor->vertex;
			int neighbor_level = heads[source_hash].dup_vertices[source_level].adj_out_vertex[i].vertex_out_neighbor->level;
			// printf("neighbor: %c %d\n", neighbor_vertex, neighbor_level);

			// if that vertex is not being vertices and neighbor has out going edges to explore.
			if(parent[neighbor_level][hash_function(neighbor_vertex)] == '\0')
			{
				parent[neighbor_level][hash_function(neighbor_vertex)] = source;
				dup_graph_dfs_recursion(heads, neighbor_vertex, neighbor_level,  parent, order, true);
			}
		}
	}
	if(topo_enqueue(order, source, source_level) == false)
	{
		fprintf(stderr, "ERROR: not enough memory for creating topological nodes.\n");
		exit(1);
	}
	return;
}

topological_order* init_topo_queue(void)
{
	topological_order* new_queue = calloc(1, sizeof(queue_list));
	if(new_queue == NULL)
	{
		fprintf(stderr, "Not enough memory for creating linked list queue.\n");
		exit(1);
	}
	return new_queue;
}

bool topo_enqueue(topological_order *queue, char vertex, int level)
{
	// create new queue_node
	topological_node *new_node = calloc(1, sizeof(topological_node));
	if (new_node == NULL)
	{
		//free_queue_list(queue);
		//fprintf(stderr, "Not enough memory for creating queue node.\n");;
		return false;
	}
	new_node->value = vertex;
	new_node->level = level;
	
	// the queue_list is empty
	if (queue->tail == NULL)
	{
		queue->head = new_node;
		queue->tail = new_node;
	} 
	else
	{
		queue->tail->next = new_node;
		new_node->prev = queue->tail;
		queue->tail = new_node;
	}

	// update the size.
	queue->size++;
	return true;
}

void free_topo_queue(topological_order *queue)
{
	topological_node *finger = queue->head;
	while(finger != NULL)
	{
		topological_node *temp = finger->next;
		free(finger);
		finger = temp;
	}
	free(queue);
}

void print_topo_order(topological_order *queue)
{
	topological_node *finger = queue->tail;
	while(finger != NULL)
	{
		printf("%c(%d), ", finger->value, finger->level);
		finger = finger->prev;
	}
	printf("\n");
}

void print_dup_graph(dup_graph_head *heads, int org_count)
{
	// for every vertices.
	for(int i = 0; i < MAX_CHAR; i++)
	{
		if(heads[i].dup_vertices != NULL)
		{
			// for every duplicated vertices.
			int j = 0;
			for(; j < org_count; j++)
			{
				printf("level_vertices with level: %c (%d)\n",heads[i].dup_vertices[j].vertex, heads[i].dup_vertices[j].level);

				// for every outgoing neighbors
				for(int k = 0; k < heads[i].out_degree + 1; k++)
				{
					dup_graph_level_vertice *vertex = heads[i].dup_vertices[j].adj_out_vertex[k].vertex_out_neighbor;
					printf("out_neighbors: %c, level %d\t", vertex->vertex, vertex->level);
				}
				printf("\n");
			}
			printf("level_vertices with level: %c (%d)\n",heads[i].dup_vertices[j].vertex, heads[i].dup_vertices[j].level);
			print_hr();
		}
	}
}

void print_distances_matrix(double distances[MAX_CHAR + 1][MAX_CHAR], char vertices[], int length)
{
	// for every character
	for(int i = 0; i < length; i++)
	{
		// for every level
		for(int j = 0; j < length + 1; j++)
		{
			printf("vertex: %c, shortest distance: %f, level: %d\n", vertices[i], distances[j][hash_function(vertices[i])], j);
		}
	}
}

void print_parent_matrix(char parents[MAX_CHAR + 1][MAX_CHAR], char vertices[], int length)
{
	// for every character
	for(int i = 0; i < length; i++)
	{
		// for every level
		for(int j = 0; j < length + 1; j++)
		{
			printf("vertex: %c, parent_vertex: %c, level: %d\n", vertices[i], parents[j][hash_function(vertices[i])], j);
		}
	}
}

void free_dup_graph(dup_graph_head *heads, char vertices[], int length)
{
	// for every vertices
	for(int i = 0; i < length; i++)
	{
		// for every level(just to the one before the last)
		for(int j = 0; j < length; j++)
		{
			// free adj lists.
			free(heads[hash_function(vertices[i])].dup_vertices[j].adj_out_vertex);
		}
		// free level dup vertices array
		free(heads[hash_function(vertices[i])].dup_vertices);
	}
	free(heads);
}
