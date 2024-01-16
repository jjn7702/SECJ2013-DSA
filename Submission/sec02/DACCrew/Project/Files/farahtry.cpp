#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
#define D "Deposit"
#define W "Withdraw"
#define T "Transfer"
using namespace std;

void dispHeader()
{
    for (int i = 0; i < 115; i++)
        cout << "-";
    cout << endl;
    cout << setw(15) << left << "| Date "
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
    string date;
    double amount, balance;
    char type;

public:
    Transaction() : date(""), amount(0.0), type(' '), balance(0.0) {}

    Transaction(string d, char t, double a, double b) : date(d), amount(a), type(t), balance(b) {}

    void setDate(string d) { date = d; }
    void setAmount(double a) { amount = a; }
    void setBalance(double b) { balance = b; }
    void setType(char t) { type = t; }

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
    queue<Transaction> transactionQueue;

public:
    bool isEmpty() const { return transactionQueue.empty(); }

    void enqueueTransaction(Transaction t)
    {
        transactionQueue.push(t);
    }

    void printTransactionList() const
    {
        if (isEmpty())
            cout << "Sorry, no transactions available." << endl;
        else
        {
            dispHeader();
            queue<Transaction> tempQueue = transactionQueue; // Create a temporary queue for display
            while (!tempQueue.empty())
            {
                Transaction currentTransaction = tempQueue.front();
                tempQueue.pop();
                cout << "| " << setw(14) << left << currentTransaction.getDate()
                     << "| "
                     << setw(13) << currentTransaction.getType()
                     << "| "
                     << setw(9) << currentTransaction.getAmount()
                     << "| "
                     << setw(9) << currentTransaction.getBalance()
                     << "| " << endl;
                for (int j = 0; j < 115; j++)
                    cout << "-";
                cout << endl;
            }
            cout << endl;
        }
    }
};

void performTransaction(TransactionList &transactionList, double &balance)
{
    string date;
    double amount;
    char type;

    cout << "Enter date (DD-MM-YYYY): ";
    cin >> date;
    cout << "Enter transaction type (D: Deposit/W: Withdraw/T: Transfer): ";
    cin >> type;

    switch (type)
    {
    case 'D':
        cout << "Enter deposit amount: ";
        cin >> amount;
        balance += amount;
        break;
    case 'W':
        cout << "Enter withdrawal amount: ";
        cin >> amount;
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient funds for withdrawal." << endl;
        break;
    case 'T':
        cout << "Enter transfer amount: ";
        cin >> amount;
        if (amount <= balance)
        {
            balance -= amount;
            Transaction newTransaction(date, type, amount, balance);
            transactionList.enqueueTransaction(newTransaction);
        }
        else
            cout << "Insufficient funds for transfer." << endl;
        break;
    default:
        cout << "Invalid transaction type." << endl;
        return;
    }

    Transaction newTransaction(date, type, amount, balance);
    transactionList.enqueueTransaction(newTransaction);
    cout << "Transaction completed successfully." << endl;
}

int main()
{
    TransactionList transactionList;
    double balance = 0.0;

    int choice;

    cout << "\n<<<<<WELCOME TO DACCrew BANKING MANAGEMENT SYSTEM>>>>>\n"
         << endl;

    do
    {
        cout << "1. Display Transaction List" << endl
             << "2. Perform Transaction" << endl
             << "3. Exit" << endl
             << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            transactionList.printTransactionList();
            break;
        case 2:
            performTransaction(transactionList, balance);
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
