// File:        hashtable.h
// Author:      Josh Vocal, Pouria Delfanazari
// Date:        March 29, 2016
// Description: Implementation of a hash table class for CMPT 225 assignment 5
//              must include hashtableprivate.h file for additional private member functions added by student

#include "hashtable.h"
#include "hashtableprivate.h"

#include <cstdlib>
#include <math.h> // needed for Hash function
#include <string>
#include <vector>
#include "slinkedlist.h"
#include "useraccount.h"

// default constructor
// creates an array of size 101
HashTable::HashTable() {
	size = 0;
	maxsize = 101;
	table = new SLinkedList<UserAccount>[maxsize]; /*
	for (int i = 0; i < maxsize; i++) {
		table[i] = NULL;
	} */
}

// parameterized constructor
// creates an array of size = smallest prime number > 2n
HashTable::HashTable(int n) { 
	size = 0;
	maxsize = SmallestPrime(2*n);
	table = new SLinkedList<UserAccount>[maxsize]; /*
	for (int i = 0; i < maxsize: i++) {
		table[i] = NULL;
	} */
}

// copy constructor
// Creates deep copy of sourceht
HashTable::HashTable(const HashTable& sourceht) { 
	size = sourceht.size;
	maxsize = sourceht.maxsize;
	table = new SLinkedList<UserAccount>[maxsize]; /*

	*Copy the table.sourceht[i] to table[i]
	for (int i = 0; i < maxsize; i++) {
		table[i] = sourceht.table[i];
	}
	*Copy the seperate chaining */
}

// destructor
HashTable::~HashTable() { /* Need to delete seperate chaining somehow.
	for (int i = 0; i < maxsize; i++) { 
		Node* temp = table[i];
		while (temp != NULL) {
			Node* next = temp->next;
			delete temp;
			temp = next;
		}
	}
	size = 0;
	delete[] table; */
}

// overloaded assignment operator
HashTable& HashTable::operator=(const HashTable& sourceht) { /*
	if (this != &sourceht) {
		~HashTable();
		HashTable(sourceht);
	} */
	return *this;
}

// Insertion
// If item does not already exist, inserts at back of hashed list and returns true
//   otherwise returns false
// If load factor (before insertion) is above 2/3, expand into a new
//   table of smallest prime number size at least double the present table size
//   and then insert the item.
bool HashTable::Insert(UserAccount acct) {
	return false;
}

// Removal
// If item exists, removes and returns true
//   otherwise returns false
bool HashTable::Remove(UserAccount acct) {
	return false;
}

// Search
// Returns true if item exists, false otherwise
bool HashTable::Search(UserAccount acct) const {
	return false;
}

// Retrieval
// Returns a pointer to a UserAccount object inside the hash table (linked list)
//   if a matching parameter is found, otherwise return NULL
UserAccount* HashTable::Retrieve(UserAccount acct) {
	UserAccount* someAccount;
	return someAccount;
}

// Returns the number of items stored in the hash table
int HashTable::Size() const {
	return size;
}

// Returns the size of the underlying array
int HashTable::MaxSize() const {
	return maxsize;
}

// Returns the load factor as size / maxsize.
// Note that due to separate chaining, load factor can be > 1.
double HashTable::LoadFactor() const {
	return (size/maxsize);
}