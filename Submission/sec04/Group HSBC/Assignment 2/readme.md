[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Banking System

### Table Of Contents
- [Description](#-Description)
- [Objective](#-Objective)
- [Synopsis](#-synopsis)
- [Class Diagram](#-class-diagram)
- [Pseudocode](#-pseudocode)
- [Design Description](#-design-description)
- [Findings](#-Findings)



### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/project-management.png" width="3%" height="3%"> Description
The main goal of HSBC's Banking System is to enhance the user experience and smoothen the flow of control of the system. In assignment 2, we implement the linked list which use pointer concept to replace the array to enhance our system's performance and the storage is unlimited.

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/bc7e2df3-d20d-457c-b9fb-e0574b6a740e" width="3%" height="3%"> Objective
The objectives of creating this banking system:
1) To manage the banking transaction
2) To implement banking system using linked list
3) Display all the banking transaction history that has been made by the user

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/ac62ef65-848d-41a6-97c2-1ff40be8ecd3" width="3%" height="3%"> Synopsis
In this assignment, we choose the topic Banking System as our group assignment. The purpose of this coding is to create a simple banking system that is able to manage the banking transaction by implementing the concept of linked list. There are some functions of linked lists which are adding a new node, deleting a node, finding a node and also displaying all of the nodes in the list. For adding a new node, the user is able to insert the details of the banking transaction based on their preference. For deleting a node, the user is able to remove the first, last or specific account number of a banking transaction. For finding a node, the user is able to find the transaction history of a specific account number. Finally for the displaying all the nodes in the list, this allow the user to have a look on all the banking transaction history.

## Design 🎨

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/b7b1299f-ead1-4e66-ad2e-95b901f4f03c" width="3%" height="3%"> Class Diagram

![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Image/DSA%20Assignment%202%20Class%20Diagram.PNG)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8b3596b0-7214-4cc8-b868-9ab2a0314386" width="3%" height="3%"> Pseudocode

![2](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Image/DSA%20Assignment%202%20Report%20-%20Google%20Docs_page-0001.jpg)

![3](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Image/DSA%20Assignment%202%20Report%20-%20Google%20Docs_page-0002.jpg)

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Image/DSA%20Assignment%202%20Report%20-%20Google%20Docs_page-0003.jpg)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/clipboard.png" width="4%" height="4%"> Design Description
##### 1. Adding a new node
For adding a new node, we create 3 member functions inside the class which are  insertBeginning function, insertEnd function and insertMiddle function. The insertBeginning function assigns a node pointer named ‘newNode’ which is assigned as the new node which is input by the user and checks whether the list is empty or not. If it is empty, it will set the head to the ‘newNode’. If it is not empty, it will set the next of the ‘newNode’ to head and the head will be set to the ‘newNode’. 

The insertEnd function assigns a node pointer named ‘newNode’ which is assigned as the new node which is input by the user and checks whether the list is empty or not. If it is empty, it will set the head to the ‘newNode’. If it is not empty, we assign a new node pointer which is named ‘current’ and it is set to the head. While loop is executed with condition the next of the ‘current’ is not null. It will set the ‘current’ to the next of the ‘current’. After the loop ends, the next of the ‘current’ is set to newNode. 

The insertMiddle function assigns a node pointer named ‘newNode’ which is assigned as the new node which is input by the user and checks whether the list is empty or not. If it is empty, it will set the head to the ‘newNode’ and end the function. If it is not empty, we assign two node pointers which are ‘slow’ and it is set to the head and for the ‘fast’ pointer, it will be set to the next of the head. While function is executed with condition ‘fast’ is not null and the next of the ‘fast’ is not null. Inside the loop, the node pointer ‘slow’ will be set to the next of the node pointer ‘slow’ and node pointer ‘fast’ will be set to the next of the next node pointer ‘fast’. After the loop ends, the next node pointer ‘newNode’ will be set to the next of node pointer ‘slow’ and the next of the node pointer ‘slow’ is set to newNode.

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

##### 2. Finding node
For the finding node function, we create a member function called findNode with return type void which accepts account number, ‘num’ as a parameter and also as a search key. In this function, we assign a node pointer named ‘current’ which is assigned as head and set boolean variable, found to false. We use a while loop with a condition, current not equal to NULL, to compare the account number in every node with the parameter ‘num’ until the end of the node. Once the account number is matched to the ‘num’, it will call the function in class Account which are printTitle and printDetails for the specific account number and set the ‘found’ to true and use break to stop the loop. On the other hand, if the parameter passed cannot match the information in every node, it will show “Node not found with Account Number” along with the ‘num’ passed.

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


##### 3. Display the node
For displaying the node, we create a member function, void displayNode() in class List. In this function, we also create a node pointer named ‘current’ and point it to the head node. Then, we will call the function , printTitle() in class Account to print out the title. Next, we create a while loop with condition, current not equal to NULL to print the account details in every node. We also update the current node to the next node by the code ‘ current = current->next’ to ensure the while loop can loop until the end of the node.

        void displayNode(){
            Node* current = head;
            current->account.printTitle();
            while (current != NULL) {
                current->account.printDetails();
                current = current->next;
            }
        }










### Prepared by 🧑‍💻

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
|  Hayden Huan Kee Jiun |    A22EC0166     | <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Assignment%202/Picture/photo_2023-12-11_08-21-15%20(1).jpg" title="Icon by Trazobanana"><img src="Picture/photo_2023-12-11_08-21-15%20(1).jpg" width=80px, height=80px>     |
|   Liow Chee Suan   |   A22EC0072      | <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Assignment%202/Picture/IMG_20231102_111152.jpg" title="Icon by Trazobanana"><img src="Picture/IMG_20231102_111152.jpg" width=80px, height=80px>         |
|  Chan Qing Yee     |   A22EC0040      | <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Assignment%202/Picture/profilepic900kb.jpg" title="Icon by Trazobanana"><img src="Picture/profilepic900kb.jpg" width=80px, height=80px>         |
|  Ooi Wei Sian     |   A22EC0102      | <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Group%20HSBC/Assignment%202/Picture/weisian.jpg" title="Icon by Trazobanana"><img src="Picture/weisian.jpg" width=80px, height=80px>         |

### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/folder.png" width="3%" height="3%"> Findings 


- [Assignment 1](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec04/Group%20HSBC/Assignment1)
- [Assignment 2](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec04/Group%20HSBC/Assignment%202)
- Project

### Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)
