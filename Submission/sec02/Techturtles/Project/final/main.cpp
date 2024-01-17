#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
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
    Parcel* next;

    Parcel(string tn, string a, string nSend, string nRec, char c, int s)
        : trackingNumber(tn), address(a), nameSender(nSend), nameReceiver(nRec), category(c), status(s), next(NULL) {}

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


class ParcelQueue {

private:
    Parcel* front, * back;

public:
    ParcelQueue() {//constructor: intilizer...

        front = NULL;
        back = NULL;
    }

    ~ParcelQueue() {//delete parcel memory 

        Parcel* currNode = front, * delNode;
        while (currNode) {
            delNode = currNode;
            currNode = currNode->next;
            delete delNode;
        }
    }

    bool isEmpty() { return (front == NULL); }

    void enqueue(Parcel* newParcel) {//insert new parcel from back

        if (isEmpty()) {//point front and back to newParcel
            front = newParcel;
            back = newParcel;
            newParcel->next = NULL;
        }
        else {
            back->next = newParcel;
            back = newParcel;
            newParcel->next = NULL;
        }
    }

    void dequeue() {//delete from front queue

        if (isEmpty()) return;//cannot delete 

        Parcel* delNode = front;
        if (front == back) {//only has one parcel, set queue to empty 
            front = NULL;
            back = NULL;
            delete delNode;
        }
        else {
            front = front->next;//have more than one parcel
            delete delNode;
        }
    }

    void displayAllNode() {//display all parcel with its details

        if (isEmpty()) return;

        Parcel* currNode = front;
        int count = 1;
        while (currNode) {
            currNode->displayDetails(count++);
            currNode = currNode->next;
        }
    }
};

class ParcelStack {

private:
    Parcel* top;

public:
    ParcelStack() {//initilize stack
        top = NULL;
    }

    ~ParcelStack() {//delete all remaining parcel in stack at end of program

        Parcel* currNode = top, * delNode;
        while (currNode) {

            delNode = currNode;
            currNode = currNode->next;
            delete delNode;
        }
    }

    bool isEmpty() { return (top == NULL); }

    void push(Parcel* newParcel) {//insert new parcel at the top of stack

        if (isEmpty()) {//if stack is empty
            top = newParcel;
            newParcel->next = NULL;
        }
        else {//if stack is not empty
            newParcel->next = top;
            top = newParcel;
        }
    }

    void pop() {//delete parcel from top 

        if (isEmpty()) return;//if stack is empty

        Parcel* delNode = top;
        top = top->next;
        delete delNode;
    }

    void displayAllNode() {//display all parcel in stack

        if (isEmpty()) return;

        Parcel* currNode = top;
        int count = 1;
        while (currNode) {
            currNode->displayDetails(count++);
            currNode = currNode->next;
        }
    }
};
//Queue stack linked list

void displayMenu() {
    cout << "\t+----------------------------------+\n";
    cout << "\t|   Courier Service System Menu    |\n";
    cout << "\t+----------------------------------+\n";
    cout << "\t| 1. Add a new parcel              |\n";
    cout << "\t| 2. Delete a parcel               |\n";
    cout << "\t| 3. Display all parcels           |\n";
    cout << "\t| 4. Exit                          |\n";
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

void stackMenu() {

    cout << "\t+------------------------------------------+\n";
    cout << "\t|           Stack Implementation           |\n";
    cout << "\t+------------------------------------------+\n";
    cout << endl;

    ParcelStack p1;

    ifstream inFile("ParcelData.txt"); // Change the file name as needed

    if (!inFile.is_open()) {
        cerr << "Error opening file." << endl;
        exit(1);
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
        else {//allocate new memory for parcel and push int stack
            Parcel* newParcel = new Parcel(tracking_no, address, sender_name, receiver_name, shipping_option[0], stoi(status_delivery));
            p1.push(newParcel);
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
            p1.push(newParcel);
            p1.displayAllNode();
            break;
        }
        case 2: {
            //delete parcel using stack
            p1.pop();
            p1.displayAllNode();
            break;
        }
        case 3://display parcel
            p1.displayAllNode();
            break;

        case 4: {
            //exit program
            cout << "\nExiting program.\n";
            exit(0);
        }
        default:
            //invalid option
            cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";

        }
    }
}

void queueMenu() {
    cout << "\t+------------------------------------------+\n";
    cout << "\t|           Queue Implementation           |\n";
    cout << "\t+------------------------------------------+\n";
    cout << endl;
    ParcelQueue p1;

    ifstream inFile("ParcelData.txt"); // Change the file name as needed

    if (!inFile.is_open()) {
        cerr << "Error opening file." << endl;
        exit(1);
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
            p1.enqueue(newParcel);//insert at back of queue
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
            p1.enqueue(newParcel); // Use queue for enQueue to insert new parcel 
            p1.displayAllNode();
            break;
        }

        case 2: {
            // delete parcel using queue
            p1.dequeue(); // Use queue for deQueue
            p1.displayAllNode();
            break;
        }
        case 3: {
            // delete parcel using queue
            p1.displayAllNode();
            break;
        }
        case 4:
            cout << "\nExiting program.\n";
            exit(0);
        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";
        }
    }

}

int main() {

    while (true) {

        displayOption();

        cout << "\nEnter your choice: ";
        int option;
        cin >> option;

        switch (option) {
        case 1: {
            stackMenu();
            break;
        }

        case 2: {
            queueMenu();
            break;
        }

        case 3: {
            cout << "\nExiting program.\n";
            return 0;
        }

        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";
            break;

        }
    }
    return 0;
}

