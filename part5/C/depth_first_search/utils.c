#include "utils.h"

queue_list* full_dfs(graph *graph, char parent[])
{
	if (graph == NULL || parent == NULL)
	{
		return NULL;
	}
	queue_list *order = calloc(1, sizeof(queue_list));
	if(order == NULL)
	{
		return NULL;
	}

	// needed to use this since I use the array data structure.
	for(int i = 0; i < MAX_CHAR; i++)
	{
		// for every vertices
		if (graph->hash_table[i].value != '\0')
		{
			// if the vertex has no parent
			if(parent[i] == '\0' && i <= 25)
			{
				char ch = (char) i + 65;
				parent[i] = ch;
				dfs_recursion(graph, ch, parent, order, true);
			} 
			else if (parent[i] == '\0' && i > 25)
			{
				char ch = (char) i + 71;
				parent[i] = ch;
				dfs_recursion(graph, ch, parent, order, true);
			}
		}
	}
	return order;
}

queue_list* dfs(graph *graph, char source, char parent[])
{
	if (graph == NULL || parent == NULL || source > 'z' || source < 'A')
	{
		return NULL;
	}

	queue_list *order = calloc(1, sizeof(queue_list));
	if(order == NULL)
	{
		return NULL;
	}

	return dfs_recursion(graph, source, parent, order, false);
}

queue_list* dfs_recursion(graph *graph, char source, char parent[], queue_list *order, bool empty_parent)
{
	// hash function checks are not necessary since we've done the source and others are in the graph.
	if (empty_parent == false)
	{
		parent[hash_function(source)] = source;		// root.
	}

	// for every neighbors.
	for (node *finger = graph->hash_table[hash_function(source)].next; finger != NULL; finger = finger->next)
	{
		// if this neighbor don't have any parent(not visited)
		if (parent[hash_function(finger->value)] == '\0')
		{
			parent[hash_function(finger->value)] = source;
			dfs_recursion(graph, finger->value, parent, order, true);
		}
	}
	
	// enqueue this source
	enqueue(order, source);
	return order;
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
	queue_node *finger = queue->tail;
	while(finger != NULL)
	{
		printf("%c, ", finger->value);
		finger = finger->prev;
	}
	printf("\n");
}
