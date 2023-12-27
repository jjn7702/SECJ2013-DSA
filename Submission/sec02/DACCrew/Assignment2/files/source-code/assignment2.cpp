// Assignment 2 - SECJ2013 - 23241 (assignment2.cpp)
// Group Members:
// 1. Nur Farah Adibah Binti Idris A22EC0245
// 2. 
// 3.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void dispHeader()
{
    for (int i = 0; i < 106; i++)
        cout << "-";
    cout << endl;
    cout << setw(50) << left << "| Name "
         << "|"
         << setw(20) << " Account Number "
         << "|"
         << setw(14) << " Ic Number "
         << "|"
         << setw(18) << " Account Balance "
         << "|" << endl;
    for (int i = 0; i < 106; i++)
        cout << "-";
    cout << endl;
}

class Bank
{
    string accNum, accName, ic;
    double accBalance;

public:
    Bank(string num = "", double b = 0, string name = "", string i = "")
    {
        accNum = num;
        accBalance = b;
        accName = name;
        ic = i;
    }

    void setName(string name) { accName = name; }
    string getName() const { return accName; }
    void setAccNum(string num) { accNum = num; }
    string getAccNum() const { return accNum; }
    void setIc(string num) { ic = num; }
    string getIc() const { return ic; }
    void setBalance(double g) { accBalance = g; }
    double getBalance() const { return accBalance; }

    void displayDetails()
    {
        cout << "| " << setw(48) << accName
             << "| " << setw(19) << accNum
             << "| " << setw(13) << ic
             << "| " << setw(17) << accBalance << "|" << endl;
        for (int i = 0; i < 106; i++)
            cout << "-";
        cout << endl;
    }
};

class Node
{
public:
    Bank data;
    Node *next;
    // Constructor
    Node(Bank b) : data(b), next(NULL) {}

    Bank getData() { return data; }
};


class LinkedList
{
    Node *head;

public:
    LinkedList() : head(NULL) {}

    bool isEmpty() { return head == NULL; }

    Node *findNodeAccNum(string n)
    {
        Node *newNode = head;
        while (newNode)
        {
            if (newNode->data.getAccNum() == n)
            {
                dispHeader();
            }
            newNode = newNode->next;
        }
        return NULL;
    }

    Node *findNodeName(string n)
    {
        Node *newNode = head;
        while (newNode)
        {
            if (newNode->data.getName() == n)
                return newNode;
            newNode = newNode->next;
        }
        return NULL;
    }

    Node *findNodeIC(string ic)
    {
        Node *newNode = head;
        while (newNode)
        {
            if (newNode->data.getIc() == ic)
                return newNode;
            newNode = newNode->next;
        }
        return NULL;
    }
};

/*void insert(Node n)
    {
        Node *newNode = new Node(n);
        if (isEmpty())
            head = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insertMiddle(int d, Bank b)
    {
        Node *temp = head;
        Node *newNode = new Node(b);
        int count = 1;

        while (temp != NULL && count < d - 1)
        {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertEnd(Bank b)
    {
        Node *temp = head;
        Node *newNode = new Node(b);

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }*/



int main(){



    //  FOR INSERT BEGINNING MIDDLE END
  /*
  if (opt == 1)
        {
            cout << "INSERT INFO AT THE BEGINNING" << endl
                 << endl;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Account Num: ";
            cin.ignore();
            getline(cin, accnum);
            cout << "Enter ic: ";
            cin.ignore();
            getline(cin, ic);
            cout << "Balance: ";
            cin.ignore();
            cin >> balance;

            Bank A(accnum, balance, name, ic);
            list.insert(A);

            list.displayAll();
            cout << endl
                 << endl;
        }
        else if (opt == 2)
        {
            cout << "INSERT INFO AT THE MIDDLE(SPECIFIED POSITION)" << endl
                 << endl;

            cout << "Specify the location want to insert: ";
            cin.ignore();
            cin >> position;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Account Num: ";
            cin.ignore();
            getline(cin, accnum);
            cout << "Enter ic: ";
            cin.ignore();
            getline(cin, ic);
            cout << "Balance: ";
            cin.ignore();
            cin >> balance;

            Bank C(accnum, balance, name, ic);
            list.insertMiddle(position, C);

            list.displayAll();
            cout << endl
                 << endl;
        }
        else if (opt == 3)
        {

            cout << "INSERT INFO AT THE END" << endl
                 << endl;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Account Num: ";
            cin.ignore();
            getline(cin, accnum);
            cout << "Enter ic: ";
            cin.ignore();
            getline(cin, ic);
            cout << "Balance: ";
            cin.ignore();
            cin >> balance;

            Bank B(accnum, balance, name, ic);
            list.insertEnd(B);

            list.displayAll();
            cout << endl
                 << endl;
        }
  */  
}
