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

void NewData(string res, string dept, string arr, string dat, string loc, string cla);
void deleteData(string res);

class User
{
private:
    string Name;
    string IC;
    string Phone;
    string Email;

public:
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
            deleteData(res);

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

    void updateCSV(string res, string dept, string arr, string dat, string loc, string cla)
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

        NewData(res, dept, arr, dat, loc, cla);
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

        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Airline Reservation System     |" << endl;
        cout << setw(56) << "|      [1] Reservation Dashboard      |" << endl;
        cout << setw(56) << "|      [2] Exit                       |" << endl;
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

void NewData(string res, string dept, string arr, string dat, string loc, string cla)
{

    ofstream reservationFile("reservation.csv", ios::app);
    reservationFile.seekp(0, ios::end);
    reservationFile << "\n"
                    << res << "," << dept << "," << arr << "," << dat << "," << loc << "," << cla;

    reservationFile.seekp(0, ios::end);
    reservationFile.close();
};

void deleteData(string res)
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

    Init init;
    int option;
    while (true)
    {
        init.displayMenu();

        cin >> option;
        cout << endl;

        if (option == 2)
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

            switch (option)
            {
            case 1:
            {
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

                            if (choice == 2)
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

                            if (choice == 3)
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

                            if (choice == 4)
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

                            if (choice == 5)
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

                    break;
                }
            }
            break;
            default:
                cout << setw(41) << "Invalid Choice" << endl;
                return 1;
            }
        }
        break;
        default:
            cout << setw(41) << "Invalid Choice" << endl;
            return 1;
        }
    }
}