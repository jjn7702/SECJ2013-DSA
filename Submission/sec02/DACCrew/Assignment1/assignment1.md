# Assignment 1
- <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DACCrew/Assignment1/files/DACCrew%20Assignment%201.pdf" >Report Assignment 1 
## Prepared By DACCrew
| Name         | Matric No    |
|--------------|--------------|
| Chai Yu Tong  | A22EC0145  |
| Nur Farah Adibah binti Idris     | A22EC0245 |
|      |  |

## Table of Contents
1. [Introduction](#Introduction)
   - 1.1[ Objective of Project](#11-Objective-of-Project)

   - 1.2[ Synopsis of Project](#12-Synopsis-of-Project)

2. [System Design](#system-design)
   - 2.1[ System Class Design](#21-System-Class-Design)
   - 2.2 [System Algorithm Design](#22-System-Algorithm-Design)
   - 2.3[ Data Structure Operation](#23-Data-Structure-Operation)
       - 2.3.1[ Sorting Process](#231-Sorting-Process)
       - 2.3.2[ Searching Process](#232-Searching-Process)

## Introduction
### 1.1 Objective of Project
   - To simulate the CIMB Banking Transaction System
   - To apply the data structure concept in the system
   - To gain hands-on experience in applying the data structure concept

### 1.2 Synopsis of Project
   We will develop a Banking transaction system focusing on sorting and searching operations using fundamental data structure concepts. This system is designed to perform basic transaction operations, including depositing money into user accounts, enabling withdrawal, and facilitating money transfers between accounts. The sorting operations encompass arranging data by name, Identification Card number, account number and balance in ascending order. Additionally, this system supports searching operations based on account holder's names and account numbers, allowing users to locate their accounts using unique identifiers.
###The existing class and its attributes:
Bank 
AccName : the name of the account holder <string>
AccNum : the account number <string>
IC : the identity card number of the account holder <string>
AccBalance : the quantity of the amount of money in the account <double>


The existing data structure:
Array
The array, in this case, stores a list of Accounts with their holder’s name, account number, IC number, and Balance. The searching operations iterate through this array to find specific records based on criteria such as name, account number, and IC number.
Bank[100]
stores a list of user name, account number, IC and balance


Sorting
The sorting function is defined to sort an array of ‘Bank’ objects on different criteria. These functions use various partitioning techniques, such as quickSort.

'partitionName'
partitions the array based on the name attributes during sorting
'sortByName'
sorts the array ‘Bank’ objects based on the account name
'partitionIC'
partitions the array based on the IC attributes during sorting
'sortByIC'
sorts the array ‘Bank’ objects based on the IC
'partitionAccNum'
partitions the array based on the account number attributes during sorting
'sortByAccNum'
sorts the array ‘Bank’ objects based on the account number
'partitionBal'
partitions the array based on the balance attributes during sorting
'sortByBal'
sorts the array ‘Bank’ objects based on the account balance


Searching:
The searching functions are defined to search for records in the array based on name, account number and IC. These functions will iterate through the array and display matching records if found.

searchByName
searches for records in the array based on the account name
searchByAccNum
searches for records in the array based on the account number
searchByIC
searches for records in the array based on the IC



## System Design
### 2.1 System Class Design
Describe the design of the system classes, if applicable.

### 2.2 System Algorithm Design
Explain the high-level design of algorithms used in your system.

1. Start. 
2. Display menu.
3. User input choice
4. If choice == 1
   4.1 Display Sort by name<br>
       4.1.1 Else if choice == 2 <br>
             4.1.1.1 Display Sort by Account Number
       4.1.2 Else if choice == 3
             4.1.2.1 Display Sort by IC Number
       4.1.3 Else if choice == 4
             4.1.3.1 Display Sort by Account Balance
       4.1.4 Else if choice == 5
             4.1.4.1 Display Search by Name
       4.1.5 Else if choice == 6
             4.1.5.1 Display Search by Account Number
       4.1.6 Else if choice == 7
             4.1.6.1 Display Search by IC Number
       4.1.7 Else 
             4.1.7.1 Exit
5. End


### 2.3 Data Structure Operation
Discuss how data structures are used in your project.

#### 2.3.1 Sorting Process
As for the sorting process, we will use a quicksort method in the banking system. Quicksort is a divide-and-conquer algorithm that involves choosing a pivot and then partitioning the array around the pivot. Quicksort involves moving elements less than the pivot value on the left, while items bigger than the pivot will be on the right. Thus, the pivot is now in the correctly sorted position. 

As for the sorting process, we use a quicksort method in the banking system. Quicksort is a divide-and-conquer algorithm that involves choosing a pivot and then partitioning the array around the pivot. Quicksort involves moving elements less than the pivot value on the left, while the elements bigger than the pivot will be on the right. Thus, the pivot is now in the correctly sorted position. 
The sortByName() function sorts the array of Bank objects according to the accName attribute using the quicksort algorithm in ascending order by partitioning the arrays using the partitionName()function. Meanwhile, the sortByNum()  function sorts the array of elements according to the accNum attribute using the quicksort algorithm in ascending order by partitioning the collection of arrays using the partitionaccNum() function. Moreover, sortByIc() function sorts the arrays according to the ic attribute using the quicksort algorithm in ascending order by partitioning the collection of bank arrays using the partitionIc() function. The sortByBal()  function sorts the array of elements according to the accBalance attribute using the quicksort algorithm in ascending order by partitioning the collection of arrays using the partitionBal() function. All the sort function recursively call itself until all elements is sorted.


#### 2.3.2 Searching Process
Describe the searching process in your system.

