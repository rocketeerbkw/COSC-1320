/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 3
 * File Name:           S9_L3_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            Feb 25, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program lets you practie your skills at addition. You must solve a user 
 * defined number of problems and will be scored at the end.
 *
 * To the extent possible under law, the author(s) have dedicated all copyright 
 * and related and neighboring rights to this software to the public domain 
 * worldwide. This software is distributed without any warranty.
 *
 * You should have received a copy of the CC0 Public Domain Dedication along 
 * with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#include <iostream>
#include <ctime>
using namespace std;

int main() {
  int numProblems,
      numRight = 0,
      numWrong = 0,
      num1, num2, answer;
  bool finished = false;
  srand(time(0)); // Seed random number generator

  cout << "How many problems would you like to practice? ";
  cin >> numProblems;
  cout << "You may answer 0 to end the exercise early." << endl << endl;

  do {
    num1 = 1 + rand() % 9;
    num2 = 1 + rand() % 9;

    cout << "What is " << num1 << " + " << num2 << "? ";
    cin >> answer;

    // End exercise early
    if (answer == 0) {
      cout << endl;
      break;
    }

    if (num1 + num2 == answer) {
      cout << "      Correct!" << endl;
      numRight++;
    }
    else {
      cout << "        Wrong! " << num1 + num2 << endl;
      numWrong++;
    }

    cout << endl;

    if (numRight + numWrong == numProblems) {
      finished = true;
    }
  } while (!finished);

  int numAnswered = numRight + numWrong;

  // Prevent division by zero
  // Use int as a dirty way of rounding
  int score = (numAnswered == 0) ? 0 : numRight * 100 / numAnswered;

  cout << "Number of problems: " << numAnswered << endl;
  cout << "Number right:       " << numRight << endl;
  cout << "Number wrong:       " << numWrong << endl;
  cout << "----------------------" << endl;
  cout << "You scored " << score << "%" << endl;

  system("pause");
  return 0;
}

/* Sample Output

How many problems would you like to practice? 5
You may answer 0 to end the exercise early.

What is 5 + 7? 12
      Correct!

What is 5 + 1? 6
      Correct!

What is 5 + 3? 9
        Wrong! 8

What is 2 + 1? 0

Number of problems: 3
Number right:       2
Number wrong:       1
----------------------
You scored 66%
Press any key to continue . . .

*/
