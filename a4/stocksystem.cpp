// File:        stocksystem.cpp
// Author:      Pouria Delfanazari, Josh Vocal
// Date:        2016-02-27
// Description: Implementation and partial implementation of a StockSystem class for use with CMPT 225 assignment #4

#include <sstream>

#include "stockitem.h"
#include "redblacktree.h"
#include "stocksystem.h"

// default constructor;
// begin with a balance of $100,000.00
StockSystem::StockSystem() {
	balance = 100000.00;
}

// returns the balance member
double StockSystem::GetBalance() {
	return balance;
}

// Add a new SKU to the system. Do not allow insertion of duplicate sku
bool StockSystem::StockNewItem(StockItem item) {
	if (records.Search(item) == false) {  	 //search for duplicates, if not found add the item
		records.Insert(item); 
	}
	else {
		return false; 
	}
	return true;				//for the first case (insertion was successful)
}

// Locate the item with key itemsku and update its description field.
// Return false if itemsku is not found.
bool StockSystem::EditStockItemDescription(int itemsku, string desc) {
	StockItem* item_edit = records.Retrieve(StockItem(itemsku, "", 0));	//find the stock item with the default settings
	if (item_edit == NULL) {						//not found
		return false;
	}
	item_edit->SetDescription(desc); 					//found; set the describtion
	
	return true;
}

// Locate the item with key itemsku and update its description field.
// Return false if itemsku is not found or retailprice is negative.
bool StockSystem::EditStockItemPrice(int itemsku, double retailprice) {
	return false;
}

// Purchase quantity of item at unitprice each, to reach a maximum (post-purchase) on-hand stock quantity of 1000.
// Return false if balance is not sufficient to make the purchase,
//   or if SKU does not exist, or if quantity or unitprice are negative.
// Otherwise, return true and increase the item's on-hand stock by quantity,
//   and reduce balance by quantity*unitprice.
bool StockSystem::Restock(int itemsku, int quantity, double unitprice) {
	return false;
}

// Sell an item to a customer, if quantity of stock is available and SKU exists.
// Reduce stock by quantity, increase balance by quantity*price, and return true if stock available.
// If partial stock (less than quantity) available, sell the available stock and return true.
// If no stock, sku does not exist, or quantity is negative, return false.
bool StockSystem::Sell(int itemsku, int quantity) {
	return false;
}
