
# Hospital Reservation System 

## Objectives

Data Sorting: Apply the proper algorithms to perform sorting operations on an array of objects or structs. Select sorting algorithms based on how well they perform given the size and properties of the dataset. Give consumers the ability to choose from a range of sorting criteria, including categories like name, age, or other pertinent characteristics.

An easy-to-use menu system: Create and build an interactive menu system that lets users select alternatives for sorting. Make sure the menu walks users through the selection process and presents the various sorting criteria in an understandable manner.

Managing Files:Create an environment similar to a database by using file handling technologies. Provide functions that enable the permanent storing of patient or physician data by storing and retrieving data from files. This gives the programme a more realistic feel by simulating user interaction with a database system.

Search operation: Execute searching operations on the array of structs or objects. Select appropriate search algorithms according to the features of the dataset. Give consumers a menu to choose certain search parameters, such age, name, or other pertinent attributes, in a manner similar to sorting.

Efficient Interaction among Users: Provide users with succinct and unambiguous cues and messages to assist them in sorting and searching. Give useful feedback on the operations' outcomes, such as sorting lists or noting whether a search was successful or unsuccessful.

Display of Adaptability: Allow users to search and sort across several datasets (e.g., patients and doctors) to demonstrate the program's versatility. This illustrates how adaptable the menu system and applied algorithms are.

Readability and Modularity of Code: Make that the code adheres to readability and maintainability best practices and is modular. To efficiently isolate particular functionalities and make the codebase easy to comprehend and modify, use structures and functions.


## Synopsis

A Hospital Management System is a software system designed to manage doctor and patient records in a hospital. The system has two main functions: sorting and searching. For the sorting function, the user is allowed to sort data according to a specific key in either ascending or descending order. Additionally, the system provides an easy search function for users to search for patient or doctor information using unique keys. This feature helps to facilitate fast searches of information within the system. Overall, the system is developed with a focus on implementing various data structure algorithms such as insertion sort, binary search, and linked lists. By utilizing this algorithm, the system can handle large amounts of data efficiently and effectively.

## Flow Chart

![Alt text](files/images/Flowchart.jpg)

## Sorting Algorithm

The Sorter class facilitates a flexible sorting mechanism that is used to implement the data sorting process. A thorough menu with numerous sorting options suitable for both doctors and patients is shown to users. Basic characteristics like name and age are included in the sorting keys for both patients and doctors. In addition, the system allows patients to be sorted according to three more criteria: illness, IC number, and the attending physician. Because of this adaptability, users can customize the sorting procedure to meet their own requirements. The application has an intuitive user interface that asks users to select the sorting key, the desired order (descending or ascending), and the type of data (patients or doctors). The program's sorting algorithms, such as insertion sort, are smoothly integrated, guaranteeing effective data organization depending on the chosen criteria. This design not only improves the user experience by offering a thorough sorting tool, but it also shows how flexible the system is to meet a variety of data sorting needs.


## Searching Method

The searching process mechanism for our system, implements standalone searching functions. A menu is displayed to allow for the user to pick a searching option. The first menu is to search by Doctor or Patient. The second menu is to search by Name or IC. Our functions have passing parameters of the actual class array(Patient/Doctor), search key that will be inputted by the user and the class array size. The content of our function includes first, the initialisation of the variable “idx” which is an integer datatype. It functions as an index that will be returned back to the main function, which signifies the index of the identical ID/Name of Doctor/Patient, when compared to the user's search key. There is a for loop that will loop through the class array while checking at each index, whether the search key matches the determined element that will be compared to. If matching data is found, the “idx” will be returned signifying, matching data is found. Else, the function returns -1 to signify, no matching data is found. After returning the idx, the display function of class will be called to display the details of searched key to the user.

