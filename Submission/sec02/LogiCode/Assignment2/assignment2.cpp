// SECJ2013 DATA STRUCTURE AND ALGORITHMS
// SEM 1 2023/2024
// Assignment 2
// Section : 02
// Lecturer : Ms. Lizawati binti Mi Yusuf

// Group Name : LogiCode
// Group Members :
// 1. Ong Yi Yan (A22EC0101)
// 2. Tang Yan Qing (A22EC0109)
// 3. Koh Su Xuan (A22EC0060)

// Topic/ Case Study: Hotel Booking System
//----------------------------------------
#include <bits/stdc++.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#define MAXSIZE 10
using namespace std;

class BookingNode {
  string checkInDate;
  string checkOutDate;
  int roomNo;
  string roomType;
  string ic;
  double totalPrice;

public:
  BookingNode *next;
  BookingNode()
      : checkInDate(""), checkOutDate(""), roomNo(0), roomType(""), ic(""),
        totalPrice(0.0){};
  BookingNode(string i, string o, int n, string t, string ic_, double p)
      : checkInDate(i), checkOutDate(o), roomNo(n), roomType(t), ic(ic_),
        totalPrice(p) {
    next = NULL;
  };
  string getCheckInDate() const { return checkInDate; }
  string getCheckOutDate() const { return checkOutDate; }
  int getRoomNo() const { return roomNo; }
  string getRoomType() const { return roomType; }
  string getIC() const { return ic; }
  double getTotalPrice() const { return totalPrice; }
  void getBookingInfo() const {
    cout << checkInDate << "\t" << checkOutDate << "\t" << roomNo << "\t"
         << roomType << "\t" << ic << "\t" << totalPrice << endl;
  }
};

/*class Node {
public:
  Booking data;
  Node *next;

  Node() : next(nullptr) {}
  Node(Booking booking) : data(booking), next(nullptr) {}
};*/

class List {
private:
  BookingNode *head;

public:
  List() : head(nullptr) {}

  bool isEmpty() { return (head == NULL); }

  void insertFront(BookingNode newBooking) {
    BookingNode *newNode = new BookingNode(newBooking);
    if (!isEmpty())
      newNode->next = head;
    head = newNode;
  }

  void insertMiddle(BookingNode newBooking, int loc) {
    BookingNode *temp = head;
    BookingNode *newNode = new BookingNode(newBooking);
    int count = 1;

    while (temp->next != NULL && count < loc) {
      temp = temp->next;
      count++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  void insertMiddle2CID(BookingNode newBooking, string sKey) { // Insert the node after the node with specific value
    BookingNode *temp = head;
    BookingNode *newNode = new BookingNode(newBooking);

    while (temp->getCheckInDate() != sKey) {
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  void insertMiddle3CID(BookingNode newBooking, string sKey) { // Insert the node before the node with specific value
    BookingNode *temp = head, *prev; // similar to the removeEnd()
    BookingNode *newNode = new BookingNode(newBooking);

    while (temp->getCheckInDate() != sKey) { //(temp->next)
      prev = temp;
      temp = temp->next;
    }

    newNode->next = temp;
    prev->next = newNode;
  }

  void insertMiddle2COD(
      BookingNode newBooking,
      string sKey) { // Insert the node after the node with specific value
    BookingNode *temp = head;
    BookingNode *newNode = new BookingNode(newBooking);

    while (temp->getCheckOutDate() != sKey) {
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  void insertMiddle3COD(
      BookingNode newBooking,
      string sKey) { // Insert the node before the node with specific value
    BookingNode *temp = head, *prev; // similar to the removeEnd()
    BookingNode *newNode = new BookingNode(newBooking);

    while (temp->getCheckOutDate() != sKey) { //(temp->next)
      prev = temp;
      temp = temp->next;
    }

    newNode->next = temp;
    prev->next = newNode;
  }

  void insertMiddle2RN(
      BookingNode newBooking,
      int sKey) { // Insert the node after the node with specific value
    BookingNode *temp = head;
    BookingNode *newNode = new BookingNode(newBooking);

    while (temp->getRoomNo() != sKey) {
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  void insertMiddle3RN(BookingNode newBooking, int sKey) { // Insert the node before the node with specific value
    BookingNode *temp = head, *prev; // similar to the removeEnd()
    BookingNode *newNode = new BookingNode(newBooking);

    while (temp->getRoomNo() != sKey) { //(temp->next)
      prev = temp;
      temp = temp->next;
    }

    newNode->next = temp;
    prev->next = newNode;
  }

  void insertEnd(BookingNode newBooking) {
    BookingNode *temp = head;
    BookingNode *newNode = new BookingNode(newBooking);

    if (head == NULL) {
        head = newNode;
        return;
    }
    
    while (temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = newNode;
  }

  void deleteFront() {
    BookingNode *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
  }

  void deleteMid(int loc) {
    BookingNode *temp = head, *pre;
    int count = 1;

    while (temp->next != NULL && count < loc) {
      pre = temp;
      temp = temp->next;
      count++;
    }

    pre->next = temp->next;
    delete temp;
  }

  void deleteMidCR(string sKey1, int sKey2) {
    BookingNode *temp = head, *pre;

    while ((temp->getCheckInDate() != sKey1)&&(temp->getRoomNo() != sKey2)) {
      pre = temp;
      temp = temp->next;
    }

    pre->next = temp->next;
    delete temp;
  }

  void deleteEnd() {
    BookingNode *temp = head, *pre;

    while (temp->next != NULL) {
      pre = temp;
      temp = temp->next;
    }

    delete temp;
    pre->next = NULL;
  }

  void dispList() {
    BookingNode *temp = head;
    int i = 0;
    while (temp != NULL) {
      ++i;
      cout << i << " ";
      temp->getBookingInfo();
      cout << "\t";
      temp = temp->next;
    }
    cout << endl;
  }

  void swapNodes(BookingNode *node1, BookingNode *node2) {
    BookingNode *tempNode = new BookingNode(
        node2->getCheckInDate(), node2->getCheckOutDate(), node2->getRoomNo(),
        node2->getRoomType(), node2->getIC(), node2->getTotalPrice());

    *node2 = BookingNode(node1->getCheckInDate(), node1->getCheckOutDate(),
                         node1->getRoomNo(), node1->getRoomType(),
                         node1->getIC(), node1->getTotalPrice());

    *node1 = *tempNode;

    delete tempNode;
  }

  void sortList() {
    if (head == NULL || head->next == NULL) {
      cout << "List is empty or has only one node." << endl;
      return;
    }

    BookingNode *current = head;
    BookingNode *nextNode = NULL;
    bool swapped;

    do {
      swapped = false;
      current = head;

      while (current->next != nextNode) {
        if (current->getCheckInDate() > current->next->getCheckInDate()) {
          swapNodes(current, current->next);
          swapped = true;
        }
        current = current->next;
      }
      nextNode = current;
    } while (swapped);
  }

  void sortList2() {
    if (head == NULL || head->next == NULL) {
      cout << "List is empty or has only one node." << endl;
      return;
    }

    BookingNode *current = head;
    BookingNode *nextNode = NULL;
    bool swapped;

    do {
      swapped = false;
      BookingNode *temp = head;
      BookingNode *pre = head;

      while (current->next != nextNode) {
        if (current->getCheckInDate() > current->next->getCheckInDate()) {
          pre->next = temp->next;
          temp->next = temp->next->next;
          pre->next->next = temp;
          swapped = true;
        }
        current = current->next;
      }
      nextNode = current;
    } while (swapped);
  }

  int FindNode(string ic) {
    BookingNode *temp = head;
    int count = 1;

    while(temp && temp->getIC() != ic) {
      temp = temp->next;
      count++;
    }

    if(temp) {
      return count;
    } 
    else {
     return 0;   
  }
  }
};

void readBookingData(List &bookingList) {
    ifstream bookinginpFile("booking.txt");
    if (!bookinginpFile.is_open()) {
        cout << "Unable to open file!" << endl;
        return;
    }

    string checkInDate;
    string checkOutDate;
    int roomNo;
    string roomType;
    string ic;
    double totalPrice;
    
    while (bookinginpFile >> checkInDate >> checkOutDate >> roomNo >> roomType >>
           ic >> totalPrice) {
        BookingNode newNode(checkInDate, checkOutDate, roomNo, roomType, ic, totalPrice);
          bookingList.insertEnd(newNode);
    }

    bookinginpFile.close();
}

void insertMenu(List &bookingList) {
  int option;
  int position;
  string checkInDate;
  string checkOutDate;
  int roomNo;
  string roomType;
  string ic;
  double totalPrice;
  string sKey;
  int sKey2;
  
  cout << "1. Insert New Booking at Front" << endl;
  cout << "2. Insert New Booking at Position" << endl;
  cout << "3. Insert New Booking before Position" << endl;
  cout << "4. Insert New Booking after Position" << endl;
  cout << "5. Insert New Booking before Specific Check-In Date" << endl;
  cout << "6. Insert New Booking after Specific Check-In Date" << endl;
  cout << "7. Insert New Booking before Specific Check-Out Date" << endl;
  cout << "8. Insert New Booking after Specific Check-Out Date" << endl;
  cout << "9. Insert New Booking before Specific Room Number" << endl;
  cout << "10. Insert New Booking after Specific Room Number" << endl;
  cout << "11. Insert New Booking at End" << endl;
  cout << "12. Exit" << endl;
  cin >> option;
  cout << endl;

  cout << "Enter Booking Info: " << endl;
  cout << "Check-In Date (YYYY/MM/DD) : ";
  getline(cin, checkInDate);
  cin.ignore();
  cout << "Check-Out Date (YYYY/MM/DD) : ";
  getline(cin, checkOutDate);
  cout << "Room Number: ";
  cin >> roomNo;
  cout << "Room Type (Single/ Double/ Queen/ King) : ";
  getline(cin, roomType);
  cout << "IC (Without '-'): ";
  getline(cin, ic);
  cout << "Total Price: RM ";
  cin >> totalPrice;

  BookingNode newbooking(checkInDate, checkOutDate, roomNo, roomType, ic, totalPrice);
  
  switch (option) {
  case 1:
    bookingList.insertFront(newbooking);
    break;
    
  case 2:
    cout << "Position: " << endl;
    cin >> position;
    bookingList.insertMiddle(newbooking, position - 1);
    break;
    
  case 3:
    cout << "Position: " << endl;
    cin >> position;
    bookingList.insertMiddle(newbooking, position - 2);
    break;

  case 4:
    cout << "Position: " << endl;
    cin >> position;
    bookingList.insertMiddle(newbooking, position);
    break;

  case 5:
    cout << "Insert Booking before Check-In Date (YYYY/MM/DD) : ";
    cin >> sKey;
    bookingList.insertMiddle3CID(newbooking, sKey);
    break;

  case 6:
    cout << "Insert Booking after Check-In Date (YYYY/MM/DD) : ";
    cin >> sKey;
    bookingList.insertMiddle2CID(newbooking, sKey);
    break;

  case 7:
    cout << "Insert Booking before Check-Out Date (YYYY/MM/DD) : ";
    cin >> sKey;
    bookingList.insertMiddle3COD(newbooking, sKey);
    break;

  case 8:
    cout << "Insert Booking after Check-Out Date (YYYY/MM/DD) : ";
    cin >> sKey;
    bookingList.insertMiddle2COD(newbooking, sKey);
    break;

  case 9:
    cout << "Insert Booking before Room Number : ";
    cin >> sKey;
    bookingList.insertMiddle3RN(newbooking, sKey2);
    break;

  case 10:
    cout << "Insert Booking after Room Number : ";
    cin >> sKey;
    bookingList.insertMiddle2RN(newbooking, sKey2);
    break;

  case 11:
    bookingList.insertEnd(newbooking);
    break;

  case 12:
    break;

  default:
    cout << "Enter a valid option." << endl;
    insertMenu(bookingList);
    break;
  }
}

  void deleteMenu(List &bookingList) {
    int option;
    int position;
    string checkInDate;
    int roomNo;
    bookingList.dispList();

    cout << "1. Delete the First Booking" << endl;
    cout << "2. Delete at a Specific Position" << endl;
    cout << "3. Delete Booking at Specific Check-In Date and Room No" << endl;
    cout << "4. Delete the Last Booking" << endl;
    cout << "5. Exit" << endl;
    cin >> option;
    cout << endl;
    
    switch (option) {
    case 1:
      bookingList.deleteFront();
      break;
    case 2:
      cout << "Position:" << endl;
      cin >> position;
      bookingList.deleteMid(position);
      break;
    case 3:
      cout << "Check In Date:" << endl;
      getline(cin, checkInDate);
      cout << "Room Number:" << endl;
      cin >> roomNo;
      bookingList.deleteMidCR(checkInDate, roomNo);
      break;
    case 4:
      bookingList.deleteEnd();
      break;
    case 5:
      break;
    default:
      cout << "Enter a valid option." << endl;
      deleteMenu(bookingList);
      break;
    }
  }

  void adminMenu(List &bookingList) {
    int option;
    string skey_ic;
    
    cout << "Admin Menu" << endl;
    cout << "1. Insert Booking" << endl;
    cout << "2. Delete Booking" << endl;
    cout << "3. Search Booking" << endl;
    cout << "4. Sort Booking" << endl;
    cout << "5. View Booking" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your option: ";
    cin >> option;
    cout << endl;

    switch (option) {
    case 1:
      insertMenu(bookingList);
      break;

    case 2:
      deleteMenu(bookingList);
      break;

    case 3:
      cout << "Please type the search key (IC without '-')" << endl;
      cin >> skey_ic;
      cout << "The booking data is at Position " << bookingList.FindNode(skey_ic) << endl;
      break;

    case 4:
      cout << "Sorting Booking by Check-In Date" << endl;
      bookingList.sortList();
      break;

    case 5:
      bookingList.dispList();
      break;

    case 6:
      break;

    default:
      cout << "Enter a valid option." << endl;
      adminMenu(bookingList);
      break;
    }
  }

  int main() {
    List bookingList;
    readBookingData(bookingList);
    cout << "---------------------------------" << endl;
    cout << "LogiCode Hotel Management System" << endl;
    cout << "---------------------------------" << endl;
    adminMenu(bookingList);
    return 0;
  }
