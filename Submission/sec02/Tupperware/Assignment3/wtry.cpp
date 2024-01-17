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


void customerView(){
    int opt, quantity, tableNum;
    char choice;
    string foodId;
    Menu selectedMenu;
    vector<Menu> menuList;  
    queueOrder order;

    NodeQueue *temp = nullptr;  
    bool validFoodId = false;
    

        cout << "Welcome to the customer View\n";
        cout << "[1]Make order\n";
        cout << "[2]View current queueing order\n";
        cout << "[3]Cancel order\n";
        cout << "Please make your choice\n";
        cout << "Choice : ";
        cin >> opt;

        switch (opt)
        {
        case 1 :
            cout << "What is your table number ? : ";
            cin >> tableNum; 

            if((tableNum < 0  && tableNum > 10) || (tableNum != static_cast<int>(tableNum)))
                cout << "The table number you entered is invalid";

            cout << "Pick your order\n";
            cout << "foodID : ";
            cin.ignore();
            getline(cin, foodId);
            cout << "Quantity : ";
            cin >> quantity;

            // to check if the foodID existed.
            validFoodId = false;
            temp = order.front;

            while (temp) {
                Order currentOrder = temp->getOrder();
                Menu currentMenu = currentOrder.getMenu();

                if (currentMenu.getFoodId() == foodId) {
                    validFoodId = true;
                }
                temp = temp->next;
            }

            if(validFoodId == false)
                cout << "Sorry, the food is not existed";
            else  {
                order.enQueue(Order(selectedMenu, quantity));
            }

            break;

        case 2:
            cout << "Viewing current queueing orders:\n";
            order.printOrder();
            break;

        default:
            break;

        }


}

    

int main() {

    string staffID;

    cout << "Welcome to Tupperware!!\n\n";
    cout << "If you are a staff, please enter your staff ID : ";
    getline(cin, staffID);

    checkStaff(staffID);

    customerView();
    return 0;

}
