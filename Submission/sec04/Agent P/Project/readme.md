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

![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Class_Project.png)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8b3596b0-7214-4cc8-b868-9ab2a0314386" width="3%" height="3%"> Flowchart

![2](https://drive.google.com/file/d/1fHlM7QDAATt5hLikZZU-9dLlpINaUTWa/view?usp=sharing)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/fabaacbe-18c1-4f64-a3a5-e1b40e910e71" width="4%" height="4%"> Queue Implementation
##### 1. Enqueue

For enqueue, since the queue is First in, First out, a new item can only be inserted at the back. 
Since the voter class used a queue, whenever a new voter registered himself, they would be at the back of the list. This is done because the voters at the back will be new users while the one at the front are the old students. 

    
##### 2. Dequeue

For dequeue, this can only be done by the admin. This is because, in the queue the deleted item will be the first item in the queue. So voters can’t delete themselves from the queue. The admin can also specify how many voters to delete at the same time since all the old voters can be deleted at the same time.

##### 3. Sort

For the voter and candidate classes, the sorting was done in ascending order and used the improved bubble sort. For voter class, name, faculty, and matric number attributes are used in sorting. For candidate class, name, faculty, matric number, vote count are used as sorting attributes. 

##### 4. Search

Search is implemented using sequential search in the candidate class. This is done to help the voters to identify the candidates they might know. The attributes used for searching is name, faculty, email, age, ic and matric number.With this the voters can search for the candidate they know. 

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

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20191347.png)

Sample output if the chosen position is 1. 

The admin can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.

Step 3.5

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20191705.png)

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20191755.png)
If the admin chose option 5, then the admin inserts an admin by inserting all the details.
**Name, Faculty, IC, Phone number, Email, Matric Number, Password are all string while age is integer. 

The admin can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.

Step 3.6

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20192503.png)

If the admin chose option 6, the system will end.

**Any other option that is not 1-6 will make the system exit.

##### 3. Voter

Step 1.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20194916.png)

*Users who have registered before
Users will be needed to enter their ID(matric number) and password is something that is decided by the user.

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20195215.png)

Users will have the options if they want to try again to enter the id and password.

Step 1.2

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20195215.png)

*Users who have not have registered before
Users can register as a new Voter by entering option 2.

Step 1.2.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20200049.png)

Users will need to fill in all this information.
**Name, Faculty, IC, Email, Matric Number are all strings while age is integer. 
**If the matric number is the same then, the system will display a message and exit the system. 

Step 1.2.2

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20200249.png)

Users will need to enter a password for authentication purpose. 

Step 1.2.3.

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20200515.png)

Users will be asked to enter their newly registered id and password.

**Users who have registered before cannot register as a voter again. 

Step 2

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20200737.png)

Voters have the option to vote(1), view profile(2), Search for candidate(3), and exit(4). 
**Any option other than 0-4 will make the system end.

Step 3.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20201841.png)

If the voter chose option 1, then the list of candidates will be displayed and the voter will need to choose 3 candidates. 
**A candidate can only be chosen once.


Step 3.1.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20202014.png)

The system will then display the information of the chosen candidate. 

The voter can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.


Step 3.2

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20202404.png)

If option 2 is selected, the voter can see their information and they can change it if they enter ‘y’ and not edit it if ‘n’ is entered. 

Step 3.2.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20202520.png)

*If the voter want to change their profile
The voter can now choose which attribute they want to change
1 for name, 2 for faculty, 3 for age, 4 for IC, 5 for Email, 6 for matric number.


Step 3.2.2

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20202848.png)

The voter can choose the attribute they want to change and enter the new information. 

The voter can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.

Step 3.2.3

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20202930.png)

If the voter chose option 3, then they can search for candidates by using the above attributes. 

Step 3.3.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20203047.png)

The voter can choose the attribute and enter the information, in this sample, the name was used. If the information is the same as the one in the candidate list then the information about the candidate will be displayed.

Step 3.3.2

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20203308.png)

If the information is not found, an error message will appear. 

The voter can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.

Step 3.4

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20203552.png)

If the voter chose option 4, the system will end.

##### 4. Candidate

Step 1.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20204325.png)

Candidates will need to enter their ID(Matric Number) and password.

Step 1.2

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20204437.png)

If the candidate entered the wrong id or password, then they will need to enter it back till they get it right. 

Step 2

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20205234.png)

The candidate will be redirected to the page where they can view profile(1), view all candidates(2), withdraw from election(3) and exit(4).

Step 3.1

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20205501.png)

If the candidate chose option 1, they can view their information like name, faculty, age, IC, Email, matric number, phone number, vote count. 

The voter can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.

Step 3.2

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20205727.png)

If the candidate chose option 2, they can view all candidates information like name, faculty, IC,age, matric number, email and vote count.

The voter can choose to continue or end the process here by entering ‘y’ to continue and ‘n’ for ending the process.

Step 3.3

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/WhatsApp%20Image%202024-01-16%20at%209.02.35%20PM.jpeg)

If the candidate chose option 3, then they will withdraw from the election process and their name will be removed from the candidate list and the system will end.

Step 3.4

![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/Screenshot%202024-01-16%20210430.png)

If the candidate chose option 4, then they will exit the system. 
**If the candidate enters any option other than 1-4, the system will end.













### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/folder.png" width="3%" height="3%"> Findings 

- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass1/Assignment1.cpp)
- [Input File](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass1/cand.csv)
- [Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass1/DSA%20Assignment%201_3.pdf)
