[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Inventory Management System

## Table Of Contents
- Objective
- Synopsis
- Class Diagram
- Pseudocode
- Design Description
- Findings





##  Objective
##  Synopsis

## Class Diagram

### <img src="[https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/b7b1299f-ead1-4e66-ad2e-95b901f4f03c](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Nothing/Images/WhatsApp%20Image%202024-01-17%20at%2010.04.50%20PM.jpeg)" width="3%" height="3%">

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

Open file “output.csv” 

While item is not empty 

Write item info into file 

Item.dequeue 

Close file 

 

## Design 





## Prepared by 🧑‍💻

| Name             | Matric Number |
| :---------------- | :-------------: |
|  GOH JING YANG   |    A22EC0052    | 
|   LOO JIA CHANG    |   A22EC0074     |
|  LOW JIE SHENG    |   A22EC0075      | 

## File
| No | Name |File | 
| -----:| ----- | :------: | 
|1| Document PDF| <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Nothing/Assignment1/Assigment%201%20Group%20Nothing%20.pdf" ><img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Nothing/Images/pdf64.png" width="24px" height="24px" ></a>|



## Findings 📊

- [Source code](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Nothing/Project/program/project.cpp)
- [Inputfile](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Nothing/Project/program/inventory.txt)
- [Report](https://liveutm-my.sharepoint.com/:w:/r/personal/gohyang_live_utm_my/_layouts/15/Doc.aspx?sourcedoc=%7B92C7213B-18DE-4231-8478-D07DF392B1B2%7D&file=DSA%20Project.docx&action=default&mobileredirect=true&DefaultItemOpen=1&ct=1705473578873&wdOrigin=OFFICECOM-WEB.MAIN.EDGEWORTH&cid=9962ffda-3870-4d17-a400-1ae1f3d19490&wdPreviousSessionSrc=HarmonyWeb&wdPreviousSession=3116b39b-768c-468a-80d7-d020017bdbcc)
- [Slide presentations](https://www.canva.com/design/DAF6JJZzRj4/GvXNuNystdpJwrXRM5xiVQ/edit?utm_content=DAF6JJZzRj4&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)

