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
        cNode->left = CopyTree(sourcenode->left, cNode);
        cNode->right = CopyTree(sourcenode->right, cNode);

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
/*
Used this as reference: http://stackoverflow.com/questions/6723488/red-black-tree-deletion-algorithm
*/
template <class T>
void RedBlackTree<T>::RBDeleteFixUp(Node<T>* x, Node<T>* xparent, bool xisleftchild) {
    while (x != root && x->is_black) {
        Node<T>* w;
        if (xisleftchild) {
            w = xparent->right;
            if (!x->is_black) {
                w->is_black = true;
                xparent->is_black = false;
                LeftRotate(xparent);
                w = xparent->right;
            }

            if (w->left->is_black && w->right->is_black) {
                w->is_black = false;
                x = xparent;
                xparent = x->p;
                xisleftchild = (xparent != NULL && x == xparent->left);
            } else {
                if (w->right->is_black) {
                    w->left->is_black = true;
                    w->is_black = false;
                    RightRotate(w);
                    w = xparent->right;
                }

                w->is_black = xparent->is_black;
                xparent->is_black = true;
                if (w->right != NULL) {
                    w->right->is_black = true;
                }
                LeftRotate(xparent);
                x = root;
                xparent = NULL;
            }
        }
        else {
            w = xparent->left;
            if (!w->is_black) {
                w->is_black = true;
                xparent->is_black = false;
                RightRotate(xparent);
                w = xparent->left;
            }

            if (w->right->is_black && w->left->is_black) {
                w->is_black = false;
                x = xparent;
                xparent = x->p;
                xisleftchild = (xparent != NULL && x == xparent->left);
            } else {
                if (w->left->is_black) {
                    w->right->is_black = true;
                    w->is_black = false;
                    LeftRotate(w);
                    w = xparent->left;
                }

                w->is_black = xparent->is_black;
                xparent->is_black = true;
                if (w->left != NULL) {
                    w->left->is_black = true;
                }
                RightRotate(xparent);
                x = root;
                xparent = NULL;
            }

        }
    }
    x->is_black = true;
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
    size = rbtree.size;
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
    //Case 1
    if (this != &rbtree) {
        //Case 2
        if (root != NULL)
            RemoveAll(root);
        //Case 3
        if (rbtree.root == NULL)
            root = NULL;
        else
            CopyTree(rbtree.root, NULL);
    }
    return *this;
}

// Accessor functions

// Calls BSTInsert and then performs any necessary tree fixing.
// If item already exists, do not insert and return false.
// Otherwise, insert, increment size, and return true.
template <class T>
bool RedBlackTree<T>::Insert(T item) { 
    if (Search(item) == false) { 			//checking for duplicates, carry on if not found 
        Node<T> *x = BSTInsert(item); 			//insert the node like a BST
        Node<T> *y;
        x->is_black = false; 				//colour the node to make it a RBT 
        while (x->p != NULL and x->p->is_black == false) {
            if (x->p == x->p->p->left) {			//x's parent is on the left --> y is x's uncle
                y = x->p->p->right;
                if (y->is_black == false || y == NULL) {
                    x->p->is_black = true;
                    if (y != NULL) {				//case 1
                        y->is_black = true;
                    }
                    x->p->p->is_black = false;
                    x = x->p->p; 					//move x up one level
                }
                else {
                    if (x == x->p->right) {			//case 2
                        x = x->p; 					//y is black, move x up a level and rotate from x
                        LeftRotate(x);
                    }
                    x->p->is_black = true; 			//case 3
                    x->p->p->is_black = false;
                    RightRotate(x->p->p);
                }
            }
            else {
                y = x->p->p->left; 				//same as the first comment, left and right exchanged
                if (y == NULL || y->is_black == false) {
                    x->p->is_black = true;
                    if (y != NULL) {
                        y->is_black = true;
                    }
                    x->p->p->is_black = false;
                    x = x->p->p;
                }
                else {
                    if (x == x->p->left) {			//same as case 2, left and right exchanged 
                        x = x->p;
                        RightRotate(x);
                    }
                    x->p->is_black = true; 
                    x->p->p->is_black = false;
                    LeftRotate(x->p->p);
                }
            }
        }
        root->is_black = true; 				//colour the root black to make it a RBT
        size++;
        return true;
    }
    else {
        return false;
    }
}



// Removal of an item from the tree.
// Must deallocate deleted node after RBDeleteFixUp returns
template <class T>
bool RedBlackTree<T>::Remove(T item) {
  //Check if the item is the RBT and set it to nd.
  if (Search(item) == false) {
      return false;
  } else {
      Node<T>* nd = root;
      while (nd->data != item) {
          if (item < nd->data) {
              nd = nd->left;
          } else {
              nd = nd->right;
          }
      }

      Node<T>* y;
      if (nd->left == NULL || nd->right == NULL) {
          y = nd;
      } else {
          y = Predecessor(nd);
      }

      Node<T>* x;
      if (y->left != NULL) {
          x = y->left;
      } else {
          x = y->right;
      }
      if (x != NULL) {
          x->p = y->p;
      }

      Node<T>* xparent = y->p;
      bool yIsLeft = false;
      if (y->p == NULL){
          root = x;
      } else if (y == y->p->left) {
          y->p->left = x;
          yIsLeft = true;
      } else {
          y->p->right = x;
          yIsLeft = false;
      }

      if (y != nd) {
          nd->data = y->data;
      }

      if (y->is_black == true) {
          RBDeleteFixUp(nd, xparent, yIsLeft);
      }
      
      size--;
      return true;
  }
}

// deletes all nodes in the tree. Calls recursive helper function.
template <class T>
void RedBlackTree<T>::RemoveAll() {
    RemoveAll(root);
    size = 0;
}

// returns the number of items in the tree
template <class T>
int RedBlackTree<T>::Size() const {
    return size; 
}

// returns the height of the tree, from root to deepest null child. Calls recursive helper function.
// Note that an empty tree should have a height of 0, and a tree with only one node will have a height of 1.
template <class T>
int RedBlackTree<T>::Height() const {
    return CalculateHeight(root);
}

#endif
