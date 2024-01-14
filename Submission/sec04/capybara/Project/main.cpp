#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

int main()
{
    // Creating Queue
    QueueReservation Reservation;

    // Data Initialization
    Reservation.displayQueueReservation();

    return 0;
}