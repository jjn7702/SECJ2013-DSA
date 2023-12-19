#include <iostream>
#include <string>
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
    string Class;
    string FoodBeverage;

public:
    Airline(string AirplaneID, string Capacity, string Company, string Class, string FoodBeverage)
        : AirplaneID(AirplaneID), Capacity(Capacity), Company(Company), Class(Class), FoodBeverage(FoodBeverage) {}

    void display() const
    {
        cout << "AirplaneID: " << AirplaneID << endl;
        cout << "Plane Max Capacity: " << Capacity << endl;
        cout << "Plane Brand: " << Company << endl;
        cout << "Plane Class: " << Class << endl;
        cout << "Number customer require MEALS: " << FoodBeverage << endl;
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

public:
    Reservation(string ReservationID, string DepartureTime, string ArrivalTime, string Date, string Location)
        : ReservationID(ReservationID), DepartureTime(DepartureTime), ArrivalTime(ArrivalTime), Date(Date), Location(Location) {}

    void display() const
    {
        cout << "ReservationID: " << ReservationID << endl;
        cout << "estimated Departure Time: " << DepartureTime << endl;
        cout << "Estimated Arrival Time: " << ArrivalTime << endl;
        cout << "Reservation Date: " << Date << endl;
        cout << "Arrival Destination: " << Location << endl;
    }
};

void displayMenu()
{

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

    cout << "<<< AIRPLANE RESERVATION SYSTEM >>>" << endl;
    cout << "[1] Display User" << endl;
    cout << "[2] Display Airline" << endl;
    cout << "[3] Display Reservation" << endl;
    cout << "[4] Exit" << endl;
    cout << "Option" << endl;
}

void displaySelection()
{
    cout << "<<< Choose Option >>>" << endl;
    cout << "[1] Sort Data" << endl;
    cout << "[2] Search Data" << endl;
}

void displaySortingUser()
{
    cout << "<<< Sorting User >>>" << endl;
    cout << "[1] By Name" << endl;
    cout << "[2] By IC" << endl;
    cout << "[3] By Phone" << endl;
    cout << "[4] By Email" << endl;
    cout << "Option" << endl;
}

void displaySortingAirline()
{
    cout << "<<< Sorting Airline >>>" << endl;
    cout << "[1] By AirplaneID" << endl;
    cout << "[2] By Capacity" << endl;
    cout << "[3] By Company" << endl;
    cout << "[4] By Class" << endl;
    cout << "[5] By Food/Beverage" << endl;
    cout << "Option" << endl;
}

void displaySortingReservation()
{
    cout << "<<< Sorting Reservation >>>" << endl;
    cout << "[1] By ReservationID" << endl;
    cout << "[2] By DepartureTime" << endl;
    cout << "[3] By ArrivalTime" << endl;
    cout << "[4] By Date" << endl;
    cout << "[5] By Location" << endl;
    cout << "Option" << endl;
}

void displaySeachingUser()
{
    cout << "<<< Searching User >>>" << endl;
    cout << "[5] By Name" << endl;
    cout << "[6] By IC" << endl;
    cout << "[7] By Phone" << endl;
    cout << "[8] By Email" << endl;
    cout << "Option" << endl;
}

void displaySeachingAirline()
{
    cout << "<<< Searching Airline >>>" << endl;
    cout << "[6] By AirplaneID" << endl;
    cout << "[7] By Capacity" << endl;
    cout << "[8] By Company" << endl;
    cout << "[9] By Class" << endl;
    cout << "[10] By Food/Beverage" << endl;
    cout << "Option" << endl;
}

void displaySeachingReservation()
{
    cout << "<<< Searching Reservation >>>" << endl;
    cout << "[6] By ReservationID" << endl;
    cout << "[7] By DepartureTime" << endl;
    cout << "[8] By ArrivalTime" << endl;
    cout << "[9] By Date" << endl;
    cout << "[10] By Location" << endl;
    cout << "Option" << endl;
}

void readFromFile()
{
    // read files
}

int main()
{
    readFromFile();

    int option;
    while (true)
    {
        displayMenu();
        cin >> option;

        if (option == 4)
        {
            break;
        }

        switch (option)
        {
        case 1:
        {
            int choice;
            displaySelection();
            cin >> choice;

            while (choice != 3)
            {
                switch (choice)
                {
                case 1:
                    displaySortingUser();
                    break;
                case 2:
                    displaySeachingUser();
                    break;

                default:
                    cout << "Invalid Choice" << endl;
                    return 1;
                }
            }
            break;
        }

        case 2:
        {
            int choice;
            displaySelection();
            cin >> choice;

            while (choice != 3)
            {
                switch (choice)
                {
                case 1:
                    displaySortingAirline();
                    break;
                case 2:
                    displaySeachingAirline();
                    break;

                default:
                    cout << "Invalid Choice" << endl;
                    return 1;
                }
            }
            break;
        }

        case 3:
        {
            int choice;
            displaySelection();
            cin >> choice;

            while (choice != 3)
            {
                switch (choice)
                {
                case 1:
                    displaySortingReservation();
                    break;
                case 2:
                    displaySeachingReservation();
                    break;

                default:
                    cout << "Invalid Choice" << endl;
                    return 1;
                }
            }
            break;
        }
        default:
            cout << "Invalid Choice" << endl;
            return 1;
        }
    }
}