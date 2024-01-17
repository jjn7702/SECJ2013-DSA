#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void displayHeader(){
    cout << left << setw(10) << "Food ID" << " | "
        << setw(21) << "Name" << " | "
        << setw(13) << "Category" << " | "
        << setw(6) << "Price" << "\n";
    cout << "---------------------------------------------------------" << endl;

}

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
             << fixed << setprecision(2) << setw(6) << price << endl;
    }
};

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

class Order {
private:
    int tableNumber;
    Menu menu;
    int quantity;
    double totalPrice;

public:
    Order(int tableNumber, const Menu& menu, int quantity)
        : tableNumber(tableNumber), menu(menu), quantity(quantity) {
        totalPrice = quantity * menu.getPrice();
    }

    int getTableNumber() const { return tableNumber; }
    Menu getMenu() const { return menu; }
    int getQuantity() const { return quantity; }
    double getTotalPrice() const { return totalPrice; }
};

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

class RestaurantSystem {
private:
    StackMenu menuStack;
    QueueMenu orderQueue;

public:
    void staffView() {
        char choice;
        int opt;
        string foodId, name, category;
        double price;
        int tableNumber;

        do {
            cout << "\n[1] Add Menu" << endl;
            cout << "[2] Delete Menu" << endl;
            cout << "[3] Display Recent Changes" << endl;
            cout << "[4] View Customer Orders" << endl;
            cout << "[5] Confirm Customer Order" << endl;
            cout << "[6] Exit Staff Menu" << endl;

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

                    menuStack.push(Menu(foodId, name, category, price));
                    cout << "Menu added successfully." << endl;
                    break;
                }

                case 2: {
                    menuStack.pop();
                    cout << "Menu deleted successfully." << endl;
                    break;
                }

                case 3: {
                    displayHeader();
                    menuStack.displayStack();
                    break;
                }

                 case 4: {
                    orderQueue.displayQueue();
                    break;
                }

                case 5: {
                    cout << "Enter table number to complete the order: ";
                    cin >> tableNumber;

                    // Check if the table number is valid
                    if (tableNumber <= 0) {
                        cout << "Invalid table number. Please enter a positive integer." << endl;
                        break;
                    }

                    orderQueue.deQueue(tableNumber);
                    break;
                }

                case 6: {
                    cout << "Exiting Staff Menu." << endl;
                    break;
                }

                default:
                    cout << "Invalid option. Please try again." << endl;
            }

            cout << "\nDo you want to continue in the staff menu? (Y/N): ";
            cin >> choice;

        } while (choice == 'Y' || choice == 'y');
    }

    void customerView() {
        char choice;
        int opt;
        string foodId, name, category;
        double price;
        int tableNumber;

        do {
            cout << "\n[1] Make Order" << endl;
            cout << "[2] Display Order Queue" << endl;
            cout << "[3] Cancel Order" << endl;
            cout << "[4] Exit Customer Menu" << endl;

            cout << "Enter your choice: ";
            cin >> opt;

            switch (opt) {
                case 1: {
                    // Display the menu for the customer
                    cout << "\nMenu:" << endl;
                    displayHeader();
                    menuStack.displayStack();

                    if (!menuStack.isEmpty()){
                        cout << "\nEnter your table number: ";
                        cin >> tableNumber;

                        // Check if the table number is valid
                        if (tableNumber <= 0) {
                            cout << "Invalid table number. Please enter a positive integer." << endl;
                            break;
                        }

                        cout << "Enter the food ID for the order: ";
                        cin >> foodId;

                        Menu selectedMenu;
                        bool validFoodId = false;

                        nodeStack* temp = menuStack.getTop();
                        while (temp) {
                            if (temp->menu.getFoodId() == foodId) {
                                selectedMenu = temp->menu;
                                validFoodId = true;
                                break;
                            }
                            temp = temp->next;
                        }

                        if (!validFoodId) {
                            cout << "Invalid food ID. Please enter a valid food ID from the menu." << endl;
                            break;
                        }

                        cout << "Enter the quantity: ";
                        int quantity;
                        cin >> quantity;

                        // Enqueue the order
                        orderQueue.enQueue(Order(tableNumber, selectedMenu, quantity));
                        cout << "Order enqueued successfully." << endl;
                    }
                    break;
                }

                case 2: {
                    orderQueue.displayQueue();
                    break;
                }

                case 3: {
                    cout << "Enter your table number to cancel the order: ";
                    cin >> tableNumber;

                    // Check if the table number is valid
                    if (tableNumber <= 0) {
                        cout << "Invalid table number. Please enter a positive integer." << endl;
                        break;
                    }

                    orderQueue.deQueue(tableNumber);
                    break;
                }

                case 4: {
                    cout << "Exiting Customer Menu." << endl;
                    break;
                }

                default:
                    cout << "Invalid option. Please try again." << endl;
            }

            cout << "\nDo you want to continue in the customer menu? (Y/N): ";
            cin >> choice;

        } while (choice == 'Y' || choice == 'y');
    }

    bool checkStaff(string staffId) {
        string registeredId[3] = {"NAQ", "NN", "WNS"};

        for (int i = 0; i < 3; i++) {
            if (staffId == registeredId[i]) {
                return true; 
            }
        }
        return false;
    }
};

int main() {
    RestaurantSystem restaurant;

    string staffID;
    string user;
    char choice;


    cout << "Welcome to Tupperware!!\n\n";
    do{

        cout << "\nAre you [Customer] or [Staff]? : ";
        // cin.ignore();
        getline(cin, user);

        if (user == "Staff" || user == "staff") {
            cout << "If you are a staff, please enter your staff ID : ";
            getline(cin, staffID);

            if (!restaurant.checkStaff(staffID)) {
                cout << "Invalid staff ID. Redirecting to customer view...\n\n";
                restaurant.customerView();
            } else {
                cout << "\nWelcome, staff! Redirecting to staff view...\n";
                restaurant.staffView();
            }
        } else if (user == "Customer" || user == "customer") {
            cout << "\nWelcome, customer! Redirecting to customer view...\n\n";
            restaurant.customerView();
        }

        cout << "\nDo you want to continue in the main menu? (Y/N): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'Y' || choice == 'y');

    cout << "\nThank you for using our system";

    return 0;
}
