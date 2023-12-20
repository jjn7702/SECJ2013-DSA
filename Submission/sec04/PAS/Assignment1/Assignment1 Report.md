# Assignment 1
## Contents
- [Objectives](#-objectives)
- [Synopsis](#-synopsis)
- [Design](#-design)
- [Description](#-description)

## Objectives :bulb:
We have outlined a few objectives for this task, which are crucial in order to provide a guideline that facilitates an efficient execution of the tasks. These said objectives are are as follows:
  - To develop a library management system that can conduct sorting and searching processes based on certain criteria.
  - To develop a system that is user-friendly and produce an output display that is neat and comprehensive.
  - To develop the system using C++ programming language.
  - To ensure that the developed system can run efficiently and effectively.

## Synopsis :page_facing_up:
The Library Management System is designed to manage and view the library’s books that have attributes of book identification, title, author’s name, genre and year of publication. In Assignment 1, the system provides two main functions which are sorting and searching data. The sorting function will arrange the library’s books data, either in an ascending or descending order, based on specific criteria, such as book id, title, author, genre or the publication’s year. The selection algorithm is used to sort the data in either ascending or descending order. The searching function allows users to find a specific book in the library system. They can search for the book based on criteria such as book id, title, author, genre or year.

## Design :art:
### Class Diagram
![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Assignment1/Images/class_diagram.PNG)
### Flowchart

## Description

### Sorting Description
The sorting operation in our Library Management System is implemented using the Selection algorithm. The selection function has 4 parameters: Book list[] which is an array of objects for the Book class, int n the size of array, int op represents the sorting criteria (id, title, author, genre or year) and int opt represents the sorting order (ascending or descending).

	Within the selection function, we used the switch case to determine the sorting criteria based on the op parameter. Each case represents a different attribute of the Book object such as ID, Title, Author, Genre and Year.

	Under each case, the opt parameter is used to determine the order of sorting. For ascending order, the selection function compares the selected criteria value of the current index to that criteria of the largest index. If the criteria value is larger, the current index will be assigned to the largest index. On the other hand, the process is opposite for descending order. If the criteria value of the current index is smaller than the criteria value of the smallest index, then the current index will be assigned to the smallest index. This process is repeated until the current index is equal to the last index.

After the book data is sorted based on the specific criteria, the switch case ends and the sorted data is printed using the print function from the Book class.

### Searching Description
The searching operation in our Library Management System is designed to search for books based on the user's input key. Users can choose to search by 5 different variables, whether by book id, book title, book author, published year or  genre.  

There are 5 different functions for the search feature, which are ‘searchId’, ‘searchName’,  ‘searchAuthor’, ‘searchGenre’ and ‘SearchYear’. Each of these functions takes an array of an object  from the ‘Book’ class as the parameter. Each search function mechanism is similar, where in each function, the system will ask for the user to enter a searching key and compare it in the ‘if’ statement. The key will be compared with the data stored in the system. If the data are matched, the bool value becomes true and the ‘if’ statement will stop the comparison. This is done by implementing the break statement. On the contrary, if the data and the key value have not matched, the bool value will remain false whereas if the user input is not matched with any of the stored data, an error message will appear.

	Next, when the bool value is true, all the details about the searched book will appear which includes the book id, title, author, published year and the genre.

For example, when the user selects option 1 in the ‘Select Searching Type’ menu, the system requires the user to input a book id to search for the desired book by comparing the id with existing book id in the system. Finally, after the book id is matched with an existing book id in the system, the system will display all of the book’s information based on that book id.

