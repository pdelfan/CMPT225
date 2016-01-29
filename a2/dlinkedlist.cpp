#ifdef _DLINKEDLIST_H_

#include <cstdlib>
#include <stdexcept>
#include "dlinkedlist.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
// helper function for deep copy
// Used by copy constructor and operator=
void DLinkedList<T>::CopyList(const DLinkedList& ll) {
	//Currently gets seg fault
	int new_size = 0;

	DLinkedList<T> llb;
	
	Node<T>* current = ll.front;
    if (current == NULL) {
        front = NULL;
        back = NULL;
    }
    else {
        while (current != NULL) {
            llb.InsertBack(current->data);
            current = current->next;
            new_size++;

            //Test: How many items are there in the original linked list
            //i++;
        }
        Node<T>* fro = llb.front;
        //cout << "There are " << i << " elements in the original linked linked list." << endl;

cout << "The copied linked list: ";
        for (int i = 0; i < new_size; i++) {
        	cout << fro->data << " ";
        	fro = fro->next;
        }
        cout << endl;
    }
    
}

template <class T>
// helper function for deep delete
// Used by destructor and copy/assignment
void DLinkedList<T>::DeleteList() {
	for (Node<T>* current = front; current != NULL; current = current->next) {
		delete current;
	}
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
	CopyList(ll);
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
	if (IsEmpty()) {               //linkedlist is empty
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
  if (IsEmpty()) {              //linkedlist is empty
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
	if (p == 0) {                  //insert front
		InsertFront(item);
	}else if (p == size) {         //inesrt back
		InsertBack(item);
	}else {                        //other cases (between front and back)
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
	Node<T>* temp = front; //for the first case
	Node<T>* current = front; //for the second case

if (p == 0) {                  //deleting front
  front = front->next;
  front->prev = nullptr;
  size--;  
  return temp->data;
}

if (p == 1 && size == 3) {    //deleting middle node when len is 3
	Node<T>* middle = front->next;
	front->next = back;
	back->prev = front;
	size--;
	return middle->data;
    }

else if (p == size-1) {       //deleting back
	Node<T>* end = back;
	back = back->prev;
	back->next = nullptr;
	size--;
	return end->data;
    }

else { 
	for (int i = 0; i < p; i++) {
		current = current->next;
	}
	Node<T>* previous = current->prev;
        Node<T>* nextNode = current->next;
        previous->next = nextNode;
        nextNode->prev = previous;
        size--;
        return current->data;
}

Node<T>* re = front;
for (int i = 0; i < p; i++) {
	re = re->next;
    }
	return re->data;
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
void DLinkedList<T>::RemoveDuplicates() { //Not working for printing backwards, connecting prev
	Node<T> *ptr1, *ptr2, *dup;
	ptr1 = front;

	cout << "Removing the duplicates..." << endl;

	while (ptr1 != NULL && ptr1->next != NULL) {

		ptr2 = ptr1;

		while (ptr2->next != NULL) {
			if(ptr1->data == ptr2->next->data) {
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				//ptr1->next = ptr2->next; //trying to connect to previous node
				delete dup;
			}
			else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
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
		if (current->data == item) {
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

// overloaded assignment operator
// must work in the following cases:
// list2 = list1 -> general case
// list2 = list2 -> should do nothing
template <class T>
DLinkedList<T>& DLinkedList<T>::operator = (const DLinkedList& ll) {
	if (this->size != 0) {
		this->DeleteList();
	}

	if (&ll == this) {
		return *this;
	}else if (ll.size == 0) {
		this->~DLinkedList();
		return *this;
	}
	this->CopyList(ll);
	this->size = ll.Size;
	return *this;
}

template <class T>
void DLinkedList<T>::printForward() {
	if (IsEmpty()) {
		cout << "List is empty" << endl;

	} else {
		Node<T>* head = front;
		cout << "These are the elements contained in the linked list: ";
		while (head) {
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl;
	}
}

template <class T>
void DLinkedList<T>::printBack(){
    Node<T>* tail = back;
    if (!tail) {
        cout << "The DLList is empty!" << endl;
        return;
    }
    else {
    	Node<T>* tail = back;
    	cout << "These are the elements printed in reverse: ";
        while (tail) {
            cout << tail->data << " ";
            tail = tail->prev;
        }
        cout << endl;
    }
}

#endif
