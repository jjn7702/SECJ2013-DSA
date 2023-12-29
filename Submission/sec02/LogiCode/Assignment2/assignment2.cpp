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

  void insertMiddle2(BookingNode newBooking, string sKey) { // Insert the node after the node with specific value
    BookingNode *temp = head;
    BookingNode *newNode = new BookingNode(newBooking);

    while (temp->getCheckInDate() != sKey) {
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  void insertMiddle3(BookingNode newBooking, string sKey) { // Insert the node before the node with specific value
    BookingNode *temp = head, *prev; // similar to the removeEnd()
    BookingNode *newNode = new BookingNode(newBooking);

    while (temp->getCheckInDate() != sKey) { //(temp->next)
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

  void deleteMid2(int sKey) {
    BookingNode *temp = head, *pre;

    while (temp->getData() != sKey) {
      pre = temp;
      temp = temp->next;
    }

    pre->next = temp->next;
    delete temp;
  }

  void deleteMid3(int sKey) {
    BookingNode *temp = head, *del;

    while (temp->getData() != sKey) {
      temp = temp->next;
      del = temp->next;
    }

    temp->next = del->next;
    delete del;
  }

  void deleteMid4(int sKey) {
    BookingNode *temp = head, *pre;

    while (temp->getData() != sKey) {
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

  void sortList() {
      if (head == NULL || head->next == NULL) {
          cout << "List is empty or has only one node." << endl;
      }

      BookingNode* current = head;
      BookingNode* nextNode = NULL;
      bool swapped;

      do {
          swapped = false;
          current = head;

          while (current->next != nextNode) {
              if (current->data > current->next->data) {
                  swap(current->data, current->next->data);
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
      
    void adminMenu() {
      // BookingNode *booking=new Node();
      int option;
      cout << "Admin Menu" << endl;
      cout << "1. View Booking" << endl;
      cout << "2. Insert Booking" << endl;
      cout << "3. Delete Booking" << endl;
      cout << "4. Search Booking" << endl;
      cout << "5. Sort Booking" << endl;
      cout << "6. Exit" << endl;
      cout << "Enter your option: ";
      cin >> option;
      cout << endl;

      switch (option) {
      case 1:
        dispList();
        break;

      case 2:
        insertMenu();
        break;

      case 3:
        deleteMenu();
        break;

      case 4:
        cout << "Please type the searchkey" << endl;
        cin >> key;
        break;

      case 5:
        break;

      case 6:
        break;

      default:
        cout << "Enter a valid option." << endl;
        adminMenu();
        break;
      }
    }

    int main() {
      cout << "---------------------------------" << endl;
      cout << "LogiCode Hotel Management System" << endl;
      cout << "---------------------------------" << endl;
      adminMenu();
      return 0;
    }
