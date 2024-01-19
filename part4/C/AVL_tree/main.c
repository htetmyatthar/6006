#include "utils.h"

int main(void) {

	// -----------------------------------------------building--------------------------------------
	int given_keys_values[][2] = {{3, 4},  {1, 2},   {7, 8},  {5, 6},
	{9, 10}, {11, 12}, {13, 14}};
	int given_keys_values1[][2] = {{3, 4},  {1, 2},   {7, 8},  {5, 6},
	{9, 10}, {11, 12}, {13, 14}};
	int length1 = sizeof(given_keys_values1) / sizeof(given_keys_values1[0]);
	binary_node *tree = build_set_avl_tree(given_keys_values1, length1);
	printf("Traversing from root to leaf:\n");
	print_pre_order(tree);
	print_hr();

	printf("In-order traversal:\n");
	subtree_iter(tree);
	print_hr();

	//-------------------------------------------------static operations----------------------------

	printf("Finding node with key 9: \n\n");
	binary_node *found_node = subtree_find(tree, 9);
	if (found_node != NULL) {
		printf("Found node's value: %d, key: %d, height: %d\n", found_node->value,
		 found_node->key, found_node->height);
	}
	print_hr();

	binary_node *first_node = subtree_first(tree);
	printf("First node for in-order traversal: \nnode's value: %d, key: %d, "
		"height %d\n",
		first_node->value, first_node->key, first_node->height);
	print_hr();

	binary_node *last_node = subtree_last(tree);
	printf("Last node for in-order traversal: \nnode's value: %d, key: %d, "
		"height %d\n",
		last_node->value, last_node->key, last_node->height);
	print_hr();

	binary_node *root_successor = successor(tree);
	printf("Root node's successor: \nnode's value: %d, key: %d, "
		"height %d\n",
		root_successor->value, root_successor->key, root_successor->height);
	print_hr();

	binary_node *root_predecessor = predecessor(tree);
	printf("Root node's predecessor: \nnode's value: %d, key: %d, "
		"height %d\n",
		root_predecessor->value, root_predecessor->key, root_predecessor->height);
	print_hr();

	int length = sizeof(given_keys_values) / sizeof(given_keys_values[0]);
	printf("Original keys values: \n");
	print_array(given_keys_values, length);
	printf("Sorted keys values: \n");
	DAA_sort(given_keys_values, length);
	print_array(given_keys_values, length);
	print_hr();

	printf("Skew of root node: %d\n", skew(tree));
	print_hr();

	printf("Height of root node: %d\n", cal_height(tree));
	print_hr();

	//---------------------------------------------rotations operations------------------------------

	printf("Right rotating the balanced avl tree.\nOriginal Pre-order-traversal: \n\n");
	print_pre_order(tree);
	binary_node* right_rotated_tree = subtree_rotate_right(tree);
	printf("\n");
	printf("Rotated Pre-order-traversal:\n\n");
	print_pre_order(right_rotated_tree);
	print_hr();

	printf("Left rotation on the unbalanced skew +2 subtree.\n(which will balanced by left rotation)\nOriginal Pre-order-traversal: \n\n");
	print_pre_order(right_rotated_tree);
	binary_node* balanced_tree = subtree_rotate_left(right_rotated_tree);
	printf("\n");
	printf("Rotated Pre-order-traversal:\n\n");
	print_pre_order(balanced_tree);
	print_hr();

	printf("Left rotation on the balanced avl tree.\nOriginal Pre-order-traversal: \n\n");
	print_pre_order(balanced_tree);
	binary_node* left_rotated_tree = subtree_rotate_left(balanced_tree);
	printf("\n");
	printf("Rotated Pre-order-traversal:\n\n");
	print_pre_order(left_rotated_tree);
	print_hr();

	printf("Rebalance the unbalanced skew -2 subtree.\n(which will balanced by rebalance function)\nOriginal Pre-order-traversal: \n\n");
	print_pre_order(left_rotated_tree);
	binary_node* final_tree = rebalance(left_rotated_tree);
	printf("\n");
	printf("Balanced tree Pre-order-traversal:\n\n");
	print_pre_order(final_tree);
	print_hr();

	//------------------------------------------find/get/set operatons----------------------------

	printf("Inserting a new node with value 99, key 8 after node with key 7.\n\n");
	print_pre_order(final_tree);
	subtree_insert_after(&final_tree, subtree_find(final_tree, 7), 99, 8);
	printf("\nInserted:\n");
	print_pre_order(final_tree);
	print_hr();

	printf("Inserting a new node with value 77, key 10 before node with key 11.\n\n");
	print_pre_order(final_tree);
	subtree_insert_before(&final_tree, subtree_find(final_tree, 11), 77, 10);
	printf("\nInserted:\n");
	print_pre_order(final_tree);
	print_hr();

	printf("Deleting two nodes with key 1 and 5.\n\n");
	print_pre_order(final_tree);
	binary_node *key_one_node = subtree_delete_node(&final_tree, subtree_find(final_tree, 1));
	binary_node *key_five_node = subtree_delete_node(&final_tree, subtree_find(final_tree, 5));
	printf("\nDeleted node, values: %d, key: %d\n", key_one_node->value, key_one_node->key);
	printf("Deleted node, values: %d, key: %d\n", key_five_node->value, key_five_node->key);
	// free that two
	free(key_one_node);
	free(key_five_node);

	printf("\nDeleted tree in-order-traversal:\n");
	print_pre_order(final_tree);
	print_hr();

	printf("maintain function works since we used it in deletion and balancing.\n");
	print_hr();

	// free the whole tree.
	free_tree(final_tree);
}
