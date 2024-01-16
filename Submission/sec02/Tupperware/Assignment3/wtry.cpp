// try to do queue link 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector> 
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

    void displayMenu() const {
        cout << left;
        cout << setw(10) << foodId << " | "
             << setw(21) << name << " | "
             << setw(13) << category << " | "
             << fixed << setprecision(2) << setw(6) << price << endl;
    }
};


class Order{
    Menu menu;
    int tableNum, pax;
    double totalPrice;
    int quantity;


    public:
    //default counter
    Order(Menu menu, int tableNum, int pax, double totalPrice, int quantity)
    : menu(menu), tableNum(tableNum), pax(pax), quantity(quantity) {}

    //order only counter
    Order(Menu menu, int quantity)
    : menu(menu), quantity(quantity) {}

    Menu getMenu(){return menu;}
    int getTableNum(){return tableNum;}
    int getPax(){return pax;}
    double gettotalPrice(){return totalPrice;}
    int getQuantity(){return quantity;}
};



class NodeQueue{
    Order order;

    public:
    NodeQueue *next;
    NodeQueue(Order o) : order(o), next(NULL) { }

    Order getOrder(){return order;}
};

class queueOrder{
    public:
        NodeQueue *back, *front;

        queueOrder(){
            front = NULL;
            back = NULL;
        }

        //indicates that the queue is empty
        bool isEmpty(){
            return ((front == NULL) && (back == NULL));
        }

        void enQueue(Order order){
            NodeQueue *newOrder = new NodeQueue(order);

            if (isEmpty()){
                front = newOrder;
                back = newOrder;
            } else {
                back->next = newOrder;
                back = newOrder;
            }
        }

        void deQueue(){
        NodeQueue *delOrder = front;
        if(isEmpty())
            cout << "There is no other order pending\n";
        else{
            if(front != back){
            front = front->next;
            delOrder->next = NULL; 
            delete delOrder;
                }
            else{
                front = NULL;
                back = NULL;
                }
            }
        }

        void printOrder() {
            if (isEmpty()) {
                cout << "There is no other order pending\n";
            } else {
                NodeQueue *temp = front;

            while (temp) {
                Order currentOrder = temp->getOrder();
                Menu currentMenu = currentOrder.getMenu();

                cout << "Menu: ";
                currentMenu.displayMenu();
                cout << "Pax: " << currentOrder.getPax() << " | ";
                cout << "Table Number: " << currentOrder.getTableNum() << " | ";
                cout << "Quantity: " << currentOrder.getQuantity() << "\n";

                temp = temp->next;
        }
    }
}

};

int main() {

int opt;
char choice;
vector<Menu> menuList;  // Use a vector to store multiple Menu objects
string foodId;
int quantitiy, tableNum;
Menu selectedMenu;
queueOrder orderQueue;

// Order order;

do {

} while (choice == 'y' || choice == 'Y');
// ape2 code utk stack 

switch (opt)
{
case 1 :
        cout << "Welcome to the customer View\n";
        cout << "[1]Make order\n";
        cout << "[2]View current queueing order\n";
        cout << "[3]Cancel order\n";
        cout << "Please make your choice\n";
        cout << "Choice : ";
        cin >> opt;


        // Populate the menuList with Menu objects
        menuList.push_back(Menu("F001", "Burger", "Fast Food", 5.99));
        menuList.push_back(Menu("F002", "Pizza", "Fast Food", 8.99));
        // Add more menu items if needed


        cout << "What is your table number ? : ";
        cin >> tableNum; 

        cout << endl;

        cout << "Pick your order\n";
        cout << "foodID : ";
        cin.ignore();
        getline(cin, foodId);
        cout << "Quantitiy : ";
        cin >> quantitiy;


        for (const Menu& menu : menuList) {
            if (foodId == menu.getFoodId()) {
                selectedMenu = menu;
                break;
            }
        }

        // Check if the foodId is valid
        if (selectedMenu.getFoodId().empty()) {
            cout << "Invalid food ID\n";
            return 1; // Exit with an error code
        }

        Order order(selectedMenu, quantitiy);


        orderQueue.enQueue(order);

        cout << "Current Orders:\n";
        orderQueue.printOrder();

        orderQueue.deQueue();

        cout << "\nOrders after dequeue:\n";
        orderQueue.printOrder();

    break;

default:
    break;
}

    return 0;
}
