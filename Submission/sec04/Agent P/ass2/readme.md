# Election Management System

### Table Of Contents
-[Introduction](#-introduction)
-[Objectives](#-ojectives)
-[Synopsis](#-synopsis)
-[Class Diagram](#-class-diagram)
-[Flowchart](#-flowchart)
-[Linked list](#-Linked-list)
-[Findings](#-Findings)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/bc7e2df3-d20d-457c-b9fb-e0574b6a740e" width="3%" height="3%"> Objectives:
The objective for this assignment 2 is to create a Election management system to manage the voters list.In this system we will enable users to add , delete, searching and sort the voters list based on their preferences.For adding a voter,user can add voters in this list and choose where to place the voter’s details in the voter’s list.User can choose three places to place the voter’s details,which are at the front , at the back and at a place that user desire.For deleting a voter,user can delete voter in the list and choose which one to delete.User can choose to delta the first person in the list or the last person in the list or the person at any position in the list.For searching,user can simply choose any of the 6 key which are voter’s name, faculty, age, email, ic, matric and enter the key’s value they want to search.If the key’s values matches any voter’s key in the list , it will display the voter’s detail to the user , if not it will display “Data was not found. Try again later !”.For sorting,user can simply choose any of the 6 key and choose to view the list in ascending or descending order accordingly to their chosen key.Thus,the aim of this system is to create a user friendly interface where user can easily manage the voter’s management system. 

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/fabaacbe-18c1-4f64-a3a5-e1b40e910e71" width="4%" height="4%"> Linked List
##### 1. Insert

1.3 Inserting at Node

For inserting at a node,user will enter how many voter’s details they want to enter first and then a new set of voter’s details which are the voter’s name,faculty,age,email,ic,matric and  the placement number they want the details to be placed on the list.Then the voter’s details will be automatically set at the place that user wanted in the list.Meanwhile if the voter’s details already exist in the list , the system will show “Voter already exist!“.

##### 2. Delete

2.3 Deleting at Node

For delete at the node,user will be asked to enter an index which is the placement of a voter’s detail in the list.Then the voter’s detail at the place chosen by the user will be automatically deleted in the list.After that the system will show the new updated list to the user.

##### 3. Searching

3.5 Search for Matric Num

For searching by matric number, we have implemented sequential search to get the details of the voters based on the matric number entered by the user. We have implemented the sequential in this searching function because it can be used in both sorted and unsorted lists. If the entered key was successfully found in the list it will display the details which have the voter’s name,faculty,age,ic,email and their matric num to the corresponding name. If the data is not found in the list it will display the message “Data was not found. Try again later !”

3.6 Search for email








