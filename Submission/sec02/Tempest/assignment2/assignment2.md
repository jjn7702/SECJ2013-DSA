[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Task Management System - Assignment 2
## Objective
The objective of  this assignment is to implement the linked list concept into the task management system. This method alllows the user to edit the data in several ways such as inserting a new task and delete current tasks in the task list. This reduces the workload of the user to edit the tasks in the list where the users can be able to access any data in the list and execute insertion or deletion method.Users are not required to shift all the subsequent tasks in order to perform the insertion and deletion.Linked list is also known to have dynamic memory allocation where the linked lists can increase or decrease during the execution of program unlike arrays where the size is fixed.

## Sypnosis 📝
In this assignment, implementation of linked list method in described with a focus of inserting and delting a node that represents tasks.The system enables the user to add and delete the nodes in the system efficiently.Users can access to any location in the lists of tasks and perform modification of lists either insertion of new node( tasks ) or deletion of node( tasks ).Users are allowed to add a new node in three different situation which is at the beginning of the list, the middle of the list ( locate by using the number of the list ) ore at the end of the list.Next,user can also delete the nodes in three different locations which are at the beginning of the list, the middle of th list ( locate by using a number ) and at the end of the list.Implementation of linked list method increases the efficiency of the system in terms of easibility of executing modification, dynamic memory allocation and memory efficiency. 


## Design 🎨

1. Class Diagram
<img src="https://raw.githubusercontent.com/jjn7702/SECJ2013-DSA/main/Submission/sec02/Tempest/img/Untitled%20Diagram-Page-16.jpg" width=300px, height=500px>

<img src="https://raw.githubusercontent.com/jjn7702/SECJ2013-DSA/main/Submission/sec02/Tempest/img/Untitled%20Diagram-Page-17.jpg" width=500px, height=400px>



3. Flowchart

<img src="https://raw.githubusercontent.com/jjn7702/SECJ2013-DSA/main/Submission/sec02/Tempest/img/DSAPage2-Page-1.jpg" width=1000px, height=800px>

<img src="https://raw.githubusercontent.com/jjn7702/SECJ2013-DSA/main/Submission/sec02/Tempest/img/New2.jpg" width=1000px, height=800px>

<img src="https://raw.githubusercontent.com/jjn7702/SECJ2013-DSA/main/Submission/sec02/Tempest/img/DSAPage2-Page-3.jpg" width=1000px, height=800px>

<img src="https://raw.githubusercontent.com/jjn7702/SECJ2013-DSA/main/Submission/sec02/Tempest/img/DSAPage2-Page-4.jpg" width=400px, height=400px>

## Flow of Event 💹

1. User will be directed to the main menu of the task management system. In the main menu user can see all the task with its date and status. User will also can see the option menu that have add, delete, find, and sort the task.

2. If the user click on the add task option, the system will redirect the user to the next option menu where the user can choose to add the task in either of these manner which are:

    1. Add beginning
    2. Add middle (by using a number)
    3. Add end

3. After choosing the option, the system will show the output based on the option that have been chosen by the user.

4. The user can exit to the main menu and will be showed again the first event. There the user can choose again which option that the user wants.

5. If the user choose the second option which is delete task, the system will redirect the user to the next option menu.

6. In the delete task menu option the user can enter any of these delete option to delete any of the task based on the option. The options are:
    1. Delete beginning
    2. Delete middle (by a using number)
    3. Delete end

7. After choosing the option, the system will show the output based on the option that have been chosen by the user.

8. The user can exit to the main menu and will be showed again the first event. There the user can choose again which option that the user wants.

9. If the user choose the third option which is find task, the system will redirect the user to the next option menu.

10. In the find task menu option the user can enter any of these searching option to see if the task that the user want to see is in the list. The options are:
    1. Find by using the alphabet
    2. Find by using the date
    3. Find by using the status

11. After choosing the option, the system will show the output based on the option that have been chosen by the user.

12. The user can exit to the main menu and will be showed again the first event. There the user can choose again which option that the user wants.

13. If the user choose the forth option which is sort task, the system will redirect the user to the next option menu.

14. If the user click on the sorting option, the system will redirect the user to the next option menu where the user can choose to sort the lisk in either of these manner which are:

    1. Ascending Alphabet
    2. Descending Alphabet
    3. Ascending Date
    4. Descending Date
    5. Ascending Status
    6. Descending Status
    (* notes: For the Status the arrangement of level will be from todo, doing and completed)

15. After choosing the option, the system will show the output based on the option that have been chosen by the user.

16. The user can exit to the main menu and will be showed again the first event. There the user can choose again which option that the user wants.

## Prepared by 🧑‍💻

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
| Muhammad Luqman Hakim Bin Mohd Rizaudin   | A22EC0086        | <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tempest/img/luqman.jpg" title="luqman"><img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tempest/img/luqman.jpg" width=80px, height=80px>     |
| Muhammad Anas Bin Mohd Pikri      | A21SC0464        | <a href="https://avatars.githubusercontent.com/u/116987481?v=4" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/116987481?v=4" width=80px, height=80px>         |
| Kugen a/l Kalidas       | A22EC0178       | <a href="https://avatars.githubusercontent.com/u/128279457?v=4" title="Anas"><img src="https://avatars.githubusercontent.com/u/128279457?v=4" width=80px, height=80px> |


## Findings 📊

- [Source Code](./source_code/assignment2.cpp)
- [Input File](./source_code/task.txt)
- [Report]

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)

