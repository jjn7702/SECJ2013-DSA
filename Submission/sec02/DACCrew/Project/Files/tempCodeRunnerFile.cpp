#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define D "Deposit"
#define W "Withdraw"
#define T "Transfer"
#define N 11
using namespace std;

void dispHeader()
{
    for (int i = 0; i < 99; i++)
        cout << "-";
    cout << endl;
    cout << setw(30) << left << "| Sender Account "
         << "|"
         << setw(30) << " Receiver Account "
         << "|"
         << setw(14) << " Type "
         << "|"
         << setw(10) << " Amount "
         << "|"
         << setw(10) << " Balance "
         << "|" << endl;
    for (int i = 0; i < 99; i++)
        cout << "-";
    cout << endl;
}

class Transaction
{
    string senderAcc, receiverAcc;
    double amount, balance;
    char type;

public:
    Transaction() : senderAcc(""), receiverAcc(""), amount(0.0), type(' '), balance(0.0) {}

    Transaction(string s, char t, double a, double b) : senderAcc(s), receiverAcc(""), amount(a), type(t), balance(b) {}

    Transaction(string s, char t, double a, double b, string r) : senderAcc(s), receiverAcc(r), amount(a), type(t), balance(b) {}

    void setSenderAcc(string s) { senderAcc = s; }
    void setReceiverAcc(string r) { receiverAcc = r; }
    void setAmount(double a) { amount = a; }
    void setBalance(double b) { balance = b; }
    void setType(char t) { type = t; }

    string getSenderAcc() const { return senderAcc; }
    string getReceiverAcc() const { return receiverAcc; }
    double getAmount() const { return amount; }
    double getBalance() const { return balance; }
    string getType() const
    {
        if (type == 'D')
            return D;
        else if (type == 'W')
            return W;
        else
            return T;
    }
};

class TransactionList
{
    Transaction *list;
    int front, back;

public:
    TransactionList() : front(0), back(-1)
    {
        list = new Transaction[N];
        for (int i = 0; i < N; ++i)
        {
            list[i] = Transaction();
        }
    }

    bool isEmpty() const { return back < front; }
    bool isFull() const { return back == (N - 1); }

    void enQueue(Transaction t)
    {
        if (isFull())
            cout << "The queue is full" << endl;
        else
            list[++back] = t;
    }

    void deQueue()
    {
        if (isEmpty())
            cout << "The queue is empty" << endl;
        else
            front++;
    }

    Transaction getFront() const { return list[front]; }
    Transaction getRear() const { return list[back]; }

    void printTransactionList() const
    {
        if (isEmpty())
            cout << "Sorry, no items in the queue" << endl;
        else
        {
            dispHeader();
            for (int i = front; i <= back; i++)
            {
                cout << "|" << setw(29) << left << list[i].getSenderAcc()
                     << "|"
                     << setw(30) << list[i].getReceiverAcc()
                     << "|"
                     << setw(14) << list[i].getType()
                     << "|"
                     << setw(10) << list[i].getAmount()
                     << "|"
                     << setw(10) << list[i].getBalance()
                     << "|" << endl;

                for (int j = 0; j < 99; j++)
                    cout << "-";
                cout << endl;
            }

            cout << endl;
        }
    }

    ~TransactionList()
    {
        delete[] list;
    }
};

int main()
{
    TransactionList list;

    fstream inputFile("accList.txt");

    if (!inputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return 1; // Exit with an error code
    }

    for (int i = 0; i < N; i++)
    {
        string senderAcc, receiverAcc;
        double amount, balance;
        char type;

        if (inputFile >> senderAcc >> type >> amount >> balance)
        {
            if (type == 'T')
            {
                inputFile >> receiverAcc;
                Transaction newNode(senderAcc, type, amount, balance, receiverAcc);
                list.enQueue(newNode);
            }
            else
            {
                Transaction newNode(senderAcc, type, amount, balance);
                list.enQueue(newNode);
            }
        }
    }

    int choice;

    do
    {
        cout << "<<<<<WELCOME TO DACCrew BANKING MANAGEMENT SYSTEM>>>>>" << endl;
        cout << "1. Display Transaction List" << endl;
        cout << "2. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.printTransactionList();
            break;
        case 2:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 2);

    return 0;
}
