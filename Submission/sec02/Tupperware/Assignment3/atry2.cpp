#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stack>
#include <queue>

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

class StackMenu {
private:
    stack<Menu> menuStack;

public:
    void pushMenu(const Menu& menu) {
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
    }
};

class QueueMenu {
private:
    queue<Menu> menuQueue;

public:
    void enqueueMenu(const Menu& menu) {
        menuQueue.push(menu);
    }

    void dequeueMenu() {
        if (!menuQueue.empty()) {
            menuQueue.pop();
        } else {
            cout << "Queue is empty. Nothing to dequeue." << endl;
        }
    }

    void displayQueue() const {
        queue<Menu> tempQueue = menuQueue;
        cout << "Order Queue:" << endl;
        while (!tempQueue.empty()) {
            tempQueue.front().displayMenu();
            tempQueue.pop();
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
        cout << "[3] Search Menu" << endl;
        cout << "[4] Display Recent Changes" << endl;
        cout << "[5] Enqueue Order" << endl;
        cout << "[6] Dequeue Order" << endl;
        cout << "[7] Display Order Queue" << endl;
        cout << "[8] Exit" << endl;

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

                menuStack.pushMenu(Menu(foodId, name, category, price));
                cout << "Menu added successfully." << endl;
                break;
            }

            case 2: {
                menuStack.popMenu();
                cout << "Menu deleted successfully." << endl;
                break;
            }

            case 3: {
                // Searching for a menu item is not implemented in this example.
                cout << "Search functionality is not implemented." << endl;
                break;
            }

            case 4: {
                menuStack.displayStack();
                break;
            }

            case 5: {
                cout << "Enter the food ID for the order: ";
                cin >> foodId;
                cout << "Enter the quantity: ";
                int quantity;
                cin >> quantity;

                for (int i = 0; i < quantity; ++i) {
                    orderQueue.enqueueMenu(Menu(foodId, "", "", 0.0));
                }

                cout << "Order enqueued successfully." << endl;
                break;
            }

            case 6: {
                orderQueue.dequeueMenu();
                cout << "Order dequeued successfully." << endl;
                break;
            }

            case 7: {
                orderQueue.displayQueue();
                break;
            }

            case 8: {
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
