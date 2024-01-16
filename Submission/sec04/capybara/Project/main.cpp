#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

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

        cout << endl;
        cout << setw(35) << "The primary booker is " << front->user_info << " with the baggage of " << front->baggage_info << endl
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
            cout << setw(25) << "Removed Ticket " << temp->user_info << " together with " << temp->baggage_info << " kg of baggage";
            cout << endl;
            delete temp;
            cout << setw(55) << "Reservation removed successfully." << endl;
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
            cout << endl;
            cout << setw(39) << "Destination: " << current->destination_info << endl;

            while (current != nullptr)
            {
                cout << setw(25) << "Name: " << current->user_info << " || Baggage Info: " << current->baggage_info << endl;
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

    cout << setw(56) << "/        Data has been updated      /" << endl;
    cout << setw(56) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
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
    cout << setw(46) << "Where do you wanna go?" << endl
         << endl;

    const int numDestinations = 5;
    string destinations[numDestinations] = {"New York", "Paris", "Tokyo", "London", "Sydney"};

    cout << setw(42) << "Destinations:" << endl;
    for (int i = 0; i < numDestinations; ++i)
    {
        cout << setw(30) << i + 1 << ". " << destinations[i] << endl;
    }

    cout << endl;

    int selectedDestination;

    cout << setw(58) << "________________________________________" << endl;
    cout << setw(59) << "| Enter the number of your destination: |" << endl;
    cout << setw(59) << "|_______________________________________|" << endl;

    cout << endl;
    cout << setw(39) << "Option: ";

    cin >> selectedDestination;
    cout << endl;

    if (selectedDestination >= 1 && selectedDestination <= numDestinations)
    {
        cout << setw(39) << "You selected: " << destinations[selectedDestination - 1] << endl;
        cout << setw(30) << "         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
             << endl;

        string user_info;
        double baggage_weight;
        int numPassengers = 0;

        cout << setw(53) << "How many passengers are there?: ";
        cin >> numPassengers;
        cout << endl;

        for (int i = 1; i <= numPassengers; i++)
        {
            cout << setw(39) << "Enter passenger " << i << " name: ";
            cin.ignore();
            getline(cin, user_info);

            cout << setw(53) << "Enter baggage weight (in kg): ";
            cin >> baggage_weight;
            cout << endl;
            reservationQueue.enqueue(user_info, to_string(baggage_weight), destinations[selectedDestination]);
        };

        cout << setw(56) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << setw(56) << "/   Reservation added successfully  /" << endl;

        writeToFile(reservationQueue);

        cout << setw(55) << "_____________________________________" << endl;
        cout << setw(56) << "|      Menu                           |" << endl;
        cout << setw(56) << "|      [1] Review All Ticket          |" << endl;
        cout << setw(56) << "|      [2] Cancel Ticket              |" << endl;
        cout << setw(56) << "|      [3] Show Primary Booker        |" << endl;
        cout << setw(56) << "|      [4] Edit Reservation Ticket    |" << endl;
        cout << setw(56) << "|      [5] Total Baggage Weight       |" << endl;
        cout << setw(56) << "|      [6] Exit                       |" << endl;
        cout << setw(56) << "|_____________________________________|" << endl
             << endl;

        int selection;
        cout << setw(39) << "Selection?: ";
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

                removeDataFromFile();
            }
            else if (selection == 3)
            {
                reservationQueue.showPrimaryBooker();
            }
            else if (selection == 4)
            {
                cout << setw(50) << "Enter passenger name to modify: ";
                cin.ignore();
                getline(cin, user_info);

                // Search for the passenger in the queue
                ReservationNode *current = reservationQueue.getFront();
                bool found = false;
                while (current != nullptr)
                {
                    if (current->user_info == user_info)
                    {
                        // Modify passenger information
                        string newName;

                        cout << setw(50) << "Enter a different user name: ";
                        getline(cin, newName);

                        cout
                            << setw(50) << "Enter new baggage weight (in kg): ";
                        cin >> baggage_weight;

                        current->user_info = newName;
                        current->baggage_info = to_string(baggage_weight);

                        cout << setw(59) << "Passenger information modified successfully." << endl;
                        cout << endl;
                        found = true;
                        break;
                    }
                    current = current->next;
                }

                if (!found)
                {
                    cout << setw(55) << "Passenger not found in the reservation list." << endl;
                }

                removeDataFromFile();
                writeToFile(reservationQueue);
            }
            else if (selection == 5)
            {
                double totalWeight = 0;

                ReservationNode *current = reservationQueue.getFront();
                while (current != nullptr)
                {
                    // Convert baggage_info to double and add to totalWeight
                    totalWeight += stod(current->baggage_info);
                    current = current->next;
                }

                cout << setw(55) << "Total baggage weight for reservations: " << totalWeight << " kg" << endl;
            }
            else if (selection == 6)
            {
                cout << setw(55) << "Thank You!" << endl;
                return 1;
            };

            cout << setw(55) << "_____________________________________" << endl;
            cout << setw(56) << "|      Menu                           |" << endl;
            cout << setw(56) << "|      [1] Review All Ticket          |" << endl;
            cout << setw(56) << "|      [2] Cancel Ticket              |" << endl;
            cout << setw(56) << "|      [3] Show Primary Booker        |" << endl;
            cout << setw(56) << "|      [4] Edit Reservation Ticket    |" << endl;
            cout << setw(56) << "|      [5] Total Baggage Weight       |" << endl;
            cout << setw(56) << "|      [6] Exit                       |" << endl;
            cout << setw(56) << "|_____________________________________|" << endl
                 << endl;

            cout << setw(39) << "Selection: ";
            cin >> selection;

        } while (selection >= 1 && selection <= 5);
    }
    else
    {
        cout << "Invalid destination selection." << endl;
    }

    return 0;
}