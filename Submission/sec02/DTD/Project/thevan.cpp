#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    string ISBN;

public:
    Book() : title(""), author(""), year(0), ISBN("") {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    string getISBN() const { return ISBN; }

    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setYear(int y) { year = y; }
    void setISBN(const string& i) { ISBN = i; }

    void displayBook() const {
        cout << setw(50) << left << "| " + title
             << setw(30) << left << "| " + author
             << setw(10) << left << "| " + to_string(year)
             << setw(15) << left << "| " + ISBN + "|" << endl;
    }
};

struct Node {
    Book data;
    Node* next;

    Node(const Book& b, Node* n = nullptr) : data(b), next(n) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const Book& book) {
        Node* newNode = new Node(book);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Book dequeue() {
        Book result;
        if (!isEmpty()) {
            Node* temp = front;
            result = front->data;
            front = front->next;
            delete temp;
        }
        return result;
    }

   Book getFront() const {
    if (front != nullptr) {
        return front->data;
    } else {
        return Book();
    }
}


    bool isEmpty() const {
        return front == nullptr;
    }

    void displayQueue() const {
        cout << "Books in the queue:\n";
       
    }

    void displayQueueFront() const {
        if (!isEmpty()) {
            cout << "Next book in the queue:\n";
            front->data.displayBook();
          
        } else {
            cout << "Queue is empty.\n";
        }
    }
};

class Stack {
private:
    Node* top; 

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const Book& book) {
        Node* newNode = new Node(book, top);
        top = newNode;
    }

    Book pop() {
        Book result;
        if (!isEmpty()) {
            Node* temp = top;
            result = top->data;
            top = top->next;
            delete temp;
        }
        return result;
    }

   Book getTop() const {
    if (top != nullptr) {
        return top->data;
    } else {
        return Book(); 
    }
}

    bool isEmpty() const {
        return top == nullptr;
    }

    void displayStack() const {
        cout << "Borrowed History:\n";
        Node* current = top;

        while (current != nullptr) {
            current->data.displayBook();
            current = current->next;
        }

        cout << "----------------------\n";
    }
};