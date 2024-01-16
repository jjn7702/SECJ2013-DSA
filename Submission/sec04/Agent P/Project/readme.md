# Election Management System

### Table of Contents
- [Introduction](#-introduction)
- [Objectives](#-objectives)
- [Synopsis](#-synopsis)
- [Class Diagram](#-class-diagram)
- [Flowchart](#-flowchart)
- [Queue Implementation](#-queue-implementation)
- [User Guide](#-Findings)
- [Finding](#-Finding)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/project-management.png" width="3%" height="3%"> Introduction
As from the agent P group we decided to develop an Election Management System for  UTM.For this system there will three type of users , Admin , Voter and Candidate.The admin can insert the candidate into the candidate list , remove candidate and voter and also view the list of voters and candidates.As for the Voters they can cast three votes , register if they’re not in the list and view the list of candidates.Finally for the Candidates , they can view their profile , view the candidate list and also withdraw.
  
### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/bc7e2df3-d20d-457c-b9fb-e0574b6a740e" width="3%" height="3%"> Objectives:
The objective for this project is to create a fully functional  Election management system during voting day at UTM.There are 3 users in this system and each one of them has their own objectives.The 3 users are the Admin , Voters and Candidates.The Admin objective is to manage the voters and candidates.They can insert a new Candidate to the candidate list while remove a candidate or voter from their list.Admin also will view the candidate list and voters list in this system.As for the Candidate , their objective is to view their profile and also if they want to withdraw they can do it so.For the voters , their objective is to register themself if they are not in the list , cast their vote by choosing any three candidates and also view the candidate’s list.Thus,the aim of this system is to create a user-friendly interface where users can easily use and manage .


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/ac62ef65-848d-41a6-97c2-1ff40be8ecd3" width="3%" height="3%"> Synopsis
Election Management System is a system that will be used during the UTM voting days for the new council members.Admin , Candidate and Voters will be the user for this system.The admin will login and can choose to view the list of candidates or voters , remove the candidate or voters and also can insert candidate.The Admin can choose to view the list of candidates based on sorting of faculty , name , matric and vote count in ascending order.As for inserting candidate , Admin will manually insert the candidates name , faculty , age , matric number , phone number , IC , password , email.The password will be given by the admin to the candidate later for them to login in to the system.To remove candidate , admin will just look at the list and input the row number to remove the row of the candidate’s detail from the list.For candidate , they can view the list of candidates , view their own profile and choose to withdraw from the candidate list.Candidate can just simply choose to view the list of candidates and the system will pop out the list of candidates.Same goes for view profile as well.If the candidate choose to withdraw they can also simply just click to withdraw from the list.For voters , they can register in the voter’s list to be eligible to cast their vote.Voters can also choose to cast their votes for 3 candidates and they can view the list of candidates as well.



## Design 🎨


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/b7b1299f-ead1-4e66-ad2e-95b901f4f03c" width="3%" height="3%"> Class Diagram

![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/classDIAGRAM.png)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8b3596b0-7214-4cc8-b868-9ab2a0314386" width="3%" height="3%"> Flowchart

![2](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Ass1%20(1).jpg)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/fabaacbe-18c1-4f64-a3a5-e1b40e910e71" width="4%" height="4%"> Queue Implementation
##### 1. Enqueue

    
##### 2. Dequeue

##### 3. Sort

##### 4. Search

### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/project-management.png"  width="4%" height="4%"> User Guide

##### 1. Main Menu

![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20184949.png)

Users will need to choose whether to login as Admin, Voter or Candidate here by entering 1 for admin, 2 for voter and 3 for candidate.
**Users need to choose either one of the options and will be redirected till the users enter either one of the options. 

##### 2. Admin

Step 1

![2](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20185433.png)

Every admin will be asked to enter their username and password.

Step 2

![3](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20185734.png)

Admin will be redirected to their profile, here they can choose few options to do, 1 to view voter, 2 for view candidate, 3 for delete voter, 4 for delete candidate and 5 for insert candidate.

Step 3.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20190013.png)

If option 1 is selected, then the admin can choose how they want to view the voters, the list will be sorted in ascending order of the chosen attribute, 1 for name, 2 for faculty and 3 for matric.

Step 3.1.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20190730.png)

Sample output if option 3 is selected. 

The admin can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.

Step 3.2

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20190529.png)

If option 2 is selected, then the admin can choose how they want to view the candidate, the list will be sorted in ascending order of the chosen attribute, 1 for name, 2 for faculty, 3 for matric and 4 for vote count.

Step 3.2.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20190730.png)

Sample output if option 1 is selected. 

The admin can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.

Step 3.3

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20190847.png)

If option 3 is selected, the admin can delete voter(s) by specifying how many voters they want to delete. Since we have implemented a queue only voters at the front of the list will be deleted.

Step 3.3.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20191115.png)

Sample output if the number of voters to be deleted is 1.

The admin can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.

Step 3.4

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20191227.png)

If option 4 is selected, the admin can delete a candidate at specific position which starts with 1.

![4]()

Sample output if the chosen position is 1. 

The admin can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.

Step 3.5

![4])()
![4]()
If the admin chose option 5, then the admin inserts an admin by inserting all the details.
**Name, Faculty, IC, Phone number, Email, Matric Number, Password are all string while age is integer. 

The admin can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.

Step 3.6

![4][()

If the admin chose option 6, the system will end.

**Any other option that is not 1-6 will make the system exit.


##### 3. Voter

##### 4. Candidate





### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/folder.png" width="3%" height="3%"> Findings 

- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass1/Assignment1.cpp)
- [Input File](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass1/cand.csv)
- [Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass1/DSA%20Assignment%201_3.pdf)
