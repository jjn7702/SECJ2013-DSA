// try to do queue link 
#include <iostream>
#include <iomanip>
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
    Order(Menu menu, int tableNum, int pax, double totalPrice, int quantity)
    : menu(menu), tableNum(tableNum), pax(pax), quantity(quantity) {}

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

        void enQueue(Menu menu){
            NodeQueue *newOrder = new NodeQueue(order);

            if (isEmpty()){
                front = newOrder;
                back = newOrder;
            } else {
                back->next = newOrder;
                back = newOrder;
            }
        }

        void printOrder(){
            //perlukan ke? 
            if (isEmpty()) {
                cout << "There is no other order pending\n";
            } else {
                NodeQueue *temp = front;

                while (temp) {
                    cout << temp->getTableNum() << " ";
                    temp = temp->next;
                }
            }
        }

};
