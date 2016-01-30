// File:        ccqueue.cpp
// Author:      Josh Vocal, Pouria Delfanazari
// Date:        January 29, 2016
// Description: Implementation of customer complaint queue functions for CMPT 225 assignment 2

#include <sstream>
#include <string>
#include "ccqueue.h"
#include "dlinkedlist.h"
#include "ticket.h"

using namespace std;

CCQueue::CCQueue() {
   this->maxticketid = 0;
   DLinkedList<Ticket> tickets;
}

    // MUTATORS
    
    // enqueues a new ticket at the back of the ticket queue and returns true
    // ticketid is assigned automatically as 1+maxticketid if enqueueing is possible
    // does not enqueue and returns false if either parameter is empty string
    // POST:  new ticket with supplied parameters is added to back of tickets,
    //        maxticketid is incremented
    // PARAM: customer and complaint fields to pass to Ticket constructor
    bool CCQueue::Add(string customer, string complaint) {
     
      if (customer == "" || complaint == "") //if input id empty
        return false;

    tickets.InsertBack(Ticket(1+maxticketid, customer, complaint)); //insert
    maxticketid++;
    return true;
    }

    // removes and returns an item from the front of the ticket queue
    // throws a logic_error if the ticket queue is empty
    // POST:  first item of the ticket queue is removed
    Ticket CCQueue::Service(){
       if (tickets.IsEmpty()) {
          throw std::logic_error("Queue is empty");
       }
       
        Ticket ticket_remove = tickets.ElementAt(0);
        maxticketid--;
        tickets.RemoveAt(0);
        return ticket_remove;
    }

    // moves an item towards the front of the queue by 1 position and returns true
    // returns false if supplied index is 0 (first item) or outside the list boundaries
    // POST:  DLinkedList items at position and position-1 swap spots in the list
    // PARAM: initial index of item to move up
    bool CCQueue::MoveUp(int index){
        
    if (index <= 0 || index >= int(maxticketid))
        return false;
    
    Ticket replace = tickets.RemoveAt(index);
    tickets.InsertAt(replace, index - 1);
    return true;

    }

    // moves an item towards the back of the queue by 1 position and returns true
    // returns false if supplied index is the last item or outside the list boundaries
    // POST:  DLinkedList items at position and position+1 swap spots in the list
    // PARAM: initial index of item to move down
    bool CCQueue::MoveDown(int index) {
    if (index >= int(maxticketid) || index <= 0)
        return false;

    Ticket replace = tickets.RemoveAt(index);
    tickets.InsertAt(replace, index+1);

    return true;
    }

    // ACCESSORS
    
    // returns the number of tickets
    int CCQueue::Size() const {
      return tickets.Size();
    }
