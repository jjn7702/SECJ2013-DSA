#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#define D "Deposit"
#define W "Withdraw"
#define T "Transfer"
#define N 20 // Increased the size of the queue
using namespace std;

void dispHeader()
{
    for (int i = 0; i < 115; i++)
        cout << "-";
    cout << endl;
    cout << setw(30) << left << "| Sender Account "
         << "|"
         << setw(15) << left << " Date "
         << "|"
         << setw(30) << " Receiver Account "
         << "|"
         << setw(14) << " Type "
         << "|"
         << setw(10) << " Amount "
         << "|"
         << setw(10) << " Balance "
         << "|" << endl;
    for (int i = 0; i < 115; i++)
        cout << "-";
    cout << endl;
}

class Transaction
{
    string senderAcc, receiverAcc, date;
    double amount, balance;
    char type;

public:
    Transaction() : senderAcc(""), receiverAcc(""), date(""), amount(0.0), type(' '), balance(0.0) {}

    Transaction(string s, string d, char t, double a, double b) : senderAcc(s), date(d), receiverAcc(""), amount(a), type(t), balance(b) {}

    Transaction(string s, string d, char t, double a, double b, string r) : senderAcc(s), date(d), receiverAcc(r), amount(a), type(t), balance(b) {}

    void setSenderAcc(string s) { senderAcc = s; }
    void setReceiverAcc(string r) { receiverAcc = r; }
    void setAmount(double a) { amount = a; }
    void setBalance(double b) { balance = b; }
    void setType(char t) { type = t; }

    string getSenderAcc() const { return senderAcc; }
    string getReceiverAcc() const { return receiverAcc; }
    string getDate() const { return date; }
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
            cout << "The queue is full. Cannot insert new transaction." << endl;
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
                cout << "| " << setw(28) << left << list[i].getSenderAcc()
                     << "| "
                     << setw(14) << left << list[i].getDate()
                     << "| "
                     << setw(30) << list[i].getReceiverAcc()
                     << "| "
                     << setw(13) << list[i].getType()
                     << "| "
                     << setw(9) << list[i].getAmount()
                     << "| "
                     << setw(9) << list[i].getBalance()
                     << "| " << endl;
                for (int j = 0; j < 115; j++)
                    cout << "-";
                cout << endl;
            }

            cout << endl;
        }
    }

    void searchByAccount(string account) const
    {
        bool found = false;
        bool headerDisplayed = false;  // Flag to check if the header is displayed
        for (int i = front; i <= back; i++)
        {
            if (list[i].getSenderAcc() == account || list[i].getReceiverAcc() == account)
            {
                found = true;
                if (!headerDisplayed)
                {
                    dispHeader();
                    headerDisplayed = true;
                }
                found = true;
                cout << "| " << setw(28) << left << list[i].getSenderAcc()
                     << "| "
                     << setw(14) << left << list[i].getDate()
                     << "|"
                     << setw(30) << list[i].getReceiverAcc()
                     << "| "
                     << setw(13) << list[i].getType()
                     << "| "
                     << setw(9) << list[i].getAmount()
                     << "| "
                     << setw(9) << list[i].getBalance()
                     << "| " << endl;
                for (int j = 0; j < 115; j++)
                    cout << "-";
                cout << endl;
            }
        }

        if (!found)
            cout << "No transactions found for account: " << account << endl;
    }

    ~TransactionList()
    {
        delete[] list;
    }
};

void insertNewTransaction(TransactionList& list)
{
    string senderAcc, receiverAcc, date;
    double amount, balance;
    char type;

    cout << "Enter sender account: ";
    cin >> senderAcc;
    cout << "Enter date: ";
    cin >> date;
    cout << "Enter type (D/W/T): ";
    cin >> type;
    cout << "Enter amount: ";
    cin >> amount;
    cout << "Enter balance: ";
    cin >> balance;

    if (type == 'T')
    {
        cout << "Enter receiver account: ";
        cin >> receiverAcc;
        Transaction newNode(senderAcc, date, type, amount, balance, receiverAcc);
        list.enQueue(newNode);
    }
    else
    {
        Transaction newNode(senderAcc, date, type, amount, balance);
        list.enQueue(newNode);
    }

    cout << "Transaction inserted successfully." << endl;
}

int main()
{
    TransactionList list;

    fstream inputFile("accList.txt", ios::in);

    for (int i = 0; i < N; i++)
    {
        string senderAcc, date, receiverAcc;
        double amount, balance;
        char type;

        // Read the entire line
        string line;
        if (getline(inputFile, line))
        {
            // Use a stringstream to extract values from the line
            stringstream ss(line);
            if (ss >> senderAcc >> date >> type >> amount >> balance)
            {
                if (type == 'T')
                {
                    ss >> receiverAcc;
                    Transaction newNode(senderAcc, date, type, amount, balance, receiverAcc);
                    list.enQueue(newNode);
                }
                else
                {
                    Transaction newNode(senderAcc, date, type, amount, balance);
                    list.enQueue(newNode);
                }
            }
        }
    }

    int choice;
    string searchAccount;

    do
    {
        cout << "<<<<<WELCOME TO DACCrew BANKING MANAGEMENT SYSTEM>>>>>" << endl;
        cout << "1. Display Transaction List" << endl;
        cout << "2. Search Transaction History by Account" << endl;
        cout << "3. Insert New Transaction" << endl;
        cout << "4. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.printTransactionList();
            break;
        case 2:
            cout << "Enter the account to search: ";
            cin >> searchAccount;
            list.searchByAccount(searchAccount);
            break;
        case 3:
            insertNewTransaction(list);
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
