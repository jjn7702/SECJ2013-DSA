#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define MAX_SIZE 100

using namespace std;

class Book
{
private:
    string title;
    string author;
    int year;
    string ISBN;

public:
    Book() : title(""), author(""), year(0), ISBN("") {}

    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getYear() { return year; }
    string getISBN() { return ISBN; }

    void setTitle(const string &t) { title = t; }
    void setAuthor(const string &a) { author = a; }
    void setYear(int y) { year = y; }
    void setISBN(const string &i) { ISBN = i; }

    void displayBook() const
    {
        cout << setw(50) << left << "| " + title
             << setw(30) << left << "| " + author
             << setw(10) << left << "| " + to_string(year)
             << setw(15) << left << "| " + ISBN + "|" << endl;
    }
};

class Stack
{
private:
    int top;
    Book book[MAX_SIZE];

public:
    Stack() : top(-1) {}

    void push(Book newBook)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top++;
            book[top] = newBook;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            top--;
        }
    }

    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top == MAX_SIZE - 1);
    }

    void readFromFile()
    {
        ifstream inputFile("book.txt");

        // Check if the file is open
        if (!inputFile.is_open())
        {
            cout << "Error opening file: book.txt" << endl;
        }

        // Read the file
        string Title, Author, isbn;
        int Year;

        while (!inputFile.eof())
        {
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

            push(newBook);
        }

        // Close the file
        inputFile.close();
    }

    void displayStack()
    {
        system("cls");
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(50) << left << "| Title"
             << setw(30) << left << "| Author"
             << setw(10) << left << "| Year"
             << setw(15) << left << "| ISBN" << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        for (int i = top; i >= 0; i--)
        {
            book[i].displayBook();
        }
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    }
};

int main()
{
    Stack bookStack;
    bookStack.readFromFile();

    int choice, stackChoice;

    //bookStack.displayStack();

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

    switch (choice)
    {
        case 1 :
            system("cls");
            cout << setw(39) << " ____________________________________" << endl;
            cout << setw(40) << "|                                    |" << endl;
            cout << setw(40) << "|             Staff Menu             |" << endl;
            cout << setw(40) << "|____________________________________|" << endl
                 << endl;

            cout << setw(5) << "[1] Add New Book (Push)" << endl;
            cout << setw(5) << "[2] Remove Book (Pop)" << endl;
            cout << setw(5) << "[3] Display Current List (DisplayStack)" << endl;
            cout << setw(5) << "[4] Back" << endl << endl;
            cout << "Please enter your choice : ";
            cin >> stackChoice;

            if(stackChoice == 1)
            {
                string title, author, isbn;
                int year;

                cout << "Enter the title of the book : ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter the author of the book : ";
                getline(cin, author);
                cout << "Enter the year of the book : ";
                cin >> year;
                cout << "Enter the ISBN of the book : ";
                cin.ignore();
                getline(cin, isbn);

                Book newBook;
                newBook.setTitle(title);
                newBook.setAuthor(author);
                newBook.setYear(year);
                newBook.setISBN(isbn);

                bookStack.push(newBook);
                bookStack.displayStack();
                cout << "Book has been added!" << endl;
            }
            else if(stackChoice == 2)
            {
                bookStack.pop();
                bookStack.displayStack();
                cout << "Book has been removed!" << endl;
                
            }
            else if(stackChoice == 3)
            {
                bookStack.displayStack();
            }
            else if(stackChoice == 4)
            {
                main();
            }
            else
            {
                cout << "Invalid input!" << endl;
            }
        break;

        case 2 :
        

        break;

        case 3 :
            cout << "Thank you for using DTD Library!" << endl;
            exit(0);
        break;

        default :
            cout << "Invalid input!" << endl;
        break;

    }

    return 0;
}
