[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Library Management System - Project
## Objective
The primary objective of this program is to create an efficient library management system utilizing a stack and queue concept in data structure. The system aims to provide essential functionalities such as adding(enqueue), , deleting(dequeue), stack, and displaying books within the library.


## Problem Analysis 📝

   DTD Library Management System use for an organized and efficient system to manage books and process borrow requests for a library.The system has two concept for implementation which is Stack and Queue.Staff using stack concept which is allows system to add new books,deleting existing books and displaying current list of books.All are managed using the stack concept.In addition, Staff can receive patron borrow requests,view and processing applications using queue concept.Patron interface allows library patrons to request books by entering their name and the title of the book they want to borrow.These requests are kept in a queue.Both interfaces provide a display option that allows users to view current status of books.An iterative user flow allows users to perform multiple actions until they decide to exit the program.In summary, the DTD library management system aims to simplify book management and borrow request processing to ensure the efficiency of library operations by implementing stack and queue concept in data structures to maintain order.  

## Design 🎨

1. Class Diagram
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DTD/Project/Images/CDProject.drawio.png">

2. Pseudocode
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DTD/Project/Images/PseudocodeProject.png">


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

### Stack
  1.Stack Implementation
  
   <li>a. The “Stack” class implements both push and pop operations to manage the books in the library.</li> 
     <li>b. These two operations are used to add new books to the top of the list of books and remove a book from the top of the list. </li>
    <li>c. The “Stack” class methods can only be accessed by a Staff. </li>

### Queue
  2.Queue Implementation
  
  <li>a. The “Queue” class handles two operations : enqueue and dequeue. </li>
  <li>b. The enqueue method can only be accessed by the patrons/ users of the Library Management System while the dequeue is accessed by the staff. </li>
  <li>c. The enqueue is used to add the name of the patron and the title of the book that they want to borrow. </li>
  <li>d. The dequeue is used by the staff to approve the request of the patron to borrow the book. </li>


## User Guide

  1.Staff Operations
  
  <li>a. Add New Book (Push) : Staff can add a new book to the top of the list. </li>
  <li>b. Remove Book (Pop) : Staff can remove the book at the top of the list. </li>
  <li>c. Display Current List (DisplayStack) : Staff can display the current list of books. </li>
  <li>d. Approve Borrow Request : Staff can approve the borrow request done by the patrons and this will dequeue the request from the queue. </li>
<br>
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DTD/Project/Images/staffmenu.png">
  2.Patron Operations <br>
  </br>
  <li>a. Request a book (Enqueue) : Patrons will make a request to borrow books from the library. </li>
  <li>b. Display Current Requests (DisplayQueue) :   Patrons can display the list of requests. </li>
<br>
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DTD/Project/Images/patronmenu.png">
  3.Exiting the System <br>
  </br>
<li>When the user (staff/patron) chooses option 3, they will exit the system. </li>
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/DTD/Project/Images/thankyou.png">

## Prepared by 🧑‍💻

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
| MUHAMMAD DANIAL BIN AHMAD SYAHIR   | A22EC0206        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/129204039?v=4" width=80px, height=80px>     |
| DANIAL HARRIZ BIN MOHD ASINEH @ MOHD ASNEH      | A22EC0152        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/118705607?v=4" width=80px, height=80px>         |
| THEVAN RAJU A/L JEGANATH       | A22EC0286        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/128228505?v=4" width=80px, height=80px>         |


## Findings 📊

- [Source Code](./Project.cpp)
- [Input File](./book.txt)
- [Report](./Project_DSA_(DTD).docx.pdf)

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)



