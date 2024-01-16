#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream> 


using namespace std;

class nodeStack
{
    string date;
    double amount, balance;
    string type;

public:
    nodeStack *next;
    nodeStack(string d, string t, double a, double b) : date(d), type(t), amount(a), balance(b), next(NULL) {}

    string getDate() const { return date; }
    string getType() const { return type; }
    double getAmount() const { return amount; }
    double getBalance() const { return balance; }
};

class stack
{
private:
    nodeStack *top;

public:
    stack() : top(NULL) {}

    bool isEmpty() const { return (top == NULL); }

    void push(string d, string t, double a, double b)
    {
        nodeStack *nn = new nodeStack(d, t, a, b);

        if (!isEmpty())
            nn->next = top;

        top = nn;
    }

    void pop()
    {
        if (isEmpty())
            cout << "Sorry, Cannot pop item from stack. Stack is still empty!" << endl;
        else
        {
            nodeStack *del = top;
            top = del->next;
            del->next = NULL;
            delete del;
        }
    }

    // Add this function to get access to the 'top' pointer
    nodeStack *getTop() const { return top; }
};

void saveToFile(stack &transactionStack)
{
    ofstream file("transaction_history.txt");

    if (file.is_open())
    {
        nodeStack *temp = transactionStack.getTop();
        while (temp)
        {
            file << temp->getDate() << "," << temp->getType() << "," << temp->getAmount() << "," << temp->getBalance() << "\n";
            temp = temp->next;
        }
        file.close();
        cout << "Transaction history saved to 'transaction_history.txt'." << endl;
    }
    else
    {
        cout << "Error opening the file." << endl;
    }
}

void readFromFile(stack &transactionStack, double &balance)
{
    ifstream file("transaction_history.txt");

    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {
            string date, type, amountStr, balanceStr;
            
            // Find the first two commas to separate date and type
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);

            if (pos1 != string::npos && pos2 != string::npos)
            {
                date = line.substr(0, pos1);
                type = line.substr(pos1 + 1, pos2 - pos1 - 1);
                amountStr = line.substr(pos2 + 1);

                // Convert amountStr to double (assuming the rest is the amount)
                double amount = stod(amountStr);

                // Update balance
                balance += amount;

                transactionStack.push(date, type, amount, balance);
            }
            else
            {
                cout << "Error processing line: " << line << endl;
            }
        }

        file.close();
        cout << "Transaction history loaded from 'transaction_history.txt'." << endl;
    }
    else
    {
        cout << "No existing transaction history file found." << endl;
    }
}




void print(const stack &transactionStack, double initialBalance)
{
    cout << setw(15) << left << "| Date "
         << "|"
         << setw(14) << " Type "
         << "|"
         << setw(10) << " Amount "
         << "|"
         << setw(10) << " Balance "
         << "|" << endl;

    for (int i = 0; i < 58; i++)
        cout << "-";
    cout << endl;

    nodeStack *temp = transactionStack.getTop();

    // Traverse from top to bottom
    while (temp)
    {
        temp = temp->next;
    }

    // Now temp is NULL, start from the bottom and move towards the top
    temp = transactionStack.getTop();

    while (temp)
    {
        cout << "| " << setw(14) << left << temp->getDate()
             << "| "
             << setw(13) << temp->getType()
             << "| "
             << setw(9) << temp->getAmount()
             << "| "
             << setw(9) << temp->getBalance()
             << "| " << endl;

        for (int i = 0; i < 58; i++)
            cout << "-";
        cout << endl;

        temp = temp->next;
    }

    cout << "| " << setw(14) << left << "Current"
         << "| "
         << setw(13) << "Balance"
         << "| "
         << setw(9) << ""
         << "| "
         << setw(9) << initialBalance
         << "| " << endl;

    for (int i = 0; i < 58; i++)
        cout << "-";
    cout << endl
         << endl;
}


void performTransaction(stack &transactionStack, double &balance)
{
    string date;
    double amount;
    char type;
    string typestring;

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
        typestring = "Deposit";
        transactionStack.push(date, typestring, amount, balance);
        saveToFile(transactionStack);
        break;
    case 'W':
        cout << "Enter withdrawal amount: ";
        cin >> amount;
        if (amount <= balance)
        {
            balance -= amount;
            typestring = "Withdrawal";
            transactionStack.push(date, typestring, amount, balance);
            saveToFile(transactionStack);
        }
        else
            cout << "Insufficient funds for withdrawal." << endl;
        break;
    case 'T':
        cout << "Enter transfer amount: ";
        cin >> amount;
        if (amount <= balance)
        {
            balance -= amount;
            typestring = "Transfer";
            transactionStack.push(date, typestring, amount, balance);
            saveToFile(transactionStack);
        }
        else
            cout << "Insufficient funds for transfer." << endl;
        break;
    default:
        cout << "Invalid transaction type." << endl;
        return;
    }

    cout << "Transaction completed successfully." << endl;
}

int main()
{
    stack transactionStack;
    double balance = 0.0;

    int choice;

    cout << "\n<<<<< WELCOME TO DACCrew BANKING MANAGEMENT SYSTEM >>>>>\n"
         << endl;

    // Load transactions from file at the start
    readFromFile(transactionStack, balance);

    do
    {

        cout << "1. Display Transaction List" << endl
             << "2. Perform Transaction" << endl
             
             << "5. Exit" << endl
             << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            print(transactionStack, balance);
            break;
        case 2:
            performTransaction(transactionStack, balance);
            break;
       
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
