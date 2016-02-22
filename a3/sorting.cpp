// File:        sorting.cpp
// Author:      Geoffrey Tien
//              Josh Vocal, Pouria Delfanazari
// Date:        2016-02-09
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here
#include <stdlib.h>
#include <stdexcept>
/*
Selection sort (from Wikipedia)
sorting by finding the smallest item,
dividing arr[] into two sorted and unsorted sections.
PRE: arr[] is unsorted (none)
POST: arr[] is sorted into ascending order, n is unchanged
PARAM: arr[] = the array, n = size of arr[]
*/
template <class T>
int SelectionSort(T arr[], int n) 
{
  int count = 0; //counter for barometer operations
  if (n < 0) {
    throw std::out_of_range("Invalid index");
  }

  else {
  int min = 0;

  for (int i = 0; i < n-1; i++) {
    min = i; /*finding the index of the smallest element in the array by comparing the first 
             element with the rest of the elements
             */
    for (int j = i + 1; j < n; j++) {
      if (arr[min] > arr[j]) {
        min = j;
      }
      count += 1;
    }

    if (min != i) {     //for swapping the smallest item with the current one
      T temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  } 
 }
  return count;
}

/* 
Quicksort (from textbook); sorts the array by partitioning,
dividing it parts by small and large elements until the array is sorted.
PRE: arr[] is unsorted (none)
POST: arr[] is sorted into ascending order, n is unchanged and return the number of operations
PARAM: arr[] = the array, n = size of arr[]
*/
template <class T>
int Quicksort(T arr[], int n)
{
  int count = 0;
  if (n < 0) {
    throw std::out_of_range("Invalid index");
  } 

  else {
  QuicksortHelper(arr, 0, n - 1, count);
  }
  return count;
}

/*
Helper function for quicksort. Partitions the array, sorts the sections
and returns the index of the pivot.
PRE: arr[] is unsorted (none)
POST: the number of barometer operations is returned
PARAM: arr[] = the array, n = size of arr[]
*/
template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{
  if (low < high) {
    int pivot = QSPartition(arr, low, high, counter); //partition the items of arr[] 
    QuicksortHelper(arr, low, pivot - 1, counter); //sort the first half      
    QuicksortHelper(arr, pivot + 1, high, counter); //sort the second half      
  }
}

/*
Quicksort partition function (from textbook)
chooses the pivots in the two small and large sections—used by QuicksortHelper
PRE: arr[] is unsorted (none)
POST: arr[] is sorted into ascending order, the number of barometer operations is returned
PARAM: arr[] = the array, n = size of arr[], low = index of the first chosen element in the array, 
high = index of the last chosen element in the array
*/
template <class T>
int QSPartition(T arr[], int low, int high, int& counter)
{
  bool done = false;
  int index = high;
  int left = low;
  int right = high - 1;
  
  while (!done) {
    while (arr[left] < arr[index]) { //comparing the elements from left to index 
      left++;
      counter++;
    }
    
    while (((arr[right] > arr[index]) && (left < right))) { //comparing the elements from right to index
      right--;
    }

    if ((left < right)) { //swapping left and right when left is smaller than big
      T temp = arr[right];
      arr[right] = arr[left];
      arr[left] = temp;
      left++;
      right--;
    }

    else {
      done = true;
    }
  }

  T temp = arr[index];    //swapping elements of index and left
  arr[index] = arr[left];
  arr[left] = temp;
  index = left;
  return index;
}

/* 
Randomized quicksort; sorts the array by partitioning, choosing the pivot randomly,
dividing it parts by small and large elements until the array is sorted.
PRE: arr[] is unsorted (none)
POST: arr[] is sorted into ascending order, n is unchanged and return the number of operations
PARAM: arr[] = the array, n = size of arr[]
*/
template <class T>
int RQuicksort(T arr[], int n)
{
   int counter = 0;
   if (n < 0) {
    throw std::out_of_range("Invalid index");
  }
  else {

   int high = n-1;
   int low = 0;
   RQuicksortHelper(arr, low, high, counter);
 }
   return counter;

}

/*
Helper function for RQuicksort. Partitions the array, sorts the sections
and returns the index of the pivot.
PRE: arr[] is unsorted (none)
POST: the number of barometer operations is returned
PARAM: arr[] = the array, n = size of arr[]
*/
template <class T>
void RQuicksortHelper(T arr[], int low, int high, int& counter)
{
    if (low < high) {
        int pivot = RQSPartition(arr, low, high, counter);
        RQuicksortHelper(arr, low, pivot - 1, counter);
        RQuicksortHelper(arr, pivot + 1, high, counter);
    }
}

/*
Randomized quicksort partition function 
chooses the pivots (randomly) in the two small and large sections—used by QuicksortHelper
PRE: arr[] is unsorted (none)
POST: arr[] is sorted into ascending order, the number of barometer operations is returned
PARAM: arr[] = the array, n = size of arr[], low = index of the first chosen element in the array, 
high = index of the last chosen element in the array
*/
template <class T>
int RQSPartition(T arr[], int low, int high, int& counter)
{
    int pivot_index = low + rand() % (high - low + 1);
    T temp = arr[high];
    arr[high] = arr[pivot_index];
    arr[pivot_index] = temp;
    return QSPartition(arr, low, high, counter);
}

/*
Mergesort (from texbook)
Sorts the array by using the function MergesortHelper
PRE: arr[] is unsorted (none)
POST: return the number of barometer operations counted
PARAM: arr[] = the array, n = size of arr[]
*/
template <class T>
int Mergesort(T arr[], int n)
{
  int count = 0;
  if (n < 0) {
    throw std::out_of_range("Invalid index");
  }
  
  else {
  MergesortHelper(arr, 0, n - 1, n, count);
}
  return count;
}

/*
Helper function for mergesort, sorts by dividing the array into left and right sections
PRE: arr[] is unsorted (none)
POST: arr[] is sorted into ascending order
PARAM: arr[] = the array, n = size of arr[], low = index of the first chosen element,
high = index of the last chosen element, mid = for choosing the middle element
*/
template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
   if (low < high) { //size of the array is more than 1
    int mid = low + (high - low) / 2; //determining the middle element
    MergesortHelper(arr, low, mid, n, counter); //sorting the first half
    MergesortHelper(arr, mid + 1, high, n, counter); //sorting the second half
    Merge(arr, low, mid, high, n, counter); //merge the sections
  }
}

/*
Mergesort function (from textbook)
PRE: none
POST: two sections are merged
PARAM: arr[] = the array, n = size of arr[], low = index of the first element of the first section,
high = index of the last element of the second section, mid = index of the last element of the first section
*/
template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{

  T* tempArray = new T[n];
  int first1 = low;       //beginning of the first section
  int last1 = mid;        //end of the first section
  int first2 = mid + 1;   //beginning of the second section
  int last2 = high;       //end of the second section

  int index = first1;     //next location in the temporary array that is available
  while ((first1 <= last1) && (first2 <= last2)) {
    if (arr[first1] <= arr[first2]) {  //tempArray[low..n-1] is in order
      tempArray[index] = arr[first1];
      first1++;
    }
    else {
      tempArray[index] = arr[first2];
      first2++;
    }
    index++;
    counter++;
  }

  while (first1 <= last1) {         //finish the first section 
    tempArray[index] = arr[first1]; //tempArray[low..n-1] is in order
    first1++;
    index++;
  }

  while (first2 <= last2) {         //finish the second section
    tempArray[index] = arr[first2]; //tempArray[low..n-1] is in order
    first2++;
    index++;
  }

  for (index = low; index <= high; index++) { //copy tempArray into the original array
    arr[index] = tempArray[index];
  }
  delete[] tempArray;
}

/*Shell Sort (from Wikipedia)
(Start with the largest gap and work down to a gap of 1)
PRE: arr[] is unsorted (none)
POST: arr[] is sorted into ascending order
PARAM: arr[] = the array, n = size of arr[]
*/
template <class T>
int ShellSort(T arr[], int n)
{
  int count = 0;
  if (n < 0) {
      throw std::out_of_range("Invalid index\n");
  }

  else {
  //Create the largest gap which is floor (arrLength/2) and work down
  for (int gap = n/2; gap > 0; gap /=2) {
    //Move up one element and compare with the gap element
      for (int i = gap; i < n; i++) {
          count++;
          T temp = arr[i];
          int j;
          //Switch the element with the gap element if it is greater
          for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
              arr[j] = arr[j - gap];
          }
          arr[j] = temp;
      }
  }
 }
  return count;
}
