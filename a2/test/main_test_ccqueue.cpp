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
  //lla.InsertFront(0);
 // cout << "-------------------------------------------------\n";
  lla.InsertBack(5);
 // cout << "-------------------------------------------------\n";
  //lla.Contains(9);
  //lla.Contains(10);
 // cout << "-------------------------------------------------\n";
  //lla.ElementAt(0);
  lla.InsertAt(0, 0);
  lla.InsertAt(1, 1);
  lla.InsertAt(2, 2);
  lla.InsertAt(3, 3);
  lla.InsertAt(4, 4);
  lla.RemoveAt(0);
  lla.ElementAt(0); 
  lla.RemoveAt(0);
  lla.ElementAt(0); 


}

void CCQTest()
{
    CCQueue ccq;
    cout << "Size of ticket queue: " << ccq.Size() << endl;
    ccq.Add("one", "Video card smoked"); //1
    ccq.Add("two", "Received wrong colour cable"); //2
    ccq.Add("three", "Motherboard DOA"); //3
    ccq.Add("four", "Order not received"); //4
    ccq.Add("five", "Only 931GB on 1TB hard drive"); //5
    cout << "Size of ticket queue: " << ccq.Size() << endl;
    cout << ccq.PrintStatus() << endl;

    //ccq.Service();
    //ccq.MoveUp(1);
    //ccq.MoveUp(1);
    ccq.MoveDown(1);
    cout << ccq.PrintStatus() << endl;
}
