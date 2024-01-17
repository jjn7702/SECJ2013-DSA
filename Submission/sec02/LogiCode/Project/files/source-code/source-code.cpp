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
