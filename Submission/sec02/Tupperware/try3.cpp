#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#define SIZE 27

using namespace std;


class Menu{
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
};

void displayHeader(){
        cout << left;
        cout << setw(10) << "ID" << " | " 
             << setw(21) << "NAME" << " | " 
             << setw(13) << "TYPE" << " | " 
             << fixed << "PRICE" << endl;
        cout <<"---------------------------------------------------------" << endl;
}

void displayMenu(Menu menuArray[]) {
    for(int i = 0; i < SIZE; i++) {
        cout << left;
        cout << setw(10) << menuArray[i].getFoodId() << " | " 
             << setw(21) << menuArray[i].getName() << " | " 
             << setw(13) << menuArray[i].getCategory() << " | " 
             << fixed << setprecision(2) << setw(6) << menuArray[i].getPrice() << endl;
    }
}

//display food id in ASC
void swap(Menu &a, Menu &b){
    Menu temp = a;
    a = b;
    b = temp;
}

void FoodIdASC(Menu menuArray[]){
    sort(menuArray, menuArray + SIZE, [](const Menu &a, const Menu &b){
        return a.getFoodId() < b.getFoodId();
    }); 
	displayMenu(menuArray);
}

void searchByName(Menu menuArray[], const string& searchTerm) {
    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (menuArray[i].getName().find(searchTerm) != menuArray[i].getName().length()) {
            if (!found) {
        displayHeader();
        found = true;
    }
    cout << left;
    cout << setw(10) << menuArray[i].getFoodId() << " | "
        << setw(21) << menuArray[i].getName() << " | "
        << setw(13) << menuArray[i].getCategory() << " | "
        << fixed << setprecision(2) << setw(6) << menuArray[i].getPrice() << endl;
}
    }

    if (!found) {
        cout << "No items found with the given name." << endl;
    }
}

int main(){
    Menu menuArray[SIZE];
    char choice;
    int size = 0;
    fstream nameFile;
    string input;
    string foodId, name, category;
    double price;

    system("cls");
    cout << "WELCOME TO TUPPERWARE!" << endl;
    cout << "View Menu? : ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        nameFile.open("menu.txt", ios::in);

        if (!nameFile){
            cout << "ERROR: Cannot open file." << endl;
            return 0;
        }

        //getline(nameFile, input);
        //menu.displayMenu();

        while (!nameFile.eof() && size < SIZE){
            //cout << input << endl;
            //getline(nameFile, input);
            getline(nameFile, foodId, ',');
            //cout << foodId ;
            getline(nameFile, name, ',');
            //cout << foodName;
            getline(nameFile, category, ',');
            nameFile >> price;
            nameFile.ignore();

            menuArray[size++] = Menu(foodId, name, category, price);
        }
        nameFile.close();
        displayHeader();
        displayMenu(menuArray);

    }
    
        cout << "\nDo you want to (V)iew in a new way, or (S)earch? ";
        cin >> choice;

        if (choice == 'V' || choice == 'v') {
            // View in a new way (sorting)
            cout << "Sort by (F)ood ID, (C)ategory, or (P)rice? ";
            int choiceSort;
            cout << "1 - ALPHABET ORDER | 2 - price => ";
            cin >> choiceSort;
            switch (choiceSort)
            {
                case 1 :
                FoodIdASC(menuArray);
                break;
    
                case 2 :
                    break;
                }

        /*} else if (choice == 'S' || choice == 's') {
            // Searching for a specific food
            string targetFoodId;
            cout << "Enter the Food ID you want to search: ";
            cin >> targetFoodId;

            if (menu.searchByFoodId(targetFoodId)) {
                cout << "Food ID found!\n";
            } else {
                cout << "Food ID not found.\n";
            }
        }*/
        }
    

    return 0;

//testing
    /*Menu menuArray[] = {Menu("WE05", "Thai Pasta", "Western", 12.00), 
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
        break;
    }*/
}
