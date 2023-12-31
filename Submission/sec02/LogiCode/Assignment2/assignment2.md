
# Assignment 2

### Table of Contents
- [Objectives](#-objectives)
- [Synopsis](#-synopsis)
- [Class Diagram](#-class-diagram)
- [Flowchart](#-flowchart)
- [Description of how to implement data structure operations: Sorting and Searching](#-description-of-how-to-implement-data-structure-operations-linked-list)

<br>


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/bc7e2df3-d20d-457c-b9fb-e0574b6a740e" width="3%" height="3%"> Objectives:
- To simulate an actual Hotel Booking System in a way that administrators can use it to manage the room bookings in a hotel.
- To improve understanding and enhance application of data structure: linked list in a real-world scenario.
- To utilize file mechanism in C++ to read data from external files as a simulation of the database of the system.

<br>


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/ac62ef65-848d-41a6-97c2-1ff40be8ecd3" width="3%" height="3%"> Synopsis
The Hotel Booking System is designed for hotel administrators to manage room bookings in a hotel. By using file input operation, the system reads the file containing booking information which are check-in date, check-out date, room number, room type, identification card number and total price of bookings and stores in BookingNode class. With the administrator menu provided, the administrator is able to insert, delete, find, sort and view the booking information stored in the BookingNode class. The menu is further detailed to insert menu and delete menu in which the insert menu involves the insertion of booking data at front, in the middle under certain conditions such as at certain position, before or after certain position, before or after specific booking information like check-in date, check-out date and room number and at the end of the booking data while delete menu involves deleting the first booking, specific position booking, booking with specific check-in date and room number and the last booking data. All menus are operated and implemented with linked list data structure concept and technique. 

<br>


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/aff8a4cc-5395-4a39-9329-0660c64eeb0a" width="3%" height="3%"> Class Diagram
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/aff8a4cc-5395-4a39-9329-0660c64eeb0a" width="80%"><br>
Figure 1: Class Diagram of Hotel Booking System
</p>

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8b3596b0-7214-4cc8-b868-9ab2a0314386" width="3%" height="3%"> Flowchart
<p align="center">
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/5891ba7b-91c6-4b00-8c06-b86758335181" width="15%" height="15%"><br>
  Figure 2: Flowchart of main Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/13f62fee-3843-4a1f-940e-f1d03851f2d8" width="70%" height="70%"><br>
  Figure 3: Flowchart of adminMenu Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/be931299-a607-4ab8-9681-33f6ef476b00" width="70%" height="70%"><br>
  Figure 4: Flowchart of insertMenu Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/1773ca16-aa2b-4978-a160-e5d7db87bc09" width="60%" height="60%"><br>
  Figure 5: Flowchart of deleteMenu Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/8d111e03-5925-48ed-8784-db6f018a7986" width="55%" height="55%"><br>
  Figure 6: Flowchart of readBookingData Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/1741b2c0-6aa7-4728-952b-ebef3bb8a7d4" width="30%" height="30%"><br>
  Figure 7: Flowchart of isEmpty Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/9d07a9f7-68b9-43f2-9de7-364b98699770" width="40%" height="40%"><br>
  Figure 8: Flowchart of insertFront Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/52bf83cf-91e8-4f3e-b131-caf0e03d15c6" width="35%" height="35%"><br>
  Figure 9: Flowchart of insertMiddle Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/f16df4d6-f2e5-4892-bb3b-3a3f95c09674" width="55%" height="55%"><br>
  Figure 10: Flowchart of insertMiddle2CID Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/98cc2ac6-ce49-47c5-a67a-e4d12e023b04" width="55%" height="55%"><br>
  Figure 11: Flowchart of insertMiddle3CID Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/a098fac4-26db-474a-b78a-c1b1b6c897ba" width="55%" height="55%"><br>
  Figure 12: Flowchart of insertMiddle2COD Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/98f86f34-ff2e-47e5-a09b-65203135d1c4" width="55%" height="55%"><br>
  Figure 13: Flowchart of insertMiddle3COD Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8db14ce2-d7d9-4677-b89b-fc6ccde14f5f" width="55%" height="55%"><br>
  Figure 14: Flowchart of insertMiddle2RN Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/72a8e18f-ca54-4830-b15c-54a9a9d5f55a" width="55%" height="55%"><br>
  Figure 15: Flowchart of insertMiddle3RN Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/3adf64ac-4530-4e96-8792-85cd2b72c9eb" width="40%" height="40%"><br>
  Figure 16: Flowchart of insertEnd Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/28d0ea99-0b25-4f65-93c3-74776495663a" width="16%" height="16%"><br>
  Figure 17: Flowchart of deleteFront Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/a7344b35-23b7-4880-8398-dd92c277be88" width="40%" height="40%"><br>
  Figure 18: Flowchart of deleteMid Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/0ebe458b-9ed9-46cf-91b3-971af1140563" width="40%" height="40%"><br>
  Figure 19: Flowchart of deleteMidCR Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/da35bf9f-ea63-4780-bfc2-f416214a6d1d" width="40%" height="40%"><br>
  Figure 22: Flowchart of merge Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/0fccfe2f-b13f-4ff2-aabc-79b7f095ecd8" width="30%" height="30%"><br>
  Figure 23: Flowchart of midPoint Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/40849ca8-7295-4fea-822c-516d3d2f8caa" width="40%" height="40%"><br>
  Figure 24: Flowchart of mergeSort Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/06c77591-e373-4b55-b770-4d4cc66655c4" width="20%" height="20%"><br>
  Figure 25: Flowchart of sortList Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/fd5f8758-ed4d-4b67-a926-41acea6d391e" width="30%" height="30%"><br>
  Figure 26: Flowchart of dispList Function
</p>




### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/fabaacbe-18c1-4f64-a3a5-e1b40e910e71" width="4%" height="4%"> Description of how to implement data structure operations: Linked List

#### 1. Inserting
There are four main types of insert linked list functions for inserting operation in our system, which are insert at the front, insert at the middle based on location, insert at the middle based on the data and insert at the end. 

First, insert at the front (insertFront()), which is implemented by checking if the linked list is empty first. If the linked list has any node, the new node will point to the first node of the linked list. Then, the head points to the new booking data. Besides, for insert at middle based on location (insertMiddle), a temporary pointer is declared and pointed to the first booking data at first.  After that, the temporary pointer will continuously point to the next node until the location specified is reached, the new node will insert at the location by pointing the new node to the next node pointed by the temporary pointer and then the node pointed by the temporary pointer will be pointed to the new node. Furthermore, for inserting the node at middle based on specified data such as insertMiddle2CID(), insertMiddle3CID(), insertMiddle2COD(), insertMiddle3COD(), insertMiddle2RN() and insertMiddle3RN() in our system, it is similar to insert at middle based on location, but the data specified instead of location will be found using loop. After the data is found, the new node can be inserted after the data using the same method as insert based on location. However, for inserting before the data, another pointer (*pre) will be declared in addition to temporary pointers. It will point to the node before the node pointed by the temporary pointer. Once the data is found, the next pointer of the new node will point to the node pointed by the temporary pointer and the next pointer of the node pointed by the pre pointer will point to the new node to complete the insertion operation. Lastly, the insert at the end (insertEnd()) function is implemented by declaring the temporary pointer and pointing to the first booking data of the linked list. The linked list will be checked if it is empty. If it is empty, the head will directly point to the new node. If the linked list is not empty, the temporary pointer will be moved to point to the next booking data until the next pointer of that node points to NULL. Then, the new booking data will be inserted after that node.

#### 3. Finding
The finding operation is implemented by utilizing a counter to track node positions and matching the user input to every node value. Once it finds the match, the position value will be returned to help the user identify the booking. In our case, the findNode() function is used to locate a customer's IC in a booking list. 

First, the findNode() function takes user input as the string parameter. A temporary pointer is set to the first node of the list, and a counter is initialized to 1. Then, a while loop runs as long as the temporary pointer is not null and the IC of the node does not match the user input. Inside the loop, the temporary pointer points to the next node, and the counter is incremented. Once the match is found or the pointer is null, the loop stops. Then the function checks the temporary pointer. It will return the position if the pointer is null, otherwise it displays an error message.

#### 4. Displaying
The dispList() function and getBookingInfo() function are used to display the list of customer bookings which contains check-in date, check-out date, room number, room type, customer IC, and total price.

In dispList() function, a temporary pointer is created and pointed to the first node of the list. A counter is also initialised to 0. The while loop will check whether the temporary pointer is null. If not, it pre-increments the counter, points the pointer to the next node and calls getBookingInfo() function. The getBookingInfo() function is used to display booking details for each node.

#### 5. Sorting
We have implemented Merge Sort algorithm to sort bookings ascendingly based on check-in date using sortList(), mergeSort(), midPoint() and merge() functions. By dividing the linked list recursively into two lists after finding the midpoint, two lists will be compared and sorted then merged back into the original list.

First, sortList() function is called in the main function. The result of mergeSort() function is declared as the first node of the list. mergeSort() function will then check whether the start node of the list is empty. If so, it returns the start node. If not, midPoint() function is called to get the midpoint. The list is then separated into two sublists using the midpoint. The sublists will be separated recursively until all lists with one or zero nodes are left and return the result of merge() function by taking two sublists as parameters.

Inside merge() function, it checks whether one list is empty. If not, it compares the two nodes by their check in date. A new list is created and the node with earlier check in date is inserted as the first node. The merging process will ensure all nodes are merged and return the new list.

<br>

### Source Codes<br>
<a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/LogiCode/Assignment2/assignment2.cpp"> <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/896def01-68aa-4cf4-95d9-144436fd3fa1" width="3%" height="3%"></a><br>

### Report<br>
<a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/LogiCode/Assignment2/Assignment2_Report_LogiCode.pdf"><img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/4bcb35dd-4e85-4aa3-bdf4-744f58a7477e" width="3%" height="3%"></a>
