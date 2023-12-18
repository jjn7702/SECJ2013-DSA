#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

class Account{
	private:
		string account_number;
		double balance;
		string transaction_date;
		string transaction_type;
		double transaction_amount;
		string target_account; //for transfer
	
	public:
		Account(string an, double b) : account_number(an), balance(b) {}
		
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


template <typename T>
int partition(vector<T>& data, int first, int last) {
    T pivot, temp;
    int loop, cutPoint, bottom, top;

    pivot = data[first];

    bottom = first;
    top = last;

    while (bottom < top) {
        while (data[top] < pivot)
            top--;

        while (data[bottom] > pivot)
            bottom++;

        if (bottom < top) {
            temp = data[bottom];
            data[bottom] = data[top];
            data[top] = temp;
        }
    }

    cutPoint = top;

    return cutPoint;
}

template <typename T>
void quickSort(vector<T>& data, int first, int last) {
    if (first < last) {
        int cut = partition(data, first, last);
        quickSort(data, first, cut);
        quickSort(data, cut + 1, last);
    }
}

vector<Account> read_data(const string& filename){
	
	string an, type, d, target;
	double b, amt;
	ifstream f1(filename);
	if(!f1){
		cout<<"Error opening file: "<<filename<<endl;
		exit(0);
	}
	
	vector<Account> acc;
	while(getline(f1,an,',')){
		f1>>b;
		f1.ignore(); //ignore the comma
		Account a(an,b);
		
		getline(f1,d,',');
		a.setTransactionDate(d);
		
		getline(f1,type,',');
		a.setTransactionType(type);
		
		if(type == "DEPOSIT" || type == "WITHDRAWAL"){
			f1>>amt;
		}
		else if(type == "TRANSFER"){
			getline(f1,target,',');
			f1>>amt;
			a.setTargetAccount(target);
		}
		f1.ignore();
		a.setTransactionAmount(amt);
		acc.push_back(a);
	}
	
	f1.close();
	return acc;
}

int main(){
	string filename;
	
	cout<<"Enter the input file name: ";
	cin>>filename;
	vector<Account> account = read_data(filename);
	cout<<"--------------------------------------------------------------------------------------------------------------\n"
		<<"| Account Number | Balance(RM) | Transaction Date | Transaction Type | Amount(RM) | Transfered Account Number |\n"
		<<"--------------------------------------------------------------------------------------------------------------\n";
	for(Account& a: account){
		a.printDetails();
	}
	
	int choice;
	cout<<"\nChoose an option:\n"
		<<"1. View all the transaction without sorting\n"
		<<"2. View transactions sorted by date(oldest to newest)\n"
		<<"3. View transactions sorted by date(newest to oldest)\n"
		<<"4. View transactions sorted by balance(fewest to greatest)\n"
		<<"5. View transactions sorted by balance(greatest to fewest)\n"
		<<"Enter your choice: ";
	cin>>choice;
	return 0;
}