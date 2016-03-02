 // File:        redblacktree.cpp
// Author:      Pouria Delfanazari, Josh Vocal
// Date:        2016-02-27
// Description: Implementation of a RedBlackTree class and template Node class for use with CMPT 225 assignment #4

#ifdef _REDBLACKTREE_H_

#include <cstdlib>
#include <stdexcept>
#include <string>

#include "redblacktree.h"

using namespace std;

// recursive helper function for deep copy
// creates a new node "thisnode" based on sourcenode's contents, links back to parentnode,
//   and recurses to create left and right children
template <class T>
Node<T>* RedBlackTree<T>::CopyTree(Node<T>* sourcenode, Node<T>* parentnode) {
	
	//Base Case
	if (sourcenode == nullptr) {
		return NULL;
	} else {
		//Recursive Case
		//Create a new node cNode and copy sourcenode's contents in preorder
		Node<T>* cNode = new Node<T>(sourcenode->data);
		cNode->p = parentnode;
		cNode->is_black = sourcenode->is_black;
		//Recursively copy the left and right subtrees
		cNode->left = CopyTree(sourcenode->left, cNode->p);
		cNode->right = CopyTree(sourcenode->right, cNode->p);

		return cNode;
	} 
}

// recursive helper function for tree deletion
// deallocates nodes in post-order
template <class T>
void RedBlackTree<T>::RemoveAll(Node<T>* node) {
	if (node != nullptr) {
		RemoveAll(node->left);
		RemoveAll(node->right);
		delete node;
	}
}

// Tree fix, performed after removal of a black node
// Note that the parameter x may be NULL
template <class T>
void RedBlackTree<T>::RBDeleteFixUp(Node<T>* x, Node<T>* xparent, bool xisleftchild) {

}

// Calculates the height of the tree
// Requires a traversal of the tree, O(n)
template <class T>
int RedBlackTree<T>::CalculateHeight(Node<T>* node) const {
	if (node == nullptr) {
		return 0;
	} else {
		return 1 + max(CalculateHeight(node->left), CalculateHeight(node->right));
	}
}

// default constructor
template <class T>
RedBlackTree<T>::RedBlackTree() {
	size = 0;
	root = nullptr;		
}

// copy constructor, performs deep copy of parameter
template <class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T>& rbtree) {
	root = CopyTree(rbtree.root, NULL);
}

// destructor
// Must deallocate memory associated with all nodes in tree
template <class T>
RedBlackTree<T>::~RedBlackTree() {
	RemoveAll(root);
}

// overloaded assignment operator
template <class T>
RedBlackTree<T>& RedBlackTree<T>::operator=(const RedBlackTree<T>& rbtree) {
	return *this;
}

// Accessor functions

// Calls BSTInsert and then performs any necessary tree fixing.
// If item already exists, do not insert and return false.
// Otherwise, insert, increment size, and return true.
template <class T>
bool RedBlackTree<T>::Insert(T item) {
	return false;
}

// Removal of an item from the tree.
// Must deallocate deleted node after RBDeleteFixUp returns
template <class T>
bool RedBlackTree<T>::Remove(T item) {
	return false;
}

// deletes all nodes in the tree. Calls recursive helper function.
template <class T>
void RedBlackTree<T>::RemoveAll() {

}

// returns the number of items in the tree
template <class T>
int RedBlackTree<T>::Size() const {
	return this->size; 
}

// returns the height of the tree, from root to deepest null child. Calls recursive helper function.
// Note that an empty tree should have a height of 0, and a tree with only one node will have a height of 1.
template <class T>
int RedBlackTree<T>::Height() const {
	return CalculateHeight(root);
}

#endif
