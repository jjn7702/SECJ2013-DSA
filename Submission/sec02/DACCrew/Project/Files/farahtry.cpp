#include <iostream>
#include <iomanip>
#include <string>

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

    void print()
    {
        if (isEmpty())
        {
            cout << "No transactions in the stack!" << endl;
        }
        else
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

            nodeStack *temp = top;

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
        }
        cout << endl;
    }
};

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
        typestring="Deposit";
        transactionStack.push(date, typestring, amount, balance);
        break;
    case 'W':
        cout << "Enter withdrawal amount: ";
        cin >> amount;
        if (amount <= balance){
            balance -= amount;
            typestring="Withdrawal";
            transactionStack.push(date, typestring, amount, balance);
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
            typestring="Transfer";
            transactionStack.push(date, typestring, amount, balance);
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
        cout << "1. Display Transaction List" << endl
             << "2. Perform Transaction" << endl
             << "3. Exit" << endl
             << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            transactionStack.print();
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

    } while (choice != 3);

    return 0;
}
