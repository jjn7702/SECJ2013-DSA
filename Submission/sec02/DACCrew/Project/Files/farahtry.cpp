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


void searchByDate(string searchDate)
{
    if (isEmpty())
    {
        cout << "\nNo transactions in the stack!" << endl;
        return;
    }

    bool found = false;
    nodeStack *temp = top;
    for (int i = 0; i < 63; i++)
        cout << "-";
    cout << endl;
    cout << setw(15) << left << "| Date "
         << "|"
         << setw(14) << " Type "
         << "|"
         << setw(15) << " Amount "
         << "|"
         << setw(15) << " Balance "
         << "|" << endl;

    for (int i = 0; i < 63; i++)
        cout << "-";
    cout << endl;

    while (temp)
    {
        if (temp->getDate() == searchDate)
        {
            found = true;
            cout << "| " << setw(13) << left << temp->getDate()
                 << "| "
                 << setw(13) << temp->getType()
                 << "| "
                 << setw(14) << temp->getAmount()
                 << "| "
                 << setw(14) << temp->getBalance()
                 << "| " << endl;

            for (int i = 0; i < 63; i++)
                cout << "-";
            cout << endl;
        }

        temp = temp->next;
    }

    if (!found)
        cout << "No matching transactions found." << endl << endl;

    cout << endl;
}

void searchByType(char searchType)
{
    if (isEmpty())
    {
        cout << "\nNo transactions in the stack!" << endl;
        return;
    }

    bool found = false;
    nodeStack *temp = top;

    for (int i = 0; i < 63; i++)
        cout << "-";
    cout << endl;
    cout << setw(15) << left << "| Date "
         << "|"
         << setw(14) << " Type "
         << "|"
         << setw(15) << " Amount "
         << "|"
         << setw(15) << " Balance "
         << "|" << endl;

    for (int i = 0; i < 63; i++)
        cout << "-";
    cout << endl;

    while (temp)
    {
        if (temp->getType()[0] == searchType) // Check the first character of the type
        {
            found = true;
            cout << "| " << setw(13) << left << temp->getDate()
                 << "| "
                 << setw(13) << temp->getType()
                 << "| "
                 << setw(14) << temp->getAmount()
                 << "| "
                 << setw(14) << temp->getBalance()
                 << "| " << endl;

            for (int i = 0; i < 63; i++)
                cout << "-";
            cout << endl;
        }

        temp = temp->next;
    }

    if (!found)
        cout << "\nNo matching transactions found." << endl;

    cout << endl;
}


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

    do
    {
        cout << "1. Check Balance" << endl
             << "2. Display Transaction List" << endl
             << "3. Perform Transaction" << endl
             << "4. Search for Transaction" << endl
             << "5. Exit" << endl
             << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Current Balance: " << balance << endl << endl;
            break;
        case 2:
            print(transactionStack, balance);
            break;
        case 3:
            performTransaction(transactionStack, balance);
            break;
        case 4:
            int searchChoice;
            cout << "\n[1] Search by Type" << endl
                 << "[2] Search by Date" << endl
                 << "[3] Back to Main Menu" << endl
                 << "Your choice:";
            cin >> searchChoice;
            if (searchChoice == 1)
            {
                char searchType;
                cout << "Enter transaction type (D: Deposit/W: Withdraw/T: Transfer): ";
                cin >> searchType;
                transactionStack.searchByType(searchType);
            }
            else if (searchChoice == 2)
            {
                string searchDate;
                cout << "Enter date (DD-MM-YYYY): ";
                cin >> searchDate;
                transactionStack.searchByDate(searchDate);
            }
            else if (searchChoice == 3)
                break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}