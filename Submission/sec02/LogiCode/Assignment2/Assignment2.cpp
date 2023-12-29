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
  BookingNode()
      : checkInDate(""), checkOutDate(""), roomNo(0), roomType(""), ic(""),
        totalPrice(0.0){};
  BookingNode(string i, string o, int n, string t, string ic_, double p)
      : checkInDate(i), checkOutDate(o), roomNo(n), roomType(t), ic(ic_),
        totalPrice(p){};
  string getCheckInDate() const { return checkInDate; }
  string getCheckOutDate() const { return checkOutDate; }
  int getRoomNo() const { return roomNo; }
  string getRoomType() const { return roomType; }
  string getIC() const { return ic; }
  double getTotalPrice() const { return totalPrice; }
  void getBookingInfo() const {
    cout << getIC() << get
  }
};

class Node {
public:
  Booking data;
  Node *next;

  Node() : next(nullptr) {}
  Node(Booking booking) : data(booking), next(nullptr) {}
};

class List {
private:
  Node *head;

public:
  List() : head(nullptr) {}

  bool isEmpty(){
    return head==NULL;
  }

  void insertFront(Booking newBooking) {
    Node *newNode = new Node(newBooking);
    if(!isEmpty())
        newNode->next=head;
      head=newNode;
    }

  void deleteFront() {
    Node *temp=head;
    head = head->next;
    temp->next=NULL;
    delete temp;
    }

};

int main() {
  
  return 0; 
}
