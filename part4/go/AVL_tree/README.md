# Introduction

This is the section for creating an AVL tree and it's complete api interface.

## File Structure

- avl_tree_main.go file contains the usage of AVL tree while implementing.

- avl_tree_helpers.go file contains *all* the functions to create an use an AVL tree.

- avl_tree_test.go file contains test cases for AVL_tree

## Specification

- Implement the completet AVL_tree interface.

## Implementation notes

- Remeber that golang's function parameters are always pass by values.

## Interface

- 
`BinaryNode.Build()` method builds a new AVL_tree naively in linear time complexity $O(n)$.

`BinaryNode.BuildTree()` method builds a new AVL_tree in maintained, balanced in linear time compilexity $O(nlogn)$.

`BinaryNode.CalHeight()` method returns the height of the caller node in constant time complexity $O(1)$.

`BinaryNode.SubtreeUpdate()` method update augmentations of the caller node in constant time complexity $O(1)$.

`BinaryNode.Skew()` method calculates and returns the skew of the caller node in constant time complexity $O(1)$.

`BinaryNode.Delete()` method deletes the node with given key in logarithmic time complexity $O(logn)$.

`BinaryNode.DeleteNode()` method deletes the given node in logarithmic time complexity $O(logn)$.

`BinaryNode.Find()` method finds the node with the given in logarithmic time complexity $O(logn)$.

`BinaryNode.Insert()` method inserts a new node to the given tree and maintain the augmentations in logarithmic time complexity $O(logn)$.

`BinaryNode.InsertAfter()` method inserts a new binary node with the given value and the key as a successor of the given node in logarithmic time complexity $O(logn)$

`BinaryNode.InsertBefore()` method inserts a new binary node with the given value and the key as a predesuccessor of the given node in logarithmic time complexity $O(logn)$.

`BinaryNode.Maintain()` method matains the caller treeNode(subtreeaugmentation, balancing) in logarithmic time complexity $O(logn)$.

`BinaryNode.Predecessor()` method returns the predecessor of the caler node in logarithmic time complexity $O(logn)$.

`BinaryNode.PrintPreOrder()` method print out the complete tree of the caller node in pre-order traversal order to the console in linear time complexity $O(n)$.

`BinaryNode.PrintTraversal()` method print out the complete tree of the caller node in in-order traversal order to the console in linear time complexity $O(n)$.

`BinaryNode.Rebalance()` method balances the caller tree in logarithmic time complexity $O(logn)$.

`BinaryNode.SubtreeFirst()` method finds the first node in the in-order traversal order of the caller subtree in logarithmic time complexity $O(logn)$.

`BinaryNode.SubtreeLast()` method finds the last node in the in-order traversal order of the caller subtree in logarithmic time complexity $O(logn)$.

`BinaryNode.SubtreeRotateLeft()` method left rotates the caller node and returns the maintained root node in constant time complexity $O(1)$.

`BinaryNode.SubtreeRotateRight()` method right rotates the caller node and returns the maintained root node in constant time complexity $O(1)$.

`BinaryNode.Successor()` method returns the successor of the caller node in logarithmic time complexity $O(logn)$.

You can compile or run the source code using the `GO` tools from the directory of these go files.

*E.g. 6006/part1/go/AVL_tree$*

*To compile source code*
```bash
go build .
```

*Running go binary*
```bash
./AVL_tree
```

*To compile the tests*
```bash
go test -c
```

*Running test binary*
```bash
./AVL_tree.test -test.v
```

*To run the source code without compiling*
```bash
go run .
```

*To run the tests without compiling*
```bash
go test -v .
```

*To check the documentation*
```bash
go doc -all
```
Depending on your os, and your computer, the commands might be a little different.

# References

Erik Demaine, Json Ku, Justin Solomon.MIT 6006 Introduction to algorithms. Spring2020. Massachusetts Institute of Technology: MIT OpenCouseWare, https://ocw.mit.edu/. License: Creative Commons BY-NC-SA.
