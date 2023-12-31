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
		
		void setAccountNumber(string acc_num){account_number = acc_num; }
		
		void setBalance(double b){balance = b; }
		
		void setTransactionDate(string d){ transaction_date = d; }
		
		void setTransactionType(string t){ transaction_type = t; }
		
		void setTransactionAmount(double amt){ transaction_amount = amt; }
		
		void setTargetAccount(string num = nullptr){ target_account = num; }
		
		void printTitle(){
			cout<<"--------------------------------------------------------------------------------------------------------------\n"
				<<"| Account Number | Balance(RM) | Transaction Date | Transaction Type | Amount(RM) | Transfered Account Number |\n"
				<<"--------------------------------------------------------------------------------------------------------------\n";
		}
		
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

// Node class
class Node {
    	
	public:
		Account account;
		Node* next;
		
    	Node(Account acc) {
      		account = acc;
      		next = NULL; 
    	}
};

class List{
	private:
		Node* head;
	
	public:
		List(){head = NULL;}
		
		bool isEmpty(){
			return (head == NULL);
		}
		
		//add node at beginning
		void insertBeginning(Account a){
			Node* newNode = new Node(a);
			
			if(isEmpty()){
				head = newNode;
			}
			else{
				newNode->next = head;
				head = newNode;
			}
		}
		
		//add node at end
		void insertEnd(Account a){
			Node* newNode = new Node(a);
			
			if (isEmpty()) {
        		head = newNode;
    		} 
			else {
        		Node* current = head;
        		while (current->next != NULL) {
            		current = current->next;
        		}
        		current->next = newNode;
    		}
		}
		
		//add node at middle
		void insertMiddle(Account a){
			Node* newNode = new Node(a);
			
			if(isEmpty()){
				head = newNode;
				return;
			}
			
			Node* slow = head;
			Node* fast = head->next;
			
			//move fast by 2 steps and slow by 1 step
			//when fast reach end, the slow will move to middle
			while( fast != NULL && fast->next != NULL){
				slow = slow->next;
				fast = fast->next->next;
			}
			
			//insert the new node after the middle node(after slow)
			newNode->next = slow->next;
			slow->next = newNode;
		}

		//delete first node
		void deleteFirst(){
			if (!isEmpty()) {
        		Node* temp = head;
        		head = head->next;
        		delete temp;
        	}
        	else{
        		cout<< "The list is empty.\n";
			}
		}
		
		//delete last node
		void deleteLast(){
			if (!isEmpty()) {
        		if (head->next == NULL) {
            		delete head;
            		head = NULL;
        		} 
				else {
            		Node* current = head;
            		Node* previous = NULL;
            		while (current->next != NULL) {
                		previous = current;
                		current = current->next;
            		}
            		delete current;
            		previous->next = NULL;
        		}
    		}
    		else{
    			cout << "The list is empty.\n";
			}
    	
		}
		
		//delete middle node(delete using account number)
		bool deleteMiddle(string accNum){
			Node* current;
			Node* previous;
			if (!isEmpty()) {
        		current = head;
        		previous = NULL;
        	}

        	// Check if the first node is the one to be deleted
        	if (current->account.getAccNum() == accNum) {
            	head = head->next;
            	delete current;
            	return true;
        	}

        	while (current != NULL && current->account.getAccNum() != accNum) {
            	previous = current;
            	current = current->next;
        	}

        	if (current == NULL) {
            	cout << "Account not found in the list." << endl;
            	return false;
        	}

        	previous->next = current->next;
        	delete current;
        	return true;
		}
		
		void findNode(string num){
			Node* current = head;
    		bool found = false;

    		while (current != NULL) {
        		if (current->account.getAccNum() == num) {
            	cout << "Node found with Account Number " << num << ":\n";
            	current->account.printTitle();
            	current->account.printDetails();
            	found = true;
            	break;
        	}
        		current = current->next;
    		}

 	   		if (!found) {
        		cout << "Node not found with Account Number " << num << ".\n";
    		}
		}

		int getSize(){
			Node* temp = head;
			int count = 1;

			while(temp)
			{
				count++;
				temp = temp->next;
			}

			return count;
		}
		
		//display all the node in the list
		void displayNode(){
			Node* current = head;
			current->account.printTitle();
    		while (current != NULL) {
        		current->account.printDetails();
        		current = current->next;
    		}
		}
		
		
};

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

int menu1(){
	int choice;
	
	cout << "1. Adding a new node\n"
		 << "2. Deleting a node\n"
		 << "3. Finding a node\n"
		 << "4. Displaying all of the nodes in the list\n"
		 << "Enter your choice: ";
	cin >> choice;
	
	return choice;
}

int menuAdd(){
	int choice;
	
	cout << "1. Inserting the new node at the beginning\n"
		 << "2. Inserting the new node at the end\n"
		 << "3. Inserting the new node at the middle\n"
		 << "Enter your choice: ";
	cin >> choice;
	return choice;
}

int menuDelete(){
	int choice;
	
	cout << "1. Deleting the node at the beginning\n"
		 << "2. Deleting the node at the end\n"
		 << "3. Deleting the node with specific account number\n"
		 << "Enter your choice: ";
	cin >> choice;
	return choice;
}


int main(){
	
	string filename = "inputasg2.txt";
	
	cout<<"Enter the input file name: ";
	//cin>>filename;
	cout<<endl;
	Account* account = new Account[99];
	int count = read_data(account, filename);
	
	List acc;
	
	//link all the node together by add the node at the end
	for(int i=0 ; i<count ; i++){
		acc.insertEnd(account[i]);
	}
	
	
	int choice1, choiceAdd, choiceDel;
	bool menu = true;
	do{
		do{
			choice1 = menu1();
			system("cls");
			
		}while(choice1 < 1 || choice1 > 4);
		
		if(choice1 == 1){ //add item
			string acc_num, trans_date, trans_type, target_acc;
			double balance, trans_amt;
			Account a;
			do{
				choiceAdd = menuAdd();
				system("cls");
				if(choiceAdd<1 || choiceAdd>3)
					continue;
				
				//get info from user
				cout << "Account Number: ";
				cin >> acc_num;
				cout << "Balance: ";
				cin >> balance;
				cout << "Transaction date(DD-MM-YYYY): ";
				cin >> trans_date;
				cout << "transaction type(DEPOSIT/WITHDRAWAL/TRANSFER): ";
				cin >> trans_type;
				if(trans_type == "TRANSFER"){
					cout << "Target Account: ";
					cin >> target_acc;
				}
				cout << "Amount: ";
				cin >> trans_amt;
				
				//add info into a obj
				a.setAccountNumber(acc_num);
					a.setBalance(balance);
					a.setTransactionDate(trans_date);
					a.setTransactionType(trans_type);
					a.setTransactionAmount(trans_amt);
					if(trans_type == "TRANSFER"){
						a.setTargetAccount(target_acc);
					}
					
				if(choiceAdd == 1){ //insert new node in front	
					acc.insertBeginning(a);
					cout << "\nInsert at the front successfully.\n";
					system("pause");
					system("cls");
				}
				else if(choiceAdd == 2){
					acc.insertEnd(a);
					cout << "\nInsert at the end successfully.\n";
					system("pause");
					system("cls");
				}
				else{
					acc.insertMiddle(a);
					cout << "\nInsert at the middle successfully.\n";
					system("pause");
					system("cls");
				}
					
			}while(choiceAdd<1 || choiceAdd>3);
		}
		else if(choice1 == 2){
			string delAcc;
			do{
				choiceDel = menuDelete();
				system("cls");
				if(choiceDel<1 || choiceDel>3)
					continue;
				
				if(choiceDel == 1){
					acc.deleteFirst();
					cout << "\nDelete the first node successfully.\n";
					system("pause");
					system("cls");
				}
				else if(choiceDel == 2){
					acc.deleteLast();
					cout << "\nDelete the last node successfully.\n";
					system("pause");
					system("cls");
					
				}
				else{
					cout << "Enter the Account Number: ";
					cin >> delAcc;
					bool status = acc.deleteMiddle(delAcc);
					if(status)
						cout << "\nDelete the specific account number successfully.\n";
					system("pause");
					system("cls");
				}
			}while(choiceDel<1 || choiceDel>3);
		}
		else if(choice1 == 3){ //find a node
			string findAcc;
			cout << "Enter the Account Number: ";
			cin >> findAcc;
			acc.findNode(findAcc);
		}
		else{
			//display all the node
			acc.displayNode();
		}
		
		cout << "\n\n\n\nBack to menu (1: yes / 0: no) : ";
		cin >> menu;
		system("cls"); 
		
	}while(menu);
	
	
	delete[] account;
	system("pause");
	return 0;
}