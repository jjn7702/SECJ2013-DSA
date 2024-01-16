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

## Synopsis <a name="synopsis"></a> ✨
  The courier management system is used to send the parcel to the specific destination and track the current location. We designed the courier system by implementing the Queue method to easily allow the user to insert, delete,change status, search and display the information of the parcel. When the customers submit the parcel details in the system, the details will be stored in the input file (COURIER.TXT). Using a Queue is suitable for a courier management system as it follows the “First In, First Out” (FIFO) principle. The first parcel detail submitted and stored is the first to be processed by the admin and worker.

  In our system, the user can insert the new details about the parcel that contains, name, the tracking number, type of parcel, source, destination, and the status of the parcel. The information will be inserted after the last information of the parcel. In addition, the user also can remove the details of the parcel from the input file and the details will be deleted from the top of the input file. Furthermore, we also implement the search feature for the user to search the details of the parcel by using the status of the parcel. Then, the system will display all the details of the parcel that have status as the user entered into the system. Last but not least, the system also has a display menu to display all and updated details of the parcel from the input file.


## Problem Analysis <a name="problemanalysis"></a> 🕵🏻‍♀️🕵🏻‍♂️
  The courier management system is designed to facilitate and improve the courier services management by handling all the information that they receive from customers and synchronizing it with the updated delivery status for their parcel. To make all the process become a lot more easier than before, we have decided to use a Queue data structure that will follow the principle of 
“First In,First Out” (FIFO). As a result the first data to enter the system (enqueue) will also be the first data deleted (dequeue) from the system. 

  Other than that, to help the customer at the courier service center to find all the data for which parcel’s status has been delivered or not, we have decided to implement a searching process. Our system has the ability to search information about couriers by inserting the tracking number of the parcel. All the parcel details that contain the similar tracking number like the one that we searched will be displayed. Meanwhile, the admin of the system can approve the new data either the data was inserted by input file (COURIER.TXT) or customer. Admin also have the ability to delete the first data inserted to the system each time the dequeue function is being called.

  In addition, our system also offers the workers of the courier service to update the status from being “Approved” to “In Transit”. From this update, customers can know that their parcels are currently being processed. The workers also have the same ability like admin which is to delete the first data inserted to the system each time the dequeue function is being called. Last but not least, our system also can save the updated data into the file after we exit the system. As a conclusion, the courier management system is a very useful system that could help all courier services management to improve their functionality and its user experience.



## Design <a name="design"></a> 🎨
#### Flowchart
![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/Images/databaseprojek.drawio.png)
#### Class Diagram
![2](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/Images/class%20diagram.jpg)

## Design Description <a name="designdescription"></a> 💹

## User Manual/Guide <a name="usermanual"></a> 📝

## Similarity Report <a name="report"></a> 🔔



## Findings <a name="findings"></a>📊

- [Source Code](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/source-code/project.cpp)
- [Input File](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Project/files/source-code/COURIER.TXT)
- [Project Report]()
- [Similarity Report]()


