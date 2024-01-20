#include "utils.h"

//----------------------------------------------------------building------------------------------

binary_node* build_set_avl_tree(int keys_values[][2], int length)
{
	// there's two ways
	// 1. first sort then make like the last time.
	// 2. iterate and sort in the way, but that would case the comparison overhead.
	// 
	// let's just use the first method.
	// we already knew from the previous part that we can do DAA sort.
	// let's use that cause we know that the keys are smaller than the size_of_array^2.
	// assumming that keys are larger than 0.
	if(length == 0 || keys_values == NULL)
	{
		return NULL;
	}
	
	DAA_sort(keys_values, length); // keys_values are now sorted in linear time complexity.
	
	return _build_set_avl_tree_recursion(keys_values, 0, length - 1);	
}

binary_node* _build_set_avl_tree_recursion(int keys_values[][2], int left, int right)
{
	if(left > right)
	{
		return NULL;
	}

	// int middle = left + ((right - left) / 2);
	int middle = (left + right) / 2;

	// create a node.
	binary_node *root = calloc(1, sizeof(binary_node));
	if(root == NULL)
	{
		fprintf(stderr, "Error: Not enough memory for creating nodes to build.\n");
		exit(1);
	}
	root->value = keys_values[middle][1];
	root->key = keys_values[middle][0];

	root->left = _build_set_avl_tree_recursion(keys_values, left, middle - 1);
	if(root->left != NULL)
	{
		root->left->parent = root;
		// setting up the height.
		subtree_update(root);
	}
	root->right = _build_set_avl_tree_recursion(keys_values, middle + 1, right);
	if(root->right != NULL)
	{
		root->right->parent = root;
		// setting up the height.
		subtree_update(root);
	}

	return root;
}

void DAA_sort(int keys_values[][2], int length)
{
	int highest_key = 0;
	for(int i = 0; i < length; i++)
	{
		if (keys_values[i][0] > highest_key)
		{
			highest_key = keys_values[i][0];
		}
	}
	int max_key = highest_key + 1;

	// allocate memory for the base array
	int **sorted_array = calloc(max_key, sizeof(int*));
	if (sorted_array == 0)
	{
		fprintf(stderr, "Error: Not enough memory for creating buckets for sorting.\n");
		exit(1);
	}

	// allocate memory for the keys values array
	for(int i = 0; i < max_key; i++)
	{
		sorted_array[i] = malloc(2 * sizeof(int));
		if (sorted_array[i] == NULL)
		{
			fprintf(stderr, "Error: Not enough memory for creating buckets for keys values.\n");
			exit(1);
		}
		// assumming keys are larger than zero.
		sorted_array[i][0] = 0;
	}

	// iterate through keys_values
	for(int i = 0; i < length; i++)
	{
		sorted_array[keys_values[i][0]][0] = keys_values[i][0];
		sorted_array[keys_values[i][0]][1] = keys_values[i][1];
	}

	// iterate through sorted_array
	int j = 0;
	for(int i = 0; i < max_key; i++)
	{
		// assuming keys are larger than zero.
		// we have to depends on keys rather than allocated base array.
		if(sorted_array[i][0] != 0)
		{
			keys_values[j][0] = sorted_array[i][0];
			keys_values[j][1] = sorted_array[i][1];
			j++;
		}
		free(sorted_array[i]);
	}
	free(sorted_array);
	return;
}

//--------------------------------------------------------------interface----------------------------

int cal_height(binary_node *node)
{
	if (node != NULL)
	{
		return node->height;
	}
	// height (-) means the given node is not connected to the tree.
	return -1;
}

int skew(binary_node *node)
{
	if(node == NULL)
	{
		fprintf(stderr, "Given node shouldn't be NULL.");
		exit(EXIT_FAILURE);
	}

	return cal_height(node->right) - cal_height(node->left);
}

void subtree_update(binary_node *node)
{
	if(node == NULL)
	{
		fprintf(stderr, "Given node shouldn't be NULL.");
		exit(EXIT_FAILURE);
	}
	int left_height = cal_height(node->left);
	int right_height = cal_height(node->right);

	// initialize for comparison
	int higher_one = left_height;
	// compare.
	if(right_height > higher_one)
	{
		higher_one = right_height;
	}

	// either == or left is more higher than right
	node->height = 1 + higher_one;
}

binary_node* subtree_rotate_right(binary_node *tree)
{
	if (tree == NULL || tree->left == NULL)
	{
		fprintf(stderr, "Error: Cannot perform right rotation. The tree or it's left subtree's NULL\n.");
		exit(EXIT_FAILURE);
	}
	// ancestor
	binary_node* base_tree = tree->parent;
	
	// preparation of rotation
	binary_node* new_root = tree->left;
	binary_node* new_root_right = new_root->right;

	// change root
	new_root->parent = tree->parent;
	tree->parent = new_root;

	// the right node of the new root
	tree->left = new_root_right;
	if (new_root_right != NULL)
	{
		new_root_right->parent = tree;
	}

	// update right child of the new root
	new_root->right = tree;

	// update the child of the ancestor of old root
	if(base_tree != NULL)
	{
		if(base_tree->left == tree)
		{
			base_tree->left = new_root;
		}
		if(base_tree->right == tree)
		{
			base_tree->right = new_root;
		}
	}

	// update the height
	subtree_update(tree);
	subtree_update(new_root);

	return new_root;
}

binary_node* subtree_rotate_left(binary_node *tree)
{
	if(tree == NULL || tree->right == NULL)
	{
		fprintf(stderr, "Error: Cannot perform left rotation. The tree or it's right subtree's NULL.\n");
		exit(EXIT_FAILURE);
	}
	// ancestor
	binary_node* base_tree = tree->parent;

	// preparation for rotation
	binary_node *new_root = tree->right;
	binary_node *new_root_left = new_root->left;

	// change root
	new_root->parent = tree->parent;
	tree->parent = new_root;

	// the left node of the new root
	tree->right = new_root_left;
	if(new_root_left != NULL)
	{
		new_root_left->parent = tree;
	}

	// update left child of the new root
	new_root->left = tree;

	// update the child of the ancestor of old root
	if(base_tree != NULL)
	{
		if(base_tree->left == tree)
		{
			base_tree->left = new_root;
		}
		if(base_tree->right == tree)
		{
			base_tree->right = new_root;
		}
	}

	// update the height
	subtree_update(tree);
	subtree_update(new_root);

	return new_root;
}

binary_node* rebalance(binary_node *node)
{
	if (node == NULL)
	{
		fprintf(stderr,"Error: Cannot rebalance. The subtree is NULL.\n");
		exit(EXIT_FAILURE);
	}

	int node_skew = skew(node);

	if (node_skew == 2)
	{
		if (skew(node->right) < 0)
		{
			node->right = subtree_rotate_right(node->right);
		}
		return subtree_rotate_left(node);
	}
	else if (node_skew == -2)
	{
		if (skew(node->left) > 0)	
		{
			node->left = subtree_rotate_left(node->left);
		}
		return subtree_rotate_right(node);
	}

	return node;
}

binary_node* maintain(binary_node *node)
{
	binary_node *balanced_node = rebalance(node);
	subtree_update(balanced_node);
	// maintain the ancestors.
	if (node->parent != NULL)
	{
		//maintain(node->parent);
		return maintain(node->parent);
	}
	return balanced_node;
}

void subtree_insert_after(binary_node **tree, binary_node *node, int value, int key)
{
	if(node == NULL)
	{
		fprintf(stderr, "Error: the before node isn't exit.\n");
		exit(EXIT_FAILURE);
	}

	// creating new node.
	binary_node *new_node = calloc(1, sizeof(binary_node));
	if (new_node == NULL)
	{
		fprintf(stderr,"Error: Not enough memory for creating binary node.\n");
		exit(1);
	}
	new_node->value = value;
	new_node->key = key;

	// if there's right child.
	if (node->right != NULL)
	{
		// node is now the first node of the right subtree.
		node = subtree_first(node->right);
		node->left = new_node;
		new_node->parent = node;
	}
	else
	{
		node->right = new_node;
		new_node->parent = node;
	}

	// maintain the height balanced traversal order.
	*tree = maintain(node);
}

void subtree_insert_before(binary_node **tree, binary_node *node, int value, int key)
{
	if(node == NULL)
	{
		fprintf(stderr, "Error: The after node isn't exit.\n");
		exit(EXIT_FAILURE);
	}

	// creating new node.
	binary_node *new_node = calloc(1, sizeof(binary_node));
	if(new_node == NULL)
	{
		fprintf(stderr,"Error: Not enough memory for creating binary node.\n");
		exit(1);
	}
	new_node->value = value;
	new_node->key = key;

	// if there's left child.
	if(node->left != NULL)
	{
		// node is now the last node in the left subtree.
		node = subtree_last(node->left);
		node->right = new_node;
		new_node->parent = node;
		return;
	}
	else
	{
		node->left = new_node;
		new_node->parent = node;
	}

	// maintain the height balanced traversal order.
	*tree = maintain(node);
}

binary_node *subtree_delete_node(binary_node **root, binary_node *node)
{
	// I think this method is not that much readable.
	// if (node->left != NULL || node->right != NULL)
	// {
	// 	binary_node* swap_node;
	// 	if(node->left != NULL)
	// 	{
	// 		swap_node = predecessor(node);
	// 	}
	// 	else
	// 	{
	// 		swap_node = successor(node);
	// 	}
	// 	int temp = swap_node->value;
	// 	swap_node->value = node->value;
	// 	node->value = temp;
	//
	// 	return subtree_delete(swap_node);
	// }
	// if (node->parent != NULL)
	// {
	// 	if(node->parent->left == node)
	// 	{
	// 		node->parent->left = NULL;
	// 	}
	// 	else
	// 	{
	// 		node->parent->right = NULL;
	// 	}
	// }
	// return node;
	//
	// I like the below better.
	//
	
	if (node == NULL)
	{
		fprintf(stderr, "Error: The node you want to delete isn't exit.");
		exit(EXIT_FAILURE);
	}

	if(node->left == NULL && node->right == NULL)
	{
		if(node->parent->left == node)
		{
			// detach
			node->parent->left = NULL;
			*root = maintain(node->parent);
			node->parent = NULL;
			// the above three lines order matters.

			return node;
		}
		// detach
		node->parent->right = NULL;
		*root = maintain(node->parent);
		node->parent = NULL;
		// the above three lines order matters.

		return node;
	}
	else if(node->left != NULL)
	{
		binary_node *predecessor_node = predecessor(node);
		int temp_value = predecessor_node->value;
		predecessor_node->value = node->value;
		node->value = temp_value;
		return subtree_delete_node(root, predecessor_node);
	}
	else
	{
		binary_node *successor_node = successor(node);
		int temp_value = successor_node->value;
		successor_node->value = node->value;
		node->value = temp_value;
		return subtree_delete_node(root, node);
	}
}

// _subtree_find_recursion finds the given key's node in the given node's subtrees.
// If there's no keys as such return NULL.
// Returns the node if the given key is found in the node's subtree.
binary_node* _subtree_find_recursion(binary_node *node, int key)
{
	// I didn't add this function to the headers file intentionally.
	// I think this function should be local just for subtree_find.
	// else subtree_find will have the overhead for unecessary error checking 
	if (key < node->key)
	{
		return _subtree_find_recursion(node->left, key);
	}
	else if (key > node->key)
	{
		return _subtree_find_recursion(node->right, key);
	}
	else if (key == node->key)
	{
		return node;
	}
	return NULL;
}

binary_node* subtree_find(binary_node *node, int key)
{
	// error handling
	if(node == NULL)
	{
		fprintf(stderr, "Error: Given subtree is empty.\n");
		exit(EXIT_FAILURE);
	}
	else if (key < 1)
	{
		fprintf(stderr, "Error: Invalid key.\n");
		exit(EXIT_FAILURE);
	}
	// find recursively the key in the node's subtrees.
	return _subtree_find_recursion(node, key);
}

binary_node* subtree_first(binary_node *node)
{
	if(node->left != NULL)
	{
		return subtree_first(node->left);
	}
	return node;
}

binary_node* subtree_last(binary_node *node)
{
	if(node->right != NULL)
	{
		return subtree_last(node->right);
	}
	return node;
}

binary_node* successor(binary_node *node)
{
	if(node->right != NULL)	
	{
		return subtree_first(node->right);
	}
	while(node->parent != NULL)
	{
		if(node == node->parent->left)
		{
			return node->parent;
		}
		node = node->parent;
	}
	return NULL;
}

binary_node* predecessor(binary_node *node)
{
	if (node->left != NULL)
	{
		return subtree_last(node->left);
	}
	while(node->parent != NULL)
	{
		if (node == node->parent->right)
		{
			return node->parent;
		}
		node = node->parent;
	}
	return NULL;
}

//---------------------------------------------visual---------------------------

void subtree_iter(binary_node *node)
{
	if (node != NULL)
	{
		subtree_iter(node->left);
		printf("value: %d, key: %d, heigth: %d\n", node->value, node->key, node->height);
		subtree_iter(node->right);
	}
}

void print_pre_order(binary_node *node)
{
	if (node != NULL)
	{
		printf("value: %d, key: %d, heigth: %d\n", node->value, node->key, node->height);
		if(node->parent != NULL)
		{
			printf("parent: %d\n", node->parent->key);
		}
		print_pre_order(node->left);
		print_pre_order(node->right);
	}
}

void free_tree(binary_node *node)
{
	if (node != NULL)
	{
		free_tree(node->left);
		free_tree(node->right);

		free(node);
	}
}


void print_hr(void)
{
	for(int i = 0; i < 10; i++)
	{
		printf("-------");
	}
	printf("\n");
}

void print_array(int keys_values[][2], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("key: %d, value: %d\n", keys_values[i][0], keys_values[i][1]);
	}
	printf("\n");
	return;
}
