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
    Book() {
        title = "";
        author = "";
        year = 0;
        ISBN = "";
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }

    string getISBN() const {
        return ISBN;
    }

    void setTitle(const string& t) { 
        title = t;
    }

    void setAuthor(const string& a) { 
        author = a; 
    }

    void setYear(int y) { 
        year = y; 
    }

    void setISBN(const string& isbn) { 
        ISBN = isbn; 
    }

    // Display book details
    void displayBook() const {
        cout << setw(50) << left << "| " + title
             << setw(30) << left << "| " + author
             << setw(10) << left << "| " + to_string(year)
             << setw(15) << left << "| " + ISBN + "|" << endl;
    }
};

// Node structure for the linked list
struct Node {
    Book data;
    Node* next;
};

class Library {
private:
    Node* head;

public:
    // Constructor and destructor
    Library() : head(nullptr) {}
    ~Library();

    // Linked list operations
    void addNode(const Book& book);
    void deleteNode(const string& key);
    Node* findNode(const string& key) const;
    void sortList();
    void displayList() const;
};

Library::~Library() {
    // Destructor to free allocated memory
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

void Library::addNode(const Book& book) {
    Node* newNode = new Node{book, nullptr};

    // Insert at the beginning
    newNode->next = head;
    head = newNode;
}


void Library::deleteNode(const string& key) {
    Node* current = head;
    Node* prev = nullptr;

    // Traverse the list to find the node with the key
    while (current != nullptr && (current->data.getTitle() != key && current->data.getISBN() != key)) {
        prev = current;
        current = current->next;
    }

    // If the node with the key is found
    if (current != nullptr) {
        if (prev == nullptr) {
            // If it's the first node
            head = current->next;
        } else {
            // If it's in the middle or end
            prev->next = current->next;
        }
        delete current;
    } else {
        cout << "Book not found with title or ISBN: " << key << endl;
    }
}

Node* Library::findNode(const string& key) const {
    Node* current = head;

    while (current != nullptr && (current->data.getTitle() != key && current->data.getISBN() != key)) {
        current = current->next;
    }

    return current;
}

void Library::sortList() {
    // Simple bubble sort for sorting by title in ascending order
    if (head == nullptr || head->next == nullptr) {
        // Already sorted or empty list
        return;
    }

    bool swapped;
    Node* current;
    Node* lastSorted = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->data.getTitle() > current->next->data.getTitle()) {
                // Swap data
                Book temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }

            current = current->next;
        }

        lastSorted = current;

    } while (swapped);
}

void Library::displayList() const {
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(50) << left << "| Title"
         << setw(30) << left << "| Author"
         << setw(10) << left << "| Year"
         << setw(15) << left << "| ISBN" << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;

    Node* current = head;

    while (current != nullptr) {
        current->data.displayBook();
        current = current->next;
    }

    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}

int main() {
    Library library;
    int choice;
    char yn1;
    string Title, Author, isbn;
    int Year;

    ifstream inputFile("book.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file: book.txt" << endl;
        return 1; // Exit with an error code
    }

    // Read books from the file and add them to the library
    int booksRead = 0;

    while (!inputFile.eof()) {
    getline(inputFile, Title, ',');
    getline(inputFile, Author, ',');
    inputFile >> Year;
    inputFile.ignore(); // Consume the newline character after reading the year
    getline(inputFile, isbn);
    Book newBook;
    newBook.setTitle(Title);
    newBook.setAuthor(Author);
    newBook.setYear(Year);
    newBook.setISBN(isbn);
    library.addNode(newBook);
    booksRead++;
}

    cout << "Number of books read: " << booksRead << endl;

    // Close the file
    inputFile.close();

    do {
        system("cls");
        cout << setw(39) << " ____________________________________" << endl;
        cout << setw(40) << "|                                    |" << endl;
        cout << setw(40) << "|       Welcome to DTD Library!      |" << endl;
        cout << setw(40) << "|____________________________________|" << endl << endl;

        cout << setw(5) << "[1] Add Book" << endl;
        cout << setw(5) << "[2] Find Book" << endl;
        cout << setw(5) << "[3] Delete Book" << endl;
        cout << setw(5) << "[4] Sort Books" << endl;
        cout << setw(5) << "[5] Display Books" << endl;
        cout << setw(5) << "[6] Exit" << endl << endl;

        cout << "Please enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1: {
                // Add Book
                Book newBook;
                cin.ignore(); // Ignore newline character from previous input
                cout << "Enter title: ";
                getline(cin, Title);
                newBook.setTitle(Title);
                cout << "Enter author: ";
                getline(cin, Author);
                newBook.setAuthor(Author);
                cout << "Enter year: ";
                cin >> Year;
                newBook.setYear(Year);
                cin.ignore(); // Ignore newline character from previous input
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                newBook.setISBN(isbn);

                library.addNode(newBook);
                cout << "Book added successfully!" << endl;
                break;
            }

            case 2: {
                // Find Book
                string searchKey;
                cout << "Enter title or ISBN to search: ";
                cin.ignore(); // Ignore newline character from previous input
                getline(cin, searchKey);
                Node* foundNode = library.findNode(searchKey);
                if (foundNode != nullptr) {
                    cout << "Book found: " << endl;
                    foundNode->data.displayBook();
                } else {
                    cout << "Book not found with title or ISBN: " << searchKey << endl;
                }
                break;
            }

            case 3: {
                // Delete Book
                string deleteKey;
                cout << "Enter title or ISBN to delete: ";
                cin >> deleteKey;
                library.deleteNode(deleteKey);
                cout << "Book deleted successfully!" << endl;
                break;
            }
            case 4:
                // Sort Books
                library.sortList();
                cout << "Books sorted successfully!" << endl;
                break;
            case 5:
                // Display Books
                library.displayList();
                break;
            case 6:
                // Exit
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "---------------------------------" << endl;

        cout << "Do you still want to use the program? (Y/N): ";
        cin >> yn1;

    } while (yn1 == 'Y' || yn1 == 'y');

    cout << "Thank you for using the program!" << endl;

    return 0;
}