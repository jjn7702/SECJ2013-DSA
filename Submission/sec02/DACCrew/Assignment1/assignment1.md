# Assignment 1
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

partitionName
partitions the array based on the name attributes during sorting
sortByName
sorts the array ‘Bank’ objects based on the account name
partitionIC
partitions the array based on the IC attributes during sorting
sortByIC
sorts the array ‘Bank’ objects based on the IC
partitionAccNum
partitions the array based on the account number attributes during sorting
sortByAccNum
sorts the array ‘Bank’ objects based on the account number
partitionBal
partitions the array based on the balance attributes during sorting
sortByBal
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

### 2.3 Data Structure Operation
Discuss how data structures are used in your project.

#### 2.3.1 Sorting Process
As for the sorting process, we will use a quicksort method in the banking system. Quicksort is a divide-and-conquer algorithm that involves choosing a pivot and then partitioning the array around the pivot. Quicksort involves moving elements less than the pivot value on the left, while items bigger than the pivot will be on the right. Thus, the pivot is now in the correctly sorted position. 

Below is the description of the key components of each sorting function and how they contribute to organizing the data.
##### 1. Sorting by Name (sortByName()):
- Algorithm: Quicksort
- Description: This function implements the quicksort algorithm to sort an array of Bank objects based on the accName attribute.
- Parameters: bl(The array of Bank objects.), first(The starting index of the subarray to be sorted), and last (The ending index of the subarray to be sorted)
- Recursive Approach: The function recursively divides the array into subarrays and sorts them based on the names of the account holders.

##### 2. Sorting by Account Number (sortByAccNum()):
- Algorithm: Quicksort
- Description: Like sortByName, this function sorts the array based on the accNum attribute using the quicksort algorithm.
- Sorting by Account Number (sortByAccNum()):
- Algorithm: Quicksort
- Description: Like sortByName, this function sorts the array based on the  ic attribute using the quicksort algorithm.

##### 3. Sorting by Balance (sortByBal()):
- Algorithm: Quicksort
- Description: This function uses a modified quicksort algorithm to sort the array based on the accBalance attribute.
Handling Equal Balances: It considers cases where balances are equal by comparing the account names to maintain stability in sorting.

##### 4. Partitioning Functions (partitionName(), partitionIc(), partitionAccNum(), partitionBal()):
- Description: These functions are integral to the quicksort algorithm. They determine a pivot element. In this case, the first element became the pivot. The elements in the Bank array that are less than the pivot are moved to be before the pivot, and elements bigger than the pivot value move to be after the pivot.


#### 2.3.2 Searching Process
Describe the searching process in your system.

