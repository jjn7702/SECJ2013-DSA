# Airline Reservation System ✈️

## Table of Content
- [Project Overview](#project-ov-)
- [Pseudocode](#pseudocode-)
- [Flow Chart](#synopsis-)
- [UML](#flow-chart-)
- [Data Structure and Code Implementation](#linked-list--%EF%B8%8F-)

## Project Overview
 
Airline reservation systems often have many features, such as booking, ticket review, and ticket cancellation. Our airline reservation system focuses on the user's point of view and not on the administrator's. Initially, the user will be given options such as selecting the location of the number of passengers to buy tickets. Moving on, the user will be given six options: review the purchased ticket details, delete all ticket details, display the primary booker, showing total weight of baggage, editing user information, or exit from the system. Throughout this process, we only apply queue implementation on all aspects, including adding, removing or returning data. 
 
## Pseudocode 📑
![Alt text](./image/image.png)

## Flow Chart 📑
![Alt text](./image/flowChartDSA.jpg)

## UML Diagram 📑
![Alt text](./image/UML.png)

## Data Structure Code Implementation 📦 ➡️ 🛑

Here, our code primarily focuses on the Queue Linked List concept. Queue is an operation where the first element inserted into the list will also be the first to be removed from the list. This scenario is also usually known as FIFO (First In First Out) method. Our queue is operated in a linear concept instead of a circular queue.

### Enqueue Method

This method adds a new element at the very first position of the Queue.
![Alt text](./image/image-1.png)
If the queue is empty, the front and rear values will be the same as the newly inserted Node.
Apart from that, if the queue is not empty, the rear pointer will be appointed to the new node, and the rear value will change to a new value, which is a new node.


### Dequeue Method

![Alt text](./image/image-2.png)
As stated before, whoever is inserted first into the list will also be the one who will be removed from the queue.
Therefore, if the queue is not empty, we will create a new temporary node with the same value as the front node.

Later, the front value will be appointed to the one next to it. Before deleting the temporary node, we will display the value of the user, as well as its baggage weight.

Then, if the queue is empty, there will be no operation since there is no single element to remove.


### Display Queue Method
![Alt text](./image/image-3.png)

Our approach to the display queue is to create a new temporary node known as current that will be appointed to the very front of the list.

Then, we first display the destination of the list since every element in the list will have the same values anyway.

After that, a while loop will traverse the list until it reaches a node with a NULL value.

If the queue is empty, it will display the error message and do nothing.

### Get Front Method and Show Primary Booker Method
![Alt text](./image/image-4.png)
Both of these methods have similar functionality.

If you look at the getFront method, it is basically to return the front node. 

Looking at the primary booker, it is to show the value of the front node.

### Is Empty Method
![Alt text](./image/image-5.png)
This method is relatively straightforward. It will return the true or false value if the front value is NULL.
