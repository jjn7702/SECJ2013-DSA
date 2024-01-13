#include <iostream>
#include <fstream>
#include <string>
#include "json/single_include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

const int MAX_COMPANION_ADULTS = 10;
const int MAX_COMPANION_CHILDREN = 10;

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

    void enQueueReservation(Node *newUser) // make it circular
    {
        if (isEmpty())
        {
            newUser->next = newUser;
            backPtr = newUser;
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
        while (temp != NULL)
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
    }

    void deQueueReservation(){

    };
};

void getData(QueueReservation &Reservation)
{
    ifstream userFile("data/user.json");

    if (!userFile.is_open())
    {
        cout << "\nThere is a problem to obtain the file.\n";
    }

    json jsonArray;

    userFile >> jsonArray;

    for (const auto &passenger : jsonArray["passengers"])
    {
        int passengerID = passenger["passengerID"];
        string passengerName = passenger["name"];

        Node *newPassenger = new Node(passengerID, passengerName);

        // Companion Adults

        int indexAdult = 0;
        for (const auto &adult : passenger["companionAdults"])
        {
            int adultID = adult["passengerID"];
            string adultName = adult["name"];
            newPassenger->companionAdultIDs[indexAdult] = adultID;
            newPassenger->companionAdultNames[indexAdult] = adultName;
            ++indexAdult;
        }
        newPassenger->numCompanionAdults = indexAdult;

        // Companion Children
        int indexChild = 0;
        for (const auto &child : passenger["companionChildren"])
        {
            int childID = child["passengerID"];
            string childName = child["childName"];
            int childAge = child["age"];
            newPassenger->companionChildIDs[indexChild] = childID;
            newPassenger->companionChildNames[indexChild] = childName;
            newPassenger->companionChildAges[indexChild] = childAge;
            ++indexChild;
        }

        newPassenger->numCompanionChildren = indexChild;

        Reservation.enQueueReservation(newPassenger);
    };
}

int main()
{

    // Creating Queue
    QueueReservation Reservation;

    // Data Initialization
    getData(Reservation);
    Reservation.displayQueueReservation();

    return 0;
}