[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

# Courier Management System - Project

## Appendix :red_circle:

- [Overview of The Project](#overview)
- [Objective](#objective)
- [Synopsis](#synopsis)
- [Problem Analysis](#problemanalysis)
- [Design](#design)
- [Design Description](#designdescription)
- [User Manual/Guide](#usermanual)
- [Similarity report](#report)
- [Findings](#findings)

## Overview of The Project <a name="overview"></a> :heavy_check_mark:
## Objective <a name="objective"></a> 🧠
  The main objective for developing the courier management system is to ease the courier and customer to insert, delete, search and display the courier information. The courier management system is designed to make the process of insertion and deletion of the courier information run smoothly and follow the flow as it follows the “First In, First Out” (FIFO) principle and get packages to their destination safely and on time. The system provides a user-friendly interface for simplicity of use, with a menu-driven system that leads users through the full process of selecting the menu provided until they choose to exit the system. The system implements the queue principle as that principle is more suitable to be implemented for the courier management system. Typically, the initial detail of a parcel will be delivered to the customer first since the parcel was sent earlier than subsequent parcels, allowing the administrator to remove the information flow by flow. Usually, the first detail will be delivered first to the customer as the parcel was sent earlier than other parcels so that the admin can delete the information flow by flow. To maintain data integrity during file activity, the system also additionally employs a data hiding concept. Data hiding ensures exclusive data access to class members exclusively and preserves object integrity by limiting modifications and disruptions, whether planned or unintended.

There are few features in the courier management system which is

1. Insert data courier

   Insert information of the parcel including name, parcel type, source, destination, status and tracking number. The new information will be inserted at the back/last of the list of parcel details.

2. Remove or delete data couriers

   Remove or delete the information about the parcel. The information will be deleted from the top/front of the list in the Queue.

3. Search courier information

   Can find any data that exists in the list by inserting the tracking number for the parcel. The algorithm used is a linked list implementation of queue.

4. Display data courier
  
   Displaying all updated courier information including name, parcel type, source, destination, status and tracking number.

5. Update data courier

   Update the status attributes in couriers from "Pending" to "Approve" and from "Approve" to "In transit".

## Synopsis <a name="synopsis"></a> ✨
  The courier management system is used to send the parcel to the specific destination and track the current location. We designed the courier system by implementing the Queue method to easily allow the user to insert, delete,change status, search and display the information of the parcel. When the customers submit the parcel details in the system, the details will be stored in the input file (COURIER.TXT). Using a Queue is suitable for a courier management system as it follows the “First In, First Out” (FIFO) principle. The first parcel detail submitted and stored is the first to be processed by the admin and worker.

  In our system, the customer has a menu to choose whether they want to add details of parcel, view the courier queue, and search courier by tracking number and exit the customer menu. The customer can insert the new details about the parcel that contains, name, type of parcel, source, destination, and the status of the parcel, and tracking number. The information will be inserted as the last/back position of information of the parcel by following the Queue principle (enqueue). The status of new detail that is inserted by the customer will be “Pending” and will be changed to the “Approved” by the Admin after the admin approves the pending couriers. Next, the Worker will update the parcel from “Approved” status to “In Transit” status. In addition, the admin also has a menu to choose whether they want to view the courier queue, approve courier, dequeue the courier (remove data) and exit from admin’s menu.  While, the worker has a menu to choose whether they want to view the courier queue, mark courier as In transit, dequeue the courier (remove data) and exit from worker’s menu.The admin and worker can remove or delete the details of the parcel from the input file and the details will be deleted from the top/first parcel’s information of the input file by regarding the Queue principle (dequeue). Furthermore, we also implement the search feature for the customers to search the details of the parcel by entering the tracking number. Then, the system will display all the details of the parcel that have the same tracking number as the user entered into the system. Last but not least, the system also has a display/view menu for customers, admins and workers to display all and updated details of the parcel from the input file(COURIER.txt).


## Problem Analysis <a name="problemanalysis"></a> 🕵🏻‍♀️🕵🏻‍♂️
  The courier management system is designed to facilitate and improve the courier services management by handling all the information that they receive from customers and synchronizing it with the updated delivery status for their parcel. To make all the process become a lot more easier than before, we have decided to use a Queue data structure that will follow the principle of 
“First In,First Out” (FIFO). As a result the first data to enter the system (enqueue) will also be the first data deleted (dequeue) from the system. 

  Other than that, to help the customer at the courier service center to find all the data for which parcel’s status has been delivered or not, we have decided to implement a searching process. Our system has the ability to search information about couriers by inserting the tracking number of the parcel. All the parcel details that contain the similar tracking number like the one that we searched will be displayed. Meanwhile, the admin of the system can approve the new data either the data was inserted by input file (COURIER.TXT) or customer. Admin also have the ability to delete the first data inserted to the system each time the dequeue function is being called.

  In addition, our system also offers the workers of the courier service to update the status from being “Approved” to “In Transit”. From this update, customers can know that their parcels are currently being processed. The workers also have the same ability like admin which is to delete the first data inserted to the system each time the dequeue function is being called. Last but not least, our system also can save the updated data into the file after we exit the system. As a conclusion, the courier management system is a very useful system that could help all courier services management to improve their functionality and its user experience.



## Design <a name="design"></a> 🎨
#### Flowchart
![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/Images/dsaflowchart.png)
#### Class Diagram
![2](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/Images/class%20diagram.jpg)

## Design Description <a name="designdescription"></a> 💹

### ADDING A NEW COURIER

1. Get the option from the customer menu.
   
2. The customer menu provides an option for customers to add a new courier into the queue at the rear.
   
   2.1 The enqueue function in the Courier Service Systems allows customers to add new              couriers to the system.
   
   2.1.1 Calls the ‘enqueue’ function in the ‘Queue’ class to add a new courier into the              system.
   
   2.1.2 User inputs courier details such as name, parcel type, source, destination,                  tracking number.
   
   2.1.3 The status will be automatically set to “Pending’ by default.
   
   2.1.4 The courier is added to the rear of the courier que (follow queue rule).
   
   2.1.5 Return back to the customer menu.

### UPDATING AND REMOVING FROM QUEUE

1. Get the option from the admin and worker menu.
   
2. From the admin menu, the courier status can be updated from “Pending” to “Approved”.
   
   2.1 Iterates through the courier queue to find the first courier with status “Pending”.
   
   2.1.1 If found, change the status from “Pending” to “Approved”.
   
   2.1.2 Notifies the approval to the admin.
   
   2.2 If no status “Pending” is found
   
      2.2.1 Notify the admin that there are no more pending status to approve.
   
3. From the worker menu, the courier status can be updated from “Approved” to “In Transit”.
   
   3.1 Iterates through the courier queue to find the first courier with status “Approved”.

      3.1.1 If found, change the status from “Approved” to “In transit”.

      3.1.2 Notifies the change to the worker.

    3.2 If no status “Approve” in found

      3.2.1 Notify the worker that there are no more approved status to be changed to in transit.
   
4. From the admin menu, the courier queue can be deleted (dequeue)
   
    4.1 The courier at the front is removed from the courier queue.
   
5. From the worker menu, the courier queue can be deleted (dequeue)
   
    5.1 The courier at the front is removed from the courier queue.
   
6. Return back to the admin/worker menu.

### SEARCHING THE COURIER

1. Get the option from the customer menu.
   
2. From the option, courier information will be searched by tracking the  tracking number entered from the customer.
   
   2.1 Iterates through the queue, comparing the attributes of each courier to the corresponding search key.
   
   2.1 If the courier found

      2.1.1 Display the courier information with the search key.
   
   2.2 If the courier not found
   
      2.2.1 Notifies the customer that there is no information for the courier with the corresponding search key.
   
3. Return back to the customer menu.

### DISPLAYING THE COURIER 

1. Get the option form the customer, admin and worker menu.
   
2. Display the content in the courier queue starting from front to rear.
   
3. Return back to the customer/admin/worker menu.

### SAVE COURIER INFORMATION 

1. Get the option in the main menu.
   
2. Save the latest courier queue to the filename “COURIER.TXT”.
   
3. Return back to the main menu.


## User Manual/Guide <a name="usermanual"></a> 📝
![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/Images/Screenshot%202024-01-16%20220555.png)
![2](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/Images/Screenshot%202024-01-16%20210820.png)
![3](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/Images/Screenshot%202024-01-16%20220520.png)
![4](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/Images/Screenshot%202024-01-16%20220533.png)

## Similarity Report <a name="report"></a> 🔔
Submission date: 16-Jan-2024 05:18AM (UTC-0800)

Submission ID: 2271861129

File name: PROJECT_DSA.pdf (427.53K)

Word count: 2121

Character count: 10197

![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/Images/similarity.png)

## Findings <a name="findings"></a>📊

- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/source-code/project.cpp)
- [Input File](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/source-code/COURIER.TXT)
- [Project Report]()
- [Similarity Report]()


