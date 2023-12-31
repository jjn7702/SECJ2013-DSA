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
            temp->data.display();
            temp = temp->next; // to move the pointer to point to the next node
        }
        cout << endl;
    }

    Node *findNodeName(string name)
    {
        Node *currNode = head;

        while (currNode != NULL)
        {
            if (currNode->data.getName() == name)
            {
                return currNode;
            }

            currNode = currNode->next;
        }

        return NULL; // Node not found
    }

    Node *findNodeIC(string ic)
    {
        Node *currNode = head;

        while (currNode != NULL)
        {
            if (currNode->data.getIC() == ic)
            {
                return currNode;
            }

            currNode = currNode->next;
        }

        return NULL; // Node not found
    }

    Node *findNodeAge(int age)
    {
        Node *currNode = head;

        while (currNode != NULL)
        {
            if (currNode->data.getAge() == age)
            {
                return currNode;
            }

            currNode = currNode->next;
        }

        return NULL; // Node not found
    }

    // sorting here

    Node *SortedMerge(Node *a, Node *b)
    {
        Node *result = NULL;

        /* Base cases */
        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        /* Pick either a or b, and recur */
        if (a->data.getName() <= b->data.getName())
        {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return result;
    }

    void FrontBackSplit(Node *source, Node **frontRef, Node **backRef)
    {
        Node *fast;
        Node *slow;
        slow = source;
        fast = source->next;

        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        /* 'slow' is before the midpoint in the list, so split it in two
        at that point. */
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }

    void MergeSort(Node **headRef)
    {
        Node *head = *headRef;
        Node *a;
        Node *b;

        /* Base case -- length 0 or 1 */
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        /* Split head into 'a' and 'b' sublists */
        FrontBackSplit(head, &a, &b);

        /* Recursively sort the sublists */
        MergeSort(&a);
        MergeSort(&b);

        /* answer = merge the two sorted lists together */
        *headRef = SortedMerge(a, b);
    }

    void sortList()
    {
        MergeSort(&head);
    }
    void sortListAge()
    {
        SortedMergeAge(&head);
    }
    void sortListDate()
    {
        SortedMergeDate(&head);
    }
    Node *SortedMergeAge(Node *a, Node *b)
    {
        Node *result = NULL;

        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        if (a->data.getAge() <= b->data.getAge())
        {
            result = a;
            result->next = SortedMergeAge(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMergeAge(a, b->next);
        }
        return result;
    }

    void MergeSortAge(Node **headRef)
    {
        Node *head = *headRef;
        Node *a;
        Node *b;

        if (head == NULL || head->next == NULL)
        {
            return;
        }

        FrontBackSplit(head, &a, &b);

        MergeSortAge(&a);
        MergeSortAge(&b);

        *headRef = SortedMergeAge(a, b);
    }

    Node *SortedMergeDate(Node *a, Node *b)
    {
        Node *result = NULL;

        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        if (a->data.getDate() <= b->data.getDate())
        {
            result = a;
            result->next = SortedMergeDate(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMergeDate(a, b->next);
        }
        return result;
    }

    void MergeSortDate(Node **headRef)
    {
        Node *head = *headRef;
        Node *a;
        Node *b;

        if (head == NULL || head->next == NULL)
        {
            return;
        }

        FrontBackSplit(head, &a, &b);

        MergeSortDate(&a);
        MergeSortDate(&b);

        *headRef = SortedMergeDate(a, b);
    }
};

// display patient record
void Patient::display()
{
    cout << setw(30) << left << name
         << setw(15) << ic
         << setw(5) << age
         << setw(10) << gender
         << setw(17) << contactNum
         << setw(25) << disease
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
         << setw(25) << "Disease"
         << setw(15) << "Diagnosed Date" << endl;
    for (int i = 0; i < 120; i++)
        cout << "-";
    cout << endl;
}

int main()
{
    Patient patient;
    List list;
    int opt, choice, position, age;
    bool logout = false;
    string name, ic, gender, contactNo, disease, date;

    // loading page
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

    // main page
    while (!logout)
    {
        system("cls");
        cout << "\nHospital Management System\n\n<<MAIN PAGE>>\n1. Add new patient\n2. Delete patient\n3. Search patient\n4. Sort patient\n5. Display patient list\n6. Logout"
             << endl;
        cout << "\nOption: ";
        cin >> opt;
        cin.ignore();

        if (opt == 1)
        {
            while (true)
            {
                system("cls");
                cout << "<<ADD PATIENT>>" << endl;
                cout << "[1] Add at the beginning" << endl;
                cout << "[2] Add at the middle(any position)" << endl;
                cout << "[3] Add at the end" << endl;
                cout << "[4] Back" << endl
                     << endl;
                cout << "Option: ";
                cin >> choice;

                if (choice == 4)
                    break;

                if (choice == 2)
                {
                    cout << "\nEnter the specific position to add: ";
                    cin >> position;
                }

                if (choice < 1 || choice > 4)
                {
                    cout << "Invalid option. Please enter a valid option (1 to 4)." << endl;
                    system("pause");
                    continue;
                }

                cout << "\n---Patient Info---" << endl;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter identity card no: ";
                getline(cin, ic);
                cout << "Enter age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter gender: ";
                getline(cin, gender);
                cout << "Enter contact no: ";
                getline(cin, contactNo);
                cout << "Enter disease: ";
                getline(cin, disease);
                cout << "Enter diagnosed date: ";
                getline(cin, date);

                Patient p1(name, ic, age, gender, contactNo, disease, date);

                if (choice == 1)
                    list.insert(p1);
                else if (choice == 2)
                {
                    list.insertMiddle(p1, position);
                }
                else if (choice == 3)
                    list.insertEnd(p1);

                dispHeader();
                list.dispList();
                system("pause");
            }
        }
        else if (opt == 2)
        {
            while (true)
            {
                system("cls");
                cout << "<<DELETE PATIENT>>" << endl;
                cout << "[1] Delete the first patient list" << endl;
                cout << "[2] Delete the middle(any position)patient list" << endl;
                cout << "[3] Delete the last patient list" << endl;
                cout << "[4] Back" << endl
                     << endl;
                cout << "Option: ";
                cin >> choice;

                if (choice == 1)
                    list.removeFront();
                else if (choice == 2)
                {
                    cout << "\nEnter the specific position to delete: ";
                    cin >> position;
                    list.removeMiddle(position);
                }
                else if (choice == 3)
                    list.removeEnd();
                else if (choice == 4)
                    break;
                else
                {
                    cout << "Invalid option. Please enter a valid option (1 to 4)." << endl;
                    system("pause");
                    continue;
                }
                dispHeader();
                list.dispList();
                system("pause");
            }
        }

        else if (opt == 3)
        {
            while (true)
            {
                system("cls");
                cout << "<<SEARCH PATIENT>>" << endl;
                cout << "[1] Search by name" << endl;
                cout << "[2] Search by IC" << endl;
                cout << "[3] Search by age" << endl;
                cout << "[4] Back" << endl
                     << endl;
                cout << "Option: ";
                cin >> choice;

                if (choice == 4)
                    break;

                if (choice < 1 || choice > 4)
                {
                    cout << "Invalid option. Please enter a valid option (1 to 4)." << endl;
                    system("pause");
                    continue;
                }

                cout << "\nEnter search keyword: ";
                cin.ignore();
                string keyword;
                getline(cin, keyword);

                Node *resultNode = nullptr;

                switch (choice)
                {
                case 1:
                    resultNode = list.findNodeName(keyword);
                    break;
                case 2:
                    resultNode = list.findNodeIC(keyword);
                    break;
                case 3:
                    resultNode = list.findNodeAge(stoi(keyword));
                    break;
                }

                if (resultNode != nullptr)
                {
                    dispHeader();
                    resultNode->data.display();
                }
                else
                {
                    cout << "Patient not found." << endl;
                }

                system("pause");
            }
        }

        else if (opt == 4)
        {
            while (true)
            {
                system("cls");
                cout << "<<SORT PATIENT>>" << endl;
                cout << "[1] Sort by name" << endl;
                cout << "[2] Sort by name" << endl;
                cout << "[3] Sort by name" << endl;
                cout << "[4] Back" << endl
                     << endl;
                cout << "Option: ";
                cin >> choice;

                if (choice == 4)
                    break;

                if (choice < 1 || choice > 4)
                {
                    cout << "Invalid option. Please enter a valid option (1 or 2)." << endl;
                    system("pause");
                    continue;
                }

                if (choice == 1)
                {
                    list.sortList(); // call the public sort function
                    dispHeader();
                    list.dispList();
                    system("pause");
                }

                if (choice == 2)
                {
                    list.sortListAge(); // call the public sort function
                    dispHeader();
                    list.dispList();
                    system("pause");
                }

                if (choice == 3)
                {
                    list.sortListDate(); // call the public sort function
                    dispHeader();
                    list.dispList();
                    system("pause");
                }
            }
        }
        else if (opt == 5)
        {
            while (true)
            {
                system("cls");
                cout << "<<Patient Record>>" << endl;
                cout << "[1] Display current list" << endl;
                cout << "[2] Back" << endl
                     << endl;
                cout << "Option: ";
                cin >> choice;

                if (choice == 1)
                {
                    dispHeader();
                    list.dispList();
                    system("pause");
                }
                else if (choice == 2)
                {
                    break;
                }
                else
                {
                    cout << "Invalid option. Please enter a valid option (1 or 2)." << endl;
                    system("pause");
                }
            }
        }
        else if (opt == 6)
        {
            logout = true;
            cout << "\n\nYou have successfully logged out!" << endl;
        }
        else
        {
            cout << "Invalid option. Please enter a valid option (1 to 6)." << endl;
            system("pause");
        }
    }
    system("pause");
    return 0;
}