#ifdef _DLINKEDLIST_H_

#include <cstdlib>
#include <stdexcept>
//#include "dlinkedlist.h"
#include <string>


using namespace std;

template <class T>
// helper function for deep copy
// Used by copy constructor and operator=
void DLinkedList<T>::CopyList(const DLinkedList& ll) {
	/*
	if (ll.IsEmpty()) {
		front = NULL;
		back = NULL;
		size = 0;

	}

	else {
		Node<T>* current = ll.front;

		size = 0;
		front = NULL;
		back = NULL;

		while (current != NULL) {
			//create a new Node to enter into the new List
			Node<T>* newNode = new Node<T>;
			newNode->InsertBack(NULL);
			newNode->InsertFront(NULL);
			newNode->data = current->data;

			//add newNode to new List
			if (size == 0) {
				//new list is empty
				front = newNode;
				back = newNode;
			} else {
				//add newNode to end of new List
				back->InsertFront(newNode);
				newNode->InsertBack(back);
				back = back->next;	

			}

			++size;
			current = current->next;
			
				
		}
	}
	*/
}

template <class T>
// helper function for deep delete
// Used by destructor and copy/assignment
void DLinkedList<T>::DeleteList() {
	Node<T>* temp = front;

	//iterate through list deleting nodes
	while (temp != NULL) {
		temp = front->next;
		delete front;
		front = temp;
	}

	front = back = NULL;
}

template <class T>
// default constructor
DLinkedList<T>::DLinkedList() {
    front = nullptr;
    back = nullptr;
    size = 0;

}

template <class T>
// copy constructor, performs deep copy of list elements
DLinkedList<T>::DLinkedList(const DLinkedList& ll) {
	CopyList(ll);
}

template <class T>
// destructor
DLinkedList<T>::~DLinkedList() {
	DeleteList();
}

template <class T>
// Inserts an item at the front of the list
// POST:  List contains item at position 0
// PARAM: item = item to be inserted
void DLinkedList<T>::InsertFront(T item) {
	size++;
	Node<T> * nnode = new Node<T>(item);
	nnode->data = T(item);
	nnode->next = front;
	nnode->prev = NULL;
	if (IsEmpty()) {
		front = back = nnode;
	}else {
		front->prev = nnode;
		front = nnode;
	}
}

template <class T>
// Inserts an item at the back of the list
// POST:  List contains item at back
// PARAM: item = item to be inserted
void DLinkedList<T>::InsertBack(T item) {
  size++;
  Node<T>* nnode = new Node<T>(item);
  nnode->data = T(item);
  nnode->next = NULL;
  nnode->prev = back;
  if (IsEmpty()) {
  	front = back = nnode;
  }else {
    back->next = nnode;
    back = nnode;	
   }
}

template <class T>
// Inserts an item in position p (0-indexed)
// Throws exception for invalid index
// PRE:   0 <= p <= size
// POST:  List contains item at position p
// PARAM: item = item to be inserted, p = position where item will be inserted
void DLinkedList<T>::InsertAt(T item, int p) {
	//inesrt front
	if (p == 0) {
		InsertFront(item);
	}
	//insert back
	else if (p == size) {
		InsertBack(item);
	}

//insert between front and back
else 
     {
	size++;
	Node<T>* behind = front;
	for (int i = 0; i < p-1; i++) {
		behind = behind->next;
	}

	Node<T>* fro = front;
	for (int i = 0; i < p; i++) {
		fro = fro->next;
	}

	Node<T>* nnode = new Node<T>(item);

	nnode->next = fro;
	fro->prev = nnode;
	nnode->prev = behind;
	behind->next = nnode;
     }	

}

template <class T>
// Removes and returns an item from position p (0-indexed)
// Throws exception if list is empty or index invalid
// PRE:   0 <= p <= size
// POST:  Item is removed from list
// PARAM: p = position from where item will be removed

T DLinkedList<T>::RemoveAt(int p) {
    
}

template <class T>
// Removes duplicates from the list, preserving existing order of remaining items.
// The first occurrence of any duplicate (relative to the front of the list)
//   is the one which remains.
// We have not yet learned about efficiency so you may implement this in any way
//   as long as the resulting list satisfies the requirement above.
// PRE:   
// POST:  List contains no duplicates, front and back point to the appropriate nodes
// PARAM: 
void DLinkedList<T>::RemoveDuplicates() {

}

template <class T>
// Returns size of list
int DLinkedList<T>::Size() const {
    return size;
}

template <class T>
// Returns whether the list is empty
bool DLinkedList<T>::IsEmpty() const {
  return (front == NULL && back == NULL);
}

template <class T>
// Returns existence of item
bool DLinkedList<T>::Contains(T item) const {
  for(Node<T>* current = front; current != NULL; current = current->next){
		if (current->data == item) 
		{
			return true;
		}
	}
	return false;
}

template <class T>
// Returns item at index (0-indexed)
// Throws exception for invalid index
T DLinkedList<T>::ElementAt(int p) const {
   	Node<T>* current = front;
	for (int i = 0; i < p; i++) {
	  current = current->next;
	}
	return current->data;
}
#endif
