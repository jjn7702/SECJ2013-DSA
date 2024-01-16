# Election Management System

### Table of Contents
- [Introduction](#-introduction)
- [Objectives](#-objectives)
- [Synopsis](#-synopsis)
- [Class Diagram](#-class-diagram)
- [Flowchart](#-flowchart)
- [Queue Implementation](#-queue-implementation)
- [User Guide](#-Findings)

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
##### 1. Sorting

1.1.1 Sorting by Name

For sorting by name, we have implemented the selection sorting algorithm. There are two functions for sorting by name which are sorting in ascending order and descending order. The selection sorting function accepts two parameters which are object array of candidate class and size of the array. In ascending order the names are sorted from A-Z while in descending order the names are sorted from Z-A. 

1.1.2 Sorting by Faculty

For sorting by faculty, we have implemented the improved bubble sorting algorithm. There are two functions for sorting by faculty which are sorting in ascending order and descending order. The improved bubble sorting function accepts two parameters which are object array of candidate class and size of the array. In ascending order the faculties are sorted from A-Z while in descending order the faculties are sorted from Z-A.

1.1.3 Sorting by IC

Sorting by IC is implemented using selection sorting algorithm.There are two functions for this sorting by IC , which are in ascending order and descending order.Both function has two parameters which are the object array of candidate class and size of the array.In ascending order the candidates are arranged according to their IC values where they are sorted from the smallest IC value to the largest IC value.The descending is the opposite of the ascending order where the candidate will be sorted from largest IC value to the biggest IC value.


1.1.4 Sorting by Age

For sorting by Age, we implemented insertion sorting. There are two functions for this sort, one for ascending order and another one for descending order. The algorithm will compare the candidates age (int) and arrange it following the ascending or descending order.

1.1.5 Sorting  by Matric Number

For sorting by 	Matric Number, we implemented selection sorting. There are two functions for this sort, one for ascending order and another one for descending order. The algorithm will compare the candidate’s Matric number (string) and arrange it following the ascending or descending order.

1.1.6 Sorting by Vote Count

Sorting by vote count is implemented using insertion sorting algorithm.There are two functions for this sorting by vote count , which are in ascending order and descending order.Both function has two parameters which  are the object array of candidate class and size of the array.In ascending order the candidates are arranged according to their vote counts where they are sorted from the smallest vote counts to the largest vote count.The descending is the opposite of the ascending order where the candidate will be sorted from largest vote counts to the biggest IC value.

    
##### 2. Searching

2.1.1 Search for name

For searching by name, we have implemented sequential search to get the details of the candidate based on the name entered by the user. We have implemented the sequential in this searching function because it can be used in both sorted and unsorted lists. If the entered key was successfully found in the list it will display the details to the corresponding name. If the data not found in the array it will display the message “Data not found”.

2.1.2 Search for faculty

For searching by name, we have implemented sequential search to get the details of the candidate based on the name entered by the user. We have implemented the sequential in this searching function because it can be used in both sorted and unsorted lists. If the entered key was successfully found in the list it will display the details to the corresponding name. If the data not found in the array it will display the message “Data not found”.

2.2.3 Search for IC

We have implemented sequential search for searching by IC to get the candidate’s detail based on the IC entered by the user.User will be asked to enter the IC of the candidate they want to search for and if the function found a match,it will display the candidate’s information,but if the IC does not match with any of the candidate’s IC,it will display “Data entered not found!”.

2.1.4 Search for Age

Students will be asked to enter the Age they want to search for and the function will display the candidate(s) and if the age they searched for was not found, a message will be displayed. 

2.1.5 Search for Matric Num

Students will be asked to enter the Matric number they want to search for and the function will display the candidate and if the Matric number they searched for was not found, a message will be displayed. 

2.2.6 Search for Vote Count

We have implemented sequential search for searching by vote count to get the candidate’s detail based on the IC entered by the user.User will be asked to enter the vote count of the candidate they want to search for and if the function found a match,it will display the candidate’s information,but if the vote count does not match with any of the candidate’s IC,it will display “Data entered not found!”.



### <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/images/folder.png" width="3%" height="3%"> Findings 

- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass1/Assignment1.cpp)
- [Input File](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass1/cand.csv)
- [Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/ass1/DSA%20Assignment%201_3.pdf)
