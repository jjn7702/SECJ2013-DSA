// Project
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
    Patient *next;
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
};

// Queue
class Queue
{
    
public:
    Patient *back, *front;

    Queue()
    {
        front = NULL;
        back = NULL;
    }

    bool isEmpty()
    {
        return ((front == NULL) && (back == NULL));
    }

    void enQueue(string n, string i, int a, string g, string c, string d, string dt)
    {
        Patient *newNode = new Patient(n, i, a, g, c, d, dt);

        if (isEmpty())
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }

    void deQueue()
    {
        Patient *delNode = front;

        if (isEmpty())
            cout << "The queue is empty!" << endl;
        else
        {
            if (front != back)
            {
                front = delNode->next;
                delNode->next = NULL;
            }
            else
            {
                front = NULL;
                back = NULL;
            }
            delete delNode;
        }
    }
    
  // Search by name
    Patient *searchByName(string name)
    {
        Patient *temp = front;

        while (temp != NULL)
        {
            if (temp->getName() == name)
            {
                return temp;
            }
            temp = temp->next;
        }

        return NULL; // Patient not found
    }

    // Search by IC
    Patient *searchByIC(string ic)
    {
        Patient *temp = front;

        while (temp != NULL)
        {
            if (temp->getIC() == ic)
            {
                return temp;
            }
            temp = temp->next;
        }

        return NULL; // Patient not found
    }

    // Search by disease
    Patient *searchByDisease(string disease)
    {
        Patient *temp = front;

        while (temp != NULL)
        {
            if (temp->getDisease() == disease)
            {
                return temp;
            }
            temp = temp->next;
        }

        return NULL; // Patient not found
    }

        // Merge Sort by name
    void mergeSortByName()
    {
        mergeSort(&front, "name");
    }

    // Merge Sort by IC
    void mergeSortByIC()
    {
        mergeSort(&front, "ic");
    }

    // Merge Sort by disease
    void mergeSortByDisease()
    {
        mergeSort(&front, "disease");
    }




    // display patient record
    void print()
    {
        if (isEmpty())
            cout << "Sorry, nothing in queue" << endl;
        else
        {
            Patient *temp = front;

            while (temp)
            { // temp != NULL
                cout << setw(30) << left << temp->getName()
                     << setw(15) << temp->getIC()
                     << setw(5) << temp->getAge()
                     << setw(10) << temp->getGender()
                     << setw(17) << temp->getContactNum()
                     << setw(25) << temp->getDisease()
                     << setw(15) << temp->getDate() << endl
                     << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void save()
    {
        fstream outFile("record.txt", ios::out);
        Patient *temp = front;

        while (temp)
        { // temp != NULL
            outFile << setw(30) << left << temp->getName()
                    << setw(15) << temp->getIC()
                    << setw(5) << temp->getAge()
                    << setw(10) << temp->getGender()
                    << setw(17) << temp->getContactNum()
                    << setw(25) << temp->getDisease()
                    << setw(15) << temp->getDate() << endl
                    << endl;
            temp = temp->next;
        }
    }

private:
    // Merge Sort Helper Function
    void mergeSort(Patient **headRef, string criteria)
    {
        Patient *head = *headRef;
        Patient *a;
        Patient *b;

        // Base case -- length 0 or 1
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        // Split head into 'a' and 'b' sublists
        frontBackSplit(head, &a, &b);

        // Recursively sort the sublists
        mergeSort(&a, criteria);
        mergeSort(&b, criteria);

        // Answer = merge the two sorted lists together
        if (criteria == "name")
        {
            *headRef = sortedMergeByName(a, b);
        }
        else if (criteria == "ic")
        {
            *headRef = sortedMergeByIC(a, b);
        }
        else if (criteria == "disease")
        {
            *headRef = sortedMergeByDisease(a, b);
        }
    }

    // Merge Sort Helper Function - Front-Back Split
    void frontBackSplit(Patient *source, Patient **frontRef, Patient **backRef)
    {
        Patient *fast;
        Patient *slow;
        slow = source;
        fast = source->next;

        // Advance 'fast' two nodes, and advance 'slow' one node
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // 'slow' is before the midpoint in the list, so split it in two at that point.
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }

    // Merge Sort Helper Function - Sorted Merge by name
    Patient *sortedMergeByName(Patient *a, Patient *b)
    {
        Patient *result = NULL;

        // Base cases
        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        // Pick either a or b, and recur
        if (a->getName() <= b->getName())
        {
            result = a;
            result->next = sortedMergeByName(a->next, b);
        }
        else
        {
            result = b;
            result->next = sortedMergeByName(a, b->next);
        }

        return result;
    }

    // Merge Sort Helper Function - Sorted Merge by IC
    Patient *sortedMergeByIC(Patient *a, Patient *b)
    {
        Patient *result = NULL;

        // Base cases
        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        // Pick either a or b, and recur
        if (a->getIC() <= b->getIC())
        {
            result = a;
            result->next = sortedMergeByIC(a->next, b);
        }
        else
        {
            result = b;
            result->next = sortedMergeByIC(a, b->next);
        }

        return result;
    }

    // Merge Sort Helper Function - Sorted Merge by disease
    Patient *sortedMergeByDisease(Patient *a, Patient *b)
    {
        Patient *result = NULL;

        // Base cases
        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        // Pick either a or b, and recur
        if (a->getDisease() <= b->getDisease())
        {
            result = a;
            result->next = sortedMergeByDisease(a->next, b);
        }
        else
        {
            result = b;
            result->next = sortedMergeByDisease(a, b->next);
        }

        return result;
    }
};

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
    Queue patList;
    int opt, choice, age;
    bool logout = false;
    string name, ic, gender, contactNum, disease, date;

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

    // read file
    fstream inFile("record.txt", ios::in);
    if (!inFile)
    {
        cout << "Can't open the file!" << endl;
        system("pause");
        return 0;
    }

    // store the data from file into linked list
    int i = 0;
    while (!inFile.eof())
    {
        getline(inFile, name, '|');
        getline(inFile, ic, '|');
        inFile >> age; // Read age as integer
        inFile.ignore();
        getline(inFile, gender, '|');
        getline(inFile, contactNum, '|');
        getline(inFile, disease, '|');
        inFile >> date;
        inFile.ignore();

        Patient *pat = new Patient(name, ic, age, gender, contactNum, disease, date);
        patList.enQueue(pat);
        i++;
    }
    inFile.close();

    // main page
    while (!logout)
    {
        system("cls");
        cout << "\nHospital Management System\n\n<<MAIN PAGE>>\n[1] Add new patient\n[2] Delete patient\n[3] Search patient\n[4] Sort patient\n[5] Display patient list\n[6] Logout"
             << endl;
        cout << "\nOption: ";
        cin >> opt;
        cin.ignore();

        if (opt == 1)
        {

            
        }else if (opt == 3)
        {
            while (true)
            {
                system("cls");
                cout << "<<SEARCH PATIENT>>" << endl;
                cout << "[1] Search by name" << endl;
                cout << "[2] Search by IC" << endl;
                cout << "[3] Search by disease" << endl;
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

                Patient *resultNode = nullptr;

                switch (choice)
                {
                case 1:
                    resultNode = patList.searchByName(keyword);
                    break;
                case 2:
                    resultNode = patList.searchByIC(keyword);
                    break;
                case 3:
                    resultNode = patList.searchByDisease(keyword);
                    break;
                }

                if (resultNode != nullptr)
                {
                    // Display the found patient details
                    cout << "\nPatient Found:" << endl;
                    resultNode->print();
                }
                else
                {
                    cout << "\nPatient not found." << endl;
                }

                system("pause");
            }
        }
        else if (opt == 4)
        {
            // Sort patient
            while (true)
            {
                system("cls");
                cout << "<<SORT PATIENT>>" << endl;
                cout << "[1] Sort by name" << endl;
                cout << "[2] Sort by IC" << endl;
                cout << "[3] Sort by disease" << endl;
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

                switch (choice)
                {
                case 1:
                    patList.mergeSortByName();
                    cout << "\nPatient list sorted by name." << endl;
                    break;
                case 2:
                    patList.mergeSortByIC();
                    cout << "\nPatient list sorted by IC." << endl;
                    break;
                case 3:
                    patList.mergeSortByDisease();
                    cout << "\nPatient list sorted by disease." << endl;
                    break;
                }
                system("pause");
            }

        }else if (opt == 6)
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