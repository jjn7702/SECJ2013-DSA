[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Inventory Management System
The Warehouse Inventory Management System, implemented in C++, is designed for efficient inventory tracking in a warehouse. It uses a queue to manage items and a stack to record user actions. The system allows importing, adding, removing, and displaying items through a user-friendly console interface. It supports input validation and provides functionalities to save the inventory and action history to external files. The code is modular, with distinct classes for items, history, and queues, promoting readability and maintainability. Overall, it provides a straightforward and organized solution for inventory management.


## Table Of Contents
- Objective
- Synopsis
- Class Diagram
- Pseudocode
- Design Description
- Findings





##  Objective

The objective of this project is to develop a Warehouse Inventory Management System using the different concept of data structure algorithm in C++. The system is designed to efficiently manage and perform operations on a collection of goods/items within the warehouse. The program employs a queue algorithm to store and manipulate the data related to goods, providing functionalities such as importing items from a file, adding new items, removing items, displaying the inventory, and stack algorithm for printing a history of actions.  

1) FIFO inventory storing algorithm 
First in first out (FIFO) concept ensures that the oldest items in the inventory are the first to be used or shipped. This helps in rotating stock efficiently, preventing perishable goods expiring or becoming obsolete. It's particularly important for industries where products have a limited shelf life. 

2) Neat and Creative Output: 
Develop a user-friendly and visually appealing interface for displaying inventory and history. 
Ensure clear and descriptive messages for user interactions.

3) Data Hiding and Encapsulation: 
Apply the concepts of data hiding and encapsulation by making the goods class private and providing public methods for accessing attributes.

4) History Tracking: 
Maintain a history of actions performed, including additions and removals, and save this history to a file when exiting the system.

5) User Interaction: 
Provide a menu-driven interface for users to interact with the system, making it intuitive and easy to use.

6) File Operations: 
Enable the system to import goods information from a file, export the result after operation and save the history to a file. 

This project aims to demonstrate effective implementation of linked lists, encapsulation, user interface design, and file operations in a practical application of Warehouse Inventory Management. 

##  Synopsis

The Inventory Management System is designed to productively oversee and perform operations on a collection of products or items inside the stockroom because it is basic for eros businesses or organizations to track or oversee their stock. By utilizing our system, users can oversee the lifecycle of inventory items from the minute they are imported into the system until they take off the distribution center. The system encourages the expansion and evacuation of items through an natural interface, supported by a solid line for item management and a stack for keeping up a brief history of exchanges. Each thing are spoken to as a question with unmistakable properties such as ID, name, price, and location, ensuring clear distinguishing proof and following. History includes permits for the review examination of stock changes, which is basic for inspecting and detailing purposes. Generally, the system points to streamlining stockroom operations, decreasing blunders in stock administration, and giving fast get-to-item and exchange information, making it an important device for any inventory-reliant business. 

## Class Diagram
![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Nothing/Images/WhatsApp%20Image%202024-01-17%20at%2010.04.50%20PM.jpeg)


## Pseudocode

### Main and other function: 

Function main ()  

1. Display welcome screen. 

2. Create an empty itemQueue for managing the inventory. 

3. Create an empty historyStack for recording actions. 

4. Enter a loop to display the menu and handle user choices: 

   a. Display the header. 

   b. Display the menu options. 

   c. Get the user's choice (integer). 

   d. Validate the user's input using isNumber function. 

   e. If the input is not a valid integer, show an error message and continue to the menu. 

   f. Perform actions based on the user's choice: 

      - If choice is 1: 

        - Call import function to load items from a file. 

        - Display import status. 

      - If choice is 2: 

        - Call add function to get item details from the user. 

        - Enqueue the item to the itemQueue. 

        - Push an 'add' action to the historyStack. 

        - Display "Item added!" message. 

      - If choice is 3: 

        - Check if the itemQueue is empty. 

        - If it's empty, display "No item in the inventory!" message. 

        - Otherwise: 

          - Dequeue an item from the itemQueue. 

          - Push a 'remove' action to the historyStack. 

          - Display "Item removed!" message. 

      - If choice is 4: 

        - Check if the itemQueue is empty. 

        - If it's empty, display "No item in the inventory!" message. 

        - Otherwise: 

          - Display items from the itemQueue. 

      - If choice is 5: 

        - Call printHistory function to print history to a file. 

        - Display "Printing history..." message. 

        - Display "History saved into file" message. 

        - Display "Exiting..." message. 

        - Sleep for 2 seconds. 

        - Clear the console screen. 

        - End the program. 

   g. Pause the program for user interaction. 

5. End the program. 

 

DisplayHeader Function: 

1. Clear the console screen. 

2. Display the program header. 

  

Menu Function: 

1. Display the available menu options. 

  

IsNumber Function (input validation for integers): 

1. Check if the input string consists of digits only. 

2. Return true if it's a valid integer, false otherwise. 

  

IsFloat Function (input validation for floating-point numbers): 

1. Check if the input string is a valid floating-point number. 

2. Return true if it's a valid float, false otherwise. 

  

WelcomeScreen Function: 

1. Clear the console screen. 

2. Display a welcome message. 

3. Wait for user confirmation (e.g., press any key). 

  

Import Function: 

1. Open the file "input.csv" for reading. 

2. Create an empty itemQueue. 

3. Read items from the file and add them to the itemQueue. 

4. Close the file. 

5. Display import status. 

6. Return the itemQueue. 

  

Add Function: 

1. Get item details (ID, name, price, location) from the user. 

2. Create a new goods object with the details provided. 

3. Return the goods object. 

  

printHistory Function: 

1. Open the file "history.txt" for writing. 

2. Iterate through the historyStack: 

   a. Write each history node's details (ID, name, price, location, action) to the file. 

3. Close the file. 

 

saveToFile function: 

1. Open file “output.csv” 

2. While item is not empty 

    a. Write item info into file 

    b. Item.dequeue 

3. Close file 

 

## Design 

The Warehouse Inventory Management System is designed to efficiently handle and streamline operations related to inventory management within a warehouse setting. The system comprises key components, including classes for goods, a history stack for tracking transactions, and a queue for managing the inventory.

### Goods Class:
The `goods` class represents individual items in the inventory, with private attributes such as ID, name, price, and item location. The class includes methods for retrieving these attributes, providing a clear and encapsulated representation of each item.

### History Stack:
The `historyStack` class is responsible for maintaining a transaction history through a stack data structure. It stores instances of the `goods` class along with an associated action character ('a' for addition and 'r' for removal). This allows the system to track changes in the inventory over time.

### Item Queue:
The `itemQueue` class is implemented to manage the main inventory. It utilizes a queue data structure to handle the lifecycle of items, allowing for easy addition and removal. The queue maintains a doubly-linked list of `itemNodeQueue` instances, each containing a `goods` object, forming a structured representation of the inventory.

### User Interface:
The main function serves as the user interface, providing a menu-driven system. Users can import items from a file, add new items to the inventory, remove items, display the current inventory, and print/save the transaction history and inventory to files. The system ensures user-friendly interactions by displaying a welcome screen and a clear header throughout the execution.

### File Operations:
The system supports file operations, including importing items from a CSV file, saving the transaction history to a text file (`history.txt`), and saving the current inventory to a CSV file (`output.csv`). This enhances data persistence and facilitates external analysis and reporting.

### Input Validation:
To ensure data integrity, the system incorporates input validation mechanisms. Functions such as `isNumber` and `isfloat` verify whether user inputs are numeric, preventing invalid data entry.

The Warehouse Inventory Management System, with its well-structured classes and functionalities, aims to provide a robust solution for businesses or organizations reliant on efficient inventory management within their warehouses.




## Prepared by 🧑‍💻

| Name             | Matric Number |
| :---------------- | :-------------: |
|  GOH JING YANG   |    A22EC0052    | 
|   LOO JIA CHANG    |   A22EC0074     |
|  LOW JIE SHENG    |   A22EC0075      | 





## Findings 📊

- [Source code](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Nothing/Project/program/project.cpp)
- [Inputfile](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Nothing/Project/program/input.csv)
- [Report](https://liveutm-my.sharepoint.com/:w:/r/personal/gohyang_live_utm_my/_layouts/15/Doc.aspx?sourcedoc=%7B92C7213B-18DE-4231-8478-D07DF392B1B2%7D&file=DSA%20Project.docx&action=default&mobileredirect=true&DefaultItemOpen=1&ct=1705473578873&wdOrigin=OFFICECOM-WEB.MAIN.EDGEWORTH&cid=9962ffda-3870-4d17-a400-1ae1f3d19490&wdPreviousSessionSrc=HarmonyWeb&wdPreviousSession=3116b39b-768c-468a-80d7-d020017bdbcc)
- [Slide presentations](https://www.canva.com/design/DAF6JJZzRj4/GvXNuNystdpJwrXRM5xiVQ/edit?utm_content=DAF6JJZzRj4&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)

