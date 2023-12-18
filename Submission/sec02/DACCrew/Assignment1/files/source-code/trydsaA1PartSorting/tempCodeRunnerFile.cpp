#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Bank
{
private:
    string accNum;
    double accBalance;
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

    void setName(string name)
    {
        accName = name;
    }
    string getName() const
    {
        return accName;
    }
    void setAccNum(string num)
    {
        accNum = num;
    }
    string getAccNum() const
    {
        return accNum;
    }
    void setIc(string num)
    {
        ic = num;
    }
    string getIc() const
    {
        return ic;
    }
    void setBalance(double g)
    {
        accBalance = g;
    }
    double getBalance() const
    {
        return accBalance;
    }

    void withdraw(double amount)
    {
        try
        {
            if (amount <= 0)
            {
                throw invalid_argument("Invalid withdrawal amount: Amount must be positive.");
            }
            if (accBalance < amount)
            {
                throw runtime_error("Insufficient funds for withdrawal.");
            }
            accBalance -= amount;
            cout << "Withdrawal of RM" << amount << " successful." << endl;
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
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

    void printDetail()
    {
        cout << "ACCOUNT INFORMATION" << endl;
        cout << "Account Holder's Name: " << accName << endl;
        cout << "Account Number: " << accNum << endl;
        // cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: RM" << accBalance << endl
             << endl;
    }

    void displaySort()
    {
        cout << accName <<setw(50)<< "|";
        cout << accNum <<setw(20)<< "|";
        cout << ic <<setw(14)<< "|";
        cout << accBalance <<setw(10)<<"|"<< endl;
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
        {
            sortByName(bl, first, cut);
        }
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
        {
            top--;
        }

        while (bl[bottom].getIc() < pivot)
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
        {
            sortByIc(bl, first, cut);
        }
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
        {
            top--;
        }

        while (bl[bottom].getAccNum() < pivot)
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
        {
            sortByAccNum(bl, first, cut);
        }
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
                {
                    top--;
                }
                else
                {
                    break;
                }
            }
            else
            {
                top--;
            }
        }

        while (bl[bottom].getBalance() < pivot || (bl[bottom].getBalance() == pivot && bottom != pivotI))
        {
            if (bl[bottom].getBalance() == pivot)
            {
                if (bl[bottom].getName() < bl[pivotI].getName())
                {
                    bottom++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                bottom++;
            }
        }

        if (bottom < top)
        {
            if (bottom == pivotI)
            {
                pivotI = top;
            }
            else if (top == pivotI)
            {
                pivotI = bottom;
            }

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
        {
            sortByBal(bl, first, cut);
        }
    }
}

int main()
{
    Bank bankList[100];
    fstream fileIn("Bank.txt", ios::in);
    string name, num, ic;
    float bal;
    int opt;

    if (!fileIn)
    {
        cout << "File input/output error!\n";
        return 1;
    }
    else
    {
        for (int a = 0; a < 4; a++)
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

            // s[a].display();
        }
    }
        fileIn.close();

        cout << ":: SORTING INTO DESCENDING ORDER" << endl;
        cout << "[1] Sort by name" << endl;
        cout << "[2] Sort by account number" << endl;
        cout << "[3] Sort by ic number" << endl;
        cout << "[4] Sort by balance" << endl;
        cout << "[5] Quit" << endl;
        cout << "OPTION >> ";
        cin >> opt;

        if (opt == 1)
        {
            cout << "Sort by name" << endl;
            sortByName(bankList, 0, 3);
        }
        else if (opt == 2)
        {
            cout << "Sort by Account Number." << endl;
            sortByAccNum(bankList, 0, 3);
        }
        else if (opt == 3)
        {
            cout << "Sort by Ic Number." << endl;
            sortByIc(bankList, 0, 3);
        }
        else if (opt == 4)
        {
            cout << "Sort by account balance" << endl;
            sortByBal(bankList, 0, 3);
        }

        else
        {
            return 0;
        }
        cout<<"| Name "<<setw(50)<<"|"<< " Account Number "<<setw(20)<<"|"<< " Ic Number "<<setw(14)<<"|"<<" Account Balance "<< setw(10)<<"|"<<endl;

        // Display the sorted results
        for (int z = 0; z < 4; z++)
        {
            bankList[z].displaySort();
        }
    }