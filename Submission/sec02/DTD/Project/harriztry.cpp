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
    static const int MAX_SIZE = 100;  // Maximum size for stack and queue
    Book stackArray[MAX_SIZE];        // Array for stack
    Book queueArray[MAX_SIZE];        // Array for queue
    int top;                          // Top index for stack
    int front;                        // Front index for queue
    int rear;                         // Rear index for queue

public:
    // Constructor
    Library() : top(-1), front(0), rear(-1) {}

    // Stack operations
    void pushBookToStack(const Book& book) {
        if (top < MAX_SIZE - 1) {
            stackArray[++top] = book;
            cout << "Book added to the stack: " << book.getTitle() << endl;
        } else {
            cout << "Stack is full. Cannot add more books.\n";
        }
    }

    void popBookFromStack() {
        if (top >= 0) {
            cout << "Book removed from the stack: " << stackArray[top].getTitle() << endl;
            top--;
        } else {
            cout << "Stack is empty. No book to remove.\n";
        }
    }

    // Queue operations
    void enqueueBook() {
        Book newBook;
        cin.ignore(); // Ignore newline character from previous input
        cout << "Enter book title: ";
        getline(cin, newBook.setTitle);
        cout << "Enter book author: ";
        getline(cin, newBook.setAuthor);
        cout << "Enter year of publication: ";
        cin >> newBook.setYear;
        cin.ignore(); // Ignore newline character from previous input
        cout << "Enter ISBN (Example: 123-1234567890): ";
        getline(cin, newBook.setISBN);

        if (rear < MAX_SIZE - 1) {
            queueArray[++rear] = newBook;
            cout << "Book enqueued: " << newBook.getTitle() << endl;
        } else {
            cout << "Queue is full. Cannot enqueue more books.\n";
        }
    }

    void dequeueBook() {
        if (front <= rear) {
            cout << "Book dequeued: " << queueArray[front].getTitle() << endl;
            front++;
        } else {
            cout << "Queue is empty. No book to dequeue.\n";
            front = 0;
            rear = -1;
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

    // Display books in the queue
    void displayQueue() const {
        cout << "Books in the queue:\n";
        for (int i = front; i <= rear; i++) {
            queueArray[i].displayBook();
        }
        cout << "------------------------\n";
    }
};

int main() {
    Library library;
    int choice;
    string Title, Author, ISBN;
    int Year;

    ifstream inputFile("Book.txt");

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

        Book newBook;
        newBook.setTitle(Title);
        newBook.setAuthor(Author);
        newBook.setYear(Year);
        newBook.setISBN(ISBN);

        library.pushBookToStack(newBook);
        library.enqueueBook(newBook);
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
        cout << "[4] Enqueue Book to Queue\n";
        cout << "[5] Dequeue Book from Queue\n";
        cout << "[6] Display Books in Queue\n";
        cout << "[7] Exit\n";
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
                cout << "Enter ISBN (Example: 123-1234567890): ";
                getline(cin, ISBN);
                newBook.setISBN(ISBN);

                library.pushBookToStack(newBook);
                break;
            }
            case 2:
                library.popBookFromStack();
                break;
            case 3:
                library.displayStack();
                break;
            case 4:
                library.enqueueBook();
                break;
            case 5:
                library.dequeueBook();
                break;
            case 6:
                library.displayQueue();
                break;
            case 7:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
