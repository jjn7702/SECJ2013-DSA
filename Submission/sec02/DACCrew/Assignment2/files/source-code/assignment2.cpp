// Assignment 2 - SECJ2013 - 23241 (assignment2.cpp)
// Group Members:
// 1. Nur Farah Adibah Binti Idris A22EC0245
// 2. Wong Qiao Ying A22EC0118
// 3. Chai Yu Tong A22EC0145

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
             << "| " << setw(18) << accNum
             << "| " << setw(14) << ic
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

    void insert(Node n)
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
    }

    void removeFront()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
        else
        {
            cout << "List is empty. Nothing to delete." << endl;
        }
    }

    void removeEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            Node *prev = nullptr;
            while (temp->next != nullptr)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = nullptr;
            delete temp;
        }
    }

    void removeMiddle(int loc)
    {
        cout << "Enter the location to delete: ";
        cin >> loc;

        if (isEmpty())
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node *temp = head, *prev = nullptr;
        int count = 1;

        while (temp != nullptr && count < loc)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (temp == nullptr)
        {
            cout << "Invalid location. Data not found." << endl;
            return;
        }

        if (prev == nullptr)
            head = temp->next;
        else
            prev->next = temp->next;

        delete temp;
        cout << "Data at location " << loc << " deleted successfully." << endl;
    }

    void displayAll()
    {
        Node *temp = head;
        dispHeader(); // Display header before displaying all nodes

        while (temp != NULL)
        {
            temp->data.displayDetails();
            temp = temp->next;
        }
    }
};

int main()
{

    LinkedList list;
    int opt = 0, count = 0;
    string name, accnum, ic;
    double balance;
    int position;

    //  FOR INSERT BEGINNING MIDDLE END

    while (opt != 10)
    {
        cout << ":: INSERT DATA ::" << endl;
        cout << "[1] Insert at the beginning" << endl;
        if(count >= 2)
            cout << "[2] Insert at the middle" << endl;
        if(count >= 1)
            cout << "[3] Insert at the end" << endl
                 << endl;

        cout << "\n:: DELETE FROM ::" << endl;
        cout << "[4] Front" << endl;
        cout << "[5] Middle (state the location)" << endl;
        cout << "[6] End" << endl
             << endl;

        cout << ":: SEARCH BY ::" << endl;
        cout << "[7] Search by Name" << endl;
        cout << "[8] Search by Account Number" << endl;
        cout << "[9] Search by IC Number" << endl
             << endl;

        cout << ":: OTHER ACTION ::" << endl;
        cout << "[10] Quit" << endl;
        cout << "OPTION >> ";
        cin >> opt;
        cout << endl
             << endl;
        if (opt == 1)
        {
            cout << "INSERT INFO AT THE BEGINNING" << endl
                 << endl;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Account Num: ";
            getline(cin, accnum); cout << accnum;
            cout << "Enter IC Number: ";
            getline(cin, ic);
            cout << "Balance: ";
            cin >> balance;
            cin.ignore();

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
            getline(cin, accnum);
            cout << "Enter ic: ";
            getline(cin, ic);
            cout << "Balance: ";
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
            getline(cin, ic);
            cout << "Balance: ";
            cin >> balance;

            Bank B(accnum, balance, name, ic);
            list.insertEnd(B);

            list.displayAll();
            cout << endl
                 << endl;
        }
        else if (opt == 4)
        {
            cout << "\nDelete data from the front of the list" << endl;
            list.removeFront();
            list.displayAll();
            cout << endl
                 << endl;
        }

        else if (opt == 5)
        {
            cout << "\nDelete data from the middle of the list" << endl;
            list.removeMiddle(0);
            list.displayAll();
            cout << endl
                 << endl;
        }
        else if (opt == 6)
        {
            cout << "\nDelete data from the end of the list" << endl;
            list.removeEnd();
            list.displayAll();
            cout << endl
                 << endl;
        }
        else if (opt == 7)
        {
            string name;
            cout << "Option chosen: [7] Search by Name" << endl;
            cout << "Enter the name of the account: ";
            cin.ignore();
            getline(cin, name);
            Node *found = list.findNodeName(name);
            if (found)
            {
                dispHeader();
                found->data.displayDetails();
            }
            else
                cout << "Account does not exists." << endl;
        }
        else if (opt == 8)
        {
            string accNum;
            cout << "Option chosen: [8] Search by Account Number" << endl;
            cout << "Enter the account number: ";
            cin.ignore();
            getline(cin, accNum);
            Node *found = list.findNodeAccNum(accNum);
            if (found)
            {
                dispHeader();
                found->data.displayDetails();
            }
            else
                cout << "Account does not exists." << endl;
        }
        else if (opt == 9)
        {
            string ic;
            cout << "Option chosen: [9] Search by IC Number" << endl;
            cout << "Enter the account number: ";
            cin.ignore();
            getline(cin, ic);
            Node *found = list.findNodeIC(ic);
            if (found)
            {
                dispHeader();
                found->data.displayDetails();
            }
            else
                cout << "Account does not exists." << endl;
        }
        count++;
    }
}
