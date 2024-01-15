#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#define N 100

using namespace std;

// Structure to hold task details
struct TaskData
{
    string tasks;
    string day;
    string month;
    string year;
    string status;
};

class stack
{
private:
    int top;
    TaskData data[N]; // Array of structures to store task details

public:
    stack()
    {
        top = -1;
    };

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
        if(isfull())
        cout<<"Stack is full"<<endl;

        else
        {
            top++;
            data[top]=d;
        }
        
    }

    void pop()
    {
        if(isempty())
        {
            cout<<"Stack is empty"<<endl;
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

int main()
{
    fstream input("task.txt", ios::in);
    if (!input.is_open())
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string tasks, status, date;
    string day, month, year;
    stack s;
    queue q;

    // Reading tasks in stack and queue methods from the file
    while (getline(input >> ws, tasks, '/'))
    {
        getline(input >> ws, day, '-');
        getline(input >> ws, month, '-');
        getline(input >> ws, year, '(');
        getline(input >> ws, status, ')');

        TaskData newTask;
        newTask.tasks = tasks;
        newTask.day = day;
        newTask.month = month;
        newTask.year = year;
        newTask.status = status;

        s.push(newTask);
        q.enqueue(newTask);
    }

    input.close();

    // Display tasks using stack method
    cout << "\nTasks using Stack method:" << endl;
    cout << left << setw(40) << "TASK";
    cout << left << setw(2) << "|";
    cout << left << setw(20) << "DATE";
    cout << left << setw(2) << "|";
    cout << left << setw(10) << "STATUS" << endl
         << endl;
     // Display the entire stack
    cout << endl;

    // Display tasks using queue method
    cout << "\nTasks using Queue method:" << endl;
     // Display the entire queue
    cout << endl;

    int choice;
    bool displayTaskList;
    do
    {

        cout << "<<OPERATION PROCESS>>" << endl;
        cout << "[1] ADD A TASK IN STACK METHOD" << endl;
        cout << "[2] REMOVE A TASK IN STACK METHOD" << endl;
        cout << "[3] ADD A TASK IN QUEUE METHOD" << endl;
        cout << "[4] REMOVE A TASK IN QUEUE METHOD" << endl; // New option for sorting
        cout << "[5] EXIT" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter new task details:" << endl;
            TaskData newTask;
            cout << "Task: ";
            cin >> newTask.tasks;
            cout << "Day: ";
            cin >> newTask.day;
            cout << "Month: ";
            cin >> newTask.month;
            cout << "Year: ";
            cin >> newTask.year;
            cout << "Status: ";
            cin >> newTask.status;

            s.push(newTask);
            // Display tasks using stack method
            cout << "\nTasks using Stack method:" << endl;
            cout << left << setw(40) << "TASK";
            cout << left << setw(2) << "|";
            cout << left << setw(20) << "DATE";
            cout << left << setw(2) << "|";
            cout << left << setw(10) << "STATUS" << endl
                 << endl;
             // Display the entire stack
            cout << endl;
        }
        break;

        case 2:
        {
            s.pop();
            // Display tasks using stack method
            cout << "\nTasks using Stack method:" << endl;
            cout << left << setw(40) << "TASK";
            cout << left << setw(2) << "|";
            cout << left << setw(20) << "DATE";
            cout << left << setw(2) << "|";
            cout << left << setw(10) << "STATUS" << endl
                 << endl;
             // Display the entire stack
            cout << endl;
        }
        break;

        case 3:
        {
            cout << "Enter new task details:" << endl;
            TaskData newTask;
            cout << "Task: ";
            cin >> newTask.tasks;
            cout << "Day: ";
            cin >> newTask.day;
            cout << "Month: ";
            cin >> newTask.month;
            cout << "Year: ";
            cin >> newTask.year;
            cout << "Status: ";
            cin >> newTask.status;

            q.enqueue(newTask);
            // Display tasks using queue method
            cout << "\nTasks using Queue method:" << endl;
             // Display the entire queue
            cout << endl;
        }
        break;

        case 4:
        {
            q.dequeue();
            // Display tasks using queue method
            cout << "\nTasks using Queue method:" << endl;
             // Display the entire queue
            cout << endl;
        }
        break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
