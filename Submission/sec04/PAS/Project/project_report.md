# Project
## CONTENTS
- [Problem Analysis](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/project_report.md#problem-analysis-%EF%B8%8F)
- Project Designs
- Data Structure Concept Implementation
- Source Code
- User Manual/Guides

## PROBLEM ANALYSIS 🖋️
### OBJECTIVES 💡
We have outlined a few objectives for this project, which are crucial in order to provide methods for a librarian to execute a task more efficiently and effectively. In this program, a librarian is able:
- To view and manage all books in the library
- To add informations of a new book or remove a book from the library
- To check the amount of books in the library
- To facilitate the borrowing and returning of books

### PROJECT OVERVIEW 📄
&emsp;&emsp;&emsp;For this project, we developed a library management system that allows the librarian to manage the books in the library such as adding a new book or delete a book from the library system. Other than that, this system allows the librarian to insert information about borrowing and returning a book process. For example, if a person wants to borrow a book from the library, the librarian will insert the person’s name and book’s details to change the status of that book to not available in the library (borrowed). Then, if that person wants to return the book, the librarian will delete his/her borrowing information from the system and the status of the book is changed to available to borrow.

&emsp;&emsp;&emsp;We implemented two operations of data structure and algorithm to achieve our goals. First, we used a stack-linked list operation to allow the insertion and deletion of a book while we used a queue to handle the borrowing and returning of books.

&emsp;&emsp;&emsp;We have 3 classes in this system, class Node, class Stack and class Queue. The Node class holds a few private attributes which are book id, name, author, genre and year of publication. For public methods, this class has an object named next, a constructor to initialize the local attributes, accessor methods to return the value of the attributes and display() function to print all attributes of a book.

&emsp;&emsp;&emsp;Next, we have a Stack class in which we have an object named top as its private attributes. In this class, we have several public methods to implement the stack operation in our system such as push, pop and stackTop. We also define a constructor to initialize the top value to null, isEmpty() function to check whether the stack is empty or not and display() function to print all data in the stack.

&emsp;&emsp;&emsp;Our last class is named Queue. For this class, we define a few attributes which are front, back and count. We also have a name attribute to represent the borrower's name and a class Node object named b represents a book. We have the basic Queue functions such as enQueue to insert new data in the queue, deQueue to remove data and deQueue(int index) to remove data at a specific position in the queue. In addition, we also define the constructor, isEmpty() and isFull() functions to help the process of queue operations in this system. 
