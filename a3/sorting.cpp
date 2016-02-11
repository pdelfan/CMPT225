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
// from the texbook
template <class T>
int Mergesort(T arr[], int n)
{
  int count = 0;
  MergesortHelper(arr, 0, n - 1, n, count);
  return count;
}

template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
   if (low < high) {
    int mid = low + (high - low) / 2;
    MergesortHelper(arr, low, mid, n, counter);
    MergesortHelper(arr, mid + 1, high, n, counter);
    Merge(arr, low, mid, high, n, counter);
  }
}

template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
  T* tempArray = new T[n];
  int first1 = low;
  int last1 = mid;
  int first2 = mid + 1;
  int last2 = high;

  int index = first1;
  while ((first1 <= last1) && (first2 <= last2)) {
    if (arr[first1] <= arr[first2]) {
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

  while (first1 <= last1) {
    tempArray[index] = arr[first1];
    first1++;
    index++;
  }

  while (first2 <= last2) {
    tempArray[index] = arr[first2];
    first2++;
    index++;
  }

  for (index = low; index <= high; index++) {
    arr[index] = tempArray[index];
  }
}

// Shell Sort
// (Start with the largest gap and work down to a gap of 1)
template <class T>
int ShellSort(T arr[], int n)
{
  int count = 0;
  //Create the largest gap which is floor (arrLength/2) and work down
  for (int gap = n/2; gap > 0; gap /=2) {
    //Move up one element and compare with the gap element
      for (int i = gap; i < n; i++) {

          count++;
          T temp = arr[i];

          int j;
          //Switch the element with the gap element if it is greater
          for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
              //Increase count when array is not in sorted order
              count++;
              arr[j] = arr[j - gap];
          }
          arr[j] = temp;
      }
  }
  
  return count;
}
