#include "utils.h"

int main(void)
{
	printf("Building with unsorted values.\n\n");
	int given_values1[] = {4, 2, 3, 5, 1};
	int length1 = sizeof(given_values1) / sizeof(given_values1[0]);
	printf("Given array of values: \n");
	print_array(given_values1, length1);
	print_hr();

	binary_node* tree1 = build_seq_avl_sorted(given_values1, length1);
	print_pre_order(tree1);
	free_tree(tree1);
	print_hr();

	int given_values[] = {1, 2, 3, 4, 5};
	int length = sizeof(given_values) / sizeof(given_values[0]);
	printf("Given array of values: \n");
	print_array(given_values, length);
	print_hr();

	binary_node* tree = build_seq_avl(given_values, length);
	print_pre_order(tree);
	print_hr();

	printf("Testing rotations: \n\n");
	printf("Left rotate: \n");
	tree = subtree_rotate_left(tree);
	print_pre_order(tree);

	printf("\nRight rotate: \n");
	tree = subtree_rotate_right(tree);
	print_pre_order(tree);
	print_hr();

	printf("Testing dynamic operations: \n\n");
	printf("Inserting index 3, with value: 77.\n\n");
	insert_at(tree, 3,  77);
	print_pre_order(tree);
	print_hr();

	printf("Inserting again for testing rotations.\n\n");
	printf("Inserting index 3, with value: 99.\n\n");
	insert_at(tree, 3,  99);
	print_pre_order(tree);
	print_hr();

	subtree_iter(tree);
	print_hr();

	printf("Deleting index 1 for testing rotations first\n\n");
	printf("Deleting index 1. \n\n");
	binary_node* deleted_node = delete_at(&tree, 1);
	print_pre_order(tree);
	printf("deleted node's value: %d\n", deleted_node->value);
	print_hr();
	subtree_iter(tree);
	free(deleted_node);
	print_hr();

	printf("Deleting index 1 for testing rotations second\n\n");
	printf("Deleting index 1. \n\n");
	deleted_node = delete_at(&tree, 1);
	print_pre_order(tree);
	printf("deleted node's value: %d\n", deleted_node->value);
	free(deleted_node);
	print_hr();

	printf("Testing get at, set at: \n\n");
	printf("get at index 1:\n");
	assert(get_at(tree, 1) == 99);
	printf("pass\n");

	printf("set at index 1:\n");
	set_at(tree, 1, 2);
	assert(get_at(tree, 1) == 2);
	printf("pass\n");
	print_pre_order(tree);
	print_hr();

	printf("Testing insert_first, insert_last: \n\n");
	printf("insert first with value 0:\n");
	insert_first(tree, 0);
	printf("insert last with value 100:\n");
	insert_last(tree, 100);
	assert(get_at(tree, 0) == 0);
	assert(get_at(tree, tree->size - 1) == 100);
	printf("pass\n");
	print_pre_order(tree);
	print_hr();

	printf("Testing delete_first, delete_last: \n\n");

	int first_value = get_at(tree, 0);
	binary_node* first_node = delete_first(&tree);
	assert(first_node->value == first_value);
	free(first_node);

	int last_value = get_at(tree, tree->size - 1);
	binary_node* last_node = delete_last(&tree);
	assert(last_node->value == last_value);
	printf("pass\n");
	free(last_node);
	print_hr();

	free_tree(tree);
}
