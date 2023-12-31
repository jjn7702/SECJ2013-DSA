# Assignment 2
# Restaurant Management System

### Table of Contents
- [Objectives of The Project](#Objectives-of-The-Project)
- [Synopsis](#Synopsis)
- [Class Diagram](#class-diagram)
- [Pseudocode](#pseudocode)
- [Implementation of Linked List](#implementation-of-linked-list)
- [Implementation of Sorting](#implementation-of-sorting)

## Introduction
### Objectives of The Project
<li>To stimulate the Restaurant Management System </li>
<li>To apply data structure operations such as sorting and searching in the system</li>

### Synopsis
For this project, we will develop a Restaurant Management System to manage orders in restaurants. This system is for the admin of the restaurant to manage orders from the customers and for the customer to make orders from the list of menu provided.

The types of data structures used in this system are sorting and searching. The class that is involved in this system is the Menu class. The system will display the menu for customers to view. Customers can choose to view in a new way where sorting is implemented or by searching the name of the food from the menu list. If the user wants to view it in a new way, the system will provide a list of options where option 1 is to sort by alphabet and option 2 is to sort according to the price in ascending order. Customers can enter the name of the food and choose whether they want to add the menu to the cart.  Then, the system will ask the customer if they want to make an order. Customers can make multiple orders until they enter ‘N/n’ to stop. The system will then display the list of orders made by the customers along with the total payment for their order. If the customer does not want to make an order, “No orders made.” will be displayed. Additionally, the use of file handling ensures data persistence, allowing the restaurant to store and retrieve order information across sessions. 

## System Design

### Class Diagram
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tupperware/Assignment2/System%20Design/class%20diagaram%20assignment2.drawio.png?raw=true" width="30%"><br>
Figure 1: Class Diagram of Restaurant Management System
</p>

### Pseudocode
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tupperware/Assignment2/System%20Design/pseudocode.jpg?raw=true" width="30%"><br>
Figure 1: Pseudocode of Restaurant Management System
</p>

### Implementation of Linked List
This assignment requires a few manipulations of the node using a linked list, such as inserting a new node and deleting a node at a time. In the insert new node, four manipulating operations have been implemented: insert a new node at the front(insertAtFront), at the end of the list(insertAtEnd) and at the middle of the list(insertAtMiddle).

For the insertFront function, it will insert a new node at the very first node in the list. The new node will be the head while previous head will become the second node. Meanwhile, insertAtEnd function only add a new node at the very last node in the list. The funciton will not modify any node before as there is only an addition of node.  Lasty, insertAtMiddle function is to add new node at any place in the list. This function asks user to input a food ID that exist in the list. When the system read the food ID, the function will add the new node after the node inserted by user.

For the delete node, there are three operations which are delete at the front of the list(deleteFront), at the end of the list (deleteEnd) and delete at the middle of the list (deleteMiddle). The deleteFront function operates by deleting the first node in the list. The deleteEnd function is used to delete the last node in the list. Furthermore, the deleteMiddle function operates by deleting a node from the middle of the node list. These three operations will print out an error message if the list is empty. The node list will be updated after delete node is operated. 

There are three different methods to find a node: findNodeName, findNodeCategory, and findNodeFoodId. These methods are implemented in the OrderList class to search menus based on name, food category and food id. Through the linked list, these operations compare the search criteria with the menu attributes of each node until a match is found.

### Implementation of Sorting
This coding also implements a sorting operation to give users a better viewing experience. The selection concept is used again, with a time complexity of O(n2), to sort the menu list based on two users' input: food ID or price. Compared to the previous assignment, this assignment implements sorting in both ascending and descending. Giving users a variety of options to choose from. This sorting algorithm differs from the previous coding, taking the Orderlist variable as the parameter. Both functions, sortFoodID, and sortPriceID, will prompt the user to enter either 1 or 2. If the user input 1, the boolean parameter being passed on is true, while for input 2, the parameter is false. The ascending order will be operated on if true, meanwhile descending on false. The condition will first check whether the current node(the head) is null. If the head is empty, a minMaxNode is assigned to the current node, and a temporary node is given to the next node for the current. An inner looping is performed to find the maximum or minimum node in the list. Every time a new node has a smaller or bigger value, the minMaxNode will be updated. Swaps will occur after the maximum or minimum node is acquired until all nodes are in the correct position. Finally, the function will return the newly sorted menu list.



<br>


