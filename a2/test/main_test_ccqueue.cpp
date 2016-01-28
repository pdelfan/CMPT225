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

void CCQTest();
void LLTest();

int main()
{
  //cout << "\nEntering DLinkedList test function..." << endl;
  //LLTest();
  //cout << "\n...DLinkedList test function complete!\n" << endl;
  //return 0;
  CCQTest();
  return 0;
}

void LLTest()
{
  // default constructor, InsertFront, InsertBack, ElementAt
  DLinkedList<int> lla;
  lla.InsertFront(1);
 // cout << "-------------------------------------------------\n";
  lla.InsertBack(2);
 // cout << "-------------------------------------------------\n";
  //lla.Contains(9);
  //lla.Contains(10);
 // cout << "-------------------------------------------------\n";
  //lla.ElementAt(0);
  lla.InsertAt(0, 0);
  lla.InsertAt(3, 3);
  lla.InsertAt(4, 4);
  lla.InsertAt(5, 5);
  lla.ElementAt(2);  

}

void CCQTest()
{
    CCQueue ccq;
    ccq.Add("Alrikr", "Video card smoked"); //1
    ccq.Add("Bjornstjerne", "Received wrong colour cable"); //2
    ccq.Add("Cyprianus", "Motherboard DOA"); //3
    ccq.Add("Dietrich", "Order not received"); //4
    ccq.Add("Elisaeus", "Only 931GB on 1TB hard drive"); //5
    cout << "Size of ticket queue: " << ccq.Size() << endl;
    //ccq.Service();
    //ccq.MoveUp(3);
    //ccq.MoveUp(2);
    //ccq.MoveDown(2);
    cout << ccq.PrintStatus() << endl;
}
