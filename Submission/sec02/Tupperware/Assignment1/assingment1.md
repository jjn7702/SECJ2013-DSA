# Assignment 1
# Restaurant Management System

### Table of Contents
- [Objectives](#-objectives)
- [Synopsis](#-synopsis)
- [Class Diagram](#-class-diagram)
- [Flowchart](#-flowchart)
- [Description of how to implement data structure operations: Sorting and Searching](#-description-of-how-to-implement-data-structure-operations-sorting-and-searching)

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
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tupperware/Assignment1/System%20Design/classDiagram.png?raw=true" width="30%"><br>
Figure 1: Class Diagram of Restaurant Management System
</p>

### Flowchart
<p align="center">
  <img src=""><br>
  <br><br><br>
</p>




### Description of how to implement data structure operations: Sorting and Searching
##### 1. Sorting

In the coding, the selection concept is utilised to sort the data from the file. The use of selection sorting which has the time complexity of O(n2) is decided as it is simple in the code and efficient for a small list of data. The sorting algorithm is implemented in the FoodIdASC function and PriceASC function, as the coding only sorts based on the food id and price given for each menu. The sorting is only in ascending order as users are more preferably to view in such order compared to the descending order. 

FoodIDASC function sorts the food id based on alphabetical order from A-Z. After the looping ends, the list of menus will display the food id, name of the food, category of the food, and also the price in table format. A column of numbers is also added on the top left table to ease customers for the next operation, which is selecting an order based on the number on the displayed menu. 

PriceASD function sorts the price for each food on the menu from the lowest to the highest price. After the looping ends, the list of menus will display the same information(food id, name of the food, category of the food, and price) in table format. A column of numbers is also included for the ease of customers. 

##### 2. Searching

The program uses a search feature that lets customers easily find the specific food items that they are looking for. The search feature works by matching customer’s input with the name of the dishes on the menu.

SearchhandOrder function works when the customer chooses the search way to find the menu, they will simply type in the name of the dishes. The program will compare the input with the entire menu to see if it is available.


<br>

