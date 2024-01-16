# Hotel Booking System - Project
## Prepared By The Trio
| Name         | Matric No    |
|--------------|--------------|
| Nur Hafizah Binti Jafri     | A22EC5022 |
| Nursyuhada Binti Badren     | A22EC0253 |
| Eddy Koh Wei Hen            | A22EC0154 |

## Findings 📊

- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec04/The%20Trio/Project/Source%20Code)
- [Plagiarism Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/The%20Trio/Project/Project%20Plagiarism%20Report.pdf)
- [Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/The%20Trio/Project/DSA%20Project%20Report.pdf)
- [UML Diagram and Flow Chart](https://app.diagrams.net/#G1qRs-q7iZpkrkau2ri2tI_dkmzvK0DKnU)
- [Presentation Slide](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/The%20Trio/Project/DSA%20Presentation%20Slide.pdf)


## Project Overview
  This project is an agent-based hotel booking system that uses classes to represent customers, a queue to manage reservations, and a stack to handle accepted booking requests. There are two characters that use the system, who are the agent and the hotel manager. The agent is the person who helps the customers to do a booking request and the booking list will pass to the hotel manager. The hotel manager will accept the booking request from the list passed by the agent. Customers are characterized by attributes such as name, age, IC number, phone number, room number, and check-in date. The queue class manages the reservation list and offers operations such as adding reservations, searching for customer data obtained in the reservation list, displaying the reservation list, and processing bookings by hotel agents. The stack class handles the list of accepted booking requests, allowing the hotel manager to accept new requests, cancel bookings, find customer data from the accepted list, and display the accepted list. The main function initializes customer data from a file named “Project.txt” and provides a user interface that allows individuals to act as either agents or hotel managers. A loop ensures continuous interaction until the user chooses to exit, with functions being called based on user choices. The program employs both queue and stack classes to manage reservations and accept booking requests.

  Using classes in this project has several perks, significantly the idea of encapsulation, which is when classes effectively group relevant methods and related data attributes into separate objects, like the class Customer. Furthermore, class abstraction can be useful in concealing complex implementation details from other components so that users may interact with simplified interfaces. This abstraction helps developers to comprehend code simply by creating a separate division between the system's internal functions and its external interactions. Additionally, the main idea of code reusability is facilitated by the use of classes. Classes help organizations and improve the clarity of the codebase. Whether a class represents a customer or a particular system functionality such as the Queue or Stack, it always operates as a separate entity with a well-defined purpose. This modular architecture improves code comprehension and scalability simply by facilitating the easy addition of new features or functionalities through the creation or modification of classes.

  
## Objective
Our objectives for this project are:

a. To help the agent store customer information in the hotel booking reservation list using the queue data structure concept

b. To help the hotel manager manage the customers’ booking requests in the accepted booking request list using the stack data structure concept

c. Keep a record of booking details, such as customers’ name, age, IC number, phone number, room number and check-in date

d. To allow changeable functions such as push and pop function in stack data structure concept as well as enQueue and deQueue function in queue data structure concept


## Synopsis📝
Our hotel reservation system uses two key structures, which are queue and stack. The queue, which is used by the hotel’s staff, uses a pointer in a class called Queue. This design allows the queue to accommodate an unlimited number of customers, just like a real hotel can. The queue operates on a first-come, first-served basis, meaning the first booking request received is the first one to be processed. Besides, the stack is used by the hotel manager and is using  an array in a class called Stack. This design reflects the reality that a hotel has a limited number of rooms. The stack operates on a last-in, first-out basis, meaning if there’s an issue with a room, the most recent booking can be canceled first. Lastly, our hotel reservation system uses a queue to handle customer requests and a stack to manage room availability. This setup ensures a fair process for customers and efficient management for the hotel.

## Design
Here is the link for Class Diagram and Flow Chart: [UML & Flow Chart](https://app.diagrams.net/#G1qRs-q7iZpkrkau2ri2tI_dkmzvK0DKnU)

## Design Description
### Main function
1. **Variable Declaration**: Declaring a set of variables (`name`, `IC`, `phoneNum`, `date`, `age`, `room`) that are used to store the customer data read from the file.

2. **Open File**: Open the file "Project.txt". If the file cannot be opened, an error message is displayed and the function returns 1, showing an error occurred.

3. **Reading Data**: If the file is successfully opened, the function enters a while loop where it reads each line of the file. For each line, it reads the customer's name, age, IC, phone number, room number, and date.

4. **Object Creation**: After reading the data, the function creates a `customer` object and sets its properties using the data read from the file. The `setName`, `setAge`, `setIC`, `setPhone`, `setNum`, and `setDate` functions are used to set the properties of the `customer` object.

5. **Data Storage**: The `customer` object is then stored in an array of `customer` objects. The `custNum` variable is used as the index for the array and increases after each `customer` object is stored.

6. **Close File**: After all the data has been read and stored, close the file.


## Data structure concept implementation
In this project, our group has implemented two data structure concepts for the agent-based hotel booking system, which are the queue data structure concept and the stack data structure concept.

### Queue Implementation
We have implemented a queue in the class Queue. The queue is in pointer style, in which all the functions inside the class are done using pointers. The class queue is used by the agent for this system. The advantage of implementing a pointer style is that it does not have a size limit. It acts as a reality where the agent just helps the customer book the hotel and does not have limitations on how many customers he wants to help. The concept also applies to agents because the queue is first in, first out, so when the hotel manager accepts the booking request, the first reservation will be deleted from the list. To conclude, first come, first served is applied.
First, we declare two private attributes for the class, which are *front and *back. For *front, it is used to point the first data in the queue and for *back, it is used to point the last data in the queue.

#### Queue()
1. It act as a constructor for the class Queue
2. When we declare a class Queue in main body, we initialize the *front and *back pointer point to NULL because we haven’t insert any customer data inside the class 

#### bool isEmpty()
1. The function is used to detect whether there is customer data inside the class or not
2. We detect the emptiness of the class by returning ( (front == NULL) && (back == NULL) ) 
3. If either one of the pointers is pointing to NULL, the function will return true
4. The function will return false if both pointers are not pointing to NULL

#### Customer* getFirstReservation()
1. The function is used to get the first customer data in the class Queue
2. We detect the emptiness of class using the isEmpty() function
3. If the class does not contain any customer data, it will display “The reservation list is empty"
4. If the class contains customer data, it will return the first customer data by using pointer *front

#### void makeReservation(Customer *newCustomer)
1. The function acts as enQueue() which means enter data into the class
2. The parameter of (Customer *newCustomer) is pointing a customer data from main body
3. We detect the emptiness of class using the isEmpty() function
4. If the class does not contain any customer data, the new customer data will be the first data insert in the class by pointing *front and *back to the data
5. If the class contains customer data, the *next pointer (declared in class Customer) of the *back pointer will point to the new customer which means the new customer data will be arranged after the last data inside the class. Then, the *back pointer will point to the new inserted data to become it the last data inside the class

#### void findCustReserveList()
1. The function is used to search the customer data obtained in the class by specific keyword
2. We detect the emptiness of class using the isEmpty() function
3. If the class does not contain any customer data, it will display “The reservation list is empty. Unable to search …” then return to main body
4. The function will display option menu for user (agent) and get the option from user
5. We declare pointer *current equal to front (point to first data), *prev equal to NULL for purpose later
6. We also declare a “bool found = false” to check the presence of customer data inside the class. “False” means the data haven’t found yet
7. Enter the switch case, if option is other than 1 to 6, it will looping to display option menu again and get user option
8. If user key in option = 1, the function will display “Please key in the name you want to search” and get the n (name) key in by user.  The line “while( (current != NULL) && (!found) )” is used for looping if haven’t got the same name inside the class as the name input by the user. It will continue looping if *current not equal to NULL and found = false. The pointer *current  will start from first data inside the class, it will detect the current pointed data is same name as user key in or not, if same found = true, then *prev will point to *current to obtain the data pointed by *current and *current will point to its next data, as found = true, the loop will break. If not found the name same as user input, the function will continue looping until *current = NULL means the end of data inside the class, found will not equal to true as all the data not same as user input
9. For case just now, if obtain the same name (found == true), the function will start to display customer data using *prev pointer. The reason of using *prev instead of using *current is because while *current pointing name is same as user input, found change to true but the loop is continued, *prev have equal to *current and *current has pointed to the next data. Therefore, the *prev has pointed to the name same as user input and *current has pointed to other data. If not obtain the same name which means found remain false, the function will display “No record found”
10. The same concept is apply to option = 2 to 6 and 2 is for searching age, 3 for searching IC number, 4 for searching phone number, 5 for searching  room number and 6 for searching check in date

#### void DoneBooking()
1. The function acts as deQueue() which means delete the first data in the class
2. We detect the emptiness of class using the isEmpty() function
3.If the class does not contain any customer data, the function will display “No reservation in the list”
4. If the class contains customer data, we declare a *delcust pointer = *front pointer for purpose later
(delcust != back) means there are many customer data in the class since at first we insert the first data by point *front and *back to the new inserted data, to insert again data *front remain and *back point to the new inserted data. 
5. If the class contains more than one customer data, we set *front pointer point to the next data inside the class and the *next pointer of the *delCust point to NULL to break the line for *delCust pointed customer data between the queue
6. If the class contains only one customer data, we just set *front and *back point to NULL to delete the customer data from the queue
*delCust point to NULL to prevent the system confuse which customer data is in the queue

#### void displayReservationList()
1. We declare pointer of *temp = *front and *prev = NULL for purpose later
2. We detect the emptiness of class using the isEmpty() function
3. If the class does not contain any customer data, the function will display “The reservation list is empty”
4. If the class contains customer data, the *prev will point to *temp pointed data. The customer data will be display by using *prev pointer. After display the customer data, *temp will point to the next data inside the queue. The display process will continue until *temp is point to NULL which means the end of data inside the class



### Stack Implementation
We have implemented a stack in the class Stack. The stack is in array style in which all the customer data is stored using an array. The class stack is used by the hotel manager for this system. The implementation of an array style is due to the size limit. It acts as a reality where the hotel has a limited number of rooms and cannot accept all the booking requests if the room is full. The concept also applies to the hotel manager because the stack is last in first out, it modifies the situation of if the room that customer booked has faced a problem like the room has been booked by previous customer, the hotel manager who accepted the customer booking request, can cancel the booking request immediately.  

First, we declare two private attributes for the class which are cust[100] and top. For cust[100], it means the hotel can maximum store 100 customer data and the hotel has only 100 rooms. For the top attribute, it is declared to know current customer data the hotel has.

#### Stack()
1. It act as a constructor for the class Stack
2. When we declare a class Stack in the main body, we initialize the top equal to -1 because we haven’t inserted any customer data inside the class. As the array is counted start from 0, if we insert one data, top will become 0 and the data can be stored in the array


#### bool isEmpty()
1. The function is used to detect whether there is customer data inside the class or not
2. We detect the emptiness of the class by returning ( top == -1 ) 
3. If top equal to -1, the function will return true
4. The function will return false if the top is a positive number or 0 


#### bool isFull()
1. The function is used to detect whether the customer data inside the class is full or not
2. We detect the fullness of the class by  returning ( top == 99 ), the reason of top == 99 instead of top == 100 is because the array starts from 0
3. If top equal to 99, the function will return true
4. The function will return false if the top is not equal to 99

#### void processBookingRequest(Queue& queue)
1. The function acts as push() which means enter data into the class
2. The parameter (Queue& queue) is used as we want to obtain customer data from class Queue. “&” is used to update the data change for class Queue
3. We detect the fullness of class using the isFull() function, if it is full, we cannot insert any data and the system will display “The hotel booking request is full”
4. If the system is not full, the value of top will increase by one for purpose storing the customer data into the array at assigned position
5. The customer data is being inserted inside the array of stack via mutator in class Customer
6. The queue.DoneBooking() function is called to delete the inserted data from class Queue. It modify the real situation of the accepted booking request will be delete from the reservation list

#### void cancelBookingRequest()
1. The function acts as pop() which means pop out the data from stack
2. The isEmpty() is used to detect the emptiness of class
3. If the class is empty, the system will display “No booking request in the queue” and do nothing
4. If the class has customer data, the function will pop out the last data in the stack

#### void findCustAcceptList()
1. The function is used to search the customer data obtained in the class by specific keyword
2. The concept of this function is same as void findCustReserveList() in class Queue just the pointer style has change to array style

#### void displayRequestList()
1. The function is used to display all the customer data in the class Stack
2. The concept of this function is same as void displayReservationList() in class Queue just the pointer style has change to array style


## Source Code Demonstration about Data Structure Concept Employed and User Guide
### Please refer the report for this part
[Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/The%20Trio/Project/DSA%20Project%20Report.pdf)
