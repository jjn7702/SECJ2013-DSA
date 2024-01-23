[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Hospital Management System

## Description 📝

In order to effectively manage and monitor patients' records in hospitals, a hospital management system has been developed. This system is intended to help healthcare professionals simplify patient information, contacts and medical history with tools that will allow for quick and accurate monitoring of patients' records.

## Prepared by 🧑‍💻

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
| Neo Zheng Weng   | A22EC0093        | <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Codera/Images/neozhengweng_pic.jpg" width=80px, height=80px>     |
| Joseph Lau Yeo Kai       | A22EC0055        | <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Codera/Images/joseph_pic.jpeg" width=80px, height=80px>         |
| Lee Yik Hong       | A21BE0376       | <img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Codera/Images/Assignment%20photo.jpg" width=80px, height=80px>         |

## Objectives
### User Interface and User Experience:
- Problem: The current system maybe be too complicated to control and manage data. 
- Solution: Design an user friendly interface, which enables the user to manage patient 
easily and efficiently. 

### Data Backup Concerns:
- Problem: The current may not update the data input or may have no data back up, which 
causes data loss sometimes. 
- Solution: There is data backup file which will be updated every time the user log out of 
the system

## Objective
•	Build a system for hospitals to handle patient records.
•	Use linked lists and queue data structures to organize data effectively.
•	This system helps workers to add and remove patient info, searching sorting and edit patient medical history.


## Synopsis
The hospital management system wants to manage patient medical records efficiently. The system uses queue and linked lists to perform those basic tasks. 

Patient record will have the info such as name, diagnosed date, disease, IC and other important information. The system can add and remove patient info, searching, sorting and edit patient medical history.

Furthermore, the system use sorting function to arrange patient lists by name, age, or date of diagnosis. The recently added edit function provides the ability to make modifications to patient records as needed. The system employs the merge sort method for consistent and reliable performance, utilizing a linked list structure in ascending order.

Notably, the system utilizes a Queue data structure method selected from stack, queue, and tree. The choice of the Queue data structure is particularly suitable for our system due to its First-In-First-Out (FIFO) nature. In a hospital setting, patient records often require processing in the order they are received or entered, making the queue an efficient choice. The inherent ability of a queue to manage and process tasks sequentially aligns well with the dynamic nature of patient data in a healthcare environment.

In a nutshell, by replacing manual patient record management, the Hospital Management System reduces the amount of labour that healthcare professionals must perform. The system helps to provide accurate and effective healthcare services.




## Class Diagram
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Codera/Project/DSA-project_classdiagram.jpg" alt="Class Diagram">

### The relationships are:
Relationship between the Patient and Queue classes involves aggregation and association.


## Pseudocode
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Codera/Project/pseudocode/Picture1.png" alt="pseudocode">
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Codera/Project/pseudocode/Picture2.png" alt="pseudocode">
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Codera/Project/pseudocode/Picture3.png" alt="pseudocode">
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Codera/Project/pseudocode/Picture4.png" alt="pseudocode">
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Codera/Project/pseudocode/Picture5.png" alt="pseudocode">

## Description on Linked List Operation
Queue data structure concept is following the FIFO principle, which is first In first out. The first input will be the first one to be deleted in this concept. 

In the Hospital Management System, this concept is used to manage the patients details and information. The system will be having two pointers which is front and back(for the application of the queue concept). 

The first concept inside the queue data structure is enqueue, we use enQueue function to add new patient to the system. If the system patient info is empty, then the front and back will be same on the newly added patient. If there are other patients info in the system, then the back will be updated to the new added patient, and the pointer of the original last patient will point to the new patient. 

The another concept is Dequeue. The dequeue function will remove the patient from the system which is at the back of the system based on the concept. However, it can also delete the patient based on its position in the system, which it travel from front to back until the corresponded patient is found based on the name. If it is found, then the pointers of the patient before and after it will then be updated. If the patient deleted is the last element, then front and back of the system will be updated to null. 

By using isEmpty function, the system can checked if the patient info txt is empty or with patient info, by checking the front and back is null or not. 

We are also using linked list to perform the queue data structure. The front of the queue being set as the head, and the back of the queue is set as the tail. The next pointer of each patient info is pointing to the next patient info. When patient is removed, next pointer of each patient info is updated. 

This queue data structure will make the system to be able to do searching, deleting, adding, sorting, and also editing functions. 

     
## Findings 📊
- [Report](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec02/Codera/Project/Report)
- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec02/Codera/Project/source-code)

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)
