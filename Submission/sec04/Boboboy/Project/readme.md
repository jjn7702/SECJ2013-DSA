[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Project

## Table Of Contents
- [Objectives](#objectives-)
- [Synopsis](#synopsis-)
- [Linked List in Ordering System](#linked-list-in-ordering-system)
- [Queue in Ordering System](#queue-in-ordering-system)
- [Class Diagram](#class-diagram)
- [Flowchart](#flowchart)
- [Findings](#Findings-)

## Objective
The main objective of BOBOBOY's Restaurant Management System (RMS) is to optimize the order management system with effectiveness features and to minimize the time to get through our ordering system. Our system is created for a full process from ordering to payment session and it can be done via through the system and the customers can get the food in the best condition without wasting any time on waiting or getting used to the system. 
All the features, panel and functions are to make sure the customers have good feedback to our restaurant and satisfy not only about the food, but also the whole system and environment of the BOBOBOY restaurant.

## Synopsis
In a restaurant, it is most important that RMS should be user friendly and show a detailed menu in a simple way. Besides, the customer's emotion is very important as they want to get the food they ordered as fast as possible. In BOBOBOY restaurant, the RMS contained two main functions in the menu which is sorting and searching. The purpose of implementing these two functions is because we want the customers to look through the menu based on their favorite arrangement such as food name with ascending alphabet arrangement. . After that, if they cannot find what specific food they want on the menu, they can type the details or info about that food on the search panel and it will show the position of that product so next time they can straight away order from the menu without wasting time. Besides, inside the order cart, the customer can add on or delete the item straight away inside the cart so there is no need to go back to the menu to do this action. Inside the cart also got a searching and sorting function which helps customers to get through their order fast and easier. All of these are to make our customers like the ordering system of BOBOBOY restaurants and they feel easy and simple when ordering their desired food.

## Problem Analysis
In this project, we will develop a food ordering system in the restaurant. Before implementing the whole system, we need to know the typical ordering system we meet in our daily life and also how it functions from the starting until the food is delivered to customers.
	
	In a typical food ordering system, there should be two main group users, the customers and the admin of the restaurant ordering system. The admin will based on what product had been ordered by the customers and delivered to the kitchen to prepare food ordered. So, for an ordering system, there must be some basic and main functions that need to be performed  no matter how we enhance it.

	First and foremost, for an ordering system, it must be a menu that showed what kind of dishes and drinks we had offered to the customers. We need to make a list of available options inside the restaurant for the customers to pick what they really desire to have. After that, the option they chose inside the menu should be saved inside one place in the system. This feature is important because it can help the customer to check whether they have misclicked about the food they choose. Besides, this place can also show all the details about the option they chose such as the number they have added, total price and food name or code. They can add or delete the items inside so they no need go back to the menu and reorder. After that, they can confirm their order and get a receipt after payment.

	On the other hand, the admin or the kitchen staff would also have several functions that can be used to control the ordering system. Firstly, the order details must be sent to the kitchen staff so they can prepare the food as soon as possible. The kitchen staff should be able to see all the uncompleted orders to make sure that they would not miss out on any customers. The order shown contains the order number and also the order details so kitchen staff can prepare their order in the shortest time. Lastly, after the order is completed and delivered out from the kitchen, the order will be deleted from the list.
	
After understanding the basic functions of the typical ordering system for both users, we can find some problems inside the typical ordering system and we can make some improvements and implementations to make it more efficient and clear to be used for both main users.

	Firstly, for the customers, it should be able to add and delete specific orders inside the cart. In our system, the customers can add their order in the specific places and delete it based on what they wanted. After that, if there are too many orders inside the cart and the customers find it hard to browse through what they had ordered, we provide a searching function inside the system. Customers can search their food based on the name and code we provided inside the cart. The system will show either the food had been ordered or not. 

After that, we also add on some features that help the customers to check their payment needs easily. The system provided customers to choose how the receipt they wanted to be displayed based on code, name or foodtype. These three can be shown in the receipt in ascending or descending order. After ordering, the customer is available to check their order status to make sure that their order is sent to the kitchen and prepared or completed. This is to make sure that the customers can have details about their orders so they no need to wait without any information.

For the kitchen staff, we need to solve the problems about the system such as checking the number or order and display the order list. The system will be able to check all the status of order and display the number of orders in the completed list or still preparing list. The details of food such as code, name and unit number can be seen inside the order so the staff no need to make sure about what is the  product ordered by the customers. After that, to improve the efficiency of kitchen staff, the completed order should be able to be cleared from the list so that the staff will not miss up any order and only need to focus on orders that have not been completed yet. 

After that, for a restaurant, we need to know how many orders are completed in one day. This is easier for the manager of a restaurant to conclude the sales and generate sales reports for everyday.
	These are the basic problems that our group members found out and faced throughout the project. All of these problems are solved in an effective way and we also add on the features to make the ordering system more efficient and multi-functional. This project can be developed successfully as we used the data structure concepts stated above, which are the queue data structure and also linked-list for ht menu display.


## Class Diagram
![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Boboboy/Project/Images/class%20diagram%20project.jpeg)

## Flowchart 

### Main Body
![1](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/Boboboy/Project/Images/mainbody3.drawio%20(1).png)

### Function deleteorder
![2]()

### Function deleteCart
![3]()

### Function Search_item_in_Cart
![4]()

### Function Customer_order
![5]()

### Function Cus_order
![6]()

### Function waytoInsert
![7]()

### Function report
！[8]()

### Function getordernum
![9]()

## Findings 📊

- [Source code]()
- [Inputfile]()
- [Report]()
