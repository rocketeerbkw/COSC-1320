/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 9 
 * File Name:           S9_L9_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            April 7, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program compares differenc sorting and searching algorithms
 * on arrays of varying sizes.
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
#include <iomanip>
using namespace std;

void showArray(int[], int);
void selectionSort(int[], int);
void selectionSortDescribed(int[], int);
void selectionSortDescribedShowProgress(int[], int);
void selectionSortConcise(int[], int);
bool linearSearchArray(int [], int, int, int&);

// My sort/search algorithms
void bubbleSort(int[], int);
int binarySearch(int[], int, int);

int main () {
  int numTests = 4;
  int numTestSizes = 5;
  int searchRuns = 2000;
  string tests[] = {"Selection Sort", "Linear Search", "Bubble Sort", "Binary Search"};
  int testSizes[] = {500, 1000, 5000, 10000, 15000, 30000, 40000, 50000};
  
  // Print table header
  cout << setw(20) << left << "Algorithm";
  for (int size = 0; size < numTestSizes; size++) {
    cout << setw(5) << right << testSizes[size] << " ";
  }
  cout << "(array size)" << endl << endl;
  
  // Run our tests for each algorithm and array size
  for (int test = 0; test < numTests; test++) {
    cout << setw(20) << left << tests[test];
    
    int *testArr;
    unsigned int startTime, stopTime;
    
    for (int testSize = 0; testSize < numTestSizes; testSize++) {
      // Initialize test array and fill it with random stuff
      testArr = new int[testSizes[testSize]];
      unsigned int seed = time(0);
      srand(seed);
      for (int index = 0; index < testSizes[testSize]; index++) // initialize array with values
        testArr[index] = rand();
        
      // Run the testss
      const int target = 123456789;
      int foundAt = 0;
      //showArray(testArr, testSizes[testSize]);
      startTime = clock();
      switch (test) {
        case 0:
          selectionSortDescribed(testArr, testSizes[testSize]);
          break;
          
        case 1: // Need to run this a lot to get any decent times
          // Binary sort requires a sorted array so we also sort this one first
          // to keep the benchmark accurate
          selectionSortDescribed(testArr, testSizes[testSize]);
          for (int runs = 0; runs < searchRuns; runs++) {
            linearSearchArray(testArr, testSizes[testSize], target, foundAt);
          }
          break;
          
        case 2:
          bubbleSort(testArr, testSizes[testSize]); 
          break;
          
        case 3: // Need to run this a lot to get any decent times
          // Binary sort requires a sorted array
          selectionSortDescribed(testArr, testSizes[testSize]);
          for (int runs = 0; runs < searchRuns; runs++) {
            binarySearch(testArr, testSizes[testSize], target);
          }
          break;
      }
      stopTime = clock();
      //showArray(testArr, testSizes[testSize]);
      
      cout << setw(5) << right << stopTime - startTime << " ";
    }
    
    delete [] testArr;
    
    cout << "milliseconds" << endl;
  }
  
  system("pause");
  return 0;
}

/**
 * My Sort/Search Algorithms
 */

void bubbleSort(int testArr[], int arrSize) {
  bool swap = false;
  
  // Outer pass. Runs repeatedly until no more swapping happens
  // (aka the array is sorted)
  do {
    swap = false;
    
    // Inner loop. Moves over each pair of array, swapping the two,
    // if necessary, to put the largest (of the two) on the right
    for (int count = 0; count < arrSize - 1; count++) {
      // Check if the current pair needs to be swapped
      if (testArr[count] > testArr[count + 1]) {
        // Remember what the first value is
        int temp = testArr[count];
        // Set the first value to the second value
        testArr[count] = testArr[count + 1];
        // Set the second value to what the first value was
        testArr[count + 1] = temp;
        swap = true;
      }
    }
  } while(swap);
}

int binarySearch(int haystack[], int size, int needle) {
  // Initialize search variables
  int begin = 0;
  int end = size - 1;
  int middle;
  int pos = -1; // pos of needle in haystack
  bool found = false;
  
  // Keep searching until we find the value
  // or we've reached the smallest "half"
  while(!found && begin <= end) {
    middle = (begin + end) / 2;
    
    if (haystack[middle] == needle) { // What luck! We found the needle so stop searching
      found = true;
      pos = middle;
    }
    else if (haystack[middle] > needle) { // needle must be in first half
      // Set last to the value right before middle so we discard
      // the entire second half of the array
      end = middle - 1;
    }
    else { // needle must be in last half
      // Set first to the value right after middle so we discard
      // the entire first half of the array
      begin = middle + 1;
    }
  }
  
  return pos;
}



/**
 * Teachers code
 */

void showArray(int array[], int size) {
  for (int count = 0; count < size; count++)
    cout << setw(2) << array[count] << ' ';
  cout << endl;
}

bool linearSearchArray(int a[], int s, int t, int &p) {
  // This is different from the textbook. If you use this, write in
  // your own words; use good variable names and add useful comments.
  for (int i = 0; i < s; i++) if (a[i] == t) {p=i; return true;}
  p = -1;
  return false;
}


// This is the selection sort from our textbook
void selectionSort(int array[], int size) {
  int startScan, minIndex, minValue;
  for (startScan = 0; startScan < (size - 1); startScan++) {
    minIndex = startScan;
    minValue = array[startScan];
    for (int index = startScan + 1; index < size; index++) {
      if (array[index] < minValue) {
        minValue = array[index];
        minIndex = index;
      }
    }
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
  }
}

// This is selection sort as best I can describe it within the code itself
void selectionSortDescribed(int array[], int size) {
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++) {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++) {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar) {
        // found a smaller value than I had before, save it for now
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is selection sort as best I can describe it within the code itself
// In addition, it shows the result of each pass of the outer loop.
void selectionSortDescribedShowProgress(int array[], int size) {
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++) {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++) {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar) {
        // found a smaller value than I had before, save it for now
        cout << "  previous min value: " << minValueSoFar << " at offset: " << minIndexSoFar;
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
        cout << "; found smaller value: " << minValueSoFar << " at offset: " << minIndexSoFar << endl;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    cout << "  swapped the previous minimum value: " << array[minIndexSoFar]
         << " with with new minimum value: " << array[unsortedIndex] << endl;
    cout << "After pass " << unsortedIndex << " the array looks like this: ";
    showArray(array, size);
    cout << endl;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is a selection sort from a concise algorithm encyclopedia VERY CRYPTIC!
void selectionSortConcise(int array[], int size) {
  int i, idx, val;
  for (i = 0; i < (size - 1); i++) {
    idx = i;
    val = array[i];
    for (int j = i + 1; j < size; j++) {
      if (array[j] < val) {
        val = array[j];
        idx = j;
      }
    }
    array[idx] = array[i];
    array[i] = val;
  }
}
/*
 Sample Output

Algorithm             500  1000  5000 10000 15000 (array size)

Selection Sort          0     1    39   153   347 milliseconds
Linear Search           3     8    68   214   442 milliseconds
Bubble Sort             2     7   166   666  1491 milliseconds
Binary Search           1     1    37   152   347 milliseconds
Press any key to continue . . .

*/
