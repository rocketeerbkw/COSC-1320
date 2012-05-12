/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 17
 * File Name:           S9_L17_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            May 12, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program demonstrates linked lists
 *
 * Source code modified from code in
 *
 * Starting Out With C++
 * Early Objects, Seventh Edition
 * Tony Gaddis, Judy Walters, Godfrey Muganda
 * Publisher Addison-Wesley
 *
 * Copyright Respective Owners
 */

#include <iostream>
using namespace std;

class NumberList {
  protected:
    // Declare a class for the list node.
    struct ListNode {
      double value;
      ListNode *next;
      ListNode(double value1, ListNode *next1 = NULL) {
          value = value1;
          next = next1;
      }
    };
    ListNode *head;                   // List head pointer
    ListNode *tail;                   // List tail pointer

  public:
    NumberList() { head = NULL;  }    // Constructor
    ~NumberList();                    // Destructor
    void add(double number);
    void remove(double number);
    void displayList();
};

//*****************************************************
// add adds a new element to the end of the list.     *
//*****************************************************
void NumberList::add(double number) {
  if (head == NULL) {
    head = new ListNode(number);
    tail = head;
  }
  else {
    // The list is not empty. Add to end of list
    ListNode *nodePtr = tail;
    nodePtr->next = new ListNode(number);
    tail = nodePtr->next;
  }
}

int main() {
  NumberList list;
  list.add(2.5);
  list.add(7.9);
  list.add(12.6);
  list.add(14.3);
  list.add(27.11);
  list.displayList();
  cout << endl;
  system("pause");
  return 0;
}

//***************************************************
// displayList outputs a sequence of all values     *
// currently stored in the list.                    *
//***************************************************
void NumberList::displayList() {
  ListNode *nodePtr = head;   // Start at head of list
  while (nodePtr) {
    // Print the value in the current node
    cout << nodePtr->value << "    ";
    // Move on to the next node
    nodePtr = nodePtr->next;
  }
}

//******************************************************
// Destructor deallocates the memory used by the list. *
//******************************************************
NumberList::~NumberList() {
  ListNode *nodePtr = head;  // Start at head of list
  while (nodePtr != NULL) {
    // garbage keeps track of node to be deleted
    ListNode *garbage = nodePtr;
    // Move on to the next node, if any
    nodePtr = nodePtr->next;
    // Delete the "garbage" node
    delete garbage;
  }
}
