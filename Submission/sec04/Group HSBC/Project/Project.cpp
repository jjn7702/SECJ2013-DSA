#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//printTitle() - WS
void printTitle(){
    cout<<"----------------------------------------------------------------------------------------------------------------\n"
        <<"| Refer Number | Account Number | Transaction Date | Transaction Type | Amount(RM) | Transfered Account Number |\n"
        <<"----------------------------------------------------------------------------------------------------------------\n";
}

//class UserAcc - WS
class UserAcc
{
    private :
        string accNum;
        float balance;
        int pin;
        string password;

    public :
        void set_accNum(string acc)
        {
            accNum = acc;
        }

        void set_balance(float b)
        {
            balance = b;
        }

        void set_pin(int p)
        {
            pin = p;
        }

        void set_password(string pw)
        {
            password = pw;
        }

        float get_balance()
        {
            return balance;
        }

        string get_accNum()
        {
            return accNum;
        }

        string get_password()
        {
            return password;
        }

        int get_pin()
        {
            return pin;
        }


};

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
        void searchNode(Transaction* node, string& accNum, vector<Transaction*>& result){
            if(node == NULL){
                return;
            }
            
            if(node->account_number == accNum){
                result.push_back(node);
            }

            searchNode(node->left, accNum, result);
            searchNode(node->right, accNum, result);
        }
        

        //displayInOrder() - WS
        void displayInOrder(Transaction* node){
            if(node != NULL) {
                displayInOrder(node->left);
                node->printDetails();
                displayInOrder(node->right);
            }
        }
        

        //update() - CS
        void Update(Transaction* node, vector<string>& transaction)
        {
            if(node != NULL)
            {
                string detail = to_string(node->referenceNumber) + "," + node->account_number + "," + node->transaction_date + "," + node->transaction_type + "," + to_string(node->transaction_amount);
                if(node->transaction_type == "TRANSFER")
                {
                    detail = detail + "," + node->target_account;
                }

                transaction.push_back(detail);

                Update(node->left, transaction);
                Update(node->right, transaction);
            }
            else
            {
                return;
            }
        }
        

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
        void searchAccount(string accNum){
            vector<Transaction*> result;
            searchNode(root, accNum, result);
            printTitle();

            if(!result.empty())
            {
                cout << "Found Account with number " << accNum << ":\n";

                for(const auto& node : result){
                    node->printDetails();
                }
            }
            else{
                cout << "No Account found with number " << accNum << "\n";
            }
        }
        

        //displayAccount() - WS
        void displayAccount(){
            printTitle();
            displayInOrder(root);
        }
        

        //transactionFile_update() - CS
        void transactionFile_update(){

            ofstream op("inputProject.txt");
            vector<string> transaction;
            Update(root, transaction);

            for(int i = 0; i < transaction.size(); i++)
            {
                op << transaction[i] << endl;
            }
        }
        

        //findMax_Red() - CS
        int findMax_Ref() {

            Transaction* node = root;
            while(node->right != NULL)
            {
                node = node->right;
            }

            return node->referenceNumber;
        }

};

//read_data() - QY

//read_Userdata() - CS
int read_Userdata(UserAcc acc[], string filename)
{
    ifstream inp(filename);

    if(!inp){
		cout<<"Error opening file: "<<filename<<endl;
		exit(0);
	}

    int i = 0;
    while(!inp.eof())
    {
        string accnum, pw;
        float balance;
        int pin;

        getline(inp, accnum, ',');
        acc[i].set_accNum(accnum);

        inp >> balance;
        inp.ignore();
        acc[i].set_balance(balance);

        inp >> pin;
        inp.ignore();
        acc[i].set_pin(pin);

        getline(inp, pw, '\n');
        acc[i].set_password(pw);

        i++;
    }

    inp.close();
    return i;
}

//menuUser() - WS
int menuUser(){
    int choice = -1;

    do{
        cout << "Menu:\n1. Make a new transaction."
             << "\n2. View Current Balance"
             << "\n3. Display Transaction History."
             << "\n4. Exit the program."
             << "\nEnter your choice: ";
        cin >> choice;
        system("cls");

        if(choice<1 || choice>5)
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";

    }while(choice<1 || choice>5);

    return choice;
}

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
void calculate_add(int type, UserAcc account[], double amt, string targetAcc, int mainAcc, int arraySize)
{
    if(type == 1)
    {
        account[mainAcc].set_balance(account[mainAcc].get_balance() + amt);
    }
    else if(type == 2)
    {
        double total = account[mainAcc].get_balance() - amt;

        if(total >= 0)
        {
            account[mainAcc].set_balance(total);
        }
        else
        {
            cout << "No enough balance" << endl;
            return;
        }
    }
    else
    {
        double total = account[mainAcc].get_balance() - amt;

        if(total >= 0)
        {
            int i = 0;
            bool find = 0;
            for(i = 0; i < arraySize; i++)
            {
                if(account[i].get_accNum() == targetAcc)
                {
                    find = 1;
                    break;
                }
            }

            if(find == 0)
            {
                cout << "Invalid Account to Transfer" << endl;
                return;
            }
            else
            {
                account[mainAcc].set_balance(total);
                account[i].set_balance(account[i].get_balance() + amt);
            }
        }
        else
        {
            cout << "No enough balance" << endl;
            return;
        }
    }
}

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
void userFile_update(UserAcc acc[], int n)
{
    ofstream op("userAcc.txt");

    for(int i = 0; i < n-1; i++)
    {
        op  << acc[i].get_accNum() << ","
            << acc[i].get_balance() << ","
            << acc[i].get_pin() << ","
            << acc[i].get_password() << endl;
    }

    op.close();
}

//menuFirstPage() - qy

//role1() - CS
void role1(UserAcc userInfo[], int& n, BinaryTree& tree, Transaction account[], int& count, int& choice, bool& conti){

    int userLogin, pin;
    int targetAcc;
    bool login = 0;
    string acc, pw;

    do{
        do{
            cout << "Login Menu :\n"
                 << "1. Login\n"
                 << "2. Create Account\n"
                 <<"Enter Your Choice : ";
             cin >> userLogin;
            system("cls");

            if(userLogin <= 0 || userLogin >= 3)
            {
                cout << "Something went wrong... please try again" << endl;
                system("pause");
                system("cls");
            }

        }while(userLogin <= 0 || userLogin >= 3);
                    
        if(userLogin == 1)
        {
            cout << "Please enter account number : ";
            cin >> acc;

            cout << "Please enter password : ";
            cin >> pw;

            system("cls");

            for(int i = 0; i < n; i++)
            {
                if(userInfo[i].get_accNum() == acc)
                {
                    if(userInfo[i].get_password() == pw)
                    {
                        cout << "Login Successful" << endl;
                        targetAcc = i;
                        login = 1;
                        break;
                    }
                    else
                    {
                        cout << "Wrong password" << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                }
                else if(i == n-1)
                {
                    cout << "invalid account number" << endl;
                    system("pause");
                    system("cls");
                }
            }
        }
        else
        {
            bool sameAcc;
            do{
                sameAcc = 0;
                cout << "Please enter account number : ";
                cin >> acc;

                for(int i = 0; i < n; i++)
                {
                    if(acc == userInfo[i].get_accNum())
                    {
                        sameAcc = 1;
                        cout << "existed account number ! please try again\n";
                    }
                }

            }while(sameAcc);

            cout << "Please enter securety pin (4 digit) : ";
            cin >> pin;

            cout << "Please enter password : ";
            cin >> pw;

            userInfo[n].set_accNum(acc);
            userInfo[n].set_pin(pin);
            userInfo[n].set_password(pw);
            userInfo[n++].set_balance(50.00);

            ofstream op("userAcc.txt", ios::app);
            op  << acc << ","
                << 50.00 << ","
                << pin << ","
                << pw << endl;
            
            op.close();

            cout << "Successfully register !\n";
            system("pause");
            system("cls");
        }

        if(login == true)
        {
            do{
                choice = menuUser();

                switch(choice){
                    case 1 :{
                                string acc_num, type, date, target;
                                double balance, amt;
                                int typeNum;

                                acc_num = userInfo[targetAcc].get_accNum();

                                cout << "Transaction date(YYYY-MM-DD): ";
                                cin >> date;

                                do{
                                    cout << "Transaction type(1.DEPOSIT/2.WITHDRAWAL/3.TRANSFER): ";
                                    cin >> typeNum;

                                    switch(typeNum)
                                    {
                                        case 1 :
                                            type = "DEPOSIT";
                                            break;

                                        case 2 :
                                            type = "WITHDRAWAL";
                                            break;

                                        case 3 :
                                            type = "TRANSFER";
                                            break;

                                        default :
                                            cout << "Something went wrong... Please try again" << endl;
                                            break;
                                    }

                                }while(typeNum <= 0 || typeNum >= 4);

                                if (type == "TRANSFER") {
                                    cout << "Target Account: ";
                                    cin >> target;
                                }
                                cout << "Amount: ";
                                cin >> amt;
                                
                                if(typeNum == 2 || typeNum == 3)
                                {
                                    int pin;
                                    cout << "Please enter pin (4 digit) :";
                                    cin >> pin;

                                    if(pin != userInfo[targetAcc].get_pin())
                                    {
                                        cout << "Wrong pin number" << endl;
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                }

                                calculate_add(typeNum, userInfo, amt, target, targetAcc, n);
                                userFile_update(userInfo, n);

                                Transaction newAcc(acc_num);
                                newAcc.setTransactionDate(date);
                                newAcc.setTransactionType(type);
                                newAcc.setTargetAccount(target);
                                newAcc.setTransactionAmount(amt);
                                newAcc.setReferNum(tree.findMax_Ref() + 1);
                                count++;

                                tree.insertAccount(newAcc);
                                tree.transactionFile_update();
                                cout << "\nInserting the new transaction successfully.\n";
                                cout << "\n\n\n\nBack to menu (1: yes / 0: no) : ";
                                cin >> conti;
                                break;
                            }
                    case 2 :{
                                cout << "Your Current Balance : RM " << userInfo[targetAcc].get_balance();
                                cout << "\n\n\n\nBack to menu (1: yes / 0: no) : ";
                                cin >> conti;
                                break;
                            }
                    case 3 :{
                                tree.searchAccount(userInfo[targetAcc].get_accNum());
                                cout << "\n\n\n\nBack to menu (1: yes / 0: no) : ";
                                cin >> conti;
                                break;
                            }
                    case 4 :{
                                conti = false;
                                break;
                            }
                            
                }
                system("cls");
                            
            }while(conti == true);
        }


    } while(userLogin <= 0 || userLogin >= 3);
}

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