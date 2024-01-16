# Project
## CONTENTS
- [Problem Analysis](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/project_report.md#problem-analysis-%EF%B8%8F)
- [Project Designs](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/project_report.md#project-designs-%EF%B8%8F)
- Data Structure Concept Implementation
- Source Code
- User Manual/Guides

## PROBLEM ANALYSIS 📊
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

## PROJECT DESIGNS 🖌️
![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/dsa-Page-1.drawio%20(1).png)
Figure 1: Overall Class Diagram for the Software Application

&emsp;&emsp;&emsp;For the software application, we implemented three different
classes which are Node, Stack and Queue. Each of these classes serve different
functions and purposes for the software application which will be broken down one by
one.

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/dsa-Page-2.drawio.png)
Figure 2: Node Class Diagram for the Software Application

&emsp;&emsp;&emsp;The above figure shows the first implementation of a class called
Node. It stores several private attributes such as book id, name, author, genre, and
year. It also stores a public attribute which is a next pointer. Additionally, this
class also implements a constructor, accessors for each of the private attributes,
as well as a display() function for printing purposes. The main purpose of this
class is to serve as a linked list implementation for the next class which is Stack.

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/dsa-Page-3.drawio.png)
Figure 3: Stack Class Diagram for the Software Application

&emsp;&emsp;&emsp;Apart from that, we have also implemented Stack class in our
software application. It only stores one private attribute which is a top pointer
from the Node class. Just like Node class, it also implements a constructor and a
display function. Plus, it implements a push() function to push book data into the
stack, meanwhile pop() function is implemented to pop or remove the top data in the
stack. As of stackTop(), the purpose of this function is to return the top book data
in the stack meanwhile stackTopN() returns the top pointer from the Node class as it
employs the Last-In-First-Out concept.. Lastly, the purpose of isEmpty() function is
to return a boolean value to determine whether or not the stack is empty. 

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/dsa-Page-4.drawio.png)
Figure 4: Queue Class Diagram for the Software Application

&emsp;&emsp;&emsp;For the last class, which is Queue, it stores multiple public
attributes in its class which are front, back, name array and array of pointers
named b. Just like the two aforementioned classes, Queue implements a constructor as
well as a display function named print(). Same as the Stack class, Queue also
implements an isEmpty() function to return a boolean value to determine whether the
queue is empty. It also implements an isFull() function to return a boolean value to
determine whether the queue is full. This class implements two different accessors
which are getBook() to return the array of pointers, b[] from the class Node, and
getName() to return the name of borrower. The Queue class also implements an
enQueue() function to add data into the queue and a deQueue() function to remove the
first data inside the queue, as it employs the First-In-First-Out concept. Lastly,
the class also implements another deQueue() function that removes data at a specific
position.

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/dsa-Page-5.drawio%20(1).png)
Figure 5: Flowchart for the Software Application Operation

&emsp;&emsp;&emsp;The above diagram illustrates the flow of processes that the
software application carries out. It employs multiple different condition statements
and loops in order to execute different operations based on different inputs to
achieve the desired outputs. The software application carries out different
operations such as inserting or removing books into a stack in the library, and
allowing books borrowing via queue operations. Each step of the operation is crucial
in order to produce the correct output efficiently.
