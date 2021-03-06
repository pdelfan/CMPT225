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

// hash function, uses Horner's method
// Assume input string consists only of lower-case a to z
int HashTable::Hash(string input) const {
    int hashvalue = 0;
    for (int i = 0; i < input.length(); i++) {
        int asc = input[i] - 96;
        hashvalue = (hashvalue*32 + asc) % maxsize;
    }
    return hashvalue;
}

// helper function to find smallest prime number greater than supplied parameter
int HashTable::SmallestPrime(int n) const {
    //Check if n + 1 is a prime number. If not, increment by 1 until a prime is found.
    int i = n + 1;
    while (1) {
        if (IsPrime(i)) {
            return i;
        } else {
            i++;
        }
    }
}

// helper function to determine whether a number is prime
bool HashTable::IsPrime(int n) const {
    //Brute Force. Divide n by every number less than n and greater than 2
    // and check if it evenly divides.
    bool isPrime = true;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            isPrime = false;
            return isPrime;
        }
    }
    return isPrime;
}

// Resizes the hashtable into a larger array.
// Return false if n is smaller than current array size or if n is negative.
// Else, set array size to the smallest prime number larger than n
//   and re-hash all contents into the new array, delete the old array and return true.
bool HashTable::Resize(int n) { 
    if (n < maxsize || n < 0) {
        return false;
    } else {
        //re-hash all contents into the new array
    	HashTable* new_table = new HashTable(n);
        for (int i = 0; i < maxsize; i++) {
            //Create a vector from the seperate chaining of each hashtable index
            vector<UserAccount> SChain = table[i].Dump();
            for (int j = 0; j < SChain.size(); j++) {
                //Go through the vector's size and rehash to the new table
                new_table->Insert(SChain[j]);
            }
        }

        maxsize = new_table->maxsize;
        SLinkedList<UserAccount>* temp = table;
        table = new_table->table;
        delete[] temp;
        return true;
    } 
}

// default constructor
// creates an array of size 101
HashTable::HashTable() {
	size = 0;
	maxsize = 11;
	table = new SLinkedList<UserAccount>[maxsize];
}

// parameterized constructor
// creates an array of size = smallest prime number > 2n
HashTable::HashTable(int n) { 
	size = 0;
	maxsize = SmallestPrime(2*n);
	table = new SLinkedList<UserAccount>[maxsize];
}

// copy constructor
// Creates deep copy of sourceht
HashTable::HashTable(const HashTable& sourceht) { 
	size = sourceht.size;
	maxsize = sourceht.maxsize;
	table = new SLinkedList<UserAccount>[maxsize];
	for (int i = 0; i < maxsize; i++) {
		table[i] = sourceht.table[i];
	}
}

// destructor
HashTable::~HashTable() {
	delete[] table;
	size = 0;
}

// overloaded assignment operator
HashTable& HashTable::operator=(const HashTable& sourceht) {
	if (this != &sourceht) {
		delete[] table;
        size = sourceht.Size();
        maxsize = sourceht.maxsize;
        table = new SLinkedList<UserAccount>[maxsize];
        for (int i = 0; i < maxsize; i++) {
            table[i] = sourceht.table[i];
        }
	}
	return *this;
}

// Insertion
// If item does not already exist, inserts at back of hashed list and returns true
//   otherwise returns false
// If load factor (before insertion) is above 2/3, expand into a new
//   table of smallest prime number size at least double the present table size
//   and then insert the item.
bool HashTable::Insert(UserAccount acct) {
    if (Search(acct) == true) { //user already exists
        return false;
    } else { 
        size++;
        //slot is full, use separate chaining, insert at the back 
        if (LoadFactor() >= 2/3.00) { // int/double to compare against double
            Resize(maxsize);
        }
        int index = Hash(acct.GetUsername());
        table[index].InsertBack(acct);
        return true;
    }
}

// Removal
// If item exists, removes and returns true
//   otherwise returns false
bool HashTable::Remove(UserAccount acct) {
	if (Search(acct) == false) {
		return false;
	} else {
		int index = Hash(acct.GetUsername());
		table[index].Remove(acct);
		size--;
		return true;
	}
}

// Search
// Returns true if item exists, false otherwise
bool HashTable::Search(UserAccount acct) const {
    int index = Hash(acct.GetUsername());
    bool found = table[index].Contains(acct);
    if (found == true){
        return true;
    }
        return false;	//not found
}

// Retrieval
// Returns a pointer to a UserAccount object inside the hash table (linked list)
//   if a matching parameter is found, otherwise return NULL
UserAccount* HashTable::Retrieve(UserAccount acct) {
    int index = Hash(acct.GetUsername());
    SLinkedList<UserAccount> account = table[index];
    UserAccount *user = account.Retrieve(acct);
    return user;
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
	return (size/(double)maxsize);
}
