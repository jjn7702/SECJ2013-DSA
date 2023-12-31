#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Book
{
private:
    string title;
    string author;
    int year;
    string ISBN;

public:
    Book()
    {
        title = "";
        author = "";
        year = 0;
        ISBN = "";
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    int getYear()
    {
        return year;
    }

    string getISBN()
    {
        return ISBN;
    }

    void setTitle(string t)
    {
        title = t;
    }

    void setAuthor(string a)
    {
        author = a;
    }

    void setYear(int y)
    {
        year = y;
    }

    void setISBN(string i)
    {
        ISBN = i;
    }

    // Display book details
    void displayBook() const
    {
        cout << setw(50) << left << "| " + title
             << setw(30) << left << "| " + author
             << setw(10) << left << "| " + to_string(year)
             << setw(15) << left << "| " + ISBN + "|" << endl;
    }
};

// Node structure for the linked list
class Node
{
public:
    Book data;
    Node *next;
};

class Library
{
private:
    Node *head;
    int size;

public:
    // Constructor and destructor
    Library() : head(nullptr), size(0) {}
    ~Library()
    {
        // Destructor to free allocated memory
        Node *current = head;
        Node *next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    // Linked list operations
    void addBookfront(Book book)
    {
        Node *newNode = new Node{book, nullptr};

        // Insert at the beginning
        newNode->next = head;
        head = newNode;
    }

    void deleteBook(int nodeChoice)
    {
        Node *current = head;
        Node *prev = nullptr;

        switch (nodeChoice)
        {
        case 1:
            // Delete the front node
            if (head != nullptr)
            {
                head = current->next;
                delete current;
            }
            else
            {
                cout << "Library is empty. Cannot delete from the front." << endl;
            }
            break;

        case 2:
           // Delete a node in the middle
    if (head != nullptr)
    {
        int size = getSize();
        int middlePosition = (size + 1) / 2;

        if (middlePosition == 1)
        {
            // If there is only one node, treat it as deleting from the front
            head = current->next;
            delete current;
        }
        else if (size >= 3)
        {
            int currentPosition = 1;
            Node *prev = nullptr; // Initialize prev here

            // Traverse to the node before the middle position
            while (currentPosition < middlePosition - 1 && current->next)
            {
                prev = current;
                current = current->next;
                currentPosition++;
            }

            // Delete the node at the middle
            if (prev != nullptr)
            {
                prev->next = current->next;
                delete current;
            }
        }
        else
        {
            cout << "Not enough nodes to delete from the middle." << endl;
        }
        break;
        }

        case 3:
            // Delete the last node
            if (head != nullptr)
            {
                while (current->next != nullptr)
                {
                    prev = current;
                    current = current->next;
                }
                if (prev != nullptr)
                {
                    prev->next = nullptr;
                    delete current;
                }
                else
                {
                    // Only one node in the list
                    delete current;
                    head = nullptr;
                }
            }
            else
            {
                cout << "Library is empty. Cannot delete from the end." << endl;
            }
            break;

        default:
            cout << "Invalid choice. No node deleted." << endl;
        }
    }

    // Modify the findNode function to return a Node* instead of Node
    Node *findBook(string key)
    {
        Node *current = head;

        while (current != nullptr && (current->data.getTitle() != key && current->data.getISBN() != key))
        {
            current = current->next;
        }

        return current; // Return a pointer to the found node or nullptr if not found
    }

    void displayList()
    {
        system("cls");
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(50) << left << "| Title"
             << setw(30) << left << "| Author"
             << setw(10) << left << "| Year"
             << setw(15) << left << "| ISBN"
             << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;

        Node *current = head;

        while (current != nullptr)
        {
            current->data.displayBook();
            current = current->next;
        }

        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    }

    int getSize()
    {
        return size;
    }

    void addBookMiddle(Book book)
    {
        Node *newNode = new Node{book, nullptr};

        if (head == nullptr)
        {
            // If the list is empty, insert at the beginning
            newNode->next = head;
            head = newNode;
        }
        else
        {
            int size = getSize();
            int middlePosition = (size + 1) / 2;

            Node *current = head;
            int currentPosition = 1;

            // Traverse to the node before the middle position
            while (currentPosition < middlePosition - 1 && current->next)
            {
                current = current->next;
                currentPosition++;
            }

            // Insert at the middle or end
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void addBookEnd(Book book)
    {
        Node *newNode = new Node{book, nullptr};

        if (head == nullptr)
        {
            // If the list is empty, insert at the beginning
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *current = head;

            // Traverse to the last node
            while (current->next)
            {
                current = current->next;
            }

            // Insert at the end
            current->next = newNode;
        }
    }
    // Bubble sort function to sort books by title
    void sortBooksByTitle()
    {
        if (head == nullptr || head->next == nullptr)
        {
            // If the list is empty or has only one element, it's already sorted
            return;
        }

        bool swapped;
        Node *ptr;
        Node *lastPtr = nullptr;

        do
        {
            swapped = false;
            ptr = head;

            while (ptr->next != lastPtr)
            {
                if (ptr->data.getTitle() > ptr->next->data.getTitle())
                {
                    // Swap nodes if they are in the wrong order
                    Book temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;
                    swapped = true;
                }
                ptr = ptr->next;
            }
            lastPtr = ptr;
        } while (swapped);
    }


    // Function to sort books by author 
    void sortBooksByAuthor()
    {
        if (head == nullptr || head->next == nullptr)
        {
            // If the list is empty or has only one element, it's already sorted
            return;
        }

        bool swapped;
        Node *ptr;
        Node *lastPtr = nullptr;

        do
        {
            swapped = false;
            ptr = head;

            while (ptr->next != lastPtr)
            {
                if (ptr->data.getAuthor() > ptr->next->data.getAuthor())
                {
                    // Swap nodes if they are in the wrong order
                    Book temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;
                    swapped = true;
                }
                ptr = ptr->next;
            }
            lastPtr = ptr;
        } while (swapped);
    }
    void sortBooksByYear()
    {
        if (head == nullptr || head->next == nullptr)
        {
            // If the list is empty or has only one element, it's already sorted
            return;
        }

        bool swapped;
        Node *ptr;
        Node *lastPtr = nullptr;

        do
        {
            swapped = false;
            ptr = head;

            while (ptr->next != lastPtr)
            {
                if (ptr->data.getYear() > ptr->next->data.getYear())
                {
                    // Swap nodes if they are in the wrong order
                    Book temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;
                    swapped = true;
                }
                ptr = ptr->next;
            }
            lastPtr = ptr;
        } while (swapped);
    }
    void sortBooksByISBN()
    {
        if (head == nullptr || head->next == nullptr)
        {
            // If the list is empty or has only one element, it's already sorted
            return;
        }

        bool swapped;
        Node *ptr;
        Node *lastPtr = nullptr;

        do
        {
            swapped = false;
            ptr = head;

            while (ptr->next != lastPtr)
            {
                if (ptr->data.getISBN() > ptr->next->data.getISBN())
                {
                    // Swap nodes if they are in the wrong order
                    Book temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;
                    swapped = true;
                }
                ptr = ptr->next;
            }
            lastPtr = ptr;
        } while (swapped);
    }
};

int main()
{
    Library library;
    int choice, nodeChoice;
    char yn1;
    string Title, Author, isbn;
    int Year;

    ifstream inputFile("book.txt");

    // Check if the file is open
    if (!inputFile.is_open())
    {
        cout << "Error opening file: book.txt" << endl;
    }

    // Read books from the file and add them to the library
    int booksRead = 0;

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
        library.addBookEnd(newBook);
        booksRead++;
    }

    cout << "Number of books read: " << booksRead << endl;

    // Close the file
    inputFile.close();

    do
    {
        system("cls");
        cout << setw(39) << " ____________________________________" << endl;
        cout << setw(40) << "|                                    |" << endl;
        cout << setw(40) << "|       Welcome to DTD Library!      |" << endl;
        cout << setw(40) << "|____________________________________|" << endl
             << endl;

        cout << setw(5) << "[1] Add Book" << endl;
        cout << setw(5) << "[2] Find Book" << endl;
        cout << setw(5) << "[3] Delete Book" << endl;
        cout << setw(5) << "[4] Sort Books" << endl;
        cout << setw(5) << "[5] Display Books" << endl;
        cout << setw(5) << "[6] Exit" << endl
             << endl;

        cout << "Please enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << setw(39) << " ____________________________________" << endl;
            cout << setw(40) << "|                                    |" << endl;
            cout << setw(40) << "|              Add Node              |" << endl;
            cout << setw(40) << "|____________________________________|" << endl
                 << endl;

            cout << setw(5) << "[1] Add Book (Front)" << endl;
            cout << setw(5) << "[2] Add Book (Middle)" << endl;
            cout << setw(5) << "[3] Add Book (End)" << endl;

            cout << "Please enter your choice: ";
            cin >> nodeChoice;

            if (nodeChoice == 1)
            {
                // Add Book
                system("cls");
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
                getline(cin, isbn);
                newBook.setISBN(isbn);

                library.addBookfront(newBook);
                cout << "Book added successfully!" << endl;
                system("pause");

                library.displayList();
            }

            else if (nodeChoice == 2)
            {
                system("cls");
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
                getline(cin, isbn);
                newBook.setISBN(isbn);

                library.addBookMiddle(newBook);
                cout << "Book added successfully!" << endl;
                system("pause");

                library.displayList();
            }

            else if (nodeChoice == 3)
            {
                system("cls");
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
                getline(cin, isbn);
                newBook.setISBN(isbn);

                library.addBookEnd(newBook);
                cout << "Book added successfully!" << endl;
                system("pause");

                library.displayList();
            }

            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }

            break;
        }

        case 2:
        {
            // Find Book
            string searchKey;

            system("cls");
            cout << setw(39) << " ____________________________________" << endl;
            cout << setw(40) << "|                                    |" << endl;
            cout << setw(40) << "|              Find Book             |" << endl;
            cout << setw(40) << "|____________________________________|" << endl
                 << endl;

            cout << "Enter title or ISBN to search: ";
            cin.ignore();
            getline(cin, searchKey);

            Node *foundNode = library.findBook(searchKey);

            if (foundNode == nullptr)
            {
                cout << "Book not found with title or ISBN: " << searchKey << endl;
            }
            else
            {
                cout << "Book found: " << endl;
                foundNode->data.displayBook();
            }
            break;
        }
        case 3:
        {
            // Delete Book
            system("cls");
            int deleteChoice;
            cout << setw(39) << " ____________________________________" << endl;
            cout << setw(40) << "|                                    |" << endl;
            cout << setw(40) << "|             Delete Book            |" << endl;
            cout << setw(40) << "|____________________________________|" << endl
                 << endl;

            cout << "[1] Delete Front Book" << endl;
            cout << "[2] Delete Middle Book" << endl; // Add more options as needed
            cout << "[3] Delete End Book" << endl;

            cout << "Please enter your choice: ";
            cin >> deleteChoice;

            if (deleteChoice == 1 || deleteChoice == 2 || deleteChoice == 3)
            {
                cout << "Book deleted successfully!" << endl;
                system("pause");
                library.deleteBook(deleteChoice);
                library.displayList();
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }

            break;
        }
        case 4:
            // Sort Books
            int sortChoice;

            system("cls");
            cout << "Sort by:" << endl;
            cout << "[1] Title" << endl;
            cout << "[2] Author" << endl;
            cout << "[3] Year" << endl;
            cout << "[4] ISBN" << endl;
            cout << "Enter your choice: ";
            cin >> sortChoice;

            switch (sortChoice)
            {
            case 1:
                library.sortBooksByTitle();
                library.displayList();
                break;
            case 2:
                library.sortBooksByAuthor();
                library.displayList();
                break;
            case 3:
                library.sortBooksByYear();
                library.displayList();
                break;
            case 4:
                library.sortBooksByISBN();
                library.displayList();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
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