# Hotel Booking System - Assignment 2
## Prepared By The Trio
| Name         | Matric No    |
|--------------|--------------|
| Nur Hafizah Binti Jafri     | A22EC5022 |
| Nursyuhada Binti Badren     | A22EC0253 |
| Eddy Koh Wei Hen            | A22EC0154 |

## Objective
Our objectives for this assignment are:

a. To store and arrange customer information using a linked list structure.

b. Keep record of booking details, such as customers’ name, age, IC number, phone number, room number and check-in date, with each customer node.

c. To allow changeable functions such as adding, deleting, finding, sorting customers from the list.




## Synopsis📝
This hotel booking system uses a constant change of linked lists, allowing for the easy handling of customer information in a way similar to the changeable movement of customers throughout a hotel. For example, when customers move  into their rooms, it easily inserts new customers by entering their data at any location they want within the list. When customers check out, their data is easily removed from the list, creating an easy checkout procedure. This ability to change, which is similar to the constant change of hotel operations, provides an easy and effective experience for both staff and customers.



## Design Description
Main function
  1. Declare array ‘customer’ of 100 ‘Customer’
  2. Read customer information from an input file.
  3. Switch case: Case 1: Add Customer

     3.1 Select to add customer at the front of the list

       3.1.1 call function addCustAtBegin()

     3.2 Select to add customer in the middle of any position of the list

       3.2.1 call function addCustAtMid()

     3.3 Select to add customer at end of the list

       3.3.1 call function addCustAtEnd()
  4. Switch case: Case 2 : Delete Customer
     4.1 Select to delete first customer from the list

       4.1.1 call function deleteFront()

     4.2 Select to delete customer in the middle of any position of the
          list

       4.2.1 call function deleteMid()

     4.3 Select to delete last customer from the list

       4.3.1 call function deleteEnd()
  6. Switch case: Case 3 : Find Customer

     5.1 call function findCustomer() to search for customers based on
          specified criteria
  7. Switch case: Case 4 : Sort Customer

     6.1 call function sorting() to sort customer list based on names
          using bubble sort algorithm
  8. Switch case: Case 5 : Display Customer

     7.1 Call the function displayList() to display the entire list of
          customers.
  9. Case Default : Quit

     8.1 Display “Bye” and quit the program/system.
  10. The program will infinite loop until user key in quit option


# Add Function
AddCustAtBegin()
  1. Check if the linked list is empty
  2. If the linked list is empty, make the new customer at the head of the list.
  3. If the linked list is not empty, point the new customer to the current head.
  4. Make the new customer the new head of the list.

AddCustAtMid()
  1. Check if the position is valid or not
  2. Move the linked list to find the node at specified position.
      2.1 If the position is the last one

       2.1.1 Reject the new customer
      2.2 If the position is the first one

       2.2.1 Reject the new customer
  3. Add the new customer to the middle of the list by setting its next pointer to the node at
     specified position and setting the next pointer of the previous node to the new customer.

AddCustAtEnd()
  1. Check if the linked list is empty.
  2. If the list is empty,
      2.1 Make the new customer the head of the list.
  3. If the list is not empty,
      3.1 Move the linked list to find the last node.
  4. Add the new customer to the end of the list by setting the next pointer of the last node to
     the new customer.

# Delete Function
deleteFront()
  1. Check if the linked list is empty.
  2. If the list is empty
      2.1 Inform user the list is empty and return
  3. If the linked is not empty,
      3.1 Delete the first node of the list by setting the head of the list to the next node,
          and delete the original head node.

deleteMid()
  1. Check if the linked list is empty.
  2. Reject if position is not valid.
  3. If the list is empty
      3.1 Inform user the list is empty and return
  4. Move the node in the linked list to the specified position.
  5. Reject if position is the last one.
  6. Reject if the position is the first one.
  7. Delete the node at specified position by setting the next pointer of the previous node to
     the node after the node to be deleted and then deleting the node.

deleteEnd()
  1. Check if the linked list is empty.
  2. If the linked list is empty,
      2.1 Inform user the list is empty and return
  3. If the linked is not empty,
      3.1 Move to the last node of the linked list.
      3.2 Delete the last node of the linked list.

# Find Function
findCustomer()
  1. Check if the linked list is empty.
  2. If the linked list is empty,
      2.1 Inform user the list is empty and unable to search, then return
  3. Display search options
  4. Initializing variables
      4.1 Set current pointer to the head of the list
      4.2 Set prev pointer to NULL
      4.3 Set found flag to false
  5. Enter switch statement after user select the search option
      5.1 Search by name
          5.1.1 Enter name to search
          5.1.2 If current node’s name matches search name
              5.1.2.1 Set found to true to break the loop after current loop
          5.1.3 Move prev to current
          5.1.4 Move current to next node
      5.2 Search by Age
          5.2.1 Enter age to search
          5.2.2 If current node’s age matches search name
              5.2.2.1 Set found to true to break the loop after current loop
          5.2.3 Move prev to current
          5.2.4 Move current to next node
      5.3 Search by IC Number
          5.3.1 Enter IC number to search
          5.3.2 If current node’s IC number matches search name
              5.3.2.1 Set found to true to break the loop after current loop
          5.3.3 Move prev to current
          5.3.4 Move current to next node
      5.4 Search by Phone Number
          5.4.1 Enter phone number to search
          5.4.2 If current node’s phone number matches search name
              5.4.2.1 Set found to true to break the loop after current loop
          5.4.3 Move prev to current
          5.4.4 Move current to next node
      5.5 Search by Room Number
          5.5.1 Enter room number to search
          5.5.2 If current node’s room number matches search name
              5.5.2.1 Set found to true to break the loop after current loop
          5.5.3 Move prev to current
          5.5.4 Move current to next node
      5.6 Search by Check In Date
          5.6.1 Enter check in date to search
          5.6.2 If current node’s check in date matches search name
              5.6.2.1 Set found to true to break the loop after current loop
          5.6.3 Move prev to current
          5.6.4 Move current to next node
      5.7 Default
          5.7.1 Inform the user the option is invalid and let them choose again
  6. Display results
      6.1 If a match is found
          6.1.1 Print customer information
      6.2 If no match is found
          6.2.1 Inform user not record found

# Sort Function
sorting()
  1. Check if the linked list is empty
  2. If the linked list is empty
      2.1 Inform user the list is empty and unable to sort then return
  3. Initializing variables
      3.1 Declare pointers current, prev and temp
      3.2 Set size = 1
  4. For loop is used to get current list size, set current point to head of the list and add
     condition of looping if current is not NULL, update current point to the next node
      4.1 size increase by 1
  5. Nested loop for bubble sort
      5.1 For outer loop, iterate from 1 to size
          5.1.1 Set current point to head and prev point to NULL in every outer loop
      5.2 For inner loop, iterating j from 0 to size-pass
  6. Inside the inner loop
      6.1 Check if current and current->next is valid and if current->getName() is larger than
          current->next->getName()
          6.1.1 switch the position of current and current->next
  7. Inform the user the data is sorted.

# Display Function
displayList()
  1. Check if the linked list is empty
      1.1 If the customer list is empty
          1.1.1 Inform user the list is empty and need to insert data first then return
  2. Set the current pointer point to the head of the list.
  3. Looping while current pointer is not NULL
      3.1 Print customer information
      3.2 Move current point to the next node in the list

## Findings 📊

- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/tree/main/Submission/sec04/The%20Trio/Assignment%202/Source%20code)
- [Plagiarism Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/The%20Trio/Assignment%202/Assignment%202%20Plagiarism%20Report.pdf)
- [Report](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/The%20Trio/Assignment%202/ASSIGNMENT%202%20(DSA)%20.pdf)
