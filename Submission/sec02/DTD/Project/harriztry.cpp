#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define MAX_SIZE 100

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    string ISBN;

public:
    Book() : title(""), author(""), year(0), ISBN("") {}

    string getTitle()  { return title; }
    string getAuthor()  { return author; }
    int getYear()  { return year; }
    string getISBN()  { return ISBN; }

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

class Stack{
    private:
        int top;
        Book book[MAX_SIZE];

    public:
        void createStack(){
            top = -1;
        }

        void push(Book newBook){
            if(isFull()){
                cout << "Stack is full" << endl;
            }else{
                top++;
                book[top] = newBook;
            }
        }

        bool isEmpty(){
            return (top == -1);
        }
        bool isFull(){
            return (top == MAX_SIZE - 1);
        }
};
