#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// a tree node for seq_AVL_tree
typedef struct binary_node {
  int size;                   // size of the subtree
  int value;                  // value of the node
  int height;
  struct binary_node *parent; // parent of the node
  struct binary_node *left;   // left child of the node
  struct binary_node *right;  // right child of the node
} binary_node;

// sequence avl tree doesn't have to maintain sorted order.
// only the set avl tree depends on its.

//----------------------------------------------helper functions-----------------------------

// cal_height returns the given node's height if given node exits.
// returns -1 if the given node is NULL.
int cal_height(binary_node *node);

// skew returns the skew of the node.
// exit with failure if the given node is NULL.
int skew(binary_node *node);

//---------------------------------------------dynamic operations--------------------------

// update the heigh and size of the given subtree's node.
// exit with failure if the given node is NULL.
void subtree_update(binary_node *tree);

// subtree_rotate_right rotates in right direction.
// exit with failure if the given tree or tree's left child is NULL.
// returns the rotate tree.
binary_node* subtree_rotate_right(binary_node *tree);

// subtree_rotate_left rotates in left direction.
// exit with failure if the given tree or tree's right child is NULL.
// returns the rotate tree.
binary_node* subtree_rotate_left(binary_node *tree);

// rebalance balances the given node using rotations(subtree_rotate_right and subtree_rotate_left)
// exit with failure if the given node is NULL.
// returns the balanced node.
binary_node* rebalance(binary_node *node);

// maintain maintains the given node's subtree augmentations.
// Also update the augmentations of ancestors if there's any.
binary_node* maintain(binary_node *node);

// subtree_insert_after inserts a new node after the given node with the given value.
// The root node of the tree is also required for maintaining the subtree's augmentations.
// exit with failure if the given node is NULL.
void subtree_insert_after(binary_node **tree, binary_node *node, int value);

// subtree_insert_before inserts a new node before the given node with the given value.
// The root node of the tree is also required for maintaining the subtree's augmentations.
// exit with failure if the given node is NULL.
void subtree_insert_before(binary_node **tree, binary_node *node, int value);


// build_seq_avl_sorted builds a new sorted seq AVL tree using
// build_seq_avl_recursion. return NULL if the values is empty or the length is
// zero. Returns the root node of the tree.
binary_node *build_seq_avl_sorted(int values[], int length);

// build_seq_avl builds a new seq AVL tree using build_seq_avl_recursion.
// return NULL if the values is empty or the length is zero.
// Returns the root node of the tree.
binary_node *build_seq_avl(int values[], int length);

// build_req_avl_recursion builds a new seq AVL tree using given values and left
// and right index of values. returns NULL
binary_node *build_seq_avl_recursion(int values[], int left, int right);

// insert_at inserts to the given tree's index with a new node having value.
// If tree is NULL, new tree is initiated and tree will be root of the new tree.
void insert_at(binary_node *tree, int index, int value);

// subtree_delete_node deletes the given node returning the deleted node
// root node of the currently deleting tree is needed since there'll be maintaining the balance.
// exit with failure if the given node is NULL.
// you have to manually set the node's parent to NULL to fully delete the given node.
// this is to support the other delete functions
binary_node *subtree_delete_node(binary_node **root, binary_node *node);

// delete_at deletes the node of the given index of the given tree.
// exit code 2 if the given tree is NULL.
// exit code 3 if the given index is less than 0.
// retuns the deleted node.
binary_node *delete_at(binary_node **tree, int index);

// insert_first inserts a new node with the given value to the given tree.
// inserted node will be the first node of the given tree.
void insert_first(binary_node *tree, int value);

// insert_last inserts a new node with the given value to the given tree.
// inserted node will be the last node of the given tree.
void insert_last(binary_node *tree, int value);

// delete_first deletes the first node of the given tree.
binary_node *delete_first(binary_node **tree);

// delete_last deletes the last node of the given tree.
binary_node *delete_last(binary_node **tree);

//-------------------------------------------------- static operations----------------------

// subtree_first finds the first node in the traversal order in the tree.
// returns the founded first node of the tree.
binary_node *subtree_first(binary_node *tree);

// subtree_last finds the last node in the traversal order in the tree.
// returns the founded first node of the tree.
binary_node *subtree_last(binary_node *tree);

// successor gives the next successor of the tree.
// returns the successor node.
binary_node* successor(binary_node *node);

// predecessor gives the previous node of the tree in traversal order.
// returns the predecessor node.
binary_node* predecessor(binary_node *node);

// subtree_at finds the node of the given index in the given subtree.
// exit code 2 if the given index is less than 0.
binary_node *subtree_at(binary_node *tree, int index);

// get_at gets the given index's node's value in given tree calling subtree_at.
// exit code 2 if the given tree is NULL.
// exit code 3 if the given index is less than 0.
int get_at(binary_node *tree, int index);

// set_at sets the given index's node's value to the given value.
// exit code 2 if the given tree is NULL.
// exit code 3 if the given index is less than 0.
void set_at(binary_node *tree, int index, int value);

//---------------------------------------------visual----------------------------------

// iterate through the tree in in-order traversal and prints out the node's
// values.
void subtree_iter(binary_node *node);

// print_root_to_leaf prints the
void print_pre_order(binary_node *root);

// free_tree frees the memory that is allocated for the given node's subtree.
void free_tree(binary_node *node);

// print_hr prints the visual line.
void print_hr(void);

void print_array(int values[], int length);
