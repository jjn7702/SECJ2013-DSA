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
        cout << "Name: " << Name << endl;
        cout << "Identification Number: " << IC << endl;
        cout << "Phone Number: " << Phone << endl;
        cout << "Email: " << Email << endl;
    }

    void display(int x, vector<User> &users) const
    {

        quickSortUsers(users, 0, users.size() - 1, x);
        cout << "Name: " << Name << endl;
        cout << "Identification Number: " << IC << endl;
        cout << "Phone Number: " << Phone << endl;
        cout << "Email: " << Email << endl;
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
        cout << "AirplaneID: " << AirplaneID << endl;
        cout << "Plane Max Capacity: " << Capacity << endl;
        cout << "Plane Brand: " << Company << endl;
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
        cout << "ReservationID: " << ReservationID << endl;
        cout << "Estimated Departure Time: " << DepartureTime << endl;
        cout << "Estimated Arrival Time: " << ArrivalTime << endl;
        cout << "Reservation Date: " << Date << endl;
        cout << "Arrival Destination: " << Location << endl;
        cout << "Class: " << Class << endl;
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
        system("cls");     // to clear the mess
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
        cout << "Sorting User" << endl;
        cout << "[1] By Name" << endl;
        cout << "[2] By IC" << endl;
        cout << "[3] By Phone" << endl;
        cout << "[4] By Email" << endl;
        cout << "Option: ";
    }

    void displaySortingAirline()
    {
        cout << "Sorting Airline" << endl;
        cout << "[1] By AirplaneID" << endl;
        cout << "[2] By Capacity" << endl;
        cout << "[3] By Company" << endl;
        cout << "[4] By Class" << endl;
        cout << "[5] By Food/Beverage" << endl;
        cout << "Option: ";
    }

    void displaySortingReservation()
    {
        cout << "Sorting Reservation" << endl;
        cout << "[1] By ReservationID" << endl;
        cout << "[2] By DepartureTime" << endl;
        cout << "[3] By ArrivalTime" << endl;
        cout << "[4] By Date" << endl;
        cout << "[5] By Location" << endl;
        cout << "Option: ";
    }

    void displaySeachingUser()
    {
        cout << "Searching User" << endl;
        cout << "[1] By Name" << endl;
        cout << "[2] By IC" << endl;
        cout << "[3] By Phone" << endl;
        cout << "[4] By Email" << endl;
        cout << "Option: ";
    }

    void displaySeachingAirline()
    {
        cout << "Searching Airline" << endl;
        cout << "[1] By AirplaneID" << endl;
        cout << "[2] By Capacity" << endl;
        cout << "[3] By Company" << endl;
        cout << "[4] By Class" << endl;
        cout << "[5] By Food/Beverage" << endl;
        cout << "Option: ";
    }

    void displaySeachingReservation()
    {
        cout << "Searching Reservation" << endl;
        cout << "[1] By ReservationID" << endl;
        cout << "[2] By DepartureTime" << endl;
        cout << "[3] By ArrivalTime" << endl;
        cout << "[4] By Date" << endl;
        cout << "[5] By Location" << endl;
        cout << "Option: ";
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

        cout << "Welcome to Capybara International Airport (CiA)" << endl;
        cout << "Where to travel?:  " << endl
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

template <typename T, typename Key>
int binarySearch(const vector<T> &items, const Key &key)
{
    int low = 0;
    int high = items.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (items[mid] == key)
        {
            return mid; // Item found at index mid
        }
        else if (items[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Item not found
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
                 << "Which operation would you like to choose?" << endl;
            cout << "Option: ";
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
                                cout << "Insert the username: ";

                                getline(cin, username);
                                quickSortUsers(users, 0, users.size() - 1, 1);
                                found = binarySearch(users, username);

                                users[found].displayBodo();
                            }

                            if (choice == 2)
                            {
                                string IC;
                                int found = 0;
                                cout << "Insert the IC: ";

                                getline(cin, IC);
                                quickSortUsers(users, 0, users.size() - 1, 1);
                                found = binarySearch(users, IC);

                                users[found].displayBodo();
                            }

                            if (choice == 3)
                            {
                                string Phone;
                                int found = 0;
                                cout << "Insert the Phone: ";

                                getline(cin, Phone);
                                quickSortUsers(users, 0, users.size() - 1, 1);
                                found = binarySearch(users, Phone);

                                users[found].displayBodo();
                            }

                            if (choice == 4)
                            {
                                string Email;
                                int found = 0;
                                cout << "Insert the Email: ";

                                getline(cin, Email);
                                quickSortUsers(users, 0, users.size() - 1, 1);
                                found = binarySearch(users, Email);

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
                                cout << "Insert the AirplaneID: ";
                                cin.ignore();
                                getline(cin, AirplaneID);
                                quickSortAirline(airlines, 0, airlines.size() - 1, 1);
                                found = binarySearch(airlines, AirplaneID);

                                users[found].displayBodo();
                            }

                            if (choice == 2)
                            {
                                string Capacity;
                                int found = 0;
                                cout << "Insert the Capacity: ";
                                cin.ignore();
                                getline(cin, Capacity);
                                quickSortAirline(airlines, 0, airlines.size() - 1, 1);
                                found = binarySearch(airlines, Capacity);

                                users[found].displayBodo();
                            }

                            if (choice == 3)
                            {
                                string Company;
                                int found = 0;
                                cout << "Insert the Company: ";
                                cin.ignore();
                                getline(cin, Company);
                                quickSortAirline(airlines, 0, airlines.size() - 1, 1);
                                found = binarySearch(airlines, Company);

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
                                cout << "Insert the ReservationID: ";
                                cin.ignore();
                                getline(cin, ReservationID);
                                quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                                found = binarySearch(reservations, ReservationID);

                                users[found].displayBodo();
                            }

                            if (choice == 2)
                            {
                                string DepartureTime;
                                int found = 0;
                                cout << "Insert the DepartureTime: ";
                                cin.ignore();
                                getline(cin, DepartureTime);
                                quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                                found = binarySearch(reservations, DepartureTime);

                                users[found].displayBodo();
                            }

                            if (choice == 3)
                            {
                                string ArrivalTime;
                                int found = 0;
                                cout << "Insert the ArrivalTime: ";
                                cin.ignore();
                                getline(cin, ArrivalTime);
                                quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                                found = binarySearch(reservations, ArrivalTime);

                                users[found].displayBodo();
                            }

                            if (choice == 4)
                            {
                                string Date;
                                int found = 0;
                                cout << "Insert the Date: ";
                                cin.ignore();
                                getline(cin, Date);
                                quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                                found = binarySearch(reservations, Date);

                                users[found].displayBodo();
                            }

                            if (choice == 5)
                            {
                                string Location;
                                int found = 0;
                                cout << "Insert the Location: ";
                                cin.ignore();
                                getline(cin, Location);
                                quickSortReservation(reservations, 0, reservations.size() - 1, 1);
                                found = binarySearch(reservations, Location);

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