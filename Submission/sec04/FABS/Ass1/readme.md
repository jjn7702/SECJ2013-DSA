[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

# Courier Management System - Assignment 1

## Appendix :red_circle:

- [Objectives](#Objectives)
- [Synopsis](#synopsis)
- [Design](#design)
- [Findings](#findings)

## Objectives <a name="objectives"></a> :heavy_check_mark:

The main objective for developing the courier management system is to ease the courier and customer. The courier management system is designed to make sure a delivery services run smoothly and gets packages to their destination safely and on time. This system aims to provide parcel tracking and tracing, customer satisfaction, customer self-service essentially helping and improving courier quality. The system also carry out a user-friendly interface for ease of use with menu-driven system that guides users through the entire process until users choose to exit the program. The system implement data hiding concept to ensure data integrity during file operation. Data hiding guarantees exclusive data access to class members only and protects and maintains object integrity by preventing intended or unintended changes and intrusions.

There are few features in the courier management system which is 

#### 1. View courier available
Displaying all courier information available including name, parcel type, source, destination, status and tracking number.

#### 2. Sort and arrange couriers 
Sort and arrange couriers based on what customer want with three possible options

1. Sort by name
2. sort by parcel type
3. sort by tracking number
   
Note that all three options are in ascending order and the algorithm used is a quick sort algorithm.

#### 3. Search courier information

Can search any data that existed in the list whether name, parcel type, source, destination, status or tracking number. The algorithm used is a simple linear search.

#### 4. Write the arranged and sorted data

The new sorted and arranged data about couriers will be stored into new file name "sorted_couriers.txt".


## Synopsis <a name="synopsis"></a> 📝

This program is designed for organizing courier management systems efficiently, with features such as sorting and searching for specific courier details. The foundation of the program focuses around a Courier class, which encapsulates each courier's information such as name, parcel type, source, destination, status, and tracking number. This program can read and write data to or from files, display information in an organized form and conduct sorting and searching.
During execution, this program will display a menu with options for viewing all couriers, sort them according to certain criteria, search for specific couriers, and exit the program. The class design ensures encapsulation by offering ways for successfully interacting with the courier data.


## Design <a name="design"></a> 🎨

1. Flowchart

![1](https://github.com/jjn7702/SECJ2013-DSA/blob/b61a33a43887545caac58fe75a6d83fb567522e5/Submission/sec04/FABS/Ass1/Images/flowchart.jpg)

## Design Description 💹

### MAIN FUNCTION

Read customer information from an input file (customer.txt).
Then, show the menu for view all data of customers option, sorting (ascending) option, searching option and exit option.

2.1 Option 1: Display all data of customers from input file
2.2 Option 2: Pass the customers data to Sorting function:
2.2.1 Pass the customers' data to the quickSortStr() function and then pass
it to partitionStrByName() function to sort the data by name, and
then pass the sorted data to the display() function to display 
the sorting result.
2.2.2 Pass the customers' data to the quickSortStr() function and then pass
it to partitionStrByType() function to sort the data by name, and
then pass the sorted data to the display() function to display 
the sorting result.
2.2.3 Pass the customers' data to the quickSortInt() function and then pass
it to partitionInt() function to sort the data by name, and
then pass the sorted data to the display() function to display 
the sorting result.
2.3 Option 3: Pass the customers data to Searching function:
2.3.1 Pass the customers' data to the SearchString() function to search data
by name, type of parcel, source, destination, or status delivery. Then
pass the searched data to the display() function to display the
search result.
2.3.2 Pass the customers' data to the SearchInt() function to search data
by tracking numbers. Then pass the searched data to the display()
function to display the searching result.
2.4 Option 4: Exit the system
2.5 Ask users to choose the valid option.
3. End


### SORTING FUNCTION

This program uses two sorting algorithms which are quick sort for sorting by integer (trackingNum) and quick sort for sorting by string (name or parcelType). It also uses a different partition function for each sorting process.
	
1. Get the option from the main function.
2. From the option, the data will be sorted by corresponding function either sort by name, parcel type or tracking number.
   	2.1 The sorting function uses a quick sort technique to rearrange the customer data ascendingly based on the option 	that was chosen by the customer.
	2.2 Option 1: quickSortStr() function: sort data only for String type
			2.2.1 partitionStrByName(): sort data based on the name of the customer
			2.2.2 partitionStrByType(): sort data based on the parcel type of customer
	2.3 Option 2: quickSortInt() function: sort data only for Integer type
			2.3.1 partitionInt(): sort data based on the tracking numbers of the customer


### SEARCHING FUNCTION

This program also implements two search functions which are SearchString() function for searching all the string attributes (name,parcelType,source,destination or status) and SearchInt() function for searching integer attributes (trackingNum).

1. Get the option from the main function.
2. From the option, the data will be searched by corresponding function either search by name, destination, source, parcel type or tracking number.
2.1 The searching function uses a ? search technique to search customers data based on the option that was chosen by the customer.
2.2 Option 1: SearchString() function: search data only for String type (name, source, destination, status, parcel type).
2.3 Option 2: SearchInt() function: search data only for Int type (tracking numbers).

### DISPLAY FUNCTION

Display the unsorted data from the file (customer.txt) that has been read or display sorted data and searched data based on users option.

## Findings <a name="findings"></a>📊

- [Source code](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass1/ASS1.cpp)
- [Input file](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass1/customer.txt)
- [Output file](https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec04/FABS/Ass1/sorted_couriers.txt)

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)

