#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

class Account{
	public:
		string account_number;
		double balance;
		string transaction_date;
		string transaction_type;
		double transaction_amount;
		string target_account; //for transfer
	
		Account(string an = "", double b = 0.0) : account_number(an), balance(b) {}
		
		void setTransactionDate(string d){ transaction_date = d; }
		
		void setTransactionType(string t){ transaction_type = t; }
		
		void setTransactionAmount(double amt){ transaction_amount = amt; }
		
		void setTargetAccount(string num){ target_account = num; }
		
		void printDetails(){
			cout<<"   "<<left;
			cout<<setw(17)<<account_number
				<<setw(14)<<balance
				<<setw(19)<<transaction_date
				<<setw(19)<<transaction_type<<setw(13)<<transaction_amount;
			if(!target_account.empty())
				cout<<target_account;
			else
				cout<<"-";
			cout<<endl;
		}
		
};


int partition(Account acc[], int first, int last, int type)
{
    Account pivot = acc[first];
    Account temp;
    int loop, cutPoint, bottom, top;

    bottom = first; top = last;
    loop = 1;

	 while (loop)
    {

        if(type == 2)
        {
            while (acc[top].transaction_date < pivot.transaction_date) { top--; }
            while (acc[bottom].transaction_date > pivot.transaction_date) { bottom++; }
        }
        else if(type == 3)
        {   
            while (acc[top].transaction_date > pivot.transaction_date) { top--; }
            while (acc[bottom].transaction_date < pivot.transaction_date) { bottom++; }
        }
        else if(type == 4)
        {
            while (acc[top].balance > pivot.balance) { top--; }
            while (acc[bottom].balance < pivot.balance) { bottom++; }
        }
		else
        {
            while (acc[top].balance < pivot.balance) { top--; }
            while (acc[bottom].balance > pivot.balance) { bottom++; }
        }
        

        if (bottom < top)
        {
            temp = acc[bottom];
            acc[bottom] = acc[top];
            acc[top] = temp;
        }
        else
        {
            loop = 0;
            cutPoint = top;
        }
    }
    return cutPoint;
}

void quickSort(Account acc[], int first , int last, int type)
{
    int cut;
    if (first < last)
    {
        cut = partition(acc, first, last, type);
        quickSort(acc, first, cut, type);
        quickSort(acc, cut+1, last, type);
    }
}

int searchAcc(Account acc[], string searchKey, int n)
{
	int index = -1;

	for(int i =0; i < n; i++)
	{
		if(searchKey == acc[i].account_number)
		{
			index = i;
			break;
		}
	}

	return index;
}

