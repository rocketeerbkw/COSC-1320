/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 12
 * File Name:           S9_L12_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            May 12, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program verifies if a given password is secure enough.
 *
 * To the extent possible under law, the author(s) have dedicated all copyright 
 * and related and neighboring rights to this software to the public domain 
 * worldwide. This software is distributed without any warranty.
 *
 * You should have received a copy of the CC0 Public Domain Dedication along 
 * with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const unsigned int PASS_MIN_LENGTH = 6;
enum err_type {OK, TOO_SHORT, MISSING_UPPERCASE, MISSING_LOWERCASE, MISSING_DIGIT};
err_type securePassword(string);

int main() {
  
  string pass;
  
  cout << "Enter a password (or Q to quit): ";
  cin >> pass;
  
  while(pass != "Q" && pass != "q") {
    err_type err = securePassword(pass);
  
    switch(err) {
      case TOO_SHORT:
        cout << "That password is too short.";
        break;
        
      case MISSING_UPPERCASE:
        cout << "You must include an uppercase character.";
        break;
        
      case MISSING_LOWERCASE:
        cout << "You must include a lowercase character.";
        break;
        
      case MISSING_DIGIT:
        cout << "You must include a digit.";
        break;
        
      default:
        cout << "That password is secure!";
    }
    
    cout << endl << endl << "Enter a password (or Q to quit): ";
    cin >> pass;
  }
  
  system("pause");
  return 0;
}

err_type securePassword(string pass) {
  if (pass.length() < PASS_MIN_LENGTH) {
    return TOO_SHORT;
  }
  
  bool hasUpper = false;
  bool hasLower = false;
  bool hasDigit = false;
  for (unsigned int pos = 0; pos < pass.length(); pos++) {
    if (isupper(pass[pos])) {
      hasUpper = true;
    }
    if (islower(pass[pos])) {
      hasLower = true;
    }
    if (isdigit(pass[pos])) {
      hasDigit = true;
    }
  }
  
  if (!hasUpper) return MISSING_UPPERCASE;
  if (!hasLower) return MISSING_LOWERCASE;
  if (!hasDigit) return MISSING_DIGIT;
  
  return OK;
}

/*
 Sample Output

Enter a password (or Q to quit): asdf
That password is too short.

Enter a password (or Q to quit): asdfasdf
You must include an uppercase character.

Enter a password (or Q to quit): ASDFASDF
You must include a lowercase character.

Enter a password (or Q to quit): ASDFasdf
You must include a digit.

Enter a password (or Q to quit): 003ASdf
That password is secure!

Enter a password (or Q to quit): q
Press any key to continue . . .

*/
