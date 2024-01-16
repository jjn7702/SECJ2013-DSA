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
            newCourier.getType(),
            newCourier.getSource(),
            newCourier.getDest(),
            newCourier.getStat(),
            newCourier.getTrackNum()
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
		     if (currNode->getTrackNum() == trackingNum) {
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
	             << currNode->getType() << ","
	             << currNode->getSource() << ","
	             << currNode->getDest() << ","
	             << currNode->getStat() << ","
	             << currNode->getTrackNum() << endl;
	
	        currNode = currNode->getNext();
	       } 
	      file.close();
      }
};

class Customer {
private:
	Queue &courierQueue;
public:
	Customer(Queue &queue) : courierQueue(queue) {}
	void customerMenu() {
		int choice;

		system("CLS");
		do{
			cout << "===== Customer Menu =====" << endl;
		        cout << "1. Add Courier" << endl;
		        cout << "2. View Courier Queue" << endl;
		        cout << "3. Search Courier by Tracking Number" << endl;
		        cout << "4. Exit" << endl;
		        cout << "Enter your choice: ";
		        cin >> choice;

		switch (choice) {
                case 1: {
                    string name, parcelType, source, destination, status;
                    int trackingNum;

                    cout << "\nEnter Courier details:" << endl;
                    cout << "Name: ";
                    cin.ignore(); // Clear buffer
                    getline(cin, name);
                    cout << "Parcel Type: ";
                    getline(cin, parcelType);
                    cout << "Source: ";
                    getline(cin, source);
                    cout << "Destination: ";
                    getline(cin, destination);
                    status = "Pending"; // Set status to "pending" initially
                    cout << "Tracking Number: ";
                    cin >> trackingNum;

					cout << "\nCourier added successfully with status 'pending'." << endl;
					cout << endl;
                    Courier newCourier(name, parcelType, source, destination, status, trackingNum);
                    courierQueue.enqueue(newCourier);

                    break;
                }

		case 2: {
                    // View Courier Queue
                    cout << endl;
                    courierQueue.display();
                    break;
                }
                case 3: {
                    // Search Courier by Tracking Number
                    int trackingNum;
                    cout << "\nEnter Tracking Number to search: ";
                    cin >> trackingNum;

                    Courier* foundCourier = courierQueue.searchByTrackingNum(trackingNum);

                    if (foundCourier) {
                        cout << "\nCourier found:" << endl;
                        cout << endl;
                        foundCourier->displayHeader();
                        foundCourier->display(1);
                        cout << endl;
                    } else {
                        cout << "\nCourier with Tracking Number " << trackingNum << " not found." << endl;
                        cout << endl;
                    }
                    break;
                }
                case 4:
                    cout << "\nExiting customer menu. Have a nice day!" << endl;
                    cout << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    }
};

class Admin {
private:
    Queue &courierQueue;

public:
    Admin(Queue &queue) : courierQueue(queue) {}
    void adminMenu() {
        int choice;

        system("CLS");
        do {
            cout << "===== Admin Menu =====" << endl;
            cout << "1. View Courier Queue" << endl;
            cout << "2. Approve Courier" << endl;
            cout << "3. Dequeue Courier" << endl;  // Added option to dequeue
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    // View Courier Queue
                    int counter = 1;
                    Courier* currentCourier = courierQueue.getFront();

                    if (!currentCourier) {
                        cout << "\nQueue is empty." << endl;
                        cout << endl;
                    } else {
                        currentCourier->displayHeader();

                        while (currentCourier) {
                            currentCourier->display(counter);
                            currentCourier = currentCourier->getNext();
                            counter++;
                        }
                        cout << endl;
                    }
                    break;
                }
                case 2: {
                    // Approve Courier
                    bool foundPendingCourier = false;
                    Courier* currentCourier = courierQueue.getFront();

                    while (currentCourier) {
                        if (currentCourier->getStat() == "Pending") {
                            foundPendingCourier = true;
                            currentCourier->setStatus("Approved");
                            cout << "\nCourier with Tracking Number " << currentCourier->getTrackNum() << " approved." << endl;
                        }

                        currentCourier = currentCourier->getNext(); // Move to the next courier
                    }

                    if (!foundPendingCourier) {
                        cout << "\nNo more pending couriers to approve." << endl;
                    }

                    cout << endl;
                    break;
                }
                case 3: {
                    // Dequeue Courier
                    if (!courierQueue.isEmpty()) {
                        cout << "\nDequeued a courier." << endl;
                        courierQueue.dequeue();
                    } else {
                        cout << "\nQueue is empty. No courier to dequeue." << endl;
                    }
                    cout << endl;
                    break;
                }
                case 4:
                    cout << "\nExiting admin menu. Have a nice day!" << endl;
                    cout << endl;
                    break;
                default:
                    cout << "\nInvalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    }

};

class Worker {
private:
    Queue &courierQueue;

public:
    Worker(Queue &queue) : courierQueue(queue) {}

    void workerMenu() {
        int choice;

        system("CLS");
        do {
            cout << "===== Worker Menu =====" << endl;
            cout << "1. View Courier Queue" << endl;
            cout << "2. Mark Courier as In transit" << endl;
            cout << "3. Dequeue Courier" << endl;  // Added option to dequeue
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    // View Courier Queue
                    int counter = 1;
                    Courier* currentCourier = courierQueue.getFront();

                    if (!currentCourier) {
                        cout << "Queue is empty." << endl;
                    } else {
                        currentCourier->displayHeader();

                        while (currentCourier) {
                            currentCourier->display(counter);
                            currentCourier = currentCourier->getNext();
                            counter++;
                        }
                        cout << endl;
                    }
                    break;
                }
                case 2: {
                    // Mark Courier as Delivered
                    Courier* currentCourier = courierQueue.getFront();

                    while (currentCourier) {
                        if (currentCourier->getStat() == "Approved") {
                            currentCourier->setStatus("In transit");
                            cout << "\nCourier with Tracking Number " << currentCourier->getTrackNum() << " marked as in transit." << endl;
                        }

                        currentCourier = currentCourier->getNext();
                    }

                    cout << endl;
                    break;
                }
                case 3: {
                    // Dequeue Courier
                    if (!courierQueue.isEmpty()) {
                        cout << "\nDequeued a courier." << endl;
                        courierQueue.dequeue();
                    } else {
                        cout << "\nQueue is empty. No courier to dequeue." << endl;
                    }
                    cout << endl;
                    break;
                }
                case 4:
                    cout << "\nExiting worker menu. Have a nice day!" << endl;
                    cout << endl;
                    break;
                default:
                    cout << "\nInvalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    }
};



int main() {
	Queue courierQueue;
	courierQueue.updateFromFile("COURIER.txt");
	Customer customer(courierQueue);
	Admin admin(courierQueue);
	Worker worker(courierQueue);

	int choice;
	system("CLS");
	do{
		cout << "===== Main Menu =====" << endl;
	        cout << "1. Customer Menu" << endl;
	        cout << "2. Admin Menu" << endl;
	        cout << "3. Worker Menu" << endl;
	        cout << "4. Save Courier Data to File" << endl;
	        cout << "5. Exit" << endl;
	        cout << "Enter your choice: ";
	        cin >> choice;

		switch (choice) {
	            case 1:
	                customer.customerMenu();
	                break;
	            case 2:
	                admin.adminMenu();
	                break;
	            case 3:
	                worker.workerMenu();
	                break;
	            case 4: {
	                // Save courier data to a file
	                string filename = "COURIER.TXT";
	                courierQueue.saveToFile(filename);
	                cout << "\nCourier data saved to file (COURIER.TXT)." << endl;
	                cout << endl;
	                break;
	            }
	            case 5:
	                cout << "\nExiting main menu. Goodbye!" << endl;
	                break;
	            default:
	                cout << "\nInvalid choice. Please try again." << endl;
	        }
	    } while (choice != 5);
    return 0;
}

