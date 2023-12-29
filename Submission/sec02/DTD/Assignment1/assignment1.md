[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Library Management System - Assignment 1
## Objective
The objective of this project for Assignment 1 is to create a Library Management System that will enable the users to efficiently manage the list of books by sorting it by different attributes and searching for books based on certain criterias. The aim of this project is to provide a user-friendly and interactive interface that can help the users to manage their collection of books by organising it and finding specific books easier.

## Sypnosis 📝
The Library Management System is a system that is designed to store information about different books which includes the title, author, publication year, and finally ISBN of the book. When using the system, users will be able to perform sorting and searching operations on the list of books to organise and find books that are within the system. We have made sure that the system can handle the task efficiently.

## Design 🎨

1. Class Diagram
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DTD/Assignment1/classdiagram.png">

2. Pseudocode
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DTD/Assignment1/Pseudocode.png">


## Flow of Event 💹
1. The user is prompted to the main menu of the Library Management System.
2. The user can choose wheter to use Sorting or Searching.
3. If the user selects "Sorting". They will then be redirected to the Sorting Main Menu.
4. The user can then choose to sort the books based on the title (alphabetically from A-Z), author, year of publish, or ISBN number.
5. After choosing either one and getting the results, the user can choose to exit the system, go back to the main menu where the user will need to choose either to sort, or search or sort books based on the other attributes.
6. If the user selects "Searching". They will be redirected to the Searching Main Menu.
7. The user can then choose to search the books specifically based on title,author , year of publish or ISBN number
8. After choosing either one and getting the results, the user can choose to exit the system , go back to the main menu where the user will need to choose either to sort or search, or search for books based on other attributes.

## Implementation

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

- [Source Code](./Assignment1.cpp)
- [Input File](./books.txt)
- [Report](./Assignment1DSA(DTD).pdf)

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)


