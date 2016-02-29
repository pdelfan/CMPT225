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
Node<T>* RedBlackTree::CopyTree(Node<T>* thisnode, Node<T>* sourcenode, Node<T>* parentnode) {

}

// recursive helper function for tree deletion
// deallocates nodes in post-order
template <class T>
void RedBlackTree::RemoveAll(Node<T>* node) {

}

// performs BST insertion and returns pointer to inserted node
// Note that this should only be called if item does not already exist in the tree
// Does not increase tree size.
template <class T>
Node<T>* RedBlackTree::BSTInsert(T item) {
}

// helper function for in-order traversal
template <class T>
void RedBlackTree::InOrder(const Node<T>* node, T* arr, int arrsize, int& index) const {

}

// rotation functions
template <class T>
void RedBlackTree::LeftRotate(Node<T>* node) {

}
template <class T>
void RedBlackTree::RightRotate(Node<T>* node) {

}

// get the predecessor of a node
template <class T>
Node<T>* RedBlackTree::Predecessor(Node<T>* node) {

}

// Tree fix, performed after removal of a black node
// Note that the parameter x may be NULL
template <class T>
void RedBlackTree::RBDeleteFixUp(Node<T>* x, Node<T>* xparent, bool xisleftchild) {

}

// Calculates the height of the tree
// Requires a traversal of the tree, O(n)
template <class T>
int RedBlackTree::CalculateHeight(Node<T>* node) const {

}

// default constructor
RedBlackTree::RedBlackTree() {

}

// copy constructor, performs deep copy of parameter
template <class T>
RedBlackTree::RedBlackTree(const RedBlackTree<T>& rbtree) {

}

// destructor
// Must deallocate memory associated with all nodes in tree
RedBlackTree::~RedBlackTree() {

}

// overloaded assignment operator
template <class T>
RedBlackTree::RedBlackTree<T>& operator=(const RedBlackTree<T>& rbtree) {

}

// Accessor functions

// Calls BSTInsert and then performs any necessary tree fixing.
// If item already exists, do not insert and return false.
// Otherwise, insert, increment size, and return true.
template <class T>
bool RedBlackTree::Insert(T item) {

}

// Removal of an item from the tree.
// Must deallocate deleted node after RBDeleteFixUp returns
template <class T>
bool RedBlackTree::Remove(T item) {

}

// Returns existence of item in the tree.
// Return true if found, false otherwise.
template <class T>
bool RedBlackTree::Search(T item) const {

}

// Searches for item and returns a pointer to the node contents so the
//   value may be accessed or modified
// Use with caution! Do not modify the item's key value such that the
//   red-black / BST properties are violated.
template <class T>
T* RedBlackTree::Retrieve(T item) {

}

// deletes all nodes in the tree. Calls recursive helper function.
void RedBlackTree::RemoveAll();

// performs an in-order traversal of the tree
// arrsize is the size of the returned array (equal to tree size attribute)
template <class T>
T* RedBlackTree::Dump(int& arrsize) const {

}

// returns the number of items in the tree
int RedBlackTree::Size() const {

}

// returns the height of the tree, from root to deepest null child. Calls recursive helper function.
// Note that an empty tree should have a height of 0, and a tree with only one node will have a height of 1.
int Height() const {
	
}

#endif