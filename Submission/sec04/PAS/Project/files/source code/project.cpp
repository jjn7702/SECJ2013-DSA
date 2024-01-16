#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#define N 100
using namespace std;

void header() {
    //cout << "\nList of Books in the Library:\n" << endl;
    cout << left 
         << setw(9) << "ID" 
         << setw(31) << "BOOK TITLE" 
         << setw(29) << "BOOK AUTHOR"
         << setw(9) << "YEAR" 
         << setw(8) << "GENRE" 
         << endl
         << "------------------------------------------------------------------------------------------------------"
         << endl;
}

void headerQ() {
    //cout << "\nList of Books in the Library:\n" << endl;
    cout << left 
         << setw(15) << "NAME" 
         << setw(10) << "ID" 
         << setw(31) << "BOOK TITLE" 
         << setw(29) << "BOOK AUTHOR"
         << setw(9) << "YEAR" 
         << setw(8) << "GENRE" 
         << endl
         << "----------------------------------------------------------------------------------------------------------"
         << endl;
}

class Node {
    string id, name, author, genre;
    int year;

public:
    Node *next;

    Node(string _id, string _name, string _author, int _year, string _genre) {
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

    void display() {
        cout << left 
             << setw(8) << id << " " 
             << setw(30) << name << " " 
             << setw(28) << author << " "
             << setw(8) << year << " " 
             << setw(10) << genre << endl;
    }
};

class Stack {
    Node *top;

public:
    Stack() {
        top = NULL;
    }

    void push(string id, string name, string author, int year, string genre) {
        Node *nn = new Node(id, name, author, year, genre);
        	nn->next = top;
        top = nn;
    }
    void pop() {
        if (isEmpty())
            cout << "The stack is empty\n";
        else {
            Node *temp = top;
            top = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }
    string stackTop() {
        return top->getID();
    }
    Node *stackTopN() {
    	return top;
    }
    bool isEmpty() {
        return top == NULL;
    }

    void display() {
    	cout << "\nList of Books in the Library:\n" << endl;
        header();
        Node *temp = top;
        while (temp != NULL) {
            temp->display();
            temp = temp->next;
        }
        cout << endl;
    }
};

class Queue {
    public:
    	int front, back, count;
    	string name[N];
        Node* b[N];
        
        Queue() {
            front = 0;
            back = -1;
            count = 0;
        }
        bool isEmpty() {
            return (count == 0);
        }
        bool isFull() {
            return (count == N);
        }
	Node* getBook() {
	    return b[front];
	}
	string getName(int idx) {
	    return name[idx];
	}
        void enQueue(string n, Node* bb) {
            if (isFull())
                cout << "\tCannot insert. Queue is full!" << endl;
            else {
                back++;
                count++;
                name[back] = n;
                b[back] = bb;
            }
        }
        void deQueue() {
            if (isEmpty())
                cout << "\tCannot remove. Queue is empty!" << endl;
            else {
                front++;
                count--;
            }
        }
        void deQueue(int index) {
            for (int i = index; i < back; i++) {
        	name[i] = name[i+1];
        	b[i] = b[i+1];
            }
            back--;
            count--;
        }

        void print() {
            if (isEmpty())
                cout << "Sorry, the queue is empty" << endl;
            else {
                headerQ();
                for (int i = front; i <= back; i++) {
                    cout << left << setw(15) << name[i] << " " << setw(5);
                    b[i]->display();
                }
                cout << endl;
            }
        }
};

int mainMenu() {
    int opt;
    cout << "-----Option Menu-----\n"
         << "[1] Enter a new book\n"
         << "[2] Undo/Remove the latest book\n"
         << "[3] Get current number of books\n"
         << "[4] Get most recently added book\n"
         << "[5] Display current list of books\n"
         << "[6] Borrow book\n"
         << "[7] Return book\n"
         << "[8] Display all request to borrow book\n"
         << "[9] Exit\n"
         << "\nYour Option: ";
    cin >> opt;
    
    return opt;
}

int main() {
    string id[N], name[N], author[N], genre[N];
    int year[N], count = 0;
    Stack books;
    string id_, title_, author_, genre_;
    int year_, recent, removed;
    
	Queue borrow;
    Queue request;
    string borrower;
    
    ifstream inp ("inp.txt");
    
    for (int i = 0; i < 10; i++) {
        getline(inp, id[i], ',');
        getline(inp, name[i], ',');
        getline(inp, author[i], ',');
        inp >> year[i];
        inp.ignore();
        getline(inp, genre[i]);
        books.push(id[i], name[i], author[i], year[i], genre[i]);
        count++;
    }
    books.display();
    
    int opt1 = mainMenu();
    
    while(opt1>0 && opt1<10) {
        switch(opt1) {
        case 1: //Add a new book to the library
	        cin.ignore();
            cout << "\n-----Insert Book Details-----\n";
			cout << "ID: ";
			getline(cin, id_);
			id[count] = id_;
			cout << "Book Title: ";
			getline(cin, title_);
			name[count] = title_;
			cout << "Book Author: ";
			getline(cin, author_);
			author[count] = author_;
			cout << "Year: ";
			cin >> year_;
			year[count]  = year_;
			cin.ignore();
			cout << "Genre: ";
			getline(cin, genre_);
			genre[count] = genre_;
			cout << endl;
			books.push(id_,title_,author_,year_,genre_);
			count++;
			cout << title_ << " is succesfully added into the library.";
			books.display();
	    	break;
	   case 2: //Delete latest book in the library
	        for (int i = 0; i < count; i++) {
	    	    if (id[i] == books.stackTop())
	    	        removed = i;
	    	}
	    	cout << endl << name[removed] << " is succesfully removed into the library.\n";
	    	books.pop();
	    	books.display();
	    	count--;
	    	break;
        case 3: //Check amount of books in the library
            	cout << "There are currently " << count << " books in the library.\n" << endl;
            	break;
        case 4: //Display details of most recent book in the library
		    for (int i = 0; i < count; i++) {
	    	    if (id[i] == books.stackTop())
	    	        recent = i;
	    	}
	    	cout << "The most recently added book is:\n\n";
	    	header();
	    	cout << left 
				 << setw(8) << id[recent] << " " 
				 << setw(30) << name[recent] << " " 
				 << setw(28) << author[recent] << " "
				 << setw(8) << year[recent] << " " 
				 << setw(10) << genre[recent] << endl << endl;
	    	break;
        case 5: //Display all books available in the library
            	books.display();
            	break;
        case 6: //Borrow book
            {
            cout << "\nEnter the name of borrower: ";
            cin.ignore();
            getline(cin, borrower);
            
            cout << "Enter the ID of the book to borrow: ";
            string bID;
            cin >> bID;
            
            Node* borrowedBook = NULL;
            Node* currBook = books.stackTopN();
            
            //To find the soecific ID book entered by user
            while (currBook != NULL) {
            	if ((currBook->getID() == bID)) {
            		borrowedBook = currBook;
            		break;
            	}
            	currBook = currBook->next;
            }
            //To check if the book is available to borrow or not
            if (borrowedBook != NULL) {
            	bool isBorrowed = false;
            	for (int i = borrow.front; i <= borrow.back; i++) {
            		if (borrow.b[i]->getID() == bID) {
            			isBorrowed = true;
            			break;
            		}
            	}
               	if (!isBorrowed) { //Add to borrowing queue if book is available
				   borrow.enQueue(borrower, borrowedBook);
				   cout << "\nList of People Borrowing Books: \n" << endl;
				   borrow.print();
				   cout << borrowedBook->getName() << " is successfully borrowed by " << borrower << ".\n\n";
	        	}
        		else { //Add to requesting queue if book is currently borrowed by someone else
        			request.enQueue(borrower, borrowedBook);
        			cout << "\nBook is not successfully borrowed by " << borrower << ". " << borrower << " is now in the queue." << endl << endl;
        			cout << "\nList of People Queueing to Borrow Books: \n" << endl;
					request.print();
        		}
    		}
    		else {
    			cout << "\nBook does not exist in the library.\n" << endl;
    		}
    		}
            break;
            
        case 7: //Return book & let next person borrow the returned book (if any)
        	{
        	Node *returnedBook = borrow.getBook();
        	borrow.deQueue();
        	cout << "\nReturned Book Details: " << endl;
        	header();
        	returnedBook->display();
        	cout << endl;
        	
        	if (!request.isEmpty()) {
        		bool findBook = false;
        		int index = 0;
	        	for (int i = request.front; i <= request.back; i++) {
	            	if (request.b[i]->getID() == returnedBook->getID()) {
	            		findBook = true;
	            		index = i;
	            		break;
	            	}
	            }
	            if (!findBook) {
	            	cout << "\nThe returned book is not in the request queue." << endl;
	            }
	            else {
	            	//Add requested book to borrow that is same with returned book to borrowing queue
	            	borrow.enQueue(request.getName(index), request.b[index]);
	            	cout << "\nList of people borrowed books(updated): \n" << endl;
	            	borrow.print();
	            	cout << returnedBook->getName() << " is successfully borrowed by " << request.getName(index) << ".\n\n";
	            	//Remove the book & borrower from request queue
	            	request.deQueue(index);
	            }
        	}
        	else {
        		cout << "\nNo requests in the queue.\n" << endl;
        	}
            break;
        	}
        case 8: //Display
        	cout << "List of People Queueing to Borrow Books: \n" << endl;
        	request.print();
        	break;
        case 9:
            exit(0);
        }
        opt1 = mainMenu();
    }
	
	return 0;
}
