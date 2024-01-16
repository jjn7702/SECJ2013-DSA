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
class BinaryTree {
    private:
        Transaction* root;

        //insertNode - Hayden
    

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