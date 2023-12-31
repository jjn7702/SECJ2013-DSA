#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

void header() {
	cout << "\nList of Books in the Library:\n" << endl;
	cout << left 
		 << setw(9) << "ID" 
		 << setw(31) << "BOOK TITLE" 
		 << setw(29) << "BOOK AUTHOR"
		 << setw(9) << "YEAR" 
		 << setw(8) << "GENRE" 
		 << endl
		 <<"---------------------------------------------------------------------------------------------------"
		 << endl << endl;
}

int searchOption() {
    int opt;
    cout << "\nSelect Searching Type" << endl
         << "[1] By Book ID" << endl
         << "[2] By Title" << endl
         << "[3] By Author" << endl
         << "[4] By Genre" << endl
         << "[5] By Year" << endl
         << "\nOption: ";
    cin >> opt;
    return opt;
}

void deleteOption() {
  cout << "\nDelete" << endl
     << "[1] Book at the top of the list" << endl
     << "[2] Book at the bottom of the list" << endl
     << "[3] Book in the middle of the list" << endl
     << "\nOption: ";
}

class Node {
    string id, name, author, genre;
	int year;
	public:
	    Node *next;
	    Node(string _id = "", string _name = "", string _author = "", int _year = 0, string _genre = "") {
			id = _id;
			name = _name;
			author = _author;
			year = _year;
			genre = _genre;
			next = NULL;
		}
		string getID() {
			return id;
		}
		string getName() {
			return name;
		}
		string getAuthor() {
			return author;
		}
		int getYear() {
			return year;
		}
		string getGenre() {
			return genre;
		}
		void displaySearch() {
			cout << left 
				 << setw(8) << id << " " 
				 << setw(30) << name << " " 
				 << setw(28) << author << " "
				 << setw(8) << year << " " 
				 << setw(10) << genre << endl;
		}
		
};

class BookList {
    Node *head;
    public:
        BookList() {
            head = NULL;
        }
        bool isEmpty() {
			return head == NULL;
		}
		void display() {
            Node *temp = head;
            header();
            while(temp != NULL) {
                cout << setw(8) << temp->getID() << " " 
				     << setw(30) << temp->getName() << " " 
				     << setw(28) << temp->getAuthor() << " "
				     << setw(8) << temp->getYear() << " " 
				     << setw(10) << temp->getGenre() << endl;
                temp = temp->next;
            }
            cout << endl;
        }
		void insertF(string id, string n, string a, int y, string g) { // beginning
			Node *newNode = new Node(id, n, a, y, g); 
			if (isEmpty()) {
				head = newNode;
			}
			else {
				newNode->next = head;
				head = newNode;
			}
		}
		void insertM(string id, string n, string a, int y, string g, int m) { // middle
		    Node *newNode = new Node(id, n, a, y, g); 
		    if (isEmpty()) {
				head = newNode;
			}
			else {
                Node *temp = head;
                int x, count = 1;
                cout << "The current number of books is " << m << ".\n";
                cout << "At which position do you wish to insert the book? (1-indexed): ";
                cin >> x;
                while(temp->next != NULL && count < x-1) {
                    temp = temp->next;
                    count++;
                }
                newNode->next = temp->next;
                temp->next = newNode;
			}
        }
        void insertE(string id, string n, string a, int y, string g) {
            Node *newNode = new Node(id, n, a, y, g);
		if (isEmpty()) {
			head = newNode;
		}
		else {
                Node *temp = head;
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
		}
        }
        void deleteNode(int &n) {
            int choice;
            deleteOption();
            cin >> choice;
      
            Node *temp = head;
            Node *delnode;
      
            switch(choice) {
                case 1: //front
                if (isEmpty()) {
                    cout << "List is empty, nothing to delete" << endl;
                }
                else if (temp->next != NULL) {
                    head = temp->next;
                    temp->next = NULL;
                    delete temp;
                }
                else { //if contains only one node
                    delete temp;
                    head = NULL;
                }
                n--;
                display();
                break;
          
                case 2: //end
                temp = head;
          
                if (isEmpty()) {
                    cout << "List is empty, nothing to delete" << endl;
                }
                else if (temp->next == NULL){ //if contains only one node
                    delete temp;
                    head = NULL;  
                }
                else {
                    while (temp->next != NULL) {
                        delnode = temp;
                        temp = temp->next;
                    }
                    delete temp;
                    delnode->next = NULL;
                }
                n--;
                display();
                break;
          
                case 3: //middle
                int count = 1;
                int index;
          
                cout << "Enter the position of book information that you want to delete: ";
                cin >> index;
          
                while (temp->next != NULL && count < index-1) {
                    delnode = temp;
                    temp = temp->next;
                    count++;
                }
                delnode = temp->next;
                temp->next = delnode->next;
                delete delnode;
                n--;
                display();
                break;
            }
        }
        void searchString(int opt, string key){
        	Node *currNode = head;
            	int currIndex = 1; 
 			
 		cout << endl;
            	switch(opt){
                case 1: 
            		while(currNode->getID() != key){
				currNode = currNode->next;
				currIndex++;
			}
			if(currNode) {
				header();
				currNode->displaySearch();
			}
                    	else
                    		cout << "The book ID is invalid.";
                    	break;
                case 2:
                	while(currNode->getName() != key){
				currNode = currNode->next;
				currIndex++;
			}
			if(currNode) {
				header();
				currNode->displaySearch();
			}
                    	else
                        	cout << "The book title is invalid.";
	                break;
                case 3:
                	while(currNode->getAuthor() != key){
				currNode = currNode->next;
				currIndex++;
			}
			if(currNode) {
				header();
				currNode->displaySearch();
			}
                    	else
                        	cout << "The book author is invalid.";
                   	break;
                case 4:
                	while(currNode->getGenre() != key){
				currNode = currNode->next;
				currIndex++;
			}
			if(currNode) {
				header();
				currNode->displaySearch();
			}
			else
