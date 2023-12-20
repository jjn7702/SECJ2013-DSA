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
int binarySearchByReservationID(std::vector<Reservation> &reservations, const std::string &ReservationID);

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

    void displayBodo() const
    {
        cout << setw(25) << "Name: " << Name << endl;
        cout << setw(42) << "Identification Number: " << IC << endl;
        cout << setw(33) << "Phone Number: " << Phone << endl;
        cout << setw(26) << "Email: " << Email << endl;
    }

    void display(int x, vector<User> &users) const
    {

        quickSortUsers(users, 0, users.size() - 1, x);
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

    void display(int x, vector<Airline> &airlines) const
    {
        quickSortAirline(airlines, 0, airlines.size() - 1, x);
        cout << setw(25) << "AirplaneID: " << AirplaneID << endl;
        cout << setw(25) << "Plane Max Capacity: " << Capacity << endl;
        cout << setw(25) << "Plane Brand: " << Company << endl;
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

    void display(int x, vector<Reservation> &reservations) const
    {
        quickSortReservation(reservations, 0, reservations.size() - 1, x);
        cout << setw(25) << "ReservationID: " << ReservationID << endl;
        cout << setw(25) << "Estimated Departure Time: " << DepartureTime << endl;
        cout << setw(25) << "Estimated Arrival Time: " << ArrivalTime << endl;
        cout << setw(25) << "Reservation Date: " << Date << endl;
        cout << setw(25) << "Arrival Destination: " << Location << endl;
        cout << setw(25) << "Class: " << Class << endl;
    }

    void displayLocation() const
    {
        cout << Location << " ";
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
        cout << setw(56) << "|      [0] Make a reservation         |" << endl;
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
        cout << setw(56) << "|      [1] Display Use                |" << endl;
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
        cout << setw(56) << "|      [4] By Class                   |" << endl;
        cout << setw(56) << "|      [5] By Food/Beverage           |" << endl;
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
        cout << setw(56) << "|      [4] By Class                   |" << endl;
        cout << setw(56) << "|      [5] By Food/Beverage           |" << endl;
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
        cout << setw(60) << "Welcome to Capybara International Airport (CiA)" << endl;
        cout << setw(45) << "Where to travel?:  " << endl
             << endl;
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

int binarySearchByName(const std::vector<User> &users, const std::string &name)
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

int binarySearchByIC(const std::vector<User> &users, const std::string &IC)
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

int binarySearchByPhone(const std::vector<User> &users, const std::string &Phone)
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

int binarySearchByEmail(const std::vector<User> &users, const std::string &Email)
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

int binarySearchByAirplaneID(std::vector<Airline> &airlines, const std::string &AirplaneID)
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

int binarySearchByCapacity(std::vector<Airline> &airlines, const std::string &Capacity)
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

int binarySearchByCompany(std::vector<Airline> &airlines, const std::string &Company)
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

int binarySearchByReservationID(std::vector<Reservation> &reservations, const std::string &ReservationID)
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

int binarySearchByDepartureTime(std::vector<Reservation> &reservations, const std::string &DepartureTime)
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

int binarySearchByArrivalTime(std::vector<Reservation> &reservations, const std::string &ArrivalTime)
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

int binarySearchByDate(std::vector<Reservation> &reservations, const std::string &Date)
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

int binarySearchByLocation(std::vector<Reservation> &reservations, const std::string &Location)
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
        case 0:
        {
            init.makeReservation();
            int i = 1;
            for (const auto &reservation : reservations)
            {
                cout << "[" << i << "] ";
                reservation.displayLocation();

                cout << endl
                     << "--------------------------" << endl;
                i++;
            }

            cout << "Select: ";
            cin >> option;
        }
        break;
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

                            for (const auto &user : users)
                            {
                                user.display(choice, users);
                                cout << "----------------------" << endl;
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
                                cout << setw(42) << "Insert the username: ";

                                getline(cin, username);
                                cout << endl;
                                quickSortUsers(users, 0, users.size() - 1, 1);
                                found = binarySearchByName(users, username);

                                users[found].displayBodo();
                            }

                            if (choice == 2)
                            {
                                string IC;
                                int found = 0;
                                cout << setw(42) << "Insert the IC: ";

                                getline(cin, IC);
                                cout << endl;
                                quickSortUsers(users, 0, users.size() - 1, 1);
                                found = binarySearchByIC(users, IC);

                                users[found].displayBodo();
                            }

                            if (choice == 3)
                            {
                                string Phone;
                                int found = 0;
                                cout << setw(42) << "Insert the Phone: ";

                                getline(cin, Phone);
                                cout << endl;
                                quickSortUsers(users, 0, users.size() - 1, 1);
                                found = binarySearchByPhone(users, Phone);

                                users[found].displayBodo();
                            }

                            if (choice == 4)
                            {
                                string Email;
                                int found = 0;
                                cout << setw(42) << "Insert the Email: ";

                                getline(cin, Email);
                                cout << endl;
                                quickSortUsers(users, 0, users.size() - 1, 1);
                                found = binarySearchByEmail(users, Email);

                                users[found].displayBodo();
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

                            for (const auto &airline : airlines)
                            {
                                airline.display(choice, airlines);
                                cout << "--------------------" << endl;
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
                                cout << endl;
                                quickSortAirline(airlines, 0, airlines.size() - 1, 1);
                                found = binarySearchByAirplaneID(airlines, AirplaneID);

                                users[found].displayBodo();
                            }

                            if (choice == 2)
                            {
                                string Capacity;
                                int found = 0;
                                cout << setw(42) << "Insert the Capacity: ";
                                cin.ignore();
                                getline(cin, Capacity);
                                cout << endl;
                                quickSortAirline(airlines, 0, airlines.size() - 1, 1);
                                found = binarySearchByCapacity(airlines, Capacity);

                                users[found].displayBodo();
                            }

                            if (choice == 3)
                            {
                                string Company;
                                int found = 0;
                                cout << setw(42) << "Insert the Company: ";
                                cin.ignore();
                                getline(cin, Company);
                                cout << endl;
                                quickSortAirline(airlines, 0, airlines.size() - 1, 1);
                                found = binarySearchByCompany(airlines, Company);

                                users[found].displayBodo();
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

                            for (const auto &reservation : reservations)
                            {
                                reservation.display(choice, reservations);
                                cout << "--------------------" << endl;
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
                                cout << setw(42) << "Insert the ReservationID: ";
                                cin.ignore();
                                getline(cin, ReservationID);
                                cout << endl;
                                quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                                found = binarySearchByReservationID(reservations, ReservationID);

                                users[found].displayBodo();
                            }

                            if (choice == 2)
                            {
                                string DepartureTime;
                                int found = 0;
                                cout << setw(42) << "Insert the DepartureTime: ";
                                cin.ignore();
                                getline(cin, DepartureTime);
                                cout << endl;
                                quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                                found = binarySearchByDepartureTime(reservations, DepartureTime);

                                users[found].displayBodo();
                            }

                            if (choice == 3)
                            {
                                string ArrivalTime;
                                int found = 0;
                                cout << setw(42) << "Insert the ArrivalTime: ";
                                cin.ignore();
                                getline(cin, ArrivalTime);
                                cout << endl;
                                quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                                found = binarySearchByArrivalTime(reservations, ArrivalTime);

                                users[found].displayBodo();
                            }

                            if (choice == 4)
                            {
                                string Date;
                                int found = 0;
                                cout << setw(42) << "Insert the Date: ";
                                cin.ignore();
                                getline(cin, Date);
                                cout << endl;
                                quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                                found = binarySearchByDate(reservations, Date);

                                users[found].displayBodo();
                            }

                            if (choice == 5)
                            {
                                string Location;
                                int found = 0;
                                cout << setw(42) << "Insert the Location: ";
                                cin.ignore();
                                getline(cin, Location);
                                cout << endl;
                                quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                                found = binarySearchByLocation(reservations, Location);

                                users[found].displayBodo();
                            }
                        }
                    }
                    else
                        cout << "Invalid Choice" << endl;

                    break;
                }
            }
            break;

            case 2:
            {
                int choice;
                init.displaySelection();
                cin >> choice;
                cout << endl;

                while (choice != 3)
                {
                    if (choice == 1)
                    {
                        init.displaySortingAirline();
                        cin >> choice;
                        cout << endl;
                    }
                    else if (choice == 2)
                    {
                        init.displaySeachingAirline();
                        cin >> choice;
                        cout << endl;
                    }
                    else
                        cout << "Invalid Choice" << endl;
                    break;
                }
            }
            break;

            case 3:
            {
                int choice = 0;
                init.displaySelection();
                cin >> choice;
                cout << endl;

                while (choice != 3)
                {
                    if (choice == 1)
                    {
                        init.displaySortingReservation();
                        cin >> choice;
                        cout << endl;
                    }
                    else if (choice == 2)
                    {
                        init.displaySeachingReservation();
                        cin >> choice;
                        cout << endl;
                    }
                    else
                        cout << "Invalid Choice" << endl;
                    break;
                }
                break;
            }
            default:
                cout << "Invalid Choice" << endl;
                return 1;
            }
        }
        break;
        default:
            cout << "Invalid Choice" << endl;
            return 1;
        }
    }
}
