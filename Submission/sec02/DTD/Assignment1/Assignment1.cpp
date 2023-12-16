#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int MAX_BOOKS = 10; // Adjust the maximum number of books as needed

class Book {
public:
    string title;
    string author;
    int publicationYear;
    string ISBN;

    // Default Constructor
    Book() : title(""), author(""), publicationYear(0), ISBN("") {}

    // Parameterized Constructor
    Book(const string& t, const string& a, int year, const string& isbn)
        : title(t), author(a), publicationYear(year), ISBN(isbn) {}
};

// Function to display a book
void displayBook(const Book& book) {
    cout << "Title: " << book.title << ", Author: " << book.author
         << ", Year: " << book.publicationYear << ", ISBN: " << book.ISBN << endl;
}

// Function to swap two books
void swapBooks(Book& a, Book& b) {
    Book temp = a;
    a = b;
    b = temp;
}

// Function to sort books based on user's choice using bubble sort
void sortBooks(Book books[], int size, int option) {
    switch (option) {
        case 1:
            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < size - i - 1; ++j) {
                    if (books[j].title > books[j + 1].title) {
                        swapBooks(books[j], books[j + 1]);
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < size - i - 1; ++j) {
                    if (books[j].author > books[j + 1].author) {
                        swapBooks(books[j], books[j + 1]);
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < size - i - 1; ++j) {
                    if (books[j].publicationYear > books[j + 1].publicationYear) {
                        swapBooks(books[j], books[j + 1]);
                    }
                }
            }
            break;
        case 4:
            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < size - i - 1; ++j) {
                    if (books[j].ISBN > books[j + 1].ISBN) {
                        swapBooks(books[j], books[j + 1]);
                    }
                }
            }
            break;
        default:
            cout << "Invalid option" << endl;
    }
}

// Function to print books in tabular format
void printBooks(const Book books[], int size) {
    cout << "<<< Sorted Books >>>" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(50) << left << "| Title"
         << setw(30) << left << "| Author"
         << setw(10) << left << "| Year"
         << setw(15) << left << "| ISBN" << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << setw(50) << left << "| " + books[i].title
             << setw(30) << left << "| " + books[i].author
             << setw(10) << left << "| " + to_string(books[i].publicationYear)
             << setw(15) << left << "| " + books[i].ISBN + "|" << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}

// Function to search for a book based on user's choice
void searchBooks(const Book books[], int size, int option, const string& key) {
    switch (option) {
        case 1:
            // Search by title
            for (int i = 0; i < size; ++i) {
                if (books[i].title == key) {
                    displayBook(books[i]);
                    return;
                }
            }
            cout << "Book with title '" << key << "' not found." << endl;
            break;
        case 2:
            // Implement search logic for other options (e.g., by author)
            break;
        case 3:
            // Implement search logic for other options (e.g., by publication year)
            break;
        case 4:
            // Implement search logic for other options (e.g., by ISBN)
            break;
        default:
            cout << "Invalid option" << endl;
    }
}

int main() {
    // Read books from file
    ifstream inputFile("book.txt");
    Book books[MAX_BOOKS];
    int numBooks = 0;

    if (inputFile.is_open()) {
        string title, author, isbn;
        int year;

        while (getline(inputFile, title, ',') &&
               getline(inputFile >> ws, author, ',') &&
               (inputFile >> year, true) &&
               getline(inputFile >> ws, isbn)) {
            books[numBooks++] = Book(title, author, year, isbn);
        }
        inputFile.close();
    } else {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    // Calculate the actual number of books in the array
    numBooks = sizeof(books) / sizeof(books[0]);

    // Display menu for user to choose between sorting and searching
    int operationOption;
    cout << "<<< Library Management System >>>" << endl;
    cout << "[1] Sort Books" << endl;
    cout << "[2] Search Books" << endl;
    cout << "Option: ";
    cin >> operationOption;

    if (operationOption == 1) {
        // Display menu for sorting
        int sortingOption;
        cout << "<<< Sorting Process >>>" << endl;
        cout << "[1] By title" << endl;
        cout << "[2] By author" << endl;
        cout << "[3] By publication year" << endl;
        cout << "[4] By ISBN" << endl;
        cout << "Option: ";
        cin >> sortingOption;

        // Sort books based on user's choice
        sortBooks(books, numBooks, sortingOption);

        // Print the sorted books
        printBooks(books, numBooks);
    } else if (operationOption == 2) {
        // Display menu for searching
        int searchingOption;
        string searchKey;
        cout << "<<< Searching Process >>>" << endl;
        cout << "[1] By title" << endl;
        cout << "[2] By author" << endl;
        cout << "[3] By publication year" << endl;
        cout << "[4] By ISBN" << endl;
        cout << "Option: ";
        cin >> searchingOption;
        cout << "Enter search key: ";
        cin >> searchKey;

        // Search for a book based on user's choice
        searchBooks(books, numBooks, searchingOption, searchKey);
    } else {
        cout << "Invalid option" << endl;
    }

    return 0;
}
