### Table of Contents
- [Objectives](#1-objectives)
- [Synopsis](#2-synopsis)
- [Class Diagram](#3-class-diagram)
- [Flowchart](#4-flowchart)
- [Description of how to implement data structure operations: Sorting and Searching](#5-description-of-how-to-implement-data-structure-operations-sorting-and-searching)


### 1. Objectives:
<li>To simulate an actual Hotel Booking System in a way that administrators can use it to manage the room bookings in a hotel.</li>
<li>To improve understanding and enhance application of data structures: sorting and searching in a real-world scenario.</li>
<li>To utilize file mechanisms in C++ to read and write data from/ to external files as a simulation of the database of the system.</li>

### 2. Synopsis


### 3. Class Diagram


### 4. Flowchart
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
</p>




### 5. Description of how to implement data structure operations: Sorting and Searching
##### 1. Sorting

In the Hotel Booking System, we have implemented Advanced Sort - Merge Sort which is using the Divide and Conquer Sorting Strategy in the mergeSort(), mergeSortDsc(), merge() and mergeDsc() functions. This data structure operation works by dividing an array into halves, sort each half and merge the sorted halves into one sorted array. 

As an example, in our system, the mergeSort() function is used to divide the array received in parameter into halves by the second and third arguments indicating first and last of the array in terms of index number. This function is recursively called to divide the array received in parameter into pieces until each piece contains only one item. The small pieces are then merged into larger sorted pieces until one sorted array is achieved by calling the merge() function. For the merge() function, it compares an item into one half of the array with an item in the other half of the array and moves the smaller item into a temporary array while the remaining items are moved to the temporary array. At the end of the function, the temporary array is copied back into the original array. We also implement the mergeDsc() functions to sort the array in an descending order by modifying the algorithm, for instance, in merge() function, the condition r[first1] < r[first2] is changed to r[first1] >= r[first2] when implementing mergeDsc() function. These functions are used to sort the Room Type, Room Price (Low to High), Room Price (High to Low), Latest Check-In Date and Earliest Check-In Date of the customers. Function template technique in C++ is also implemented when declaring the sorting functions in order to be flexible to work with different data types.

We have chosen the sorting algorithm - Merge Sort out of five sorting algorithms we have learned after the consideration of the growth rates of time required by the Merge Sort has the Big O Notation of O(n log n) which is significantly faster than O(n²).

<br>

##### 2. Searching

In the Hotel Booking System, we have implemented Searching Technique - Sequential search in SequenceSearch() function. This data structure operation works by examining each element in the array sequentially and compares its value with the search key. 

As an example, in our system, the SequenceSearch() will receive a search key which is the adminID entered by the admin, an array to be searched which is the admin information read from the admin file (database) and the size of the array in its parameter list as arguments. The variable index is set to -1 initially to indicate the record is not found. When comparing the adminID with the array which is accessing getadminID() function, if the adminID matches with any adminID from the database, the index is assigned the current array index and eventually returns the index. After returning to the main function, the result of SequenceSearch() is checked as if the value is equal to -1 (not found) or ! = -1 (found). This function acts as a verification and authentication for the admin identity.

We have chosen the Searching Technique - Sequential search as it is a basic function that is suitable to be implemented in a small size of list in which after considering the number of administrators in a hotel will not be a large population.

