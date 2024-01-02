typedef struct node 
{
	int value;
	struct node* next;
}node;

node* build(int values[], int length);

void free_list(node *list);

void half_reverse(node *list, int length);

void print_list(node* list, char* context);
