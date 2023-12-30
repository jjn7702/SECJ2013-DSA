// Assignment 2
// Group Codera
// Hospital Management System
// Neo Zheng Weng A22EC0093
// Joseph Lau Yeo Kai A22EC0055
// Lee Yik Hong A21BE0376

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <Windows.h>
#include <stdio.h>

#define SIZE 10000

using namespace std;

// Patient
class Patient
{
private:
    string name;
    string ic;
    int age;
    string gender;
    string contactNum;
    string disease;
    string date;

public:
    // default constructor
    Patient()
    {
        name = "";
        ic = "";
        age = 0;
        gender = "";
        contactNum = "";
        disease = "";
        date = "";
    }

    // constructor
    Patient(string n, string i, int a, string g, string c, string d, string dt)
    {
        name = n;
        ic = i;
        age = a;
        gender = g;
        contactNum = c;
        disease = d;
        date = dt;
    }

    // accessor
    string getName() const
    {
        return name;
    }
    string getIC() const
    {
        return ic;
    }
    int getAge() const
    {
        return age;
    }
    string getGender() const
    {
        return gender;
    }
    string getContactNum() const
    {
        return contactNum;
    }
    string getDisease() const
    {
        return disease;
    }
    string getDate() const
    {
        return date;
    }

    // mutator
    void setName(string n)
    {
        name = n;
    }
    void setIC(string i)
    {
        ic = i;
    }
    void setAge(int a)
    {
        age = a;
    }
    void setGender(string g)
    {
        gender = g;
    }
    void setContactNum(string c)
    {
        contactNum = c;
    }
    void setDisease(string d)
    {
        disease = d;
    }
    void setDate(string dt)
    {
        date = dt;
    }

    // display patient record
    void display();
};

// Node
class Node
{
public:
    Patient data; // patient data
    Node *next;   // pointer to next node

    Node(Patient p)
    {
        data = p;
        next = NULL;
    }
};

// List
class List
{
private:
    Node *head;

public:
    List()
    {
        head = NULL; // list is empty
    }

    ~List()
    {
        Node *currNode = head, *nextNode = NULL;
        while (currNode != NULL)
        {
            nextNode = currNode->next;
            // destroy the current node
            delete currNode;
            currNode = nextNode;
        }
        head = NULL;
    }

    bool isEmpty()
    {
        return head = NULL;
    }

    // add a new node at the beginning
    void insert(Patient p)
    {
        Node *newNode = new Node(p);

        if (!isEmpty())
            newNode->next = head;

        head = newNode;
    }

    // add a new node at the end of the list
    void insertEnd(Patient p)
    {
        Node *temp = head; // point to the first node in the list
        Node *newNode = new Node(p);

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // add a new node at a specific position
    void insertMiddle(Patient p, int loc)
    {
        Node *temp = head; // point to the first node in the list
        Node *newNode = new Node(p);
        int count = 1;

        while (temp->next != NULL && count < loc)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // delete the first node
    void removeFront()
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // delete the last node
    void removeEnd()
    {
        Node *temp = head, *t = head;

        while (temp->next != NULL)
        {
            t = temp;
            temp = temp->next;
        }
        delete temp;
        t->next = NULL;
    }

    // delete the node at a specific position
    void removeMiddle(int loc)
    {
        Node *temp = head, *prev; // point to the first node in the list
        int count = 1;

        while (temp->next != NULL && count < loc) // (temp->next)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }
        prev->next = temp->next;
        delete temp;
    }

    // display all nodes in the list
    void dispList()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data.display();
            temp = temp->next; // to move the pointer to point to the next node
        }
        cout << endl;
    }

    Node* findNodeName(string name);
    Node* findNodeIC(string ic);
    Node* findNodeAge(int age);
};

// display patient record
void Patient::display()
{
    cout << setw(30) << left << name
         << setw(15) << ic
         << setw(5) << age
         << setw(10) << gender
         << setw(17) << contactNum
         << setw(30) << disease
         << setw(15) << date << endl
         << endl;
}

// display header
void dispHeader()
{
    cout << endl;
    cout << "Patient Record: " << endl
         << endl;
    cout << setw(30) << left << "Name"
         << setw(15) << "IC"
         << setw(5) << "Age"
         << setw(10) << "Gender"
         << setw(17) << "Contact Number"
         << setw(30) << "Disease"
         << setw(15) << "Diagnosed Date" << endl;
    for (int i = 0; i < 130; i++)
        cout << "-";
    cout << endl;
}

// sorting

// searching
Node* List::findNodeName(string name) {
    Node* currNode = head;

    while (currNode != NULL) {
        if (currNode->data.getName() == name) {
            return currNode;
        }

        currNode = currNode->next;
    }

    return NULL; // Node not found
}

Node* List::findNodeIC(string ic) {
    Node* currNode = head;

    while (currNode != NULL) {
        if (currNode->data.getIC() == ic) {
            return currNode;
        }

        currNode = currNode->next;
    }

    return NULL; // Node not found
}


Node* List::findNodeAge(int age) {
    Node* currNode = head;

    while (currNode != NULL) {
        if (currNode->data.getAge() == age) {
            return currNode;
        }

        currNode = currNode->next;
    }

    return NULL; // Node not found
}


int main()
{
    Patient pat[SIZE];

    // read file
    fstream inFile("record.txt", ios::in);
    if (!inFile)
    {
        cout << "Can't open the file!" << endl;
        system("pause");
        return 0;
    }

    int i = 0;
    while (!inFile.eof())
    {
        string name;
        string ic;
        int age;
        string gender;
        string contactNum;
        string disease;
        string date;

        getline(inFile, name, '|');
        getline(inFile, ic, '|');
        inFile >> age; // Read age as integer
        inFile.ignore();
        getline(inFile, gender, '|');
        getline(inFile, contactNum, '|');
        getline(inFile, disease, '|');
        inFile >> date;
        inFile.ignore();

        pat[i].setName(name);
        pat[i].setIC(ic);
        pat[i].setAge(age);
        pat[i].setGender(gender);
        pat[i].setContactNum(contactNum);
        pat[i].setDisease(disease);
        pat[i].setDate(date);

        i++;
    }
    inFile.close();

    system("cls");
    printf("\e[?25l");
    int bar1 = 177, bar2 = 219;

    cout << "\n\n\n\t\t\t\tWELCOME TO HOSPITAL MANAGEMENT SYSTEM!";
    cout << "\n\t\t\t\t";
    cout << "\n\n\n\t\t\t\tLoading...";
    cout << "\n\n\n\t\t\t\t";

    for (int i = 0; i < 25; i++)
        cout << (char)bar1;
    cout << "\r";
    cout << "\t\t\t\t";

    for (int i = 0; i < 25; i++)
    {
        cout << (char)bar2;
        Sleep(150);
    }
    cout << "\n\t\t\t\t" << (char)1 << "!";

    // main menu
    int opt;
    bool logout = false;

    while (!logout)
    {
        system("cls");
        cout << "\nHospital Management System\n\n<<<Main Menu>>>\n1. Sorting\n2. Searching\n3. Logout\n"
             << endl;
        cout << "Option: ";
        cin >> opt;
        cin.ignore();

        if (opt == 1)
        {
            while (true)
            {
                system("cls");
                int choice;
                cout << "\nHospital Management System\n\n<<<Sorting Process>>>\n1. By name\n2. By IC\n3. By age\n4. By gender\n5. By contact number\n6. By disease\n7. By diagnosed date\n8. Back to Main Menu\n"
                     << endl;
                cout << "Option: ";
                cin >> choice;

                if (choice == 1)
                {
                    mergeSortByName(pat, 0, i - 1);
                }

                else if (choice == 2)
                {
                    mergeSortByIC(pat, 0, i - 1);
                }

                else if (choice == 3)
                {
                    mergeSortByAge(pat, 0, i - 1);
                }

                else if (choice == 4)
                {
                    mergeSortByGender(pat, 0, i - 1);
                }

                else if (choice == 5)
                {
                    mergeSortByContactNum(pat, 0, i - 1);
                }

                else if (choice == 6)
                {
                    mergeSortByDisease(pat, 0, i - 1);
                }

                else if (choice == 7)
                {
                    mergeSortByDate(pat, 0, i - 1);
                }

                else if (choice == 8)
                {
                    break;
                }

                else
                {
                    cout << "Invalid input! Only accepts 1 to 8!" << endl;
                }

                dispHeader();
                for (int j = 0; j < i; j++)
                    pat[j].display();
                system("pause");
            }
        }
        else if (opt == 2)
        {
            while (true)
            {
                system("cls");
                int select;
                cout << "\nHospital Management System\n\n<<<Searching Process>>>\n1. By name\n2. By IC\n3. By disease\n4. Back to Main Menu\n"
                     << endl;
                cout << "Option: ";
                cin >> select;

                if (select == 1)
                {
                    string name;
                    int result;
                    cout << "\nEnter patient name: ";
                    cin.ignore();
                    getline(cin, name);

                    mergeSortByName(pat, 0, i - 1);
                    result = binarySearchByName(pat, 0, i - 1, name);
                    if (result == -1)
                    {
                        cout << "Patient with name given is not found!" << endl;
                    }
                    else
                    {
                        dispHeader();
                        pat[result].display();
                    }
                }
                else if (select == 2)
                {
                    string ic;
                    int result;
                    cout << "\nEnter patient IC: ";
                    cin.ignore();
                    getline(cin, ic);

                    mergeSortByIC(pat, 0, i - 1);
                    result = binarySearchByIC(pat, 0, i - 1, ic);
                    if (result == -1)
                    {
                        cout << "Patient with IC given is not found!" << endl;
                    }
                    else
                    {
                        dispHeader();
                        pat[result].display();
                    }
                }
                else if (select == 3)
                {
                    string disease;
                    cout << "\nEnter disease: ";
                    cin.ignore();
                    getline(cin, disease);

                    mergeSortByDisease(pat, 0, i - 1);
                    vector<int> occurrences = binarySearchByDisease(pat, 0, i - 1, disease);
                    if (occurrences.empty())
                    {
                        cout << "Patient with disease given is not found!" << endl;
                    }
                    else
                    {
                        dispHeader();
                        for (int index : occurrences)
                        {
                            pat[index].display();
                        }
                    }
                }
                else if (select == 4)
                {
                    break;
                }
                else
                {
                    cout << "Invalid input! Only accepts 1 to 4!" << endl;
                }
                system("pause");
            }
        }
        else if (opt == 3)
        {
            logout = true;
            cout << "\n\nYou have successfully logged out!" << endl;
        }
        else
        {
            cout << "Invalid input! Only accepts 1 to 3!" << endl;
        }
    }
    system("pause");
    return 0;
}