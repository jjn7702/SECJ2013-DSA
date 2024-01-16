// Project - SECJ2013 - 23241 (main.cpp)
// Group Members:
// 1. Muhammad Nur Azhar Bin Mohd Yazid A22EC0220
// 2. Muhammad Daniel Hakim Bin Syahrulnizam A22EC0207
// 3. Muhammad Safwan Bin Mohd Azmi A22EC0221

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <stack>
#include <queue>
#define COMPLETE 0
#define INCOMPLETE 1
#define bulkyheavydelivery 'A'
#define standarddelivery 'B'

using namespace std;

class Parcel {
private:
    string trackingNumber, address, nameSender, nameReceiver;
    char category; // 'A' for Bulky & Heavy Delivery, 'B' for Standard Delivery
    int status;    // '0' for Incomplete, '1' for Complete
    string note;

public:
    Parcel(string tn, string a, string nSend, string nRec, char c, int s)
        : trackingNumber(tn), address(a), nameSender(nSend), nameReceiver(nRec), category(c), status(s) {}

    string getTrackingNumber() const {
        return trackingNumber;
    }

    string getAddress() const {
        return address;
    }

    string getSender() const {
        return nameSender;
    }

    string getReceiver() const {
        return nameReceiver;
    }

    char getCategory() const {
        return category;
    }

    int getStatus() const {
        return status;
    }

    void addNoteToParcel(const string& n) {
        note = n;
    }

    void displayDetails(int count) {
        cout << "\t" << left << setw(5) << count
            << setw(15) << trackingNumber
            << setw(30) << address
            << setw(15) << nameSender
            << setw(15) << nameReceiver
            << setw(10);
        displayShippingCategory();
        cout << setw(7) << "\t";
        displayStatusDelivery();
        cout << endl;
        cout << "\t";
        for (int i = 0; i < 120; i++)
        {
            cout << "-";
        }
        cout << endl;

        if (!note.empty()) {
            cout << "\tNote: " << note << endl;
        }
    }

    void displayShippingCategory() {
        if (category == 'A' || category == 'a') {
            cout << "Bulky & Heavy Delivery";
        }
        else
            cout << "Standard Delivery";
    }

    void displayStatusDelivery() {
        if (status == 0) {
            cout << "COMPLETE";
        }
        else
            cout << "INCOMPLETE";
        cout << endl;
    }
};



class ParcelList {
private:
    stack<Parcel*> parcelStack;
    queue<Parcel*> parcelQueue;

public:
    void addNode(Parcel* newParcel) {
        // Add a new parcel to the stack

        parcelStack.push(newParcel);
    }
    void displayAllNodes() {
        if (parcelStack.empty()) {
            cout << "No parcels to display.\n";
            return;
        }

        stack<Parcel*> tempStack = parcelStack;  // Create a temporary stack

        int count = 1;
        while (!tempStack.empty()) {
            Parcel* currentParcel = tempStack.top();
            currentParcel->displayDetails(count);
            tempStack.pop();
            count++;
        }
    }
    void deleteNode() {
        if (!parcelStack.empty()) {
            Parcel* deletedParcel = parcelStack.top();
            parcelStack.pop();
            delete deletedParcel; // Release memory allocated for the deleted parcel
            cout << "Last added parcel deleted.\n";
        }
        else {
            cout << "No parcels to delete.\n";
        }
    }

    void enQueue(Parcel* newParcel) {
        parcelQueue.push(newParcel);
    }
    void deQueue() {
        if (!parcelQueue.empty()) {
            Parcel* deletedParcel = parcelQueue.front();
            parcelQueue.pop();
            delete deletedParcel;
            cout << "Last added parcel deleted from the queue.\n";
        }
        else {
            cout << "No parcels to deQueue.\n";
        }
    }

    void displayAllNodesQueue() {
        if (parcelQueue.empty()) {
            cout << "No parcels to display.\n";
            return;
        }

        queue<Parcel*> tempQueue = parcelQueue;  // Create a temporary queue

        int count = 1;
        while (!tempQueue.empty()) {
            Parcel* currentParcel = tempQueue.front();  // Use front() instead of top()
            currentParcel->displayDetails(count);
            tempQueue.pop();
            count++;
        }
    }
};

void displayMenu() {
    cout << "\t+----------------------------------+\n";
    cout << "\t|   Courier Service System Menu    |\n";
    cout << "\t+----------------------------------+\n";
    cout << "\t| 1. Add a new parcel              |\n";
    cout << "\t| 2. Delete a parcel               |\n";
    cout << "\t| 3. Exit                          |\n";
    cout << "\t+----------------------------------+\n";
}

void displayOption() {
    cout << "\t+------------------------------------------+\n";
    cout << "\t|    Courier Service System Menu           |\n";
    cout << "\t+------------------------------------------+\n";
    cout << "\t| 1. Parcel using Implementation of Stack  |\n";
    cout << "\t| 2. Parcel using Implementation of Queue  |\n";
    cout << "\t| 3. Exit                                  |\n";
    cout << "\t+------------------------------------------+\n";
}

int main() {

    while (true) {
        displayOption();

        cout << "\nEnter your choice: ";
        int option;
        cin >> option;

        switch (option) {
        case 1: {
            cout << "STACK IMPLEMENTION..." << endl << endl;

            ParcelList p1;

            ifstream inFile("ParcelData.txt"); // Change the file name as needed

            if (!inFile.is_open()) {
                cerr << "Error opening file." << endl;
                return 1;
            }

            string headerLine;
            getline(inFile, headerLine); // Read and ignore the header line

            string tracking_no, address, sender_name, receiver_name, shipping_option, status_delivery;

            while (!inFile.eof()) {
                getline(inFile, tracking_no, ';');
                getline(inFile, address, ';');
                getline(inFile, sender_name, ';');
                getline(inFile, receiver_name, ';');
                getline(inFile, shipping_option, ';');
                getline(inFile, status_delivery);

                if ((shipping_option[0] != 'A') && (shipping_option[0] != 'B')) { //If shipping option is not A or B
                    cout << "Invalid shipping option. Parcel not added.\n";

                }
                else if ((status_delivery[0] != '0' && status_delivery[0] != '1')) { //If status delivery is not 0 or 1
                    cout << "Invalid status delivery. Parcel not added.\n";
                    cout << status_delivery << endl;
                }
                else {
                    Parcel* newParcel = new Parcel(tracking_no, address, sender_name, receiver_name, shipping_option[0], stoi(status_delivery));
                    p1.addNode(newParcel);
                }
            }

            inFile.close();

            while (true) {
                displayMenu();

                cout << "\nEnter your choice: ";
                int choice;
                cin >> choice;

                switch (choice) {
                case 1: {
                    //add node using stack
                    cout << "\nEnter parcel details:\n";
                    string new_tracking_no, new_address, new_sender_name, new_receiver_name;
                    char new_shipping_option;
                    int new_status_delivery;

                    cout << "Tracking Number: ";
                    cin >> new_tracking_no;
                    cout << "Address: ";
                    cin.ignore();
                    getline(cin, new_address);
                    cout << "Sender's Name: ";
                    getline(cin, new_sender_name);
                    cout << "Receiver's Name: ";
                    getline(cin, new_receiver_name);
                    cout << endl;
                    cout << "A: Bulky & Heavy Delivery  B: Standard Delivery" << endl;
                    cout << "Shipping Option (A/B): ";
                    cin >> new_shipping_option;
                    while (new_shipping_option != 'A' && new_shipping_option != 'B') {
                        cout << "Invalid shipping option. Parcel not added.\n";
                        cout << "Re-enter Shipping Option (A/B): ";
                        cin >> new_shipping_option;
                    }

                    cout << "Status Delivery (0 for Complete, 1 for Incomplete): ";
                    cin >> new_status_delivery;
                    while (new_status_delivery != 0 && new_status_delivery != 1) {
                        cout << "Invalid status delivery. Parcel not added.\n";
                        cout << "Re-enter Status Delivery (0 for Incomplete, 1 for Complete): ";
                        cin >> new_status_delivery;
                    }

                    Parcel* newParcel = new Parcel(new_tracking_no, new_address, new_sender_name, new_receiver_name, new_shipping_option, new_status_delivery);
                    p1.addNode(newParcel);
                    p1.displayAllNodes();
                    break;
                }
                case 2: {
                    //delete parcel using stack
                    p1.deleteNode();
                    p1.displayAllNodes();
                    break;
                }
                case 3:
                    //exit program
                    cout << "\nExiting program.\n";
                    return 0;
                default:
                    //invalid option
                    cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";

                }
            }
            break;
        }
        case 2: {
            cout << "QUEUE IMPLEMENTATION..." << endl << endl;
            ParcelList p1;

            ifstream inFile("ParcelData.txt"); // Change the file name as needed

            if (!inFile.is_open()) {
                cerr << "Error opening file." << endl;
                return 1;
            }

            string headerLine;
            getline(inFile, headerLine); // Read and ignore the header line

            string tracking_no, address, sender_name, receiver_name, shipping_option, status_delivery;

            while (!inFile.eof()) {
                getline(inFile, tracking_no, ';');
                getline(inFile, address, ';');
                getline(inFile, sender_name, ';');
                getline(inFile, receiver_name, ';');
                getline(inFile, shipping_option, ';');
                getline(inFile, status_delivery);

                if ((shipping_option[0] != 'A') && (shipping_option[0] != 'B')) { //If shipping option is not A or B
                    cout << "Invalid shipping option. Parcel not added.\n";

                }
                else if ((status_delivery[0] != '0' && status_delivery[0] != '1')) { //If status delivery is not 0 or 1
                    cout << "Invalid status delivery. Parcel not added.\n";
                    cout << status_delivery << endl;
                }
                else {
                    Parcel* newParcel = new Parcel(tracking_no, address, sender_name, receiver_name, shipping_option[0], stoi(status_delivery));
                    p1.enQueue(newParcel);
                }
            }

            inFile.close();


            while (true) {
                displayMenu();

                cout << "\nEnter your choice: ";
                int choice;
                cin >> choice;

                switch (choice) {

                case 1: {
                    // add node using queue
                    cout << "\nEnter parcel details:\n";
                    string new_tracking_no, new_address, new_sender_name, new_receiver_name;
                    char new_shipping_option;
                    int new_status_delivery;

                    cout << "Tracking Number: ";
                    cin >> new_tracking_no;
                    cout << "Address: ";
                    cin.ignore();
                    getline(cin, new_address);
                    cout << "Sender's Name: ";
                    getline(cin, new_sender_name);
                    cout << "Receiver's Name: ";
                    getline(cin, new_receiver_name);
                    cout << endl;
                    cout << "A: Bulky & Heavy Delivery  B: Standard Delivery" << endl;
                    cout << "Shipping Option (A/B): ";
                    cin >> new_shipping_option;
                    while (new_shipping_option != 'A' && new_shipping_option != 'B') {
                        cout << "Invalid shipping option. Parcel not added.\n";
                        cout << "Re-enter Shipping Option (A/B): ";
                        cin >> new_shipping_option;
                    }

                    cout << "Status Delivery (0 for Complete, 1 for Incomplete): ";
                    cin >> new_status_delivery;
                    while (new_status_delivery != 0 && new_status_delivery != 1) {
                        cout << "Invalid status delivery. Parcel not added.\n";
                        cout << "Re-enter Status Delivery (0 for Incomplete, 1 for Complete): ";
                        cin >> new_status_delivery;
                    }
                    Parcel* newParcel = new Parcel(new_tracking_no, new_address, new_sender_name, new_receiver_name, new_shipping_option, new_status_delivery);
                    p1.enQueue(newParcel); // Use queue for enQueue
                    p1.displayAllNodesQueue();
                    break;
                }

                case 2: {
                    // delete parcel using queue
                    p1.deQueue(); // Use queue for deQueue
                    p1.displayAllNodesQueue();
                    break;
                }
                case 3:
                    cout << "\nExiting program.\n";
                    return 0;
                default:
                    cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";
                }
            }
            break;
        }
        case 3:
            cout << "\nExiting program.\n";
            return 0;
        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}
