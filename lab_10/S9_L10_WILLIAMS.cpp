/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 10
 * File Name:           S9_L10_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            April 7, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program sorts arrays using pointers instead of directly
 *
 * To the extent possible under law, the author(s) have dedicated all copyright 
 * and related and neighboring rights to this software to the public domain 
 * worldwide. This software is distributed without any warranty.
 *
 * You should have received a copy of the CC0 Public Domain Dedication along 
 * with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#include <iostream>
#include <iomanip>
using namespace std;

class Arrays {
  private:
    int size;
    int *pArrayNum, // Pointer to an array
        **pArrayUp, // Pointer to array of pointers
        **pArrayDown; // Pointer to array of pointers
    
  public:
    Arrays(int size);
    ~Arrays();
    void sortAsc();
    void sortDesc();
    void print();
};

int main () {
  int arrSize;
  
  cout << "How big of an array would you like to sort? ";
  cin >> arrSize;
  
  Arrays testArr(arrSize);
  
  cout << "Arrays before sorting: " << endl;
  testArr.print();
  cout << endl << endl;
  
  cout << "Sorting asc...  ";
  testArr.sortAsc();
  cout << "done!" << endl;
  
  cout << "Sorting desc...  ";
  testArr.sortDesc();
  cout << "done!" << endl << endl;
  
  cout << "Arrays after sorting: " << endl;
  testArr.print();
  
  system("pause");
  return 0;
}

Arrays::Arrays(int arrSize) {
  size = arrSize;
  cout << "Generating a random array with " << size << " elements...  ";
  
  pArrayNum = new int[arrSize];
  pArrayUp = new int*[arrSize];
  pArrayDown = new int*[arrSize];
  
  srand(clock());
  for (int index = 0; index < arrSize; index++) { // initialize array with values
    pArrayNum[index] = rand();
    pArrayUp[index] = &pArrayNum[index];
    pArrayDown[index] = &pArrayNum[index];
  }
  
  cout << "done!" << endl;
}

// Destructor frees memory
Arrays::~Arrays() {
  if (size > 0) {
    delete [] pArrayNum;
    delete [] pArrayUp;
    delete [] pArrayDown;
    pArrayNum = 0;
    pArrayUp = 0;
    pArrayDown = 0;
  }
}

/**
 * Implementations of selection sort algorithm
 */
void Arrays::sortAsc() {
  int minIndex;
  int *minElem;
  
  for (int scan = 0; scan < (size - 1); scan++) {
    minIndex = scan;
    minElem = pArrayUp[scan];
    
    for(int index = scan + 1; index < size; index++) {
      if (*(pArrayUp[index]) < *minElem) {
        minElem = pArrayUp[index];
        minIndex = index;
      }
    }
    
    pArrayUp[minIndex] = pArrayUp[scan];
    pArrayUp[scan] = minElem;
  }
}

void Arrays::sortDesc() {
  int minIndex;
  int *minElem;
  
  for (int scan = 0; scan < (size - 1); scan++) {
    minIndex = scan;
    minElem = pArrayDown[scan];
    
    for(int index = scan + 1; index < size; index++) {
      if (*(pArrayDown[index]) > *minElem) {
        minElem = pArrayDown[index];
        minIndex = index;
      }
    }
    
    pArrayDown[minIndex] = pArrayDown[scan];
    pArrayDown[scan] = minElem;
  }
}

void Arrays::print() {
  cout << "pArrayNum  ";
  for (int i = 0; i < size; i++)
    cout << pArrayNum[i] << " ";
  cout << endl;
    
  cout << "pArrayUp   ";
  for (int i = 0; i < size; i++)
    cout << *(pArrayUp[i]) << " ";
  cout << endl;
    
  cout << "pArrayDown ";
  for (int i = 0; i < size; i++)
    cout << *(pArrayDown[i]) << " ";
  cout << endl;
}

/*
 Sample Output

How big of an array would you like to sort? 10
Generating a random array with 10 elements...  done!
Arrays before sorting:
pArrayNum  3327 17924 20827 18642 8175 1086 29643 871 24245 32660
pArrayUp   3327 17924 20827 18642 8175 1086 29643 871 24245 32660
pArrayDown 3327 17924 20827 18642 8175 1086 29643 871 24245 32660


Sorting asc...  done!
Sorting desc...  done!

Arrays after sorting:
pArrayNum  3327 17924 20827 18642 8175 1086 29643 871 24245 32660
pArrayUp   871 1086 3327 8175 17924 18642 20827 24245 29643 32660
pArrayDown 32660 29643 24245 20827 18642 17924 8175 3327 1086 871
Press any key to continue . . .

*/
