#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define SIZE 7
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

void displayHeader(){
        cout << left;
        cout << setw(10) << "ID" << " | " 
             << setw(21) << "NAME" << " | " 
             << setw(10) << "TYPE" << " | " 
             << fixed << "PRICE" << endl;
        cout <<"---------------------------------------------------------" << endl;
}

void displayMenu(Menu menuArray[]) {
    for(int i = 0; i < SIZE; i++) {
        cout << left;
        cout << setw(10) << menuArray[i].getFoodId() << " | " 
             << setw(21) << menuArray[i].getName() << " | " 
             << setw(10) << menuArray[i].getCategory() << " | " 
             << fixed << setprecision(2) << setw(4) << menuArray[i].getPrice() << endl;
    }
}

//display food id in ASC
void FoodIdASC(Menu menuArray[]){
    Menu newArray[]{NULL, NULL, NULL, 0};
    for(int i = 0; i < SIZE - 1; i++){
        for(int j = 0; j < i - 1; j++){
            if(menuArray[j].getFoodId() > menuArray[j + 1].getFoodId()){
                swap(menuArray[j], menuArray[j + 1]);
            } 
        }  newArray[i] = menuArray[i];
    }  displayMenu(newArray);
}

void swapArrays(Menu menuArray[], Menu newArray[]){
    for(int i = 0; i < SIZE; i++){
        newArray[i] = menuArray[i];
    }
}

int main(){
    Menu menuArray[] = {Menu("WE05", "Thai Pasta", "Western", 12.00), 
                   Menu("WE06", "Chicken Pasta", "Western", 12.00), 
                   Menu("WE07", "Seafood Pasta", "Western", 12.00), 
                   Menu("WE08", "Chicken Lasagna", "Western", 10.00), 
                   Menu("WE09", "Beef Lasagna", "Western", 10.50), 
                   Menu("DE01", "Ice Cream", "Dessert", 1.50), 
                   Menu("DE02", "Cendol" ,"Dessert",2.00)};

    displayHeader();
    displayMenu(menuArray);                 
    
    cout << endl << endl;

    int choiceSort;
    cout << "1 - ALPHABET ORDER | 2 - price => ";
    cin >> choiceSort;

    if (choiceSort == 1){FoodIdASC(menuArray); }
    else if (choiceSort == 2);
}
