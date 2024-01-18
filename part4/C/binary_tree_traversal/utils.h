#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
  int value;
  struct tree_node *left;
  struct tree_node *right;
  struct tree_node *parent;
} tree_node;

// build_tree_recursion builds a binary tree,
// using the values given by the left most index and right most index of the
// values array. returns the root node of the tree.
tree_node *_build_tree_recursion(int values[], int left, int right);

// build_tree builds a binary tree,
// returns the root node of the tree.
tree_node *build_tree(int values[], int length);

// first_tree_node finds the first node in the traversal order in the tree.
// returns the founded first node of the tree.
tree_node *first_tree_node(tree_node *tree);

// last_tree_node finds the last node in the traversal order in the tree.
// returns the founded last node of the tree.
tree_node *last_tree_node(tree_node *tree);

// tree_successor gives the next successor of the tree.
// returns the successor node.
tree_node *tree_successor(tree_node *node);

// tree_predecessor gives the previous node of the tree in traversal order.
// returns the predecessor node.
tree_node* tree_predecessor(tree_node* node);

// insert_after_node inserts a new tree node with the given value after given node.
void insert_after_node(tree_node *node, int value);

// insert_before_node inserts a new tree node with the given value before given node.
void insert_before_node(tree_node *node, int value);

void delete_tree_node(tree_node *node);

// print_tree_traversal prints the values in the given tree in traversal order.
// this function uses iterative method.
void print_tree_traversal(tree_node *tree);

// in_order_traversal prints the values in the given tree in traversal order.
// this function uses recursive method.
void in_order_traversal(tree_node *tree);

// print_root_to_leaf prints the 
void print_pre_order(tree_node* root);

// free_tree_recursive frees the memory that is allocated during the creation of
// given binary tree.
void free_tree_recursive(tree_node *root);

// print_hr prints out a visual line.
void print_hr(void);
