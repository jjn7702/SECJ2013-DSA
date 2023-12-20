#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <Windows.h>
#include <stdio.h>

#define SIZE 10000

using namespace std;

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
    Patient();
    Patient(string, string, int, string, string, string, string);
    string getName() const;
    string getIC() const;
    int getAge() const;
    string getGender() const;
    string getContactNum() const;
    string getDisease() const;
    string getDate() const;
    void setName(string);
    void setIC(string);
    void setAge(int);
    void setGender(string);
    void setContactNum(string);
    void setDisease(string);
    void setDate(string);
    void display();
};

// default constructor
Patient::Patient()
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
Patient::Patient(string n, string i, int a, string g, string c, string d, string dt)
{
    name = n;
    ic = i;
    age = a;
    gender = g;
    contactNum = c;
    disease = d;
    date = dt;
}

// get
string Patient::getName() const
{
    return name;
}

string Patient::getIC() const
{
    return ic;
}

int Patient::getAge() const
{
    return age;
}

string Patient::getGender() const
{
    return gender;
}

string Patient::getContactNum() const
{
    return contactNum;
}

string Patient::getDisease() const
{
    return disease;
}

string Patient::getDate() const
{
    return date;
}

// set
void Patient::setName(string n)
{
    name = n;
}

void Patient::setIC(string i)
{
    ic = i;
}

void Patient::setAge(int a)
{
    age = a;
}

void Patient::setGender(string g)
{
    gender = g;
}

void Patient::setContactNum(string c)
{
    contactNum = c;
}

void Patient::setDisease(string d)
{
    disease = d;
}

void Patient::setDate(string dt)
{
    date = dt;
}

// display
void Patient::display()
{
    cout << setw(30) << left << name
         << setw(15) << ic
         << setw(5) << age
         << setw(10) << gender
         << setw(17) << contactNum
         << setw(30) << disease
         << setw(15) << date << endl << endl;
}

// display header
void dispHeader()
{
    cout << endl;
    cout << "Patient Record: " << endl << endl;
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