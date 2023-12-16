#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#define N 16

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

    void setTitle(string t) {
        title = t;
    }

    void setAuthor(string a) {
        author = a;
    }

    void setYear(int y) {
        year = y;
    }

    void setISBN(string i) {
        ISBN = i;
    }
};

int readFile(Book book[], int& size) { // read data from file
    ifstream inputFile("Book.txt");
    string title, author, isbn;
    int year;
    int i = 0;

    if (inputFile.is_open()) {
        while (getline(inputFile, title, ',') && getline(inputFile >> ws, author, ',') && (inputFile >> year, true)) {
            inputFile.ignore();
            getline(inputFile >> ws, isbn);
            book[i].setTitle(title);
            book[i].setAuthor(author);
            book[i].setYear(year);
            book[i].setISBN(isbn);
            i++;
        }
        inputFile.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    size = i;
    return size;
}

// Sorting
void sortByTitle(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (books[i].getTitle() > books[j].getTitle()) {
                swap(books[i], books[j]);
            }
        }
    }
}

void sortByAuthor(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (books[i].getAuthor() > books[j].getAuthor()) {
                swap(books[i], books[j]);
            }
        }
    }
}

void sortByYear(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (books[i].getYear() > books[j].getYear()) {
                swap(books[i], books[j]);
            }
        }
    }
}

void sortByISBN(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (books[i].getISBN() > books[j].getISBN()) {
                swap(books[i], books[j]);
            }
        }
    }
}

// Print
void printBook(Book books[], int size) {
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(50) << left << "| Title"
         << setw(30) << left << "| Author"
         << setw(10) << left << "| Year"
         << setw(15) << left << "| ISBN" << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << setw(50) << left << "| " + books[i].getTitle()
             << setw(30) << left << "| " + books[i].getAuthor()
             << setw(10) << left << "| " + to_string(books[i].getYear())
             << setw(15) << left << "| " + books[i].getISBN() + "|" << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}

int main() {
    Book books[N];
    int choice, sortChoice;
    int size = 0;

    cout << setw(40) << " ____________________________________" << endl;
    cout << setw(40) << "|                                    |" << endl;
    cout << setw(40) << "|   Welcome to Sort/Search by DTD!   |" << endl;
    cout << setw(40) << "|____________________________________|" << endl << endl;

    cout << setw(15) << "[1] Sorting" << endl;
    cout << setw(17) << "[2] Searching" << endl << endl;

    cout << "Please enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        system("cls");
        cout << setw(40) << " ____________________________________" << endl;
        cout << setw(40) << "|                                    |" << endl;
        cout << setw(40) << "|              Sorting               |" << endl;
        cout << setw(40) << "|____________________________________|" << endl << endl;
        cout << setw(15) << "[1] Sort by Title" << endl;
        cout << setw(17) << "[2] Sort by Author" << endl;
        cout << setw(16) << "[3] Sort by Year" << endl;
        cout << setw(16) << "[4] Sort by ISBN" << endl << endl;

        cout << "Please enter your choice: ";
        cin >> sortChoice;

        readFile(books, size);

        switch (sortChoice) {
        case 1:
            sortByTitle(books, size);
            system("cls");
            cout << "Sorted Books (Title): " << endl;
            printBook(books, size);
            break;
        case 2:
            sortByAuthor(books, size);
            system("cls");
            cout << "Sorted Books (Author): " << endl;
            printBook(books, size);
            break;
        case 3:
            sortByYear(books, size);
            system("cls");
            cout << "Sorted Books (Year Published): " << endl;
            printBook(books, size);
            break;
        case 4:
            sortByISBN(books, size);
            system("cls");
            cout << "Sorted Books (ISBN): " << endl;
            printBook(books, size);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}
