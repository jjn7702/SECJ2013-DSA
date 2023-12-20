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

int read_data(Account acc[], const string& filename)
{
	
	string an, type, d, target;
	double b, amt;
	int n = 0;
	ifstream f1(filename);
	if(!f1)
	{
		cout<<"Error opening file: "<<filename<<endl;
		exit(0);
	}
	
	while(getline(f1,acc[n].account_number,','))
	{
		f1>>acc[n].balance;
		f1.ignore(); //ignore the comma
		
		getline(f1,d,',');
		acc[n].setTransactionDate(d);
		
		getline(f1,type,',');
		acc[n].setTransactionType(type);
		
		if(type == "DEPOSIT" || type == "WITHDRAWAL")
		{
			f1>>amt;
		}
		else if(type == "TRANSFER")
		{
			getline(f1,target,',');
			f1>>amt;
			acc[n].setTargetAccount(target);
		}
		f1.ignore();
		acc[n].setTransactionAmount(amt);
		n++;

	}
	
	f1.close();
	return n;
}

int main(){
	string filename;
	
	cout<<"Enter the input file name: ";
	cin>>filename;
	Account account[99];
	int count = read_data(account, filename);
	system("cls");
	
	bool menu = 1;
	while(menu)
	{
		int choice1, choice2;
		do
		{
			cout << "Menu of Account Checking : " << endl
				<< "1. Account Searching" << endl
				<< "2. Account List" << endl
				<< "Enter your choice: ";
			cin >> choice1;
			system("cls");

		} while (choice1 != 1 && choice1 != 2);

		if(choice1 == 1)
		{
			string accountSearch;
			cout << "Account : ";
			cin >>accountSearch;
			system("cls");

			cout << "Searched Account Details : \n";
			cout<<"--------------------------------------------------------------------------------------------------------------\n"
			<<"| Account Number | Balance(RM) | Transaction Date | Transaction Type | Amount(RM) | Transfered Account Number |\n"
			<<"--------------------------------------------------------------------------------------------------------------\n";
			account[searchAcc(account, accountSearch, count)].printDetails();
		}

		else{
            do{
                cout<<"Choose an option:\n"
                    <<"1. View all the transaction without sorting\n"
                    <<"2. View transactions sorted by date(oldest to newest)\n"
                    <<"3. View transactions sorted by date(newest to oldest)\n"
                    <<"4. View transactions sorted by balance(fewest to greatest)\n"
                    <<"5. View transactions sorted by balance(greatest to fewest)\n"
                    <<"Enter your choice: ";
                cin>>choice2;
                system("cls");
            } while (choice2 <= 0 && choice2 >= 6);

            if(choice2 > 1 && choice2 < 6)
            {
                quickSort(account, 0, count, choice2);
                cout << "Sorted Listed\n";
            }

            cout<<"--------------------------------------------------------------------------------------------------------------\n"
            <<"| Account Number | Balance(RM) | Transaction Date | Transaction Type | Amount(RM) | Transfered Account Number |\n"
            <<"--------------------------------------------------------------------------------------------------------------\n";
            for(int i =0; i < count; i++){
                account[i].printDetails();
            }
        }

		cout << "\n\n\n\nBack to menu (1: yes / 0: no) : ";
		cin >> menu;
		system("cls"); 
	}
		
	system("pause");
	return 0;
}
