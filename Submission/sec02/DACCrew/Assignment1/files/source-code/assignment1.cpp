#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Account
{
	private:
	string name;
	string accNum;
	string ic; 
  string pin;
	double accBalance;

	public:
	Account (string n="", string a=0, string i="", double b=0.0)
		:name(n),accNum(a),ic(i),accBalance(b){}

	string getName(string name)
	{
		return name;  
	}

	string getAccNum(string accNum)
	{
		return accNum;
	}

	string getIc(string ic)
	{
		return ic;
	}

	double getBalance(double accBalance)
	{
		return accBalance;
	}

	void setName(string name)
	{
		name = name;
	}

	void setAccNum(string accNum)
	{
		accNum = accNum;
	}

	void setName(string ic)
	{
		ic = ic;
	}

	void setName(string name)
	{
		name = name;
	}

	void Withdraw()
	{

	}

	void Deposit()
	{

	}

	void display()
	{
		//display account details (all attributes)
		//what have been done this withdraw/deposit
	}
};


int partitionName(Account bl[], int first, int last)
{
    string pivot = bl[first].getName();
    Account temp;
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

void sortByName(Account bl[], int first, int last)
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

int partitionIc(Account bl[], int first, int last)
{
    string pivot = bl[first].getIc();
    Account temp;
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

void sortByIc(Account bl[], int first, int last)
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

int partitionAccNum(Account bl[], int first, int last)
{
    string pivot = bl[first].getAccNum();
    Account temp;
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

void sortByAccNum(Account bl[], int first, int last)
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
int partitionBal(Account bl[], int first, int last)
{
    int pivotI = (first + last) / 2;
    double pivot = bl[pivotI].getBalance();
    Account temp;
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

void sortByBal(Account bl[], int first, int last)
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



