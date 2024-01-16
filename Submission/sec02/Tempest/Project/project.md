[![Stars Badge](https://img.shields.io/github/stars/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/stargazers)
[![Forks Badge](https://img.shields.io/github/forks/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/network/members)
[![Pull Requests Badge](https://img.shields.io/github/issues-pr/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/pulls)
[![Issues Badge](https://img.shields.io/github/issues/jjn7702/SECJ2013-DSA)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/issues)
[![Contributors Badge](https://img.shields.io/github/contributors/jjn7702/SECJ2013-DSA?color=2b9348)](https://github.com/jjn7702/SECJ2013-DSA/Submission/Sample/graphs/contributors)
![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fjjn7702%2FSECJ2013-DSA%2FSubmission%2FSample&labelColor=%23d9e3f0&countColor=%23697689&style=flat)

_Don't forget to hit the :star: if you like this repo._

# Task Management System - Assignment 2

## Objective📝
The stack technique is used in this task management system to facilitate user navigation by preserving a history stack that allows users to easily backtrack through their interactions. A stack is also used to implement a reverse feature, which allows users to return to previous states. The queue technique, on the other hand, is used to manage tasks in a first-in, first-out manner, ensuring task execution fairness. Furthermore, an update queue is implemented, which uses a queue to organise and present updates to users in a systematic manner. These techniques, when combined, improve data accessibility and user experience in the system.


## Sypnosis 📝
 
Users encounter a comprehensive display of tasks, which includes dates and statuses, in the task management system's main menu, as well as an option menu with distinct options such as stack and queue. When users select the stack option, they are redirected to a sub-menu designed for last-in-first-out (LIFO) task data manipulation. Users can add tasks (push them onto the stack), remove tasks (pop them off the stack), and inspect tasks in a stacked manner, providing a dynamic and simple approach to task management. In the same way, selecting the queue option directs users to a sub-menu designed for first-in-first-out (FIFO) task manipulation. This menu contains options for adding tasks (enqueuing), removing tasks (dequeuing), and examining tasks in a queued manner, introducing a systematic and ordered approach to task management.

## Design 🎨

1. Class Diagram
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tempest/img/WhatsApp%20Image%202024-01-16%20at%2020.09.18_c792ba2c.jpg">


2. Flowchart
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tempest/img/WhatsApp%20Image%202024-01-16%20at%2020.09.18_7862cded.jpg">


## Flow of Event 💹

1. User will be directed to the main menu of the task management system. In the main menu user can see all the task with its date and status. User will also can see the option menu that have stack and queue.

2. If the user click on the stack option, the system will redirect the user to the next option menu where the user can choose to use the stack implementation(last-in-first-out) for the task data manipulation in such manner:

    1. Add (push)
    2. Delete (pop)
    3. View in stack manner(bottled view)

3. After choosing the option, the system will show the output based on the option that have been chosen by the user.

4. The user can exit to the main menu and will be showed again the first event. There the user can choose again which option that the user wants.

5. If the user choose the second option which is queue task, the system will redirect the user to the next option menu.

6. If the user click on the queue option, the system will redirect the user to the next option menu where the user can choose to use the queue implementation(first-in-first-out) for the task data manipulation in such manner:

    1. Add (enqueue)
    2. Delete (dequeue)
    3. View in queue manner(list view)

7. After choosing the option, the system will show the output based on the option that have been chosen by the user.

8. The user can exit to the main menu and will be showed again the first event. There the user can choose again which option that the user wants.

## Source Code Demonstrating The Data Structure Concept Employed 💹

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

