#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class User;
class Airline;
class Reservation;

int partitionUsers(vector<User> &users, int bottom, int top, int choice);
void quickSortUsers(vector<User> &users, int bottom, int top, int choice);

int partitionAirline(vector<Airline> &airlines, int bottom, int top, int choice);
void quickSortAirline(vector<Airline> &airlines, int bottom, int top, int choice);

int partitionReservation(vector<Reservation> &reservations, int bottom, int top, int choice);
void quickSortReservation(vector<Reservation> &reservations, int bottom, int top, int choice);

int binarySearchByName(const vector<User> &users, const string &name);
int binarySearchByAirplaneID(const vector<Airline> &airlines, const string &AirplaneID);
int binarySearchByReservationID(vector<Reservation> &reservations, const string &ReservationID);

void NewDataUser(string n, string ic, string p, string mail);
void deleteDataUser(string n);

void NewDataReservation(string res, string dept, string arr, string dat, string loc, string cla);
void deleteDataReservation(string res);

void NewDataAirline(string AirplaneID, string Capacity, string Company);
void deleteDataAirline(string AirID);

class User
{
private:
    string Name;
    string IC;
    string Phone;
    string Email;

public:
    User *next;
    User(string Name, string IC, string Phone, string Email)
        : Name(Name), IC(IC), Phone(Phone), Email(Email) {}

    string getName() const
    {
        return Name;
    }
    string getIC() const
    {
        return IC;
    }
    string getPhone() const
    {
        return Phone;
    }
    string getEmail() const
    {
        return Email;
    }

    void display() const
    {
        cout << setw(25) << "Name: " << Name << endl;
        cout << setw(42) << "Identification Number: " << IC << endl;
        cout << setw(33) << "Phone Number: " << Phone << endl;
        cout << setw(26) << "Email: " << Email << endl;
    }
};

class UserList
{
private:
    User *head;

public:
    UserList()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return head = NULL;
    }

    User *getHead() const
    {
        return head;
    }

    //* Insert value at the  start of the node
    User *insertNodeUser(string n, string ic, string p, string mail)
    {
        int currIndex = 0;
        User *curr = head;
        User *prev = NULL;

        while (curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            currIndex++;
        }

        User *newNode = new User(n, ic, p, mail);

        if (currIndex == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = prev->next;
            prev->next = newNode;
        }

        return newNode;
    }

    //* Insert new value at the exact location
    User *insertMidNodeUser(string n, string ic, string p, string mail, int location)
    {
        if (location < 0)
        {
            cout << "Sorry Invalid Location." << endl;
            return 0;
        }

        int currIndex = 1;
        User *curr = head;
        User *prev = NULL;

        while (curr != NULL && currIndex < location)
        {
            prev = curr;
            curr = curr->next;
            currIndex++;
        }

        User *newNode = new User(n, ic, p, mail);

        if (currIndex == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else if (currIndex == location)
        {
            newNode->next = curr;
            prev->next = newNode;
        }
        else
        {
            cout << "Node number value is over the existing value. Value will be inserted at the end of the node." << endl;
            prev->next = newNode;
        }

        return newNode;
    }

    //* Insert new value at the end of the node
    User *insertEndNodeUser(string n, string ic, string p, string mail)
    {
        User *newNode = new User(n, ic, p, mail);

        if (head == NULL) //*If list is empty insert at head
        {
            head = newNode;
        }

        else
        {
            User *curr = head;

            while (curr->next != NULL)
            {
                curr = curr->next;
            }

            curr->next = newNode;
        }

        return newNode;
    }

    //* Delete node at the first Linked List
    void deleteFrontNodeUser()
    {
        User *temp = head;
        head = temp->next;

        deleteDataUser(temp->getIC());
        delete temp;
    }

    //* Delete node with specific value
    int deleteMidNodeUser(string n)
    {
        User *curr = head;
        User *prev = NULL;
        int currentIndex = 1;

        while (curr != NULL && (curr->getIC() != n))
        {
            prev = curr;
            curr = curr->next;
            currentIndex++;
        }

        if (curr != NULL)
        {
            if (prev != NULL)
            {
                prev->next = curr->next;
                delete curr;
            }
            else
            {
                head = curr->next;
                delete curr;
            }

            deleteDataUser(n);

            return currentIndex;
        }
        else
        {
            return 0;
        }
    }

    //* Delete node the end of the Linked List
    void deleteBackNodeUser()
    {
        User *temp = head;
        User *stay = NULL;

        while (temp->next != NULL)
        {
            stay = temp;
            temp = temp->next;
        }

        stay->next = NULL;
        deleteDataUser(temp->getIC());
        delete temp;
    }

    int findNodeUser(string n, string ic, string p, string mail)
    {
        int currentIndex = 1;
        User *curr = head;

        while (curr != NULL && (curr->getName() != n || curr->getIC() != ic || curr->getPhone() != p || curr->getEmail() != mail))
        {
            curr = curr->next;
            currentIndex++;
        }

        if (curr != NULL)
            return currentIndex;
        else
            return 0;
    }

    void displayListUser()
    {
        User *curr = head;
        while (curr != NULL)
        {
            cout << "Name: " << curr->getName() << endl
                 << "Identification Number: " << curr->getIC() << endl
                 << "Phone Number: " << curr->getPhone() << endl
                 << "Email: " << curr->getEmail() << endl;

            cout << endl;
            curr = curr->next;
        }
    }

    void updateCSVUser(string n, string ic, string p, string mail)
    {
        int currentIndex = 0;
        User *curr = head;
        User *prev = NULL;

        while (curr != NULL && (n > curr->getName() || (n == curr->getName() && ic > curr->getIC()) || (n == curr->getName() && ic == curr->getIC() && p > curr->getPhone()) || (n == curr->getName() && ic == curr->getIC() && p > curr->getPhone() && mail > curr->getEmail()) || (n == curr->getName() && ic == curr->getIC() && p > curr->getPhone() && mail > curr->getEmail())))
        {
            prev = curr;
            curr = curr->next;
            currentIndex++;
        }

        User *newNode = new User(n, ic, p, mail);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            User *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        NewDataUser(n, ic, p, mail);
    }
};

//* List function User
void NewDataUser(string n, string ic, string p, string mail)
{
    ofstream userfile("data/user.csv", ios::app);
    userfile.seekp(0, ios::end);
    userfile << "\n"
             << n << "," << ic << "," << p << "," << mail;

    userfile.seekp(0, ios::end);
    userfile.close();
};

//* Delete User data in File
void deleteDataUser(string n)
{
    ifstream inputfile("data/user.csv");
    ofstream tempfile("data/temp.csv");

    string line;
    getline(inputfile, line);

    tempfile << line << endl;

    while (getline(inputfile, line))
    {
        stringstream ss(line);
        string Name, IC, Phone, Email;

        getline(ss, Name, ',');
        getline(ss, IC, ',');
        getline(ss, Phone, ',');
        getline(ss, Email, ',');

        if (IC != n)
        {
            tempfile << line << endl;
        }
    }

    inputfile.close();
    tempfile.close();

    remove("data/user.csv");
    rename("data/temp.csv", "data/user.csv");
}

int partitionUsers(vector<User> &users, int bottom, int top, int choice)
{
    User pivot = users[top];
    int pIndex = bottom;

    for (int i = bottom; i <= top - 1; i++)
    {
        if (choice == 1 && users[i].getName() < pivot.getName())
        {
            swap(users[i], users[pIndex]);
            pIndex++;
        }
        else if (choice == 2 && users[i].getIC() < pivot.getIC())
        {
            swap(users[i], users[pIndex]);
            pIndex++;
        }
        else if (choice == 3 && users[i].getPhone() < pivot.getPhone())
        {
            swap(users[i], users[pIndex]);
            pIndex++;
        }
        else if (choice == 4 && users[i].getEmail() < pivot.getEmail())
        {
            swap(users[i], users[pIndex]);
            pIndex++;
        }
    }

    swap(users[top], users[pIndex]);
    return pIndex;
}

void quickSortUsers(vector<User> &users, int bottom, int top, int choice)
{
    if (bottom < top)
    {
        int pivot = partitionUsers(users, bottom, top, choice);
        quickSortUsers(users, bottom, pivot - 1, choice);
        quickSortUsers(users, pivot + 1, top, choice);
    }
}

class Airline
{
private:
    string AirplaneID;
    string Capacity;
    string Company;

public:
    Airline *next;
    Airline(string AirplaneID, string Capacity, string Company)
        : AirplaneID(AirplaneID), Capacity(Capacity), Company(Company) {}

    string getAirplaneID()
    {
        return AirplaneID;
    }
    string getCapacity()
    {
        return Capacity;
    }

    string getCompany()
    {
        return Company;
    }

    void display()
    {
        cout << setw(32) << "AirplaneID: " << AirplaneID << endl;
        cout << setw(40) << "Plane Max Capacity: " << Capacity << endl;
        cout << setw(33) << "Plane Brand: " << Company << endl;
    }
};

void NewDataAirline(string AirplaneID, string Capacity, string Company)
{

    ofstream airlineFile("data/airline.csv", ios::app);
    airlineFile.seekp(0, ios::end);
    airlineFile << "\n"
                << AirplaneID << "," << Capacity << "," << Company;

    airlineFile.seekp(0, ios::end);
    airlineFile.close();
};

void deleteDataAirline(string AirID)
{
    ifstream inputFile("data/airline.csv");
    ofstream tempFile("temp.csv");

    string line;
    getline(inputFile, line); // Read and write the header

    tempFile << line << endl; // Write the header to the temporary file

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string AirplaneID, Capacity, Company;

        getline(ss, AirplaneID, ',');
        getline(ss, Capacity, ',');
        getline(ss, Company, ',');

        // Check if the current line matches the reservation to be deleted
        if (AirID != AirplaneID)
        {
            // Write the line to the temporary file
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    // Remove the original file and rename the temporary file
    remove("data/airline.csv");
    rename("temp.csv", "data/airline.csv");
}

int partitionAirline(vector<Airline> &airlines, int bottom, int top, int choice)
{
    Airline pivot = airlines[top];
    int pIndex = bottom;

    for (int i = bottom; i <= top - 1; i++)
    {
        if (choice == 1 && airlines[i].getAirplaneID() < pivot.getAirplaneID())
        {
            swap(airlines[i], airlines[pIndex]);
            pIndex++;
        }
        else if (choice == 2 && airlines[i].getCapacity() < pivot.getCapacity())
        {
            swap(airlines[i], airlines[pIndex]);
            pIndex++;
        }
        else if (choice == 3 && airlines[i].getCompany() < pivot.getCompany())
        {
            swap(airlines[i], airlines[pIndex]);
            pIndex++;
        }
    }

    swap(airlines[top], airlines[pIndex]);
    return pIndex;
}

void quickSortAirline(vector<Airline> &airlines, int bottom, int top, int choice)
{
    if (bottom < top)
    {
        int pivot = partitionAirline(airlines, bottom, top, choice);
        quickSortAirline(airlines, bottom, pivot - 1, choice);
        quickSortAirline(airlines, pivot + 1, top, choice);
    }
}

class Reservation
{
private:
    string ReservationID;
    string DepartureTime;
    string ArrivalTime;
    string Date;
    string Location;
    string Class;

public:
    Reservation *next;
    Reservation(string ReservationID, string DepartureTime, string ArrivalTime, string Date, string Location, string Class)
        : ReservationID(ReservationID), DepartureTime(DepartureTime), ArrivalTime(ArrivalTime), Date(Date), Location(Location), Class(Class) {}

    string getReservationID()
    {
        return ReservationID;
    }
    string getDepartureTime()
    {
        return DepartureTime;
    }
    string getArrivalTime()
    {
        return ArrivalTime;
    }
    string getDate()
    {
        return Date;
    }
    string getLocation()
    {
        return Location;
    }
    string getClass()
    {
        return Class;
    }

    void display()
    {
        cout << setw(34) << "ReservationID: " << ReservationID << endl;
        cout << setw(45) << "Estimated Departure Time: " << DepartureTime << endl;
        cout << setw(43) << "Estimated Arrival Time: " << ArrivalTime << endl;
        cout << setw(37) << "Reservation Date: " << Date << endl;
        cout << setw(40) << "Arrival Destination: " << Location << endl;
        cout << setw(26) << "Class: " << Class << endl;
    }
};

class reservationList // List
{
private:
    Reservation *head;

public:
    reservationList() : head(nullptr) {}

    bool isEmpty()
    {
        return head == nullptr;
    }
    Reservation *getHead() const
    {
        return head;
    }

    Reservation *insertNode(string res, string dept, string arr, string dat, string loc, string cla)
    {
        int currIndex = 0;
        Reservation *curr = head;
        Reservation *prev = nullptr;

        while (curr != nullptr && (res > curr->getReservationID() || (res == curr->getReservationID() && dept > curr->getDepartureTime()) || (res == curr->getReservationID() && dept == curr->getDepartureTime() && arr > curr->getArrivalTime()) || (res == curr->getReservationID() && dept == curr->getDepartureTime() && arr > curr->getArrivalTime() && dat > curr->getDate()) || (res == curr->getReservationID() && dept == curr->getDepartureTime() && arr > curr->getArrivalTime() && dat > curr->getDate() && loc > curr->getLocation()) || (res == curr->getReservationID() && dept == curr->getDepartureTime() && arr > curr->getArrivalTime() && dat > curr->getDate() && loc > curr->getLocation() && cla > curr->getClass())))
        {
            prev = curr;
            curr = curr->next;
            currIndex++;
        }

        Reservation *newNode = new Reservation(res, dept, arr, dat, loc, cla);

        if (currIndex == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = prev->next;
            prev->next = newNode;
        }
        return newNode;
    }

    int deleteNodeReservation(string res)
    {
        Reservation *prev = nullptr;
        Reservation *curr = head;
        int currentIndex = 1;

        while (curr != nullptr && (curr->getReservationID() != res))
        {
            prev = curr;
            curr = curr->next;
            currentIndex++;
        }

        if (curr != nullptr)
        {
            if (prev != nullptr)
            {
                prev->next = curr->next;
                delete curr;
            }
            else
            {
                head = curr->next;
                delete curr;
            }

            // Move this line here
            deleteDataReservation(res);

            return currentIndex;
        }
        else
        {
            return 0; // Node not found
        }
    }

    int findNode(string res, string dept, string arr, string dat, string loc, string cla)
    {
        int currentIndex = 1;
        Reservation *curr = head;

        while (curr != nullptr && (curr->getReservationID() != res || curr->getArrivalTime() != arr || curr->getClass() != cla || curr->getDate() != dat || curr->getDepartureTime() != dept || curr->getLocation() != loc))
        {
            curr = curr->next;
            currentIndex++;
        }

        if (curr != nullptr)
        {
            return currentIndex;
        }
        else
        {
            return 0;
        }
    }

    void displayList()
    {
        Reservation *current = head;
        while (current != nullptr)
        {
            cout << "ReservationID: " << current->getReservationID() << endl;
            cout << "Departure Time: " << current->getDepartureTime() << endl;
            cout << "Arrival Time: " << current->getArrivalTime() << endl;
            cout << "Reservation Date: " << current->getDate() << endl;
            cout << "Location: " << current->getLocation() << endl;
            cout << "Class: " << current->getClass() << endl
                 << endl;
            current = current->next;
        }
        cout << endl;
    }

    void updateCSVReservation(string res, string dept, string arr, string dat, string loc, string cla)
    {
        int currIndex = 0;
        Reservation *curr = head;
        Reservation *prev = nullptr;

        while (curr != nullptr && (res > curr->getReservationID() || (res == curr->getReservationID() && dept > curr->getDepartureTime()) || (res == curr->getReservationID() && dept == curr->getDepartureTime() && arr > curr->getArrivalTime()) || (res == curr->getReservationID() && dept == curr->getDepartureTime() && arr > curr->getArrivalTime() && dat > curr->getDate()) || (res == curr->getReservationID() && dept == curr->getDepartureTime() && arr > curr->getArrivalTime() && dat > curr->getDate() && loc > curr->getLocation()) || (res == curr->getReservationID() && dept == curr->getDepartureTime() && arr > curr->getArrivalTime() && dat > curr->getDate() && loc > curr->getLocation() && cla > curr->getClass())))
        {
            prev = curr;
            curr = curr->next;
            currIndex++;
        }

        Reservation *newNode = new Reservation(res, dept, arr, dat, loc, cla);

        if (head == nullptr)
        {
            // If the list is empty, make the new node the head
            head = newNode;
        }
        else
        {
            Reservation *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        NewDataReservation(res, dept, arr, dat, loc, cla);
    }
};

int partitionReservation(vector<Reservation> &reservations, int bottom, int top, int choice)
{
    Reservation pivot = reservations[top];
    int pIndex = bottom;

    for (int i = bottom; i <= top - 1; i++)
    {
        if (choice == 3 && reservations[i].getArrivalTime() < pivot.getArrivalTime())
        {
            swap(reservations[i], reservations[pIndex]);
            pIndex++;
        }
        else if (choice == 6 && reservations[i].getClass() < pivot.getClass())
        {
            swap(reservations[i], reservations[pIndex]);
            pIndex++;
        }
        else if (choice == 4 && reservations[i].getDate() < pivot.getDate())
        {
            swap(reservations[i], reservations[pIndex]);
            pIndex++;
        }
        else if (choice == 2 && reservations[i].getDepartureTime() < pivot.getDepartureTime())
        {
            swap(reservations[i], reservations[pIndex]);
            pIndex++;
        }
        else if (choice == 5 && reservations[i].getLocation() < pivot.getLocation())
        {
            swap(reservations[i], reservations[pIndex]);
            pIndex++;
        }
        else if (choice == 1 && reservations[i].getReservationID() < pivot.getReservationID())
        {
            swap(reservations[i], reservations[pIndex]);
            pIndex++;
        }
    }

    swap(reservations[top], reservations[pIndex]);
    return pIndex;
}

void quickSortReservation(vector<Reservation> &reservations, int bottom, int top, int choice)
{
    if (bottom < top)
    {
        int pivot = partitionReservation(reservations, bottom, top, choice);
        quickSortReservation(reservations, bottom, pivot - 1, choice);
        quickSortReservation(reservations, pivot + 1, top, choice);
    }
}

class AirLineList // List
{
private:
    Airline *head;

public:
    AirLineList() : head(nullptr) {}

    bool isEmpty()
    {
        return head == nullptr;
    }
    Airline *getHead() const
    {
        return head;
    }

    Airline *insertNode(string AirplaneID, string Capacity, string Company)
    {
        int currIndex = 0;
        Airline *curr = head;
        Airline *prev = nullptr;

        while (curr != nullptr)
        {
            prev = curr;
            curr = curr->next;
            currIndex++;
        }

        Airline *newNode = new Airline(AirplaneID, Capacity, Company);

        if (currIndex == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = prev->next;
            prev->next = newNode;
        }
        return newNode;
    }

    int deleteNodeAirline(string AirplaneID)
    {
        Airline *prev = nullptr;
        Airline *curr = head;
        int currentIndex = 1;

        while (curr != nullptr && (curr->getAirplaneID() != AirplaneID))
        {
            prev = curr;
            curr = curr->next;
            currentIndex++;
        }

        if (curr != nullptr)
        {
            if (prev != nullptr)
            {
                prev->next = curr->next;
                delete curr;
            }
            else
            {
                head = curr->next;
                delete curr;
            }

            // Move this line here
            deleteDataAirline(AirplaneID);

            return currentIndex;
        }
        else
        {
            return 0; // Node not found
        }
    }

    // int findAirplaneNode(string AirplaneID)
    // {
    //     int currentIndex = 1;
    //     Airline *curr = head;

    //     while (curr != nullptr && (curr->getAirplaneID() != AirplaneID || curr->getCapacity() != Capacity || curr->getCompany() != Company))
    //     {
    //         curr = curr->next;
    //         currentIndex++;
    //     }

    //     if (curr != nullptr)
    //     {
    //         return currentIndex;
    //     }
    //     else
    //     {
    //         return 0;
    //     }
    // }

    void findAirplaneNode(const string &AirplaneID)
    {
        Airline *curr = head;
        while (curr != nullptr)
        {
            if (curr->getAirplaneID() == AirplaneID)
            {
                cout << "Airplane Found: ";
                cout << "\nID: " << curr->getAirplaneID()
                     << "\nCapacity: " << curr->getCapacity()
                     << "\nCompany: " << curr->getCompany() << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "No airplane found with ID: " << AirplaneID << endl;
    }

    void displayAirplaneList()
    {
        Airline *current = head;
        while (current != nullptr)
        {
            cout << "AirplaneID: " << current->getAirplaneID() << endl;
            cout << "Capacity : " << current->getCapacity() << endl;
            cout << "Company : " << current->getCompany() << endl;
            cout << endl;
            current = current->next;
        }
        cout << endl;
    }

    void updateAirplaneCSV(string AirplaneID, string Capacity, string Company)
    {
        int currIndex = 0;
        Airline *curr = head;
        Airline *prev = nullptr;

        Airline *newNode = new Airline(AirplaneID, Capacity, Company);

        if (head == nullptr)
        {
            // If the list is empty, make the new node the head
            head = newNode;
        }
        else
        {
            Airline *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        NewDataAirline(AirplaneID, Capacity, Company);
    }
};

class Init
{
public:
    void
    displayMenu()
    {
        // system("cls");     // to clear the mess
        cout << "\033[1m"; // Start bold text
        cout << endl;
        cout << "                                   |" << endl;
        cout << "                                   |" << endl;
        cout << "                                   |" << endl;
        cout << "                                 .-'-." << endl;
        cout << "                                ' ___ '" << endl;
        cout << "                      ---------'  .-.  '---------" << endl;
        cout << "      _________________________'  '-'  '_________________________" << endl;
        cout << "      ''''''-|---|--/    \\==][^',_m_,'^][==/    \\--|---|-'''''' " << endl;
        cout << "                    \\    /  ||/   H   \\||  \\    /" << endl;
        cout << "                     '--'   OO   O|O   OO     '--'" << endl;
        cout << endl;
        cout << setw(55) << "_________________________________________________________________" << endl;
        cout << setw(56) << "|      Airline Reservation System                                |" << endl;
        cout << setw(56) << "|      [1] Reservation Dashboard (Sorting/Searching Function)    |" << endl;
        cout << setw(56) << "|      [2] Reservation Management (Linked List Implementation)   |" << endl;
        cout << setw(56) << "|      [3] Exit                                                  |" << endl;
        cout << setw(56) << "|________________________________________________________________|" << endl;
        cout << endl;
        cout << setw(37) << "Option: ";
    }

    void displayReservationManagement()
    {
        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Reservation Management         |" << endl;
        cout << setw(56) << "|      [1] Manage User                |" << endl;
        cout << setw(56) << "|      [2] Manage Airline             |" << endl;
        cout << setw(56) << "|      [3] Manage Reservation         |" << endl;
        cout << setw(56) << "|      [4] Exit                       |" << endl;
        cout << setw(56) << "|_____________________________________|" << endl;
    }

    void displayAlter()
    {
        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Choose Operation               |" << endl;
        cout << setw(56) << "|      [1] Insert Data                |" << endl;
        cout << setw(56) << "|      [2] Delete Data                |" << endl;
        cout << setw(56) << "|      [3] Find Data                  |" << endl;
        cout << setw(56) << "|      [4] Display All Data           |" << endl;
        cout << setw(56) << "|_____________________________________|" << endl;
        cout << endl;
        cout << setw(37) << "Option: ";
    }

    void displayReservationDashboard()
    {
        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Reservation Dashboard          |" << endl;
        cout << setw(56) << "|      [1] Display User               |" << endl;
        cout << setw(56) << "|      [2] Display Airline            |" << endl;
        cout << setw(56) << "|      [3] Display Reservation        |" << endl;
        cout << setw(56) << "|      [4] Exit                       |" << endl;
        cout << setw(56) << "|_____________________________________|" << endl;
    }

    void displaySelection()
    {
        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Choose Option                  |" << endl;
        cout << setw(56) << "|      [1] Sort Data                  |" << endl;
        cout << setw(56) << "|      [2] Search Data                |" << endl;
        cout << setw(56) << "|_____________________________________|" << endl;
        cout << endl;
        cout << setw(37) << "Option: ";
    }

    void displaySortingUser()
    {
        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Sorting User                   |" << endl;
        cout << setw(56) << "|      [1] By Name                    |" << endl;
        cout << setw(56) << "|      [2] By IC                      |" << endl;
        cout << setw(56) << "|      [3] By Phone                   |" << endl;
        cout << setw(56) << "|      [4] By Email                   |" << endl;
        cout << setw(56) << "|_____________________________________|" << endl;
        cout << endl;
        cout << setw(37) << "Option: ";
    }

    void displaySortingAirline()
    {
        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Sorting Airline                |" << endl;
        cout << setw(56) << "|      [1] By AirplaneID              |" << endl;
        cout << setw(56) << "|      [2] By Capacity                |" << endl;
        cout << setw(56) << "|      [3] By Company                 |" << endl;
        cout << setw(56) << "|_____________________________________|" << endl;
        cout << endl;
        cout << setw(37) << "Option: ";
    }

    void displaySortingReservation()
    {
        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Sorting Reservation            |" << endl;
        cout << setw(56) << "|      [1] By ReservationID           |" << endl;
        cout << setw(56) << "|      [2] By DepartureTime           |" << endl;
        cout << setw(56) << "|      [3] By ArrivalTime             |" << endl;
        cout << setw(56) << "|      [4] By Date                    |" << endl;
        cout << setw(56) << "|      [5] By Location                |" << endl;
        cout << setw(56) << "|_____________________________________|" << endl;
        cout << endl;
        cout << setw(37) << "Option: ";
    }

    void displaySeachingUser()
    {
        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Searching User                 |" << endl;
        cout << setw(56) << "|      [1] By Name                    |" << endl;
        cout << setw(56) << "|      [2] By IC                      |" << endl;
        cout << setw(56) << "|      [3] By Phone                   |" << endl;
        cout << setw(56) << "|      [4] By Email                   |" << endl;
        cout << setw(56) << "|_____________________________________|" << endl;
        cout << endl;
        cout << setw(37) << "Option: ";
    }

    void displaySeachingAirline()
    {
        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Searching Airline              |" << endl;
        cout << setw(56) << "|      [1] By AirplaneID              |" << endl;
        cout << setw(56) << "|      [2] By Capacity                |" << endl;
        cout << setw(56) << "|      [3] By Company                 |" << endl;
        cout << setw(56) << "|_____________________________________|" << endl;
        cout << endl;
        cout << setw(37) << "Option: ";
    }

    void displaySeachingReservation()
    {
        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Searching Reservation          |" << endl;
        cout << setw(56) << "|      [1] By ReservationID           |" << endl;
        cout << setw(56) << "|      [2] By DepartureTime           |" << endl;
        cout << setw(56) << "|      [3] By ArrivalTime             |" << endl;
        cout << setw(56) << "|      [4] By Date                    |" << endl;
        cout << setw(56) << "|      [5] By Location                |" << endl;
        cout << setw(56) << "|_____________________________________|" << endl;
        cout << endl;
        cout << setw(37) << "Option: ";
    }

    void makeReservation()
    {
        system("cls");
        int error = 0;
        cout << setw(40) << "                                               _" << endl;
        cout << setw(40) << "                 ___                          (_)" << endl;
        cout << setw(20) << "               _/XXX\\" << endl;
        cout << setw(40) << "_             /XXXXXX\\_                                    __" << endl;
        cout << setw(40) << "X\\__    __   /X XXXX XX\\                          _       /XX\\__      ___" << endl;
        cout << setw(40) << "    \\__/  \\_/__       \\ \\                       _/X\\__   /XX XXX\\____/XXX\\" << endl;
        cout << setw(40) << "  \\  ___   \\/  \\_      \\ \\               __   _/      \\_/  _/  -   __  -  \\" << endl;
        cout << setw(40) << " ___/   \\__/   \\ \\__     \\__           /  \\_//  _ _ \\  \\     __  /  \\____/" << endl;
        cout << setw(40) << "/  __    \\  /     \\ \\_   _//_\\___    __/    //           \\___/  \\/     __/" << endl;
        cout << setw(40) << "__/_______\\________\\__\\_/________\\__/_/____/_____________/_______\\____/____" << endl;
        cout << setw(32) << "                                  ___" << endl;
        cout << setw(36) << "                                 /L|0\\" << endl;
        cout << setw(38) << "                                /  |  \\" << endl;
        cout << setw(40) << "                               /       \\" << endl;
        cout << setw(40) << "                              /    |    \\" << endl;
        cout << setw(40) << "                             /           \\" << endl;
        cout << setw(40) << "                            /  __  | __   \\" << endl;
        cout << setw(40) << "                           /  __/    \\__   \\" << endl;
        cout << setw(40) << "                          /  /__   |  __\\   \\" << endl;
        cout << setw(40) << "                         /___________________\\" << endl;
        cout << setw(40) << "                         /          |         \\" << endl;
        cout << setw(40) << "                              /   _|_   \\" << endl;
        cout << setw(40) << "                      /      ____/___\\____     \\" << endl;
        cout << setw(40) << "                      ___________[o0o]___________" << endl;
        cout << setw(40) << "                               O   O   O" << endl;

        cout << endl;
        cout << setw(60) << "Welcome to Capybara International Airport (CiA)" << endl
             << endl;

        cout << setw(45) << "Where to travel?:  " << endl
             << endl;
        cout << setw(45) << "[1] Chicago to Miami" << endl;
        cout << setw(45) << "[2] Seattle to Denver" << endl;
        cout << setw(45) << "[3] San Francisco to Houston" << endl;
        cout << setw(45) << "[4] Atlanta to Las Vegas" << endl;
        cout << setw(45) << "[5] Boston to Orlando" << endl;
        cout << setw(45) << "[6] New York to Los Angeles" << endl;

        int choice;

        string departureTime, arrivalTime, date, flightClass;
        cout << "Selection: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            departureTime = "08:00 AM";
            arrivalTime = "10:30 AM";
            date = "2023-04-15";
            break;
        case 2:
            departureTime = "12:45 PM";
            arrivalTime = "03:15 PM";
            date = "2023-05-22";
            break;
        case 3:
            departureTime = "04:30 PM";
            arrivalTime = "06:45 PM";
            date = "2023-06-10";
            break;
        case 4:
            departureTime = "09:15 AM";
            arrivalTime = "11:45 AM";
            date = "2023-07-03";
            break;
        case 5:
            departureTime = "02:30 PM";
            arrivalTime = "05:00 PM";
            date = "2023-08-18";
            break;
        case 6:
            departureTime = "06:20 PM";
            arrivalTime = "08:40 PM";
            date = "2023-09-05";
            break;
        default:
            error = 1;
            cout << "Invalid choice. Exiting program." << endl;
        }

        cout << "Select your class:" << endl;
        cout << "[1] Economy" << endl;
        cout << "[2] Business" << endl;
        cout << "[3] First Class" << endl;
        cout << "Enter your choice (1-3): ";
        int classChoice;
        cin >> classChoice;

        switch (classChoice)
        {
        case 1:
            flightClass = "Economy";
            break;
        case 2:
            flightClass = "Business";
            break;
        case 3:
            flightClass = "First Class";
            break;
        default:
            cout << "Invalid class choice. Exiting program." << endl;
        }

        if (error != 1)
        {
            cout << "Your flight details:" << endl;
            cout << "Departure Time: " << departureTime << endl;
            cout << "Arrival Time: " << arrivalTime << endl;
            cout << "Date: " << date << endl;
            cout << "Class: " << flightClass << endl;
        }
    }
};

void LoadFiles(vector<User> &users, vector<Airline> &airline, vector<Reservation> &reservation)
{
    ifstream userFile("data/user.csv");
    string lineUser;

    getline(userFile, lineUser); // skip the headings

    while (getline(userFile, lineUser))
    {
        string name, ic, phone, email;
        stringstream ss(lineUser); // get the whole line
        getline(ss, name, ',');
        getline(ss, ic, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');

        users.push_back(User(name, ic, phone, email));
    }

    userFile.close();

    ifstream airlineFile("data/airline.csv");
    string lineAirline;

    getline(airlineFile, lineAirline); // skip the headings

    while (getline(airlineFile, lineAirline))
    {
        string airplaneId, capacity, company;
        stringstream ss(lineAirline); // get the whole line
        getline(ss, airplaneId, ',');
        getline(ss, capacity, ',');
        getline(ss, company, ',');

        airline.push_back(Airline(airplaneId, capacity, company));
    }
    airlineFile.close();

    ifstream reservationFile("data/reservation.csv");
    string lineReservation;

    getline(reservationFile, lineReservation); // skip the headings

    while (getline(reservationFile, lineReservation))
    {
        string reservationId, departureTime, arrivalTime, date, location, Class;
        stringstream ss(lineReservation); // get the whole line
        getline(ss, reservationId, ',');
        getline(ss, departureTime, ',');
        getline(ss, arrivalTime, ',');
        getline(ss, date, ',');
        getline(ss, location, ',');
        getline(ss, Class, ',');

        reservation.push_back(Reservation(reservationId, departureTime, arrivalTime, date, location, Class));
    }
    reservationFile.close();
};

void NewDataReservation(string res, string dept, string arr, string dat, string loc, string cla)
{

    ofstream reservationFile("reservation.csv", ios::app);
    reservationFile.seekp(0, ios::end);
    reservationFile << "\n"
                    << res << "," << dept << "," << arr << "," << dat << "," << loc << "," << cla;

    reservationFile.seekp(0, ios::end);
    reservationFile.close();
};

void deleteDataReservation(string res)
{
    ifstream inputFile("reservation.csv");
    ofstream tempFile("temp.csv");

    string line;
    getline(inputFile, line); // Read and write the header

    tempFile << line << endl; // Write the header to the temporary file

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string reservationId, departureTime, arrivalTime, date, location, Class;

        getline(ss, reservationId, ',');
        getline(ss, departureTime, ',');
        getline(ss, arrivalTime, ',');
        getline(ss, date, ',');
        getline(ss, location, ',');
        getline(ss, Class, ',');

        // Check if the current line matches the reservation to be deleted
        if (reservationId != res)
        {
            // Write the line to the temporary file
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    // Remove the original file and rename the temporary file
    remove("reservation.csv");
    rename("temp.csv", "reservation.csv");
}

int binarySearchByName(const vector<User> &users, const string &name)
{
    int low = 0;
    int high = users.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (users[mid].getName() == name)
        {
            return mid; // User found at index mid
        }
        else if (users[mid].getName() < name)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int binarySearchByIC(const vector<User> &users, const string &IC)
{
    int low = 0;
    int high = users.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (users[mid].getIC() == IC)
        {
            return mid; // User found at index mid
        }
        else if (users[mid].getIC() < IC)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int binarySearchByPhone(const vector<User> &users, const string &Phone)
{
    int low = 0;
    int high = users.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (users[mid].getPhone() == Phone)
        {
            return mid; // User found at index mid
        }
        else if (users[mid].getPhone() < Phone)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int binarySearchByEmail(const vector<User> &users, const string &Email)
{
    int low = 0;
    int high = users.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (users[mid].getEmail() == Email)
        {
            return mid; // User found at index mid
        }
        else if (users[mid].getEmail() < Email)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int binarySearchByAirplaneID(vector<Airline> &airlines, const string &AirplaneID)
{
    int low = 0;
    int high = airlines.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (airlines[mid].getAirplaneID() == AirplaneID)
        {
            return mid; // User found at index mid
        }
        else if (airlines[mid].getAirplaneID() < AirplaneID)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int binarySearchByCapacity(vector<Airline> &airlines, const string &Capacity)
{
    int low = 0;
    int high = airlines.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (airlines[mid].getCapacity() == Capacity)
        {
            return mid; // User found at index mid
        }
        else if (airlines[mid].getCapacity() < Capacity)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int binarySearchByCompany(vector<Airline> &airlines, const string &Company)
{
    int low = 0;
    int high = airlines.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (airlines[mid].getCompany() == Company)
        {
            return mid; // User found at index mid
        }
        else if (airlines[mid].getCompany() < Company)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int binarySearchByReservationID(vector<Reservation> &reservations, const string &ReservationID)
{
    int low = 0;
    int high = reservations.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (reservations[mid].getReservationID() == ReservationID)
        {
            return mid; // User found at index mid
        }
        else if (reservations[mid].getReservationID() < ReservationID)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int binarySearchByDepartureTime(vector<Reservation> &reservations, const string &DepartureTime)
{
    int low = 0;
    int high = reservations.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (reservations[mid].getDepartureTime() == DepartureTime)
        {
            return mid; // User found at index mid
        }
        else if (reservations[mid].getDepartureTime() < DepartureTime)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int binarySearchByArrivalTime(vector<Reservation> &reservations, const string &ArrivalTime)
{
    int low = 0;
    int high = reservations.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (reservations[mid].getArrivalTime() == ArrivalTime)
        {
            return mid; // User found at index mid
        }
        else if (reservations[mid].getArrivalTime() < ArrivalTime)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int binarySearchByDate(vector<Reservation> &reservations, const string &Date)
{
    int low = 0;
    int high = reservations.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (reservations[mid].getDate() == Date)
        {
            return mid; // User found at index mid
        }
        else if (reservations[mid].getDate() < Date)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int binarySearchByLocation(vector<Reservation> &reservations, const string &Location)
{
    int low = 0;
    int high = reservations.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (reservations[mid].getLocation() == Location)
        {
            return mid; // User found at index mid
        }
        else if (reservations[mid].getLocation() < Location)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // User not found
}

int main()
{

    vector<User> users;
    vector<Airline> airlines;
    vector<Reservation> reservations;

    LoadFiles(users, airlines, reservations);
    reservationList reservationList;
    AirLineList airlineList;
    Init init;

    for (int i = 0; i < reservations.size(); i++)
    {
        reservationList.insertNode(reservations[i].getReservationID(), reservations[i].getDepartureTime(), reservations[i].getArrivalTime(), reservations[i].getDate(), reservations[i].getLocation(), reservations[i].getClass());
    }

    for (int i = 0; i < airlines.size(); i++)
    {
        airlineList.insertNode(airlines[i].getAirplaneID(), airlines[i].getCapacity(), airlines[i].getCompany());
    }

    // tambahhhh--------->
    while (true)
    {
        int option;
        init.displayMenu();

        cin >> option;
        cout << endl;

        if (option == 3)
        {
            break;
        }

        switch (option)
        {
        case 1:
        {
            int choice;
            init.displayReservationDashboard();

            cout << endl
                 << setw(57) << "Which operation would you like to choose?" << endl;
            cout << setw(37) << "Option: ";
            cin >> choice;
            cout << endl;

            while (choice != 4)
            {
                if (choice == 1)
                {
                    int selection;
                    init.displaySelection();
                    cin >> selection;
                    cout << endl;

                    if (selection == 1)
                    {
                        init.displaySortingUser();
                        cin >> choice;
                        cout << endl;

                        int i = 1;

                        quickSortUsers(users, 0, users.size() - 1, choice);

                        for (int j = 0; j < users.size(); j++)
                        {
                            users[j].display();
                            cout << setw(18) << "                   -------------------------------" << endl;
                        }
                    }
                    else if (selection == 2)
                    {
                        init.displaySeachingUser();
                        cin >> choice;
                        cout << endl;

                        cin.ignore();
                        if (choice == 1)
                        {
                            string username;
                            int found = 0;
                            cout << setw(42) << "Insert the Name: ";

                            getline(cin, username);
                            quickSortUsers(users, 0, users.size() - 1, 1);
                            found = binarySearchByName(users, username);

                            users[found].display();
                        }

                        if (choice == 2)
                        {
                            string IC;
                            int found = 0;
                            cout << setw(42) << "Insert the IC: ";

                            getline(cin, IC);
                            quickSortUsers(users, 0, users.size() - 1, 1);
                            found = binarySearchByIC(users, IC);

                            users[found].display();
                        }

                        if (choice == 3)
                        {
                            string Phone;
                            int found = 0;
                            cout << setw(38) << "Insert the Phone: ";

                            getline(cin, Phone);
                            quickSortUsers(users, 0, users.size() - 1, 1);
                            found = binarySearchByPhone(users, Phone);

                            users[found].display();
                        }

                        if (choice == 4)
                        {
                            string Email;
                            int found = 0;
                            cout << setw(42) << "Insert the Email: ";

                            getline(cin, Email);
                            quickSortUsers(users, 0, users.size() - 1, 1);
                            found = binarySearchByEmail(users, Email);

                            users[found].display();
                        }
                    }
                }
                else if (choice == 2)
                {
                    int selection;
                    init.displaySelection();
                    cin >> selection;
                    cout << endl;
                    if (selection == 1)
                    {
                        init.displaySortingAirline();
                        cin >> choice;
                        cout << endl;

                        quickSortAirline(airlines, 0, airlines.size() - 1, choice);

                        for (int j = 0; j < airlines.size(); j++)
                        {
                            airlines[j].display();
                            cout << setw(18) << "                   -------------------------------" << endl;
                        }
                    }
                    else if (selection == 2)
                    {
                        init.displaySeachingAirline();
                        cin >> choice;
                        cout << endl;

                        if (choice == 1)
                        {
                            string AirplaneID;
                            int found = 0;
                            cout << setw(42) << "Insert the AirplaneID: ";
                            cin.ignore();
                            getline(cin, AirplaneID);
                            quickSortAirline(airlines, 0, airlines.size() - 1, 1);
                            found = binarySearchByAirplaneID(airlines, AirplaneID);

                            airlines[found].display();
                        }

                        if (choice == 2)
                        {
                            string Capacity;
                            int found = 0;
                            cout << setw(42) << "Insert the Capacity: ";
                            cin.ignore();
                            getline(cin, Capacity);
                            quickSortAirline(airlines, 0, airlines.size() - 1, 1);
                            found = binarySearchByCapacity(airlines, Capacity);

                            airlines[found].display();
                        }

                        if (choice == 3)
                        {
                            string Company;
                            int found = 0;
                            cout << setw(42) << "Insert the Company: ";
                            cin.ignore();
                            getline(cin, Company);
                            quickSortAirline(airlines, 0, airlines.size() - 1, 1);
                            found = binarySearchByCompany(airlines, Company);

                            airlines[found].display();
                        }
                    }
                }
                else if (choice == 3)
                {
                    int selection;
                    init.displaySelection();
                    cin >> selection;
                    cout << endl;

                    if (selection == 1)
                    {
                        init.displaySortingReservation();
                        cin >> choice;
                        cout << endl;

                        quickSortReservation(reservations, 0, reservations.size() - 1, choice);

                        for (int j = 0; j < reservations.size(); j++)
                        {
                            reservations[j].display();
                            cout << setw(18) << "                   -------------------------------" << endl;
                        }
                    }
                    else if (selection == 2)
                    {
                        init.displaySeachingReservation();
                        cin >> choice;
                        cout << endl;

                        if (choice == 1)
                        {
                            string ReservationID;
                            int found = 0;
                            cout << setw(47) << "Insert the ReservationID (RX): ";
                            cin.ignore();
                            getline(cin, ReservationID);
                            quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                            found = binarySearchByReservationID(reservations, ReservationID);

                            reservations[found].display();
                        }

                        else if (choice == 2)
                        {
                            string DepartureTime;
                            int found = 0;
                            cout << setw(47) << "Insert the Departure Time: ";
                            cin.ignore();
                            getline(cin, DepartureTime);
                            quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                            found = binarySearchByDepartureTime(reservations, DepartureTime);

                            reservations[found].display();
                        }

                        else if (choice == 3)
                        {
                            string ArrivalTime;
                            int found = 0;
                            cout << setw(47) << "Insert the Arrival Time: ";
                            cin.ignore();
                            getline(cin, ArrivalTime);
                            quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                            found = binarySearchByArrivalTime(reservations, ArrivalTime);

                            reservations[found].display();
                        }

                        else if (choice == 4)
                        {
                            string Date;
                            int found = 0;
                            cout << setw(47) << "Insert the Date (YYYY-MM-DD): ";
                            cin.ignore();
                            getline(cin, Date);
                            quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                            found = binarySearchByDate(reservations, Date);

                            reservations[found].display();
                        }

                        else if (choice == 5)
                        {
                            string Location;
                            int found = 0;
                            cout << setw(39) << "Insert the Location: ";
                            cin.ignore();
                            getline(cin, Location);
                            quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                            found = binarySearchByLocation(reservations, Location);

                            reservations[found].display();
                        }
                    }
                }
                else
                    cout << setw(41) << "Invalid Choice" << endl;
            }

            break;
        }
        break;
        case 2:
        {
            int pilih;
            init.displayReservationManagement();
            cout << setw(37) << "Option: ";
            cin >> pilih;

            int pilih2;
            if (pilih == 1)
            {
                init.displayAlter();
                cin >> pilih2;
                if (pilih2 == 1)
                {
                }
                else if (pilih2 == 2)
                {
                }
                else if (pilih2 == 3)
                {
                }
                else if (pilih2 == 4)
                {
                }
            }

            if (pilih == 2)
            {
                init.displayAlter();
                string AirplaneID, Capacity, Company;

                cin >> pilih2;
                if (pilih2 == 1) //* Insert new value
                {
                    for (int i = 0; i < airlines.size(); i++)
                    {
                        airlineList.insertNode(airlines[i].getAirplaneID(), airlines[i].getCapacity(), airlines[i].getCompany());
                    }

                    /* Add option for
                    [1] Front Insert
                    [2] End Insert
                    [3] Specific Insert*/

                    cout << "Current Airplane List: " << endl
                         << endl;
                    airlineList.displayAirplaneList();

                    cout << "Enter new Airplane ID: ";
                    getline(cin >> ws, AirplaneID);
                    cout << "Enter Capacity: ";
                    getline(cin >> ws, Capacity);
                    cout << "Enter Company: ";
                    getline(cin >> ws, Company);

                    airlineList.updateAirplaneCSV(AirplaneID, Capacity, Company);
                    LoadFiles(users, airlines, reservations);

                    // system("cls");
                    cout << "\nUpdated Airplane List: " << endl
                         << endl;
                    airlineList.displayAirplaneList();
                }
                else if (pilih2 == 2) //* Delete existing value
                {
                    cout << "Current Airplane List: " << endl
                         << endl;
                    airlineList.displayAirplaneList();

                    /* Add option for
                    [1] Front Delete
                    [2] End Delete
                    [3] SpecificDeletet*/

                    string deleteAirplaneID;
                    cout << "Enter Airplane ID to delete: ";
                    getline(cin >> ws, deleteAirplaneID);

                    airlineList.deleteNodeAirline(deleteAirplaneID);
                    LoadFiles(users, airlines, reservations);

                    cout << "Current Airplane List after deletion: " << endl;
                    airlineList.displayAirplaneList();
                }
                else if (pilih2 == 3) //* Find value using specific value
                {
                    cout << "Enter AirplaneID to search\n";
                    string searchAirplaneID;
                    getline(cin >> ws, searchAirplaneID);

                    airlineList.findAirplaneNode(searchAirplaneID);
                }
                else if (pilih2 == 4) //* Display sorted
                {
                    cout << "Current Airplane List: " << endl
                         << endl;
                    airlineList.displayAirplaneList();
                }
                else //* Exit
                    break;
            }

            if (pilih == 3)
            {
                init.displayAlter();
                cin >> pilih2;
                if (pilih2 == 1)
                {
                }
                else if (pilih2 == 2)
                {
                }
                else if (pilih2 == 3)
                {
                }
                else if (pilih2 == 4)
                {
                }
            }
        }
        break;
        }

        //

        // reservationList.updateCSV("1", "2", "33", "$", "%", "23123");
        // airlineList.updateAirplaneCSV("1", "2", "#");
        // LoadFiles(users, airlines, reservations);

        // airlineList.displayAirplaneList();
        // reservationList.displayList();
    }
}