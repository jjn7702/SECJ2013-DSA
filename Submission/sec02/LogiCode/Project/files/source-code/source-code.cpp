#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct TreeNode
{
    string checkInDate;
    string checkOutDate;
    int roomNo;
    string roomType;
    string ic;
    double totalPrice;

    TreeNode *left;
    TreeNode *right;

    TreeNode(string i, string o, int n, string t, string ic_, double p)
        : checkInDate(i), checkOutDate(o), roomNo(n), roomType(t), ic(ic_), totalPrice(p),
          left(nullptr), right(nullptr) {}

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
    HotelBookingTree();
    ~HotelBookingTree();
    bool IsEmpty() const;
    int NumberOfNodes() const;
    void RetrieveItem(string checkInDate, int roomNo, bool &found);
    void InsertItem(TreeNode *newNode);
    void DeleteItem(string checkInDate, int roomNo);
    void PrintTree() const;
    TreeNode *FindNode(string ic);

private:
    TreeNode *root;

    void Destroy(TreeNode *&tree);
    void Insert(TreeNode *&tree, TreeNode *newNode);
    void Retrieve(TreeNode *tree, string checkInDate, int roomNo, bool &found);
    void Delete(TreeNode *&tree, string checkInDate, int roomNo);
    void DeleteNode(TreeNode *&tree);
    void GetPredecessor(TreeNode *tree, TreeNode *&predecessor);
    void Print(TreeNode *tree) const;
    int CountNodes(TreeNode *tree) const;
};

HotelBookingTree::HotelBookingTree()
{
    root = nullptr;
}

HotelBookingTree::~HotelBookingTree()
{
    Destroy(root);
}

void HotelBookingTree::Destroy(TreeNode *&tree)
{
    if (tree != nullptr)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

bool HotelBookingTree::IsEmpty() const
{
    return (root == nullptr);
}

int HotelBookingTree::NumberOfNodes() const
{
    return CountNodes(root);
}

int HotelBookingTree::CountNodes(TreeNode *tree) const
{
    if (tree == nullptr)
        return 0;
    else
        return 1 + CountNodes(tree->left) + CountNodes(tree->right);
}

void HotelBookingTree::RetrieveItem(string checkInDate, int roomNo, bool &found)
{
    Retrieve(root, checkInDate, roomNo, found);
}

void HotelBookingTree::Retrieve(TreeNode *tree, string checkInDate, int roomNo, bool &found)
{
    if (tree == nullptr)
    {
        found = false;
    }
    else if (checkInDate < tree->checkInDate || (checkInDate == tree->checkInDate && roomNo < tree->roomNo))
    {
        Retrieve(tree->left, checkInDate, roomNo, found);
    }
    else if (checkInDate > tree->checkInDate || (checkInDate == tree->checkInDate && roomNo > tree->roomNo))
    {
        Retrieve(tree->right, checkInDate, roomNo, found);
    }
    else
    {
        found = true;
    }
}

void HotelBookingTree::InsertItem(TreeNode *newNode)
{
    Insert(root, newNode);
}

void HotelBookingTree::Insert(TreeNode *&tree, TreeNode *newNode)
{
    if (tree == nullptr)
    {
        tree = newNode;
    }
    else if (newNode->checkInDate < tree->checkInDate || (newNode->checkInDate == tree->checkInDate && newNode->roomNo < tree->roomNo))
    {
        Insert(tree->left, newNode);
    }
    else
    {
        Insert(tree->right, newNode);
    }
}

void HotelBookingTree::DeleteItem(string checkInDate, int roomNo)
{
    Delete(root, checkInDate, roomNo);
}

void HotelBookingTree::Delete(TreeNode *&tree, string checkInDate, int roomNo)
{
    if (tree == nullptr)
    {
        return;
    }

    if (checkInDate < tree->checkInDate || (checkInDate == tree->checkInDate && roomNo < tree->roomNo))
    {
        Delete(tree->left, checkInDate, roomNo);
    }
    else if (checkInDate > tree->checkInDate || (checkInDate == tree->checkInDate && roomNo > tree->roomNo))
    {
        Delete(tree->right, checkInDate, roomNo);
    }
    else
    {
        DeleteNode(tree);
    }
}

void HotelBookingTree::DeleteNode(TreeNode *&tree)
{
    TreeNode *tempNode = tree;
    if (tree->left == nullptr)
    {
        tree = tree->right;
        delete tempNode;
    }
    else if (tree->right == nullptr)
    {
        tree = tree->left;
        delete tempNode;
    }
    else
    {
        GetPredecessor(tree->left, tempNode);
        tree->checkInDate = tempNode->checkInDate;
        tree->roomNo = tempNode->roomNo;
        Delete(tree->left, tempNode->checkInDate, tempNode->roomNo);
    }
}

void HotelBookingTree::GetPredecessor(TreeNode *tree, TreeNode *&predecessor)
{
    while (tree->right != nullptr)
    {
        tree = tree->right;
    }
    predecessor = tree;
}

void HotelBookingTree::PrintTree() const
{
    Print(root);
}

void HotelBookingTree::Print(TreeNode *tree) const
{
    if (tree != nullptr)
    {
        Print(tree->left);
        tree->getBookingInfo();
        Print(tree->right);
    }
}

TreeNode *HotelBookingTree::FindNode(string ic)
{
    TreeNode *current = root;

    while (current != nullptr)
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

    return nullptr;
}

void readBookingData(HotelBookingTree &bookingTree)
{
    ifstream bookinginpFile("booking.txt");
    if (!bookinginpFile.is_open())
    {
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
           ic >> totalPrice)
    {
        TreeNode *newNode = new TreeNode(checkInDate, checkOutDate, roomNo, roomType, ic, totalPrice);
        bookingTree.InsertItem(newNode);
    }

    bookinginpFile.close();
}

void adminMenu(HotelBookingTree &bookingTree)
{
    int option;
    string skey_ic;
    string checkInDate;
    int roomNo;

    do
    {
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

        switch (option)
        {
        case 1:
        {
            cout << "Enter Booking Info: " << endl;
            cout << "Check-In Date (YYYY/MM/DD): ";
            cin >> checkInDate;
            cout << "Room Number: ";
            cin >> roomNo;

            bool found;
            bookingTree.RetrieveItem(checkInDate, roomNo, found);

            if (!found)
            {
                TreeNode *newNode = new TreeNode(checkInDate, "", roomNo, "", "", 0.0);
                bookingTree.InsertItem(newNode);
                cout << "Booking successfully added." << endl;
            }
            else
            {
                cout << "Booking with the same Check-In Date and Room Number already exists." << endl;
            }
            break;
        }

        case 2:
            cout << "Enter Booking Info to Delete: " << endl;
            cout << "Check-In Date (YYYY/MM/DD): ";
            cin >> checkInDate;
            cout << "Room Number: ";
            cin >> roomNo;
            bookingTree.DeleteItem(checkInDate, roomNo);
            break;

        case 3:
            cout << "Please type the search key (IC without '-')" << endl;
            cin >> skey_ic;
            if (bookingTree.FindNode(skey_ic) != nullptr)
            {
                cout << "The booking data is found." << endl;
            }
            else
            {
                cout << "No booking data found." << endl;
            }
            break;

        case 4:
            cout << "Sorting Booking by Check-In Date" << endl;
            bookingTree.PrintTree();
            break;

        case 5:
            cout << "Viewing Booking" << endl;
            bookingTree.PrintTree();
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

int main()
{
    HotelBookingTree bookingTree;
    readBookingData(bookingTree);

    cout << "---------------------------------" << endl;
    cout << "LogiCode Hotel Management System" << endl;
    cout << "---------------------------------" << endl;
    adminMenu(bookingTree);

    return 0;
}

