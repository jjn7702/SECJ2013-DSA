// Assignment 2 - SECJ2013 - 23241 (Assg2.cpp)
// Group Members:
// 1. Muhammad Iman Firdaus Bin Baharuddin A22EC0216
// 2. Muhammad Ariff Danish Bin Hashnan A22EC0204
// 3. Che Marhumi Bin Che AB Rahim A22EC0147
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
///-----------------------------------------------CLASS CUSTOMER----------------------------------------------------------------///
class Cust
{
private:
    string name, destination, airlines;
    int day, month, years;
    int count; // edit

public:
    Cust(string n, int d, int m, int y, string dest, string a)
    {
        name = n;
        day = d;
        month = m;
        years = y;
        destination = dest;
        airlines = a;
    }

    void printResult(int count)
    {
        cout << "\t\t\t" << left << setw(5) << count << setw(15) << name << setw(2) << day << " / " << setw(2) << month
             << " / " << setw(15) << years << setw(19) << destination << setw(19) << airlines << endl;
    }

    void printSearch(int date)
    {
        cout << left << setw(5) << setw(15) << getName() << setw(2) << day << " / " << setw(2) << month
             << " / " << setw(15) << years << setw(20) << destination << setw(5) << airlines << endl;
    }

    int getdate()
    {
        return day + years * 10000 + month * 100;
    }

    string getName()
    {
        return name;
    }

    string getDestination()
    {
        return destination;
    }

    string getAirlines()
    {
        return airlines;
    }
};
///-----------------------------------------------END OF CLASS CUSTOMER----------------------------------------------------------------///

///-----------------------------------------------CLASS NODE----------------------------------------------------------------///
class Node
{
public:
    Cust *data;
    Node *next;

    Node(Cust *c) : data(c), next(nullptr) {}
};
///-----------------------------------------------END OF CLASS NODE----------------------------------------------------------------///

///-----------------------------------------------CLASS LINKEDLIST----------------------------------------------------------------///
class LinkedList
{
private:
    Node *head;
    int count;       // get number of customer updated after add or delete
    int initialSize; // get size form file

public:
    LinkedList() : head(nullptr), count(0), initialSize(0) {}

    ~LinkedList()
    {
        Node *current = head;
        Node *next;

        while (current != nullptr)
        {
            next = current->next;
            delete current->data; // Free Cust object
            delete current;       // Free Node
            current = next;
        }
    }

    int updatedSize() // edit
    {
        int MAX = count + initialSize;

        return MAX;
    }

    int getInitialSize(int n) // edit
    {
        return initialSize = n;
    }

    int getNodeCount() // edit
    {
        return count;
    }

    void addNode(Cust *cust) // use just to add node from file
    {
        Node *newNode = new Node(cust);
        newNode->next = head;
        head = newNode;
    }

    void listcust()
    {
        Node *current = head;
        int i = 1;

        while (current != nullptr)
        {
            current->data->printResult(i);
            current = current->next;
            i++;
        }
    }

    ///-----------------------------------------------FUNCTION TO ADD NEW CUSTOMER TO THE LIST----------------------------------------------------------------///
    void addToBeginning(Cust *cust)
    {
        Node *newNode = new Node(cust);
        newNode->next = head;
        head = newNode;
        count++;
    }

    void addToMiddle(Cust *cust, int position)
    {
        if (position < 1 || position >= updatedSize())
        {
            cout << "\n\t\t\t\t\t\tInvalid position." << endl;
            cout <<"\t\t\t\t\t\tCannot add customer." << endl;
            return;
        }

        Node *newNode = new Node(cust);
        Node *current = head;

        for (int i = 1; i < position && current != nullptr; ++i)
        {
            current = current->next;
        }

        if (current != nullptr)
        {
            newNode->next = current->next;
            current->next = newNode;
            count++;
            cout << "\n\t\t\t\t\t\tCustomer added successfully." << endl;
        }
    }

    void addToEnd(Cust *cust)
    {
        Node *newNode = new Node(cust);
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }

        last->next = newNode;
        count++;
    }
    ///-----------------------------------------------END OF FUNCTION TO ADD CUSTOMER----------------------------------------------------------------///

    ///-----------------------------------------------FUNCTION TO DELETE CUSTOMER FROM THE LIST----------------------------------------------------------------///
    void deleteFromBeginning()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
            count--;
        }
        else
        {
            cout << "\n\t\t\t\t\t\tList is empty. Cannot delete." << endl;
        }
    }

    void deleteFromMiddle(int position)
    {
        if (head == nullptr)
        {
            cout << "\n\t\t\t\t\t\tList is empty. Cannot delete." << endl;
            return;
        }

        if (position <= 1 || position >= updatedSize())
        {
            cout << "\n\t\t\t\t\t\tInvalid position. Cannot delete." << endl;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;

        for (int i = 1; i < position && current != nullptr; ++i)
        {
            prev = current;
            current = current->next;
        }

        if (current != nullptr)
        {
            prev->next = current->next;
            delete current->data;
            delete current;
            count--;
            cout << "\n\t\t\t\t\t\tCustomer deleted successfully." << endl;
        }
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "\n\t\t\t\t\t\tList is empty. Cannot delete." << endl;
            return;
        }

        if (head->next == nullptr) // check if there is only one node in the list
        {
            delete head->data;
            delete head;
            head = nullptr;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;

        while (current->next != nullptr)
        {
            prev = current;
            current = current->next;
        }

        prev->next = nullptr;
        delete current->data;
        delete current;
        count--;
    }
    ///-----------------------------------------------END OF FUNCTION TO DELETE CUSTOMER----------------------------------------------------------------///
