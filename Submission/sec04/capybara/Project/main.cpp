#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct ReservationNode
{
    string destination_info;
    string user_info;
    string baggage_info;
    ReservationNode *next;

    ReservationNode(string user, string baggage, string destination) : user_info(user), baggage_info(baggage), destination_info(destination), next(nullptr) {}
};

class ReservationQueue
{
private:
    ReservationNode *front;
    ReservationNode *rear;

public:
    ReservationQueue() : front(nullptr), rear(nullptr) {}

    ReservationNode *getFront()
    {
        return front;
    }

    void showPrimaryBooker()
    {

        if (isEmpty())
        {
            cout << "There are no reservations made\n";
        };
        cout << "The primary booker is " << front->user_info << " with the baggage of " << front->baggage_info << endl
             << endl;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(string user_info, string baggage_info, string destination_info)
    {
        ReservationNode *new_reservation = new ReservationNode(user_info, baggage_info, destination_info);
        if (isEmpty())
        {
            front = rear = new_reservation;
        }
        else
        {
            rear->next = new_reservation;
            rear = new_reservation;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No reservations to dequeue." << endl;
        }
        else
        {
            ReservationNode *temp = front;
            front = front->next;
            cout << endl;
            cout << "Removed Ticket " << temp->user_info << " together with " << temp->baggage_info << " kg of baggage";
            cout << endl;
            delete temp;
            cout << "Reservation removed successfully." << endl;
        }
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            ReservationNode *current = front;
            cout << "\nDestination: " << current->destination_info << endl;

            while (current != nullptr)
            {
                cout << "Name: " << current->user_info << ", Baggage Info: " << current->baggage_info << endl;
                current = current->next;
            }

            cout << endl;
        }
    }
};

void writeToFile(ReservationQueue &reservationQueue)
{
    ofstream outFile("reservation.csv");

    if (!outFile.is_open())
    {
        cerr << "Error opening file " << endl;
    }

    ReservationNode *current = reservationQueue.getFront();

    outFile << "Passenger Name, Baggage Weight, Destination Info\n";

    while (current != nullptr)
    {
        outFile << current->user_info << "," << current->baggage_info << "," << current->destination_info << endl;
        current = current->next;
    }

    outFile.close();

    cout << "Data has been updated" << endl
         << endl;
}

void removeDataFromFile()
{
    ofstream file("reservation.csv", ios::trunc);

    file << "passengerName, baggageweight, destination";
};

int main()
{
    ReservationQueue reservationQueue;

    cout << "Welcome to Capybara Airport" << endl;
    cout << "Where do you wanna go?" << endl
         << endl;

    const int numDestinations = 5;
    string destinations[numDestinations] = {"New York", "Paris", "Tokyo", "London", "Sydney"};

    cout << "Destinations:" << endl;
    for (int i = 0; i < numDestinations; ++i)
    {
        cout << i + 1 << ". " << destinations[i] << endl;
    }

    cout << endl;

    int selectedDestination;
    cout << "Enter the number of your destination: ";
    cin >> selectedDestination;

    if (selectedDestination >= 1 && selectedDestination <= numDestinations)
    {
        cout << "\nYou selected: " << destinations[selectedDestination - 1] << endl
             << endl;

        string user_info;
        double baggage_weight;
        int numPassengers = 0;

        cout << "How many passengers are there?: ";
        cin >> numPassengers;
        cout << endl;

        for (int i = 1; i <= numPassengers; i++)
        {
            cout << "Enter passenger " << i << " name: ";
            cin.ignore();
            getline(cin, user_info);

            cout << "Enter baggage weight (in kg): ";
            cin >> baggage_weight;
            cout << endl;
            reservationQueue.enqueue(user_info, to_string(baggage_weight), destinations[selectedDestination]);
        };
        cout << "Reservation added successfully." << endl;
        writeToFile(reservationQueue);

        cout
            << "Menu" << endl;
        cout << "[1] Review All Ticket" << endl;
        cout << "[2] Cancel Ticket" << endl;
        cout << "[3] Show Primary Booker" << endl;
        cout << "[4] Exit" << endl;

        int selection;
        cout << "\nSelection?: ";
        cin >> selection;

        do
        {
            if (selection == 1)
            {
                reservationQueue.displayQueue();
            }
            else if (selection == 2)
            {
                for (int i = 0; i < numPassengers; i++)
                    reservationQueue.dequeue();
            }
            else if (selection == 3)
            {
                reservationQueue.showPrimaryBooker();
            }
            else if (selection == 4)
            {
                cout << "Thank You!" << endl;
                return 1;
            };

            cout << "\nMenu" << endl;
            cout << "[1] Review All Ticket" << endl;
            cout << "[2] Cancel Ticket" << endl;
            cout << "[3] Show Primary Booker" << endl;
            cout << "[4] Exit" << endl;

            cout << "\nSelection: ";
            cin >> selection;

        } while (selection >= 1 && selection <= 3);
    }
    else
    {
        cout << "Invalid destination selection." << endl;
    }

    return 0;
}