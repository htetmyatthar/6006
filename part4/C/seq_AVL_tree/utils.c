#include "utils.h"
  
binary_node *build_seq_avl_sorted(int values[], int length)
{
	if(values == NULL || length == 0)
	{
		// return the empty tree.
		return NULL;
	}

	// limited to positive values.
	int highest_value = values[0];
	for(int i = 0; i < length; i++)
	{
		if (values[i] > highest_value)
		{
			highest_value = values[i];
		}
	}
	int max_value = highest_value + 1;
	// initialize bucket
	int *sorted_array = malloc(sizeof(int) * max_value);
	if(sorted_array == NULL)
	{
		fprintf(stderr, "Error: Not enough memory for creating bucket to sort.\n");
		exit(1);
	}
	for(int i = 0; i < max_value; i++)
	{
		sorted_array[i] = -1;
	}

	// copy to bucket
	for(int i = 0; i < length; i++)
	{
		sorted_array[values[i]] = values[i];
	}
	//copy the sorted
	int j = 0;
	for(int i = 0; i < max_value; i++)
	{
		if (sorted_array[i] != -1)
		{
			values[j] = sorted_array[i];
			j++;
		}
	}
	// free the allocated memory.
	free(sorted_array);

	return build_seq_avl_recursion(values, 0, length - 1);
}

binary_node *build_seq_avl_recursion(int values[], int left, int right)
{
	if(left > right)
	{
		return NULL;
	}

	// int middle = left + ((right - left) / 2);
	int middle = (left + right) / 2;

	binary_node *root = calloc(1, sizeof(binary_node));
	if(root == NULL)
	{
		fprintf(stderr, "Error: Not enough memory creating nodes.\n");
		exit(1);
	}
	root->value = values[middle];
	root->size = 1;

	root->left = build_seq_avl_recursion(values, left, middle - 1);
	if (root->left != NULL)
	{
		root->left->parent = root;
		subtree_update(root);
		//printf("size %d", root->size);
	}

	root->right = build_seq_avl_recursion(values, middle + 1, right);
	if (root->right != NULL)
	{
		root->right->parent = root;
		subtree_update(root);
	}

	return root;
}

binary_node *build_seq_avl(int values[], int length)
{
	if(values == NULL || length == 0)
	{
		// return the empty tree.
		return NULL;
	}
	return build_seq_avl_recursion(values, 0, length - 1);
}

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

void subtree_update(binary_node *tree)
{
	// height updates
	if(tree == NULL)
	{
		fprintf(stderr, "Given tree shouldn't be NULL.");
		exit(EXIT_FAILURE);
	}
	int left_height = cal_height(tree->left);
	int right_height = cal_height(tree->right);

	// initialize for comparison
	int higher_one = left_height;
	// compare.
	if(right_height > higher_one)
	{
		higher_one = right_height;
	}

	// either == or left is more higher than right
	tree->height = 1 + higher_one;

	// size updates
	tree->size = 1;
	if (tree->left)
	{
		tree->size += tree->left->size;
	}
	if (tree->right)
	{
		tree->size += tree->right->size;
	}
}

binary_node *subtree_at(binary_node *tree, int index)
{
	// invalid index checking
	if (index < 0)
	{
		fprintf(stderr, "Error: Invalid index.\n");
		exit(2);
	}
	
	// preparation for comparison
	int left_subtree_size = 0;
	if(tree->left != NULL)
	{
		left_subtree_size = tree->left->size;
	}

	// recusive searches
	if(index < left_subtree_size)
	{
		return subtree_at(tree->left, index);
	}
	else if(index > left_subtree_size)
	{
		return subtree_at(tree->right, index - left_subtree_size - 1);
	}
	return tree;
}

int get_at(binary_node *tree, int index)
{
	if(tree == NULL)
	{
		fprintf(stderr, "Error: Given tree is NULL.\n");
		exit(2);
	}
	else if(index < 0)
	{
		fprintf(stderr, "Error: Invalid index.\n");
		exit(3);
	}

	return subtree_at(tree, index)->value;
}

void set_at(binary_node *tree, int index, int value)
{
	if(tree == NULL)
	{
		fprintf(stderr, "Error: Given tree is NULL.\n");
		exit(2);
	}
	else if(index < 0)
	{
		fprintf(stderr, "Error: Invalid index.\n");
		exit(3);
	}

	binary_node* temp = subtree_at(tree, index);
	temp->value = value;
}

binary_node* subtree_rotate_right(binary_node *tree)
{
	if (tree == NULL || tree->left == NULL)
	{
		fprintf(stderr, "Error: Cannot perform right rotation. The tree or it's left subtree's NULL\n.");
		exit(EXIT_FAILURE);
	}

	// ancestor
	binary_node *base_tree = tree->parent;
	
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

	// update the base tree's child
	if(base_tree != NULL)
	{
		if (base_tree->left == tree)
		{
			base_tree->left = new_root;
		}
		else if(base_tree->right == tree)
		{
			base_tree->right = new_root;
		}
	}

	// update the height and size
	// augmentations updating.
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
	binary_node *base_tree = tree->parent;

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

	// update the base tree's child.
	if (base_tree != NULL)
	{
		if(base_tree->left == tree)
		{
			base_tree->left = new_root;
		}
		else if(base_tree->right == tree)
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

	// remember the skew's definition.
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
		//return the maintained node.
		return maintain(node->parent);
	}
	return balanced_node;
}

void subtree_insert_after(binary_node **tree, binary_node *node, int value)
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
	new_node->size = 1;

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

void subtree_insert_before(binary_node **tree, binary_node *node, int value)
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
	new_node->size = 1;

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

void insert_at(binary_node *tree, int index, int value)
{
	// insert at first.
	if(index == 0)
	{
		// check if the tree has any node
		if (tree != NULL)
		{
			binary_node *node = subtree_first(tree);
			subtree_insert_before(&tree, node, value);
			return;
		}

		// this tree will be new.
		binary_node *new_node = calloc(1, sizeof(binary_node));
		if(new_node == NULL)
		{
			fprintf(stderr, "Error: Not enough memory for creating new node.\n");
			exit(1);
		}
		tree = new_node;
		return;
	}

	// other indexes
	binary_node *node = subtree_at(tree, index - 1);
	subtree_insert_after(&tree, node, value);
	//tree->size += 1;
	return;
}

binary_node *subtree_first(binary_node *tree)
{
	if(tree->left)
	{
		return subtree_first(tree->left);
	}
	return tree;
}

binary_node *subtree_last(binary_node *tree)
{
	if(tree->right)
	{
		return subtree_last(tree->right);
	}
	return tree;
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

binary_node *subtree_delete_node(binary_node **root, binary_node *node)
{
	if (node == NULL)
	{
		fprintf(stderr, "Error: The node you want to delete isn't exit.");
		exit(EXIT_FAILURE);
	}

	// this is a leaf
	if(node->left == NULL && node->right == NULL)
	{
		// this is the left child leaf
		if(node->parent->left == node)
		{
			// detach
			node->parent->left = NULL;
			*root = maintain(node->parent);
			//node->parent = NULL;
			//see the doc.
			// the above three lines order matters.

			return node;
		}
		// this is the right child leaf
		// detach
		node->parent->right = NULL;
		*root = maintain(node->parent);
		//node->parent = NULL;
		//see the doc.
		// the above three lines order matters.

		return node;
	}
	// this is an ancestor check if this has left child to swap with left successor
	else if(node->left != NULL)
	{
		binary_node *predecessor_node = predecessor(node);
		int temp_value = predecessor_node->value;
		predecessor_node->value = node->value;
		node->value = temp_value;
		return subtree_delete_node(root, predecessor_node);
	}
	// this is an ancestor there's gotta be right child to swap with right successor
	else
	{
		binary_node *successor_node = successor(node);
		int temp_value = successor_node->value;
		successor_node->value = node->value;
		node->value = temp_value;
		return subtree_delete_node(root, node);
	}
	// if there's no right or left child it's certain it's leaf.(first condition)
}

binary_node *delete_at(binary_node **tree, int index)
{
	if(tree == NULL)
	{
		fprintf(stderr, "Error: Given tree doesn't exit.\n");
		exit(2);
	}
	else if(index < 0)
	{
		fprintf(stderr, "Error: Invalid index.\n");
	}

	binary_node* node_to_delete = subtree_at(*tree, index);
	binary_node* deleted_node = subtree_delete_node(tree, node_to_delete);

	// the deleted node is the root node.
	if (deleted_node->parent == NULL)
	{
		*tree = NULL;
	}
	deleted_node->parent = NULL;
	//tree->size -= 1;
	return deleted_node;
}

void insert_first(binary_node *tree, int value)
{
	return insert_at(tree, 0, value);
}

void insert_last (binary_node *tree, int value)
{
	return insert_at(tree, tree->size, value);
}

binary_node *delete_first(binary_node **tree)
{
	return delete_at(tree, 0);
}

binary_node *delete_last(binary_node **tree)
{
	return delete_at(tree, (*tree)->size - 1);
}

//---------------------------------------------visual---------------------------

void subtree_iter(binary_node *node)
{
	if (node != NULL)
	{
		subtree_iter(node->left);
		printf("value: %d, size: %d, heigth: %d\n", node->value, node->size, node->height);
		subtree_iter(node->right);
	}
}

void print_pre_order(binary_node *node)
{
	if (node != NULL)
	{
		printf("value: %d, size: %d, heigth: %d\n", node->value, node->size, node->height);
		if(node->parent != NULL)
		{
			printf("parent: %d\n", node->parent->value);
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

void print_array(int values[], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d, ", values[i]);
	}
	printf("\n");
}

