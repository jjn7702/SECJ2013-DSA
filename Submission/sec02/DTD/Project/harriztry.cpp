#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    string ISBN;

public:
    Book() : title(""), author(""), year(0), ISBN("") {}

    // Getter functions
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    string getISBN() const { return ISBN; }

    // Setter functions
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setYear(int y) { year = y; }
    void setISBN(const string& i) { ISBN = i; }

    // Display book details
    void displayBook() const {
        cout << setw(50) << left << "| " + title
             << setw(30) << left << "| " + author
             << setw(10) << left << "| " + to_string(year)
             << setw(15) << left << "| " + ISBN + "|" << endl;
    }
};

class Library {
private:
    static const int MAX_SIZE = 100;  // Maximum size for the stack
    Book stackArray[MAX_SIZE];        // Array for stack
    int top;                          // Top index for stack

public:
    // Constructor
    Library() : top(-1) {}

    // Stack operations
    void pushBook(const Book& book) {
        if (top < MAX_SIZE - 1) {
            stackArray[++top] = book;
            cout << "Book added to the stack: " << book.getTitle() << endl;
        } else {
            cout << "Stack is full. Cannot add more books.\n";
        }
    }

    void popBook() {
        if (top >= 0) {
            cout << "Book removed from the stack: " << stackArray[top].getTitle() << endl;
            top--;
        } else {
            cout << "Stack is empty. No book to remove.\n";
        }
    }

    // Display books in the stack
    void displayStack() const {
        cout << "Books in the stack:\n";
        for (int i = top; i >= 0; i--) {
            stackArray[i].displayBook();
        }
        cout << "------------------------\n";
    }
};

int main() {
    Library library;
    int choice;
    ifstream inputFile("Book.txt");
    Book newBook;
        string Title, Author, ISBN;
        int Year;

    // Check if the file is open
    if (!inputFile.is_open()) {
        cout << "Error opening file: Book.txt" << endl;
        return 1;  // Return with an error code
    }

    // Read books from the file and add them to the library
    int booksRead = 0;

    while (!inputFile.eof()) {
        

        getline(inputFile, Title, ',');
        getline(inputFile, Author, ',');
        inputFile >> Year;
        inputFile.ignore();  // Consume the newline character after reading the year
        getline(inputFile, ISBN);

        newBook.setTitle(Title);
        newBook.setAuthor(Author);
        newBook.setYear(Year);
        newBook.setISBN(ISBN);

        library.pushBook(newBook);
        booksRead++;
    }

    cout << "Number of books read: " << booksRead << endl;

    // Close the file
    inputFile.close();

    do {
        cout << "Library Management System\n";
        cout << "[1] Add Book to Stack\n";
        cout << "[2] Remove Book from Stack\n";
        cout << "[3] Display Books in Stack\n";
        cout << "[4] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Book newBook;
                cin.ignore(); // Ignore newline character from previous input
                cout << "Enter book title: ";
                getline(cin, Title);
                newBook.setTitle(Title);
                cout << "Enter book author: ";
                getline(cin, Author);
                newBook.setAuthor(Author);
                cout << "Enter year of publication: ";
                cin >> Year;
                newBook.setYear(Year);
                cin.ignore(); // Ignore newline character from previous input
                cout << "Enter ISBN (Example : 123-1234567890): ";
                getline(cin, ISBN);
                newBook.setISBN(ISBN);

                library.pushBook(newBook);
                break;
            }
            case 2:
                library.popBook();
                break;
            case 3:
                library.displayStack();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "---------------------------------\n";

    } while (choice != 4);

    return 0;
}
