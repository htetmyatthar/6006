#include <stdio.h>
#include <stdlib.h>

// binary node for set avl tree.
typedef struct binary_node {
  int key;                    // key for set interface of avl tree.
  int value;                  // actual value that is store in the tree node.
  int height;                 // height of the node.
  struct binary_node *left;   // pointer to the left child.
  struct binary_node *right;  // pointer to the right child.
  struct binary_node *parent; // pointer to the ancessrot.
} binary_node;

// height minus(-) means the node is not connected with the tree.

//-----------------------------------------helper functions--------------------------------

// cal_height return's the given node's height if given node exits.
// returns -1 if the given node is NULL.
int cal_height(binary_node *node);

// skew returns the skew of the node.
// exit with failure if the given node is NULL.
// depends on cal_height.
int skew(binary_node *node);

//-----------------------------------------dynamic operations-------------------------------

// update the height of the given subtree's node
// exit with failure if the given node is NULL.
// dependencies -> cal_height.
void subtree_update(binary_node *node);

// subtree_rotate_right rotates in right direction.
// exit with failure if the given tree or tree's left child is NULL.
// returns the rotated tree.
// direct dependencies subtree_update(indirect dependecies cal_height)
binary_node* subtree_rotate_right(binary_node *tree);

// subtree_rotate_left rotates in left direction.
// exit with failure if the given tree or tree's right child is NULL.
// returns the rotated tree.
// dependencies subtree_update(indirect dependencies cal_height)
binary_node* subtree_rotate_left(binary_node *tree);

// rebalance balances the given node using rotations(subtree_rotate_right and subtree_rotate_left)
// exit with failure if the given node is NULL.
// returns the balanced node.
// dependencies subtree_rotate_right, subtree_rotate_left, skew
// indirent dependencies(cal_height, subtree_update)
binary_node* rebalance(binary_node *node);

// maintain maintains the given node's heigh balance and height augmentation.
// also update the augmentation of heights of the ancestors if there's any.
// direct dependencies rebalace and subtree_update
// indirect dependencies(subtree_rotate_right, subtree_rotate_left, skew, cal_height, subtree_update)
binary_node* maintain(binary_node *node);

// subtree_insert_after inserts a new node after the given node with the given value and key.
// Caution, be careful about the traversal order for insertion.
// exit with failure if the given before node is NULL.
// direct dependencies subtree_last, maintain
// indirect dependencies (rebalance, subtree_update, subtree_rotate_right, subtree_rotate_left, skew, cal_height, subtree_update)
void subtree_insert_after(binary_node **tree, binary_node *node, int value, int key);

// subtree_insert_before inserts a new node before the given node with the given value and key.
// Caution, be careful about the traversal order for insertion.
// exit with failure if the given after node is NULL.
// direct dependencies subtree_last, maintain
// indirect dependencies (rebalance, subtree_update, subtree_rotate_right, subtree_rotate_left, skew, cal_height, subtree_update)
void subtree_insert_before(binary_node **tree, binary_node *node, int value, int key);

// subtree_delete_node deletes the given node returning the deleted node.
// given root node is needed since there'll be maintaining the balance.
// exit with failure if the given node is NULL.
// direct dependencies predecessor, successor
// indirect dependencies (subtree_first, subtree_last)
binary_node *subtree_delete_node(binary_node **root, binary_node *node);

// builds set avl tree in n log n.
// depends on subtree_update and DAA_sort.
binary_node* build_set_avl_tree(int keys_values[][2], int length);

// recursion local helper function for bulid_set_avl_tree.
// build a set avl tree using the SORTED keys values arrays.
binary_node* _build_set_avl_tree_recursion(int keys_values[][2], int left, int right);

// sorting function for keys while building set AVL tree.
// sort using the zero index of every key_values indexes as keys.
void DAA_sort(int keys_values[][2], int length);

//----------------------------------------static operations--------------------------------

// subtree_find finds the given key in given node's subtrees.
// Exit with failure whether node is NULL or the key is invalid(less than 1).
// Returns the found node. If there's no node with given key, returns NULL.
binary_node* subtree_find(binary_node *node, int key);

// subtree_first finds the first node in the traversal order in the tree.
// returns the founded first node of the tree.
binary_node *subtree_first(binary_node *node);

// subtree_last finds the last node in the traversal order in the tree.
// returns the founded last node of the tree.
binary_node *subtree_last(binary_node *node);

// successor gives the next successor of the tree.
// returns the successor node.
binary_node *successor(binary_node *node);

// predecessor gives the previous node of the tree in traversal order.
// returns the predecessor node.
binary_node *predecessor(binary_node *node);

// iterate through the tree in in-order traversal and prints out the node's
// values.
void subtree_iter(binary_node *node);

// print_root_to_leaf prints the
void print_pre_order(binary_node *root);

// free_tree frees the memory that is allocated for the given node's subtree.
void free_tree(binary_node *node);

// print_hr prints the visual line.
void print_hr(void);

void print_array(int keys_values[][2], int length);
