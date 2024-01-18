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
#define SIZE 50
using namespace std;

class Admin
{
public:
  string name;
  string position;
  string username;
  string password;

  Admin() {}
  Admin(string n, string p, string u, string pwd)
      : name(n), position(p), username(u), password(pwd) {}

  string getName() const { return name; }
  string getPosition() const { return position; }
  string getUsername() const { return username; }
  string getPassword() const { return password; }
};

class AdminNode
{
public:
  Admin user;
  AdminNode *left;
  AdminNode *right;

  AdminNode() : user(), left(NULL), right(NULL) {}
  AdminNode(const Admin &u, AdminNode *l, AdminNode *r)
      : user(u), left(l), right(r) {}
};

class AdminAuthentication
{
private:
  AdminNode *root;

public:
  AdminAuthentication() : root(NULL) {}

  void addAdmin(string n, string p, string u, string pwd)
  {
    if (root == NULL)
    {
      root = new AdminNode(Admin(n, p, u, pwd), NULL, NULL);
      return;
    }

    AdminNode *current = root;
    AdminNode *parent = NULL;

    while (current != NULL)
    {
      parent = current;

      if (u < current->user.getUsername())
      {
        current = current->left;
      }
      else if (u > current->user.getUsername())
      {
        current = current->right;
      }
      else
      {
        return;
      }
    }

    if (u < parent->user.getUsername())
    {
      parent->left = new AdminNode(Admin(n, p, u, pwd), NULL, NULL);
    }
    else
    {
      parent->right = new AdminNode(Admin(n, p, u, pwd), NULL, NULL);
    }
  }

  bool authenticateAdmin(string enteredUsername, string enteredPassword)
  {
    AdminNode *current = root;

    while (current != NULL)
    {
      if (enteredUsername == current->user.getUsername() &&
          enteredPassword == current->user.getPassword())
      {
        return true;
      }
      else if (enteredUsername < current->user.getUsername())
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }

    return false;
  }
};

struct BookingTreeNode
{
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

  void getBookingInfo() const
  {
    cout << "| " << setw(10) << checkInDate << " | " << setw(10) << checkOutDate
         << " |   " << setw(4) << roomNo << "  |   " << setw(6) << roomType
         << "  | " << setw(12) << ic << " |    " << fixed << setprecision(2)
         << setw(5) << totalPrice << "   |" << endl;
  }
};

class HotelBookingTree
{
public:
  HotelBookingTree() : root(NULL) {}

  ~HotelBookingTree()
  {
    destroyTree(root);
  }

  bool isEmpty() const
  {
    return (root == NULL);
  }

  int numOfNodes() const
  {
    return countNodes(root);
  }

  void retrieveBooking(string checkInDate, int roomNo, bool &found)
  {
    retrieve(root, checkInDate, roomNo, found);
  }

  void insertBooking(BookingTreeNode *newNode)
  {
    insert(root, newNode);
  }

  void deleteBooking(string checkInDate, int roomNo)
  {
    deleteNode(root, checkInDate, roomNo);
    cout << "\n===== Booking deleted successfully =====" << endl;
  }

  void displayBooking() const
  {
    cout << "\n____________________________________________________________________"
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

  BookingTreeNode *findBooking(string ic)
  {
    BookingTreeNode *current = root;

    while (current != NULL)
    {
      if (ic == current->ic)
      {
        return current;
      }
      else if (ic < current->ic)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }

    return NULL;
  }

private:
  BookingTreeNode *root;

  void destroyTree(BookingTreeNode *&tree)
  {
    if (tree != NULL)
    {
      destroyTree(tree->left);
      destroyTree(tree->right);
      delete tree;
    }
  }

 void insert(BookingTreeNode *&tree, BookingTreeNode *newNode)
  {
    if (tree == NULL)
    {
      tree = newNode;
    }
    else if (newNode->checkInDate < tree->checkInDate ||
             (newNode->checkInDate == tree->checkInDate &&
              newNode->roomNo < tree->roomNo))
    {
      insert(tree->left, newNode);
    }
    else
    {
      insert(tree->right, newNode);
    }
  }

  void retrieve(BookingTreeNode *tree, string checkInDate, int roomNo, bool &found)
  {
    if (tree == NULL)
    {
      found = false;
    }
    else if (checkInDate < tree->checkInDate ||
             (checkInDate == tree->checkInDate && roomNo < tree->roomNo))
    {
      retrieve(tree->left, checkInDate, roomNo, found);
    }
    else if (checkInDate > tree->checkInDate ||
             (checkInDate == tree->checkInDate && roomNo > tree->roomNo))
    {
      retrieve(tree->right, checkInDate, roomNo, found);
    }
    else
    {
      found = true;
    }
  }

  void deleteNode(BookingTreeNode *&tree, string checkInDate, int roomNo)
  {
    if (tree == NULL)
    {
      return;
    }

    if (checkInDate < tree->checkInDate ||
        (checkInDate == tree->checkInDate && roomNo < tree->roomNo))
    {
      deleteNode(tree->left, checkInDate, roomNo);
    }
    else if (checkInDate > tree->checkInDate ||
             (checkInDate == tree->checkInDate && roomNo > tree->roomNo))
    {
      deleteNode(tree->right, checkInDate, roomNo);
    }
    else
    {
      deleteCurrentNode(tree);
    }
  }

  void deleteCurrentNode(BookingTreeNode *&tree)
  {
    BookingTreeNode *tempNode = tree;

    if (tree->left == NULL)
    {
      tree = tree->right;
      delete tempNode;
    }
    else if (tree->right == NULL)
    {
      tree = tree->left;
      delete tempNode;
    }
    else
    {
      getPredecessor(tree->left, tempNode);
      tree->checkInDate = tempNode->checkInDate;
      tree->roomNo = tempNode->roomNo;
      deleteNode(tree->left, tempNode->checkInDate, tempNode->roomNo);
    }
  }

  void getPredecessor(BookingTreeNode *tree, BookingTreeNode *&predecessor)
  {
    while (tree->right != NULL)
    {
      tree = tree->right;
    }
    predecessor = tree;
  }

  void display(BookingTreeNode *tree) const
  {
    if (tree != NULL)
    {
      display(tree->left);
      tree->getBookingInfo();
      display(tree->right);
    }
  }

  int countNodes(BookingTreeNode *tree) const
  {
    if (tree == NULL)
      return 0;
    else
      return 1 + countNodes(tree->left) + countNodes(tree->right);
  }
};

void readBookingData(HotelBookingTree &bookingTree)
{
  ifstream bookinginpFile("booking.txt");
  if (!bookinginpFile.is_open())
  {
    cout << "\n===== Unable to open file! =====" << endl;
    return;
  }

  string checkInDate;
  string checkOutDate;
  int roomNo;
  string roomType;
  string ic;
  double totalPrice;

  while (bookinginpFile >> checkInDate >> checkOutDate >> roomNo >> roomType >>
         ic >> totalPrice)
  {
    BookingTreeNode *newNode = new BookingTreeNode(checkInDate, checkOutDate, roomNo, roomType, ic, totalPrice);
    bookingTree.insertBooking(newNode);
  }

  bookinginpFile.close();
}

void adminMenu(HotelBookingTree &bookingTree)
{
  int option;
  string checkInDate;
  string checkOutDate;
  int roomNo;
  string roomType;
  string ic;
  double totalPrice;
  string sKey_ic;

  do
  {
    cout << "\n---------------------------------" << endl;
    cout << "            Admin Menu" << endl;
    cout << "---------------------------------" << endl;
    cout << "        1. Insert Booking" << endl;
    cout << "        2. Delete Booking" << endl;
    cout << "        3. Search Booking" << endl;
    cout << "        4. View Booking" << endl;
    cout << "        5. View Number of Booking" << endl;
    cout << "        6. Exit" << endl;
    cout << "---------------------------------" << endl;
    cout << "Enter your option: ";

    cin >> option;
    cout << endl;

    switch (option)
    {
    case 1:
    {
      cout << "Enter Booking Info: " << endl;
      cout << "Check-In Date (YYYY/MM/DD): ";
      cin >> checkInDate;
      cin.ignore();
      cout << "Check-Out Date (YYYY/MM/DD) : ";
      cin >> checkOutDate;
      cin.ignore();
      cout << "Room Number: ";
      cin >> roomNo;
      cout << "Room Type (Single/ Double/ Queen/ King) : ";
      cin >> roomType;
      cout << "IC (Without '-'): ";
      cin >> ic;
      cout << "Total Price: RM ";
      cin >> totalPrice;

      bool found;
      bookingTree.retrieveBooking(checkInDate, roomNo, found);

      if (!found)
      {
        BookingTreeNode *newNode = new BookingTreeNode(checkInDate, checkOutDate, roomNo, roomType, ic, totalPrice);
        bookingTree.insertBooking(newNode);
        cout << "\n===== Booking successfully added =====" << endl;
      }
      else
      {
        cout << "\n===== Booking fail. Room is booked. ====="
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
      cin >> sKey_ic;
      if (bookingTree.findBooking(sKey_ic) != NULL)
      {
        cout << "\n===== The booking data is found =====" << endl;
      }
      else
      {
        cout << "\n===== No booking data found =====" << endl;
      }
      break;

    case 4:
      cout << "Viewing Booking" << endl;
      bookingTree.displayBooking();
      break;
    
    case 5:
      cout << "Viewing Number of Booking" << endl;
      cout << "\nCurrent number of bookings in the system : " << bookingTree.numOfNodes() << endl;
      break;

    case 6:
      break;

    default:
      cout << "Enter a valid option." << endl;
      adminMenu(bookingTree);
      break;
    }
  } while (option != 7);
  cout << "\n=========== Thank you ===========" << endl << endl;
}

int main()
{
  AdminAuthentication auth;
  HotelBookingTree bookingTree;
  readBookingData(bookingTree);

  ifstream inFile("admin.txt");

  int count = 0;
  string line, name, position, username, password;

  while (count < SIZE && getline(inFile, line))
  {
    size_t pos1 = line.find(',');
    size_t pos2 = line.find(',', pos1 + 1);
    size_t pos3 = line.find(',', pos2 + 1);

    name = line.substr(0, pos1);
    position = line.substr(pos1 + 1, pos2 - pos1 - 1);
    username = line.substr(pos2 + 1, pos3 - pos2 - 1);
    password = line.substr(pos3 + 1);

    auth.addAdmin(name, position, username, password);
    count++;
  }
  inFile.close();

  string enteredUsername, enteredPassword;
  cout << "Enter username: ";
  cin >> enteredUsername;
  cout << "Enter password: ";
  cin >> enteredPassword;

  if (auth.authenticateAdmin(enteredUsername, enteredPassword))
  {
    cout << "\n===== Authentication successful! =====" << endl;
    cout << endl;
    cout << "---------------------------------" << endl;
    cout << "LogiCode Hotel Management System" << endl;
    cout << "---------------------------------" << endl;
    adminMenu(bookingTree);
  }
  else
  {
    cout << "===== Invalid username or password =====" << endl;
  }

  return 0;
}
