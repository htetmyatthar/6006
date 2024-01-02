// nodes of a singly linked list.
typedef struct node 
{
	int number;
	struct node *next;
}node;

// build builds the singly linked-list given the numbers and length of the numbers.
// returns the list.
node* build(int numbers[], int length);

// create a new singly linked-list node and return a node.
node* create_node(int number);

// print_list prints out the items inside the inputted singly linked-list.
void print_list(node *list);

// free all the memory that is allocated after the program finish using the singly linked-list
void free_list(node *list);

// set the new_value at index for the given singly linked-list.
void set_at(node *list, int index, int new_value);

// delete the first item, in other words the last inputted item in the constant time operation.
node* delete_first(node *list);

// get the node at the index for the given singly linked-list
//  returns the node.
node* get_at(node *list, int index);

