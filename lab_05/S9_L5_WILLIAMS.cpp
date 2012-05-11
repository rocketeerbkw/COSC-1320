/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 5
 * File Name:           S9_L5_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            Feb 25, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program shows a vertical bar chart representing the population changes 
 * of a city over a number of years.
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
#include <fstream>
using namespace std;

int main() {
  ifstream dataFile;
  int population[6];
  
  // Make sure we can open the file
  dataFile.open("people.dat");
  if (!dataFile) {
    cout << "Error: Could not open people.dat." << endl;
    system("pause");
    exit(0);
  }
  
  // Get the population data from the file and close the file
  dataFile >> population[0] >> population[1] >> population[2] >> population[3] >> population[4] >> population[5];
  dataFile.close();
  
  cout << "         Prairieville Population Growth" << endl << endl;
  
  // Find the highest population (in 1000s)
  int highestPop = 0;
  for (int i = 0; i < 6; i++) {
    if ((population[i] / 1000) > highestPop) {
      highestPop = population[i] / 1000;
    }
  }
  
  // Print out the graph including y-axis and labels, from top to bottom
  int currentPop = highestPop;

  while (currentPop > 0) {
    cout << setw(6) << currentPop * 1000 << " |";
    
    for (int col = 0; col < 6; col++) {
      if (population[col] >= currentPop * 1000) {
        cout << "  **  ";
      }
      else {
        cout << "      ";
      }
    }
    
    cout << endl;
    currentPop--;
  }
  
  // Print out the x-axis and it's labels
  cout << "       ------------------------------------" << endl << "        ";
  int year = 1990;
  for (int col = 0; col < 6; col++) {
    cout << " " << year << " ";
    year += 20;
  }
  cout << endl;
  
  system("pause");
  return 0;
}
