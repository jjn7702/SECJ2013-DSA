#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define MAX_SIZE 100

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    string ISBN;

public:
    Book() : title(""), author(""), year(0), ISBN("") {}

    string getTitle()  { return title; }
    string getAuthor()  { return author; }
    int getYear()  { return year; }
    string getISBN()  { return ISBN; }

    void setTitle(string& t) { title = t; }
    void setAuthor(string& a) { author = a; }
    void setYear(int y) { year = y; }
    void setISBN(string& i) { ISBN = i; }

    void displayBook() const {
        cout << setw(50) << left << "| " + title
             << setw(30) << left << "| " + author
             << setw(10) << left << "| " + to_string(year)
             << setw(15) << left << "| " + ISBN + "|" << endl;
    }
};

class Library {
private:
    Book stackArray[MAX_SIZE];
    int top;

public:
    Library() : top(-1) {}

    void pushBook(Book& book) {
        if (top < MAX_SIZE - 1) {
            stackArray[++top] = book;
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

    void displayStack() {
        system("cls");
        cout << "Books in the stack:\n";
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(50) << left << "| Title"
             << setw(30) << left << "| Author"
             << setw(10) << left << "| Year"
             << setw(15) << left << "| ISBN"
             << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        for (int i = top; i >= 0; i--) {
            stackArray[i].displayBook();
        }
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    }

    void enqueueRequest(string& patronName,string& bookTitle) {
        ofstream outputFile("PatronQueue.txt", ios::app);
        if (outputFile.is_open()) {
            outputFile << patronName << "," << bookTitle << endl;
            outputFile.close();
            cout << "Request added to the queue: " << patronName << " - " << bookTitle << endl;
        } else {
            cout << "Error opening file: PatronQueue.txt" << endl;
        }
    }

void dequeueRequest() {
    fstream file("PatronQueue.txt", ios::in | ios::out);

    if (file.is_open()) {
        string patronName, bookTitle;
        bool requestFound = false;

        ofstream tempFile("temp.txt", ios::app);

        while (getline(file, patronName, ',') && getline(file, bookTitle)) {
            if (!requestFound) {
                cout << "Patron request removed from the queue: " << patronName << " - " << bookTitle << endl;
                requestFound = true;
            } else {
                tempFile << patronName << "," << bookTitle << endl;
            }
        }

        if (!requestFound) {
            cout << "Queue is empty. No request to remove." << endl;
        }

        file.close();
        tempFile.close();

        remove("PatronQueue.txt");
        rename("temp.txt", "PatronQueue.txt");
    } else {
        cout << "Error opening file: PatronQueue.txt" << endl;
    }
}

    void displayQueue() {
        ifstream inputFile("PatronQueue.txt");
        if (inputFile.is_open()) {
            system("cls");
            cout << "Patron requests in the queue:\n\n";
            cout << "--------------------------------------------------" << endl;
            cout << "| " << setw(20) << left << "Patron Name" << " | " << setw(23) << left << "Requested Book Title" << " |" << endl;
            cout << "--------------------------------------------------" << endl;
            string patronName, bookTitle;
            while (getline(inputFile, patronName, ',') && getline(inputFile, bookTitle)) {
                cout << "| " << setw(20) << left << patronName << " | " << setw(23) << left << bookTitle << " |" << endl;
            }
            cout << "--------------------------------------------------" << endl;
            inputFile.close();
        } else {
            cout << "Error opening file: PatronQueue.txt" << endl;
        }
    }
};

int main() {
    Library library;
    int choice, stackChoice, queueChoice;
    char yn1;
    Book newBook;
    string Title, Author, ISBN, patronName, requestedBookTitle;
    int Year;
    ifstream inputFile("Book.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening file: Book.txt" << endl;
        return 1;
    }

    while (!inputFile.eof()) {
        getline(inputFile, Title, ',');
        getline(inputFile, Author, ',');
        inputFile >> Year;
        inputFile.ignore();
        getline(inputFile, ISBN);

        newBook.setTitle(Title);
        newBook.setAuthor(Author);
        newBook.setYear(Year);
        newBook.setISBN(ISBN);

        library.pushBook(newBook);
    }

    inputFile.close();

do {
    system("cls");
    cout << setw(39) << " ____________________________________" << endl;
    cout << setw(40) << "|                                    |" << endl;
    cout << setw(40) << "|       Welcome to DTD Library!      |" << endl;
    cout << setw(40) << "|____________________________________|" << endl
         << endl;

    cout << setw(5) << "[1] Staff (Stack)" << endl;
    cout << setw(5) << "[2] Patron (Queue)" << endl;
    cout << setw(5) << "[3] Exit" << endl << endl;
    cout << "Please enter your choice : ";
    cin >> choice;

    switch (choice) {
        case 1:
            system("cls");
            cout << setw(39) << " ____________________________________" << endl;
            cout << setw(40) << "|                                    |" << endl;
            cout << setw(40) << "|             Staff Menu             |" << endl;
            cout << setw(40) << "|____________________________________|" << endl
                 << endl;

            cout << setw(5) << "[1] Add New Book (Push)" << endl;
            cout << setw(5) << "[2] Remove Book (Pop)" << endl;
            cout << setw(5) << "[3] Display Current List (DisplayStack)" << endl;
            cout << setw(5) << "[4] Exit" << endl << endl;
            cout << "Please enter your choice : ";
            cin >> stackChoice;

            if (stackChoice == 1) {
                system("cls");
                cout << setw(39) << " ____________________________________" << endl;
                cout << setw(40) << "|                                    |" << endl;
                cout << setw(40) << "|             Add New Book           |" << endl;
                cout << setw(40) << "|____________________________________|" << endl << endl;

                cout << "Enter the book title : ";
                cin.ignore();
                getline(cin, Title);
                cout << "Enter the book author : ";
                getline(cin, Author);
                cout << "Enter the book year : ";
                cin >> Year;
                cout << "Enter the book ISBN : ";
                cin.ignore();
                getline(cin, ISBN);

                newBook.setTitle(Title);
                newBook.setAuthor(Author);
                newBook.setYear(Year);
                newBook.setISBN(ISBN);

                library.pushBook(newBook);
                cout << "Book added to the stack: " << newBook.getTitle() << endl;
                library.displayStack();
                system("pause");
            } else if (stackChoice == 2) {
                system("cls");
                cout << setw(39) << " ____________________________________" << endl;
                cout << setw(40) << "|                                    |" << endl;
                cout << setw(40) << "|             Delete Book            |" << endl;
                cout << setw(40) << "|____________________________________|" << endl << endl;
                library.popBook();
                library.displayStack();
                system("pause");
            } else if (stackChoice == 3) {
                library.displayStack();
            } else {
                cout << "Invalid input. Please try again." << endl;
                system("pause");
            }
            break;

        case 2:
            system("cls");
            cout << setw(39) << " ____________________________________" << endl;
            cout << setw(40) << "|                                    |" << endl;
            cout << setw(40) << "|             Patron Menu            |" << endl;
            cout << setw(40) << "|____________________________________|" << endl
                 << endl;

            cout << setw(5) << "[1] Add Request (Enqueue)" << endl;
            cout << setw(5) << "[2] Remove Request (Dequeue)" << endl;
            cout << setw(5) << "[3] Display Requests (DisplayQueue)" << endl;
            cout << setw(5) << "[4] Exit" << endl << endl;
            cout << "Please enter your choice : ";
            cin >> queueChoice;

            if (queueChoice == 1) {
                system("cls");
                cout << setw(39) << " ____________________________________" << endl;
                cout << setw(40) << "|                                    |" << endl;
                cout << setw(40) << "|           Add Patron Request        |" << endl;
                cout << setw(40) << "|____________________________________|" << endl << endl;

                cout << "Enter your name : ";
                cin.ignore();
                getline(cin, patronName);
                cout << "Enter the title of the book you want : ";
                getline(cin, requestedBookTitle);

                library.enqueueRequest(patronName, requestedBookTitle);
                library.displayQueue();
                system("pause");
            } else if (queueChoice == 2) {
                system("cls");
                cout << setw(39) << " ____________________________________" << endl;
                cout << setw(40) << "|                                    |" << endl;
                cout << setw(40) << "|         Remove Patron Request      |" << endl;
                cout << setw(40) << "|____________________________________|" << endl << endl;

                library.dequeueRequest();
                library.displayQueue();
                system("pause");
            } else if (queueChoice == 3) {
                library.displayQueue();
            } else {
                cout << "Invalid input. Please try again." << endl;
            }
            break;

        case 3:
            cout << "Exiting the program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid input. Please try again." << endl;
    }
    cout << "Do you still want to use the program? (Y/N): ";
    cin >> yn1;
} while (yn1 == 'Y' || yn1 == 'y');

    return 0;
}
