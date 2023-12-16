#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#define N 20

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
        
        string getTitle(){
            return title;
        }

        string getAuthor(){
            return author;
        }

        int getyear(){
            return year;
        }

        string getISBN(){
            return ISBN;
        }

        void setTitle(string t){
            title = t;
        }

        void setAuthor(string a){
            author = a;
        }

         void setYear(int y){
            year = y;
        }

         void setISBN(string i){
            ISBN = i;
        }
        
        friend istream& operator>>(istream& in, Book& book) {
        getline(in, book.title, ',');
        getline(in, book.author, ',');

        return in;
        }   

};

int readFile (Book book[] , int &size){ // read data from file
    ifstream inFile;
    inFile.open("Book.txt");
    if (!inFile){
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    int i = 0;
    while (!inFile.eof()){
        inFile >> book[i];
        i++;
    }
    size = i;
    inFile.close();
    return size;

}
