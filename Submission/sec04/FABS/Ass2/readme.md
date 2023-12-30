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
   The objective is to implement a simple courier management system based on linked lists. The program reads courier data from a file, builds a linked list of courier objects, and provides a menu-driven interface for performing various operations on the courier list. Adding a new courier node to the list, deleting a node from the list, searching for a courier node based on specified criteria, sorting the list based on different criteria, and displaying the list are all supported operations.
The following are the code's key features and objectives:

1. Courier Service:
  
   A courier is represented by attributes such as name, parcel type, source, destination, status, and tracking number.
   Provides methods for setting and retrieving these attributes. There is a display method for printing the courier details.

2. Node Class:
 
   A node in a linked list, each of which contains a Courier object and a pointer to the next node.


3. LinkedList Class:
  
   A linked list of Courier nodes is managed. Allows you to insert a new node at the beginning, middle, or end of the list. Supports operations for removing a node from the list's beginning, middle, or end. Provides a method for locating a node using specified search criteria. This function implements a sorting algorithm. Implements a sorting algorithm to sort the list based on various criteria (such as name, parcel type, and tracking number). The list of couriers is displayed.

4. Main Purpose:
   
   The linked list is populated by reading courier information from a file. Implements a menu-driven interface for interacting with the courier list. Adding, deleting, searching, sorting, and displaying courier nodes are all options. The program will continue to run until the user chooses to exit.

5. Input from a File:
    
   The program reads courier information from a file (TEST.txt) and uses it to populate the linked list.


6. Menu-Based User Interface:
    
   To perform various operations on the courier list, the program provides a user-friendly menu.

7. Validation of Data:
    
   Basic input validation includes checking for valid menu options and handling invalid input while searching. In general, the goal is to create a flexible and interactive courier management system based on linked lists that allows users to efficiently manage and manipulate courier data.





## Synopsis <a name="synopsis"></a> 📝

The Courier Management System uses a linked list to store and manage courier data. The program reads data from a file, populates a linked list, and then provides a menu-driven interface for users to do various processes on the courier list. These processes include the adding, deleting, search, sorting, and the display of courier information.

## Design <a name="design"></a> 🎨
![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/images/dsa.jpg)

## Design Description <a name="designdescription"></a> 💹

#### LINKED LIST FUNCTION

The linked list is implemented as nodes, containing a Courier object and a pointer to the next node. These nodes are managed by the LinkedList class, which includes methods for adding a new node (insertFront, insertMiddle, insertBack), deleting a node (deleteFront, deleteMiddle, deleteBack), finding the node (findNode), sorting the list (sortList), and displaying all the nodes (displayList) for the Courier Management System.

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

3. The function begins by setting the value of a boolean variable (found) to false.

4. It iterates through the linked list, comparing the attributes of each courier to the corresponding attributes in the searchData.

5. If a match is found based on the specified search criteria, the courier's information is displayed using the Courier class's display method.

    5.1 The findNode function uses searchKey to search the courier data based on the option that was chosen by the user.

         5.1.1 Option 1: name with specific searchKey will be displayed.

         5.1.2 Option 2: parcel type with specific searchKey will be displayed.

         5.1.3 Option 3: source with specific searchKey will be displayed.

         5.1.4 Option 4: destination with specific searchKey will be displayed.

         5.1.5 Option 5: status with specific searchKey will be displayed.

         5.1.6 Option 6: tracking number with specific searchKey will be displayed.

         5.1.7 Option 0: return back to the main menu.



 #### SORTING THE LIST

1. Get the option from the main function.

2. The function begins by determining whether the linked list is not empty and has more than one node.

3. It iteratively traverses the list, comparing and swapping elements based on the sorting criterion selected.

4. The sortCriteria parameter determines the sorting criteria, and the comparison is performed accordingly.

      4.1 The sortList function uses sortCriteria to sort the courier data based on the option that was chosen by the user.

            4.1.1 Option 1: courier data sort by name.

            4.1.2 Option 2: courier data sort by parcel type.

            4.1.3 Option 3: courier data sort by tracking number.

            4.1.4 Option 0: return back to the main menu.

#### DISPLAYING THE NODE

1. Display the unsorted data from the file (TEST.txt) that has been read or display sorted data and searched data based on users option.


## Assignment Report <a name="report"></a> 🔔

Submission date: 29-Dec-2023 08:22PM (UTC-0800)

Submission ID: 2265594315

File name: ASSIGNMENT_2_DSA_FABS.pdf (179.03K)

Word count: 1167

Character count: 5866

![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/images/REPORT.jpg)

## Findings <a name="findings"></a>📊

- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/source-code/ASS2.cpp)
- [Input File](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/source-code/TEST.txt)
- [Assignment 2 Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/ASSIGNMENT%202%20DSA%20(FABS).pdf)
- [Similarity Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass2/files/ASSINGNMENT%202%20REPORT.pdf)

