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
class Node
{
public:
    int userID;
    string userName;

    // adultInfo
    int companionAdultIDs[MAX_COMPANION_ADULTS];
    string companionAdultNames[MAX_COMPANION_ADULTS];
    int numCompanionAdults;

    // childrenInfo
    int companionChildIDs[MAX_COMPANION_CHILDREN];
    string companionChildNames[MAX_COMPANION_CHILDREN];
    int companionChildAges[MAX_COMPANION_CHILDREN];

    int numCompanionChildren;

    Node *next;

    Node(int id, string userName) : userID(id), userName(userName), next(NULL), numCompanionAdults(0), numCompanionChildren(0) {}
};

class QueueReservation
{
public:
    Node *backPtr, *frontPtr;

    QueueReservation()
    {
        createQueueReservation();
    };

    void createQueueReservation()
    {
        backPtr = NULL;
        frontPtr = NULL;
    };

    bool isEmpty()
    {
        return backPtr == NULL && frontPtr == NULL;
    };

    void enQueueReservation(Node *newUser)
    {
        if (isEmpty())
        {
            newUser->next = newUser;
            backPtr = newUser;
            frontPtr = newUser;
        }
        else
        {
            newUser->next = backPtr->next;
            backPtr->next = newUser;
            backPtr = newUser;
        }
    }

    void displayQueueReservation()
    {
        Node *temp = frontPtr;

        if (isEmpty())
        {
            cout << "\nThe queue is empty\n";
        };
        while (temp->next != frontPtr)
        {
            cout << "Passenger ID: " << temp->userID << ", Name: " << temp->userName << endl;

            cout << "Companion Adults: ";
            for (int i = 0; i < temp->numCompanionAdults; ++i)
            {
                cout << "ID: " << temp->companionAdultIDs[i] << ", Name: " << temp->companionAdultNames[i] << " | ";
            }
            cout << endl;

            cout << "Companion Children: ";
            for (int i = 0; i < temp->numCompanionChildren; ++i)
            {
                cout << "ID: " << temp->companionChildIDs[i] << ", Name: " << temp->companionChildNames[i] << ", Age: " << temp->companionChildAges[i] << " | ";
            }
            cout << endl;

            temp = temp->next;

            cout << endl;
        }

        cout << "Passenger ID: " << temp->userID << ", Name: " << temp->userName << endl;

        cout << "Companion Adults: ";
        for (int i = 0; i < temp->numCompanionAdults; ++i)
        {
            cout << "ID: " << temp->companionAdultIDs[i] << ", Name: " << temp->companionAdultNames[i] << " | ";
        }
        cout << endl;

        cout << "Companion Children: ";
        for (int i = 0; i < temp->numCompanionChildren; ++i)
        {
            cout << "ID: " << temp->companionChildIDs[i] << ", Name: " << temp->companionChildNames[i] << ", Age: " << temp->companionChildAges[i] << " | ";
        }
        cout << endl;

        temp = temp->next;

        cout << endl;
    }

    void deQueueReservation()
    {
        Node *delQueue = frontPtr;

        if (isEmpty())
        {
            cout << "\nNo one is in queue\n";
        }
        else if (frontPtr == backPtr)
        {
            frontPtr = backPtr = NULL;
            delete delQueue;
        }
        else
        {
            frontPtr = frontPtr->next;
            backPtr->next = frontPtr;
            delete delQueue;
        };
    }
    void peekQueueReservation()
    {
        if (isEmpty())
        {
            cout << "The queue is empty\n";
        }
        else
        {
            cout << "Passenger ID: " << frontPtr->userID << ", Name: " << frontPtr->userName << endl;
            cout << "Companion Adults: ";
            for (int i = 0; i < frontPtr->numCompanionAdults; ++i)
            {
                cout << "ID: " << frontPtr->companionAdultIDs[i] << ", Name: " << frontPtr->companionAdultNames[i] << " | ";
            }
            cout << endl;

            cout << "Companion Children: ";
            for (int i = 0; i < frontPtr->numCompanionChildren; ++i)
            {
                cout << "ID: " << frontPtr->companionChildIDs[i] << ", Name: " << frontPtr->companionChildNames[i] << ", Age: " << frontPtr->companionChildAges[i] << " | ";
            }
            cout << endl;
        }
    }
};

void newCheckIn(string &pID, string &fNumber, string &sNumber, string &dFlight, string &tFlight)
{

    ofstream reservationFile("data/checkin.csv", ios::app);
    reservationFile.seekp(0, ios::end);
    reservationFile << "\n"
                    << pID << "," << fNumber << "," << sNumber << "," << dFlight << "," << tFlight;

    reservationFile.seekp(0, ios::end);
    reservationFile.close();
};

// buat newdata function

int main()
{
    // Creating Queue
    QueueReservation Reservation;

    // Data Initialization
    // Reservation.displayQueueReservation();

    //? Kena buang line atas untuk tgk Stack
    //* Stack akan ada function display, add and delete yg proper after this

    //! Output Stack
    StackList BS;

    ifstream inputFile("data/baggage.csv");

    if (inputFile.is_open())
    {
        string line;

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

    return 0;
}