#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
#define ARRAY_SIZE 5
#define COMPLETE 0
#define INCOMPLETE 1

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

void BubbleSortAsc(Parcel* parcel[], int listSize)
{
    Parcel* tempValue;
    bool sorted = false;
    for (int pass = 1; (pass < listSize) && !sorted; ++pass) {
        sorted = true;
        // moves the largest element to the 
        // end of the array 
        for (int x = 0; x < listSize - pass; x++)
        {      // compare adjacent elements 
            if (parcel[x]->getStatus() > parcel[x + 1]->getStatus()) {
                // swap elements 
                tempValue = parcel[x];
                parcel[x] = parcel[x + 1];
                parcel[x + 1] = tempValue;
                sorted = false;
            }
        }
    }
} // end Bubble Sort

void BubbleSortDesc(Parcel* parcel[], int listSize)
{
    Parcel* tempValue;
    bool sorted = false;
    for (int pass = 1; (pass < listSize) && !sorted; ++pass) {
        sorted = true;
        // moves the largest element to the 
        // end of the array 
        for (int x = 0; x < listSize - pass; x++)
        {      // compare adjacent elements 
            if (parcel[x]->getStatus() < parcel[x + 1]->getStatus()) {
                // swap elements 
                tempValue = parcel[x];
                parcel[x] = parcel[x + 1];
                parcel[x + 1] = tempValue;
                sorted = false;
            }
        }
    }
} // end Bubble Sort

void displayBubbleSortMenu(int opt, Parcel* parcel[], int count) {
    cout << "After Sort " << endl << endl;

    if (opt == 1) {
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
    int option, count = 0;
    Parcel* parcel[ARRAY_SIZE];
    inputFile(parcel, count);
    cout << endl;
    cout << "Before Sort : " << endl;

    dispItems(parcel, count);

    cout << "Enter '1' to sort parcel by status in Ascending Order" << endl;
    cout << "Enter '2' to sort parcel by status in Descending Order" << endl;
    cout << "Option: ";
    cin >> option;
    displayBubbleSortMenu(option, parcel, count);

    return 0;
}
