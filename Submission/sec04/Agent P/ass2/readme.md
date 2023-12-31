# Election Management System

### Table Of Contents
- [Introduction](#-introduction)
- [Objectives](#-objectives)
- [Synopsis](#-synopsis)
- [Class Diagram](#-class-diagram)
- [Flowchart](#-flowchart)
- [Linked list](#-Linked-list)
- [Sorting and Searching](#-sorting-and-searching)
- [Findings](#-Findings)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/project-management.png" width="3%" height="3%"> Introduction
As from the agent P group we decided to develop an election management system for  UTM.For this system UTM can manage the voters list easily and efficiently. For assignment 2,we had developed 2 classes. One is voter class which contains 6 attributes(name,faculty,email,ic,matric and age) which define a voter and class list which has the methods to manage the list of voters.


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/bc7e2df3-d20d-457c-b9fb-e0574b6a740e" width="3%" height="3%"> Objectives
The objective for this assignment 2 is to create a Election management system to manage the voters list.In this system we will enable users to add , delete, searching and sort the voters list based on their preferences.For adding a voter,user can add voters in this list and choose where to place the voter’s details in the voter’s list.User can choose three places to place the voter’s details,which are at the front , at the back and at a place that user desire.For deleting a voter,user can delete voter in the list and choose which one to delete.User can choose to delta the first person in the list or the last person in the list or the person at any position in the list.For searching,user can simply choose any of the 6 key which are voter’s name, faculty, age, email, ic, matric and enter the key’s value they want to search.If the key’s values matches any voter’s key in the list , it will display the voter’s detail to the user , if not it will display “Data was not found. Try again later !”.For sorting,user can simply choose any of the 6 key and choose to view the list in ascending or descending order accordingly to their chosen key.Thus,the aim of this system is to create a user friendly interface where user can easily manage the voter’s management system. 

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/ac62ef65-848d-41a6-97c2-1ff40be8ecd3" width="3%" height="3%"> Synopsis

## Design 🎨

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/b7b1299f-ead1-4e66-ad2e-95b901f4f03c" width="3%" height="3%"> Class Diagram

![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/class%20diagram%20ass2.jpg)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8b3596b0-7214-4cc8-b868-9ab2a0314386" width="3%" height="3%"> Flowchart

![2](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Ass1-Page-2.drawio%20(2).png)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/fabaacbe-18c1-4f64-a3a5-e1b40e910e71" width="4%" height="4%"> Linked List
##### 1. Insert

1.1 Insert At Front

For inserting at the front,users will enter how many voter’s details they want to enter first and then  a new set of voter’s details  which are the voter’s name, faculty, age, email, ic, matric. Then the voter’s details will be automatically set at the front of the list.Meanwhile if the voter’s details already exist in the list , the system will show “Voter already exists!“.

1.2 Insert at End

For inserting at the end,user will enter how many voter’s details they want to enter first and then a new set of voter’s details which are the voter’s name, faculty, age, email, ic, matrix.Then the voter’s details will be automatically set at the end of the list.Meanwhile if the voter’s details already exist in the list , the system will show “Voter already exist!“.

1.3 Inserting at Node

For inserting at a node,user will enter how many voter’s details they want to enter first and then a new set of voter’s details which are the voter’s name,faculty,age,email,ic,matric and  the placement number they want the details to be placed on the list.Then the voter’s details will be automatically set at the place that user wanted in the list.Meanwhile if the voter’s details already exist in the list , the system will show “Voter already exist!“.

##### 2. Delete

2.1 Delete at Front

For delete at the front,users can simply choose the option to delete at the front of the file.Then the voter’s detail at the front of the list will be automatically deleted.After that, the system will show the new updated list to the user.

2.2 Delete at End

For delete at the end,the user can simply choose the option to delete at the end of the file.Then the voter’s detail at the end of the list will be automatically deleted.After that, the system will show the new updated list to the user.

2.3 Deleting at Node

For delete at the node,user will be asked to enter an index which is the placement of a voter’s detail in the list.Then the voter’s detail at the place chosen by the user will be automatically deleted in the list.After that the system will show the new updated list to the user.

##### 3. Searching

3.5 Search for Matric Num

For searching by matric number, we have implemented sequential search to get the details of the voters based on the matric number entered by the user. We have implemented the sequential in this searching function because it can be used in both sorted and unsorted lists. If the entered key was successfully found in the list it will display the details which have the voter’s name,faculty,age,ic,email and their matric num to the corresponding name. If the data is not found in the list it will display the message “Data was not found. Try again later !”

3.6 Search for email

For searching by email, we have implemented sequential search to get the details of the voters based on the email entered by the user. We have implemented the sequential in this searching function because it can be used in both sorted and unsorted lists. If the entered key was successfully found in the list it will display the details which have the voter’s name,faculty,age,ic,email and their matric num to the corresponding name. If the data is not found in the list it will display the message “Data was not found. Try again later !”

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/fabaacbe-18c1-4f64-a3a5-e1b40e910e71" width="4%" height="4%"> Sorting and Searching
##### 1. Sorting
In this system,we have added sorting in ascending and descending order.User will choose a key,from any of the 6 attributes.

1.1 Ascending order

The ascending order for each attributes was done by an improved bubble sorting algorithm.In this algorithm,it will check the node adjacent to it and check whether the value in the node is higher, if it is higher, the values will be swapped, if not the pointer will traverse the linked list till it finds it.Hence,the list will be sorted in ascending order  accordingly to the chosen key entered by the user.

1.2 Descending order

As for the descending order,it was done by using a selection sorting algorithm.In this algorithm , it will search for the node with lowest value, and swap the values with node at the end of it. This will be done until the linked list is sorted.Which means the list of voters will be arranged in descending order according to the chosen key entered by the user.

##### 2. Searching

2.1 Search for name

For searching by name, we have implemented sequential search to get the details of the voter based on the name entered by the user. We have implemented the sequential in this searching function because it can be used in both sorted and unsorted lists. If the entered key was successfully found in the list it will display the details which have the voter’s name,faculty,age,ic,email and their matric num to the corresponding name. If the data is not found in the list it will display the message “Data was not found. Try again later !”.

2.2 Search for faculty

For searching by faculty, we have implemented sequential search to get the details of the voters based on the faculty entered by the user. We have implemented the sequential in this searching function because it can be used in both sorted and unsorted lists. If the entered key was successfully found in the list it will display the details which have the voter’s name,faculty,age,ic,email and their matric num to the corresponding name. If the data is not found in the list it will display the message “Data was not found. Try again later !”.

### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/folder.png" width="3%" height="3%"> Findings 

- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass2/Assignment_2.cpp)
- [Input File / Output File ](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass2/voter.csv)
- [Output File 2](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass2/voter2.txt)
- [Report]()
