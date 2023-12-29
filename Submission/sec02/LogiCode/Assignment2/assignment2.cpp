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
        totalPrice(p){ next = NULL; };
  string getCheckInDate() const { return checkInDate; }
  //string getCheckOutDate() const { return checkOutDate; }
  //int getRoomNo() const { return roomNo; }
  //string getRoomType() const { return roomType; }
  //string getIC() const { return ic; }
  //double getTotalPrice() const { return totalPrice; }
  void getBookingInfo() const {
    cout << checkInDate << '\t' << checkOutDate << '\t' << roomNo << '\t' << roomType << '\t' << ic << '\t' << totalPrice << endl;
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

  bool isEmpty(){
    return (head == NULL);
  }

  void insertFront(BookingNode newBooking) {
    BookingNode *newNode = new BookingNode(newBooking);
    if(!isEmpty())
        newNode->next=head;
      head=newNode;
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

  void insertMiddle2(
BookingNode newBooking, string sKey) { // Insert the node after the node with specific value
    BookingNode *temp = head;
    BookingNode *newNode = new BookingNode(d);

      while (temp->getCheckInDate() != sKey) {
        temp = temp->next;
      }

      newNode->next = temp->next;
      temp->next = newNode;
    }

  void insertEnd(BookingNode newBooking){
      BookingNode *temp = head; 
      BookingNode *newNode = new BookingNode(newBooking);

      while (temp->next != NULL)
      {
          temp = temp->next;
      }

      temp->next = newNode;
  }

  void deleteFront() {
    BookingNode *temp = head;
    head = head->next;
    temp->next=NULL;
    delete temp;
    }

};

void insertMenu(){
  cout << "1. Insert " << endl;
  cout << "2. Sort Booking" << endl;
  cout << "3. Insert Booking" << endl;
}
void adminMenu() {
  //BookingNode *booking=new Node();
  int option;
  cout << "Admin Menu" << endl;
  cout << "1. View Booking" << endl;
  cout << "2. Sort Booking" << endl;
  cout << "3. Insert Booking" << endl;
  cout << "4. Delete Booking" << endl;
  cout << "5. Search Booking" << endl;
  cout << "6. Exit" << endl;
  cout << "Enter your option: ";
  cin >> option;
  cout << endl;

  switch (option) {
  case 1:
    break;

  case 2:
    break;

  case 3:
    insertMenu();
    break;

  case 4:
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
