# Assignment 2
## Contents
- Objectives 
- Sinopsis
- Design
- Description

## OBJECTIVES :bulb:

We have outlined a few objectives for this task, which are crucial in order to provide a guideline that facilitates an efficient execution of the tasks. These said objectives are are as follows:
To develop a system that is user-friendly and produce an output display that is neat and comprehensive.
To develop the system using C++ programming language.
To ensure that the developed system can run efficiently and effectively.
To allow insertion and deletion of book information to/from the library book list using linked list.
To develop a library management system that can conduct processes based on certain criteria.


## SYNOPSIS 📄

The Library Management System is designed to manage and view the library’s books that have attributes of book identification, title, author’s name, genre and year of publication. In Assignment 2, we implemented the linked list concept in our system to let users add new book information or delete an existing book. For both addition and deletion of books, users can either do at the beginning, middle or the end of the list. We also provide a function where users can find a book in the linked list based on their entered search key.


## DESIGN 🎨

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Assignment2/Images/flow-Page-2.drawio%20(1).png)

Figure 1: Overall Class Diagram of the Library Management System Program

The diagram above shows the overall class diagram of the library management system program. 
 In the diagram, we implement two different classes which are Node and BookList. 
 These two classes are joined with each other through an aggregation relationship due to the declaration of a Node pointer inside the BookList class.

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Assignment2/Images/asg2.drawio.png)
Figure 2: Class Design of Class Node

The diagram above illustrates the class design for class Node. This class stores private attributes which are id, name, author, genre, and year. This class also contains a Node object named next which is a pointer, it is used to point to the next address of the data in the list. In this class, we also implemented member functions such as default argument and the accessors of the private attributes.




Figure 3: Class Design of Class BookList


The diagram above illustrates the class design for class BookList. This class stores a private Node object which is a pointer named head. In this class, we implemented various member functions inside this class. These said functions are such as isEmpty(), display(), insertF(), insertM(), insertE(), deleteNode(), searchString(), searchInt(), and insertOption().

Figure 4: Flowchart of the Library Management System’s Operation
The diagram above visualizes how the library management system operates from

