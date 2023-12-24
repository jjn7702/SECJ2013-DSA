#include <iostream>
#include <iomanip>

using namespace std;

class Book{
private:
    string title;
    string author;
    int year;
    string ISBN;

public:
    Book(){
        title = "";
        author = "";
        year = 0;
        ISBN = "";
    }

    string getTitle() const{
        return title;
    }

    string getAuthor() const{
        return author;
    }

    int getYear() const{
        return year;
    }

    string getISBN() const{
        return ISBN;
    }
};

class Node{
public:
   
    Node* next;


};

class LibraryLinkedList{
private:
    Node* head;

public:

LibraryLinkedList() : head(nullptr) {}




};