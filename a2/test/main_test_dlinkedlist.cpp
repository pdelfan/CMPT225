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
  lla.InsertBack(5);
  lla.InsertAt(0, 0);
  lla.InsertAt(1, 1);
  lla.InsertAt(2, 2);
  lla.InsertAt(3, 3);
  lla.InsertAt(4, 4);
  
  try {
    lla.InsertAt(0, -1);
  }
  catch (exception& e) {
    cout << "Exception: " << e.what() << endl;
  }
}
