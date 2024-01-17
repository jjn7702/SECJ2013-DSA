[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Task Management System - Project

## Objective🔎
The stack technique is used in this task management system to facilitate user navigation by preserving a history stack that allows users to easily backtrack through their interactions. A stack is also used to implement a reverse feature, which allows users to return to previous states. The queue technique, on the other hand, is used to manage tasks in a first-in, first-out manner, ensuring task execution fairness. Furthermore, an update queue is implemented, which uses a queue to organise and present updates to users in a systematic manner. These techniques, when combined, improve data accessibility and user experience in the system.


## Sypnosis 📝
 
Users encounter a comprehensive display of tasks, which includes dates and statuses, in the task management system's main menu, as well as an option menu with distinct options such as stack and queue. When users select the stack option, they are redirected to a sub-menu designed for last-in-first-out (LIFO) task data manipulation. Users can add tasks (push them onto the stack), remove tasks (pop them off the stack), and inspect tasks in a stacked manner, providing a dynamic and simple approach to task management. In the same way, selecting the queue option directs users to a sub-menu designed for first-in-first-out (FIFO) task manipulation. This menu contains options for adding tasks (enqueuing), removing tasks (dequeuing), and examining tasks in a queued manner, introducing a systematic and ordered approach to task management.

## Design 🎨

1. Class Diagram
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tempest/img/WhatsApp%20Image%202024-01-16%20at%2020.09.18_c792ba2c.jpg">


2. Flowchart
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tempest/img/WhatsApp%20Image%202024-01-16%20at%2020.09.18_7862cded.jpg">


## Flow of Event 💹

1. User will be directed to the main menu of the task management system. In the main menu user can see all the task with its date and status. User will also can see the option menu that consists of stack and queue data operation methods.

2. If the user click on the option 1 which add task in stack method, the system will show the output where the task will be added on the top of the list

3. The user will go to the main menu and will be showed again the first event. There the user can choose again which option that the user wants.

4. If the user click on the option 2 which delete task in stack method, the system will show the output where the task will be deleted on the top of the list.

5. The user will go to the main menu and will be showed again the first event. There the user can choose again which option that the user wants.

6. If the user click on the option 3 which add task in queue method, the system will show the output where the task will be added on the last of the list.

7. The user will go to the main menu and will be showed again the first event. There the user can choose again which option that the user wants.

8. If the user click on the option 4 which delete task in queue method, the system will show the output where the task will be deleted at the first of the list.

9. The user will go to the main menu and will be showed again the first event. There the user can choose again which option that the user wants.

10. If the user click on the option 5 which exit, the system will end the session and user will exiting the system.

## Source Code Demonstrating The Data Structure Concept Employed 💻

1. Stack Concept Code

class stack
{

private:

    int top;
    TaskData data[N]; // Array of structures to store task details

public:

    stack()
    {
        top = -1;
    }

    bool isfull()
    {
        return top == N - 1;
    }

    bool isempty()
    {
        return top == -1;
    }

    void push(const TaskData &d)
    {
        if (isfull())
            cout << "Stack is full" << endl;

        else
        {
            top++;
            data[top] = d;
        }
    }

    void pop()
    {
        if (isempty())
        {
            cout << "Stack is empty" << endl;
        }

        else
            top--;
    }

    TaskData stacktop()
    {
        return data[top];
    }

    void print()
    {
        if (isempty())
        {
            cout << "sorry, stack is empty" << endl;
        }
        else
        {
            for (int a = top; a >= 0; a--)
            {
                cout << left << setw(40) << data[a].tasks;
                cout << left << setw(2) << "|";
                cout << left << setw(20) << data[a].day + "-" + data[a].month + "-" + data[a].year;
                cout << left << setw(2) << "|";
                cout << left << setw(10) << data[a].status << endl;

                cout << endl;
            }
        }
    }
    };
    

2. Queue Concept Code

class queue
{

private:

    int front;
    int rear;
    TaskData data[N];
    int count;

public:

    queue()
    {
        front = 0;
        rear = N - 1;
        count = 0;
    }

    bool isempty()
    {
        return count == 0;
    }

    bool isfull()
    {
        return count == N;
    }

    void enqueue(const TaskData &newTask)
    {
        if (isfull())
        {
            cout << "Sorry, the queue is full" << endl;
        }
        else
        {
            rear = (rear + 1) % N; //*
            data[rear] = newTask;
            count++;
        }
    }

    void dequeue()
    {
        if (isempty())
        {
            cout << "Sorry, the queue is empty" << endl;
        }
        else
        {
            front = (front + 1) % N;
            count--;
        }
    }

    TaskData getfront()
    {
        return data[front];
    }

    TaskData getrear()
    {
        return data[rear];
    }

    void display()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
        }
        else if (front <= rear)
        {
            for (int a = front; a < rear; a++)
            {
                cout << data[a].tasks << "|" << data[a].day + "-" + data[a].month + "-" + data[a].year << "|" << data[a].status << " -> ";
            }
            // Display the last element without the arrow
            cout << data[rear].tasks << "|" << data[rear].day + "-" + data[rear].month + "-" + data[rear].year << "|" << data[rear].status;
        }
        else
        {
            for (int a = front; a < N - 1; a++)
            {
                cout << data[a].tasks << "|" << data[a].day + "-" + data[a].month + "-" + data[a].year << "|" << data[a].status << "->";
            }
            // Display the last element without the arrow
            cout << data[rear].tasks << "|" << data[rear].day + "-" + data[rear].month + "-" + data[rear].year << "|" << data[rear].status;
        }
        cout << endl;
    }
    };

## User Manual/Guide 📒

1. When the user enter the Task management system, the system will show the main page with the task in stack and queue manner. The system will also give option to the user.
![image](https://github.com/jjn7702/SECJ2013-DSA/assets/128146716/653e92b4-fc61-4268-9145-4651e08c3016)



2. Then, in the operation process option, the user can choose 5 options which are add and delete task in stack method, add and delete task in queue method and exit the program.
3. If the user enter the option 1 which is the add a task in stack method, the user can enter the task detail which are task, date, and status. After insert the data, the system will shows the output which the new task will be added at the top of the list. Then the user will shown again the option to choose.

Input:
![image](https://github.com/jjn7702/SECJ2013-DSA/assets/128146716/8294b8d2-3a81-4405-b8c7-0047e63f6894)


Output:
![image](https://github.com/jjn7702/SECJ2013-DSA/assets/128146716/81186eee-ed4c-4017-996b-8bc91a3a98ea)



4. If the user enter the option 2 which is the delete a task in stack method, The system will delete the topmost task from the list. After delete the data, the system will shows the output which the topmost task will be deleted from the list. Then the user will shown again the option to choose.


Before:
![image](https://github.com/jjn7702/SECJ2013-DSA/assets/128146716/44f0a8f4-369f-4668-bd49-f72c5b6ed4ea)


After:
![image](https://github.com/jjn7702/SECJ2013-DSA/assets/128146716/bad10448-ae27-4fca-9de2-3ca10c690f45)


5. If the user enter the option 3 which is the add a task in queue method, the user can enter the task detail which are task, date, and status. After insert the data, the system will shows the output which the new task will be added at the end of the list. Then the user will shown again the option to choose.

Input:
![image](https://github.com/jjn7702/SECJ2013-DSA/assets/128146716/f2877bad-6a8e-47b3-847e-cffd39ad03bf)



Output:
![image](https://github.com/jjn7702/SECJ2013-DSA/assets/128146716/b226d90d-ff97-4fca-8626-0da54caa3900)



6. If the user enter the option 4 which is the delete a task in queue method, The system will delete the first task from the list. After delete the data, the system will shows the output which the first task will be deleted from the list. Then the user will shown again the option to choose.

Before:
![image](https://github.com/jjn7702/SECJ2013-DSA/assets/128146716/7bceff1f-d801-4838-bf82-f331449ab256)



After:
![image](https://github.com/jjn7702/SECJ2013-DSA/assets/128146716/423a9c1c-5cb8-42d9-b806-8268df4f91ba)



7. If the user enter the option 5 which exit, the system will stop the session and the user will be exiting the system.

![image](https://github.com/jjn7702/SECJ2013-DSA/assets/128146716/2b41dffb-f0a3-4c6f-9acc-14b36ed5ec4b)


## Prepared by 🧑‍💻

| Name             | Matric Number | Photo                                                         |
| :---------------- | :-------------: | :------------------------------------------------------------: |
| Muhammad Luqman Hakim Bin Mohd Rizaudin   | A22EC0086        | <a href="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tempest/img/luqman.jpg" title="luqman"><img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tempest/img/luqman.jpg" width=80px, height=80px>     |
| Muhammad Anas Bin Mohd Pikri      | A21SC0464        | <a href="https://avatars.githubusercontent.com/u/116987481?v=4" title="Icon by Trazobanana"><img src="https://avatars.githubusercontent.com/u/116987481?v=4" width=80px, height=80px>         |
| Kugen a/l Kalidas       | A22EC0178       | <a href="https://avatars.githubusercontent.com/u/128279457?v=4" title="Anas"><img src="https://avatars.githubusercontent.com/u/128279457?v=4" width=80px, height=80px> |


## Findings 📊

- [Source Code](./source_code/project.cpp)
- [Input File](./source_code/task.txt)
- [Report]

## Contribution 🛠️
Please create an [Issue](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues) for any improvements, suggestions or errors in the content.

[![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702&labelColor=%23697689&countColor=%23555555&style=plastic)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fjjn7702)
![](https://hit.yhype.me/github/profile?user_id=81284918)

