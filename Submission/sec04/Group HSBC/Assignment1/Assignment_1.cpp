#include<iostream>
#include<fstream>
#include<string>
#include<cstring> 
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
		
		Account(string an ="", double b =0.0) : account_number(an), balance(b) {}
		
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

		double getBalance(){
			return balance;
		}

		string getDate(){
			return transaction_date;
		}

		string getAccNum(){
			return account_number;
		}
		
};

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

int read_data(Account acc[], const string& filename){
	
	string an, type, d, target;
	double b, amt;
	int n = 0;
	ifstream f1(filename);
	if(!f1){
		cout<<"Error opening file: "<<filename<<endl;
		exit(0);
	}
	
	while(getline(f1,acc[n].account_number,',')){
		f1>>acc[n].balance;
		f1.ignore(); //ignore the comma
		
		getline(f1,d,',');
		acc[n].setTransactionDate(d);
		
		getline(f1,type,',');
		acc[n].setTransactionType(type);
		
		if(type == "DEPOSIT" || type == "WITHDRAWAL"){
			f1>>amt;
		}
		else if(type == "TRANSFER"){
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

//for ascending order
template <typename T, bool ascending = true>
void sort(T arr[], int n){

	T temp; 

	for(int i=0; i<n-1; i++){
  		for(int j=0; j<n-i-1; j++){
    		if(ascending){
    			if(arr[j] > arr[j+1]) {
        			temp = arr[j];
        			arr[j] = arr[j+1];
        			arr[j+1] = temp;  
				}
      		}
      		else{
      			if(arr[j] < arr[j+1]) {
        			temp = arr[j];
        			arr[j] = arr[j+1];
        			arr[j+1] = temp;  
        		}
			}
    	}
	}
}

////for descending order
//template <typename T>
//void descenSort(T arr[], int n){
//
//  T temp; 
//
//  for(int i=0; i<n-1; i++){
//    for(int j=0; j<n-i-1; j++){
//      if(arr[j] < arr[j+1]) {
//        temp = arr[j];
//        arr[j] = arr[j+1];
//        arr[j+1] = temp;  
//      }
//    }
//  }
//}

int menu1(){
	int choice;
	
	cout << "Menu of Account Checking : " << endl
		 << "1. Account Searching" << endl
		 << "2. Account List" << endl
		 << "Enter your choice: ";
	cin >> choice;
	return choice;
} 

int menu2(){
	int choice;
	
	cout<<"Choose an option:\n"
		<<"1. View all the transaction without sorting\n"
		<<"2. View transactions sorted by date(oldest to newest)\n"
		<<"3. View transactions sorted by date(newest to oldest)\n"
		<<"4. View transactions sorted by balance(fewest to greatest)\n"
		<<"5. View transactions sorted by balance(greatest to fewest)\n"
		<<"Enter your choice: ";
	
	cin>>choice;
	return choice;
}

int main(){
	string filename = "inputasg1.txt";
	
	cout<<"Enter the input file name: ";
	//cin>>filename;
	Account account[99];
	int count = read_data(account, filename);
	system("cls");
	
	// cout << "Balance checking"<<endl;
	// for(int i=0;i<count;i++){
	// 	cout<<"Account Number: "<<account[i].getAccNum()<<"\t Balance: RM"<<account[i].getBalance()<<endl;
	// }

	// cout << "Date checking"<<endl;
	// for(int i=0;i<count;i++){
	// 	cout<<account[i].getDate()<<endl;
	// }
	int menu = 1;
	while(menu)
	{
		int choice1, choice2;
		do
		{
			choice1 = menu1();
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
		else if(choice1 == 2)
		{
			do
			{
				choice2 = menu2();
				system("cls");
                if(choice2 <= 0 || choice2 >= 6){
                    cout << "Please choose again the option with following number: \n";
                }

			} while (choice2 <= 0 || choice2 >= 6);
			
			cout<<"--------------------------------------------------------------------------------------------------------------\n"
			<<"| Account Number | Balance(RM) | Transaction Date | Transaction Type | Amount(RM) | Transfered Account Number |\n"
			<<"--------------------------------------------------------------------------------------------------------------\n";
			if(choice2 == 1){
				for(int i=0 ; i<count ; i++)
					account[i].printDetails();
			}
			if(choice2 == 2 || choice2 == 3){
                string sortingDate[count];

                for(int i=0 ;i<count ;i++) {
                    sortingDate[i] = account[i].getDate();
                }

                if(choice2 == 2){
                    sort<string>(sortingDate, count);
                }
                else{ //choice2 == 3
                    sort<string,false>(sortingDate, count);
                }

                for(int i=0 ; i<count ; i++){
                    for(int j=0 ; j<count ; j++){
                        if(sortingDate[i] == account[j].getDate()){
                                account[j].printDetails();
                        }
                    }
                }
            }
            
            if(choice2 == 4 || choice2 == 5){
            	double sortingBalance[count];
            	
            	for(int i=0 ;i<count ;i++) {
                    sortingBalance[i] = account[i].getBalance();
                }
                
                if(choice2 == 4){
                    sort<double>(sortingBalance, count);
                }
                else{ //choice2 == 5
                    sort<double,false>(sortingBalance, count);
                }

                for(int i=0 ; i<count ; i++){
                    for(int j=0 ; j<count ; j++){
                        if(sortingBalance[i] == account[j].getBalance()){
                                account[j].printDetails();
                        }
                    }
                }
                
			}

		}
        else
        {
            system("cls");
            continue;
        }

		cout << "\n\n\n\nBack to menu (1: yes / 0: no) : ";
		cin >> menu;
		system("cls"); 
	}
		
	system("pause");
	return 0;
}
