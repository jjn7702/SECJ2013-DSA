[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

# Courier Management System - Assignment 2

## Appendix :red_circle:

- [Objectives](#Objectives)
- [Synopsis](#synopsis)
- [Design](#design)
- [Design Description](#designdescription)
- [Similarity report](#report)
- [Findings](#findings)

## Objectives <a name="objectives"></a> :heavy_check_mark:

The aim is to apply a courier management system based on linked lists. The program will read courier data from aTEST.txt file, and builds a linked list of courier objects, provides a menu- driven interface for performing some operations similar as adding a new courier node to the list, deleting a node from the list, searching for a courier node based on provided options, sorting the list based on provided options, and displaying the updated list. In this coding we use sorted- linked list class and node class to ease the courier management system on adding new nodes, deleting, sorting and searching systems. The system also has a user-friendly interface with a menu- driven system that determines users through the whole process until they choose to exit the system.
The following are the code's vital features and aims

Courier Service

A courier is by attributes such as name, parcel type, source, destination, status, and tracking number. There are approaches for setting and retrieving and also a display method for printing the courier details.

Node Class

A node in a linked list, each of which contains a Courier object and a pointer to the succeeding node.

LinkedList Class

Managed a linked list of Courier nodes. Ask and allow the user to insert a new node at the beginning, middle, or end of the list. Have operations for deleting a node from the list's beginning, middle, or end. This class also provides a method for locating a node using defined features. This function implements a sorting algorithm. Implements a sorting algorithm to sort the list based on varied criteria( similar as name, parcel type, and tracking number).

Main Purpose

The linked list is populated by reading courier information from a file(TEST.txt). Implements a menu- driven interface for interacting with the courier list. Have varied options which are adding, deleting, searching, sorting, and displaying courier nodes. The program will continue to run until the user chooses to exit. 

Input from a File
The program reads courier information from a file(TEST.txt) and uses it to add the data of the linked list.

Menu- Based User Interface

The program provides a user-friendly menu to perform varied operations on the courier list. 
Checking for valid menu options and handling invalid input while searching are included in validation of DataBasic input confirmation . The aim is to produce an adjustable and reciprocal courier operation system based on linked lists which allows the users to make the courier data is easily managed.



## Synopsis <a name="synopsis"></a> 📝

The Courier Management System allows workers to store data about parcels in a more organized way. For instance, we can update new data when we receive a parcel order by the customer and delete it a few days after the parcel has been delivered. We also can search the data based on the specified criteria of the parcel. Moreover, this system also can sort the data of parcels in ascending orders (name,parcel type,tracking number) .

## Design <a name="design"></a> 🎨
![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/images/dsa.jpg)

## Design Description <a name="designdescription"></a> 💹

#### LINKED LIST FUNCTION

#### ADDING A NEW NODE

1. Get the option from the main function.
   
2. From the option, the data will be added by corresponding function either insert at the front, middle or end.

   2.1 The insertion function in the Courier Management System allows users to add new couriers to the system.

         2.1.1 Option 1: insertFront() function: insert details for the new courier (name, parcel type, source, destination, status, and tracking number) at the front of the linked list.

         2.1.2 Option 2: insertMiddle() function: insert details for the new courier (name, parcel type, source, destination, status, and tracking number) at specified location (using position) of the linked list.

         2.1.3 Option 3: insertBack() function: insert details for the new courier (name, parcel type, source, destination, status, and tracking number) at the back of the linked list.

         2.1.4 Option 0: return back to the main menu.



#### DELETING A NODE

1. Get the option from the main function.

2. From the option, the data will be deleted by corresponding function either delete at the front, middle or end.

   2.1 The deletion function in the Courier Management System allows users to remove couriers from the system

         2.1.1 Option 1: deleteFront() function: the courier at the front of the list is removed.

         2.1.2 Option 2: deleteMiddle() function: the courier at the specific location (using position) of the list is removed.

         2.1.3 Option 3: deleteBack() function: the courier at the back of the list is removed.

         2.1.4 Option 0: return back to the main menu.


#### FINDING THE NODE

1. Get the option from the main function.

2. From the option, the data will be searched by corresponding function either by name, parcel type, source, destination, status or tracking number.

3. The function sets the value of a boolean variable (found) to false.

4. It iterates through the linked list, comparing the attributes of each courier to the corresponding attributes in the searchData.

    4.1 The findNode function uses searchKey to search the courier data based on the option that was chosen by the user.

         4.1.1 Option 1: name with specific searchKey will be displayed.

         4.1.2 Option 2: parcel type with specific searchKey will be displayed.

         4.1.3 Option 3: source with specific searchKey will be displayed.

         4.1.4 Option 4: destination with specific searchKey will be displayed.

         4.1.5 Option 5: status with specific searchKey will be displayed.

         4.1.6 Option 6: tracking number with specific searchKey will be displayed.

         4.1.7 Option 0: return back to the main menu.



 #### SORTING THE LIST

1. Get the option from the main function.

2. The function determines whether the linked list is not empty and has more than one node.

3. It iteratively traverses the list, comparing and swapping elements based on the sorting criterion selected.

      3.1 The sortList function uses sortCriteria to sort the courier data based on the option that was chosen by the user.

            3.1.1 Option 1: courier data sort by name.

            3.1.2 Option 2: courier data sort by parcel type.

            3.1.3 Option 3: courier data sort by tracking number.

            3.1.4 Option 0: return back to the main menu.

#### DISPLAYING THE NODE

1. Display the unsorted data from the file (TEST.txt) that has been read or display sorted data and searched data based on users option.


## Assignment Report <a name="report"></a> 🔔

Submission date: 31-Dec-2023 04:55AM (UTC-0800)

Submission ID: 2265594315

File name: ASSIGNMENT_2_DSA_FABS.pdf (179.44K)

Word count: 1172

Character count: 5829

![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/images/REPORT.jpg)

## Findings <a name="findings"></a>📊

- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/source-code/ASS2.cpp)
- [Input File](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/source-code/TEST.txt)
- [Assignment 2 Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/ASSIGNMENT%202%20DSA%20(FABS).pdf)
- [Similarity Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/ASSINGNMENT%202%20REPORT.pdf)

