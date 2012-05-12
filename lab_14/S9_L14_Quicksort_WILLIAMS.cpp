/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 14
 * File Name:           S9_L14_Quicksort_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            May 12, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program demonstrates the Quicksort algorithm.
 *
 * Source code modified from code in
 *
 * Starting Out With C++
 * Early Objects, Seventh Edition
 * Tony Gaddis, Judy Walters, Godfrey Muganda
 * Publisher Addison-Wesley
 *
 * Copyright Respective Owners
 */

#include <iostream>
#include <algorithm>   //needed for swap function
using namespace std;

// Function prototypes
void quickSort(int [], int, int);
int partition(int [], int, int);

void showArray(int array[], int start, int end) {
  // Print the sorted array.
  for (int k = start; k <= end; k++)
    cout << array[k] << " ";
}


// Array to be sorted.
const int SIZE = 10;
int array[SIZE] = {17, 53, 9, 2, 30, 1, 82, 64, 26, 5};

int main() {
  cout << "Array before quicksort "; showArray(array, 0, SIZE-1); cout << endl << endl;
  
  quickSort(array, 0, SIZE-1);   // Sort the array using Quicksort.
  
  cout << endl << "Array after quicksort "; showArray(array, 0, SIZE-1); cout << endl << endl;

  system("pause");
  return 0;
}

//************************************************
// quickSort uses the QuickSort algorithm to     *
// sort arr from arr[start] through arr[end].    *
//************************************************
void quickSort(int arr[], int start, int end) {
  if (start < end) {
    cout << "Sorting "; showArray(arr, start, end);
    
    // Partition the array and get the pivot point.
    int p = partition(arr, start, end);
    
    // Sort the portion before the pivot point.
    quickSort(arr, start, p - 1);
    
    // Sort the portion after the pivot point.
    quickSort(arr, p + 1, end);
  }
}

//***********************************************************
// partition rearranges the entries in the array arr from   *
// start to end so all values greater than or equal to the  *
// pivot are on the right of the pivot and all values less  *
// than are on the left of the pivot.                       *
//***********************************************************
int partition(int arr[], int start, int end) {
  // The pivot element is taken to be the element at
  // the start of the subrange to be partitioned.
  int pivotValue = arr[start];
  int pivotPosition = start;
  
  cout << "pivot on " << pivotValue << endl << "Moving everything less than " << pivotValue << " to the left of it" << endl;
  
  // Rearrange the rest of the array elements to 
  // partition the subrange from start to end.
  for (int pos = start + 1; pos <= end; pos++) {
    if (arr[pos] < pivotValue) {  
      // arr[pos] is the "current" item.
      // Swap the current item with the item to the
      // right of the pivot element. Only if the two
      // positions are not equal (saves a swap)
      if (arr[pivotPosition + 1] != arr[pos]) {
        swap(arr[pivotPosition + 1], arr[pos]);
        cout << " swap " << arr[pivotPosition + 1] << " with " << arr[pos] << endl;
      }
      // Swap the current item with the pivot element.
      swap(arr[pivotPosition], arr[pivotPosition + 1]);
      cout << " swap " << arr[pivotPosition] << " with " << arr[pivotPosition + 1] << endl;
      // Adjust the pivot position so it stays with the
      // pivot element.
      pivotPosition ++;
    }
  }
  cout << " "; showArray(array, start, end); cout << endl << endl;
  return pivotPosition;
}
