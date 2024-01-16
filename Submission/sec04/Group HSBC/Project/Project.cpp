#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//printTitle() - WS

//class UserAcc - WS

//class Transaction - Hayden
class Transaction{
	
	public:
        int referenceNumber;
		string account_number;
		string transaction_date;
		string transaction_type;
		double transaction_amount;
		string target_account; //for transfer
        Transaction* left;
        Transaction* right;
		
		Transaction(string an =""){
            account_number = an;
            left = NULL;
            right = NULL;
        }
		
        void setReferNum(int referNum) {referenceNumber = referNum; }

		void setAccountNumber(string acc_num){account_number = acc_num; }
		
		void setTransactionDate(string d){ transaction_date = d; }
		
		void setTransactionType(string t){ transaction_type = t; }
		
		void setTransactionAmount(double amt){ transaction_amount = amt; }
		
		void setTargetAccount(string num = "-"){ target_account = num; }
		
		void printDetails(){
            cout << setw(7) << referenceNumber;
			cout<<"             ";        
			cout<<account_number<<"  " 
				<<setw(19)<<transaction_date << "        "
				<<transaction_type;
			
			if(transaction_type == "DEPOSIT")
				cout << "   ";
			else if(transaction_type == "TRANSFER")
				cout << "  ";
				
			cout<<setw(13)<<transaction_amount
				<<"                 "<<target_account<<endl;

            
		}

		string getDate(){
			return transaction_date;
		}

		string getAccNum(){
			return account_number;
		}
		
};

//ALL
class BinaryTree {
    private:
        Transaction* root;

        //insertNode - Hayden
        Transaction* insertNode(Transaction* node, Transaction& acc) {
            if (node == NULL) {
                return new Transaction(acc); 
            }
            if(acc.referenceNumber < node->referenceNumber){
                node->left = insertNode(node->left, acc);
            }
            else if(acc.referenceNumber > node->referenceNumber){
                node->right = insertNode(node->right, acc);
            }

            return node; // Return the updated root of the current subtree
        }
    

        //QY
        Transaction* findMinValueNode(Transaction* node){
            Transaction* current = node;

            while(current->left != NULL){
                current = current->left;
            }

            return current;
        }

        //QY
        Transaction* deleteNode(Transaction* node, int& refer){
            //case 1: if the node is null
            if (node == NULL)   
                return node;
            
            //case 2: small the go left subtree
            if(refer < node->referenceNumber){
                node->left = deleteNode(node->left, refer);
            }
            //case 3: larger then go right subtree
            else if(refer > node->referenceNumber){
                node->right = deleteNode(node->right, refer);
            }
            //case 4: current node == acc that want to be deleted
            else{
                //case 4.1: if the node has one child or no child
                if(node->left == NULL){
                    Transaction* temp = node->right;
                    delete node;
                    return temp;
                }
                else if(node->right == NULL){
                    Transaction* temp = node->left;
                    delete node;
                    return temp;
                }

                //case 4.2: if the node has two child
                Transaction* temp = findMinValueNode(node->right);
                node->referenceNumber = temp->referenceNumber;
                node->right = deleteNode(node->right, temp->referenceNumber);
            }

            return node;
        }

        //searchNode() - WS
        

        //displayInOrder() - WS
        

        //update() - CS
        

    public:
        BinaryTree() : root(NULL) {}

        //insertAccount() - Hayden
        void insertAccount(Transaction& acc){
            root = insertNode(root, acc);
        }    

        //QY
        void deleteAccount(int& refer){
            root = deleteNode(root, refer);
        }

        //searchAccount() - WS
        

        //displayAccount() - WS
        

        //transactionFile_update() - CS
        

        //findMax_Red() - CS
        

};

//read_data() - QY

//read_Userdata() - CS

//menuUser() - WS

//menuStaff() - Hayden
int menuStaff()
{
    int choice = -1;

    do{
        cout << "Menu:"
             << "\n1. Search a transaction by account number."
             << "\n2. Display all transaction."
             << "\n3. Delete a transaction"
             << "\n4. Exit the program."
             << "\nEnter your choice: ";
        cin >> choice;
        system("cls");

        if(choice<1 || choice>5)
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";

    }while(choice<1 || choice>5);

    return choice;
}

//calculate_add - WS

//calculate_del - Hayden
void calculate_del(Transaction trans[], UserAcc account[], int ref, int count, int n)
{
    for(int i =0; i < count; i++)
    {
        if(trans[i].referenceNumber == ref)
        {
            for(int j = 0; j < n; j++)
            {
                if(trans[i].account_number == account[j].get_accNum())
                {
                    if(trans[i].transaction_type == "DEPOSIT")
                    {
                        account[j].set_balance(account[j].get_balance() - trans[i].transaction_amount);
                        return;
                    }
                    else if(trans[i].transaction_type == "WITHDRAWAL")
                    {
                        account[j].set_balance(account[j].get_balance() + trans[i].transaction_amount);
                        return;
                    }
                    else
                    {   
                        int k;
                        for(k = 0; k < n; k++)
                        {
                            if(trans[i].target_account == account[k].get_accNum())
                            {
                                break;
                            }
                        }

                        account[k].set_balance(account[k].get_balance() - trans[i].transaction_amount);
                        account[j].set_balance(account[j].get_balance() + trans[i].transaction_amount);
                        return;
                    }
                }
            }
        }
    }

    cout << "Invalid reference number" << endl;
    system("pause");
    return;
}

//userFile_update() - CS

//menuFirstPage() - qy

//role1() - CS

//role2() - QY


int main()
{
    string filename1 = "inputProject.txt";
    string filename2 = "userAcc.txt";

    BinaryTree tree;
    Transaction* account = new Transaction[99];
	int count = read_data(account, filename1);
	
	for(int i=0 ; i < count ; i++){
		tree.insertAccount(account[i]);
	}

    UserAcc userInfo[99];
    int n = read_Userdata(userInfo, filename2);

    int choice, role;
    bool conti = true, repeat = true;

    do{
        role = menuFirstPage();

        if(role == 1)
            role1(userInfo, n, tree, account, count, choice, conti);
        else if (role == 2)
        	role2(userInfo, n, tree, account, count, choice, conti); 
        else
        	repeat = false;

    }while(repeat == true);

    system("pause");
    return 0;
}