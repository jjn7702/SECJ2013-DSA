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


class Library {
private:
    Node* head;
    int size;
    Queue bookQueue;
    Queue userQueue;

public:
    Stack borrowedHistory; 

    Library() : head(nullptr), size(0) {}

    ~Library() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void displayList() const {
        system("cls");
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(50) << left << "| Title"
             << setw(30) << left << "| Author"
             << setw(10) << left << "| Year"
             << setw(15) << left << "| ISBN"
             << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;

        Node* current = head;

        while (current != nullptr) {
            current->data.displayBook();
            current = current->next;
        }

        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    }

    int getSize() const {
        return size;
    }


    void addBookEnd(const Book& book) {
        Node* newNode = new Node(book, nullptr);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;

            while (current->next) {
                current = current->next;
            }

            current->next = newNode;
        }

        size++;
    }

    void deleteBook(const string& isbn) {
        if (head == nullptr) {
            cout << "Error: The library is empty.\n";
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        // Search for the book with the specified ISBN
        while (current != nullptr && current->data.getISBN() != isbn) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Error: Book with ISBN " << isbn << " not found.\n";
            return;
        }

        // Found the book, now delete it
        if (prev == nullptr) {
            // Book is at the beginning of the list
            head = head->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        size--;
        cout << "Book with ISBN " << isbn << " deleted successfully.\n";
    }

    void requestBookBorrowing(const Book& book) {
        userQueue.enqueue(book);
        cout << "Your request to borrow the book '" << book.getTitle() << "' has been added to the queue.\n";
    }

    void processUserBorrowRequests() {
        system("cls");
        cout << "Processing User Borrow Requests:\n";

        if (!userQueue.isEmpty()) {
            // Display the book at the front of the queue
            userQueue.displayQueueFront();

            // Check if the user's request has been processed
            Book requestedBook = userQueue.getFront();
            bool bookFound = isBookInLibrary(requestedBook);

            if (bookFound) {
                // Book is available, request is approved
                cout << "Your request to borrow the book '" << requestedBook.getTitle() << "' has been approved.\n";
                cout << "You can now collect the book.\n";

                // Remove the book from the library
                deleteBook(requestedBook.getISBN());

                // Add to borrowed history
                borrowedHistory.push(requestedBook);

                userQueue.dequeue();  // Remove the request from the queue
            } else {
                cout << "Book cannot be borrowed as it's not available\n";
            }
        } else {
            cout << "No user borrow requests to process.\n";
        }

        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    }

   void displayBorrowedHistory() const {
    borrowedHistory.displayStack();
}

Book getTop() const {
    return borrowedHistory.getTop();
}

    bool isBookInLibrary(const Book& book) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.getISBN() == book.getISBN()) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void patronMenu() {
        int choice;
        do {
            cout << "Patron Menu\n";
            cout << "[1] Request to Borrow a Book\n";
            cout << "[2] Check Borrow Request Status\n";
            cout << "[3] Display Books\n";
            cout << "[4] Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    displayList();
                    Book requestedBook;
                    cin.ignore();
                    string input;
                    cout << "Enter the title of the book you want to borrow: ";
                    getline(cin, input);
                    requestedBook.setTitle(input);

                    cout << "Enter the author of the book: ";
                    getline(cin, input);
                    requestedBook.setAuthor(input);

                    cout << "Enter the year of publication: ";
                    cin >> input; // Assuming Year is a string
                    requestedBook.setYear(stoi(input));

                    cin.ignore(); // Clear the newline character
                    cout << "Enter the ISBN (Example: 123-1234567890): ";
                    getline(cin, input);
                    requestedBook.setISBN(input);

                    requestBookBorrowing(requestedBook);
                    break;
                }
                case 2:
                    processUserBorrowRequests();
                    break;
                case 3:
                    displayList();
                    break;
                case 4:
                    cout << "Exiting patron menu.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }

            cout << "---------------------------------\n";
        } while (choice != 4);
    }

    void staffMenu() {
    int choice;
    do {
        cout << "Staff Menu\n";
        cout << "[1] Check Borrowed History\n";
        cout << "[2] Last Book borrowed\n";
        cout << "[3] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

       switch (choice) {
        case 1:
            displayBorrowedHistory(); 
            break;
        case 2: {
            Book lastBorrowedBook = getTop();
            if (lastBorrowedBook.getISBN() != "") { 
                cout << "Last Book Borrowed:\n";
                lastBorrowedBook.displayBook();
        }   else {
            cout << "No books have been borrowed yet.\n";
        }
            break;
        }
        case 3:
            cout << "Exiting staff menu.\n";
            break;
        default:
        cout << "Invalid choice. Please try again.\n";
}


        cout << "---------------------------------\n";
    } while (choice != 3);
}
};


int main() {
    Library library;
    int userType;

    // Reading books from the file
    ifstream inputFile("book.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file: book.txt" << endl;
    }

    int booksRead = 0;
    while (!inputFile.eof()) {
        string Title, Author, isbn;
        int Year;

        getline(inputFile, Title, ',');
        getline(inputFile, Author, ',');
        inputFile >> Year;
        inputFile.ignore();
        getline(inputFile, isbn);

        Book newBook;
        newBook.setTitle(Title);
        newBook.setAuthor(Author);
        newBook.setYear(Year);
        newBook.setISBN(isbn);

        library.addBookEnd(newBook);
        booksRead++;
    }

    cout << "Number of books read: " << booksRead << endl;

    inputFile.close();

     do {
        cout << "Welcome to the Library Management System!\n";
        cout << "Are you a staff or a patron?\n";
        cout << "[1] Staff\n";
        cout << "[2] Patron\n";
        cout << "[3] Exit\n";
        cout << "Enter your choice: ";
        cin >> userType;

        switch (userType) {
            case 1:
                library.staffMenu();
                break;
            case 2:
                library.patronMenu();
                break;
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "---------------------------------\n";
    } while (userType != 3);

    return 0;
}