#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;

class Courier {
    string name, parcelType, source, destination, status;
    int trackingNum;

	public:
	    Courier(string n = " ", string p = " ", string s = " ", string d = " ", string st = " ", int t = 0)
	        : name(n), parcelType(p), source(s), destination(d), status(st), trackingNum(t) {}
	
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
	    
	    void display(bool printHeader = true) const {
		    if (printHeader) {
			    cout << left << setw(20) << "Tracking Number" << setw(20) << "Name"
				 << setw(20) << "Parcel Type" << setw(20) << "Source"
				 << setw(20) << "Destination" << setw(20) << "Status" << endl;
			    cout << setfill('-') << setw(120) << " " << setfill(' ') << endl;
        	    }

		    cout << left << setw(20) << trackingNum << setw(20) << name
			 << setw(20) << parcelType << setw(20) << source 
			 << setw(20) << destination << setw(20) << status << endl;
	    }
};

class Node {
   	public:
		Courier data;
		Node* next;
		
		Node(Courier d) {
			data = d;
			next = NULL;
		} 
};

class LinkedList {
   Node* head;
	
	public:
		LinkedList() {
			head = NULL;
		}
		
		Courier getNewCourier() {
	        string n, parcel, sourc, dest, stat;
	        int track;
	
	        cout << "\nEnter details for the new Courier:" << endl;
	
	        cout << "Name: ";
	        cin.ignore();
	        getline(cin, n);
	
	        cout << "Parcel Type: ";
	        getline(cin, parcel);
	
	        cout << "Source: ";
	        getline(cin, sourc);
	
	        cout << "Destination: ";
	        getline(cin, dest);
	
	        cout << "Status: ";
	        getline(cin, stat);
	
	        cout << "Tracking Number: ";
	        cin >> track;
			
	        cin.ignore();
	
	        return Courier(n, parcel, sourc, dest, stat, track);
    	}
	
		void insertFront(Courier d) {
			Node* newNode = new Node(d);
			newNode->next = head;
			head = newNode;
			cout << "Courier added at the beginning.\n" << endl;
		}
		
		void insertMiddle(Courier d, int position) {
			Node* newNode = new Node(d);
			
			if (!head) {
				if (position == 1) {
					head = newNode;
					return;
				}
				else {
					cout << "Invalid position. List is empty." << endl;
					return;
				}
			}
			
			int listSize = 1;
		    Node* sizeChecker = head;
		    while (sizeChecker->next) {
		        listSize++;
		        sizeChecker = sizeChecker->next;
		    }
		    if (position == 1) {
		        cout << "Invalid position. Use 'Insert at the beginning' option instead.\n" << endl;
		        delete newNode;
		        return;
		    } else if (position == listSize) {
		        cout << "Invalid position. Use 'Insert at the end' option instead.\n" << endl;
		        delete newNode;
		        return;
		    }
			
			Node* curr = head;
			int currPosition = 1;
			
			while (currPosition < position -1 && curr->next != NULL) {
				curr = curr->next;
				currPosition++;
			}
			
			if (currPosition < position - 1) {
				cout << "Invalid position." << endl;
				delete newNode;
				return;
			}
			
			newNode->next = curr->next;
			curr->next = newNode;
			cout << "Courier added at the position " << position << ".\n" << endl;
		}
		
		void insertBack(Courier d) {
			Node* newNode = new Node(d);
			if (!head) {
				head = newNode;
				return;
			}
			Node* curr = head;
			while (curr->next) {
				curr = curr->next;
			}
			curr->next = newNode;
		}
		
		void deleteFront() {
			if (!head) {
				cout << "List is empty." << endl;
				return;
			}
			Node* temp = head;
			head = head->next;
			delete temp;
			cout << "Courier deleted at the beginning.\n" << endl;
		}
		
		void deleteMiddle(int position) {
			if (!head) {
      			cout << "List is empty." << endl;
       			return;
    		}
    		
    		int listSize = 1;
		    Node* sizeChecker = head;
		    while (sizeChecker->next) {
		        listSize++;
		        sizeChecker = sizeChecker->next;
		    }
		     if (position == 1) {
		        cout << "Invalid position. Use 'Delete at the beginning' option instead.\n" << endl;
		        return;
		    } else if (position == listSize) {
		        cout << "Invalid position. Use 'Delete at the end' option instead.\n" << endl;
		        return;
		    }
    		
    		Node* curr = head;
    		Node* prev = NULL;
    		int currPosition = 1;
    		
    		while (currPosition < position && curr) {
    			prev = curr;
    			curr = curr->next;
    			currPosition++;
			}
			
			if (currPosition < position) {
				cout << "Invalid position." << endl;
        		return;
			}
			
			prev->next = curr->next;
			delete curr;
			cout << "Courier deleted at the position " << position << ".\n" << endl;
		}
		
		void deleteBack() {
			if (!head) {
            	cout << "List is empty. Nothing to delete." << endl;
            	return;
        	}
        	if (!head->next) {
        		delete head;
        		head = NULL;
        		return;
			}
			Node* curr = head;
			while (curr->next->next) {
				curr = curr->next;
			}
			delete curr->next;
			curr->next = NULL;
			cout << "Courier deleted at the end.\n" << endl;
		}
		
		void findNode(const Courier& searchData) {
		    Node* curr = head;
		    bool found = false;
			
		    while (curr) {
		        const Courier& currentData = curr->data;
		
		        if ((searchData.getName().empty() || currentData.getName() == searchData.getName()) ||
		            (searchData.getType().empty() || currentData.getType() == searchData.getType()) ||
		            (searchData.getSource().empty() || currentData.getSource() == searchData.getSource()) ||
		            (searchData.getDest().empty() || currentData.getDest() == searchData.getDest()) ||
		            (searchData.getStat().empty() || currentData.getStat() == searchData.getStat()) ||
		            (searchData.getTrackNum() != 0 && currentData.getTrackNum() == searchData.getTrackNum())) {

			     currentData.display(!found);
			     cout << endl;
			     found = true;
		        }
		
		        curr = curr->next;
		    }
		    if (!found)
			    cout << "\nCourier not found. Please try again.\n" << endl;
		}

		void sortList(int sortCriteria) {
		    if (!head || !head->next) {
		        return;
		    }
		    bool swapped;
		    Node* current;
		    Node* lastSorted = NULL;
		
		    do {
		        swapped = false;
		        current = head;
		
		        while (current->next != lastSorted) {
		            const Courier& currentData = current->data;
		            const Courier& nextData = current->next->data;
		
		            switch (sortCriteria) {
		                case 1:
					if (currentData.getName() > nextData.getName()) {
		                        Courier temp = current->data;
		                        current->data = current->next->data;
		                        current->next->data = temp;
		                        swapped = true;
		                    }
		     
		                    break;
		                case 2: 
		                    if (currentData.getType() > nextData.getType()) {
		                        Courier temp = current->data;
		                        current->data = current->next->data;
		                        current->next->data = temp;
		                        swapped = true;
		                    }
		                    break;
		                case 3: 
		                   if (currentData.getTrackNum() > nextData.getTrackNum()) {
		                        Courier temp = current->data;
		                        current->data = current->next->data;
		                        current->next->data = temp;
		                        swapped = true;
		                    }
		                    break;
		                default:
		                    cout << "Invalid sort criteria.\n";
		                    return;
		            }
		            current = current->next;
		        }
		
		    lastSorted = current; 
		    } while (swapped);
		    
		    switch (sortCriteria) {
		        case 1:
		            cout << "List sorted by name.\n";
		            break;
		        case 2:
		            cout << "List sorted by parcel type.\n";
		            break;
		        case 3:
		            cout << "List sorted by tracking number.\n";
		            break;
		        default:
		        	cout << "Invalid sort criteria.\n";
		            break;
		    }
		}
		
		void displayList() {
		    Node* current = head;
		    int nodeNumber = 1; 
			cout << endl;
		    cout << left << setw(6) << "No." << setw(20) << "Tracking Number" << setw(20) << "Name"
		         << setw(20) << "Parcel Type" << setw(20) << "Source"
		         << setw(20) << "Destination" << setw(20) << "Status" << endl;
		    cout << setfill('-') << setw(120) << "" << setfill(' ') << endl;
		
		    while (current) {
		        const Courier& currentData = current->data;
		        cout << left << setw(6) << "[" + to_string(nodeNumber) + "]" << setw(20) << currentData.getTrackNum() << setw(20) << currentData.getName()
		             << setw(20) << currentData.getType() << setw(20) << currentData.getSource()
		             << setw(20) << currentData.getDest() << setw(20) << currentData.getStat() << endl;
		        current = current->next;
		        nodeNumber++;
		    }
		}
};

class Queue {
    queue<Courier> courierQueue;

public:
    void enqueue(const Courier& courier) {
        courierQueue.push(courier);
    }

    void dequeue() {
        if (!courierQueue.empty()) {
            courierQueue.pop();
        } else {
            cout << "Queue is empty. Nothing to dequeue.\n";
        }
    }

    void displayQueue() {
        queue<Courier> tempQueue = courierQueue;

        cout << "\nCourier Queue:\n";
        int count = 1;
        while (!tempQueue.empty()) {
            const Courier& currentData = tempQueue.front();
            cout << "[" << count << "] ";
            currentData.display(false);
            tempQueue.pop();
            count++;
        }
       
    }
};

class Stack {
    stack<Courier> courierStack;

public:
    void push(const Courier& courier) {
        courierStack.push(courier);
    }

    void pop() {
        if (!courierStack.empty()) {
            courierStack.pop();
        } else {
            cout << "Stack is empty. Nothing to pop.\n";
        }
    }

  
};


int main() {
    
    ifstream inputFile("TEST.txt");
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
                CourierQueue.dequeue();
                break;
        	}
            case 8: {
                CourierQueue.displayQueue();
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
