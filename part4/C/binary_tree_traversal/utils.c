#include "utils.h"

tree_node* build_tree(int values[], int length){
	if (length == 0 || values == NULL)
	{
		return NULL;
	}
	return _build_tree_recursion(values, 0, length - 1);
}

tree_node* _build_tree_recursion(int values[], int left, int right)
{
	// return node base on right subtree.
	if (left > right)
	{
		return NULL;
	}

	//int middle = left + (right - left) / 2;
	int middle = (left + right) / 2;

	// create a new node.
	tree_node *root = calloc(1, sizeof(tree_node));
	if(root == NULL)
	{
		printf("Not enough memory for creating tree nodes.");
		return NULL;
	}
	root->value = values[middle];

	// build left.
	root->left = _build_tree_recursion(values, left, middle - 1);
	if (root->left != NULL)
	{
		root->left->parent = root;
	}

	// build right
	root->right = _build_tree_recursion(values, middle + 1, right);
	if(root->right != NULL)
	{
		root->right->parent = root;
	}

	// if everything is done.
	return root;
}

tree_node* first_tree_node(tree_node* node)
{
	// if there's left subtree
	if(node->left != NULL)
	{
		// go into that left subtree.
		return first_tree_node(node->left);
	}
	// there's no left subtree, this is the first node.
	return node;
}

tree_node* last_tree_node (tree_node* node)
{
	// if there's right subtree
	if(node->right != NULL)
	{
		// go into that right subtree.
		return last_tree_node(node->right);
	}
	// there's no right subtree, this is the last node.
	return node;
}

tree_node* tree_successor(tree_node* node)
{
	// if the given node has right subtree
	if(node->right != NULL)
	{
		// it's the first node of the node's right subtree.
		return first_tree_node(node->right);
	}
	// iterate through the parent node.
	while(node->parent != NULL) 
	{
		// until the node's parent's left subtree is the node.
		if (node == node->parent->left)
		{
			return node->parent;
		}
		// if not go to next parent.
		node = node->parent;
	}
	return NULL;
}

tree_node* tree_predecessor(tree_node* node)
{
	// if the given node has left subtree
	if(node->left != NULL)
	{
		// it's the first node of the node's left subtree.
		return last_tree_node(node->left);
	}
	// iterate through the parent node.
	while(node->parent != NULL)
	{
		// until the node's parent's right subtree is the node.
		if (node == node->parent->right)
		{
			return node->parent;
		}
		// if not go to next parent.
		node = node->parent;
	}
	return NULL;
}

void insert_after_node(tree_node *node, int value)
{
	tree_node *new_node = calloc(1, sizeof(tree_node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Not enough memory for creating a new node.");
		exit(1);
	}
	new_node->value = value;

	// if the given node doesn't have right child.
	if(node->right == NULL)
	{
		new_node->parent = node;
		node->right = new_node;
		return;
	}

	// first node of the right subtree
	tree_node *first_of_right_subtree = first_tree_node(node->right);

	first_of_right_subtree->left = new_node;
	new_node->parent = first_of_right_subtree;
	return;
}

void insert_before_node(tree_node *node, int value)
{
	tree_node *new_node = calloc(1, sizeof(tree_node));
	if(new_node == NULL)
	{
		fprintf(stderr, "Not enough memory for creating a new node.");
		exit(1);
	}
	new_node->value = value;

	if(node->left == NULL)
	{
		new_node->parent = node;
		node->left = new_node;
		return;
	}

	// last node of the left subtree.
	tree_node *last_of_left_subtree = last_tree_node(node->left);

	last_of_left_subtree->right = new_node;
	new_node->parent = last_of_left_subtree;
	return;
}

void delete_tree_node(tree_node *node)
{
	// if the node is a leaf.
	if(node->left == NULL && node->right == NULL)
	{
		// if this node is the left child.
		if(node->parent->left == node)
		{
			// detach and free.
			node->parent->left = NULL;
			free(node);
			return;
		}
		node->parent->right = NULL;
		free(node);
		return;
	}
	// if the node has left child.
	else if (node->left != NULL)
	{
		tree_node *predecessor = tree_predecessor(node);
		int temp_value = predecessor->value;
		predecessor->value = node->value;
		node->value = temp_value;
		delete_tree_node(predecessor);
	}
	// the node has right child after all.
	else
	{
		tree_node *successor = tree_successor(node);
		int temp_value = successor->value;
		successor->value = node->value;
		node->value = temp_value;
		delete_tree_node(successor);
	}
}

void print_tree_traversal(tree_node* tree)
{
	tree_node *node = first_tree_node(tree);
	while (node != NULL)
	{
		printf("%d, ", node->value);
		node = tree_successor(node);
	}
}

void in_order_traversal(tree_node* tree)
{
	if (tree != NULL)
	{
		in_order_traversal(tree->left);
		printf("%d, ", tree->value);
		in_order_traversal(tree->right);
	}
}

void print_pre_order(tree_node* root)
{
	if(root != NULL)
	{
		printf("%d, ", root->value);
		print_pre_order(root->left);
		print_pre_order(root->right);
	}
}

void free_tree_recursive(tree_node *root)
{
	if(root != NULL)
	{
		free_tree_recursive(root->left);
		free_tree_recursive(root->right);

		free(root);
	}
}

void print_hr(void)
{
	for(int i = 0; i < 10; i++)
	{
		printf("--------");
	}
	printf("\n");
}
