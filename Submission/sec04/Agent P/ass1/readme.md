# Election Management System - Assignment 1

### Table of Contents
- [Objectives](#-objectives)
- [Synopsis](#-synopsis)
- [Class Diagram](#-class-diagram)
- [Flowchart](#-flowchart)
- [Description of how to implement data structure operations: Sorting and Searching](#-description-of-how-to-implement-data-structure-operations-sorting-and-searching)

  
### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/bc7e2df3-d20d-457c-b9fb-e0574b6a740e" width="3%" height="3%"> Objectives:
The objective for this assignment 1 is to create an Election management system for UTM which will enable users to get a sorted version of the Election candidate list by attributes like name,faculty,age,vote count ,IC and matric num.The system will also enable users to do searching on the stated attributes.Thus, the aim of this system is to create a user friendly interface where user can easily use the election management system.


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/ac62ef65-848d-41a6-97c2-1ff40be8ecd3" width="3%" height="3%"> Synopsis

Election Management System is a system that can help students in UTM to view the candidates information like name, faculty, age, matric number, phone number and vote count. There is also a sorting and searching algorithm implemented in the system so that students have an easier time looking for the candidates. For example, students can search for the candidates from their faculty so that they can support the candidate from their faculty. There is also sorting that will arrange the candidates in ascending or descending order depending on the information they want to sort. For example, students can see the candidates from oldest to youngest or vice versa. This system will ease students in their search for candidates as all candidates are registered in the system. 


## Design 🎨


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/b7b1299f-ead1-4e66-ad2e-95b901f4f03c" width="3%" height="3%"> Class Diagram

![1]()

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8b3596b0-7214-4cc8-b868-9ab2a0314386" width="3%" height="3%"> Flowchart

![2](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Agent%20P/images/photo_6057581772625000910_y.jpg)

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/fabaacbe-18c1-4f64-a3a5-e1b40e910e71" width="4%" height="4%"> Description of how to implement data structure operations: Sorting and Searching
##### 1. Sorting
1.1.4 Sorting by Age

For sorting by Age, we implemented insertion sorting. There are two functions for this sort, one for ascending order and another one for descending order. The algorithm will compare the candidates age (int) and arrange it following the ascending or descending order.

1.1.5 Sorting  by Matric Number

For sorting by 	Matric Number, we implemented selection sorting. There are two functions for this sort, one for ascending order and another one for descending order. The algorithm will compare the candidate’s Matric number (string) and arrange it following the ascending or descending order.
    
##### 2. Searching

2.2.4 Search for Age
Students will be asked to enter the Age they want to search for and the function will display the candidate(s) and if the age they searched for was not found, a message will be displayed. 

2.2.5 Search for Matric Num
Students will be asked to enter the Matric number they want to search for and the function will display the candidate and if the Matric number they searched for was not found, a message will be displayed. 



## Findings 📊

- [Source Code](/ass1/Assignment1.cpp)
- [Input File](/ass1/cand.csv)
- [Report]()







