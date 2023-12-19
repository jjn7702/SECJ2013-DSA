#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

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

    string getName() const { return Name; }
    string getIC() const { return IC; }
    string getPhone() const { return Phone; }
    string getEmail() const { return Email; }

    void display() const
    {

        cout << "Name: " << Name << endl;
        cout << "Identification Number: " << IC << endl;
        cout << "Phone Number: " << Phone << endl;
        cout << " Email: " << Email << endl;
    }
};

class Airline
{
private:
    string AirplaneID;
    string Capacity;
    string Company;

public:
    Airline(string AirplaneID, string Capacity, string Company)
        : AirplaneID(AirplaneID), Capacity(Capacity), Company(Company) {}

    void display() const
    {
        cout << "AirplaneID: " << AirplaneID << endl;
        cout << "Plane Max Capacity: " << Capacity << endl;
        cout << "Plane Brand: " << Company << endl;
    }
};

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

    void display() const
    {
        cout << "ReservationID: " << ReservationID << endl;
        cout << "estimated Departure Time: " << DepartureTime << endl;
        cout << "Estimated Arrival Time: " << ArrivalTime << endl;
        cout << "Reservation Date: " << Date << endl;
        cout << "Arrival Destination: " << Location << endl;
        cout << "Class: " << Class << endl;
    }
};

class Init
{
public:
    void
    displayMenu()
    {
        // system("cls"); // to clear the mess
        cout << endl;
        cout << "                                   |" << endl;
        cout << "                                   |" << endl;
        cout << "                                   |" << endl;
        cout << "                                 .-'-." << endl;
        cout << "                                ' ___ '" << endl;
        cout << "                      ---------'  .-.  '---------" << endl;
        cout << "      _________________________'  '-'  '_________________________" << endl;
        cout << "       ''''''-|---|--/    \\==][^',_m_,'^][==/    \\--|---|-'''''' " << endl;
        cout << "                     \\    /  ||/   H   \\||  \\    /" << endl;
        cout << "                      '--'   OO   O|O   OO   '--'" << endl;

        cout << "Airline Reservation System" << endl;
        cout << "[0] Make a reservation" << endl;
        cout << "[1] Reservation Dashboard" << endl;
        cout << "[2] Exit" << endl;
        cout << "Option: ";
    }

    void displayReservationDashboard()
    {
        cout << "Reservation Dashboard" << endl;
        cout << "[1] Display User" << endl;
        cout << "[2] Display Airline" << endl;
        cout << "[3] Display Reservation" << endl;
        cout << "[4] Exit" << endl;
    }

    void displaySelection()
    {
        cout << "Choose Option" << endl;
        cout << "[1] Sort Data" << endl;
        cout << "[2] Search Data" << endl;
        cout << "Option: ";
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

    int binarySearchUser(const vector<User> &users, const string &key, int left, int right, int option)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            switch (option)
            {
            case 1:
                if (users[mid].getName() == key)
                    return mid;
                break;
            case 2:
                if (users[mid].getIC() == key)
                    return mid;
                break;
            case 3:
                if (users[mid].getPhone() == key)
                    return mid;
                break;
            case 4:
                if (users[mid].getEmail() == key)
                    return mid;
                break;
            default:
                break;
            }

            if (option == 1 && users[mid].getName() < key)
                left = mid + 1;
            else if (option == 2 && users[mid].getIC() < key)
                left = mid + 1;
            else if (option == 3 && users[mid].getPhone() < key)
                left = mid + 1;
            else if (option == 4 && users[mid].getEmail() < key)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1; // Not found
    }

    void readFromFile()
    {
        // read files
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

    getline(airlineFile, lineReservation); // skip the headings

    while (getline(airlineFile, lineReservation))
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
            cout << "hello";
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
                while (choice != 3)
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
                        }
                        else if (selection == 2)
                        {
                            // init.displaySeachingUser();
                            // cin >> choice;
                            // cout << endl;

                            string key;
                            cout << "Enter search key: ";
                            cin.ignore(); // Ignore the newline character left in the buffer
                            getline(cin, key);

                            // Perform binary search
                            int result = init.binarySearchUser(users, key, 0, users.size() - 1, choice);

                            // Display result
                            if (result != -1)
                            {
                                cout << "User found at index " << result << ":" << endl;
                                users[result].display();
                            }
                            else
                            {
                                cout << "User not found." << endl;
                            }
                        }

                        for (const auto &user : users)
                        {
                            user.display();
                            cout << "--------------------" << endl;
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
                        }
                        else if (selection == 2)
                        {
                            init.displaySeachingAirline();
                            cin >> choice;
                            cout << endl;
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
                        }
                        else if (selection == 2)
                        {
                            init.displaySeachingReservation();
                            cin >> choice;
                            cout << endl;
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
                int choice;
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