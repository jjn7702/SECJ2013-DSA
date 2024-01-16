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




int main() {
    
    ifstream inputFile("COURIER.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    LinkedList courierList;
    Queue courierQueue;
    Stack courierStack;
    
	
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
            courierList.insertBack(newCourier);
        }
    }

inputFile.close();
 int choice;
    do {
        cout << "Menu:\n[1] Add a new courier\n[2] Delete a courier\n[3] Find a courier\n"
             << "[4] Sort the list(ascending)\n[5] Display all couriers\n"
             << "[6] Enqueue to Courier Queue\n[7] Dequeue from Courier Queue\n"
             << "[8] Display Courier Queue\n[9] Push to Courier Stack\n"
             << "[10] Pop from Courier Stack\n[11] Display Courier Stack\n[0] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int insertChoice;
                do {
                    cout << "\nAdd Courier Menu:\n[1] Insert at the beginning\n[2] Insert at the middle\n"
                         << "[3] Insert at the end\n[0] Back to Main Menu\nEnter your choice: ";
                    cin >> insertChoice;

                    switch (insertChoice) {
                          case 1: {
	                        Courier newCourier = courierList.getNewCourier();
	                        courierList.insertFront(newCourier);
	                        break;
	                    }
	                    case 2: {
	                        int position;
	                        cout << "Enter the position to insert: ";
	                        cin >> position;
	                        Courier newCourier = courierList.getNewCourier();
	                        courierList.insertMiddle(newCourier, position);
	                        break;
	                    }
	                    case 3: {
	                        Courier newCourier = courierList.getNewCourier();
	                        courierList.insertBack(newCourier);
	                        cout << "Courier added at the back.\n" << endl;
	                        break;
	                    }
	                    case 0: {
	                        cout << "Returning to Main Menu.\n" << endl;
	                        break;
	                    }
	                    default: {
	                        cout << "\nInvalid choice. Please try again.";
	                        cout << endl;
	                        break;
	                    }
	                }
                    
                } while (insertChoice != 0 && insertChoice != 1 && insertChoice != 2 && insertChoice != 3);
                break;
            }
            case 2: {
                int deleteChoice;
                do {
                    cout << "\nDelete Courier Menu:\n[1] Delete at the beginning\n[2] Delete at the middle\n"
                         << "[3] Delete at the end\n[0] Back to Main Menu\nEnter your choice: ";
                    cin >> deleteChoice;

                    switch (deleteChoice) {
                          case 1:
	                        courierList.deleteFront();
	                        break;
	                    case 2: {
	                        int position;
	                        cout << "Enter the position to delete: ";
	                        cin >> position;
	                        courierList.deleteMiddle(position);
	                        break;
	                    }
	                    case 3:
	                        courierList.deleteBack();
	                        break;                   
	                    case 0:
	                        cout << "Returning to Main Menu.\n" << endl;
	                        break;
	                    default:
	                        cout << "Invalid choice. Please try again.\n";
	                        break;
	                } 
                    
                } while (deleteChoice != 0 && deleteChoice != 1 && deleteChoice != 2 && deleteChoice != 3);
                break;
            }
            case 3: {
                int searchOption;
		cout << "\nSearch by:\n";
		cout << "[1] Name\n[2] Parcel Type\n[3] Source\n[4] Destination\n[5] Status\n[6] Tracking Number\n[0] Back to Main Menu\nEnter you choice: ";
		cin >> searchOption;

		if (searchOption == 0) {
			cout << "Returning to Main Menu.\n" << endl;
			break;
		} else if (searchOption < 1 || searchOption > 6) {
			cout << "Invalid option. Please try again." << endl;
			break;
		}
			
                string searchKey;
                Courier searchCourier;

                    cout << "Enter the search key: ";
                    cin.ignore();
                    getline(cin, searchKey);

                    switch (searchOption) {
                        case 1:
                            if (!searchKey.empty()) {
                                searchCourier.setName(searchKey);
                            }
                            break;
                        case 2:
                            if (!searchKey.empty()) {
                                searchCourier.setType(searchKey);
                            }
                            break;
                        case 3:
                            if (!searchKey.empty()) {
                                searchCourier.setSource(searchKey);
                            }
                            break;
                        case 4:
                            if (!searchKey.empty()) {
                                searchCourier.setDest(searchKey);
                            }
                            break;
                        case 5:
                            if (!searchKey.empty()) {
                                searchCourier.setStat(searchKey);
                            }
                            break;
                        case 6:
                            if (!searchKey.empty()) {
				try {
                                	searchCourier.setTrackNum(stoi(searchKey));
                            }
				catch (const invalid_argument& e) {
					cout << "Invalid tracking number. Please enter a valid number. \n";
					break;
				}
			    }
                            break;
                        default:
                            break;
                    }

		cout << "\nSearching...\n";
		courierList.findNode(searchCourier);
		break;
           	}
	case 4: {
                 int sortCriteria;
	            bool sorting;
	            do {
	                cout << "\n[1] Sort by name\n[2] Sort by parcel type\n[3] Sort by tracking number\n[0] Back to Main Menu\nEnter your choice: ";
	                cin >> sortCriteria;
	
	                if (sortCriteria == 0) {
	                    cout << "Returning to Main Menu.\n" << endl;
	                    break;
	                } else if (sortCriteria < 1 || sortCriteria > 3) {
	                    cout << "Invalid option. Please try again.\n";
	                    sorting = false;
	                    continue;
	                }
	                courierList.sortList(sortCriteria);
	                cout << endl;
	                sorting = true;
	            } while (!sorting);
	            break;
	        }
            
        case 5: {
                courierList.displayList();
                cout << endl;
                break;
            }
	case 6: {
                Courier newCourier = courierList.getNewCourier();
                courierQueue.enqueue(newCourier);
                cout << "Courier enqueued to the queue.\n" << endl;
                break;
            }
        case 7: {
                courierQueue.dequeue();
                break;
        	}
        case 8: {
                courierQueue.displayQueue();
                break;
        	}
	case 9: {
                Courier newCourier = courierList.getNewCourier();
                courierStack.push(newCourier);
                cout << "Courier pushed to the stack.\n" << endl;
                break;
            }
        case 10: {
                courierStack.pop();
                break; 
        	}
	case 11: {
                courierStack.displayStack();
                break;
        	}
         case 0: {
                cout << "Exiting program.\n";
                break;
        	}
         default:
                cout << "Invalid choice. Please try again.\n" << endl;
                break;
  }
    } while (choice != 0);

    return 0;
}
