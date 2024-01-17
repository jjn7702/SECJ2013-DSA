[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Airline Reservation System - Project
## Objective



## Description 📝
<p align="center">
  <img src="https://i.ibb.co/Krb7W8J/aeroplane.gif" alt="aeroplane" width="400" height="300" />
</p>

An extensive application software called the Airline Reservation System was created to automate and simplify the process of handling airline reservations. This project, which was created with the C++ programming language, uses important ideas like sorting, searching, and queue to improve productivity and structure.

**Component of the features in the Airline Reservation System** 

In an Airline Reservation System, various features and components work together to facilitate booking, management, and user interactions. Here are some key components and features of such a system:

1. **User Authentication:**
   - **Description:** Allows users to log in with valid credentials.
   - **Functionality:** Validates user identity and grants appropriate access (admin or customer).

2. **Customer Booking:**
   - **Description:** Enables customers to reserve flights.
   - **Functionality:** Collects customer details, such as name, date, destination, airline, and IC number. Adds the booking to the reservation queue.

3. **Admin Approval:**
   - **Description:** Allows administrators to approve reservation requests.
   - **Functionality:** Displays reservation details, prompts admin for approval, and processes approved reservations by moving them to the list of completed bookings.

4. **Cancellation of Reservations:**
   - **Description:** Permits customers to cancel their recent reservations.
   - **Functionality:** Removes the most recent reservation from the queue upon customer request.

5. **Search and Display Bookings:**
   - **Description:** Enables administrators to search for and display booking details.
   - **Functionality:** Admins can search for bookings by customer IC number and view the details of matching bookings.

6. **Booking Removal:**
   - **Description:** Allows administrators to remove a booking by IC number.
   - **Functionality:** Deletes a booking from the completed bookings list based on the provided IC number.

7. **Data Extraction from File:**
   - **Description:** Reads existing booking data from a file during system initialization.
   - **Functionality:** Parses the contents of a file (e.g., "booking.txt") to extract previous bookings, populating the completed bookings list.

8. **Display All Bookings:**
   - **Description:** Shows a list of all completed bookings.
   - **Functionality:** Displays the details of all bookings stored in the completed bookings list.

9. **User Interface (Menus):**
   - **Description:** Provides a user-friendly interface for customers and administrators.
   - **Functionality:** Displays menus with options for different functionalities, guiding users through the reservation and management processes.

10. **Queue Management:**
    - **Description:** Manages the queues for reservation requests and completed bookings.
    - **Functionality:** Enqueues new reservations and dequeues approved reservations or canceled requests.

11. **Error Handling:**
    - **Description:** Manages errors and provides feedback to users.
    - **Functionality:** Alerts users in case of invalid inputs, unsuccessful operations, or exceptional conditions.

12. **Program Termination:**
    - **Description:** Handles the termination of the program.
    - **Functionality:** Exits the program gracefully, ensuring that all resources are appropriately released.

These features collectively contribute to the overall functionality and usability of the Airline Reservation System. The system aims to streamline the booking process for customers while providing administrators with tools to manage and monitor reservations.





## Flow of Event 💹
Here's the flow of events in a simplified manner for the pseudocode:

1. **Customer Reserves Booking:**
   - User selects the option to reserve a booking.
   - Enters customer details (name, date, destination, airline, IC number).
   - Creates a new Customer object with the input details.
   - Enqueues the new customer in the reservationRequests queue.
   - Prints a message indicating that the reservation request has been sent.

2. **Customer Cancels Reservation:**
   - User selects the option to cancel a reservation.
   - Enters the IC number of the reservation to be canceled.
   - Dequeues the most recent reservation from reservationRequests if it exists.
   - Prints a message indicating whether the cancellation was successful or if there were no reservation requests to cancel.

3. **Admin Approves Reservations:**
   - Admin selects the option to approve reservations.
   - Displays the details of all reservation requests.
   - Prompts the admin to approve all reservations (1 for Yes, 0 for No).
   - If approved:
      - Dequeues each reservation from reservationRequests.
      - Enqueues each reservation in the doneBooking queue.
      - Prints a message indicating that all reservations have been approved.
   - If not approved, prints a message indicating that reservations were not approved.

4. **Admin Searches for Booking by IC Number:**
   - Admin selects the option to search for a booking by IC number.
   - Inputs the IC number to search for.
   - Iterates through the doneBooking queue to find a matching IC number.
   - Displays booking details if found; otherwise, prints a message indicating no bookings were found.

5. **Admin Removes Booking by IC Number:**
   - Admin selects the option to remove a booking by IC number.
   - Inputs the IC number to be removed.
   - Finds and removes the booking with the specified IC number from the doneBooking queue.
   - Prints a message indicating whether the removal was successful or if the booking was not found.

6. **Admin Displays All Bookings:**
   - Admin selects the option to display all bookings.
   - Displays the details of all bookings in the doneBooking queue.

7. **Extract Data from File:**
   - Reads data from the "booking.txt" file.
   - Parses each line to extract customer details.
   - Creates a new Customer object for each set of details.
   - Enqueues each customer in the doneBooking queue.

8. **Customer and Admin Menus:**
   - The program runs a loop for the main menu.
   - Users (admin or customer) select their type (1 for admin, 2 for customer, 3 to exit).
   - Based on the selection, either the adminMenu or customerMenu function is called.
   - The respective menu functions handle user interactions until the user chooses to exit (option 3).

9. **Program Termination:**
   - The main loop ends when the user selects the exit option (3) from the main menu.
   - The program displays an exit message and pauses before returning 0.


## Design 🎨
**PSEUDOCODE**
Here's a pseudocode for the main part of our program in project:

```plaintext
class Customer
    attributes: name, destination, airline, day, month, year, IC

class BookingQueue
    class Node
        attributes: data (Customer), next (Node)

    attributes: front (Node), rear (Node)

    method enqueue(data)
        create Node with data
        if isEmpty()
            front = rear = newNode
        else
            rear.next = newNode
            rear = newNode

    method dequeue()
        if not isEmpty()
            temp = front
            front = front.next
            delete temp

    method isEmpty()
        return front == null

    method getFront()
        if not isEmpty()
            return front.data
        else
            throw out_of_range("Queue is empty")

class BookingSystem
    attributes: doneBooking (BookingQueue), reservationRequests (BookingQueue)

    method addBooking(booking)
        doneBooking.enqueue(booking)

    method reserveBooking(booking)
        reservationRequests.enqueue(booking)

    method cancelRecentReservation()
        if not reservationRequests.isEmpty()
            reservationRequests.dequeue()
            print "Most recent reservation canceled."
            return true
        else
            print "No reservation requests to cancel."
            return false

    method approveReservation()
        if not reservationRequests.isEmpty()
            process all reservations
            print "All reservations approved."
        else
            print "No reservation requests to approve."

    method searchByICNumber(icNumber)
        for each booking in doneBooking
            if booking.getIcNum() == icNumber
                display booking details
                return true
        print "No bookings found for IC Number " + icNumber
        return false

    method removeBookingByIC(icNumber)
        find and remove booking by IC number
        print "Booking for IC Number " + icNumber + " removed."

    method displayAllBookings()
        display all bookings

    method displayRequestedBookings()
        display reservation requests

function extractData(bookingSystem)
    open "booking.txt"
    if file not found
        print "Cannot open file."
        return
    else
        read lines from file
        extract and add data to bookingSystem

function customerMenu(bookingSystem)
    do
        display menu
        read user choice
        switch user choice
            case 1:
                input customer details
                create Customer
                bookingSystem.reserveBooking(newCustomer)
                print "Reservation request sent."
            case 2:
                input IC number
                bookingSystem.cancelRecentReservation()
            case 3:
                print "Returning to main menu."
    while user choice is not 3

function adminMenu(bookingSystem)
    do
        display menu
        read user choice
        switch user choice
            case 1:
                bookingSystem.approveReservation()
            case 2:
                bookingSystem.displayAllBookings()
            case 3:
                print "Returning to main menu."
            case 4:
                input IC number
                bookingSystem.searchByICNumber(IC number)
            case 5:
                input IC number
                bookingSystem.removeBookingByIC(IC number)
    while user choice is not 3

function main()
    create BookingSystem
    call extractData(bookingSystem)

    do
        display main menu
        read user type choice
        switch user type choice
            case 1:
                call adminMenu(bookingSystem)
            case 2:
                call customerMenu(bookingSystem)
    while user type choice is not 3

    pause and return 0

```

This pseudocode outlines the structure of our program, including class definitions and the main logic for handling user input. We use this as a guide to implement the actual C++ code.


## Prepared by 🧑‍💻

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
| CHE MARHUMI BIN CHE AB RAHIM   | A22EC0147|<a href="https://imgbb.com/"><img src="https://i.ibb.co/hg1vSKm/chemi.jpg" alt="chemi" border="0" width="80" height="80"></a>      |
| MUHAMMAD ARIFF DANISH BIN HASHNAN       | A22EC0204      | <a href="https://ibb.co/CJ4Z8yv"><img src="https://i.ibb.co/gvQp98w/GAMBAR-PASSPORT.jpg" alt="GAMBAR-PASSPORT" width="80" height="80" border="0"></a>  |
| MUHAMMAD IMAN FIRDAUS BIN BAHARUDDIN       | A22EC0216       |<a href="https://imgbb.com/"><img src="https://i.ibb.co/yYcSd4R/imantekk.jpg" alt="imantekk" border="0" width="80" height="80"></a>       |


## Findings 📊

- [Source Code](./Source-code/Project.cpp)
- [Input File]
- [Report]

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)


