/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 11
 * File Name:           S9_L11_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            May 12, 2012
 * Instructor:          Prof Paul Thayer
 *
 * Day of Year Class
 * Calculate a month/day from the day of year and vice versa.
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

class DayOfYear {
  private:
    static string monthNames[13];
    static int daysInMonth[13];
    int dayOfYear, month, dayOfMonth;
    static int daysInYear();
    void calcDateFromYear();
    void calcDateFromMonth();
    
  public:
    DayOfYear(int);
    DayOfYear(string, int);
    void print();
    DayOfYear operator++();
    DayOfYear operator++(int);
    DayOfYear operator--();
    DayOfYear operator--(int);
    friend ostream &operator<<(ostream &out, DayOfYear day);
};

// Set monthNames and daysInMonth statically so all DayOfYear classes can use
string DayOfYear::monthNames[]  = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int    DayOfYear::daysInMonth[] = { 0,    31,    29,    31,    30,    31,    30,    31,    31,    30,    31,    30,    31};




int main() {
  
  DayOfYear halfway(365/2);
  halfway.print();
  
  DayOfYear cincoDeMayo("May", 5);
  DayOfYear restDay = ++cincoDeMayo;
  restDay.print();
  
  cout << endl;
  
  int dayNum;
  cout << "What day? ";
  cin >> dayNum;
  DayOfYear day(dayNum - 5);
  
  int counter = 0;
  do {
    cout << day << endl;
    day++;
    
    counter++;
  } while (counter <= 10);
  
  system("pause");
  return 0;
}




DayOfYear::DayOfYear(int dayOfYear) {
  if (dayOfYear < 1 || dayOfYear > DayOfYear::daysInYear()) {
    cout << "Must set a day between 1 and " << DayOfYear::daysInYear() << "." << endl;
    system("pause");
    exit(1);
  }
  
  this->dayOfYear = dayOfYear;
  this->calcDateFromYear();
}

DayOfYear::DayOfYear(string monthName, int monthDay) {
  this->dayOfYear = 0;
  this->dayOfMonth = 0;
  this->month = 0;
  
  // Figure out the month number for the string given
  for (int month = 1; month <= 12; month++) {
    if (DayOfYear::monthNames[month] == monthName) {
      this->month = month;
      break;
    }
  }
  
  if (this->month == 0) {
    cout << "Invalid month name." << endl;
    system("pause");
    exit(1);
  }
  
  if (monthDay < 1 || monthDay > DayOfYear::daysInMonth[this->month]) {
    cout << "Must set a day between 1 and " << DayOfYear::daysInMonth[this->month] << "." << endl;
    system("pause");
    exit(1);
  }
  
  this->dayOfMonth = monthDay;
  this->calcDateFromMonth();
}

// Determine total days in the year based on how many days are in each month
int DayOfYear::daysInYear() {
  int days = 0;
  
  for (int month = 1; month <= 12; month++) {
    days += DayOfYear::daysInMonth[month];
  }
  
  return days;
}

// Turn a day of the year into a month and day of month
void DayOfYear::calcDateFromYear() {
  int totalDaysCounter = this->dayOfYear;
  int monthDaysCounter = 0;
  int month = 1;

  // For every dayOfYear
  while (totalDaysCounter > 0) {
    monthDaysCounter++; // Increment curent dayOfMonth

    // If current dayOfMonth is more than the number of days in month, 
    // move onto next month
    if (monthDaysCounter > DayOfYear::daysInMonth[month]) {
      month++;
      monthDaysCounter = 1;
    }

    totalDaysCounter--;
  }

  this->month = month;
  this->dayOfMonth = monthDaysCounter;
}

// Turn a month and day of month into the day of year
void DayOfYear::calcDateFromMonth() {
  int totalDaysCounter = 0;
  
  for (int month = 1; month < this->month; month++) {
    totalDaysCounter += DayOfYear::daysInMonth[month];
  }
  
  totalDaysCounter += this->dayOfMonth;
  
  this->dayOfYear = totalDaysCounter;
}

void DayOfYear::print() {
  cout << "(" << this->dayOfYear << ") " << DayOfYear::monthNames[this->month] << " " << this->dayOfMonth << endl;
}

/**
 * Operator Overlaods
 */
DayOfYear DayOfYear::operator++() {
  if (this->dayOfYear == DayOfYear::daysInYear()) {
    this->dayOfYear = 1;
  }
  else {
    this->dayOfYear++;
  }
  
  this->calcDateFromYear();
  
  return *this;
}

DayOfYear DayOfYear::operator++(int) {
  DayOfYear temp = *this;
  
  if (this->dayOfYear == DayOfYear::daysInYear()) {
    this->dayOfYear = 1;
  }
  else {
    this->dayOfYear++;
  }
  
  this->calcDateFromYear();
  
  return temp;
}

DayOfYear DayOfYear::operator--() {
  if (this->dayOfYear == 1) {
    this->dayOfYear = DayOfYear::daysInYear();
  }
  else {
    this->dayOfYear--;
  }
  
  this->calcDateFromYear();
  
  return *this;
}

DayOfYear DayOfYear::operator--(int) {
  DayOfYear temp = *this;
  
  if (this->dayOfYear == 1) {
    this->dayOfYear = DayOfYear::daysInYear();
  }
  else {
    this->dayOfYear--;
  }
  
  this->calcDateFromYear();
  
  return temp;
}

ostream &operator<<(ostream& out, DayOfYear day) {
  out << "(" << day.dayOfYear << ") " << DayOfYear::monthNames[day.month] << " " << day.dayOfMonth;
  return out;
}

/*
 Sample Output

(182) Jun 30
(127) May 6

What day? 305
(300) Oct 26
(301) Oct 27
(302) Oct 28
(303) Oct 29
(304) Oct 30
(305) Oct 31
(306) Nov 1
(307) Nov 2
(308) Nov 3
(309) Nov 4
(310) Nov 5
Press any key to continue . . .

*/
