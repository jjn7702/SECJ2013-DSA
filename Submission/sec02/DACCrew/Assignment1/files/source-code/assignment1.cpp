#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void dispHeader()
{
    for(int i = 0; i < 106; i++)
        cout << "-";
    cout << endl;
    cout << setw(50) << left << "| Name " << "|" 
             << setw(20) << " Account Number " << "|" 
             << setw(14) << " Ic Number " << "|" 
             << setw(18) << " Account Balance " << "|" << endl;
    for(int i = 0; i < 106 ; i++)
        cout << "-";
    cout << endl;
}

class Bank
{
private:
    string accNum;
    double accBalance;
    string pin;
    string accName;
    string ic;

public:
    Bank(int a = 0, double b = 0, string n = "", int ic = 0)
    {
        accNum = a;
        accBalance = b;
        accName = n;
        ic = ic;
    }

    void setName(string name) { accName = name; }
    string getName() const { return accName; }
    void setAccNum(string num) { accNum = num; }
    string getAccNum() const { return accNum; }
    void setIc(string num) { ic = num; }
    string getIc() const { return ic; }
    void setBalance(double g) { accBalance = g; }
    double getBalance() const { return accBalance; }

    void withdraw(double amount)
    {
        try
        {
            if (amount <= 0)
                throw invalid_argument("Invalid withdrawal amount: Amount must be positive.");
            if (accBalance < amount)
                throw runtime_error("Insufficient funds for withdrawal.");
            accBalance -= amount;
            cout << "Withdrawal of RM" << amount << " successful." << endl;
        }
        catch (const exception &e)
        { cerr << "Error: " << e.what() << endl; }
            
    }

    void deposit(double depo)
    {
        accBalance += depo;
    }

    /*void transfer(Account &A, float c)
    {
        accBalance -= c;
        A.deposit(c);
    }*/

    void displaySort()
    {
        cout << "| " << setw(48) << accName
             << "| " << setw(19) << accNum
             << "| " << setw(13) << ic
             << "| " << setw(17) << accBalance << "|" << endl;
        for(int i = 0; i < 106 ; i++)
            cout << "-";
        cout << endl;   
    }
};

int partitionName(Bank bl[], int first, int last)
{
    string pivot = bl[first].getName();
    Bank temp;
    int cutPoint;
    int bottom = first;
    int top = last;
    int loop = true;

    while (loop)
    {
        while (bl[top].getName() > pivot)
        {
            top--;
        }

        while (bl[bottom].getName() < pivot)
        {
            bottom++;
        }

        if (bottom < top)
        {
            temp = bl[top];
            bl[top] = bl[bottom];
            bl[bottom] = temp;
        }
        else
        {
            loop = false;
            cutPoint = top;
        }
    }

    return cutPoint;
}

void sortByName(Bank bl[], int first, int last)
{
    if (first < last)
    {
        int cut;
        cut = partitionName(bl, first, last);

        if (cut != last)
        {
            sortByName(bl, first, cut);
            sortByName(bl, cut + 1, last);
        }
        else
            sortByName(bl, first, cut);
    }
}

int partitionAccNum(Bank bl[], int first, int last)
{
    string pivot = bl[first].getAccNum();
    Bank temp;
    int cutPoint;
    int bottom = first;
    int top = last;
    int loop = true;

    while (loop)
    {
        while (bl[top].getAccNum() > pivot)
            top--;

        while (bl[bottom].getAccNum() < pivot)
            bottom++;

        if (bottom < top)
        {
            temp = bl[top];
            bl[top] = bl[bottom];
            bl[bottom] = temp;
        }
        else
        {
            loop = false;
            cutPoint = top;
        }
    }

    return cutPoint;
}

void sortByAccNum(Bank bl[], int first, int last)
{
    if (first < last)
    {
        int cut;
        cut = partitionAccNum(bl, first, last);

        if (cut != last)
        {
            sortByAccNum(bl, first, cut);
            sortByAccNum(bl, cut + 1, last);
        }
        else
            sortByAccNum(bl, first, cut);
    }
}
int partitionIc(Bank bl[], int first, int last)
{
    string pivot = bl[first].getIc();
    Bank temp;
    int cutPoint;
    int bottom = first;
    int top = last;
    int loop = true;

    while (loop)
    {
        while (bl[top].getIc() > pivot)
            top--;

        while (bl[bottom].getIc() < pivot)
            bottom++;

        if (bottom < top)
        {
            temp = bl[top];
            bl[top] = bl[bottom];
            bl[bottom] = temp;
        }
        else
        {
            loop = false;
            cutPoint = top;
        }
    }

    return cutPoint;
}

void sortByIc(Bank bl[], int first, int last)
{
    if (first < last)
    {
        int cut;
        cut = partitionIc(bl, first, last);

        if (cut != last)
        {
            sortByIc(bl, first, cut);
            sortByIc(bl, cut + 1, last);
        }
        else
            sortByIc(bl, first, cut);
    }
}
int partitionBal(Bank bl[], int first, int last)
{
    int pivotI = (first + last) / 2;
    double pivot = bl[pivotI].getBalance();
    Bank temp;
    int cutPoint;
    int bottom = first;
    int top = last;
    int loop = true;

    while (loop)
    {
        while (bl[top].getBalance() > pivot || (bl[top].getBalance() == pivot && top != pivotI))
        {
            if (bl[top].getBalance() == pivot)
            {
                if (bl[top].getName() > bl[pivotI].getName())
                    top--;
                else
                    break;
            }
            else
                top--;
        }

        while (bl[bottom].getBalance() < pivot || (bl[bottom].getBalance() == pivot && bottom != pivotI))
        {
            if (bl[bottom].getBalance() == pivot)
            {
                if (bl[bottom].getName() < bl[pivotI].getName())
                    bottom++;
                else
                    break;
            }
            else
                bottom++;
        }

        if (bottom < top)
        {
            if (bottom == pivotI)
                pivotI = top;
            else if (top == pivotI)
                pivotI = bottom;

            temp = bl[top];
            bl[top] = bl[bottom];
            bl[bottom] = temp;
        }
        else
        {
            loop = false;
            cutPoint = top;
        }
    }

    return cutPoint;
}

void sortByBal(Bank bl[], int first, int last)
{
    if (first < last)
    {
        int cut;
        cut = partitionBal(bl, first, last);

        if (cut != last)
        {
            sortByBal(bl, first, cut);
            sortByBal(bl, cut + 1, last);
        }
        else
            sortByBal(bl, first, cut);
    }
}

//Searching
void searchByName(Bank bl[], int size, const string& searchName)
{
    bool found = false;

    cout << "Search Results for Name: " << searchName << endl;

    for (int i = 0; i < size; i++)
    {
        if (bl[i].getName() == searchName)
        {
            dispHeader();
            bl[i].displaySort();
            found = true;
        }
    }

    if (!found)
        cout << "No matching records found for the given name." << endl;
}

void searchByAccNum(Bank bl[], int size, const string& searchAccNum)
{
    bool found = false;

    cout << "Search Results for Account Number: " << searchAccNum << endl;

    for (int i = 0; i < size; i++)
    {
        if (bl[i].getAccNum() == searchAccNum)
        {
            dispHeader();
            bl[i].displaySort();
            found = true;
        }
    }

    if (!found)
        cout << "No matching records found for the given account number." << endl;
}

void searchByIc(Bank bl[], int size, const string& searchIc)
{
    bool found = false;

    cout << "Search Results for IC Number: " << searchIc << endl;

    for (int i = 0; i < size; i++)
    {
        if (bl[i].getIc() == searchIc)
        {
            dispHeader();
            bl[i].displaySort();
            found = true;
        }
    }

    if (!found)
        cout << "No matching records found for the given IC number." << endl;
}

int main()
{
    Bank bankList[100];
    fstream fileIn("Bank.txt", ios::in);
    string name, num, ic;
    float bal;
    int opt;
    int idx=0;

    if (!fileIn)
    {
        cout << "File input/output error!\n";
        return 1;
    }
    else
    {   int a=0;
        while (!fileIn.eof())
        {
            getline(fileIn, name, '|');
            getline(fileIn, num, '|');
            getline(fileIn, ic, '|');
            fileIn >> bal;
            fileIn.ignore();
            bankList[a].setName(name);
            bankList[a].setAccNum(num);
            bankList[a].setIc(ic);
            bankList[a].setBalance(bal);
            a++;
            idx++;
    
            // s[a].display();
        }
    }
        fileIn.close();

        cout << ":: SORTING INTO ASCENDING ORDER ::" << endl;
        cout << "[1] Sort by Name" << endl;
        cout << "[2] Sort by Account Number" << endl;
        cout << "[3] Sort by IC Number" << endl;
        cout << "[4] Sort by Balance" << endl << endl;

        cout << ":: SEARCH BY ::" << endl;
        cout << "[5] Search by Name" << endl;
        cout << "[6] Search by Account Number" << endl;
        cout << "[7] Search by IC Number" << endl << endl;

        cout << ":: OTHER ACTION ::" << endl;
        cout << "[8] Quit" << endl;
        cout << "OPTION >> ";
        cin >> opt;

        if(opt >= 1 && opt <= 4)
        {
            switch (opt)
            {
                case 1:
                    cout << "Sort by name" << endl;
                    dispHeader();
                    sortByName(bankList, 0, idx);
                    break;
                case 2:
                    cout << "Sort by Account Number" << endl;
                    dispHeader();
                    sortByAccNum(bankList, 0, idx);
                    break;
                case 3:
                    cout << "Sort by IC Number" << endl;
                    dispHeader();
                    sortByIc(bankList, 0, idx);
                    break;
                default:
                    cout << "Sort by account balance" << endl;
                    dispHeader();
                    sortByBal(bankList, 0, idx);
                    break;
            }
           
            // Display the sorted resultss
            for (int z = 1; z <=idx; z++)
                bankList[z].displaySort();
        }/*
        else if(opt >= 5 && opt <= 7)
        {
            if(opt == 5)
            {
                string searchName;
                cout << "Enter the name to search: ";
                cin.ignore(); 
                getline(cin, searchName);
                searchByName(bankList, 4, searchName);
            }
            else if(opt == 6)
            {
                string searchAccNum;
                cout << "Enter the account number to search: ";
                cin.ignore(); // Ignore newline character in the input buffer
                getline(cin, searchAccNum);
                searchByAccNum(bankList, 4, searchAccNum);
            }
            else
            {
                string searchIc;
                cout << "Enter the IC number to search: ";
                cin.ignore();
                getline(cin, searchIc);
                searchByIc(bankList, 4, searchIc);
            }
        }
        else
        {
            cout << "Shutting down system...";
            return 0;
        }
}
