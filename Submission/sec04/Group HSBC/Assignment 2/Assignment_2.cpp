


int main(){
	
	string filename = "inputasg1.txt";
	
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