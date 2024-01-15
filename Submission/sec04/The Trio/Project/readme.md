# Hotel Booking System - Project
## Prepared By The Trio
| Name         | Matric No    |
|--------------|--------------|
| Nur Hafizah Binti Jafri     | A22EC5022 |
| Nursyuhada Binti Badren     | A22EC0253 |
| Eddy Koh Wei Hen            | A22EC0154 |

## Findings 📊

- [Source Code]
- [Plagiarism Report]
- [Report]
- [UML Diagram and Flow Chart](https://app.diagrams.net/#G1qRs-q7iZpkrkau2ri2tI_dkmzvK0DKnU)

  
## Objective
Our objectives for this project are:

a. To help the agent store customer information in the hotel booking reservation list using the queue data structure concept

b. To help the hotel manager manage the customers’ booking requests in the accepted booking request list using the stack data structure concept

c. Keep a record of booking details, such as customers’ name, age, IC number, phone number, room number and check-in date

d. To allow changeable functions such as push and pop function in stack data structure concept as well as enQueue and deQueue function in queue data structure concept


## Synopsis📝
Our hotel reservation system uses two key structures, which are queue and stack. The queue, which is used by the hotel’s staff, uses a pointer in a class called Queue. This design allows the queue to accommodate an unlimited number of customers, just like a real hotel can. The queue operates on a first-come, first-served basis, meaning the first booking request received is the first one to be processed. Besides, the stack is used by the hotel manager and is using  an array in a class called Stack. This design reflects the reality that a hotel has a limited number of rooms. The stack operates on a last-in, first-out basis, meaning if there’s an issue with a room, the most recent booking can be canceled first. Lastly, our hotel reservation system uses a queue to handle customer requests and a stack to manage room availability. This setup ensures a fair process for customers and efficient management for the hotel.

## Design
### Class Diagram
[Class Diagram]

### Flowchart
[Flowchart]

## Design Description
### Main function
1. **Variable Declaration**: Declaring a set of variables (`name`, `IC`, `phoneNum`, `date`, `age`, `room`) that are used to store the customer data read from the file.

2. **Open File**: Open the file "Project.txt". If the file cannot be opened, an error message is displayed and the function returns 1, showing an error occurred.

3. **Reading Data**: If the file is successfully opened, the function enters a while loop where it reads each line of the file. For each line, it reads the customer's name, age, IC, phone number, room number, and date.

4. **Object Creation**: After reading the data, the function creates a `customer` object and sets its properties using the data read from the file. The `setName`, `setAge`, `setIC`, `setPhone`, `setNum`, and `setDate` functions are used to set the properties of the `customer` object.

5. **Data Storage**: The `customer` object is then stored in an array of `customer` objects. The `custNum` variable is used as the index for the array and increases after each `customer` object is stored.

6. **Close File**: After all the data has been read and stored, close the file.
