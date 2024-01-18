#include "utils.h"

int main(void) {
  int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int length = sizeof(values) / sizeof(values[0]);
  tree_node *tree = build_tree(values, length);

  printf("In-order traversal: \n");
  in_order_traversal(tree);
  printf("\n");
  print_hr();

  printf("Using print_tree_traversal: \n");
  print_tree_traversal(tree);
  printf("\n");
  print_hr();

  printf("From root to leaf.");
  print_pre_order(tree);
  printf("\n");
  print_hr();

  printf("Testing traversal order functions.\n");
  printf("Last tree node: %d\n", last_tree_node(tree)->value);
  printf("Predecessor node of root %d: %d\n", tree->value, tree_predecessor(tree)->value);
  print_hr();

  printf("inserting 99 after a node that has right child(root): \nBefore: \n");
  print_tree_traversal(tree);
  printf("\n");
  insert_after_node(tree, 99);
  printf("After: \n");
  print_tree_traversal(tree);
  printf("\n");
  print_hr();

  printf("inserting 88 after a node that doesn't have right child(last leave): \nBefore: \n");
  print_tree_traversal(tree);
  printf("\n");
  insert_after_node(last_tree_node(tree), 88);
  printf("After: \n");
  print_tree_traversal(tree);
  printf("\n");
  print_hr();

  printf("inserting 77 before a node that has left child(root): \nBefore: \n");
  print_tree_traversal(tree);
  printf("\n");
  insert_before_node(tree, 77);
  printf("After: \n");
  print_tree_traversal(tree);
  printf("\n");
  print_hr();

  printf("inserting 33 before a node that doesn't have left child(first node): \nBefore: \n");
  print_tree_traversal(tree);
  printf("\n");
  insert_before_node(first_tree_node(tree), 33);
  printf("After: \n");
  print_tree_traversal(tree);
  printf("\n");
  print_hr();

  printf("deleting a leaf(first node now due to 33 insertion.)\nBefore: \n");
  print_tree_traversal(tree);
  printf("\n");
  delete_tree_node(first_tree_node(tree));
  printf("After: \n");
  print_tree_traversal(tree);
  printf("\n");
  print_hr();

  printf("deleting an item that only has right subtree(parent of root's predecessor).\nBefore: \n");
  print_tree_traversal(tree);
  printf("\n");
  delete_tree_node(tree_predecessor(tree)->parent);
  printf("After: \n");
  print_tree_traversal(tree);
  printf("\n");
  print_hr();

  printf("deleting an item that has left subtree(root).\nBefore: \n");
  print_tree_traversal(tree);
  printf("\n");
  delete_tree_node(tree);
  printf("After: \n");
  print_tree_traversal(tree);
  printf("\n");
  print_hr();


  printf("From root to leaf.");
  print_pre_order(tree);
  printf("\n");
  print_hr();
  free_tree_recursive(tree);
}
