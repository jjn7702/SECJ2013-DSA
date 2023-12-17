#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define SIZE 30
using namespace std;


class Menu{
    private:
        string foodId;
        string name;
        string category;
        double price;

    public:
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
};

void displayMenu(Menu menuArray[], int size) {
    for(int i = 0; i < size; i++) {
        cout << left;
        cout << setw(10) <<menuArray[i].getFoodId() << " | " 
             << setw(21) << menuArray[i].getName() << " | " 
             << setw(10) <<menuArray[i].getCategory() << " | " 
             << fixed << setprecision(2) << setw(4) <<menuArray[i].getPrice() << endl;
    }
}

int main(){

//testing
    Menu menuArray[] = {Menu("WE05", "Thai Pasta", "Western", 12.00), 
                   Menu("WE06", "Chicken Pasta", "Western", 12.00), 
                   Menu("WE07", "Seafood Pasta", "Western", 12.00), 
                   Menu("WE08", "Chicken Lasagna", "Western", 10.00), 
                   Menu("WE09", "Beef Lasagna", "Western", 10.50), 
                   Menu("DE01", "Ice Cream", "Dessert", 1.50), 
                   Menu("DE02", "Cendol" ,"Dessert",2.00)};

    displayMenu(menuArray, 7);                 
    
    cout << endl << endl;

    int choiceSort;
    cout << "1 - ALPHABET ORDER | 2 - price => ";
    cin >> choiceSort;
}
