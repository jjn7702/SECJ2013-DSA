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

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    string getISBN() const { return ISBN; }

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

class Node
{
public:
    Book data;
    Node *next;

    Node(const Book &b) : data(b), next(nullptr) {}
};

class Stack
{
private:
    int top;
    Book book[MAX_SIZE];

public:
    Stack() : top(-1) {}

    void push(const Book &newBook)
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

        if (!inputFile.is_open())
        {
            cout << "Error opening file: book.txt" << endl;
        }

        string Title, Author, isbn;
        int Year;

        while (!inputFile.eof())
        {
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

            push(newBook);
        }

        inputFile.close();
    }

    void displayStack() const
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

class Queue
{
private:
    Node *front, *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const
    {
        return (front == nullptr);
    }

    void enqueue(const Book &newBook)
    {
        Node *newNode = new Node(newBook);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Book added to the queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;

            if (front == nullptr)
            {
                rear = nullptr;
            }

            delete temp;

            cout << "Book request has been approved!" << endl;
        }
    }

    void displayQueueFront() const {
        if (!isEmpty()) {
            cout << "First borrow request in the queue:\n";
            cout << "- [" << front->data.getTitle() << " requested by " << front->data.getAuthor() << "] " << endl;
          
        } else {
            cout << "Queue is empty.\n";
        }
    }

    void displayQueue() const
    {
        if (isEmpty())
        {
            system("cls");
            cout << "Queue is empty." << endl;
        }
        else
        {
            system("cls");
            cout << "Books in the queue:" << endl;
            Node *current = front;
            while (current != nullptr)
            {
                cout << "- [" << current->data.getTitle() << " requested by " << current->data.getAuthor() << "] " << endl;
                current = current->next;
            }
            cout << endl;
        }
    }

    void readFromFile()
{
    ifstream inputFile("borrowqueue.txt");

    if (!inputFile.is_open())
    {
        cout << "Error opening file: borrowqueue.txt" << endl;
        return;
    }

    string line;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string patronName, title;

        if (getline(ss, patronName, ',') && getline(ss, title))
        {
            Book requestedBook;
            requestedBook.setTitle(title);
            requestedBook.setAuthor(patronName);
            enqueue(requestedBook);
        }
        else
        {
            cout << "Error reading line from file: " << line << endl;
        }
    }

    inputFile.close();
}

    void writeToBorrowQueueFile(const Book &newBook)
    {
        ofstream outputFile("borrowqueue.txt", ios::app);

        if (!outputFile.is_open())
        {
            cout << "Error opening file: borrowqueue.txt" << endl;
        }

        outputFile << newBook.getAuthor() << "," << newBook.getTitle() << endl;

        outputFile.close();
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    Stack bookStack;
    Queue patronQueue;
    bookStack.readFromFile();
    patronQueue.readFromFile();

    int choice;
    char yn;
    int queueChoice;

    do
    {
        system("cls");
        cout << setw(39) << " ____________________________________" << endl;
        cout << setw(40) << "|                                    |" << endl;
        cout << setw(40) << "|       Welcome to DTD Library!      |" << endl;
        cout << setw(40) << "|____________________________________|" << endl
             << endl;

        cout << setw(5) << "[1] Staff (Stack)" << endl;
        cout << setw(5) << "[2] Patron (Queue)" << endl;
        cout << setw(5) << "[3] Exit" << endl
             << endl;
        cout << "Please enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
           system("cls");
        int stackChoice;
        cout << setw(39) << " ____________________________________" << endl;
        cout << setw(40) << "|                                    |" << endl;
        cout << setw(40) << "|             Staff Menu             |" << endl;
        cout << setw(40) << "|____________________________________|" << endl
             << endl;

        cout << setw(5) << "[1] Add New Book (Push)" << endl;
        cout << setw(5) << "[2] Remove Book (Pop)" << endl;
        cout << setw(5) << "[3] Display Current List (DisplayStack)" << endl;
        cout << setw(5) << "[4] Approve Borrow Request" << endl ;
        cout << setw(5) << "[5] Display Borrow Requests" << endl ;
        cout << setw(5) << "[6] Back" << endl;
        cout << "Please enter your choice : ";
        cin >> stackChoice;

        if (stackChoice == 1)
        {
            string title, author, isbn;
            int year;

            system("cls");
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
        else if (stackChoice == 2)
        {
             bookStack.pop();
             bookStack.displayStack();
            cout << "Book has been removed!" << endl;
        }
        else if (stackChoice == 3)
        {
             bookStack.displayStack();
        }
        else if (stackChoice == 4)
        {
                
                patronQueue.displayQueueFront();
                system("pause");
                patronQueue.dequeue();
                system("pause");
                patronQueue.displayQueue();
                system("pause");
        }
        else if (stackChoice == 5)
        {
                
                patronQueue.displayQueue();
                system("pause");
        }
        else if (stackChoice == 6)
        {
            main();
        }

        else
        {
            cout << "Invalid input!" << endl;
        }
            break;

        case 2:
            system("cls");

            cout << setw(39) << " ____________________________________" << endl;
            cout << setw(40) << "|                                    |" << endl;
            cout << setw(40) << "|            Patron Menu             |" << endl;
            cout << setw(40) << "|____________________________________|" << endl
                 << endl;

            cout << setw(5) << "[1] Request a Book (Enqueue)" << endl;
            cout << setw(5) << "[2] Display Current Requests (DisplayQueue)" << endl;
            cout << setw(5) << "[3] Back" << endl
                 << endl;
            cout << "Please enter your choice : ";
            cin >> queueChoice;

            if (queueChoice == 1)
            {
                system("cls");
                string patronName, title;
                bookStack.displayStack();
                cout << "\nEnter your name : ";
                cin.ignore();
                getline(cin, patronName);
                cout << "Enter the title of the requested book : ";
                getline(cin, title);

                Book requestedBook;
                requestedBook.setTitle(title);
                requestedBook.setAuthor(patronName); // Using Author field to store patron name for tracking
                patronQueue.enqueue(requestedBook);
                patronQueue.writeToBorrowQueueFile(requestedBook);
                patronQueue.displayQueue();
                cout << "Book request added!" << endl;
            }
            else if (queueChoice == 2)
            {
                patronQueue.displayQueue();
            }
            else if (queueChoice == 3)
            {
                main();
            }
            else
            {
                cout << "Invalid input!" << endl;
            }
            break;

        case 3:
            system("cls");
            cout << "Thank you for using DTD Library!" << endl;
            break;

        default:
            system("cls");
            cout << "Invalid input!" << endl;
            break;
        }

        cout << "Do you still want to use the system? (Y/N) : ";
        cin >> yn;

    } while (yn == 'Y' || yn == 'y');

    return 0;
}
