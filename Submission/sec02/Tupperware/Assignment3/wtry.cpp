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


// instead quantity of food at the order list, make it in the menu
class Order{
    Menu m;
    int tableNum, pax;
    double totalPrice;
    int quantity;

    public:
    Order(Menu m, int tableNum, int pax, double totalPrice, int quantity)
    : m(m), tableNum(tableNum), pax(pax), quantity(quantity){}

}
class NodeQueue{
    Menu menu;

    public:
    NodeQueue *next;
    Node(Menu m){
        Menu = m;
        next = NULL;
    }

    Menu getMenu(){return Menu;}
    
}