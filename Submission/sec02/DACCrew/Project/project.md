# Banking System - Project Report

- <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DACCrew/Project/Mini%20Project%20DACCrew.pdf" >Report Project</a>
- <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DACCrew/Project/DACCrew%20Project%20Report.pdf" >Project Turnitin Report </a>
- <a href="https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec02/DACCrew/Project/Files/source-code" >Project coding </a>
## Prepared By DACCrew
| Name         | Matric No    |
|--------------|--------------|
| Chai Yu Tong  | A22EC0145  |
| Nur Farah Adibah binti Idris     | A22EC0245 |
| Wong Qiao Ying     | A22EC0118 |

## Table of Contents
1. [Introduction](#introduction)
   - 1.1 [Objective](#11-Objective)
   - 1.2 [Synopsis](#12-Synopsis)

2. [System Design](#System-Design)
   - 2.1 [System Algorithm Design](#21-System-Algorithm-Design)
   - 2.2 [Data Structure Operation](#22-Data-Structure-Operation)
3. [User-Guide](#User-Guide)
   
## Introduction
### 1.1 Objective


### 1.2 Synopsis


## System Design
### 2.1 System Algorithm Design
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DACCrew/Images/Pseudocodeproject.png" width="450" height="700">

### 2.2 Data Structure Operation
Data Structure Operation and Implementation

Since, our project is about the banking system, we adopted the use of stack in our program as stack offers several advantages, mainly on its principle that is LIFO(Last In, First Out) principle that is suitable for the user to view the latest transaction and the balance over time as the latest transaction will be at the top of the list. We use a linked list stack as it will be more flexible in scenarios where the number of transactions is uncertain.

Stack Implementation:
nodeStack class
- represents a node in the stack, in which each node will contain information on a single transaction, including the date, amount, balance and type.
- Have getter functions that are getDate(), getBalance(), getAmount() and getType() that return the date, balance, amount and type of transaction.

Stack class
- The banking transaction will be pushed onto the stack whenever a user performs a transaction.  
- In the public:
- push(string d, string t, double a, double b): push the transaction into the stack
- searchByDate(string searchDate): search the transaction by date
- searchByType(string searchType): search the transaction by transaction type


To conclude, stacks are used in the banking system to manage and track transactions in Last In, First Out order. Stack implementation will show the order of transactions where the latest one will be at the top of the list. 


