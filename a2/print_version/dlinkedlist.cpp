#ifdef _DLINKEDLIST_H_

#include <cstdlib>
#include <stdexcept>
//#include "dlinkedlist.h"
#include <string>
#include <iostream>

using namespace std;

template <class T>
// helper function for deep copy
// Used by copy constructor and operator=
void DLinkedList<T>::CopyList(const DLinkedList& ll) {


}

template <class T>
// helper function for deep delete
// Used by destructor and copy/assignment
void DLinkedList<T>::DeleteList() {

}

template <class T>
// default constructor
DLinkedList<T>::DLinkedList() {
front = NULL;
back = NULL;
size = 0;
}

template <class T>
// copy constructor, performs deep copy of list elements
DLinkedList<T>::DLinkedList(const DLinkedList& ll) {

}

template <class T>
// destructor
DLinkedList<T>::~DLinkedList() {

}

template <class T>
// Inserts an item at the front of the list
// POST:  List contains item at position 0
// PARAM: item = item to be inserted
void DLinkedList<T>::InsertFront(T item) {

	size++;
	Node<T>* nnode = new Node<T>(item);
	nnode->data = T(item);
	nnode->next = front;
	nnode->prev = NULL;
	if (IsEmpty()) {
		front = back = nnode;
	}else {
		front->prev = nnode;
		front = nnode;
	}

	//for showing 

	cout<< "Added " << nnode->data <<  " in front.\n";

	cout << "List: ";
	for(Node<T>* current = front;
		current != NULL; 
		current = current->next){

		cout<< current->data << " ";
	}
cout << endl;

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

    //for showing

   cout << "Added " << nnode->data << " one to back. Should Have it at the back: \n";
   cout << "List: ";
	for(Node<T>* current = front;
		current != NULL; 
		current = current->next){

		cout<< current->data << " ";
	}
cout << endl;

}

template <class T>
// Inserts an item in position p (0-indexed)
// Throws exception for invalid index
// PRE:   0 <= p <= size
// POST:  List contains item at position p
// PARAM: item = item to be inserted, p = position where item will be inserted
void DLinkedList<T>::InsertAt(T item, int p) {
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

	/*nnode->next = behind;
	behind->prev = nnode;
	fro->next = nnode;
	nnode->prev = fro;*/

	nnode->next = fro;
	fro->prev = nnode;
	nnode->prev = behind;
	behind->next = nnode;
	
	for(Node<T>* current = front; current != NULL; 
		current = current->next){

		cout<< current->data << " ";
	}


}

template <class T>
// Removes and returns an item from position p (0-indexed)
// Throws exception if list is empty or index invalid
// PRE:   0 <= p <= size
// POST:  Item is removed from list
// PARAM: p = position from where item will be removed

T DLinkedList<T>::RemoveAt(int p) {

	/*Node<T>* current = front;

	for (int i = 0; i < p; i++) {
		current = current->next;
	}
	    Node<T>* previous = current->prev;
        Node<T>* nextNode = current->next;

        previous->next = nextNode;
        nextNode->prev = previous;

        delete current;
        ///
        for(Node<T>* aa = front;
		aa != NULL; 
		aa = aa->next){

		cout<< aa->data << " ";

	}*/

	        T a;
        return a;


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
			cout << "Found item!" << endl;
			return true;
		}
	}
	cout << "Item not found." << endl;
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
	//cout << "Item at int p is: " << current->data;
	return current->data;
}

#endif
