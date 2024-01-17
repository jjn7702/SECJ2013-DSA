# Project
# Restaurant Management System

### Table of Contents
- [Problem Analysis](#Problem-Analysis)
- [Objectives of The Project](#Objectives-of-The-Project)
- [Synopsis](#Synopsis)
- [Class Diagram](#class-diagram)
- [Pseudocode](#pseudocode)
- [Implementation of Stack](#implementation-of-stack)
- [Implementation of Queue](#implementation-of-queue)
- [Development Code Steps](#development-code-steps)

## Introduction
### Problem Analysis
In this project, we will develop a restaurant management system to manage the orders in the restaurant. In a restaurant management system, there should be two main users, which are staff of the restaurant and customers. The purpose of developing this system is to address several challenges faced by both staff and customers. One of the primary challenges is the traditional and time consuming order management in a restaurant. Currently, staff must manage the menu manually before allowing the customer to make orders which lead to inefficiencies. The system proposed a solution by implementing stack operations for menu lists. Staff are allowed to add a new menu, delete current menu, and review current changes of the menu, aiming to a more organized and accurate preferences of the restaurant. 

Another challenge identified in the current order system in restaurants is the lack of efficiency of taking orders from customers. By handling customer orders manually, it often leads to delays and is unorganized. In order to address this issue, the system implements queue operations for order management in the restaurant. Customers can make orders, and the system will manage their orders in a queue systematically. Staff can also view the customer order queue, which allows them to track and confirm the order. This is to enhance the overall service of the restaurant. The system also provides an interface where customers can place orders based on the available manu stack, view their order, and cancel order if needed. This resolves the challenges that often occur in order and customer management, eventually providing satisfaction to the customers. 

In conclusion, by implementing stack and queue operations, the proposed restaurant management system can contribute to a more organized flow of ordering management as well as to meet the customers requirements.

### Objectives of The Project
<li>To simplify the process of taking orders in restaurant  </li>
<li>To apply data structure concept such as stack and queue in the system</li>
<li>To manage menu by adding and deleting menu using stack operation</li>
<li>To manage customer orders using queue, ensuring a smooth workflow</li>
<li>To provide a seamless system for both staff and customers </li>


### Synopsis
There are two types of data structure used in the Restaurant Management System, which are  Stack and Queue. In the system, we have Staff and Customer as the users. Staff is the one to manage the orders queue made by customers. Staff are also able to add or delete new menus using stack operation. Basically, if the user is a staff member,  he can add or delete the menu from the list, view the current list of customer orders, and confirm customer orders by using queue operation. 

On the other hand, if the user is a customer, they are able to make orders based on the menu list from stack operation. Customers are required to enter their table number, food Id and the quantity of the food they want. Customers are also able to view their list of orders and cancel orders by entering the table number. The order details will be deleted from the order queue. 


## System Design

### Class Diagram
<p align="center">
<img src="https://github.com/jjn7702/SECJ2013-DSA/blob/main/Submission/sec02/Tupperware/Project/ProjectClassDiagram.png?raw=true" width="80%"><br>
Figure 1: Class Diagram of Restaurant Management System
</p>

### Pseudocode
<p align="center">

</p>

### Implementation of Stack
The system uses a Stack linked list operation to manage the menu list. This operation is basically used by the staff to add or delete menus from the stack. Stack operations required two classes which are nodeStack and StackMenu. The nodeStack class holds menu information by using the instance of the Menu class, menu. The nodeStack* next represents a pointer to point the next node in the stack. 

The StackMenu class represents stack operation for the menu. nodeStack* top indicates a pointer to point to the top of the stack. StackMenu initialises top as null value indicating that the stack is empty. isEmpty() is to check whether the stack menu is empty or not. The push function in the system is to add a new menu in the stack menu. The system will prompt the user to enter menu details, if the stack is not empty it will set the new menu to the current top stack. On the other hand, the pop function is to delete a menu from the stack. If the stack is empty, the system will display “The stack is empty”. If not, the top stack will be set to the next node, and the top node will be deleted. The stackTop() is to get the current of the stack menu. Lastly, displayStack() is to display all the menus in the stack. It will display according to the current menu changes.


### Implementation of Queue
The system implements the queue linked-list operation to store customer’s orders. The operation includes adding a new order from the customer, viewing the current list of orders, and also cancelling orders. 

The addition of a new order is by adding an order into the queue. If the queue is empty, the new order  or node will be placed first in the queue and also the back of queue, otherwise, it will be added to the back of the queue. The next for back will take the new node and the back will be the new node. This means, the queue will only increment its storage at the end of the list.

The cancel order operation works by deleting the most front node in the queue. When the most front order is deleted, the second in order will be the new front. Two temporary nodes, temp and prev are needed to make this operation work. The temp node will always move to the next temp when the condition of not null and getTableNum is must not equal to tableNumber is abide. The prev on the other hand, will take the node temp before the temp move to the next node. If one of the condition does not followed, the loop will break. If  temp is null, the system will output error messages. If the prev is null however, the front node will be the next temp, but if prev is not null, the next for prev will take the node from next for temp. If the next of prev is null too, hence the back node will be prev. Lastly, the next for temp will be null, and then does the temp can be deleted.

### Development Code Steps

#### Source code demonstrating the data structure concept employed. 

##### Stack Implementation


    class nodeStack {
    public:
        Menu menu;
        nodeStack* next;
        nodeStack(Menu m) : menu(m), next(nullptr) {}
    };
    
    
    class StackMenu {
    private:
        nodeStack *top;
    
    
    public:
        StackMenu() {
            top = NULL;
        }
    
    
        bool isEmpty() {
            return top == NULL;
        }
    
    
        void push(const Menu& menu) {
            nodeStack* newNode = new nodeStack(menu);
    
    
            if (!isEmpty())
                newNode->next = top;
            top = newNode;
        }
    
    
        void pop() {
            if (isEmpty())
                cout << "The stack is empty." << endl;
            else {
                nodeStack* del = top;
    
    
                top = del->next;
                del->next = NULL;
                delete del;
            }
        }
    
    
        nodeStack* getTop() const {
            return top;
        }
    
    
        void displayStack() {
            if (isEmpty())
                cout << "Sorry, no menu in the stack." << endl;
            else {
                nodeStack* temp = top;
    
    
                while (temp) {
                    temp->menu.displayMenu();
                    temp = temp->next;
                }
            }
        }
    };

##### Queue Implementation

        class nodeQueue {
    public:
        Order order;
        nodeQueue* next;
        nodeQueue(Order o) : order(o), next(nullptr) {}
    };
    
    
    class QueueMenu {
    public:
        nodeQueue *back, *front;
    
    
        QueueMenu() {
            front = NULL;
            back = NULL;
        }
    
    
        bool isEmpty() {
            return ((front == NULL) && (back == NULL));
        }
    
    
        void enQueue(const Order& order) {
            nodeQueue* newNode = new nodeQueue(order);
    
    
            if (isEmpty()) {
                front = newNode;
                back = newNode;
            } else {
                back->next = newNode;
                back = newNode;
            }
        }
    
    
        void deQueue(int tableNumber) {
            nodeQueue* temp = front;
            nodeQueue* prev = NULL;
    
    
            while (temp != NULL && temp->order.getTableNumber() != tableNumber) {
                prev = temp;
                temp = temp->next;
            }
    
    
            if (temp == NULL) {
                cout << "No orders found for table number " << tableNumber << "." << endl;
            } else {
                if (prev == NULL) {
                    front = temp->next;
                    if (front == NULL) {
                        back = NULL;
                    }
                } else {
                    prev->next = temp->next;
                    if (prev->next == NULL) {
                        back = prev;
                    }
                }
    
    
                temp->next = NULL;
                delete temp;
                cout << "Order for table number " << tableNumber << " dequeued successfully." << endl;
            }
        }
    
    
        void displayQueue() {
            if (isEmpty())
                cout << "Sorry, no order in the queue." << endl;
            else {
                cout << setw(10) << "Table" << " | "
                     << left << setw(10) << "Food ID" << " | "
                     << setw(21) << "Name" << " | "
                     << setw(13) << "Category" << " | "
                     << setw(8) << "Quantity" << " | "
                     << setw(6) << "Price" << " | "
                     << setw(10) << "Total Price" << endl;
                cout << "-------------------------------------------------------------------------------------------------" << endl;
    
    
                nodeQueue* temp = front;
                while (temp) {
                    Order order = temp->order;
                    Menu menu = order.getMenu();
                    cout << setw(10) << order.getTableNumber() << " | "
                         << setw(10) << menu.getFoodId() << " | "
                         << setw(21) << menu.getName() << " | "
                         << setw(13) << menu.getCategory() << " | "
                         << setw(8) << order.getQuantity() << " | "
                         << fixed << setprecision(2) << setw(6) << menu.getPrice() << " | "
                         << setw(10) << fixed << setprecision(2) << order.getTotalPrice() << endl;
                    temp = temp->next;
                }
    
    
                cout << endl;
            }
        }
    };

##### User manual/guide: provide examples of input and output (if any) for each task.




<br>



