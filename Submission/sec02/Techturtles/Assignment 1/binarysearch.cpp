#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
#define ARRAY_SIZE 5

/*
    Delivery status (sorting) - use bubblesort
    I. complete (0)
    II. incomplete (1)

    Shipping category (sorting) - use selection sort
    I.bulky& heavy delivery(A)
    II.standard delivery(B)

*/

class Parcel {
private:
    string trackingNumber, address, nameSender, nameReceiver;
    char category;
    int status;

public:

    Parcel() {}

    Parcel(string tracking, string addr, string nameS, string nameR, char categ, int stat) {
        trackingNumber = tracking;
        address = addr;
        nameSender = nameS;
        nameReceiver = nameR;
        category = categ;
        status = stat;
    }

    string getTrackingNumber() {

        return trackingNumber;
    }

    string getAddress() {
        return address;
    }

    string getNameSender() {
        return nameSender;
    }

    string getNameReceiver() {
        return nameReceiver;
    }

    char getCategory() {

        return category;
    }

    int getStatus() {
        return status;
    }

    void displayShippingCategory() {
        if (category == 'A' || category == 'a') {
            cout << "Bulky & Heavy Delivery";
        }
        else
            cout << "Standard Delivery";
        cout << endl;
    }
    void displayStatus_Delivery() {
        if (status == 0) {
            cout << "COMPLETE";
        }
        else
            cout << "INCOMPLETE";
        cout << endl;
    }

    void displayParcelDetails()
    {
        cout << "Tracking No. : " << trackingNumber << endl;
        cout << "Address : " << address << endl;
        cout << "Sender : " << nameSender << endl;
        cout << "Receiver : " << nameReceiver << endl;
        cout << "Shipping category : ";
        displayShippingCategory();
        cout << "Parcel status : ";
        displayStatus_Delivery();
    }
};

//Dispaly items in array
void dispItems(Parcel* parcel[], int listSize)
{
    for (int i = 0;i < listSize;i++) {
        parcel[i]->displayParcelDetails();
        cout << endl << endl;
    }
}

void mergeAsc(Parcel* theArray[], int first, int mid, int last) {
    {
        Parcel* tempArray[ARRAY_SIZE]; // temp array
        int first1 = first; // first subarray begin
        int last1 = mid; // end of first subarray
        int first2 = mid + 1; // second subarray begin
        int last2 = last; // end of second subarray
        int index = first1; // next available location in tempArray

        for (; (first1 <= last1) && (first2 <= last2); ++index) {
            if (theArray[first1]->getTrackingNumber() < theArray[first2]->getTrackingNumber()) {
                tempArray[index] = theArray[first1];
                ++first1;
            }
            else {
                tempArray[index] = theArray[first2];
                ++first2;
            }
        }

        for (; first1 <= last1; ++first1, ++index) //copying elements from one array (theArray) to another (tempArray) within a specified range [first1, last1].
            tempArray[index] = theArray[first1];

        for (; first2 <= last2; ++first2, ++index)
            tempArray[index] = theArray[first2];

        for (index = first; index <= last; ++index)
            theArray[index] = tempArray[index];
    }
}

void mergeSortAsc(Parcel* theArray[], int first, int last) {
    {

        if (first < last) {
            int mid = (first + last) / 2; // index of midpoint

            mergeSortAsc(theArray, first, mid);
            mergeSortAsc(theArray, mid + 1, last);
            mergeAsc(theArray, first, mid, last);
        }
    }
}

void mergeDesc(Parcel* theArray[], int first, int mid, int last) {
    {
        Parcel* tempArray[ARRAY_SIZE]; // temp array
        int first1 = first; // first subarray begin
        int last1 = mid; // end of first subarray
        int first2 = mid + 1; // second subarray begin
        int last2 = last; // end of second subarray
        int index = first1; // next available location in tempArray

        for (; (first1 <= last1) && (first2 <= last2); ++index) {
            if (theArray[first1]->getTrackingNumber() > theArray[first2]->getTrackingNumber()) {
                tempArray[index] = theArray[first1];
                ++first1;
            }
            else {
                tempArray[index] = theArray[first2];
                ++first2;
            }
        }

        for (; first1 <= last1; ++first1, ++index) //copying elements from one array (theArray) to another (tempArray) within a specified range [first1, last1].
            tempArray[index] = theArray[first1];

        for (; first2 <= last2; ++first2, ++index)
            tempArray[index] = theArray[first2];

        for (index = first; index <= last; ++index)
            theArray[index] = tempArray[index];
    }
}

void mergeSortDesc(Parcel* theArray[], int first, int last) {
    {

        if (first < last) {
            int mid = (first + last) / 2; // index of midpoint

            mergeSortDesc(theArray, first, mid);
            mergeSortDesc(theArray, mid + 1, last);
            mergeDesc(theArray, first, mid, last);
        }
    }
}

void displayMergeSortMenu(int opt, Parcel* parcel[], int count) {
    cout << "After Sort " << endl << endl;

    if (opt == 1) {
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

int binarySearch(Parcel* arr[], string key, int size) {

    bool found = false;
    int index = -1;
    int middle;
    int left = 0;
    int right = size - 1;

    while ((left <= right) && (!found)) {

        middle = (left + right) / 2;
        if (arr[middle]->getTrackingNumber() == key) {

            index = middle;
            found = true;
        }
        else if (arr[middle]->getTrackingNumber() > key) {

            right = middle - 1;
        }
        else {

            left = middle + 1;
        }
    }

    return index;
}

void inputFile(Parcel* arr[], int& count) {
    ifstream input("ParcelData.txt");
    string buffer;
    string tracking_no, address, sender_name, receiver_name, shipping_option, status_delivery;
    getline(input, buffer);
    for (int i = 0; !input.eof(); i++) {
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

int main()
{
    int option, size = 1, count = 0;
    string userKey;
    Parcel* parcel[ARRAY_SIZE];
    inputFile(parcel, count);
    cout << endl;
    cout << "Before Sort : " << endl;

    dispItems(parcel, count);

    cout << endl;
    cout << "Enter parcel tracking number to search for parcel : ";
    cin >> userKey;
    mergeSortAsc(parcel, 0, count - 1);
    int parcelIndex = binarySearch(parcel, userKey, count);
    parcel[parcelIndex]->displayParcelDetails();

    return 0;
}