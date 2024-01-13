#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Book{
    private:
        string title;
        string author;
        int year;
        string ISBN;

    public:
        Book(string title, string author, int year, string ISBN){
            this->title = title;
            this->author = author;
            this->year = year;
            this->ISBN = ISBN;
        }

        string getTitle(){
            return title;
        }

        string getAuthor(){
            return author;
        }

        int getYear(){
            return year;
        }

        string getISBN(){
            return ISBN;
        }

        void setTitle(string title){
            this->title = title;
        }

        void setAuthor(string author){
            this->author = author;
        }

        void setYear(int year){
            this->year = year;
        }

        void setISBN(string ISBN){
            this->ISBN = ISBN;
        }

        void displayBook(){
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Year: " << year << endl;
            cout << "ISBN: " << ISBN << endl;
        }
}
