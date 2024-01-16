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
