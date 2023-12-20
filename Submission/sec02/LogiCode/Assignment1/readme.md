# Assignment 1

### Table of Contents
- [Objectives](#-objectives)
- [Synopsis](#-synopsis)
- [Class Diagram](#-class-diagram)
- [Flowchart](#-flowchart)
- [Description of how to implement data structure operations: Sorting and Searching](#-description-of-how-to-implement-data-structure-operations-sorting-and-searching)

<br>


### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/bc7e2df3-d20d-457c-b9fb-e0574b6a740e" width="3%" height="3%"> Objectives:
<li>To simulate an actual Hotel Booking System in a way that administrators can use it to manage the room bookings in a hotel.</li>
<li>To improve understanding and enhance application of data structures: sorting and searching in a real-world scenario.</li>
<li>To utilize file mechanisms in C++ to read and write data from/ to external files as a simulation of the database of the system.</li>

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/ac62ef65-848d-41a6-97c2-1ff40be8ecd3" width="3%" height="3%"> Synopsis
The Hotel Booking System is designed for hotel administrators to manage bookings. By using file input operations, the system reads the files containing admin information and booking information. Admin’s ID, name, position and phone number are stored in Admin class while check-in date, check-out date, room number, room type and total price of booking are stored in Booking class. Then requiring admin ID from the user to achieve authentication. The verification is carried out through sequential searching of ID input in Admin class. With the menu provided, admin is able to sort bookings ascendingly or descendingly based on check-in date, check-out date, room type and total price with  merge sort techniques implemented.

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/b7b1299f-ead1-4e66-ad2e-95b901f4f03c" width="3%" height="3%"> Class Diagram
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128159572/c058aa3c-edbb-4ac7-abcf-e4e15ad63970" width="80%"><br>
Figure 1: Class Diagram of Hotel Booking System
</p>

### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8b3596b0-7214-4cc8-b868-9ab2a0314386" width="3%" height="3%"> Flowchart
<p align="center">
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/3751215f-0055-451b-abe3-d813a1558362" width="70%" height="70%"><br>
  Figure 2: Flowchart of Main Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/6c372a7e-16b3-4fdb-8f70-0e95c9455134" width="30%" height="30%"><br>
  Figure 3: Flowchart of SequenceSearch Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/3b7da027-72df-49f0-9a8a-ed5e9260202a" width="30%" height="30%"><br>
  Figure 4: Flowchart of adminMenu Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/0c1a3187-00d0-4620-a4ea-f61ce19b9dc5" width="70%" height="70%"><br>
  Figure 5: Flowchart of bookingMenu Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128119778/e0b8b0e0-3925-42fe-95fd-f5bad720ddbc" width="40%" height="40%"><br>
  Figure 6: Flowchart of readBookingData Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/8fad63ef-2fe0-42cc-afce-d9790634dae2" width="30%" height="30%"><br>
  Figure 7: Flowchart of mergeSort Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/1774b9d3-3284-4cbe-8687-4a11133ec081" width="70%" height="70%"><br>
  Figure 8: Flowchart of merge Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/a13ec04c-8d31-4108-90b0-5e898a19f602" width="40%" height="40%"><br>
  Figure 9: Flowchart of dispItems Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/aee4657a-2aa4-4d8e-a3f8-1b593cbe464e" width="30%" height="30%"><br>
  Figure 10: Flowchart of mergeSortDsc Function
  <br><br><br>
  <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/b3db9b85-0a5b-49d7-a162-efa99e4db789" width="70%" height="70%"><br>
  Figure 11: Flowchart of mergeDsc Function
  <br><br><br>
</p>




### <img src="https://github.com/jjn7702/SECJ2013-DSA/assets/128120717/fabaacbe-18c1-4f64-a3a5-e1b40e910e71" width="4%" height="4%"> Description of how to implement data structure operations: Sorting and Searching
##### 1. Sorting

In the Hotel Booking System, we have implemented Advanced Sort - Merge Sort which uses the Divide and Conquer Sorting Strategy in the mergeSort(), mergeSortDsc(), merge() and mergeDsc() functions. This data structure operation works by dividing an array received in the parameter into halves, sort each half and merge the sorted halves into one sorted array. 

As an example, in our system, the mergeSort() function is used to divide the array received in parameter into halves by the second and third arguments indicating first and last index numbers of the array. This function is recursively called to divide the array received in the parameter list into small pieces until each of them has one item only. Then, by calling the merge() function, the small pieces are merged into larger yet sorted pieces repeatedly until the array is sorted. For the merge() function, it compares one item in the first half of the array with another item in the other half and moves the item with smaller value into a temporary array declared in the function and also the items remaining are moved to the temporary array. At the end of the function, the temporary array is copied into the original array. We also implement the mergeDsc() functions to sort the array in an descending order by modifying the algorithm, for instance, in merge() function, the condition r[first1] < r[first2] is changed to r[first1] >= r[first2] when implementing mergeDsc() function. These functions are used to sort the Room Type, Room Price (Low to High), Room Price (High to Low), Latest Check-In Date and Earliest Check-In Date of the customers. Function template technique in C++ is also implemented when declaring the sorting functions in order to be flexible to work with different data types.

We have chosen the sorting algorithm - Merge Sort out of five sorting algorithms we have learned after the consideration of the growth rates of time required by the Merge Sort has the Big O Notation of O(n log n) which is faster compared to O(n²).

<br>

##### 2. Searching

In the Hotel Booking System, we have implemented Searching Technique - Sequential search in SequenceSearch() function. This data structure operation works by examining each element in the array sequentially and compares its value with the search key. 

As an example, in our system, the SequenceSearch() will receive a search key which is the adminID entered by the admin, an array to be searched which is the admin information read from the admin file (database) and the size of the array in its parameter list as arguments. The variable index is set to -1 initially to indicate the record is not found. When comparing the adminID with the array which is accessing getadminID() function, if the adminID matches with any adminID from the database, the index is assigned the current array index and eventually returns the index. After returning to the main function, the result of SequenceSearch() is checked as if the value is equal to -1 (not found) or ! = -1 (found). This function acts as a verification and authentication for the admin identity.

We have chosen the Searching Technique - Sequential search as it is a basic function that is suitable to be implemented in a small size of list in which after considering the number of administrators in a hotel will not be a large population.

