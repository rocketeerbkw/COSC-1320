/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 1
 * File Name:           S9_L1_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            Feb 25, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program calculates the revenue of a candy bar fundraiser when
 * provided with the number of candy bars sold and the amount each candy bar
 * sold for.
 *
 * To the extent possible under law, the author(s) have dedicated all copyright 
 * and related and neighboring rights to this software to the public domain 
 * worldwide. This software is distributed without any warranty.
 *
 * You should have received a copy of the CC0 Public Domain Dedication along 
 * with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#include <iostream>
using namespace std;

int main() {
  unsigned short candyBarsSold;
  float candyBarPrice,
        revenue;

  cout << "How many candy bars did you sell? ";
  cin >> candyBarsSold;

  cout << "How much did you sell one candy bar for (in dollars)? ";
  cin >> candyBarPrice;

  revenue = candyBarsSold * candyBarPrice;

  cout << "Your revenue is $" << revenue << endl;

  system("pause");
  return 0;
}

/* Sample Output

How many candy bars did you sell? 164
How much did you sell one candy bar for (in dollars)? 1.25
Your revenue is $205
Press any key to continue . . .

*/
