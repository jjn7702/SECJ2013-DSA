// Assignment 2 - SECJ2013 - 23241 (Assignment 2.cpp)
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
#define COMPLETE 0
#define INCOMPLETE 1
#define bulkyheavydelivery 'A'
#define standarddelivery 'B'

using namespace std;

class Parcel {
private:
    string trackingNumber, address, nameSender, nameReceiver;
    char category; // shipping option: 'A' for Bulky & Heavy Delivery, 'B' for Standard Delivery
    int status;    // delivery status: '0' for Complete, '1' for Incomplete

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

class Node {
public:
    Parcel* data;
    Node* next;

    Node(Parcel* p) : data(p), next(nullptr) {}
};

class ParcelList {
private:
    Node* head;
    int count;

public:
    ParcelList() : head(nullptr), count(0) {}

    ~ParcelList() {
        Node* current = head;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current->data;
            delete current;
            current = next;
        }
    }

    int getNodeCount()
    {
        return count;
    }

    void addNodeAtBeginning(Parcel* parcel) {
        Node* newNode = new Node(parcel);
        newNode->next = head;
        head = newNode;
        count++;
    }

    void addNodeAtEnd(Parcel* parcel) {
        Node* newNode = new Node(parcel);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            count++;
        }
    }

    void addNodeAtPosition(Parcel* parcel, int position) {
        if (position <= 0) {
            addNodeAtBeginning(parcel);
        }
        else {
            Node* newNode = new Node(parcel);
            Node* current = head;
            int count = 1;

            while (current != nullptr && count < position) {
                current = current->next;
                count++;
            }

            if (current != nullptr) {
                newNode->next = current->next;
                current->next = newNode;
                count++;
            }
            else {
                cout << "Invalid position. Node not added." << endl;
                delete newNode;
            }
        }
    }

    Node* getNodeAtPosition(int position) const {
        if (position < 0 || position >= count) {
            return nullptr; // Invalid position
        }

        Node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }

        return current;
    }

    void deleteNodeAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;

        count--;
        cout << "Node deleted from the beginning.\n";
    }

    void deleteNodeAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        if (head->next == nullptr) {
            delete head->data;
            delete head;
            head = nullptr;
        }
        else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }

            delete current->next->data;
            delete current->next;
            current->next = nullptr;
        }

        count--;
        cout << "Node deleted from the end.\n";
    }

    void deleteNodeAtPosition(int position) {
        if (position < 0 || position >= count) {
            cout << "Invalid position. Nothing to delete.\n";
            return;
        }

        if (position == 0) {
            deleteNodeAtBeginning();
        }
        else if (position == count) {
            deleteNodeAtEnd();
        }
        else {
            Node* current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current->next;
            }

            Node* temp = current->next;
            current->next = temp->next;
            delete temp->data;
            delete temp;

            count--;
            cout << "Node deleted at position " << position << ".\n";
        }
    }

    Node* findNode(const string& trackingNumber) const {
        Node* current = head;

        while (current != nullptr) {
            if (current->data->getTrackingNumber() == trackingNumber) {
                return current;
            }
            current = current->next;
        }

        return nullptr;
    }

    void sortList() {
        if (head == nullptr || head->next == nullptr) {
            return; // Already sorted
        }

        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->data->getTrackingNumber() > ptr1->next->data->getTrackingNumber()) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void displayAllNodes() const {
        Node* current = head;
        int count = 1;

        cout << "\t";
        for (int i = 0; i < 120; i++)
        {
            cout << "-";
        }
        cout << "\n\t" << left << setw(5) << "No."
            << setw(15) << "Tracking No."
            << setw(30) << "Address"
            << setw(15) << "Sender"
            << setw(15) << "Receiver"
            << setw(30) << "Category"
            << setw(10) << "Status" << endl;

        cout << "\t";
        for (int i = 0; i < 120; i++)
        {
            cout << "-";
        }
        cout << endl;
        while (current != nullptr) {
            current->data->displayDetails(count);
            current = current->next;
            count++;
        }
    }
};

void swapParcels(Node* a, Node* b) {
    swap(a->data, b->data);
}

void bubbleSort(ParcelList& list, bool ascending) {
    int n = list.getNodeCount();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            string firstTracking = list.getNodeAtPosition(j)->data->getTrackingNumber();
            string secondTracking = list.getNodeAtPosition(j + 1)->data->getTrackingNumber();

            bool needSwap = (ascending) ? (firstTracking > secondTracking) : (firstTracking < secondTracking);

            if (needSwap) {
                swapParcels(list.getNodeAtPosition(j), list.getNodeAtPosition(j + 1));
            }
        }
    }
}

void selectionSort(ParcelList& list, bool ascending) {
    int n = list.getNodeCount();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            string firstAddress = list.getNodeAtPosition(j)->data->getAddress();
            string secondAddress = list.getNodeAtPosition(minIndex)->data->getAddress();

            bool needSwap = (ascending) ? (firstAddress < secondAddress) : (firstAddress > secondAddress);

            if (needSwap) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swapParcels(list.getNodeAtPosition(i), list.getNodeAtPosition(minIndex));
        }
    }
}

void insertionSort(ParcelList& list, bool ascending) {
    int n = list.getNodeCount();

    for (int i = 1; i < n; i++) {
        string key = (ascending) ? list.getNodeAtPosition(i)->data->getSender() : list.getNodeAtPosition(i)->data->getReceiver();
        int j = i - 1;

        while (j >= 0 && ((ascending) ? (list.getNodeAtPosition(j)->data->getSender() > key) : (list.getNodeAtPosition(j)->data->getSender() < key))) {
            swapParcels(list.getNodeAtPosition(j), list.getNodeAtPosition(j + 1));
            j--;
        }

    }
}



void displayMenu() {
    cout << right << endl;
    cout << setw(46) << "WELCOME TO TECHTURTLES PARCEL SYSTEM...\n";
    cout << "\t+-------------------------------+\n";
    cout << "\t|  Courier Service System Menu  |\n";
    cout << "\t+-------------------------------+\n";
    cout << "\t| 1. Add a new parcel           |\n";
    cout << "\t| 2. Delete a parcel            |\n";
    cout << "\t| 3. Find a parcel              |\n";
    cout << "\t| 4. Sort the parcel list       |\n";
    cout << "\t| 5. Display all parcels        |\n";
    cout << "\t| 6. Exit                       |\n";
    cout << "\t+-------------------------------+\n";
}

int main() {
    ParcelList p1;

    ifstream inFile("ParcelData2.txt"); // Change the file name as needed

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
            p1.addNodeAtEnd(newParcel);
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
            cout << "\nEnter parcel details:\n";
            string tracking_no, address, sender_name, receiver_name;
            char shipping_option;
            int status_delivery;

            cout << "Tracking Number: ";
            cin >> tracking_no;
            cout << "Address: ";
            cin.ignore();
            getline(cin, address);
            cout << "Sender's Name: ";
            getline(cin, sender_name);
            cout << "Receiver's Name: ";
            getline(cin, receiver_name);
            cout << endl;
            cout << "A: Bulky & Heavy Delivery  B: Standard Delivery" << endl;
            cout << "Shipping Option (A/B): ";
            cin >> shipping_option;
            while (shipping_option != 'A' && shipping_option != 'B')
            {
                cout << "Invalid shipping option. Parcel not added.\n";
                cout << "Re-enter Shipping Option (A/B): ";
                cin >> shipping_option;
            }

            cout << "Status Delivery (0 for Complete, 1 for Incomplete): ";
            cin >> status_delivery;
            while (status_delivery != 0 && status_delivery != 1)
            {
                cout << "Invalid status delivery. Parcel not added.\n";
                cout << "Re-enter Status Delivery (0 for Incomplete, 1 for Complete): ";
                cin >> status_delivery;
            }

            Parcel* newParcel = new Parcel(tracking_no, address, sender_name, receiver_name, shipping_option, status_delivery);
            int addChoice;
            cout << "\n1. Add at the beginning\n2. Add at the end\n3. Add at a specific position\nEnter your choice: ";
            cin >> addChoice;

            switch (addChoice) {
            case 1:
                p1.addNodeAtBeginning(newParcel);
                p1.displayAllNodes();
                break;
            case 2:
                p1.addNodeAtEnd(newParcel);
                p1.displayAllNodes();
                break;
            case 3: {
                int position;
                cout << "Enter position to add the parcel: ";
                cin >> position;
                p1.addNodeAtPosition(newParcel, position);
                p1.displayAllNodes();
                break;
            }
            default:
                cout << "Invalid choice. Parcel not added.\n";
                delete newParcel;
                break;
            }
            break;
        }
        case 2: {
            if (p1.getNodeCount() == 0) {
                cout << "\nList is empty. Nothing to delete.\n";
            }
            else {
                int deleteChoice;
                cout << "\n1. Delete at the beginning\n2. Delete at the end\n3. Delete at a specific position\nEnter your choice: ";
                cin >> deleteChoice;

                switch (deleteChoice) {
                case 1:
                    p1.deleteNodeAtBeginning();
                    p1.displayAllNodes();
                    break;
                case 2:
                    p1.deleteNodeAtEnd();
                    p1.displayAllNodes();
                    break;
                case 3: {
                    int position;
                    cout << "Enter position to delete the parcel: ";
                    cin >> position;
                    p1.deleteNodeAtPosition(position);
                    p1.displayAllNodes();
                    break;
                }
                default:
                    cout << "Invalid choice. Parcel not deleted.\n";
                    break;
                }
            }
            break;
        }
        case 3: {
            if (p1.getNodeCount() == 0) {
                cout << "\nList is empty. Nothing to find.\n";
            }
            else {
                string searchKey;
                cout << "\nEnter tracking number to find the parcel: ";
                cin >> searchKey;
                Node* foundNode = p1.findNode(searchKey);

                if (foundNode != nullptr) {
                    cout << "\nParcel found:\n";
                    cout << "\t";
                    for (int i = 0; i < 100; i++)
                    {
                        cout << "-";
                    }
                    cout << endl;
                    foundNode->data->displayDetails(1);
                }
                else {
                    cout << "\nParcel not found.\n";
                }
            }
            break;
        }
        case 4: {
            int sortChoice;
            cout << "\nSorting Options:\n1. Bubble Sort by Tracking Number\n2. Selection Sort by Address\n3. Insertion Sort by Sender Name\nEnter your choice: ";
            cin >> sortChoice;

            bool ascending;
            cout << "Sort in what order? (1 for Ascending, 0 for Descending): ";
            cin >> ascending;

            switch (sortChoice) {
            case 1:
                bubbleSort(p1, ascending);
                cout << "\nList sorted by tracking number.\n";
                p1.displayAllNodes();
                break;
            case 2:
                selectionSort(p1, ascending);
                cout << "\nList sorted by address.\n";
                p1.displayAllNodes();
                break;
            case 3:
                insertionSort(p1, ascending);
                cout << "\nList sorted by sender name.\n";
                p1.displayAllNodes();
                break;
            default:
                cout << "Invalid sorting option.\n";
                break;
            }
            break;
        }
        case 5:
            p1.displayAllNodes();
            break;
        case 6:
            cout << "\nExiting program.\n";
            return 0;
        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}
