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
	Node<T>* current = ll.front;
	if (current == NULL) {
		front = NULL;
		back = NULL;
	} else {
		front = NULL;
		back = NULL;
		while (current != NULL) {
			InsertBack(current->data);
			current = current->next;
		}
	}
}

// destructor
template <class T>
SLinkedList<T>::~SLinkedList() {
	RemoveAll();
}

// MUTATORS

// Inserts an item at the front of the list
// POST:  List contains item at front
// PARAM: item = item to be inserted
template <class T>
void SLinkedList<T>::InsertFront(T item) {
	Node<T>* nnode = new Node<T>(item);
	nnode->data = T(item);
	nnode->next = front;
	if (IsEmpty()) {
		front = back = nnode;
	} else {
		front = nnode;
	}
	size++;
}

// Inserts an item at the back of the list
// POST:  List contains item at back
// PARAM: item = item to be inserted
template <class T>
void SLinkedList<T>::InsertBack(T item) {
	Node<T>* nnode = new Node<T>(item);
	nnode->data = T(item);
	nnode->next = NULL;
	if (IsEmpty()) {
		front = back = nnode;
	} else {
		back->next = nnode;
		back = nnode;
	}
	size++;
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
	Node<T>* current = front;
	while (current != NULL) {
		Node<T>* next = current->next;
		delete current;
		current = next;
	}
	front = NULL;
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
    return (front == NULL && back == NULL);
}

// Returns existence of item
template <class T>
bool SLinkedList<T>::Contains(T item) const {
	for (Node<T>* current = front; current != NULL; current = current->next) {
		if (current->data == item) {
			return true;
		}
	}
	return false;
}

// Returns a pointer to the in-place list item or NULL if item not found
template <class T>
T* SLinkedList<T>::Retrieve(T item) {
	return NULL;
}

// Returns a vector containing the list contents using push_back
template <class T>
vector<T> SLinkedList<T>::Dump() const {
	vector<T> v; 

	if (front != NULL && size > 0) {
		Node<T>* temp = front;
		v.push_back(temp->data); 
		while (temp->next != NULL) {
			temp = temp->next;
			v.push_back(temp->data);
		}
	}
	
	/*testing

	for (int i=0; i < size; i++) {
		cout << v[i] << " ";
	}*/
	return v;
}

// OVERLOADED OPERATORS

// must work in the following cases:
// list2 = list1 -> general case
// list2 = list2 -> should do nothing
template <class T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList<T>& ll) {
	if (this != &ll) {
		~SLinkedList();
		SLinkedList(ll);
		size = ll.size;
	}
	return *this;
}

#endif
