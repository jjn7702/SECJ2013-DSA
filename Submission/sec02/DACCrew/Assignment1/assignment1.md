# Banking System
## Prepared By
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
The existing class and its attributes:
Bank
AccName
the name of the account holder <string>
AccNum
the account number <string>
IC
the identity card number of the account holder <string>
AccBalance
the quantity of the amount of money in the account <double>


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
Explain the sorting process in your system.

#### 2.3.2 Searching Process
Describe the searching process in your system.

