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

- Develop a hospital management system.
- Uses the sorting and searching data structure and algorithm in this hospital management system for management.
- Allow healthcare workers to get patient’s information, contact information, and their medical history.
## Synopsis
This hospital management system has been developed to manage patients' records. The system is designed to get patient information, contacts, and medical history. Healthcare workers can get and manage patients' records in a better way.

Healthcare workers choose to sort or search for this system. Besides, the system uses the Merge sort sorting method in ascending order followed by the attributes as it has a stable and predictable performance. This is because Merge sort has an O(n log n) time complexity, where "n" is the number of elements to be sorted. Attributes examples are name, IC, age, gender, contact number, disease, and diagnosis date. Moreover, this system uses Binary search algorithms as it gives a quick and more accurate search performance for the healthcare workers to search specific patient records or data they want.

In a nutshell, the Hospital Management System helps minimize the workload for healthcare workers in replacing finding patient records manually. The system contributes to efficient healthcare services.

## Class Diagram
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Codera/Images/DSA.jpg"><br>

## Pseudocode
<img src=><be>
## Description of How to Implement Data Structure Operations
The system allows the healthcare professionals to manage patient records by providing the option to sort based on different attributes such as name, IC, age, gender, contact number, disease, and diagnosed date. Our team has decided to use the Merge Sort algorithm due to its small complexity time and faster sorting process. However, we only apply ascending order sorting in our system.

### Sorting:<br>
Divide and Conquer algorithm(Merge Sort) is used to divide the input array into two parts, sort the two halves independently, and finally merge them together. Next, the MergeSort function is a recursive function that continuously divides an array until it reaches the individual elements (base case: if first < last). Once all the elements are created successfully into their own, they are recombined into a sorted order using the Merge function.

For example, mergeSortByName() is used to sort the patient record by name in ascending order. Three parameters will be accepted in the program: the patient array, and the first and last indices of the section of the list to be generated. The middle index will be calculated, then the program sorts the two halves of the array iteratively, and finally is merged into two ordered halves. A similar concept is used in the other Merge Sort functions in the system to sort the patient list in ascending order based on the attributes.

### Searching:<br>
In addition to sorting, the function of searching for patients by name, IC, or disease is offered. It is performed by using a binary search. For example, if the user wants to search by name, the binarySearchByName function is called. Then perform a binary search on the list of Patient objects based on the name attribute. If the user wants to search by IC, the binarySearchByIC function is used. To search for disease, the system uses the binarySearchByDisease function to find all patients of the specified disease.

Binary search is done by dividing the list of objects by two times what the object must do. For example, in binarySearchByName, a list of patients is searched by a name. The program accepts four parameters: the patient name array, the lowest and highest indices of the part of the array being searched, the name to search for. The program calculates the middle index, then compares the names in the middle index with names. If the names match, it returns an index. If the target name is less than the name in the middle list, the left side of the array is searched. If there is more than one target name, the right side is searched. This process is repeated until the target name is found or no target name is found in the whole list. However, in binarySearchByDisease, the vector concept is used to store elements with the same data types and to get the range of data. It is to search for all patients with the same disease.

## Findings 📊
- [Report]()
- [Source Code]()
- [Input File]()

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)



