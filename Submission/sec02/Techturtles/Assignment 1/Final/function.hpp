#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Parcel.hpp"
using namespace std;

#define ARRAY_SIZE 5

// Dispaly items in array
void dispItems(Parcel *parcel[], int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        parcel[i]->displayParcelDetails();
        cout << endl
             << endl;
    }
}

void BubbleSortAsc(Parcel *parcel[], int listSize)
{
    Parcel *tempValue;
    bool sorted = false;
    for (int pass = 1; (pass < listSize) && !sorted; ++pass)
    {
        sorted = true;
        // moves the largest element to the
        // end of the array
        for (int x = 0; x < listSize - pass; x++)
        { // compare adjacent elements
            if (parcel[x]->getStatus() > parcel[x + 1]->getStatus())
            {
                // swap elements
                tempValue = parcel[x];
                parcel[x] = parcel[x + 1];
                parcel[x + 1] = tempValue;
                sorted = false;
            }
        }
    }
} // end Bubble Sort

void BubbleSortDesc(Parcel *parcel[], int listSize)
{
    Parcel *tempValue;
    bool sorted = false;
    for (int pass = 1; (pass < listSize) && !sorted; ++pass)
    {
        sorted = true;
        // moves the largest element to the
        // end of the array
        for (int x = 0; x < listSize - pass; x++)
        { // compare adjacent elements
            if (parcel[x]->getStatus() < parcel[x + 1]->getStatus())
            {
                // swap elements
                tempValue = parcel[x];
                parcel[x] = parcel[x + 1];
                parcel[x + 1] = tempValue;
                sorted = false;
            }
        }
    }
} // end Bubble Sort

void displayBubbleSortMenu(int opt, Parcel *parcel[], int count)
{
    cout << "After Sort " << endl
         << endl;

    if (opt == 1)
    {
        BubbleSortAsc(parcel, count);
        dispItems(parcel, count);
    }
    else if (opt == 2)
    {
        BubbleSortDesc(parcel, count);
        dispItems(parcel, count);
    }
    else
        return;
}

void selectionSortAsc(Parcel *parcel[], int size)
{

    for (int last = size - 1; last > 0; last--)
    {

        int largest = 0;
        for (int i = 0; i <= last; i++)
        {

            if (parcel[i]->getCategory() > parcel[largest]->getCategory())
                largest = i;
        }
        if (largest != last)
        {
            swap(parcel[largest], parcel[last]);
        }
    }
}

void selectionSortDesc(Parcel *parcel[], int size)
{

    for (int last = size - 1; last > 0; last--)
    {

        int largest = 0;
        for (int i = 0; i <= last; i++)
        {

            if (parcel[i]->getCategory() < parcel[largest]->getCategory())
                largest = i;
        }
        if (largest != last)
        {
            swap(parcel[largest], parcel[last]);
        }
    }
}
void displaySelectionSortMenu(char cat, Parcel *parcel[], int count)
{
    cout << "After Sort " << endl
         << endl;

    if (cat == 'A' || cat == 'a')
    {
        selectionSortAsc(parcel, count);
        dispItems(parcel, count);
    }
    else if (cat == 'B' || cat == 'b')
    {
        selectionSortDesc(parcel, count);
        dispItems(parcel, count);
    }
    else
        return;
}

void mergeAsc(Parcel *theArray[], int first, int mid, int last)
{
    {
        Parcel *tempArray[ARRAY_SIZE]; // temp array
        int first1 = first;            // first subarray begin
        int last1 = mid;               // end of first subarray
        int first2 = mid + 1;          // second subarray begin
        int last2 = last;              // end of second subarray
        int index = first1;            // next available location in tempArray

        for (; (first1 <= last1) && (first2 <= last2); ++index)
        {
            if (theArray[first1]->getTrackingNumber() < theArray[first2]->getTrackingNumber())
            {
                tempArray[index] = theArray[first1];
                ++first1;
            }
            else
            {
                tempArray[index] = theArray[first2];
                ++first2;
            }
        }

        for (; first1 <= last1; ++first1, ++index) // copying elements from one array (theArray) to another (tempArray) within a specified range [first1, last1].
            tempArray[index] = theArray[first1];

        for (; first2 <= last2; ++first2, ++index)
            tempArray[index] = theArray[first2];

        for (index = first; index <= last; ++index)
            theArray[index] = tempArray[index];
    }
}

void mergeSortAsc(Parcel *theArray[], int first, int last)
{
    {

        if (first < last)
        {
            int mid = (first + last) / 2; // index of midpoint

            mergeSortAsc(theArray, first, mid);
            mergeSortAsc(theArray, mid + 1, last);
            mergeAsc(theArray, first, mid, last);
        }
    }
}

void mergeDesc(Parcel *theArray[], int first, int mid, int last)
{
    {
        Parcel *tempArray[ARRAY_SIZE]; // temp array
        int first1 = first;            // first subarray begin
        int last1 = mid;               // end of first subarray
        int first2 = mid + 1;          // second subarray begin
        int last2 = last;              // end of second subarray
        int index = first1;            // next available location in tempArray

        for (; (first1 <= last1) && (first2 <= last2); ++index)
        {
            if (theArray[first1]->getTrackingNumber() > theArray[first2]->getTrackingNumber())
            {
                tempArray[index] = theArray[first1];
                ++first1;
            }
            else
            {
                tempArray[index] = theArray[first2];
                ++first2;
            }
        }

        for (; first1 <= last1; ++first1, ++index) // copying elements from one array (theArray) to another (tempArray) within a specified range [first1, last1].
            tempArray[index] = theArray[first1];

        for (; first2 <= last2; ++first2, ++index)
            tempArray[index] = theArray[first2];

        for (index = first; index <= last; ++index)
            theArray[index] = tempArray[index];
    }
}

void mergeSortDesc(Parcel *theArray[], int first, int last)
{
    {

        if (first < last)
        {
            int mid = (first + last) / 2; // index of midpoint

            mergeSortDesc(theArray, first, mid);
            mergeSortDesc(theArray, mid + 1, last);
            mergeDesc(theArray, first, mid, last);
        }
    }
}

void displayMergeSortMenu(int opt, Parcel *parcel[], int count)
{
    cout << "After Sort " << endl
         << endl;

    if (opt == 1)
    {
        mergeSortAsc(parcel, 0, count - 1);
        dispItems(parcel, count);
    }
    else if (opt == 2)
    {
        mergeSortDesc(parcel, 0, count - 1);
        dispItems(parcel, count);
    }
    else
        return;
}

// Function to display main menu
void displayMenu()
{
    cout << "WELCOME TO TECHTURTLES PARCEL SYSTEM" << endl;
    cout << "1. Add New Parcel" << endl;
    cout << "2. Search parcel by Tracking No." << endl;
    cout << "3. Sort Parcel by Delivery Status" << endl;
    cout << "4. Sort Parcel by Shipping Option" << endl;
    cout << "5. Sort Parcel by Tracking No" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

int binarySearch(Parcel *arr[], string key, int size)
{

    bool found = false;
    int index = -1;
    int middle;
    int left = 0;
    int right = size - 1;

    while ((left <= right) && (!found))
    {

        middle = (left + right) / 2;
        if (arr[middle]->getTrackingNumber() == key)
        {

            index = middle;
            found = true;
        }
        else if (arr[middle]->getTrackingNumber() > key)
        {

            right = middle - 1;
        }
        else
        {

            left = middle + 1;
        }
    }

    return index;
}

void inputFile(Parcel *arr[], int &count)
{
    ifstream input("ParcelData.txt");
    string buffer;
    string tracking_no, address, sender_name, receiver_name, shipping_option, status_delivery;
    getline(input, buffer);
    for (int i = 0; !input.eof(); i++)
    {
        getline(input, tracking_no, ';');
        getline(input, address, ';');
        getline(input, sender_name, ';');
        getline(input, receiver_name, ';');
        getline(input, shipping_option, ';');
        getline(input, status_delivery);

        arr[i] = new Parcel(tracking_no, address, sender_name, receiver_name, shipping_option[1], stoi(status_delivery));
        count++;
    }
}

void addNewParcel(Parcel *parcel[], int &count)
{
    string tracking_no, address, sender_name, receiver_name;
    char shipping_option;
    int status_delivery;
    cout << "Enter Parcel's Tracking No. : ";
    cin >> tracking_no;
    fflush(stdin);
    cout << "Enter Parcel's Address : ";
    getline(cin, address);
    cout << "Enter Parcel's Sender Name: ";
    cin >> sender_name;
    cout << "Enter Parcel' Receiver Name : ";
    cin >> receiver_name;
    cout << "Enter Shipping Option 'A' for Bulky & Heavy Delivery and 'B' for Standard Delivery: ";
    cin >> shipping_option;
    cout << "Enter Status Delivery '0' for Complete and '1' for Incomplete: ";
    cin >> status_delivery;
    count++;
    parcel[count - 1] = new Parcel(tracking_no, address, sender_name, receiver_name, shipping_option, status_delivery);
}
