# Techturtles Courier Service System
<a href="#" title="Icon by Trazobanana" style="display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0;">
    <img src="https://media0.giphy.com/media/h6sDj3CAKKUSxEkd9E/giphy.gif" width="350px" height="220px" alt="Centered Image">
</a>


## Description 📝
The Courier Service System is specially designed for the administrator. The system's objectives are mainly to sort parcels efficiently based on their status, shipping option or tracking number. Moreover, it also helps the administrator to add a new parcel into the system. Not to mention, the admin will be able to search the intended parcel based on the parcel’s tracking number. In Assignment 2, the latest Courier Service System will implement linked lists. The system's objectives are mainly to add, delete, find, sort and display parcels using linked lists method.

## Prepared by 🧑‍💻

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
| MUHAMMAD DANIEL HAKIM BIN SYAHRULNIZAM   | A22EC0207        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/129138344?v=4" width=80px, height=80px>     |
| MUHAMMAD NUR AZHAR BIN MOHD YAZID      | A22EC0220        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/128233352?v=4" width=80px, height=80px>         |
| MUHAMMAD SAFWAN BIN MOHD AZMI       | A22EC0221        | <a href="https://www.freepik.com/icon/graduated_4537051" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/128201537?v=4" width=80px, height=80px>         |


<h1>Assignment 1</h1>

## Flow of system
1. The user is prompted to the main menu of the Courier Service System.
2. The system displays a welcome message to the users.
3. The system can choose 5 options.
   - 3.1. If the user choose case '1', the user will choose to add a new parcel to the system.
   - 3.2. If the user choose case '2', the user wants to search for a particular parcel by using parcel tracking number as the input.
   - 3.3. If the user choose case '3', the user will prompt the system to sort the parcels’ status (complete or incomplete). The system will give the user two options: either to sort in ascending or descending order.
   - 3.4. If the user choose case '4', the user will prompt the system to sort the parcels’ shipping options. The system will give the user two options: bulky and heavy delivery or standard delivery.
   - 3.5. If the user choose case '5', the user will prompt the system to sort the parcels’ tracking number. The system will give the user two options: either to sort in ascending or descending order.
4. After the sorting has been done, the system will display tracking number, address, sender name, receiver name, status (complete or incomplete), or shipping option.
5. After that, the system will prompt the user either to continue or quit the system.


<h3>Report Assignment 1</h3>
<a href="https://docs.google.com/document/d/1IBuotBV8MyPapQ3iG9L_BJigHuHo5fWuo8pLHKXZuRI/edit"><img src="https://cdn.vectorstock.com/i/1000x1000/45/57/file-doc-icon-digital-blue-vector-24754557.webp" width="35px" height="40px" ></a>

<br>
<h1>Assignment 2</h1>

## Flow of system
1. The user is prompted to the main menu of the Courier Service System.

2. The system displays a welcome message to the users.

3. The system enters a loop for user interaction with the following options:

- 3.1. If the user chooses case '1':
   - 3.1.1. The user is prompted to enter parcel details, including tracking number, address, sender's name, receiver's name, shipping option, and delivery status.
   - 3.1.2. The system creates a new Parcel object with the entered details.
   - 3.1.3. The user is prompted to choose where to add the parcel (beginning, end, or specific position).
   - 3.1.4. The system adds the new parcel to the ParcelList accordingly.
   - 3.1.5. The system displays the updated list of parcels.

- 3.2. If the user chooses case '2':
   - 3.2.1. The user is prompted to input the parcel’s tracking number for search.
   - 3.2.2. The system searches for the parcel using binary search.
   - 3.2.3. If a match is found, the system displays the parcel details; otherwise, it prompts the user to try again.

- 3.3. If the user chooses case '3':
   - 3.3.1. The user is prompted to choose the sorting criteria (delivery status).
   - 3.3.2. The user selects the order (ascending or descending).
   - 3.3.3. The system executes the bubble sort algorithm based on the selected criteria.
   - 3.3.4. The system displays the sorted list of parcels.

- 3.4. If the user chooses case '4':
   - 3.4.1. The user is prompted to choose the sorting criteria (shipping options).
   - 3.4.2. The user selects the order (ascending or descending).
   - 3.4.3. The system executes the selection sort algorithm based on the selected criteria.
   - 3.4.4. The system displays the sorted list of parcels.

- 3.5. If the user chooses case '5':
   - 3.5.1. The user is prompted to choose the sorting criteria (tracking number).
   - 3.5.2. The user selects the order (ascending or descending).
   - 3.5.3. The system executes the merge sort algorithm based on the selected criteria.
   - 3.5.4. The system displays the sorted list of parcels.

4. After sorting, the system displays the details of each parcel, including tracking number, address, sender name, receiver name, status (complete or incomplete), or shipping option.

5. The system prompts the user to either continue or quit the system.

6. If the user selects '0', the system terminates. Otherwise, the loop continues, and the user is returned to the main menu.
7. End
<h3>Report Assignment 2</h3>
<a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Techturtles/Assignment%202/Assignment2_DSA.pdf"><img src="https://cdn.vectorstock.com/i/1000x1000/45/57/file-doc-icon-digital-blue-vector-24754557.webp" width="35px" height="40px" ></a>

<h1>Project</h1>

## Flow of system
1. Start
2. The system reads the file data from ParcelData.txt.
   - 2.1. If there is an error in the opening file, the system will terminate.
3. The system will prompt the user to input a choice number between 1 to 3.
   - 3.1. Case 1: If user selects case 1, the user will be implementing stack operations to enter a new parcel using push function, or remove an item using pop function.
      - 3.1.1. If case 1, the parcel will be added at the top of the stack.
      - 3.1.2. Else if case 2, the parcel will be removed from the top of the stack.
      - 3.1.3. Else if case 3, the system will display the lists of parcels.
      - 3.1.4. Else if case 4, the system will terminate.
      - 3.1.5. Else the system will display “Invalid choice. Please enter a number between 1 and 4”.
   - 3.2. Case 2 : If user enters case 2, the user will be implementing queue operations to enter a new parcel using enQueue function, or remove an item using deQueue function.
      - 3.2.1. If case 1, the parcel will be added at the back of the queue.
      - 3.2.2. Else if case 2, the parcel will be removed from the front of the queue.
      - 3.2.3. Else if case 3, the system will display the lists of parcels.
      - 3.2.4. Else if case 4, the system will terminate.
      - 3.2.5. Else the system will display “Invalid choice. Please enter a number between 1 and 4”.
   - 3.3. Case 3 : If the user enters choice 3, the system will be terminated.
   - 3.4. Else the system will display “Invalid choice. Please enter a number between 1 and 3”.
4. End

<h3>Project</h3>
<a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Techturtles/Project/Project_DSA_TechTurtles.pdf"><img src="https://cdn.vectorstock.com/i/1000x1000/45/57/file-doc-icon-digital-blue-vector-24754557.webp" width="35px" height="40px" ></a>

## Findings 📊

- <a href="Assignment 1" >Assignment 1 
- <a href="Assignment 2" >Assignment 2
- <a href="Project" >Project

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.
