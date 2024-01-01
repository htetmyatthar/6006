#include "doubly.h"

dll* build(int values[], int length);

dll* remove_nodes(dll *list, node *start, node *end);

int delete_last(dll *list);

int delete_first(dll *list);

dll* insert_last(dll *list, int value);

dll* insert_first(dll *list, int value);

void print_list(dll *list);

void free_list(dll *list);

node* get_at(dll *list, int index);

void splice_list(dll *list, node *list_index_node, dll *another_list);
