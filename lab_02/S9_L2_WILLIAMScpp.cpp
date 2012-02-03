/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 2
 * File Name:           S9_L2_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            Feb 25, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program writes a diamond pattern on the screen when provided with the 
 * number of rows the diamond should occupy.
 *
 * To the extent possible under law, the author(s) have dedicated all copyright 
 * and related and neighboring rights to this software to the public domain 
 * worldwide. This software is distributed without any warranty.
 *
 * You should have received a copy of the CC0 Public Domain Dedication along 
 * with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int stars = -1;
  double rows; // Use double to not lose precision when dividing
  int spaces, userRows;
  bool userRowsValid = false;
  
  // Get number of rows from the user
  do {
    cout << "Enter an odd number: ";
    cin >> userRows;
    
    // Make sure it's an odd number
    if (userRows % 2 != 0) {
      userRowsValid = true;
      rows = userRows;
    }
  } while (!userRowsValid);
  
  // Write out our diamond
  for (int row = 1; row <= rows; row++) {
    // Get the number of stars in the current row
    stars = (row <= ceil(rows/2)) ? stars + 2 : stars - 2;
    // Get the number of spaces to pad the star with
    spaces = (rows - stars) / 2;
    
    for (int col = 1; col <= spaces + stars; col++) {
      if (col <= spaces) {
        cout << " ";
      }
      else {
        cout << "*";
      }
    }
    
    cout << endl;
  }
  
  system("pause");
  return 0;
}

/* Sample Output

Enter an odd number: 7
   *
  ***
 *****
*******
 *****
  ***
   *
Press any key to continue . . .

*/
