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
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
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

  void insertMiddle2COD(BookingNode newBooking, string sKey) { // Insert the node after the node with specific value
    BookingNode *temp = head;
    BookingNode *newNode = new BookingNode(newBooking);

    while (temp->getCheckOutDate() != sKey) {
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  void insertMiddle3COD(BookingNode newBooking, string sKey) { // Insert the node before the node with specific value
    BookingNode *temp = head, *prev; // similar to the removeEnd()
    BookingNode *newNode = new BookingNode(newBooking);

    while (temp->getCheckOutDate() != sKey) { //(temp->next)
      prev = temp;
      temp = temp->next;
    }

    newNode->next = temp;
    prev->next = newNode;
  }

  void insertMiddle2RN(BookingNode newBooking, int sKey) { // Insert the node after the node with specific value
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

  void deleteMid2CID(string sKey) {
    BookingNode *temp = head, *pre;

    while (temp->getCheckInDate() != sKey) {
      pre = temp;
      temp = temp->next;
    }

    pre->next = temp->next;
    delete temp;
  }

  void deleteMid3CID(string sKey) {
    BookingNode *temp = head, *del;

    while (temp->getCheckInDate() != sKey) {
      temp = temp->next;
      del = temp->next;
    }

    temp->next = del->next;
    delete del;
  }

  void deleteMid4CID(string sKey) {
    BookingNode *temp = head, *pre;

    while (temp->getCheckInDate() != sKey) {
      pre = temp;
      temp = temp->next;
    }

    pre->next = temp->next;
    delete temp;
  }

  void deleteMid2COD(string sKey) {
    BookingNode *temp = head, *pre;

    while (temp->getCheckOutDate() != sKey) {
      pre = temp;
      temp = temp->next;
    }

    pre->next = temp->next;
    delete temp;
  }

  void deleteMid3COD(string sKey) {
    BookingNode *temp = head, *del;

    while (temp->getCheckOutDate() != sKey) {
      temp = temp->next;
      del = temp->next;
    }

    temp->next = del->next;
    delete del;
  }

  void deleteMid4COD(string sKey) {
    BookingNode *temp = head, *pre;

    while (temp->getCheckOutDate() != sKey) {
      pre = temp;
      temp = temp->next;
    }

    pre->next = temp->next;
    delete temp;
  }

  void deleteMid2RN(int sKey) {
    BookingNode *temp = head, *pre;

    while (temp->getRoomNo() != sKey) {
      pre = temp;
      temp = temp->next;
    }

    pre->next = temp->next;
    delete temp;
  }

  void deleteMid3RN(int sKey) {
    BookingNode *temp = head, *del;

    while (temp->getRoomNo() != sKey) {
      temp = temp->next;
      del = temp->next;
    }

    temp->next = del->next;
    delete del;
  }

  void deleteMid4RN(int sKey) {
    BookingNode *temp = head, *pre;

    while (temp->getRoomNo() != sKey) {
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

    while (temp != NULL) {
      temp->getBookingInfo();
      cout << "\t";
      temp = temp->next;
    }
    cout << endl;
  }

  void swapNodes(BookingNode* node1, BookingNode* node2) {
    BookingNode *tempNode = new BookingNode(
        node2->getCheckInDate(), node2->getCheckOutDate(), node2->getRoomNo(),
        node2->getRoomType(), node2->getIC(), node2->getTotalPrice());
    
    *node2 = BookingNode(
      node1->getCheckInDate(), node1->getCheckOutDate(), node1->getRoomNo(), 
      node1->getRoomType(), node1->getIC(), node1->getTotalPrice());

    *node1 = *tempNode;

    delete tempNode;
  }

  void sortList() {
      if (head == NULL || head->next == NULL) {
          cout << "List is empty or has only one node." << endl;
          return;
      }
  
      BookingNode* current = head;
      BookingNode* nextNode = NULL;
      bool swapped;
  
      do {
          swapped = false;
          current = head;
  
          while (current->next != nextNode) {
              if (current->getCheckInDate() > current->next->getCheckInDate()) {
                  // swapNodes(current, current->next); 
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

        BookingNode* current = head;
        BookingNode* nextNode = NULL;
        bool swapped;

        do {
            swapped = false;
            BookingNode* temp = head;
            BookingNode* pre = head;

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
};

void insertMenu() {
  int option;
  int position;
  // BookingNode *booking=new Node();
  cout << "1. Insert New Booking at Front" << endl;
  cout << "2. Insert New Booking at Position" << endl;
  cout << "3. Insert New Booking before Position" << endl;
  cout << "4. Insert New Booking after Position" << endl;
  cout << "5. Insert New Booking at End" << endl;
  cout << "6. Exit" << endl;
  cin >> option;
  cout << endl;
  switch (option) {
  case 1:
    
    break;
    
  case 2:
    cout<<"Position: "<<endl;
    cin>>position;
    break;
    
  case 3:
    cout<<"Position: "<<endl;
    cin>>position;
    break;
    
  case 4:
    cout<<"Position: "<<endl;
    cin>>position;
    break;
    
  case 5:
    
    break;
    
  case 6:
    break;
    
  default:
    cout << "Enter a valid option." << endl;
    insertMenu();
    break;
  }
  
  void deleteMenu() {
    int option;
    int position;
    // BookingNode *booking=new Node();
    cout << "1. Delete the first booking" << endl;
    cout << "2. Delete the last booking" << endl;
    cout << "3. Delete at a specific position" << endl;
    cout << "4. Delete after a specific position" << endl;
    cout << "5. Delete before a specific position" << endl;
    cout << "6. Exit" << endl;
    cin >> option;
    cout << endl;
    switch (option) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      cout << "Position:" << endl;
      cin >> position;
      break;
    case 4:
      cout << "Position:" << endl;
      cin >> position;
      break;
    case 5:
        cout << "Position:" << endl;
        cin >> position;
        break;
    case 6:
        break;
    default:
      cout << "Enter a valid option." << endl;
      insertMenu();
      break;
    }
  }
      
    void adminMenu() {
      //List list;
      int option;
      cout << "Admin Menu" << endl;
      cout << "1. Insert Booking" << endl;
      cout << "2. Delete Booking" << endl;
      cout << "3. Search Booking" << endl;
      cout << "4. Sort Booking" << endl;
      cout << "5. Exit" << endl;
      cout << "Enter your option: ";
      cin >> option;
      cout << endl;

      switch (option) {
      case 1:
        insertMenu();
        break;

      case 2:
        deleteMenu();
        break;

      case 3:
        cout << "Please type the searchkey" << endl;
        cin >> key;
        break;

      case 4:
        break;

      case 5:
        break;

      default:
        cout << "Enter a valid option." << endl;
        adminMenu();
        break;
      }
    }

    int main() {
      List bookingList;
      cout << "---------------------------------" << endl;
      cout << "LogiCode Hotel Management System" << endl;
      cout << "---------------------------------" << endl;
      bookingList.dispList();
      adminMenu();
      return 0;
    }
