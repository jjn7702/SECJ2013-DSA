// Assignment 2 - SECJ2013 - 23241 (Assg2.cpp)
// Group Members:
// 1. Muhammad Iman Firdaus Bin Baharuddin A22EC0216
// 2. Muhammad Ariff Danish Bin Hashnan A22EC0204
// 3. Che Marhumi Bin Che AB Rahim A22EC0147
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


// Task (Chemi) --------> Function LinkedList & int main (Part LinkedList)
///-----------------------------------------------CLASS CUSTOMER----------------------------------------------------------------///
class Cust
{
private:
    string name, destination, airlines;
    int day, month, years;
    int count; // edit

public:
    Cust(string n, int d, int m, int y, string dest, string a)
    {
        name = n;
        day = d;
        month = m;
        years = y;
        destination = dest;
        airlines = a;
    }

    void printResult(int count)
    {
        cout << "\t\t\t" << left << setw(5) << count << setw(15) << name << setw(2) << day << " / " << setw(2) << month
             << " / " << setw(15) << years << setw(19) << destination << setw(19) << airlines << endl;
    }

    void printSearch(int date)
    {
        cout << left << setw(5) << setw(15) << getName() << setw(2) << day << " / " << setw(2) << month
             << " / " << setw(15) << years << setw(20) << destination << setw(5) << airlines << endl;
    }

    int getdate()
    {
        return day + years * 10000 + month * 100;
    }

    string getName()
    {
        return name;
    }

    string getDestination()
    {
        return destination;
    }

    string getAirlines()
    {
        return airlines;
    }
};
///-----------------------------------------------END OF CLASS CUSTOMER----------------------------------------------------------------///

///-----------------------------------------------CLASS NODE----------------------------------------------------------------///
class Node
{
public:
    Cust *data;
    Node *next;

    Node(Cust *c) : data(c), next(nullptr) {}
};
///-----------------------------------------------END OF CLASS NODE----------------------------------------------------------------///

///-----------------------------------------------CLASS LINKEDLIST----------------------------------------------------------------///
class LinkedList
{
private:
    Node *head;
    int count;       // get number of customer updated after add or delete
    int initialSize; // get size form file

public:
    LinkedList() : head(nullptr), count(0), initialSize(0) {}

    ~LinkedList()
    {
        Node *current = head;
        Node *next;

        while (current != nullptr)
        {
            next = current->next;
            delete current->data; // Free Cust object
            delete current;       // Free Node
            current = next;
        }
    }

    int updatedSize() // edit
    {
        int MAX = count + initialSize;

        return MAX;
    }

    int getInitialSize(int n) // edit
    {
        return initialSize = n;
    }

    int getNodeCount() // edit
    {
        return count;
    }

    void addNode(Cust *cust) // use just to add node from file
    {
        Node *newNode = new Node(cust);
        newNode->next = head;
        head = newNode;
    }

    void listcust()
    {
        Node *current = head;
        int i = 1;

        while (current != nullptr)
        {
            current->data->printResult(i);
            current = current->next;
            i++;
        }
    }

    ///-----------------------------------------------FUNCTION TO ADD NEW CUSTOMER TO THE LIST----------------------------------------------------------------///
    void addToBeginning(Cust *cust)
    {
        Node *newNode = new Node(cust);
        newNode->next = head;
        head = newNode;
        count++;
    }

    void addToMiddle(Cust *cust, int position)
    {
        if (position < 1 || position >= updatedSize())
        {
            cout << "\n\t\t\t\t\t\tInvalid position." << endl;
            cout <<"\t\t\t\t\t\tCannot add customer." << endl;
            return;
        }

        Node *newNode = new Node(cust);
        Node *current = head;

        for (int i = 1; i < position && current != nullptr; ++i)
        {
            current = current->next;
        }

        if (current != nullptr)
        {
            newNode->next = current->next;
            current->next = newNode;
            count++;
            cout << "\n\t\t\t\t\t\tCustomer added successfully." << endl;
        }
    }

    void addToEnd(Cust *cust)
    {
        Node *newNode = new Node(cust);
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }

        last->next = newNode;
        count++;
    }
    ///-----------------------------------------------END OF FUNCTION TO ADD CUSTOMER----------------------------------------------------------------///

    ///-----------------------------------------------FUNCTION TO DELETE CUSTOMER FROM THE LIST----------------------------------------------------------------///
    void deleteFromBeginning()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
            count--;
        }
        else
        {
            cout << "\n\t\t\t\t\t\tList is empty. Cannot delete." << endl;
        }
    }

    void deleteFromMiddle(int position)
    {
        if (head == nullptr)
        {
            cout << "\n\t\t\t\t\t\tList is empty. Cannot delete." << endl;
            return;
        }

        if (position <= 1 || position >= updatedSize())
        {
            cout << "\n\t\t\t\t\t\tInvalid position. Cannot delete." << endl;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;

        for (int i = 1; i < position && current != nullptr; ++i)
        {
            prev = current;
            current = current->next;
        }

        if (current != nullptr)
        {
            prev->next = current->next;
            delete current->data;
            delete current;
            count--;
            cout << "\n\t\t\t\t\t\tCustomer deleted successfully." << endl;
        }
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "\n\t\t\t\t\t\tList is empty. Cannot delete." << endl;
            return;
        }

        if (head->next == nullptr) // check if there is only one node in the list
        {
            delete head->data;
            delete head;
            head = nullptr;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;

        while (current->next != nullptr)
        {
            prev = current;
            current = current->next;
        }

        prev->next = nullptr;
        delete current->data;
        delete current;
        count--;
    }
    ///-----------------------------------------------END OF FUNCTION TO DELETE CUSTOMER----------------------------------------------------------------///


// Task (Ariff) --------> Function Searching & int main (Part Searching)
  vector<Node *> findNode(const string &searchKey, int searchType)
    {
        Node *current = head;
        vector<Node *> matchNode;

        while (current != nullptr)
        {
            bool isMatch = false;
            
            //convert the key to uppercase or lowercase when user accidently enter wrong char
            string lowerSearchKey = searchKey;
            transform(lowerSearchKey.begin(), lowerSearchKey.end(), lowerSearchKey.begin(), ::tolower);

            string lowerName = current->data->getName();
            transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

            if (searchType == 1 && lowerName.find(lowerSearchKey) != string::npos )
            {
                isMatch = true;
            }

            if (searchType == 2 && current->data->getDestination() == searchKey)
            {
                isMatch = true;
            }

            if (searchType == 3 && current->data->getAirlines() == searchKey)
            {
                isMatch = true;
            }

            if (searchType == 4)
            {
                // Extract day, month, and year from the stored date using getdate()
                int storedDate = current->data->getdate();
                int storedYear = storedDate / 10000;
                int storedMonth = (storedDate / 100) % 100;
                int storedDay = storedDate % 100;
                // Extract day, month, and year from the search key
                int searchDay, searchMonth, searchYear;
                char dot1, dot2;
                stringstream dateStream(searchKey);
                dateStream >> searchDay >> dot1 >> searchMonth >> dot2 >> searchYear;

                // Check if the extracted values match
                if (!dateStream.fail() &&
                    dot1 == '.' && dot2 == '.' &&
                    storedDay == searchDay && storedMonth == searchMonth && storedYear == searchYear)
                {
                    isMatch = true;
                }
            }

            if (isMatch)
            {
                matchNode.push_back(current);
            }
            current = current->next;
        }

        return matchNode;
    }

// Task (Iman) --------> Function Sorting & int main (Part Sorting)

 void bubbleSortByName()
    {
        bool swapped;
        Node *ptr1;
        Node *lptr = nullptr;

        if (head == nullptr)
            return;

        do
        {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr)
            {
                if (ptr1->data->getName() > ptr1->next->data->getName())
                {
                    // Swap data of adjacent nodes
                    Cust *temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;

                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void bubbleSortByAirline()
    {
        bool swapped;
        Node *ptr1;
        Node *lptr = nullptr;

        if (head == nullptr)
            return;

        do
        {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr)
            {
                if (ptr1->data->getAirlines() > ptr1->next->data->getAirlines())
                {
                    // Swap data of adjacent nodes
                    Cust *temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;

                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void bubbleSort()
    {
        // Provide options for sorting by name or airline
        int sortChoice;
        cout << "\t\t\t\t\t\t1. Sort by Name\n\t\t\t\t\t\t2. Sort by Airline\n\t\t\t\t\t\tEnter your choice: ";
        cin >> sortChoice;

        switch (sortChoice)
        {
        case 1:
            bubbleSortByName();
            break;
        case 2:
            bubbleSortByAirline();
            break;
        default:
            cout << "\t\t\t\t\t\tInvalid choice." << endl;
        }
    }

    void displayAllNodes()
    {
        Node *current = head;
        int count;

        while (current != nullptr)
        {
            current->data->printResult(count);
            current = current->next;
        }
    }
};

int main()
{
    LinkedList custList;
    string line;
    int count, size;

    fstream fileIn("booking.txt", ios::in);

    if (!fileIn)
    {
        cout << "File input/output error!\n";
        return 1;
    }
    else
    {
        while (getline(fileIn, line))
        {
            // Use stringstream to parse the line
            stringstream ss(line);
            string name, destination, airlines, dateStr;
            int day, month, years;

            // Read the name

            ss >> name;
            while (ss >> ws && !isdigit(ss.peek()))
            {
                // Append subsequent words to the name
                string word;
                ss >> word;
                name += ' ' + word;
            }

            // Read the date and other details
            ss >> day;
            ss.ignore(); // Ignore the dot
            ss >> month;
            ss.ignore(); // Ignore the dot
            ss >> years;

            ss >> destination >> airlines;

            if (!ss.fail())
            {
                // Adding/extract infomation from booking.txt to list
                custList.addNode(new Cust(name, day, month, years, destination, airlines));
                size++; // edit
            }
            else
            {
                cout << "Invalid date format in line: " << line << endl;
            }
        }
    }

    int position; // edit
    int choice;

    custList.getInitialSize(size - 2);
    do
    {
        cout << "\n\t\t\t\t   +================== MAIN MENU ===================+" << endl;
        cout << "\t\t\t\t   +1. \t\tAdd a new customer"
             << "\t\t    +" << endl;
        cout << "\t\t\t\t   +2. \t\tDelete a customer"
             << "\t\t    +" << endl;
        cout << "\t\t\t\t   +3. \t\tFind a customer"
             << "\t\t\t    +" << endl;
        cout << "\t\t\t\t   +4. \t\tSort the list"
             << "\t\t\t    +" << endl;
        cout << "\t\t\t\t   +5. \t\tDisplay all customer"
             << "\t\t    +" << endl;
        cout << "\t\t\t\t   +6. \t\tExit"
             << "\t\t\t\t    +" << endl;
        cout << "\t\t\t\t   +================================================+" << endl;
        cout << "\n\n\t\t\t\t\t\tEnter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        ///-----------------------------------------------CODE TO ADD CUSTOMER TO THE LIST----------------------------------------------------------------///    
        case 1:
        {
            // Add a new node
            // Provide options for adding at the beginning, middle, or end
            int addChoice;
            cout << "\t\t\t\t\t\t1. Add at the beginning\n\t\t\t\t\t\t2. Add at the middle\n\t\t\t\t\t\t3. Add at the end\n\n\t\t\t\t\t\tEnter your choice: ";
            cin >> addChoice;

            string newName, newDestination, newAirlines;
            int newDay, newMonth, newYear;

            cout << "\n\t\t\t\t\t\tEnter name: ";
            cin.ignore(); // Clear the newline character from the previous input
            getline(cin, newName);

            cout << "\n\t\t\t\t\t\tEnter date (day month year): " << endl;
            cout << "\n\t\t\t\t\t\tDay (eg : 12): ";
            cin >> newDay;
            cout << "\t\t\t\t\t\tMonth (eg : 6) : ";
            cin >> newMonth;
            cout << "\t\t\t\t\t\tYear (eg : 2002): ";
            cin >> newYear;

            cout << "\n\t\t\t\t\t\tEnter destination" << endl;
            cout << "\t\t\t\t\t\t(Attention! Case Sensitive): ";
            cin >> newDestination;

            cout << "\n\t\t\t\t\t\tEnter airlines" << endl;
            cout << "\t\t\t\t\t\t(Attention! Case Sensitive): ";
            cin >> newAirlines;

            Cust *newCust = new Cust(newName, newDay, newMonth, newYear, newDestination, newAirlines);

            switch (addChoice)
            {
            case 1:
                custList.addToBeginning(newCust);
                cout << "\n\t\t\t\t\t\tCustomer added successfully." << endl;
                break;
            case 2:
                // int position;
                cout << "\n\t\t\t\t\t\tAdd after position: ";
                cin >> position;
                custList.addToMiddle(newCust, position);
                break;
            case 3:
                custList.addToEnd(newCust);
                cout << "\n\t\t\t\t\t\tCustomer added successfully." << endl;
                break;
            default:
                cout << "\t\t\t\t\t\tInvalid choice." << endl;
            }

            break;
        }
        ///-----------------------------------------------END OF CODE TO ADD CUSTOMER TO THE LIST----------------------------------------------------------------///
        
        ///-----------------------------------------------CODE TO DELETE CUSTOMER IN THE LIST----------------------------------------------------------------///
        case 2:
        {
            // Delete a node
            // Provide options for deleting from the beginning, middle, or end
            int deleteChoice;
            cout << "\t\t\t\t\t\t1. Delete from the beginning\n\t\t\t\t\t\t2. Delete from the middle\n\t\t\t\t\t\t3. Delete from the end\n\n\t\t\t\t\t\tEnter your choice: ";
            cin >> deleteChoice;

            switch (deleteChoice)
            {
            case 1:
                custList.deleteFromBeginning();
                cout << "\n\t\t\t\t\t\tCustomer deleted successfully." << endl;
                break;
            case 2:
                // int position;
                cout << "\n\t\t\t\t\t\tEnter position: ";
                cin >> position;
                custList.deleteFromMiddle(position);
                break;
            case 3:
                custList.deleteFromEnd();
                cout << "\n\t\t\t\t\t\tCustomer deleted successfully." << endl;
                break;
            default:
                cout << "\n\t\t\t\t\t\t[Invalid choice.]!!!!" << endl;
            }
        
            break;
        }
        ///-----------------------------------------------END OF CODE TO DELETE CUSTOMER TO THE LIST----------------------------------------------------------------///
 
                                                //Task (Ariff) 
///-----------------------------------------------CODE TO START THE SEARCHING IN THE LIST----------------------------------------------------------------///
        case 3: // search
        {
            int searchKey;

            do
            {
                cout << "\n\t\t\t\t   +================== SEARCH MENU ===================+" << endl;
                cout << "\t\t\t\t   +1. \t\tSearch Customer by Name"
                     << "\t\t      +" << endl;
                cout << "\t\t\t\t   +2. \t\tSearch Customer by Destination"
                     << "\t      +" << endl;
                cout << "\t\t\t\t   +3. \t\tSearch Customer by Airline"
                     << "\t      +" << endl;
                cout << "\t\t\t\t   +4. \t\tSearch Customer by Date"
                     << "\t\t      +" << endl;
                cout << "\t\t\t\t   +5. \t\tExit"
                     << "\t\t\t\t      +" << endl;
                cout << "\t\t\t\t   +==================================================+" << endl;
                cout << "\n\n\t\t\t\t\t\tEnter your choice: ";
                cin >> searchKey;

                switch (searchKey)
                {
                case 1:
                {
                    // Search Customer by Name
                    string searchName;
                    cout << "\t\t\t\t\t\tEnter the name to search: ";
                    cin.ignore(); // Clear the newline character from the previous input
                    getline(cin, searchName);

                    vector<Node *> matchNode = custList.findNode(searchName, 1);

                    if (!matchNode.empty())
                    {
                        cout << "\n\n\t\t\t\t\t\tCustomer found:" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                        cout << left << setw(5) << setw(15) << "\t\t\tName"
                             << "Date of Booking"
                             << " \t \tDestination"
                             << "\t    Airlines" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;

                        for (Node *current : matchNode)
                        {
                            cout << "\t\t\t";
                            current->data->printSearch(current->data->getdate());
                        }

                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\t\tCustomer not found." << endl;
                    }
                    break;
                }

                case 2:
                {
                    // Search Customer by destination
                    string searchDest;
                    cout << "\n\t\t\t\t\t\tEnter the destination to search" << endl;
                    cout << "\t\t\t\t\t\t(Attention! Case Sensitive): ";
                    cin.ignore(); // Clear the newline character from the previous input
                    getline(cin, searchDest);

                    vector<Node *> matchNode = custList.findNode(searchDest, 2);

                    if (!matchNode.empty())
                    {
                        cout << "\n\t\t\t\t\t\tCustomer found:" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                        cout << left << setw(5) << setw(15) << "\t\t\tName"
                             << "Date of Booking"
                             << " \t \tDestination"
                             << "\t    Airlines" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;

                        for (Node *current : matchNode)
                        {
                            cout << "\t\t\t";
                            current->data->printSearch(current->data->getdate());
                        }

                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\t\tCustomer not found." << endl;
                    }
                    break;
                }

                case 3:
                {
                    // Search Customer by Airline
                    string searchAir;
                    cout << "\n\t\t\t\t\t\tEnter the Airline to search" << endl;
                    cout << "\t\t\t\t\t\t(Attention! Case Sensitive): ";
                    cin.ignore(); // Clear the newline character from the previous input
                    getline(cin, searchAir);

                    vector<Node *> matchNode = custList.findNode(searchAir, 3);

                    if (!matchNode.empty())
                    {
                        cout << "\n\t\t\t\t\t\tCustomer found:" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                        cout << left << setw(5) << setw(15) << "\t\t\tName"
                             << "Date of Booking"
                             << " \t \tDestination"
                             << "\t    Airlines" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;

                        for (Node *current : matchNode)
                        {
                            cout << "\t\t\t";
                            current->data->printSearch(current->data->getdate());
                        }

                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\t\tCustomer not found." << endl;
                    }
                    break;
                }

                case 4:
                {
                    // Search Customer by Date
                    string searchDate;
                    cout << "\t\t\t\t\t\tEnter the date to search" << endl;
                    cout << "\t\t\t\t\t(in the format dd.mm.yyyy): ";
                    cin >> searchDate;

                    int day, month, year;
                    char dot1, dot2;
                    stringstream dateStream(searchDate);

                    if (!(dateStream >> day >> dot1 >> month >> dot2 >> year) || dot1 != '.' || dot2 != '.' || !dateStream.eof())
                    {
                        cout << "\n\t\t\t\t\t\tInvalid date format." << endl;
                        cout << "\t\t\t\t\t\tPlease enter the date in DD.MM.YYYY format." << endl;
                        break;
                    }
                    vector<Node *> matchNode = custList.findNode(searchDate, 4);

                    if (!matchNode.empty())
                    {
                        cout << "\n\t\t\t\t\t\tCustomer found:" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                        cout << left << setw(5) << setw(15) << "\t\t\tName"
                             << "Date of Booking"
                             << " \t \tDestination"
                             << "\t    Airlines" << endl;
                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;

                        for (Node *current : matchNode)
                        {
                            cout << "\t\t\t";
                            current->data->printSearch(current->data->getdate());
                        }

                        cout << "\t\t\t----------------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\t\tCustomer not found." << endl;
                    }
                    break;
                }

                case 5:
                    // Exit
                    cout << "\n\n\t\t\t\t\t[Exiting the  search program. Goodbye]!" << endl;
                    break;

                default:
                    cout << "\n\t\t\t\t\t\tInvalid choice. Please enter a valid option." << endl;
                }
            } while (searchKey != 5);
        }
        break;
        ///--------------------------------------------------------END OF CODE TO SEARCH----------------------------------------------------------------------------------///
 ///-------------------------------------------------------- CODE TO SORT THE LIST----------------------------------------------------------------------------------///
        case 4:
            // Sort the list           
            custList.bubbleSort();
            cout << "\n\t\t\t\t\t\tList sorted successfully." << endl;
            break;
        ///--------------------------------------------------------END OF CODE TO SORT THE LIST----------------------------------------------------------------------------------///
     ///-------------------------------------------------------- CODE TO DISPLAY LIST----------------------------------------------------------------------------------///
        case 5:
            cout << "\t\t\t----------------------------------------------------------------------------" << endl;
            cout << left << setw(5) << "\t\t\tNo." << setw(15) << "  Name"
                 << "  Date of Booking"
                 << "\t     Destination"
                 << "\tAirlines" << endl;
            cout << "\t\t\t----------------------------------------------------------------------------" << endl;;
            custList.listcust();
            cout << "\t\t\t----------------------------------------------------------------------------" << endl;
            cout << endl;
            break;
        ///--------------------------------------------------------END OF CODE TO DISPLAY----------------------------------------------------------------------------------///

        case 6:
            // Exit
            cout << "\n\n\t\t\t\t\t[Exiting the program. Goodbye]!" << endl;
            break;
        default:
            cout << "\n\t\t\t\t\t\tInvalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 6);

    system("pause");
            
return 0;
}
