/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 13
 * File Name:           S9_L13_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            May 12, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program counts the frequency with which letters appear in an input
 * file specified by the user and outputs that data to a seperate file.
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
#include <string>
#include <cctype>
using namespace std;

int main() {
  
  string fileName, input, output;
  fstream inFile, outFile;
  
  // Keep trying to open a file specified by user
  do {
    cout << "Enter the name of an input file: ";
    cin >> fileName;
    input = fileName + ".txt";
    
    inFile.clear(); // Clear error codes if we failed to open last time
    inFile.open(input.data(), ios::in);
    if (!inFile) {
      cout << "Could not open " << input << " for reading (misspelled?)" << endl;
      continue;
    }
  } while(!inFile);
  
  // Array to hold count of how many times a letter appears
  int letterFrequency[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  // Variable to hold what we read from file
  char ch;
  
  // Read every character of inFile and track how many times it appears
  cout << "Counting letter frequency in " << input << "...  ";
  
  inFile.get(ch);
  while (!inFile.fail()) {
    // Only track letters of the alphabet
    if (isalpha(ch)) {
      // Tracking is not case sensitive
      ch = tolower(ch);
      // Convert ASCII code of character to go from 0-25 instead of 97-122
      letterFrequency[static_cast<int>(ch) - 97]++;
    }
      
    inFile.get(ch);
  }
  inFile.close();
  
  cout << "done!" << endl;
  
  // Write results
  output = fileName + "Out.txt";
  
  outFile.open(output.data(), ios::out);
  if (!outFile) {
    cout << "Could not open " << output << " for writing" << endl;
    system("pause");
    exit(1);
  }
  
  cout << "Writing results to " << output << "...  ";
  
  outFile << "Character counts found in file (graph approximated): " << input << endl << endl;
  for (int i = 0; i < 26; i++) {
    // Convert 0-25 back to ASCII codes of 97-122
    outFile << static_cast<char>(i+97) << ": " << left << setw(5) << letterFrequency[i];
    outFile << setw(1);
    // Display a graph, but divide every number by 3 so it's not huuuge
    for (int freq = 1; freq <= letterFrequency[i] / 3; freq++) {
      outFile << "*";
    }
    outFile << endl;
  }
  outFile.close();
  
  cout << "done!" << endl;
  
  system("pause");
  return 0;
}

/*
 Sample Output

Enter the name of an input file: inpu
Could not open inpu.txt for reading (misspelled?)
Enter the name of an input file: input
Counting letter frequency in input.txt...  done!
Writing results to inputOut.txt...  done!
Press any key to continue . . .

inputOut.txt
------------
Character counts found in file (graph approximated): input.txt

a: 112 *************************************
b: 12  ****
c: 45  ***************
d: 46  ***************
e: 143 ***********************************************
f: 6   **
g: 15  *****
h: 11  ***
i: 135 *********************************************
j: 1   
k: 0   
l: 79  **************************
m: 57  *******************
n: 84  ****************************
o: 65  *********************
p: 36  ************
q: 22  *******
r: 79  **************************
s: 119 ***************************************
t: 106 ***********************************
u: 111 *************************************
v: 9   ***
w: 0   
x: 0   
y: 0   
z: 0   


*/
