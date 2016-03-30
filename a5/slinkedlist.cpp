// File:        slinkedlist.h
// Author:      Pouria Delfanazari, Josh Vocal
// Date:        March 26, 2016
// Description: Implementation of a template singly-linked-list class for CMPT 225 assignment 5

#ifdef _SLINKEDLIST_H_

#include <cstdlib>
#include <string>
#include <vector>

#include "slinkedlist.h"

// default constructor
template <class T>
SLinkedList<T>::SLinkedList() {
    front = NULL;
    back = NULL;
    size = 0;
}

// copy constructor, performs deep copy of list elements
template <class T>
SLinkedList<T>::SLinkedList(const SLinkedList& ll) {

}

// destructor
template <class T>
SLinkedList<T>::~SLinkedList() {

}

// MUTATORS

// Inserts an item at the front of the list
// POST:  List contains item at front
// PARAM: item = item to be inserted
template <class T>
void SLinkedList<T>::InsertFront(T item) {

}

// Inserts an item at the back of the list
// POST:  List contains item at back
// PARAM: item = item to be inserted
template <class T>
void SLinkedList<T>::InsertBack(T item) {

}

// Removes the first occurrence of the supplied parameter
// Removes and returns true if found, otherwise returns false if parameter is not found or list is empty
template <class T>
bool SLinkedList<T>::Remove(T item) {
    return false;
}

// Removes all items in the list
template <class T>
void SLinkedList<T>::RemoveAll() {

}

// ACCESSORS

// Returns size of list
template <class T>
int SLinkedList<T>::Size() const {
    return size;
}

// Returns whether the list is empty
template <class T>
bool SLinkedList<T>::IsEmpty() const {
    return false;
}

// Returns existence of item
template <class T>
bool SLinkedList<T>::Contains(T item) const {
    return false;
}

// Returns a pointer to the in-place list item or NULL if item not found
template <class T>
T* SLinkedList<T>::Retrieve(T item) {

}

// Returns a vector containing the list contents using push_back
template <class T>
vector<T> SLinkedList<T>::Dump() const {

}

// OVERLOADED OPERATORS

// must work in the following cases:
// list2 = list1 -> general case
// list2 = list2 -> should do nothing
template <class T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList<T>& ll) {

}

#endif