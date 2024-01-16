#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Courier {
    string name, parcelType, source, destination, status;
    int trackingNum;

	public:
	    Courier *next;
	    Courier()
	    : name(" "), parcelType(" "), source(" "), destination(" "), status(" "), trackingNum(0), next(NULL) {}

       	    Courier(string name, string parcelType, string source, string destination, string status, int trackingNum)
            : name(name), parcelType(parcelType), source(source), destination(destination), status(status), trackingNum(trackingNum), next(NULL) {}
	
	    string getName() const { return name; }
	    string getType() const { return parcelType; }
	    string getSource() const { return source; }
	    string getDest() const { return destination; }
	    string getStat() const { return status; }
	    int getTrackNum() const { return trackingNum; }
	    
	    Courier* getNext() const { return next; }
   	    void setNext(Courier* node) { next = node; }
	    void setStatus(string s) {status = s;}

    	    void displayHeader() const {
            cout << left << setw(5) << "No." << setw(20) << "Tracking Number" << setw(20) << "Name"
                 << setw(20) << "Parcel Type" << setw(25) << "Source"
                 << setw(25) << "Destination" << setw(20) << "Status" << endl;
            cout << setfill('-') << setw(135) << " " << setfill(' ') << endl;
          }

           void display(int index) {
           cout << "[" << setw(1) << index << "]"
                << setw(20)  << trackingNum << setw(20) << name
                << setw(20) << parcelType << setw(25) << source
                << setw(25) << destination << setw(20) << status << endl;
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

    void enqueue(const Courier& newCourier) {
        Courier* node = new Courier(
            newCourier.getName(),
            newCourier.getParcelType(),
            newCourier.getSource(),
            newCourier.getDestination(),
            newCourier.getStatus(),
            newCourier.getTrackingNum()
	);

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

        delete delNode;
    }

    Courier* getFront() const {
	    return front;
    }

    Courier* getRear() const {
	    return rear;
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
		cout << endl;
            }
        }
    }

     Courier* searchByTrackingNum(int trackingNum) const {
	     Courier* currNode = front;

	     while (currNode) {
		     if (currNode->getTrackingNum() == trackingNum) {
			     return currNode;
		     }
		     currNode = currNode->getNext();
	     }
	     return NULL;
     }

      void updateFromFile(const string& filename) {
	      ifstream inputFile(filename);

	      if (!inputFile.is_open()) {
		      cout << "Error opening file: " << filename << endl;
		      return;
	      }

	      while (!isEmpty()) {
		      dequeue();
	      }

	      string line;
	      while (getline(inputFile, line)) {
		      stringstream ss(line);
		      string name, parcelType, source, destination, status;
		      int trackingNum;
		      
		      if (getline(ss >> std::ws, name, ',') &&
		          getline(ss >> std::ws, parcelType, ',') &&
		          getline(ss >> std::ws, source, ',') &&
		          getline(ss >> std::ws, destination, ',') &&
		          getline(ss >> std::ws, status, ',') &&
		                 (ss >> trackingNum)) {
	
	            	  Courier newCourier(name, parcelType, source, destination, status, trackingNum);
	            	  enqueue(newCourier);
	        	}
	      }
       	      inputFile.close();
      }

      void saveToFile(const string& filename) const {
	      ofstream file(filename);

	      if (!file.is_open()) {
		      cout << "Error opening file: " << filename << endl;
		      return;
	      }

	      Courier* currNode = front;

	      while (currNode) {
		file << currNode->getName() << ","
	             << currNode->getParcelType() << ","
	             << currNode->getSource() << ","
	             << currNode->getDestination() << ","
	             << currNode->getStatus() << ","
	             << currNode->getTrackingNum() << endl;
	
	        currNode = currNode->getNext();
	       } 
	      file.close();
      }
};



int main() {

   ifstream inputFile("COURIER.TXT");
    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

   Queue courierQueue;
	
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

