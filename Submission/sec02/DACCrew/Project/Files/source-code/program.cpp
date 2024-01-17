
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
        for (int i = 0; i < 54; i++)
            cout << "-";
        cout << endl;
        cout << setw(16) << left << "| Date "
             << "|"
             << setw(14) << " Type "
             << "|"
             << setw(10) << " Amount "
             << "|"
             << setw(10) << " Balance "
             << "|" << endl;

        for (int i = 0; i < 54; i++)
            cout << "-";
        cout << endl;

        while (temp)
        {
            if (temp->getDate() == searchDate)
            {
                found = true;
                cout << "| " << setw(14) << left << temp->getDate()
                     << "| "
                     << setw(13) << temp->getType()
                     << "| "
                     << setw(9) << temp->getAmount()
                     << "| "
                     << setw(9) << temp->getBalance()
                     << "| " << endl;

                for (int i = 0; i < 54; i++)
                    cout << "-";
                cout << endl
                     << endl;
            }

            temp = temp->next;
        }

        if (!found)
            cout << "\nNo matching transactions found." << endl
                 << endl;

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

        for (int i = 0; i < 54; i++)
            cout << "-";
        cout << endl;
        cout << setw(16) << left << "| Date "
             << "|"
             << setw(14) << " Type "
             << "|"
             << setw(10) << " Amount "
             << "|"
             << setw(10) << " Balance "
             << "|" << endl;

        for (int i = 0; i < 54; i++)
            cout << "-";
        cout << endl;

        while (temp)
        {
            if (temp->getType()[0] == searchType) // Check the first character of the type
            {
                found = true;
                cout << "| " << setw(14) << left << temp->getDate()
                     << "| "
                     << setw(13) << temp->getType()
                     << "| "
                     << setw(9) << temp->getAmount()
                     << "| "
                     << setw(9) << temp->getBalance()
                     << "| " << endl;

                for (int i = 0; i < 54; i++)
                    cout << "-";
                cout << endl
                     << endl;
            }

            temp = temp->next;
        }

        if (!found)
            cout << "\nNo matching transactions found." << endl;

        cout << endl;
    }
};


void print(const stack &transactionStack, double initialBalance)
{
    for (int i = 0; i < 54; i++)
        cout << "-";
    cout << endl;
    cout << setw(16) << left << "| Date "
         << "|"
         << setw(14) << " Type "
         << "|"
         << setw(10) << " Amount "
         << "|"
         << setw(10) << " Balance "
         << "|" << endl;

    for (int i = 0; i < 54; i++)
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

        for (int i = 0; i < 54; i++)
            cout << "-";
        cout << endl
             << endl;

        temp = temp->next;
    }
}

//save to file function
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
