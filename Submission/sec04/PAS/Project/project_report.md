# Project
## CONTENTS
- [Problem Analysis](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/project_report.md#problem-analysis-%EF%B8%8F)
- [Project Designs](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/project_report.md#project-designs-%EF%B8%8F)
- [Data Structure Concept Implementation](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/project_report.md#data-structure-concept-implementation)
- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec04/PAS/Project/files/source%20code)
- [User Manual/Guides](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/project_report.md#user-manual-)

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

## DATA STRUCTURE CONCEPT IMPLEMENTATION
In this project, we implemented 2 different data structures learnt in the 
Data Structure and Algorithm course throughout this semester which are 
stack and queue. The Library Management System is designed to manage and 
view the library’s books that have attributes of book identification, 
title, author’s name, genre and year of publication. Stack data structure 
is implemented in this system to store book information that is read from 
an input file, to store the book information entered by the user and to get 
the details of the most recently added book. On the other hand, Queue data 
structure is implemented to store all the customer’s name that are 
borrowing books from the library, to store the customer’s name that are 
waiting to borrow books that are currently unavailable, to remove the name 
of the borrower that has returned the borrowed book and lastly to remove 
the name of the customer that queued for a book that is previously 
unavailable and enter the customer’s name and the details of the borrowed 
book into the ‘borrower’ queue.

### DATA STRUCTURE: STACK
Book information is stored in a stack. For the implementation of stack, 2 
classes are written in the code which are class Node and class Stack. In 
this project, the program reads the book details from an input file named 
‘inp.txt’. After reading each book’s details the system will then push the 
book information into the stack by using push() function to store them in 
the stack. Other than reading book information from the input file, our 
program accepts user input to add new books into the system. The user can 
enter the book's details such as the book id, title, author, genre, and 
year of publication. Once the information is entered, it will be pushed 
into the stack. Switch case is implemented in our program where the switch 
expression is the user's option from an option menu as shown in the diagram 
below.

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/QUEUE%20IMAGE.png)

When the user enters option 1, the system will ask for the book’s details 
to be pushed into the stack as explained above. Next, pop() function is 
used to delete the latest book in the stack. When the user chooses the 
second option in the option menu,  the switch case in the main() function 
will call the pop() function in class Stack to delete the latest book in 
the stack. Other than that,  The stackTop() function returns the id of the 
book at the top of the stack. When the user picks option 4 from the menu, 
the program uses the stackTop() function from class Stack to get the book 
information stored at the top of the stack. This can be clearly shown by 
the code segment below. 

GAMBAR 2

### DATA STRUCTURE: QUEUE 

For the implementation of queue data structure, we implemented class Queue 
and 2 objects for the class queue are implemented in the main() function, 
one named ‘borrow’ and another named ‘request’. The ‘borrow’ queue is used 
to store the borrower’s name into the queue. When the user chooses option 
number 6, the system will ask for the name of the borrower and the book id 
of the book to be borrowed. Based on the book id, if the book is available, 
the customer will get to borrow the book and the customer's  name is put 
into the ‘borrow’ queue using the enQueue() function that is called in the 
main() function from the class Queue. On the other hand, if the book is not 
available,  by using the enQueue() function, the customer name is put into 
the ‘request’ queue. When user enters option number 7, the first borrowed 
book in the ‘borrow’ queue is returned to the returnedBook object of class 
Node using the getBook() function from the class queue. Then, deQueue() 
function is implemented in the main() function to delete the book that has 
been returned from the ‘borrow’ queue. If there are people requesting for 
the recently returned book in the ‘request’ queue, the book returned will 
automatically be given to the first person in the ‘request’ queue. This can 
be clearly shown in the output diagram below.


## SOURCE CODE 🧩
[Main.cpp & inp.txt](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec04/PAS/Project/files/source%20code)

## USER MANUAL 🕹
### Enter a new book
    Your Option: 1
    -----Insert Book Details-----
    ID: B011
    Book Title: When Breath Becomes Air
    Book Author: Paul Kalanithi
    Year: 2016
    Genre: Non-Fiction
Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o1.PNG)

### Undo/Remove the latest book
    Your Option: 2
Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o2.PNG)

### Get Current Number of books
    Your Option: 3
Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o3.PNG)

### Get most recently added book
    Your Option: 4
Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o4.PNG)

### Display current list of books
    Your Option: 5
Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o5.PNG)

### Borrow Book
    Your Option: 6
#### If the book is available to borrow

    Enter the name of borrower: Seri
    Enter the ID of the book to borrow: B009

Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o6a.PNG)

#### If the book is already borrowed by someone else
    Enter the name of borrower: Puteri
    Enter the ID of the book to borrow: B009

Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o6b.PNG)

### Return Book
    Your Option: 7
#### If there is the next person in request queue that wants to borrow the returned book
Example situation: Seri returned book B009 and Puteri is in the request queue to borrow book B009

Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o7a.PNG)

#### If there is no person in the request queue that wants to borrow the returned book
Example situation: Puteri returned book B009 but no one in the request queue wants to borrow book B009.

Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o7b.PNG)

#### If the request to borrow books queue is empty
Example situation: Aliyah returned book B002 but the request queue is empty.

Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o7c.PNG)

### Display all request to borrow book
    Your Option: 8
#### If empty
Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o8a.PNG)

#### If not empty
Example Output:

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Project/files/images/o8b.PNG)

### Exit
    Your Option: 9

The program will terminate.
