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
- [Presentation Slide]


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
