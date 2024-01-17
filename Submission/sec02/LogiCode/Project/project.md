
# Project

### Table of Contents
- [Objectives](#-objectives)
- [Synopsis](#-synopsis)
- [Project Overview/ Problem Analysis](#-project-overview-problem-analysis)
- [Class Diagram](#-class-diagram)
- [Flowchart](#-flowchart)
- [Description of how to implement data structure operations: Binary Tree](#-description-of-how-to-implement-data-structure-operations-binary-tree)

<br>


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/bc7e2df3-d20d-457c-b9fb-e0574b6a740e" width="3%" height="3%"> Objectives:
- To simulate an actual Hotel Booking System in a way that administrators can use it to manage the room bookings of customers in a hotel.
- To improve understanding and enhance application of data structure: Binary Search Tree in a real-world scenario.
- To utilize file mechanism in C++ to read data from external files as a simulation of the database of the system.

<br>


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/ac62ef65-848d-41a6-97c2-1ff40be8ecd3" width="3%" height="3%"> Synopsis
The Hotel Booking System is designed for hotel administrators to manage room bookings in a hotel. By using file input operation, the system reads the files containing admin information which are admin name, position, username and password and booking information which are check-in date, check-out date, room number, room type, identification card number and total price of bookings and stores in AdminNode class and BookingNode class respectively. 

The administrators are then required to enter their username and password to achieve the purpose of Authentication of the Hotel Booking System. The verification is carried out through the searching function implemented by the binary search tree on the username and password inputted in the AdminNode class. 

With the administrator menu provided, the administrator is able to insert, delete, search, view the booking information and number of bookings stored in the BookingNode class. The menu is operated and implemented with pointer-based Binary Search Tree data structure concept and technique. 

<br>

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/7c22dd04-a0ad-4b86-93eb-1b7506935823" width="3%" height="3%"> Project Overview/ Problem Analysis:
In this project, the case study carried out is the Hotel Booking System, which is described to be a system to manage room bookings in a hotel. The primary users targeted for the system are the administrators of the hotel while the secondary users targeted are the staff of the hotel. There are multiple main features that were implemented in the system of this project, including, 

I. Authentication and Security System 
- The user is required to enter their username and password before accessing the Hotel Booking System. The entered information is then verified by the system with the implementation of Binary Search Tree to store admin information which are admin name, position, username and password retrieved from the file (database) and search for matching information to authenticate the administrator.

II. Booking Information Management System
- The booking information is stored by using Binary Search Tree after retrieving from the file (database) in a similar way as Authentication and Security System. The booking details include check-in date, check-out date, room number, room type, identification card number of customer and total price are then used in collaboration to implement functions to insert, delete, search, view booking information and number of bookings in the system.

III. File Handling as the Simulation of Database of System
- By using the external files which store the administrator and booking information, the database of the real world scenario is successfully simulated. The data in the files are read and stored into the system using file operations and Binary Search Tree in C++ respectively. 

IV. User Interface
- In order to enhance user experience, an interactive menu for administrators to perform various operations is created with structured arrangement and design. The administrators menu options include clear instructions for each operation such as inserting a booking, deleting a booking, searching for a booking, viewing all bookings and viewing the number of bookings in the system.

By addressing the main features in the Hotel Booking System, a well-structured system that can manage room bookings in a hotel is achieved at the same time as developing an understanding of data structures of Binary Search Tree and file handling in C++.

<br>


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/aff8a4cc-5395-4a39-9329-0660c64eeb0a" width="5%" height="5%"> Class Diagram
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/74751c5b-ec20-4f99-9709-553f9a8d8679" width="40%"><br>
Figure : Class Diagram of Hotel Booking System
</p>

<br>


<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/4821c68b-0d26-430e-a984-8ca7a41786f4" width="40%"><br>
Figure : Class Diagram of Hotel Booking System
</p>


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8b3596b0-7214-4cc8-b868-9ab2a0314386" width="3%" height="3%"> Flowchart
<p align="center">
  <img src="" width="15%" height="15%"><br>
  Figure 1: Flowchart of deleteBooking Function
  <br><br><br>
  <img src="" width="15%" height="15%"><br>
  Figure 2: Flowchart of getPredecessor Function
  <br><br><br>
  <img src="" width="70%" height="70%"><br>
  Figure 3: Flowchart of isEmpty Function
  <br><br><br>
  <img src="" width="70%" height="70%"><br>
  Figure 4: Flowchart of deleteNode Function
  <br><br><br>
  <img src="" width="60%" height="60%"><br>
  Figure 5: Flowchart of deleteCurrentNode Function
  <br><br><br>
  <img src="" width="55%" height="55%"><br>
  Figure 6: Flowchart of retrieveBooking Function
  <br><br><br>
  <img src="" width="30%" height="30%"><br>
  Figure 7: Flowchart of insertBooking Function
  <br><br><br>
  <img src="" width="40%" height="40%"><br>
  Figure 8: Flowchart of numOfNodes Function
  <br><br><br>
  <img src="" width="35%" height="35%"><br>
  Figure 9: Flowchart of insert Function
  <br><br><br>
  <img src="" width="55%" height="55%"><br>
  Figure 10: Flowchart of retrieve Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/438b3b12-cfbc-49ac-bcfd-05b07830c665" width="55%" height="55%"><br>
  Figure 11: Flowchart of findBooking Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/966f0c97-38f0-44e1-8a5f-6d7ed0df6761" width="35%" height="35%"><br>
  Figure 12: Flowchart of destroyTree Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/37ddabee-bdee-4ecf-9dbd-68344af13d97" width="18%" height="18%"><br>
  Figure 13: Flowchart of displayBooking Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/0361f71b-7fbc-475f-ba94-4980537de5dd" width="35%" height="35%"><br>
  Figure 14: Flowchart of display Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/2a70ecec-328f-4804-bfb2-f4f6fbfcbf8a" width="40%" height="40%"><br>
  Figure 15: Flowchart of countNodes Function
  <br><br><br>
  <img src="" width="40%" height="40%"><br>
  Figure 16: Flowchart of addAdmin Function
  <br><br><br>
  <img src="" width="16%" height="16%"><br>
  Figure 17: Flowchart of adminMenu Function
  <br><br><br>
  <img src="" width="40%" height="40%"><br>
  Figure 18: Flowchart of authenticationAdmin Function
  <br><br><br>
  <img src="" width="70%" height="70%"><br>
  Figure 19: Flowchart of main Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/fc9f7d5d-c417-41a3-9a07-a2ba1b44222e" width="45%" height="45%"><br>
  Figure 20: Flowchart of readBookingData Function
</p>


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/fabaacbe-18c1-4f64-a3a5-e1b40e910e71" width="4%" height="4%"> Description of how to implement data structure operations: Binary Tree
In the Hotel Booking System, we have implemented Binary Search Tree - Inserting, Deleting, Searching, Displaying and Counting in the form of pointer-based to define functions in managing the room bookings in a hotel. This data structure operation works by having two main declarations which are Node declaration and Tree declaration.


#### 1. Inserting
There are four main types of insert linked list functions for inserting operation in our system, which are insert at the front, insert at the middle based on location, insert at the middle based on the data and insert at the end. 

First, insert at the front (insertFront()), which is implemented by checking if the linked list is empty first. If the linked list has any node, the new node will point to the first node of the linked list. Then, the head points to the new booking data. Besides, for insert at middle based on location (insertMiddle), a temporary pointer is declared and pointed to the first booking data at first.  After that, the temporary pointer will continuously point to the next node until the location specified is reached, the new node will insert at the location by pointing the new node to the next node pointed by the temporary pointer and then the node pointed by the temporary pointer will be pointed to the new node. Furthermore, for inserting the node at middle based on specified data such as insertMiddle2CID(), insertMiddle3CID(), insertMiddle2COD(), insertMiddle3COD(), insertMiddle2RN() and insertMiddle3RN() in our system, it is similar to insert at middle based on location, but the data specified instead of location will be found using loop. After the data is found, the new node can be inserted after the data using the same method as insert based on location. However, for inserting before the data, another pointer (*pre) will be declared in addition to temporary pointers. It will point to the node before the node pointed by the temporary pointer. Once the data is found, the next pointer of the new node will point to the node pointed by the temporary pointer and the next pointer of the node pointed by the pre pointer will point to the new node to complete the insertion operation. Lastly, the insert at the end (insertEnd()) function is implemented by declaring the temporary pointer and pointing to the first booking data of the linked list. The linked list will be checked if it is empty. If it is empty, the head will directly point to the new node. If the linked list is not empty, the temporary pointer will be moved to point to the next booking data until the next pointer of that node points to NULL. Then, the new booking data will be inserted after that node.


#### 2. Deleting
In the Basic Operations - Deleting, we have defined four delete linked list concept functions which are deleteFront(), deleteMid(), deleteMidCR() and deleteEnd() functions. The delete operations are implemented by deciding and locating the desirable data to be deleted, setting the pointer of the predecessor of the unwanted data to the successor of the data, declaring the pointer of data that points to the successor to NULL (for deleting first data) and releasing the memory used by the data.

As an example, in our system, the deleteFront() function is used to delete the first booking data by declaring a temporary pointer points to head (first data), pointing head to the data pointed by the next pointer of head to make the second booking data as the first booking data and breaking the pointer connection by declaring the next pointer of the temporary pointer to NULL and finally deleting the temporary pointer. For deleteMid() function, the desirable unwanted booking data location is entered and found using a while loop, points the next pointer of the previous booking data pointer to the booking data pointed by the next pointer of unwanted data and ultimately deleted the booking data found while the deleteMidCR() function will be implemented in a similar way except the function will accept, find and delete the booking data that has matched check-in date and room number at the same time. Lastly, the deleteEnd() function operates by finding and deleting the last booking data and making the second last booking data points to NULL.


#### 3. Searching
The finding operation is implemented by utilizing a counter to track node positions and matching the user input to every node value. Once it finds the match, the position value will be returned to help the user identify the booking. In our case, the findNode() function is used to locate a customer's IC in a booking list. 

First, the findNode() function takes user input as the string parameter. A temporary pointer is set to the first node of the list, and a counter is initialized to 1. Then, a while loop runs as long as the temporary pointer is not null and the IC of the node does not match the user input. Inside the loop, the temporary pointer points to the next node, and the counter is incremented. Once the match is found or the pointer is null, the loop stops. Then the function checks the temporary pointer. It will return the position if the pointer is null, otherwise it displays an error message.


#### 4. Displaying
In the system, the displayBooking() function and display() function collaborate with getBookingInfo() function to display the list of room bookings in the hotel which contains check-in date, check-out date, room number, room type, customer IC and total price.

The displayBooking() function is first called by the option chosen by the administrator to view the booking data in the system. Once called, the function will then call the display() function. The latter then checks whether the argument passed is pointing to NULL. Recursive functions are called if the argument is pointing to a node in which it will call display() function and pass the pointer pointed by the left pointer of the original argument, collaborate with getBookingInfo() to display the current argument room booking data and ultimately call again the display() function and pass the pointer pointed by the right pointer of the original argument. This process continues until the tree points to NULL which means that the tree is a leaf. As a result, the room booking data is printed in inorder traversal.


#### 5. Counting
The Counting operation is used to count the number of nodes in the tree in which in our system it is implemented to count the number of bookings having in the system. To achieve the counting purpose, the numberOfNodes() function and countNodes() function operate together when the numberOfNodes() is called due to the administrator choosing to view the number of bookings in the system. It then calls countNodes() function and in the function, the argument passed examines and if it points to NULL, value 0 is returned while other conditions will return the value of 1 + countNodes(tree->left) + countNodes(tree->right). In a simpler manner, the recursive approach makes each node which is each booking data contribute 1 to the count and then the counts of the left and right subtrees are added. Consequently, the number of bookings is counted and returned.

<br>

### Source Codes<br>
<a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/LogiCode/Assignment2/source-code/assignment2.cpp"> <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/896def01-68aa-4cf4-95d9-144436fd3fa1" width="3%" height="3%"></a><br>

### Report<br>
<a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/LogiCode/Assignment2/Assignment2_Report_LogiCode.pdf"><img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/4bcb35dd-4e85-4aa3-bdf4-744f58a7477e" width="3%" height="3%"></a>

