// File:        sorting.cpp
// Author:      Geoffrey Tien
//              Josh Vocal, Pouria Delfanazari
// Date:        2016-02-09
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here
// Selection Sort
// from wiki
template <class T>
int SelectionSort(T arr[], int n) {

  int min = 0;
  int count = 0; //counter for barometer operations

  for (int i = 0; i < n-1; i++) {
    min = i;
    
    for (int j = i + 1; j < n; j++) {
      if (arr[min] > arr[j]) {
        min = j;
      }
      count += 1;
    }

    if (min != i) {
      T temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
  return count;
}

// Quicksort
// (your comments here)
template <class T>
int Quicksort(T arr[], int n)
{
  int count = 0;
  
  return count;
}

template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{
  
}

template <class T>
int QSPartition(T arr[], int low, int high, int& counter)
{
  int pivotindex = 0;
  
  return pivotindex;
}

// Randomized Quicksort
// (your comments here)
template <class T>
int RQuicksort(T arr[], int n)
{
  int count = 0;
  
  return count;
}

template <class T>
void RQuicksortHelper(T arr[], int low, int high, int& counter)
{
  
}

template <class T>
int RQSPartition(T arr[], int low, int high, int& counter)
{
  int pivotindex = 0;
  
  return pivotindex;
}

// Mergesort
// (your comments here)
template <class T>
int Mergesort(T arr[], int n)
{
  int count = 0;
  
  return count;
}

template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
  
}

template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
  
}

// Shell Sort
// (your comments here)
template <class T>
int ShellSort(T arr[], int n)
{
  int count = 0;
  
  return count;
}
