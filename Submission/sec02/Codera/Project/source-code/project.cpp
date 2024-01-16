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

// Queue
class Queue
{
public:
    Node *back, *front;

    Queue(){
        front = NULL;
        back = NULL;
    }

    bool isEmpty(){
        return ((front == NULL) && (back == NULL));
    }

    void enQueue(int d){
        Node *newNode = new Node(d);

        if(isEmpty()){
            front = newNode;
            back = newNode;
        }
        else{
            back->next =  newNode;
            back = newNode;
        }
    }

    void deQueue(){
        Node *delNode = front;
        if(isEmpty())
            cout << "The queue is empty" << endl;
        else{
            if(front != back){
                front = front->next;
                delNode->next = NULL;
            }
            else{
                front = NULL;
                back = NULL;
            }
            delete delNode;
        }
    }

    void print(){
        if(isEmpty())
            cout << "Sorry, nothing in queue" << endl;
        else{
            Node *temp = front;

            while(temp){ //temp != NULL
                cout << temp->getData() << " ";
                temp = temp->next;
            }
            cout << endl;
        }
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
    int opt, choice;
    bool logout = false;

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
        cout << "\nHospital Management System\n\n<<MAIN PAGE>>\n[1] Add new patient\n[2] Delete patient\n[3] Search patient\n[4] Sort patient\n[5] Display patient list\n[6] Logout"
             << endl;
        cout << "\nOption: ";
        cin >> opt;
        cin.ignore();

        if (opt == 1)
        {
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