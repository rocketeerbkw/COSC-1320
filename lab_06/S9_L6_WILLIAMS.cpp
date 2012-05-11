/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 6
 * File Name:           S9_L6_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            Feb 25, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program calculates the charges for a hospital patient depending on if
 * they are an in-patient or out-patient.
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

// Function prototypes
double getPositiveNumberFromUser(string msg);
double calculateCharges(double services, double meds, bool outpatient);
double calculateCharges(double services, double meds, double days = 2, double day_rate = 500);

int main() {
  
  cout << "Calculate Hopital Charges\n-------------------------" << endl << endl;
  
  // Allow calculating charges for many patients
  do {
    char patient_type;
    cout << "Are they an (I)npatient or (O)utpatient? ";
    cin >> patient_type;
    
    double services, meds, days, day_rate, total;
    
    // Determine charge for In or Out patients
    switch (tolower(patient_type)) {
      case 'i': // In-Patient
        char routine;
        bool is_routine;
        
        do {
          cout << "  Was it a routine stay? Y/N ";
          cin >> routine;
          
          if (tolower(routine) == 'y' || tolower(routine) == 'n') {
            is_routine = tolower(routine) == 'y' ? true : false;
            break;
          }
          else {
            cout << "That is not a valid selection." << endl;
            continue;
          }
        } while(true);
        
        services = getPositiveNumberFromUser("Cost of hospital services? $");
        meds = getPositiveNumberFromUser("Cost of medication? $");
        
        if (!is_routine) {
          days = getPositiveNumberFromUser("How many days in the hospital? $");
          day_rate = getPositiveNumberFromUser("Daily rate? $");
          total = calculateCharges(services, meds, days, day_rate);
        }
        else {
          total = calculateCharges(services, meds);
        }
        break;
        
      case 'o': // Out-Patient
        services = getPositiveNumberFromUser("Cost of hospital services? $");
        meds = getPositiveNumberFromUser("Cost of medication? $");
        total = calculateCharges(services, meds, true);
        break;
        
      default:
        cout << "That is not a valid selection." << endl;
        continue;
    }
    
    cout << "Total charges: $" << total << endl;
    
    cout << endl;
    
    // See if they want to continue
    char another;
    cout << "Calculate another patient? Y/N ";
    cin >> another;
    
    if (tolower(another) == 'n') {
      break;
    }
    
  } while (true);
  
  system("pause");
  return 0;
}

double getPositiveNumberFromUser(string msg) {
  double input;
  int tries = 0;
  
  do {
    if (tries >= 3) {
      cout << "Sorry you have run out of tries." << endl;
      system("pause");
      exit(0);
    }
    
    cout << msg;
    cin >> input;
    
    if (!cin.fail() && input >= 0) {
      return input;
    }
    
    cout << "Please enter a positive number." << endl;
    cin.clear();
    cin.ignore();
    tries++;
  } while (true);
}

// Calculate out-patient charges
double calculateCharges(double services, double meds, bool outpatient) {
  return services + meds;
}

// Calculate in-patient charges
double calculateCharges(double services, double meds, double days, double day_rate) {
  double total_day_charges = days * day_rate;
  return services + meds + total_day_charges;
}

/*
 Sample Output
 
Calculate Hopital Charges
-------------------------

Are they an (I)npatient or (O)utpatient? i
  Was it a routine stay? Y/N y
Cost of hospital services? $100.40
Cost of medication? $236.72
Total charges: $1337.12

Calculate another patient? Y/N y
Are they an (I)npatient or (O)utpatient? i
  Was it a routine stay? Y/N n
Cost of hospital services? $2000
Cost of medication? $0
How many days in the hospital? $4
Daily rate? $75
Total charges: $2300

Calculate another patient? Y/N y
Are they an (I)npatient or (O)utpatient? o
Cost of hospital services? $652.80
Cost of medication? $89
Total charges: $741.8

Calculate another patient? Y/N n
Press any key to continue . . .

*/
