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
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DTD/Assignment2/ClassDiagramASG2DSA.png">

2. Pseudocode
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DTD/Assignment2/Pseudocode.png">


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

### Linked List
The program's linked list is a crucial component. Book data can be managed dynamically with the help of this data structure. The Library class encompasses functions like appending books to the start, middle, and finish of the list, locating and eliminating books according to their ISBN or title, and organising books according to their ISBN, title, author, year, or sort order.

A new book node is added into the list by using the addBookfront function. This function will add a new book that will act as a node to the current list of books. The book will be added to the front of the list.

In addition,a new node for book is position at the middle or the linked list.The addBookMiddle can add the book to the middle of the book list.The function make it more organised because it is being updated in the middle of the book list depending on how much the total of books following the file and when inserting a new data.

Other than that, users can also add new books to the end of the linked list by using the addBookEnd function. By executing this function, the new book will then appear at the end of the list when the displayBook function is called to display the books.

Next is the findBook function, this will enable the users to find books from the library/linked list based on user input. The user can input either the title of the book or the ISBN number of the book that they want to find.

Finally, the deleteNode function can be used to delete the nodes in the data in the file based on the user input. The user can choose to delete the book/node in the front, middle, or end. After the deletion process, the updated list of books will appear and the user can check whether the book is deleted.



### Sorting
In the program, sorting is also implemented. The type of sorting that is used in the program is the bubble sort. This type of sorting was chosen because it is straightforward and is easier to implement. The user can choose to sort the list of books by the attributes such as title, author, year of publication and ISBN number.




## Prepared by 🧑‍💻

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
| MUHAMMAD DANIAL BIN AHMAD SYAHIR   | A22EC0206        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/129204039?v=4" width=80px, height=80px>     |
| DANIAL HARRIZ BIN MOHD ASINEH @ MOHD ASNEH      | A22EC0152        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/118705607?v=4" width=80px, height=80px>         |
| THEVAN RAJU A/L JEGANATH       | A22EC0286        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/128228505?v=4" width=80px, height=80px>         |


## Findings 📊

- [Source Code](./Assignment2.cpp)
- [Input File](./book.txt)
- [Report](./Assignment_2_DSA_(DTD).pdf)

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)



