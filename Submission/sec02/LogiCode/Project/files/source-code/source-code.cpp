// SECJ2013 DATA STRUCTURE AND ALGORITHMS
// SEM 1 2023/2024
// Project
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

using namespace std;

struct BookingTreeNode {
  string checkInDate;
  string checkOutDate;
  int roomNo;
  string roomType;
  string ic;
  double totalPrice;

  BookingTreeNode *left;
  BookingTreeNode *right;

  BookingTreeNode(string i, string o, int n, string t, string ic_, double p)
      : checkInDate(i), checkOutDate(o), roomNo(n), roomType(t), ic(ic_),
        totalPrice(p), left(NULL), right(NULL) {}

  void getBookingInfo() const {
    cout << "| " << setw(10) << checkInDate << " | " << setw(10) << checkOutDate
         << " |   " << setw(4) << roomNo << "  |   " << setw(6) << roomType
         << "  | " << setw(12) << ic << " |    " << fixed << setprecision(2)
         << setw(5) << totalPrice << "   |" << endl;
  }
};

class HotelBookingTree {
public:
  HotelBookingTree();
  ~HotelBookingTree();
  bool isEmpty() const;
  int numOfNodes() const;
  void retrieveBooking(string checkInDate, int roomNo, bool &found);
  void insertBooking(BookingTreeNode *newNode);
  void deleteBooking(string checkInDate, int roomNo);
  void displayBooking() const;
  BookingTreeNode *findBooking(string ic);

private:
  BookingTreeNode *root;

  void Destroy(BookingTreeNode *&tree);
  void Insert(BookingTreeNode *&tree, BookingTreeNode *newNode);
  void Retrieve(BookingTreeNode *tree, string checkInDate, int roomNo,
                bool &found);
  void Delete(BookingTreeNode *&tree, string checkInDate, int roomNo);
  void DeleteNode(BookingTreeNode *&tree);
  void GetPredecessor(BookingTreeNode *tree, BookingTreeNode *&predecessor);
  void display(BookingTreeNode *tree) const;
  int CountNodes(BookingTreeNode *tree) const;
};

HotelBookingTree::HotelBookingTree() { root = NULL; }

HotelBookingTree::~HotelBookingTree() { Destroy(root); }

void HotelBookingTree::Destroy(BookingTreeNode *&tree) {
  if (tree != NULL) {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

bool HotelBookingTree::isEmpty() const { return (root == NULL); }

int HotelBookingTree::numOfNodes() const { return CountNodes(root); }

int HotelBookingTree::CountNodes(BookingTreeNode *tree) const {
  if (tree == NULL)
    return 0;
  else
    return 1 + CountNodes(tree->left) + CountNodes(tree->right);
}

void HotelBookingTree::retrieveBooking(string checkInDate, int roomNo,
                                       bool &found) {
  Retrieve(root, checkInDate, roomNo, found);
}

void HotelBookingTree::Retrieve(BookingTreeNode *tree, string checkInDate,
                                int roomNo, bool &found) {
  if (tree == NULL) {
    found = false;
  } else if (checkInDate < tree->checkInDate ||
             (checkInDate == tree->checkInDate && roomNo < tree->roomNo)) {
    Retrieve(tree->left, checkInDate, roomNo, found);
  } else if (checkInDate > tree->checkInDate ||
             (checkInDate == tree->checkInDate && roomNo > tree->roomNo)) {
    Retrieve(tree->right, checkInDate, roomNo, found);
  } else {
    found = true;
  }
}

void HotelBookingTree::insertBooking(BookingTreeNode *newNode) {
  Insert(root, newNode);
}

void HotelBookingTree::Insert(BookingTreeNode *&tree,
                              BookingTreeNode *newNode) {
  if (tree == NULL) {
    tree = newNode;
  } else if (newNode->checkInDate < tree->checkInDate ||
             (newNode->checkInDate == tree->checkInDate &&
              newNode->roomNo < tree->roomNo)) {
    Insert(tree->left, newNode);
  } else {
    Insert(tree->right, newNode);
  }
}

void HotelBookingTree::deleteBooking(string checkInDate, int roomNo) {
  Delete(root, checkInDate, roomNo);
}

void HotelBookingTree::Delete(BookingTreeNode *&tree, string checkInDate,
                              int roomNo) {
  if (tree == NULL) {
    return;
  }

  if (checkInDate < tree->checkInDate ||
      (checkInDate == tree->checkInDate && roomNo < tree->roomNo)) {
    Delete(tree->left, checkInDate, roomNo);
  } else if (checkInDate > tree->checkInDate ||
             (checkInDate == tree->checkInDate && roomNo > tree->roomNo)) {
    Delete(tree->right, checkInDate, roomNo);
  } else {
    DeleteNode(tree);
  }
}

void HotelBookingTree::DeleteNode(BookingTreeNode *&tree) {
  BookingTreeNode *tempNode = tree;
  if (tree->left == NULL) {
    tree = tree->right;
    delete tempNode;
  } else if (tree->right == NULL) {
    tree = tree->left;
    delete tempNode;
  } else {
    GetPredecessor(tree->left, tempNode);
    tree->checkInDate = tempNode->checkInDate;
    tree->roomNo = tempNode->roomNo;
    Delete(tree->left, tempNode->checkInDate, tempNode->roomNo);
  }
}

void HotelBookingTree::GetPredecessor(BookingTreeNode *tree,
                                      BookingTreeNode *&predecessor) {
  while (tree->right != NULL) {
    tree = tree->right;
  }
  predecessor = tree;
}

void HotelBookingTree::displayBooking() const {
  cout << "____________________________________________________________________"
          "__________"
       << endl;
  cout << left << setw(14) << "|  Check-in  |" << setw(13) << "  Check-out |"
       << setw(10) << " Room No |" << setw(12) << " Room Type |" << setw(15)
       << " Customer  IC |" << setw(10) << " Total Price |" << endl;
  cout << "--------------------------------------------------------------------"
          "----------"
       << endl;
  display(root);
  cout << "--------------------------------------------------------------------"
          "----------"
       << endl;
  cout << endl;
}

void HotelBookingTree::display(BookingTreeNode *tree) const {
  if (tree != NULL) {
    display(tree->left);
    tree->getBookingInfo();
    display(tree->right);
  }
}

BookingTreeNode *HotelBookingTree::findBooking(string ic) {
  BookingTreeNode *current = root;

  while (current != NULL) {
    if (ic == current->ic) {
      return current;
    } else if (ic < current->ic) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  return NULL;
}

void readBookingData(HotelBookingTree &bookingTree) {
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
    BookingTreeNode *newNode = new BookingTreeNode(
        checkInDate, checkOutDate, roomNo, roomType, ic, totalPrice);
    bookingTree.insertBooking(newNode);
  }

  bookinginpFile.close();
}

void adminMenu(HotelBookingTree &bookingTree) {
  int option;
  string skey_ic;
  string checkInDate;
  int roomNo;

  do {
    cout << "\nAdmin Menu" << endl;
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
    case 1: {
      cout << "Enter Booking Info: " << endl;
      cout << "Check-In Date (YYYY/MM/DD): ";
      cin >> checkInDate;
      cout << "Room Number: ";
      cin >> roomNo;

      bool found;
      bookingTree.retrieveBooking(checkInDate, roomNo, found);

      if (!found) {
        BookingTreeNode *newNode =
            new BookingTreeNode(checkInDate, "", roomNo, "", "", 0.0);
        bookingTree.insertBooking(newNode);
        cout << "Booking successfully added." << endl;
      } else {
        cout << "Booking with the same Check-In Date and Room Number already "
                "exists."
             << endl;
      }
      break;
    }

    case 2:
      cout << "Enter Booking Info to Delete: " << endl;
      cout << "Check-In Date (YYYY/MM/DD): ";
      cin >> checkInDate;
      cout << "Room Number: ";
      cin >> roomNo;
      bookingTree.deleteBooking(checkInDate, roomNo);
      break;

    case 3:
      cout << "Please type the search key (IC without '-')" << endl;
      cin >> skey_ic;
      if (bookingTree.findBooking(skey_ic) != NULL) {
        cout << "The booking data is found." << endl;
      } else {
        cout << "No booking data found." << endl;
      }
      break;

    case 4:
      cout << "Sorting Booking by Check-In Date" << endl;
      bookingTree.displayBooking();
      break;

    case 5:
      cout << "Viewing Booking" << endl;
      bookingTree.displayBooking();
      break;

    case 6:
      break;

    default:
      cout << "Enter a valid option." << endl;
      adminMenu(bookingTree);
      break;
    }
  } while (option != 6);
}

int main() {
  HotelBookingTree bookingTree;
  readBookingData(bookingTree);

  cout << "---------------------------------" << endl;
  cout << "LogiCode Hotel Management System" << endl;
  cout << "---------------------------------" << endl;
  adminMenu(bookingTree);

  return 0;
}
