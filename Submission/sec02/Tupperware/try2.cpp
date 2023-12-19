#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
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

void printSortedResult(Menu menuArray[]){
    for(int i = 0; i < SIZE; i++){
        cout << left;
        cout << setw(10) << menuArray[i].getFoodId() << " | " 
             << setw(21) << menuArray[i].getName() << " | " 
             << setw(10) << menuArray[i].getCategory() << " | " 
             << fixed << setprecision(2) << setw(4) << menuArray[i].getPrice() << endl;
    }
}

//selection sort
void swap(Menu &a, Menu &b){
    Menu temp = a;
    a = b;
    b = temp;
}

void FoodIdASC(Menu menuArray[]){
//    int n = sizeof(menuArray)/sizeof(menuArray[0]);
    string fI[SIZE];
    for(int last = SIZE - 1 ; last >= 1; --last){
        
        fI[last] = menuArray[last].getFoodId();
        int largestIndex = 0;
        for (int p = 1; p <= last; ++p){
            if (menuArray[p].getFoodId() > menuArray[largestIndex].getFoodId())
                largestIndex = p;
        }
        swap(menuArray[largestIndex], menuArray[last]);
    } 
    displayHeader();
    printSortedResult(menuArray);
}

void PriceASC(Menu menuArray[]){
//    int n = sizeof(menuArray)/sizeof(menuArray[0]);
    string fI[SIZE];
    for(int last = SIZE - 1 ; last >= 1; --last){
        
        fI[last] = menuArray[last].getPrice();
        int largestIndex = 0;
        for (int p = 1; p <= last; ++p){
            if (menuArray[p].getPrice() > menuArray[largestIndex].getPrice())
                largestIndex = p;
        }
        swap(menuArray[largestIndex], menuArray[last]);
    } 
    displayHeader();
    printSortedResult(menuArray);
}


    /*sort(menuArray, menuArray + SIZE, [](const Menu &a, const Menu &b){
        return a.getFoodId() < b.getFoodId();
    }); displayMenu(menuArray);*/

int main(){
//testing
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
    switch (choiceSort)
    {
    case 1 :
        FoodIdASC(menuArray);
        break;
    
    case 2 :
        PriceASC(menuArray);
        break;
    }
}
