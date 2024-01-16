#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//printTitle() - WS

//class UserAcc - WS

//class Transaction - Hayden

//ALL
class BinaryTree(){ 

};

//read_data() - QY

//read_Userdata() - CS

//menuUser() - WS

//menuStaff() - Hayden

//calculate_add - WS

//calculate_del - Hayden

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