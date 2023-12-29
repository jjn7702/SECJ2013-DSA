[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Library Management System - Assignment 2
## Objective
The primary objective of this program is to create an efficient library management system utilizing a linked list data structure. The system aims to provide essential functionalities such as adding, finding, deleting, sorting, and displaying books within the library.
.

## Sypnosis 📝
The program utilizes a linked list to store information about books. Each book is represented by an instance of the Book class. The linked list is implemented using the Node and Library classes. The Library class provides methods to perform various operations on the linked list, such as adding, deleting, finding, sorting, and displaying books. The main function interacts with the user through a menu, allowing them to manage the library efficiently.

## Design 🎨

1. Class Diagram
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DTD/Assignment2/ClassDiagramASG2DSA.drawio%20(2).png">

2. Pseudocode
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DTD/Assignment1/Pseudocode.png">


## Flow of System 💹
1. The user is prompted to the main menu of the Library Management System.
2. The user can choose wheter to use Add Book,Search Book,Delete Book,Sort Books and Display Books or Exit.
3. If the user selects "Add Book". They will then be ask to add the book whther in front,middle or end of the arrangement of books.
4. The user can then input the books based on the title (alphabetically from A-Z).
5. After choosing either one and getting the results, the user can choose to exit the system, go back to the main menu where the user will need to choose either to add book, or search or delete book or sort book or display based on the other attributes.
6. If the user selects "Search Book". They will be redirected to the Searching Main Menu.
7. The user can then choose to search the books specifically based on title,author , year of publish or ISBN number.
8. If the user selects "Delete Book". They will be ask to delete by input the title or ISBN number of the book.
9. If the user selects "Sort Books". They will then be redirected to the Sorting Main Menu.
10. The user can then choose to sort the books based on the title (alphabetically from A-Z), author, year of publish, or ISBN number.
11. If the user selects "Display Books".The system will display the book based on what user prompt in sorting books menu.
12. After choosing either one and getting the results, the user can choose to exit the system , go back to the main menu where the user will need to choose either to sort or search, or search for books based on other attributes.

## Implementation

### Linked list
-The linked list implementation is a crucial aspect of the program, as it enables dynamic management of book data. The Library class encapsulates operations such as adding books to the beginning, middle, and end of the list, finding and deleting books based on title or ISBN, and sorting books by title, author, year, or ISBN.

The addNode method facilitates the addition of a new book node at the front of the linked list.By creating a new node with the book's information and updating the head, this operation maintains chronological order in the library. This operation is crucial for efficiently inserting new books and maintaining a chronological order within the library.

The addNodeMiddle operation enhances the library's functionality by allowing the insertion of a new book node at the middle position of the linked list. This operation calculates the middle position based on the current size of the list and intelligently inserts the new node, providing a more organized structure.

The addNodeEnd operation provides users with the flexibility to append new books to the end of the linked list. it traverses the list to find the last node and seamlessly integrates the new book, accommodating users who prefer appending new entries.This is beneficial when users prefer to add books without disrupting the existing order or when dealing with a continuously expanding collection. 

The findNode method searches for a book node in the linked list based on the title or ISBN. This operation is essential for retrieving specific books from the library. Utilizing a pointer to traverse the list and compare titles or ISBNs, this operation returns a pointer to the matching node or null if no match is found. 

The deleteNode method enables the removal of a book node from the linked list based on the title or ISBN. Employing two pointers to traverse and locate the target node, this operation ensures the list remains updated and accurate in its representation of the library.


### Sorting
- In the program, sorting is implemented using straightforward algorithms, such as the bubble sort algorithm, for simplicity and ease of understanding. Each sorting function corresponds to a specific criterion: title, author, year, or ISBN. The sorting algorithms iterate through the array and compare adjacent elements, swapping them if they are out of order. This process is repeated until the entire array is sorted according to the chosen criterion.

### Searching
- Searching is implemented using a linear search algorithm, where the program iterates through the array to find a match based on the user's input. Similar to sorting, searching functions are designed for specific criteria: title, author, year, or ISBN. For instance, the searchByTitle function prompts the user to enter a book title, and then it iterates through the array to find and display books with matching titles. Linear search is effective for small datasets and ensures that all matching elements are found.

## Prepared by 🧑‍💻

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
| MUHAMMAD DANIAL BIN AHMAD SYAHIR   | A22EC0206        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/129204039?v=4" width=80px, height=80px>     |
| DANIAL HARRIZ BIN MOHD ASINEH @ MOHD ASNEH      | A22EC0152        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/118705607?v=4" width=80px, height=80px>         |
| THEVAN RAJU A/L JEGANATH       | A22EC0286        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/128228505?v=4" width=80px, height=80px>         |


## Findings 📊

- [Source Code](./Assignment2.cpp)
- [Input File](./book.txt)
- [Report](./Assignment1DSA(DTD).pdf)

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)



