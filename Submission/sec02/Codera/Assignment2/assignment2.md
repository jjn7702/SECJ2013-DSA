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

- Develop a hospital management system to manage the patient record.
- Implement linked list data structure and algorithm to build this hospital mangament system.
- Allow healthcare workers to add or delete patients, search or sort patient record, and view patient medical history.

## Synopsis
The hospital management system has been developed to manage the patient records in a hospital effectively. This system will act as a tool to help the healthcare professionals to monitor patient information, contacts, and medical history in a better way. 

This system will allow those healthcare workers to add, delete, search, sort , and display all the patient records. Linked list data structure is used with some operations to perform the functions of this proposed system because linked list is better than array in the modification without moving larger amount of data. The patient record will include with patient name, identity card number, age, contact number, diagnosed disease, and diagnosed date. 

Firstly, add a new patient function will provide options to insert the data at the beginning, at any position of the middle, or at the end of the patient record. Next, delete a patient function will provide options to delete the first data, any data in the middle, or the last data of patient record. Moreover, search patient function will allow the healthcare staff to search patient medical record based on name, identity card number, or age. Furthermore, sort patient function will allow the healthcare staff to sort the patient list in assending order based on name, age, or diagnosed date. Lastly, the complete patient medical record can be displayed to the healthcare workers. 

The system uses merge sort algorithm with linked list structure in assending order because it has stable and predictable performance. This is because merge sort has an O(n log n) time complexity, where "n" is the number of elements to be sorted. 

In a nutshell, the Hospital Management System helps minimize the workload for healthcare workers in replacing manage patient records manually. The system contributes to efficient  and accurate healthcare services. 

## Class Diagram
### The relationships are:
- Patient and Node: Composition, as each Node contains an instance of Patient.
- List and Node: Composition, as List contains a collection of Node instances to construct the linked list.
- List and Patient: Association, as List uses instances of Patient through Node to manage patient information in the linked list.
  
<br><img src = https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Codera/Assignment2/Images/class-diagram.png><br>

## Pseudocode


## Description on Linked List Operation
Adding a Patient: The insert, insertEnd, and insertMiddle functions are used to add a new patient to the list. They all perform same functions which is add new patient records at different position. The insert function will add the node at the beginning of the list. The next pointer of the new node is set to the current head of the list, then the head is updated to the new node. For the insertEnd function, the node is added at the end of the list. This is done by travelling to the last node and next pointer is set to the new node. The insertMiddle function can help to add the node at a middle position. The function move to the desired location and update next pointers of the adjacent nodes to insert the new node. 

Deleting a Patient: The removeFront, removeEnd, and removeMiddle functions are used to remove a patient from the list. The removeFront function deletes the first patient info in the list.  The head is the second node and therefore the system deletes the first node. The head is set to the set The removeEnd function will help to delete the last node in the list. The last second node is set to NULL, then the last node is deleted. The removeMiddle function deletes a node at a position. The node before the node want to be deleted position will be updated for its upgoing pointer, in order to delete that node. 

Searching for a Patient: The findNodeName, findNodeIC, and findNodeAge functions are used to find a patient in the list. Each function will go through the list based on the input. If input match the list, then the system returns that patient info. If no patient found, the system returns NULL. 

Sorting Patients: The MergeSort, MergeSortDate, and MergeSortAge functions are used to sort the list of patients. Merge Sort is a Divide and Conquer algorithm that divides the input array into two parts, sorts the two halves independently, and then merges them. The MergeSort function is a recursive function that continuously divides an array until it reaches the individual elements (base case: if first < last). Once the elements are created individually, they are recombined in the sorted order using the merge function. The sorting is done based on three types sorting, name, date and age of the patient. 

Displaying the Patient List: The dispList function is used to display the current list of patients.  

## Findings 📊
- [Report](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec02/Codera/Assignment2/Report)
- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec02/Codera/Assignment2/source-code)

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)
