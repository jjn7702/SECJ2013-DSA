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

**Figure 1: Overall Class Diagram of the Library Management System Program**

The diagram above shows the overall class diagram of the library management system program. 
 In the diagram, we implement two different classes which are Node and BookList. 
 These two classes are joined with each other through an aggregation relationship due to the declaration of a Node pointer inside the BookList class.

![image](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/PAS/Assignment2/Images/NODE%20diagram.drawio.png)

**Figure 2: Class Design of Class Node**

The diagram above illustrates the class design for class Node. This class stores private attributes which are id, name, author, genre, and year. This class also contains a Node object named next which is a pointer, it is used to point to the next address of the data in the list. In this class, we also implemented member functions such as default argument and the accessors of the private attributes.




Figure 3: Class Design of Class BookList


The diagram above illustrates the class design for class BookList. This class stores a private Node object which is a pointer named head. In this class, we implemented various member functions inside this class. These said functions are such as isEmpty(), display(), insertF(), insertM(), insertE(), deleteNode(), searchString(), searchInt(), and insertOption().

Figure 4: Flowchart of the Library Management System’s Operation
The diagram above visualizes how the library management system operates from start to finish. The system goes through multiple layers of processes, such as inserting, deleting and finding a book information. As illustrated above, we also implemented multiple conditions in order to achieve its objectives and desired output. It is crucial for this system to carry out each of the operations and conditions in order to not only produce output correctly but also efficiently .


## DESCRIPTION
### ADDING A NEW NODE

For insertion of a new node in the library list, we define three different functions, insertF to insert at the beginning, insertM to insert in the middle and insertE to insert at the end. For all functions, we declare a new node using class Node and we check if the list is empty. If yes, the new node will be assigned as the head node.

In the insertF function, if the list is not empty, the new node next points to the head node and new node assigned as the head node.

Next, in the insertM, we also declare variable x representing the index and variable count to count the node. If the value of the temp next node points to non null and the count value is less than x minus 1, the temp next node is assigned as the temp node. The process continued until we found the index we wanted. The temp next will be the new node next and new node is assigned to temp next

Last, in the insertE function, the new node will be added and linked at the end of the list if the temp next is equal to null value.

### DELETE A NODE

We declare one function in the libraryList to do the deletion of a node named deleteNode. This function takes one argument, int n, representing the number of nodes in the list. In this function, we have two objects of class Node named temp and delnode. Head is assigned to the temp node. We used a switch case to facilitate the process of deleting. 

Case 1 is to delete at the beginning of the list or the book at the top of the displayed book list. If the list contains only one node, then the temp node is deleted and the null value is assigned to the head node while if the list contains many nodes, deletion will occur after we have assigned the next node as the new head node.

Case 2 is to delete at the end of the list and we
