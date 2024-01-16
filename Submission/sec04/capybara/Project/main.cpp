#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const int MAX_COMPANION_ADULTS = 10;
const int MAX_COMPANION_CHILDREN = 10;

void newCheckIn(string &pID, string &fNumber, string &sNumber, string &dFlight, string &tFlight);

//! Code STACK
class Stack
{
public:
    Stack *next;

    string passangerName;
    string baggageID;
    string typeBaggage;
    string baggageWeight;
    string baggageCheckIn;

    string passengerId;
    string flightNumber;
    string seatNumber;
    string dateFlight;
    string timeFlight;

    Stack(string pId, string &pName, string &bID, string &typBaggage, string &bWeight, string &bCheckIn)
    {
        passengerId = pId;
        passangerName = pName;
        baggageID = bID;
        typeBaggage = typBaggage;
        baggageWeight = bWeight;
        baggageCheckIn = bCheckIn;

        next = NULL;
    }

    Stack(string pId, string fNumber, string sNumber, string dFlight, string tFlight)
    {
        passengerId = pId;
        flightNumber = fNumber;
        seatNumber = sNumber;
        dateFlight = dFlight;
        timeFlight = tFlight;
        next = NULL;
    }

    string getPassangerName() const
    {
        return passangerName;
    }

    string getBaggageID() const
    {
        return baggageID;
    }

    string getTypeBaggage() const
    {
        return typeBaggage;
    }

    string getBaggageWeight() const
    {
        return baggageWeight;
    }

    string getBaggageCheckIn() const
    {
        return baggageCheckIn;
    }

    string getFlightNumber()
    {
        return flightNumber;
    }

    string getSeatNumber()
    {
        return seatNumber;
    }

    string getDateFlight()
    {
        return dateFlight;
    }

    string getTimeFlight()
    {
        return timeFlight;
    }

    string getPassengerId()
    {
        return passengerId;
    }
};

class StackList
{
private:
    Stack *top;

public:
    StackList()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void pushBaggage(string &passangerName, string &baggageID, string &typeBaggage, string &baggageWeight, string &baggageCheckIn)
    {
        Stack *newNode = new Stack(passangerName, baggageID, typeBaggage, baggageWeight, baggageCheckIn);

        if (!isEmpty())
        {
            newNode->next = top;
        }
        top = newNode;
    }

    void pushCheckIn(string &pID, string &fNumber, string &sNumber, string &dFlight, string &tFlight)
    {
        Stack *newNode = new Stack(pID, fNumber, sNumber, dFlight, tFlight);

        if (!isEmpty())
        {
            newNode->next = top;
        }
        top = newNode;

        // add new data
    }

    void popBaggage()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No baggage to pop." << endl;
        }
        else
        {
            Stack *temp = top;
            top = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void popCheckIn()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No check-in data to pop." << endl;
        }
        else
        {
            Stack *temp = top;
            top = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void displayStackBaggage()
    {
        Stack *temp = top;
        while (temp)
        {
            cout << "Name: " << temp->getPassangerName() << endl;
            cout << "Baggage ID: " << temp->getBaggageID() << endl;
            cout << "Type of Baggage: " << temp->getTypeBaggage() << endl;
            cout << "Baggaga Weight: " << temp->getBaggageWeight() << endl;
            cout << "Baggage Checked In: " << temp->getBaggageCheckIn() << endl;
            cout << endl;

            temp = temp->next;
        }
        cout << endl;
    }

    void displayStackCheckIn()
    {
        Stack *temp = top;
        while (temp)
        {
            cout << "Passenger ID : " << temp->getPassengerId() << endl;
            cout << "Flight ID: " << temp->getFlightNumber() << endl;
            cout << "Seat Number: " << temp->getSeatNumber() << endl;
            cout << "Date Flight: " << temp->getDateFlight() << endl;
            cout << "Time Flight: " << temp->getTimeFlight() << endl;
            cout << endl;

            temp = temp->next;
        }
        cout << endl;
    }

    // void display semua babi
};

//! Code QUEUE
class Reservation
{
public:
    string passengerName;
    string seatNumber;

    Reservation(const string &name, const string &seat) : passengerName(name), seatNumber(seat) {}
};

class Node
{
    Reservation data;
    Node *next;

public:
    Node(const Reservation &d) : data(d), next(NULL) {}

    Reservation getData()
    {
        return data;
    }

    friend class Queue; // So Queue can access private members of Node
};

class Queue
{
    Node *front;
    Node *back;

public:
    Queue() : front(NULL), back(NULL) {}

    bool isEmpty()
    {
        return front == NULL;
    }

    void enQueue(const Reservation &d)
    {
        Node *newNode = new Node(d);
        if (isEmpty())
        {
            front = back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Nothing in the Queue!!" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            if (front == NULL)
                back = NULL;
            delete temp;
        }
    }

    Reservation getFront()
    {
        if (!isEmpty())
        {
            return front->getData();
        }
        else
        {
            // Handle empty queue case
            return Reservation("", "");
        }
    }

    void print()
    {
        Node *temp = front;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                Reservation res = temp->getData();
                cout << res.passengerName << " (" << res.seatNumber << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

class Seat
{
public:
    string seatNumber;
    bool isBooked;

    Seat() : seatNumber(""), isBooked(false) {}

    void setSeatNumber(const string &number)
    {
        seatNumber = number;
    }
};

class Flight
{
public:
    string airline, destination, takeoffTime;

    Flight(const string &a, const string &d, const string &t)
        : airline(a), destination(d), takeoffTime(t) {}
};

class AirlineReservationSystem
{
private:
    Seat seats[5][6];
    Queue reservations;
    Flight flight;

public:
    AirlineReservationSystem(const Flight &f) : flight(f)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                seats[i][j].setSeatNumber((i < 2 ? 'A' : 'B') + to_string(i + 1) + char('1' + j));
            }
        }
    }

    void displaySeats() const
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (j == 3)
                {
                    cout << "   ";
                }
                cout << "[" << seats[i][j].seatNumber << (seats[i][j].isBooked ? " X" : " O") << "] ";
            }
            cout << endl;
        }
    }

    void displayFlightInfo() const
    {
        cout << "Airline: " << flight.airline << endl;
        cout << "Destination: " << flight.destination << endl;
        cout << "Takeoff Time: " << flight.takeoffTime << endl;
    }

    void makeReservation(const string &passengerName, const string &seatNumber)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (seats[i][j].seatNumber == seatNumber && !seats[i][j].isBooked)
                {
                    seats[i][j].isBooked = true;
                    reservations.enQueue(Reservation(passengerName, seatNumber));
                    cout << "Reservation successful for " << passengerName << " at seat " << seatNumber << endl;
                    return;
                }
            }
        }
        cout << "Reservation failed: Seat not available or does not exist." << endl;
    }
};

// buat newdata function

int main()
{

    //! Output Stack
    StackList BS;

    ifstream inputFile("data/baggage.csv");

    if (inputFile.is_open())
    {
        string line;

        getline(inputFile, line);

        while (getline(inputFile, line))
        {
            istringstream iss(line);
            string passangerName, baggageID, typeBaggage, baggageWeight, baggageCheckIn;

            if (getline(iss, passangerName, ',') && getline(iss, baggageID, ',') && getline(iss, typeBaggage, ',') && getline(iss, baggageWeight, ',') && getline(iss, baggageCheckIn, ','))
            {
                BS.pushBaggage(passangerName, baggageID, typeBaggage, baggageWeight, baggageCheckIn);
            }
            else
            {
                cout << "Error: " << line << endl;
            }
        }
        inputFile.close();
    }
    else
    {
        cout << "Error while opening file: " << endl;
        return 1;
    }

    StackList checkIn; // Fix the identifier name
    ifstream userFile("data/checkin.csv");
    string lineUser;
    string passengerID, flightNumber, seatNumber, dateFlight, timeFlight;

    getline(userFile, lineUser); // skip the headings

    while (getline(userFile, lineUser))
    {
        stringstream ss(lineUser); // get the whole line
        getline(ss, passengerID, ',');
        getline(ss, flightNumber, ',');
        getline(ss, seatNumber, ',');
        getline(ss, dateFlight, ',');
        getline(ss, timeFlight, ',');
        checkIn.pushCheckIn(passengerID, flightNumber, seatNumber, dateFlight, timeFlight);
    }

    userFile.close();

    cout << "Add new data: ";
    cin >> passengerID >> flightNumber >> seatNumber >> dateFlight >> timeFlight;
    checkIn.pushCheckIn(passengerID, flightNumber, seatNumber, dateFlight, timeFlight);
    newCheckIn(passengerID, flightNumber, seatNumber, dateFlight, timeFlight);

    checkIn.displayStackCheckIn(); // Display the updated stack

    // checkIn.displayStackCheckIn(); // Use correct identifier

    //! Output Queue
    Flight flightInfo("Example Airline", "New York", "10:00");
    AirlineReservationSystem system(flightInfo);

    system.displayFlightInfo();
    system.displaySeats();

    system.makeReservation("arif", "A11");
    system.makeReservation("megat", "B32");
    system.makeReservation("Derf", "B41");

    system.displaySeats();

    return 0;
}