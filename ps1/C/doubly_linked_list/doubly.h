// doubly linked-list node.
typedef struct node
{
	int number;
	struct node *next;
	struct node *prev;
}node;

// doubly linked-list's tracker
typedef struct dll
{
	node *head;
	node *tail;
}dll;
