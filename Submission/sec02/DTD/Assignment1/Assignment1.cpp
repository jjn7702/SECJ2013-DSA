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
        while (!inputFile.eof()) {
            getline(inputFile, title, ',');
            getline(inputFile >> ws, author, ',');
            inputFile >> year;
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

// Print Search Results
void displaySearchResultsHeader() {
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "| Index |" << setw(40) << "Title" << setw(25) << "Author" << setw(10) << "Year" << setw(15) << "ISBN" << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}

// Print Book Details of search results
void displayBookDetails(int index, const Book& book) {
    cout << "| " << setw(5) << index << " | " << setw(38) << book.getTitle() << " | " << setw(23) << book.getAuthor() << " | "
         << setw(8) << book.getYear() << " | " << setw(13) << book.getISBN() << " |" << endl;
} 

<<<<<<< Updated upstream
//Start Searching
=======
//Searching
>>>>>>> Stashed changes
void searchByTitle(Book books[], int size) {
    string title;
    bool found = false;
    cout << "Enter the title of the book: ";
    cin.ignore(); // ignore the newline character
    getline(cin, title); // read the title with spaces

    system("cls");
    cout << "Searched Books (Title): " << endl;
    displaySearchResultsHeader();

    for (int i = 0; i < size; i++) {
        if (books[i].getTitle() == title) {
            displayBookDetails(i + 1, books[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "No books found with the title: " << title << endl;
    }

    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}


void searchByAuthor(Book books[], int size) {
    string author;
    bool found = false;
    cout << "Enter the author of the book: ";
    cin.ignore(); // ignore the newline character
    getline(cin, author); // read the author with spaces

    system("cls");
    cout << "Searched Books (Author): " << endl;
    displaySearchResultsHeader();

    for (int i = 0; i < size; i++) {
        if (books[i].getAuthor() == author) { 
            displayBookDetails(i + 1, books[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found with the author: " << author << endl;
    }

    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}


void searchByYear(Book books[], int size) 
{
    int year;
    bool found = false;
    cout << "Enter the year of the book: ";
    cin >> year;

    system("cls");
    cout << "Searched Books (Year Published): " << endl;
    displaySearchResultsHeader();

    for (int i = 0; i < size; i++) {
        if (books[i].getYear() == year) {
           displayBookDetails(i + 1, books[i]);
            found = true;
        }
    }
    if (!found) {
       cout << "No books found in the year of: " << year << endl;
    }

    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}

void searchByISBN(Book books[], int size) {
    string isbn;
    bool found = false;
    cout << "Enter the ISBN of the book: ";
    cin.ignore(); // ignore the newline character
    getline(cin, isbn); // read the title with spaces

    system("cls");
    cout << "Searched Books (ISBN): " << endl;
    displaySearchResultsHeader();

    for (int i = 0; i < size; i++) {
        if (books[i].getISBN() == isbn) {
            displayBookDetails(i + 1, books[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found with the ISBN: " << isbn << endl;
    }

    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
} //end searching





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
    int choice, sortChoice, searchChoice;
    int size = 0;
    char yn1;


    system("cls");
    cout << setw(40) << " ____________________________________" << endl;
    cout << setw(40) << "|                                    |" << endl;
    cout << setw(40) << "|       Welcome to DTD Library!      |" << endl;
    cout << setw(40) << "|____________________________________|" << endl << endl;

    cout << setw(15) << "[1] Sorting" << endl;
    cout << setw(17) << "[2] Searching" << endl;
    cout << setw(17) << "[3] Book List" << endl << endl;


    cout << "Please enter your choice: ";
    cin >> choice;

//Start Sorting
    if (choice == 1) {
        system("cls");
        cout << setw(40) << " ____________________________________" << endl;
        cout << setw(40) << "|                                    |" << endl;
        cout << setw(40) << "|           Sorting Books            |" << endl;
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
        }//end sorting
    }
    else if (choice == 2)
    {
        system("cls");
        cout << setw(40) << " ____________________________________" << endl;
        cout << setw(40) << "|                                    |" << endl;
        cout << setw(40) << "|          Searching Books           |" << endl;
        cout << setw(40) << "|____________________________________|" << endl << endl;
        cout << setw(15) << "[1] Search by Title" << endl;
        cout << setw(17) << "[2] Search by Author" << endl;
        cout << setw(16) << "[3] Search by Year" << endl;
        cout << setw(16) << "[4] Search by ISBN" << endl << endl;

        cout << "Please enter your choice: ";
        cin >> searchChoice;

        readFile(books, size);

       switch (searchChoice) {
        case 1:
            searchByTitle(books, size);
            break;
        case 2:
            searchByAuthor(books, size);
            break;
        case 3:
            searchByYear(books, size);
            break;
        case 4:
            searchByISBN(books, size);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }//end searching
    }
    

    else if (choice == 3)
    {
        readFile(books, size);
        system("cls");
        cout << "List of Books: " << endl;
        printBook(books, size);
    }
    
    else 
    {
        cout << "Invalid choice" << endl;
    }

    system("pause");

        system("cls");
        cout << "Do you still want to use the program? (Y/N): ";
        cin >> yn1;

        if (yn1 == 'Y' || yn1 == 'y') {
            main();
        } else {
            cout << "Thank you for using the program!" << endl;
        }
    return 0;
}
