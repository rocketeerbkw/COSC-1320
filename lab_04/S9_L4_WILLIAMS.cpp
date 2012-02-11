/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 4
 * File Name:           S9_L4_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            Feb 25, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program calculates the time it takes sound to travel through air, 
 * water and steel.
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

int main() {
  char menuSelection;
  float speed, feet, travelTime;
  string medium;
  
  cout << "Calculate the time it takes sound to travel through:" << endl;
  
  // Loop to allow multpile calculations
  do {
    cout << "A)ir, S)teel, W)ater or Q)uit ";
    cin >> menuSelection;
    
    // They want to quit
    if (toupper(menuSelection) == 'Q') {
      break;
    }
    
    // Determine which medium they want
    switch(toupper(menuSelection)) {
      case 'A':
        medium = "air";
        speed = 1100;
        break;
        
      case 'S':
        medium = "steel";
        speed = 16400;
        break;
        
      case 'W':
        medium = "water";
        speed = 4900;
        break;
        
      default:
        cout << "Please choose a valid medium:" << endl;
        continue;
    }
    
    // Get a positive number from them for feet to travel
    do {
      cout << "How many feet will the sound travel? ";
      cin >> feet;
      
      if (feet <= 0) {
        cout << "You must enter a distance greater than zero." << endl << endl;
        continue;
      }
      break;
    } while(true);
    
    // Calculate the time it takes the sound to travel through the medium
    travelTime = feet / speed;
    
    // Round the time to 4 decimal places
    cout << "It will take " << fixed << setprecision(4) << travelTime;
    // Round feet to 2 decimal places
    cout << " seconds for sound to travel through " << setprecision(2) << feet;
    cout << "ft of " << medium << "." << endl << endl;
    
  } while (true);
  
  system("pause");
  return 0;
}

/* Sample Output

Calculate the time it takes sound to travel through:
A)ir, S)teel, W)ater or Q)uit a
How many feet will the sound travel? 2000
It will take 1.8182 seconds for sound to travel through 2000.00ft of air.

A)ir, S)teel, W)ater or Q)uit s
How many feet will the sound travel? 2000
It will take 0.1220 seconds for sound to travel through 2000.00ft of steel.

A)ir, S)teel, W)ater or Q)uit W
How many feet will the sound travel? 2000
It will take 0.4082 seconds for sound to travel through 2000.00ft of water.

A)ir, S)teel, W)ater or Q)uit p
Please choose a valid medium:
A)ir, S)teel, W)ater or Q)uit q
Press any key to continue . . .

*/
