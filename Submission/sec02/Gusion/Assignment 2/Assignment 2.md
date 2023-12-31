[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Airline Reservation System - Assignment 2
## Objective
- Able to `ADD` at(begining, middle, end) and `DELETE` at(begining, middle, end) using `LINKED LIST` 
  in booking list based on name, date of departure, destination and airlines.
- Able to `SEARCH` for information in the list based on the attribute provided.
- Able to `SORT` for information in the list based on the option provided.
- Can display the list after `ADD` or `DELETE` based on user input.
- Can display sorted list based on user input.
- Can display related information based on user search term.
- To apply data structure operations of `SORTING` and `SEARCHING` in the system.
- To apply data structure operations of `LINKED LIST` in the system.


## Description 📝


## Flow of Event 💹
The flow of events in this program. Let's break it down:

1. **Include Libraries:**
   - The program includes necessary C++ libraries like iostream, fstream, vector, etc.

2. **Define Class `Cust`:**
   - Represents customer information.
   - Includes private data members (name, destination, airlines, day, month, years) and member functions for printing results and searching.

3. **Define Class `Node`:**
   - Represents a node in a linked list.
   - Contains a pointer to a `Cust` object and a pointer to the next node.

4. **Define Class `LinkedList`:**
   - Represents a linked list of customers.
   - Includes functions for adding, deleting, searching, sorting, and displaying customers.

5. **Main Function:**
   - Opens a file (`booking.txt`) and reads customer information from it.
   - Initializes a `LinkedList` object (`custList`) and populates it with customer data from the file.

6. **User Menu in Main Function:**
   - Presents a menu to the user with options like adding, deleting, searching, sorting, and displaying customers.

7. **Switch Case for User Choices:**
   - Executes different actions based on the user's choice.

8. **Add Customer (Case 1):**
   - Takes user input for new customer details and adds the customer to the linked list based on the user's choice (beginning, middle, or end).

9. **Delete Customer (Case 2):**
   - Takes user input for deleting a customer from the linked list based on the user's choice (beginning, middle, or end).

10. **Search Customer (Case 3):**
    - Presents a submenu for searching customers by name, destination, airline, or date.
    - Performs a search and displays matching customer information.

11. **Sort List (Case 4):**
    - Presents a submenu for sorting the list by name or airline.
    - Calls the appropriate sorting function in the `LinkedList` class.

12. **Display All Customers (Case 5):**
    - Displays all customers in the linked list.

13. **Exit (Case 6):**
    - Exits the program.

14. **Loop to Main Menu:**
    - The program continues to run in a loop until the user chooses to exit.

15. **File Closing and End of Program:**
    - Closes the file and exits the program.

This program is an interactive customer management system with file I/O, linked list operations, and various functionalities to manipulate customer data.


## Design 🎨

**PSEUDOCODE**
Here's a pseudocode for the main part of our program:

```plaintext
`class Cust:`
    properties: name, destination, airlines, day, month, years

`class Node:`
    properties: data (Cust object), next (pointer to the next node)

`class LinkedList:`
    properties: head, count, initialSize
    Methods: 
        - `addNode`
        - `listcust`
        - `addToBeginning`
        - `addToMiddle`
        - `addToEnd`
        - `deleteFromBeginning`
        - `deleteFromMiddle`
        - `deleteFromEnd`
        - `findNode`
        - `bubbleSortByName`
        - `bubbleSortByAirline`
        - `bubbleSort`
        - `displayAllNodes`

function main():
    initialize custList as an empty LinkedList
    open fileIn for reading "booking.txt"

    if fileIn not found:
        print "File input/output error!"
        return 1
    else:
        while there are lines in fileIn:
            read a line from fileIn
            parse the line using stringstream to extract customer information
            create a new Cust object with extracted information
            add the Cust object to custList using addNode

    initialize position, choice
    display main menu
    repeat until choice is 6:
        read user choice
        switch on user choice:
            case 1:
                get addChoice from user (1, 2, or 3)
                read new customer details
                create a new Cust object
                switch on addChoice:
                    case 1: add to the beginning
                    case 2: read position, add to the middle
                    case 3: add to the end
            case 2:
                get deleteChoice from user (1, 2, or 3)
                switch on deleteChoice:
                    case 1: delete from the beginning
                    case 2: read position, delete from the middle
                    case 3: delete from the end
            case 3:
                get searchKey from user (1 to 5)
                switch on searchKey:
                    case 1: search by name
                    case 2: search by destination
                    case 3: search by airline
                    case 4: search by date
                    case 5: exit search
            case 4:
                call bubbleSort on custList
            case 5:
                display all customers in custList
            case 6:
                print "Exiting the program. Goodbye!"
            default:
                print "Invalid choice. Please enter a valid option."
```

This pseudocode outlines the structure of our program, including class definitions and the main logic for handling user input and interacting with the linked list of customers. We use this as a guide to implement the actual C++ code.


## Prepared by 🧑‍💻

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
| CHE MARHUMI BIN CHE AB RAHIM   | A22EC0147|<a href="https://imgbb.com/"><img src="https://i.ibb.co/hg1vSKm/chemi.jpg" alt="chemi" border="0" width="80" height="80"></a>      |
| MUHAMMAD ARIFF DANISH BIN HASHNAN       | A22EC0204      | <a href="https://ibb.co/CJ4Z8yv"><img src="https://i.ibb.co/gvQp98w/GAMBAR-PASSPORT.jpg" alt="GAMBAR-PASSPORT" width="80" height="80" border="0"></a>  |
| MUHAMMAD IMAN FIRDAUS BIN BAHARUDDIN       | A22EC0216       |<a href="https://imgbb.com/"><img src="https://i.ibb.co/yYcSd4R/imantekk.jpg" alt="imantekk" border="0" width="80" height="80"></a>       |


## Findings 📊

- [Source Code](./Source-code/Assg2.cpp)
- [Input File](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Gusion/Assignment%202/Source-code/booking.txt)
- [Report]

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)


