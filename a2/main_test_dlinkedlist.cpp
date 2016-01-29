//              In general, please ensure that you test:
//               1. invalid parameter(s)
//               2. valid parameter(s), boundary case
//               3. valid parameter(s), general case

#include <cstdlib>
#include <iostream>
#include <string>
#include "ccqueue.h"
#include "dlinkedlist.h"
#include "ticket.h"

using namespace std;

void LLTest();

int main()
{
  cout << "\nEntering DLinkedList test function..." << endl;
  LLTest();
  cout << "...DLinkedList test function complete!\n" << endl;
  return 0;
}

void LLTest()
{
  // default constructor, InsertFront, InsertBack, ElementAt
  DLinkedList<int> lla;
  lla.InsertFront(2);
  cout << "-------------------------------------------------\n";
  lla.InsertBack(10);
  lla.InsertBack(2);
  lla.InsertBack(5);
  lla.InsertBack(10);
  lla.InsertBack(2);
  cout << "-------------------------------------------------\n";
  lla.Contains(9);
  lla.Contains(10);
  lla.printForward();
  lla.printBack();
  lla.RemoveDuplicates();
  lla.printForward();
  //lla.printBack(); // dosen't work when duplicates are removed
}
