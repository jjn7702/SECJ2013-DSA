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
