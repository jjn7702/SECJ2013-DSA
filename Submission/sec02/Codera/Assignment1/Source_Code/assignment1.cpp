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

// sorting
void mergeByName(Patient pat[], int first, int mid, int last)
{
    int size = last - first + 1;
    Patient *tempArray = new Patient[size];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;

    while (first1 <= last1 && first2 <= last2)
    {
        if (pat[first1].getName() < pat[first2].getName())
        {
            tempArray[index] = pat[first1];
            ++first1;
        }
        else
        {
            tempArray[index] = pat[first2];
            ++first2;
        }
        ++index;
    }

    while (first1 <= last1)
    {
        tempArray[index] = pat[first1];
        ++first1;
        ++index;
    }

    while (first2 <= last2)
    {
        tempArray[index] = pat[first2];
        ++first2;
        ++index;
    }

    for (int i = 0; i < size; ++i)
    {
        pat[first + i] = tempArray[i];
    }

    delete[] tempArray;
}

void mergeSortByName(Patient pat[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;

        mergeSortByName(pat, first, mid);
        mergeSortByName(pat, mid + 1, last);

        mergeByName(pat, first, mid, last);
    }
}

void mergeByIC(Patient pat[], int first, int mid, int last)
{
    int size = last - first + 1;
    Patient *tempArray = new Patient[size];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;

    while (first1 <= last1 && first2 <= last2)
    {
        if (pat[first1].getIC() < pat[first2].getIC())
        {
            tempArray[index] = pat[first1];
            ++first1;
        }
        else
        {
            tempArray[index] = pat[first2];
            ++first2;
        }
        ++index;
    }

    while (first1 <= last1)
    {
        tempArray[index] = pat[first1];
        ++first1;
        ++index;
    }

    while (first2 <= last2)
    {
        tempArray[index] = pat[first2];
        ++first2;
        ++index;
    }

    for (int i = 0; i < size; ++i)
    {
        pat[first + i] = tempArray[i];
    }

    delete[] tempArray;
}

void mergeSortByIC(Patient pat[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;

        mergeSortByIC(pat, first, mid);
        mergeSortByIC(pat, mid + 1, last);

        mergeByIC(pat, first, mid, last);
    }
}

void mergeByAge(Patient pat[], int first, int mid, int last)
{
    int size = last - first + 1;
    Patient *tempArray = new Patient[size];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;

    while (first1 <= last1 && first2 <= last2)
    {
        if (pat[first1].getAge() < pat[first2].getAge())
        {
            tempArray[index] = pat[first1];
            ++first1;
        }
        else
        {
            tempArray[index] = pat[first2];
            ++first2;
        }
        ++index;
    }

    while (first1 <= last1)
    {
        tempArray[index] = pat[first1];
        ++first1;
        ++index;
    }

    while (first2 <= last2)
    {
        tempArray[index] = pat[first2];
        ++first2;
        ++index;
    }

    for (int i = 0; i < size; ++i)
    {
        pat[first + i] = tempArray[i];
    }

    delete[] tempArray;
}

void mergeSortByAge(Patient pat[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;

        mergeSortByAge(pat, first, mid);
        mergeSortByAge(pat, mid + 1, last);

        mergeByAge(pat, first, mid, last);
    }
}

void mergeByGender(Patient pat[], int first, int mid, int last)
{
    int size = last - first + 1;
    Patient *tempArray = new Patient[size];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;

    while (first1 <= last1 && first2 <= last2)
    {
        if (pat[first1].getGender() < pat[first2].getGender())
        {
            tempArray[index] = pat[first1];
            ++first1;
        }
        else
        {
            tempArray[index] = pat[first2];
            ++first2;
        }
        ++index;
    }

    while (first1 <= last1)
    {
        tempArray[index] = pat[first1];
        ++first1;
        ++index;
    }

    while (first2 <= last2)
    {
        tempArray[index] = pat[first2];
        ++first2;
        ++index;
    }

    for (int i = 0; i < size; ++i)
    {
        pat[first + i] = tempArray[i];
    }

    delete[] tempArray;
}

void mergeSortByGender(Patient pat[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;

        mergeSortByGender(pat, first, mid);
        mergeSortByGender(pat, mid + 1, last);

        mergeByGender(pat, first, mid, last);
    }
}

void mergeByContactNum(Patient pat[], int first, int mid, int last)
{
    int size = last - first + 1;
    Patient *tempArray = new Patient[size];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;

    while (first1 <= last1 && first2 <= last2)
    {
        if (pat[first1].getContactNum() < pat[first2].getContactNum())
        {
            tempArray[index] = pat[first1];
            ++first1;
        }
        else
        {
            tempArray[index] = pat[first2];
            ++first2;
        }
        ++index;
    }

    while (first1 <= last1)
    {
        tempArray[index] = pat[first1];
        ++first1;
        ++index;
    }

    while (first2 <= last2)
    {
        tempArray[index] = pat[first2];
        ++first2;
        ++index;
    }

    for (int i = 0; i < size; ++i)
    {
        pat[first + i] = tempArray[i];
    }

    delete[] tempArray;
}

void mergeSortByContactNum(Patient pat[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;

        mergeSortByContactNum(pat, first, mid);
        mergeSortByContactNum(pat, mid + 1, last);

        mergeByContactNum(pat, first, mid, last);
    }
}

void mergeByDisease(Patient pat[], int first, int mid, int last)
{
    int size = last - first + 1;
    Patient *tempArray = new Patient[size];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;

    while (first1 <= last1 && first2 <= last2)
    {
        if (pat[first1].getDisease() < pat[first2].getDisease())
        {
            tempArray[index] = pat[first1];
            ++first1;
        }
        else
        {
            tempArray[index] = pat[first2];
            ++first2;
        }
        ++index;
    }

    while (first1 <= last1)
    {
        tempArray[index] = pat[first1];
        ++first1;
        ++index;
    }

    while (first2 <= last2)
    {
        tempArray[index] = pat[first2];
        ++first2;
        ++index;
    }

    for (int i = 0; i < size; ++i)
    {
        pat[first + i] = tempArray[i];
    }

    delete[] tempArray;
}

void mergeSortByDisease(Patient pat[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;

        mergeSortByDisease(pat, first, mid);
        mergeSortByDisease(pat, mid + 1, last);

        mergeByDisease(pat, first, mid, last);
    }
}

void mergeByDate(Patient pat[], int first, int mid, int last)
{
    int size = last - first + 1;
    Patient *tempArray = new Patient[size];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;

    while (first1 <= last1 && first2 <= last2)
    {
        if (pat[first1].getDate() < pat[first2].getDate())
        {
            tempArray[index] = pat[first1];
            ++first1;
        }
        else
        {
            tempArray[index] = pat[first2];
            ++first2;
        }
        ++index;
    }

    while (first1 <= last1)
    {
        tempArray[index] = pat[first1];
        ++first1;
        ++index;
    }

    while (first2 <= last2)
    {
        tempArray[index] = pat[first2];
        ++first2;
        ++index;
    }

    for (int i = 0; i < size; ++i)
    {
        pat[first + i] = tempArray[i];
    }

    delete[] tempArray;
}

void mergeSortByDate(Patient pat[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;

        mergeSortByDate(pat, first, mid);
        mergeSortByDate(pat, mid + 1, last);

        mergeByDate(pat, first, mid, last);
    }
}
