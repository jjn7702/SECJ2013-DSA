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
