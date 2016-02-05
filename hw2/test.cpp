#include "llistint.h"
#include <iostream>
#include "llistint.cpp"
using namespace std;

int main() {
  LListInt * list = new LListInt();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  list->insert(0, 3);//test if it can insert in an empty list
  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }
  if (list->get(0) == 3) {
    cout << "SUCCESS: 3 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }
  
  list->insert(1, 2);//test if it can insert at end of the list
  if (list->size() == 2) {
    cout << "SUCCESS: List has size 2 after one insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }
  if (list->get(1) == 2) {
    cout << "SUCCESS: 2 is at the 1th index of the list." << endl;
  } else {
    cout << "FAIL: 2 is not at the 1th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }
  
  list ->insert(0,4);//if it can insert at the front of the list
  if (list->size() == 3) {
    cout << "SUCCESS: List has size 3 after one insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }
  if (list->get(0) == 4) {
    cout << "SUCCESS: 4 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 4 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }
  
  list -> insert(5,3);//loc>size
  list -> insert(-1,3);//loc < 0, test insert in invalid location
  if (list->size() == 3) {
    cout << "SUCCESS: List has size 3 after one insertion." << endl;
  } 
  else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }
  
  
  list -> remove(2);//test if it can remove at end of list
  if (list->size() == 2) {
    cout << "SUCCESS: List has size 2 after one insertion." << endl;
  } 
  else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }
  
  list -> remove(0);//test if it can remove at beginning of the list
  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  } 
  else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  list -> remove(5);
  list -> remove(-1);//test if remove returns after getting invalid location
  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  } 
  else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } 
  else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  } 
  else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  list -> remove(0);//test if it can remove last element in list
  if (list->empty()) {
    cout << "SUCCESS: List is empty." << endl;
  } 
  else {
    cout << "FAIL: List is not empty ." << endl;
  }



  // Clean up memory.
  delete list;
}
