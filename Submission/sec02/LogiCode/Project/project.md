
# Project

### Table of Contents
- [Objectives](#-objectives)
- [Synopsis](#-synopsis)
- [Project Overview/ Problem Analysis](#-project-overview-problem-analysis)
- [Class Diagram](#-class-diagram)
- [Flowchart](#-flowchart)
- [Description of how to implement data structure operations: Binary Tree](#-description-of-how-to-implement-data-structure-operations-binary-tree)
- [User Guide](#-user-guide)

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
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/c44bca2b-69b9-421f-8b56-4807d9ab16b0" width="25%" height="25%"><br>
  Figure 1: Flowchart of deleteBooking Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/deb7c373-15a3-403c-a4db-4ac20fbb34be" width="40%" height="40%"><br>
  Figure 2: Flowchart of getPredecessor Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/e8b2586d-1d1e-42c9-a8e6-41a3e7e21f4a" width="20%" height="20%"><br>
  Figure 3: Flowchart of isEmpty Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/2b4dfc80-9ef5-40a7-a5f3-e8730628eadb" width="50%" height="50%"><br>
  Figure 4: Flowchart of deleteNode Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/66100e17-eb7a-465b-8052-f9c87a079f55" width="60%" height="60%"><br>
  Figure 5: Flowchart of deleteCurrentNode Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/c6d83f74-041c-4a30-8d52-5fc2dd1300bc" width="30%" height="55%"><br>
  Figure 6: Flowchart of retrieveBooking Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/0a82f249-4e65-4585-888a-e250c1cc8a68" width="30%" height="30%"><br>
  Figure 7: Flowchart of insertBooking Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/68a0ca0d-8215-4b21-89d2-84df74f6fc6e" width="25%" height="40%"><br>
  Figure 8: Flowchart of numOfNodes Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/0366951d-499b-4065-a1de-d738f12618df" width="55%" height="35%"><br>
  Figure 9: Flowchart of insert Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/6157abdd-6400-496c-b83a-2164450e4cf8" width="55%" height="55%"><br>
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
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/628ea5b6-5254-4600-a392-19a607b3884b" width="50%" height="40%"><br>
  Figure 16: Flowchart of addAdmin Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/cf3d089e-efb7-4e89-941e-bd8509228dae" width="60%" height="16%"><br>
  Figure 17: Flowchart of adminMenu Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/4ee26350-b1cc-459d-aad3-c3abd203616a" width="60%" height="60%"><br>
  Figure 18: Flowchart of authenticationAdmin Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/6e2b13ff-89b5-448f-a8db-21f728bbe167" width="70%" height="70%"><br>
  Figure 19: Flowchart of main Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/fc9f7d5d-c417-41a3-9a07-a2ba1b44222e" width="45%" height="45%"><br>
  Figure 20: Flowchart of readBookingData Function
</p>


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/fabaacbe-18c1-4f64-a3a5-e1b40e910e71" width="4%" height="4%"> Description of how to implement data structure operations: Binary Tree
In the Hotel Booking System, we have implemented Binary Search Tree - Inserting, Deleting, Searching, Displaying and Counting in the form of pointer-based to define functions in managing the room bookings in a hotel. This data structure operation works by having two main declarations which are Node declaration and Tree declaration.


#### 1. Inserting
For inserting a new node into the tree, insert() function and insertBooking() functions are used. In our case, the tree is called bookingTree and the node is called bookingTreeNode. inserBooking() function is called in the main function to pass newNode (a bookingTreeNode object) and root (starting node of bookingTree)  to the insert() function. insert() function first checks whether the bookingTree is empty. If empty, then the newNode will become the root. If not, it will compare the check-in date and room number of the currentNode and newNode. newNode will be inserted to the left child nodes of currentNode  if its check-in date is earlier than the root. If both currentNode and newNode contain equal check-in date, newNode will be inserted to the  left child nodes of currentNode  if its room number is smaller. The process continues until newNode is placed in the correct position.

#### 2. Deleting
In the Binary Search Tree - Deleting, we have defined two delete functions which are deleteNode() and deleteCurrentNode(). The delete operations are implemented by deciding and locating the desirable data to be deleted. The deleteNode() function will compare the check-in date and room number data entered by the user. If the check-in date or room number entered is smaller than the check-in date or room number in the node pointed by the tree pointer, the tree pointer will move to the left subtree. On the other hand,  if the check-in date or room number entered is larger than the check-in date or room number in the node pointed by the tree pointer, the tree pointer will move to the right subtree. The moving process will continue until the check-in date and room number entered are equal to the data in the node pointed by the tree pointer. Then, the deleteCurrentNode() function will be called. In the deleting process, if the unwanted booking data has no children at the left side, the unwanted node will be replaced by the booking data at the right side of the unwanted node. If the unwanted booking data has no children at the right side, the unwanted node will be replaced by the booking data at the left side of the unwanted node. However, if the unwanted booking data has two children at both side, the getPredecessor() function will be called to find the booking data located at the right most of the left side of the tree, and the booking data in that node will replace the node with the unwanted booking data. Lastly, the memory used by the unwanted booking data will be released.


#### 3. Searching
retrieve() function and retrieveBooking() function are utilized for searching a booking. By taking the check-in date, room number and a boolean variable as parameters, retrieve() function will check whether the input check-in date and room number are less than current node’s check-in date and room number, if so, then recursively call the function on the left subtree of the starting node. If not, then search it on the right subtree. If the booking is found, the boolean variable will be set as true. retrieveBooking() function is called in the main function to pass the user input to the retrieve() function. 

Besides, the authenticateAdmin() function is used to find the username and password in the tree. The current pointer that is initially point to the root will move to the node at left subtree if the entered username is smaller than the username pointed by the pointer and move to the node at right subtree if the entered username is larger than the username pointed by the pointer until the username and password that same with that one that the user entered is found. If not, the function will return false.


#### 4. Displaying
In the system, the displayBooking() function and display() function collaborate with getBookingInfo() function to display the list of room bookings in the hotel which contains check-in date, check-out date, room number, room type, customer IC and total price.

The displayBooking() function is first called by the option chosen by the administrator to view the booking data in the system. Once called, the function will then call the display() function. The latter then checks whether the argument passed is pointing to NULL. Recursive functions are called if the argument is pointing to a node in which it will call display() function and pass the pointer pointed by the left pointer of the original argument, collaborate with getBookingInfo() to display the current argument room booking data and ultimately call again the display() function and pass the pointer pointed by the right pointer of the original argument. This process continues until the tree points to NULL which means that the tree is a leaf. As a result, the room booking data is printed in inorder traversal.


#### 5. Counting
The Counting operation is used to count the number of nodes in the tree in which in our system it is implemented to count the number of bookings having in the system. To achieve the counting purpose, the numberOfNodes() function and countNodes() function operate together when the numberOfNodes() is called due to the administrator choosing to view the number of bookings in the system. It then calls countNodes() function and in the function, the argument passed examines and if it points to NULL, value 0 is returned while other conditions will return the value of 1 + countNodes(tree->left) + countNodes(tree->right). In a simpler manner, the recursive approach makes each node which is each booking data contribute 1 to the count and then the counts of the left and right subtrees are added. Consequently, the number of bookings is counted and returned.

<br>

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/d824d795-81a4-47ac-8144-171209c36d9c" width="3%" height="3%"> User Guide

##### User Authentication
1. The user enters the username and password.
<br>
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/085e52ed-80ae-4f88-96b1-5e668b768a68" width="30%" height="30%"><br>
</p>
2. If the username and password are valid, it will show “Authentication successful!” and the admin menu.
<br>
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/c4ecb57c-23e8-4cab-9b31-0ee023baecb4" width="30%" height="30%"><br>
</p>
3. If the username and password are invalid, it will show “Invalid username or password”.
<br>
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/5df91a44-10a0-499a-9916-04c3fcf42dbd" width="30%" height="30%"><br>
</p>

##### Insert Booking
1. The user enters ‘1’.
<br>
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/5c587bfc-8c04-457c-9ea7-eeb22ead7270" width="30%" height="30%"><br>
</p>

2. The user enters required information such as check-in date, check-out date,room number, room type, ic and total price.
<br>
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8e2f5cd6-600d-487a-a475-baee1a5abfb8" width="30%" height="30%"><br>
</p>
3. The booking is successfully added.
<br>

##### Delete Booking
1. The user enters ‘2’.
<br>
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/d54d8b52-dcd9-4d1c-bb8d-43f9c0153f25" width="30%" height="30%"><br>
</p>
2. The user enters required information such as check-in date and room number.
<br>
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/d1899f6c-c904-4cf1-9007-f369b4e53134" width="30%" height="30%"><br>
</p>
3. The booking is deleted successfully.
<br>


### Source Codes<br>
<a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/LogiCode/Assignment2/source-code/assignment2.cpp"> <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/896def01-68aa-4cf4-95d9-144436fd3fa1" width="3%" height="3%"></a><br>

### Report<br>
<a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/LogiCode/Assignment2/Assignment2_Report_LogiCode.pdf"><img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/4bcb35dd-4e85-4aa3-bdf4-744f58a7477e" width="3%" height="3%"></a>

