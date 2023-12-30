#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
#define ARRAY_SIZE 5
#define bulkyheavydelivery 'A'
#define standarddelivery 'B'
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
void selectionSortAsc(Parcel* parcel[], int size) {

    for (int last = size - 1; last > 0; last--) {

        int largest = 0;
        for (int i = 0; i <= last; i++) {

            if (parcel[i]->getCategory() > parcel[largest]->getCategory())
                largest = i;
        }
        if (largest != last) {
            swap(parcel[largest], parcel[last]);
        }
    }
}

void selectionSortDesc(Parcel* parcel[], int size) {

    for (int last = size - 1; last > 0; last--) {

        int largest = 0;
        for (int i = 0; i <= last; i++) {

            if (parcel[i]->getCategory() < parcel[largest]->getCategory())
                largest = i;
        }
        if (largest != last) {
            swap(parcel[largest], parcel[last]);
        }
    }
}
void displaySelectionSortMenu(char cat, Parcel* parcel[], int count) {
    cout << "After Sort " << endl << endl;

    if (cat == 'A' || cat == 'a') {
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
    char category;
    Parcel* parcel[ARRAY_SIZE];
    inputFile(parcel, count);
    cout << endl;
    cout << "Before Sort : " << endl;

    dispItems(parcel, count);

    cout << "Enter 'A' to sort parcel by shipping category in Ascending Order" << endl;
    cout << "Enter 'B' to sort parcel by shipping category in Descending Order" << endl;
    cout << "Category: ";
    cin >> category;
    displaySelectionSortMenu(category, parcel, count);

    return 0;
}
