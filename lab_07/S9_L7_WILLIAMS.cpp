/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 7
 * File Name:           S9_L7_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            Feb 25, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program keeps an inventory of items.
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
#include <string>
using namespace std;

// Class and Function prototypes
class Inventory
{
  private:
    int itemNumber;
    string description;
    int quantity;
    double cost;
    double totalCost;
    
  public:
    Inventory();
    Inventory(int number, string descrip, int qty, int cst);
    int getItemNumber();
    string getDescription();
    int getQuantity();
    double getCost();
    double getTotalCost();
    void setItemNumber(int number);
    void setDescription(string descrip);
    void setQuantity(int qty);
    void setCost(double cst);
};

double getPositiveNumberFromUser(string msg);


// Driver code for Inventory Class
int main() {
  
  cout << "Inventory Tracker v1.0\n------------------------" << endl << endl;
  
  int numInventory = 0;
  
  while (numInventory < 1) {
    cout << "How many items in inventory? ";
    cin >> numInventory;
    
    if (cin.fail() || numInventory > 10) {
      cout << (cin.fail() ? "Please enter a valid number" : "You may only have up to 10 items") << endl;
      cin.clear();
      cin.ignore();
      numInventory = 0;
    }
  }
  
  Inventory items[numInventory];
  
  // Collect inventory info
  for (int item = 0; item < numInventory; item++) {
    int itemNumber, qty;
    string descrip;
    double cost;
    
    cout << "Item " << item << endl;
    
    itemNumber = getPositiveNumberFromUser(" Item Number: ");
    items[item].setItemNumber(itemNumber);
    
    cout << " Description: ";
    getline(cin, descrip);
    items[item].setDescription(descrip);
    
    qty = getPositiveNumberFromUser(" Quantity: ");
    items[item].setQuantity(qty);
    
    cost = getPositiveNumberFromUser(" Cost: ");
    items[item].setCost(cost);
    
    cout << endl << endl;
  }
  
  // Output the inventory info we collected
  double inventory_worth = 0;
  int inventory_qty = 0;
  int spacing = 9;
  
  cout << left << setw(10) << "Item"
     << setw(6) << "Qty"
     << setw(12) << "Cost"
     << setw(12) << "Total"
     << "Description\n-\n";
     
  for (int item = 0; item < numInventory; item++) {
    cout << setw(10) << items[item].getItemNumber()
         << setw(6) << items[item].getQuantity()
         << "$" << setw(11) << fixed << setprecision(2) << items[item].getCost()
         << "$" << setw(11) << fixed << setprecision(2) << items[item].getTotalCost()
         << items[item].getDescription() << endl;
         
    inventory_qty += items[item].getQuantity();
    inventory_worth += items[item].getTotalCost();
  }
  
  cout << "-\nTotal     " << setw(18) << inventory_qty;
  cout << "$" << fixed << setprecision(2) << inventory_worth << endl;
  
  system("pause");
  return 0;
}

// Function definitions
Inventory::Inventory() {
  itemNumber = quantity = 0;
  cost = totalCost = 0;
  description = "";
}

Inventory::Inventory(int number, string descrip, int qty, int cst) {
  setItemNumber(number);
  setDescription(descrip);
  setQuantity(qty);
  setCost(cst);
}

int Inventory::getItemNumber() {
  return itemNumber;
}

string Inventory::getDescription() {
  return description;
}

int Inventory::getQuantity() {
  return quantity;
}

double Inventory::getCost() {
  return cost;
}

double Inventory::getTotalCost() {
  return cost * quantity;
}

void Inventory::setItemNumber(int number) {
  itemNumber = number;
}

void Inventory::setDescription(string descrip) {
  description = descrip;
}

void Inventory::setQuantity(int qty) {
  quantity = qty;
}

void Inventory::setCost(double cst) {
  cost = cst;
}

double getPositiveNumberFromUser(string msg) {
  double input;
  
  do {
    cout << msg;
    cin >> input;
    
    if (!cin.fail() && input >= 0) {
      cin.ignore(); // Clear left over newline char in buffer
      return input;
    }
    
    cout << "Please enter a positive number." << endl;
    cin.clear();
    cin.ignore();
  } while (true);
}


/*
 Sample Output

Inventory Tracker v1.0
------------------------

How many items in inventory? 5
Item 0
 Item Number: 1
 Description: White Shirt
 Quantity: 1
 Cost: 1


Item 1
 Item Number: 2
 Description: Green Shirt
 Quantity: 2
 Cost: 2


Item 2
 Item Number: 3
 Description: Red Shirt
 Quantity: 3
 Cost: 3


Item 3
 Item Number: 4
 Description: Blue Shirt
 Quantity: 4
 Cost: 4


Item 4
 Item Number: 5
 Description: Purple Shirt
 Quantity: 5
 Cost: 5


Item      Qty   Cost        Total       Description
-
1         1     $1.00       $1.00       White Shirt
2         2     $2.00       $4.00       Green Shirt
3         3     $3.00       $9.00       Red Shirt
4         4     $4.00       $16.00      Blue Shirt
5         5     $5.00       $25.00      Purple Shirt
-
Total     15                $55.00
Press any key to continue . . . 

*/
