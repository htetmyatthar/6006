#include "utils.h"

shortest_distances* Dijkstra(graph *graph, char source, char parent[])
{
	if(graph == NULL || parent == NULL)
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
	for(int i = 0; i < MAX_CHAR; i++)
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

	// build changable priority queue with (v, d(s, v)) for each v in V
	changable_PQ_array *queue = changable_PQ_array_build(graph, distances);

	// While Q is not empty, delete item(u, d(s, u)) from Q that is minimum.
	while(queue->size != 0)
	{
		char vertex = changable_PQ_array_delete_min(queue);
		// for every vertex in adj+ of vertex
		for(node* finger = graph->hash_table[hash_function(vertex)].next; finger != NULL; finger = finger->next)
		{
			double edge_weight = find_weight(graph, vertex, finger->value);
			
			// relax and decrease key
			bool relaxed = try_to_relax(graph, distances, vertex, finger->value);
			if(relaxed == true)
			{
				parent[hash_function(finger->value)] = vertex;
			}
			changable_PQ_array_decrease_key(queue, finger->value, edge_weight);
		}
	}
	free_PQ_array(queue);
	return distances;
}

changable_PQ_array* changable_PQ_array_build(graph *graph, shortest_distances *distances)
{
	changable_PQ_array* new_queue = malloc(sizeof(changable_PQ_array) * 1);
	if(new_queue == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating chanagable priority queue\n");
		exit(1);
	}
	new_queue->queue_vertix = malloc(sizeof(queue_node) * graph->total_vertices);
	if(new_queue->queue_vertix == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating queue vertix array for priority queue.\n");
		exit(1);
	}
	new_queue->queue_map = calloc(MAX_CHAR, sizeof(queue_node*));
	if(new_queue->queue_vertix == NULL)
	{
		fprintf(stderr, "ERROR: not enough memory for creating queue vertix array for priority queue.\n");
		exit(1);
	}

	// all item in queue_map will be NULL first since I make it with NULL.
	// iterate through all the vertices inside the graph.
	for(int i = 0, j = 0; i < MAX_CHAR; i++)
	{
		if(graph->hash_table[i].value != '\0')
		{
			new_queue->queue_vertix[j].vertix = graph->hash_table[i].value;
			new_queue->queue_vertix[j].distance_estimate = (*distances).data[i].shortest_distance;
			new_queue->queue_map[i] = &new_queue->queue_vertix[j];
			j++;
		}
	}
	new_queue->size = graph->total_vertices;
	return new_queue;
}

char changable_PQ_array_delete_min(changable_PQ_array *queue)
{
	double smallest = queue->queue_vertix->distance_estimate;
	int j = 0;
	char vertex = '\0';
	// find the smallest index
	for(int i = 0; i < queue->size; i++)
	{
		if(queue->queue_vertix[i].distance_estimate < smallest)
		{
			vertex = queue->queue_vertix[i].vertix;
			j = i;
		}
	}

	// swap with last and decrease the size.
	// we don't care about the order, we can just swap and delete
	
	// swap for vertix
	queue_node temp = queue->queue_vertix[j];
	queue->queue_vertix[j] = queue->queue_vertix[queue->size - 1];
	queue->queue_vertix[queue->size - 1] = temp;

	// delete from queue map
	if(vertex != '\0')
	{
		queue->queue_map[hash_function(vertex)] = NULL;
	}
	
	// decrease the size for delete effect.
	queue->size--;
	return temp.vertix;
}

void changable_PQ_array_decrease_key(changable_PQ_array *queue, char vertex, double distance)
{
	int vertex_hash = hash_function(vertex);
	if(queue->queue_map[vertex_hash] != NULL)
	{
		queue->queue_map[vertex_hash]->distance_estimate = distance;
	}
}

void free_PQ_array(changable_PQ_array *queue)
{
	free(queue->queue_map);
	free(queue->queue_vertix);
	free(queue);
}
