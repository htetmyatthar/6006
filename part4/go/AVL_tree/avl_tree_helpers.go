package main

import (
	"errors"
	"fmt"
)

// BinaryNode represents a tree node with the height augmentation
// to create a AVL tree.
type BinaryNode struct {
	Key    int         // key of this node
	Value  int         // value of this node
	Height int         // height augmentation of this node
	Left   *BinaryNode // left child(to another node) of this node
	Right  *BinaryNode // right child (to another node) of this node
	Parent *BinaryNode // parent(ancestor) of this node
}

// BinaryNode.CalHeight returns the given node's height if exits.
// Returns -1 is the given node is nil.
func (treeNode *BinaryNode) CalHeight() int {
	if treeNode == nil {
		return -1
	}
	return treeNode.Height
}

// BinaryNode.Skew calculates the skew of the given node.
// Returns skew value if the given treeNode is a valid node.
func (treeNode *BinaryNode) Skew() (int, error) {
	if treeNode == nil {
		return 0, errors.New("Given treeNode is not a valid node <nil>.")
	}
	return treeNode.Right.CalHeight() - treeNode.Left.CalHeight(), nil
}

// BinaryNode.SubtreeUpdate updates the given node's augmentations.
// Returns an error if the given treeNode is nil.
func (treeNode *BinaryNode) SubtreeUpdate() error {
	if treeNode == nil {
		return errors.New("Given treeNode is nil.")
	}

	leftHeight := treeNode.Left.CalHeight()
	rightHeight := treeNode.Right.CalHeight()

	higherHeight := leftHeight
	if rightHeight > leftHeight {
		higherHeight = rightHeight
	}

	treeNode.Height = 1 + higherHeight

	return nil
}

// BinaryNode.SubtreeRotateRight right rotates the given subtree(using it's root node) treeNode
// Returns an error if the given treeNode is nil or if the given treeNode does not have left child.
// Overwrite's the treeNode(old root) with the newly rotated tree's root.
func (treeNode *BinaryNode) SubtreeRotateRight() (*BinaryNode, error) {
	if treeNode == nil {
		return nil, errors.New("Given treeNode is nil.")
	} else if treeNode.Left == nil {
		return nil, errors.New("Given treeNode has no left subtree.")
	}

	// remeber the ancestor
	ancestor := treeNode.Parent

	// initialize for rotating
	newRoot := treeNode.Left
	newRootRightSubtree := newRoot.Right

	// change the root
	newRoot.Parent = ancestor
	treeNode.Parent = newRoot

	// relink the tree
	treeNode.Left = newRootRightSubtree
	if newRootRightSubtree != nil {
		newRootRightSubtree.Parent = treeNode
	}
	newRoot.Right = treeNode

	// update the child of the ancestor
	if ancestor != nil {
		if ancestor.Left == treeNode {
			ancestor.Left = newRoot
		}
		if ancestor.Right == treeNode {
			ancestor.Right = newRoot
		}
	}

	// update augmentations
	treeNode.SubtreeUpdate()
	newRoot.SubtreeUpdate()

	// overwrite the root
	// treeNode = newRoot
	// NOTE: WE CAN'T OVERRIDE IT. since golang is pass by value even the pointers.

	return newRoot, nil
}

// BinaryNode.SubtreeRotateLeft left rotates the given subtree(using it's root node) treeNode
// Returns an error if the given treeNode is nil or if the given treeNode does not have right child.
// Overwrite's the treeNode(old root) with the newly rotated tree's root.
func (treeNode *BinaryNode) SubtreeRotateLeft() (*BinaryNode, error) {
	if treeNode == nil {
		return nil, errors.New("Given treeNode is nil.")
	} else if treeNode.Right == nil {
		return nil, errors.New("Given treeNode has no right subtree.")
	}

	// remeber the ancestor
	ancestor := treeNode.Parent

	// initialize for rotation
	newRoot := treeNode.Right
	newRootLeftSubtree := newRoot.Left

	// change the root
	newRoot.Parent = ancestor
	treeNode.Parent = newRoot

	// relink the tree
	treeNode.Right = newRootLeftSubtree
	if newRootLeftSubtree != nil {
		newRootLeftSubtree.Parent = treeNode
	}
	newRoot.Left = treeNode

	// update the child fo the ancestor
	if ancestor != nil {
		if ancestor.Left == treeNode {
			ancestor.Left = treeNode
		}
		if ancestor.Right == treeNode {
			ancestor.Right = treeNode
		}
	}

	// update the augmentations
	treeNode.SubtreeUpdate()
	newRoot.SubtreeUpdate()

	// overwrite the root.
	// treeNode = newRoot
	// NOTE: CAN'T OVERRIDE
	return newRoot, nil
}

// BinaryNode.Rebalance balances the given treeNode using the skew.
// Returns an error if the given treeNode is nil.
// Returns nil if there's no error happened during rebalancing.
func (treeNode *BinaryNode) Rebalance() (*BinaryNode, error) {
	if treeNode == nil {
		return nil, errors.New("Cannot rebalance the nil treeNode.")
	}

	treeNodeSkew, err := treeNode.Skew()
	if err != nil {
		return nil, err
	}

	if treeNodeSkew == 2 {
		// calculating right child's skew
		rightChildSkew, err := treeNode.Right.Skew()
		if err != nil {
			return nil, err
		}

		// check the right child skew to rotate if necessary
		if rightChildSkew < 0 {
			newRoot, err := treeNode.Right.SubtreeRotateRight()
			if err != nil {
				return nil, err
			}
			treeNode.Right = newRoot
		}
		newRoot, err := treeNode.SubtreeRotateLeft()
		if err != nil {
			return nil, err
		}
		return newRoot, nil
	} else if treeNodeSkew == -2 {
		// calculating the left child's skew
		leftChildSkew, err := treeNode.Left.Skew()
		if err != nil {
			return nil, err
		}

		// check the left child skew to rotate if necessary
		if leftChildSkew > 0 {
			newRoot, err := treeNode.Left.SubtreeRotateLeft()
			if err != nil {
				return nil, err
			}
			treeNode.Left = newRoot
		}

		newRoot, err := treeNode.SubtreeRotateRight()
		return newRoot, nil
	}
	return treeNode, nil
}

// BinaryNode.Maintain maintains the given treeNode's augmentations.
// Recursively maintain on parents if there's any.
// Returns an error if the given treeNode is nil.
// Overwrites the given treeNode with the newly maintained root node.
func (treeNode *BinaryNode) Maintain() (*BinaryNode, error) {
	if treeNode == nil {
		return nil, errors.New("Given treeNode is nil.")
	}
	balancedNode, err := treeNode.Rebalance()
	if err != nil {
		return nil, err
	}
	err = balancedNode.SubtreeUpdate()
	if err != nil {
		return nil, err
	}

	// maintain the ancestors
	if balancedNode.Parent != nil {
		maintainedNode, err := balancedNode.Parent.Maintain()
		if err != nil {
			return nil, err
		}
		return maintainedNode, nil
	}
	return balancedNode, nil
}

// BinaryNode.SubtreeFirst finds and returns the first node in traversal order.
// Returns nil if given treeRoot is nil.
func (treeRoot *BinaryNode) SubtreeFirst() *BinaryNode {
	if treeRoot == nil {
		return nil
	}

	if treeRoot.Left != nil {
		return treeRoot.Left.SubtreeFirst()
	}
	return treeRoot
}

// BinaryNode.SubtreeLast finds and returns the last node in traversal order.
// Returns nil if given treeRoot is nil.
func (treeRoot *BinaryNode) SubtreeLast() *BinaryNode {
	if treeRoot == nil {
		return nil
	}

	if treeRoot.Right != nil {
		return treeRoot.Right.SubtreeLast()
	}
	return treeRoot
}

// BinaryNode.Successor finds and returns the successor node in traversal order.
// Returns nil if given treeNode is nil or there's no successor.
func (treeNode *BinaryNode) Successor() *BinaryNode {
	if treeNode == nil {
		return nil
	}

	if treeNode.Right != nil {
		return treeNode.Right.SubtreeFirst()
	}

	for treeNode.Parent != nil {
		if treeNode == treeNode.Parent.Left {
			return treeNode.Parent
		}
		treeNode = treeNode.Parent
	}
	return nil
}

// BinaryNode.Predecessor finds and returns the predecessor node in traversal order.
// Returns nil if given treeNode is nil or there's no predecessor.
func (treeNode *BinaryNode) Predecessor() *BinaryNode {
	if treeNode == nil {
		return nil
	}

	if treeNode.Left != nil {
		return treeNode.Left.SubtreeLast()
	}

	for treeNode.Parent != nil {
		if treeNode == treeNode.Parent.Right {
			return treeNode.Parent
		}
		treeNode = treeNode.Parent
	}
	return nil
}

// BinaryNode.InsertBefore inserts a new binary node with the given value and key as a predecessor of
// given node, while updating treeRoot with the balanced and maintained new root.
func (treeRoot *BinaryNode) InsertBefore(node *BinaryNode, value int, key int) error {
	if treeRoot == nil {
		return errors.New("Given treeRoot is nil.")
	} else if node == nil {
		return errors.New("Given (before) node is nil.")
	}

	newNode := &BinaryNode{Value: value, Key: key}

	if node.Left != nil {
		// SubtreeLast returns nil only when the caller node is nil.
		node = node.Left.SubtreeLast()
		node.Right = newNode
		newNode.Parent = node
		return nil
	} else {
		node.Left = newNode
		newNode.Parent = node
	}
	node.Maintain()
	// node is the new root now.
	treeRoot = node
	return nil
}

// BinaryNode.InsertAfter inserts a new binary node with the given value and key as a successor of
// given node, while updating treeRoot with the balanced and maintained new root.
func (treeRoot *BinaryNode) InsertAfter(node *BinaryNode, value int, key int) error {
	if treeRoot == nil {
		return errors.New("Given treeRoot is nil.")
	} else if node == nil {
		return errors.New("Given (after) node is nil.")
	}

	newNode := &BinaryNode{Value: value, Key: key}

	if node.Right != nil {
		node = node.Right.SubtreeFirst()
		node.Left = newNode
		newNode.Parent = node
	} else {
		node.Right = newNode
		newNode.Parent = node
	}
	node.Maintain()
	// node is the new root now.
	treeRoot = node
	return nil
}

// BinaryNode.DeleteNode deletes the given node in the given treeRoot and returns the maintained tree and the deleted node.
// Returns error if the treeRoot is nil or node is nil.
// After deleting the given node the tree is balanced and maintained any augmentations.
func (treeRoot *BinaryNode) DeleteNode(node *BinaryNode) (*BinaryNode, *BinaryNode, error) {
	if treeRoot == nil {
		return nil, nil, errors.New("Given treeRoot is nil.")
	} else if node == nil {
		return nil, nil, errors.New("Trying to delete node that doesn't exit.")
	}

	// the node is a leaf
	if node.Left == nil && node.Right == nil {

		if node.Parent.Left == node {
			node.Parent.Left = nil
			maintainedNode, err := node.Parent.Maintain()
			if err != nil {
				return nil, nil, err
			}
			node.Parent = nil
			return maintainedNode, node, nil
		}

		node.Parent.Right = nil
		maintainedNode, err := node.Parent.Maintain()
		if err != nil {
			return nil, nil, err
		}
		node.Parent = nil
		return maintainedNode, node, nil

		// this node is an ancestor check if is the node has the left child
	} else if node.Left != nil {
		predecessor := node.Predecessor()
		tempValue := predecessor.Value
		predecessor.Value = node.Value
		node.Value = tempValue
		return treeRoot.DeleteNode(predecessor)

		// this node is an ancestor alleast has right child.
	} else {
		successor := node.Successor()
		tempValue := successor.Value
		successor.Value = node.Value
		node.Value = tempValue
		return treeRoot.DeleteNode(successor)
	}
}

// BinaryNode.Insert inserts a new node to the given tree and maintained the augmentations.
// Also maintains the property of AVL tree.
func (treeRoot *BinaryNode) Insert(key int, value int) (*BinaryNode, error) {
	if treeRoot != nil {
		treeRoot.subtreeInsert(key, value)
		maintainedNode, err := treeRoot.Maintain()
		if err != nil {
			return nil, err
		}
		return maintainedNode, nil
	}

	newNode := &BinaryNode{Value: value, Key: key}
	treeRoot = newNode
	maintainedNode, err := treeRoot.Maintain()
	if err != nil {
		return nil, err
	}
	return maintainedNode, nil
}

// BinaryNode.subtreeInsert inserts a new node with the given key and value
// to the given treeRoot. Acts as a helper function to BinaryNode.Insert
// insert a new node to it's corresponding key.
func (treeRoot *BinaryNode) subtreeInsert(key int, value int) {
	if key < treeRoot.Key {
		if treeRoot.Left != nil {
			treeRoot.Left.subtreeInsert(key, value)
		} else {
			treeRoot.InsertBefore(treeRoot, value, key)
		}
	} else if key > treeRoot.Key {
		if treeRoot.Right != nil {
			treeRoot.Right.subtreeInsert(key, value)
		} else {
			treeRoot.InsertAfter(treeRoot, value, key)
		}
	} else {
		treeRoot.Key = key
		treeRoot.Value = value
	}
}

// BinaryNode.Find finds the node with the given key in the given treeRoot.
// Returns an error if the given treeRoot is nil or the key is invalid.
// Returns nil if the node with the given key doesn't exits.
func (treeRoot *BinaryNode) Find(key int) (*BinaryNode, error) {
	if treeRoot == nil {
		return nil, errors.New("Given treeRoot is nil.")
	} else if key < 1 {
		return nil, errors.New("Invalid key.")
	}

	return treeRoot.findRecursion(key), nil
}

// BinaryNode.findRecursion finds the node with given key in the given treeRoot
// and returns it assuming given tree is not empty and the given key is valid.
// Acts as a helper function for BinaryNode.Find.
// Returns nil if the node with the given key doesn't exits.
func (treeRoot *BinaryNode) findRecursion(key int) *BinaryNode {
	if treeRoot == nil {
		return nil
	}
	if key < treeRoot.Key {
		return treeRoot.Left.findRecursion(key)
	} else if key > treeRoot.Key {
		return treeRoot.Right.findRecursion(key)
	} else {
		return treeRoot
	}
}

// BinaryNode.Delete deletes the node with the given key in the given treeRoot.
// Returns an error if the node with the given key doesn't exit in the given tree
// or the tree is nil or the given key is an invalid key.
// Returns the deleted node's value.
func (treeRoot *BinaryNode) Delete(key int) (*BinaryNode, int, error) {
	nodeToDelete, err := treeRoot.Find(key)
	if err != nil {
		return nil, 0, err
	}

	if nodeToDelete == nil {
		return nil, 0, errors.New("Given key doesn't associated to any node in this tree.")
	}

	newTree, deletedNode, err := treeRoot.DeleteNode(nodeToDelete)
	if err != nil {
		return nil, 0, err
	}
	return newTree, deletedNode.Value, nil
}

func (treeRoot *BinaryNode) Build(node [][]int) {
	for i := range node {
		treeRoot.Insert(node[i][0], node[i][1])
	}
}

func (treeRoot *BinaryNode) BuildTree(keyValues [][]int) (*BinaryNode, error) {
	if len(keyValues) == 0 || keyValues == nil {
		return nil, errors.New("Cannot build empty tree.")
	}
	root := treeRoot.buildTreeRecursion(keyValues, 0, len(keyValues)-1)
	return root, nil
}

func (treeRoot *BinaryNode) buildTreeRecursion(keyValues [][]int, left int, right int) *BinaryNode {
	if left > right {
		return nil
	}

	middle := (left + right) / 2

	root := &BinaryNode{Value: keyValues[middle][1], Key: keyValues[middle][0]}

	root.Left = root.buildTreeRecursion(keyValues, left, middle-1)
	if root.Left != nil {
		root.Left.Parent = root
		root.SubtreeUpdate()
	}

	root.Right = root.buildTreeRecursion(keyValues, middle+1, right)
	if root.Right != nil {
		root.Right.Parent = root
		root.SubtreeUpdate()
	}

	return root
}

// BinaryNode.PrintTraversal prints the given subtree in in-order traversal order.
func (treeRoot *BinaryNode) PrintTraversal() {
	if treeRoot != nil {
		treeRoot.Left.PrintTraversal()
		fmt.Println("value: ", treeRoot.Value, "key: ", treeRoot.Key, "height: ", treeRoot.Height)
		treeRoot.Right.PrintTraversal()
	}
}

// BinaryNode.PrintPreOrder prints the given subtree in preorder traversal order.
func (treeRoot *BinaryNode) PrintPreOrder() {
	if treeRoot != nil {
		fmt.Println("value: ", treeRoot.Value, "key: ", treeRoot.Key, "height: ", treeRoot.Height)
		if treeRoot.Parent != nil {
			fmt.Println("parent: ", treeRoot.Parent.Key)
		}

		treeRoot.Left.PrintPreOrder()
		treeRoot.Right.PrintPreOrder()
	}
}
