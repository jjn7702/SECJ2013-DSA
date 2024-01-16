#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

class Courier {
    string name, parcelType, source, destination, status;
    int trackingNum;
    Courier *next;

	public:
	    Courier()
	    : name(" "), parcelType(" "), source(" "), destination(" "), status(" "), trackingNum(0), next(NULL) {}

       	    Courier(string name, string parcelType, string source, string destination, string status, int trackingNum)
            : name(name), parcelType(parcelType), source(source), destination(destination), status(status), trackingNum(trackingNum), next(NULL) {}
	
	    void setName(string n) { name = n; }
	    void setType(string p) { parcelType = p; }
	    void setSource(string s) { source = s; }
	    void setDest(string d) { destination = d; }
	    void setStat(string st) { status = st; }
	    void setTrackNum(int t) { trackingNum = t; }
	
	    string getName() const { return name; }
	    string getType() const { return parcelType; }
	    string getSource() const { return source; }
	    string getDest() const { return destination; }
	    string getStat() const { return status; }
	    int getTrackNum() const { return trackingNum; }
	    
	    Courier* getNext() const { return next; }
   	    void setNext(Courier* node) { next = node; }

    	    void displayHeader()  {
            cout << left << setw(1) << "No." << setw(20) << "Tracking Number" << setw(20) << "Name"
                 << setw(20) << "Parcel Type" << setw(20) << "Source"
                 << setw(20) << "Destination" << setw(20) << "Status" << endl;
            cout << setfill('-') << setw(120) << " " << setfill(' ') << endl;
          }

           void display(int index) {
           cout << "[" << setw(2) << index << "]"
                << setw(6)  << trackingNum << setw(20) << name
                << setw(20) << parcelType << setw(20) << source
                << setw(20) << destination << setw(20) << status << endl;
    	  }
};

class Queue {
private:
    Courier* front;
    Courier* rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    bool isEmpty() const {
        return front == NULL;
    }

    Courier* getFront() const {
        return front;
    }

    void enqueue() {
        string newName, newParcelType, newSource, newDestination, newStatus;
        int newTrackingNum;

        cout << "<<<<<<< Enqueue Courier >>>>>>>" << endl << endl;
        cout << "Name : ";
        getline(cin, newName);

        cout << "Parcel Type : ";
        getline(cin, newParcelType);

        cout << "Source : ";
        getline(cin, newSource);

        cout << "Destination : ";
        getline(cin, newDestination);

        cout << "Status : ";
        getline(cin, newStatus);

        cout << "Tracking Number : ";
        cin >> newTrackingNum;

        Courier* node = new Courier(newName, newParcelType, newSource, newDestination, newStatus, newTrackingNum);

        if (isEmpty()) {
            front = rear = node;
        } else {
            rear->setNext(node);
            rear = node;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Sorry, cannot dequeue item from queue. The queue is empty!!" << endl;
            return;
        }

        Courier* delNode = front;
        front = delNode->getNext();

        cout << "<<<<<<< Dequeue Courier >>>>>>>" << endl << endl
             << "Name            : " << delNode->getName() << endl
             << "Parcel Type     : " << delNode->getParcelType() << endl
             << "Status          : " << delNode->getStatus() << endl
             << "Destination     : " << delNode->getDestination() << endl
             << "Tracking Number : " << delNode->getTrackingNum() << endl << endl;

        delete delNode;
        cout << "<< Press any key to continue >>";
        cin.get();
    }

    void display() {
        int counter = 1;
        Courier* currNode;

        if (isEmpty()) {
            cout << "Sorry, there are no couriers in the system." << endl;
        } else {
            currNode = front;
            currNode->displayHeader();

            while (currNode) {
                currNode->display(counter);
                currNode = currNode->getNext();
                counter++;
            }
        }

        cout << "<< Press any key to continue >>";
        cin.get();
    }

     void search() {
        string input;

        Courier* currNode;
        bool found = false;

        cout << "<<<<<<< Search Courier(s) >>>>>>>" << endl;
        cout << "Enter Status : ";
        getline(cin, input);

        currNode = front;
        currNode->displayHeader();
        while (currNode) {
            if (currNode->getStatus() == input) {
                currNode->display(1);
                found = true;
            }
            currNode = currNode->getNext();
        }

        if (!found) {
            cout << "Status not found in the queue." << endl;
        }

        cout << "<< Finish searching... Press any key to continue >>";
        cin.get();
    }

	void insertBack(Courier& newCourier) {
        Courier* node = new Courier(newCourier.getName(), newCourier.getParcelType(), newCourier.getSource(),
                                    newCourier.getDestination(), newCourier.getStatus(), newCourier.getTrackingNum());

        if (isEmpty()) {
            front = rear = node;
        } else {
            rear->setNext(node);
            rear = node;
        }
    }

    ~Queue() {
        Courier* currNode = front;
        Courier* nextNode;

        while (currNode != NULL) {
            nextNode = currNode->getNext();
            delete currNode;
            currNode = nextNode;
        }
    }
       
};

// To display main menu
void dispMenu() {
    system("CLS");
    cout << "COURIER MANAGEMENT SYSTEM" << endl
         << "\n\t1. Enqueue Courier (Queue)"
         << "\n\t2. Dequeue Courier (Queue)"
         << "\n\t3. Search Courier  (Queue)"
         << "\n\t4. Display Courier (Queue)"
         << "\n\t5. Exit" << endl;
}


int main() {
    
   string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string n, parcel, sourc, dest, stat;
        int track;

        if (getline(ss >> std::ws, n, ',') &&
            getline(ss >> std::ws, parcel, ',') &&
            getline(ss >> std::ws, sourc, ',') &&
            getline(ss >> std::ws, dest, ',') &&
            getline(ss >> std::ws, stat, ',') &&
            (ss >> track)) {

            Courier newCourier(n, parcel, sourc, dest, stat, track);
            courierQueue.insertBack(newCourier);
        }
    }

    inputFile.close();

    int choice;

    do {
        dispMenu();
        cout << "\nEnter your choice [1-5]: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                courierQueue.enqueue();
                break;
            case 2:
                courierQueue.dequeue();
                break;
            case 3:
                courierQueue.search();
                break;
            case 4:
                courierQueue.display();
                break;
            case 5:
                cout << "\nThank you.. see you again.." << endl;

                // Save the courier list back to the file
                ofstream outputFile("COURIER.TXT");
                Courier* currNode = courierQueue.getFront();
                while (currNode != NULL) {
                    outputFile << currNode->getName() << "," << currNode->getParcelType() << ","
                                << currNode->getSource() << "," << currNode->getDestination() << ","
                                << currNode->getStatus() << "," << currNode->getTrackingNum() << endl;

                    currNode = currNode->getNext();
                }

                outputFile.close();
        }

    } while (choice > 0 && choice < 5);

    return 0;
}
    return 0;
}
