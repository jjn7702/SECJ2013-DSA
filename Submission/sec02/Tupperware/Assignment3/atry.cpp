#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
//#include <stack>

using namespace std;

class Menu {
private:
    string foodId;
    string name;
    string category;
    double price;

public:
    Menu() {
        foodId = "";
        name = "";
        category = "";
        price = 0.0;
    }

    Menu(string foodId, string name, string category, double price)
        : foodId(foodId), name(name), category(category), price(price) {}

    string getFoodId() const { return foodId; }
    string getName() const { return name; }
    string getCategory() const { return category; }
    double getPrice() const { return price; }

    void setFoodId(string foodId) { this->foodId = foodId; }
    void setName(string name) { this->name = name; }
    void setCategory(string category) { this->category = category; }
    void setPrice(double price) { this->price = price; }

    // Display menu details
    void displayMenu() const {
        cout << left;
        cout << setw(10) << foodId << " | "
            << setw(21) << name << " | "
            << setw(13) << category << " | "
            << fixed << setprecision(2) << setw(4) << price << endl;
    }
};

class nodeStack {
    public:
        Menu menu;
        nodeStack* next;
        nodeStack(Menu m) : menu(m), next(nullptr){}
};

class StackMenu {
private:
    //stack<Menu> menuStack;
    nodeStack *top;

public:
    StackMenu(){
        top = NULL; //shows the stack is empty
    }

    bool isEmpty(){
        return top == NULL;
    }

    void push(const Menu& menu){
        nodeStack* newNode = new nodeStack(menu);

        if (!isEmpty())
            newNode->next = top;
        top = newNode;
    }

    void pop(){
        if (isEmpty())
            cout << "The stack is empty." << endl;
        else {
            nodeStack *del = top;

            top = del->next;
            del->next = NULL;
            delete del;
        }
    }

    /*int stackTop() {
        return top->menu;
    }*/

    void displayStack(){
        if (isEmpty())
            cout << "Sorry, no menu in the stack." << endl;
        else {
            nodeStack *temp = top;

            cout << "Recent Menu Changes:" << endl;

            while (temp) {
                temp->menu.displayMenu();
                temp = temp->next;
            }
        }
    }


    /*void pushMenu(const Menu& menu) {
        menuStack.push(menu);
    }

    void popMenu() {
        if (!menuStack.empty()) {
            menuStack.pop();
        } else {
            cout << "Stack is empty. Nothing to pop." << endl;
        }
    }

    void displayStack() const {
        stack<Menu> tempStack = menuStack;
        cout << "Recent Menu Changes:" << endl;
        while (!tempStack.empty()) {
            tempStack.top().displayMenu();
            tempStack.pop();
        }
    }*/
};

class QueueMenu {
    public:
        nodeStack *back, *front;

        QueueMenu() {
            front = NULL;
            back = NULL;
        }

        bool isEmpty() {
            return ((front == NULL) && (back == NULL));
        }

        void enQueue(const Menu& menu) {
            nodeStack *newNode = new nodeStack(menu);

            if (isEmpty()){
                front = newNode;
                back = newNode;
            }
            else {
                back->next = newNode;
                back = newNode;
            }
        }

        void deQueue() {
            nodeStack *delNode = front;

            if (isEmpty())
                cout << "The queue is empty." << endl;
            else {
                if (front != back) {
                    front = front->next;
                    delNode->next = NULL; 
                } else {
                    front = NULL;
                    back = NULL;
                }
                delete delNode;

            }
        }

        void displayQueue() {
            if (isEmpty())
                cout << "Sorry, no order in the queue." << endl;
            else {
                cout << "Order Queue:" << endl;
                cout << left << setw(10) << "Food ID" << " | "
                    << setw(21) << "Name" << " | "
                    << setw(13) << "Category" << " | "
                    << setw(6) << "Price" << endl;
                cout << "----------------------------------------------" << endl;

                nodeStack *temp = front;
                while (temp) {
                    Menu menu = temp->menu;
                    cout << setw(10) << menu.getFoodId() << " | "
                        << setw(21) << menu.getName() << " | "
                        << setw(13) << menu.getCategory() << " | "
                        << fixed << setprecision(2) << setw(6) << menu.getPrice() << endl;
                    temp = temp->next;
                }

                cout << endl;
            }
        }
};

int main() {
    char choice;
    int opt;
    string foodId, name, category;
    double price;
    StackMenu menuStack;
    QueueMenu orderQueue;

    cout << "WELCOME TO TUPPERWARE!" << endl;

    do {
        cout << "\n[1] Add Menu" << endl;
        cout << "[2] Delete Menu" << endl;
        cout << "[3] Display Recent Changes" << endl;
        cout << "[4] Enqueue Order" << endl;
        cout << "[5] Dequeue Order" << endl;
        cout << "[6] Display Order Queue" << endl;
        cout << "[7] Exit" << endl;

        cout << "Enter your choice: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                cout << "Enter the food ID: ";
                cin >> foodId;
                cout << "Enter the food Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter the category: ";
                getline(cin, category);
                cout << "Enter the price: ";
                cin >> price;

                //menuStack.pushMenu(Menu(foodId, name, category, price));
                menuStack.push(Menu(foodId, name, category, price));
                cout << "Menu added successfully." << endl;
                break;
            }

            case 2: {
                //menuStack.popMenu();
                menuStack.pop();
                cout << "Menu deleted successfully." << endl;
                break;
            }

            case 3: {
                menuStack.displayStack();
                break;
            }

            case 4: {
                cout << "Enter the food ID for the order: ";
                cin >> foodId;
                cout << "Enter the quantity: ";
                int quantity;
                cin >> quantity;

                for (int i = 0; i < quantity; ++i) {
                    //orderQueue.enqueueMenu(Menu(foodId, "", "", 0.0));
                    orderQueue.enQueue(Menu(foodId, "", "", 0.0));
                }

                cout << "Order enqueued successfully." << endl;
                break;
            }

            case 5: {
                //orderQueue.dequeueMenu();
                orderQueue.deQueue();
                cout << "Order dequeued successfully." << endl;
                break;
            }

            case 6: {
                orderQueue.displayQueue();
                break;
            }

            case 7: {
                cout << "Exiting the program. Thank you!" << endl;
                break;
            }

            default:
                cout << "Invalid option. Please try again." << endl;
        }

        cout << "\nDo you want to continue? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
