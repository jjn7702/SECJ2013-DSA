#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define SIZE 27
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
};

void displayHeader() {
    cout << left;
    cout << setw(10) << "ID" << " | "
         << setw(21) << "NAME" << " | "
         << setw(13) << "TYPE" << " | "
         << fixed << "PRICE" << endl;
    cout << "---------------------------------------------------------" << endl;
}

void displayMenu(Menu menuArray[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << left;
        cout << setw(10) << menuArray[i].getFoodId() << " | "
             << setw(21) << menuArray[i].getName() << " | "
             << setw(13) << menuArray[i].getCategory() << " | "
             << fixed << setprecision(2) << setw(6) << menuArray[i].getPrice() << endl;
    }
}

void printSortedResult(Menu menuArray[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << left;
        cout << setw(10) << menuArray[i].getFoodId() << " | "
             << setw(21) << menuArray[i].getName() << " | "
             << setw(13) << menuArray[i].getCategory() << " | "
             << fixed << setprecision(2) << setw(4) << menuArray[i].getPrice() << endl;
    }
}

// Selection sort
void swap(Menu& a, Menu& b) {
    Menu temp = a;
    a = b;
    b = temp;
}

void FoodIdASC(Menu menuArray[]) {
    string fI[SIZE];
    for (int last = SIZE - 1; last >= 1; --last) {

        fI[last] = menuArray[last].getFoodId();
        int largestIndex = 0;
        for (int p = 1; p <= last; ++p) {
            if (menuArray[p].getFoodId() > menuArray[largestIndex].getFoodId())
                largestIndex = p;
        }
        swap(menuArray[largestIndex], menuArray[last]);
    }
    displayHeader();
    printSortedResult(menuArray);
}

void PriceASC(Menu menuArray[]) {
    string fI[SIZE];
    for (int last = SIZE - 1; last >= 1; --last) {

        fI[last] = menuArray[last].getPrice();
        int largestIndex = 0;
        for (int p = 1; p <= last; ++p) {
            if (menuArray[p].getPrice() > menuArray[largestIndex].getPrice())
                largestIndex = p;
        }
        swap(menuArray[largestIndex], menuArray[last]);
    }
    displayHeader();
    printSortedResult(menuArray);
}

void makeOrder(Menu menuArray[]) {
    int orderChoice;
    cout << "Enter the number corresponding to the menu you want to order: ";
    cin >> orderChoice;

    if (orderChoice >= 1 && orderChoice <= SIZE) {
        cout << "You ordered:\n";
        displayHeader();
        cout << left;
        cout << setw(10) << menuArray[orderChoice - 1].getFoodId() << " | "
             << setw(21) << menuArray[orderChoice - 1].getName() << " | "
             << setw(13) << menuArray[orderChoice - 1].getCategory() << " | "
             << fixed << setprecision(2) << setw(4) << menuArray[orderChoice - 1].getPrice() << endl;
    } else {
        cout << "Invalid menu choice.\n";
    }
}

void searchAndOrder(Menu menuArray[]) {
    string searchTerm;
    cout << "Enter the food name you want to search: ";
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    for (int i = 0; i < SIZE; ++i) {
        if (menuArray[i].getName().find(searchTerm) != string::npos) {
            if (!found) {
                cout << left;
                cout << setw(10) << "ID" << " | "
                    << fixed << "PRICE" << endl;
                cout << "---------------------" << endl;
                found = true;
            }
            cout << left;
            cout << setw(10) << menuArray[i].getFoodId() << " | "
                << fixed << setprecision(2) << setw(6) << menuArray[i].getPrice() << endl;

            // Ask the user if they want to add the order to the cart
            char addToCartChoice;
            cout << "Do you want to add this item to the cart? (Y/N): ";
            cin >> addToCartChoice;

            if (addToCartChoice == 'Y' || addToCartChoice == 'y') {
                // Add code to handle adding to the cart
                cout << "Item added to cart!" << endl;
                // Back to the main menu
                return;
            }
        }
    }
    if (!found) {
        cout << "No matching items found.\n";
    }
}

int main() {
    Menu menuArray[SIZE];
    char choice;
    int size = 0;
    fstream nameFile;
    string foodId, name, category;
    double price;
    bool condition = true;

    do {
        system("cls");
        cout << "WELCOME TO TUPPERWARE!" << endl;
        cout << "View Menu? Y => yes | N => no: ";
        cin >> choice;

        if (choice == 'N' || choice == 'n')
            break;

        else if (choice == 'Y' || choice == 'y') {
            nameFile.open("menu.txt", ios::in);

            if (!nameFile) {
                cout << "ERROR: Cannot open file." << endl;
                return 0;
            }

            while (!nameFile.eof() && size < SIZE) {
                getline(nameFile, foodId, ',');
                getline(nameFile, name, ',');
                getline(nameFile, category, ',');
                nameFile >> price ;
                nameFile.ignore();

                menuArray[size++] = Menu(foodId, name, category, price);
            }
            nameFile.close();
            displayHeader();
            displayMenu(menuArray);

            cout << "\nDo you want to (V)iew in a new way, or (S)earch? ";
            cin >> choice;

            if (choice == 'V' || choice == 'v') {
                // View in a new way (sorting)
                cout << "Sort by Food ID or Price? ";
                int choiceSort;
                cout << "1 - ALPHABET ORDER | 2 - PRICE => ";
                cin >> choiceSort;
                switch (choiceSort) {
                case 1:
                    FoodIdASC(menuArray);
                    break;

                case 2:
                    PriceASC(menuArray);
                    break;
                }
                condition = false ;
            } else if (choice == 'S' || choice == 's') {
                // Searching for a specific food and ordering
                searchAndOrder(menuArray);
            } else {
                cout << "Invalid input. Please enter V or S.\n";
            }
        } else {
            cout << "Invalid input. Please enter Y or N.\n";
        }

    } while (condition == true);
    
    do{
    cout << "Do you want to make order? (Y/N): ";
    cin >> choice;

    if (choice == 'N' || choice == 'n') 
        main();
    
    else if (choice == 'Y' || choice == 'y'){
        makeOrder(menuArray);
    }
} while(true);

    return 0;
}
