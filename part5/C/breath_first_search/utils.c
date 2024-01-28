#include "utils.h"

queue_list* find_path(graph *graph, char source, char destination)
{
	if (graph == NULL || source == destination)
	{
		return NULL;
	}

	char *parent_path = bfs(graph, destination);
	queue_list *shortest_path = init_queue();	// we can use dynamic array let's just use linked list.
	// don't need to check any more.
	enqueue(shortest_path, source);

	// loop until parent is the root.
	char parent = parent_path[hash_function(source)];
	while(parent != '\0')
	{
		// don't need to check any more.
		enqueue(shortest_path, parent);
		parent = parent_path[hash_function(parent)];
	}
	free(parent_path);

	return shortest_path;
}

char* bfs(graph *graph, char start_vertex)
{
	int hashed_value = hash_function(start_vertex);
	if (hashed_value == -1 || graph->hash_table[hashed_value].value != start_vertex)
	{
		fprintf(stderr, "Invalid vertex.\n");
		exit(2);
	}

	queue_list *vertex_queue = init_queue();
	if (vertex_queue == NULL)
	{
		fprintf(stderr, "Not enough memory for creating vertices queue,\n");
		exit(1);
	}

	// will use the hash function for a-zA-Z
	bool *visited_vertices = calloc(MAX_CHAR, sizeof(bool));
	if (visited_vertices == NULL)
	{
		free_queue_list(vertex_queue);
		fprintf(stderr, "Not enough memory for creating visited vertices array.\n");
		exit(1);
	}

	// will use the hash function for a-zA-Z
	char *parent_vertices = calloc(MAX_CHAR, sizeof(char));
	if (parent_vertices == NULL)
	{
		free_queue_list(vertex_queue); free(visited_vertices);
		fprintf(stderr, "Not enough memory for creating parent vertices array.\n");
		exit(1);
	}

	// enqueue the start vertex.
	if (enqueue(vertex_queue, start_vertex) == false)
	{
		free_queue_list(vertex_queue); free(visited_vertices); free(parent_vertices);
		fprintf(stderr, "Not enough memory for creating queueu_node for queueu_list.\n");
		exit(1);
	}

	// mark the start as visited.
	visited_vertices[hashed_value] = true;

	while(vertex_queue->size != 0)
	{
		// dequeue the first value
		char current_vertex = dequeue(vertex_queue);
		// insanity check.
		if (current_vertex == '\0')
		{
			fprintf(stderr, "Empty vertex\n");
			exit(2);
		}
		
		// process the current_vertix somehow.
		
		// getting the adjacency list. we don't have to check invalid vertix anymore.
		// that is already being checked during the creation of graph.
		int current_vertex_hash = hash_function(current_vertex);
		
		// for every neighbors.
		for(node* finger = graph->hash_table[current_vertex_hash].next; finger != NULL; finger = finger->next)
		{
			int finger_value_hash = hash_function(finger->value);
			// this neighbor's not visited
			if (visited_vertices[finger_value_hash] != true)
			{
				// everything's okay.
				if(enqueue(vertex_queue, finger->value) == true)
				{
					// mark visited
					visited_vertices[finger_value_hash] = true;
					// book mark the parent
					parent_vertices[finger_value_hash] = current_vertex;
				} else {
					free_queue_list(vertex_queue); free(visited_vertices); free(parent_vertices);
					fprintf(stderr, "Not enough memory for creating queue_node for queue_list.\n");
					exit(1);
				}
			}
		}
	}

	free_queue_list(vertex_queue); free(visited_vertices);
	// The bfs complete when the queue is empty.
	return parent_vertices;
}

queue_list* init_queue(void)
{
	queue_list* new_queue = calloc(1, sizeof(queue_list));
	if(new_queue == NULL)
	{
		fprintf(stderr, "Not enough memory for creating linked list queue.\n");
		exit(1);
	}
	return new_queue;
}

bool enqueue(queue_list *queue, char vertex)
{
	// create new queue_node
	queue_node *new_node = calloc(1, sizeof(queue_node));
	if (new_node == NULL)
	{
		//free_queue_list(queue);
		//fprintf(stderr, "Not enough memory for creating queue node.\n");;
		return false;
	}
	new_node->value = vertex;
	
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

char dequeue(queue_list *queue)
{
	if (queue == NULL || queue->head == NULL)
	{
		// dequeuing the empty queue_list.
		return '\0';
	}

	queue_node *first_node = queue->head;
	if(first_node->next == NULL)
	{
		queue->head = NULL;
		queue->tail = NULL;
	}
	else
	{
		queue->head = first_node->next;
		queue->head->prev = NULL;
	}

	char value = first_node->value;
	free(first_node);
	queue->size--;
	return value;
}

void free_queue_list(queue_list *queue)
{
	queue_node *finger = queue->head;
	while(finger != NULL)
	{
		queue_node *temp = finger->next;
		free(finger);
		finger = temp;
	}
	free(queue);
}

void print_queue_list(queue_list *queue)
{
	queue_node *finger = queue->head;
	while(finger != NULL)
	{
		printf("%c, ", finger->value);
		finger = finger->next;
	}
	printf("\n");
}
