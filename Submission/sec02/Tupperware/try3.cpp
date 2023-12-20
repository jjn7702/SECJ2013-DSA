#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
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

    void makeOrder(Menu menuArray[], vector<Menu>& orders) {
        int orderChoice;
        cout << "Enter the number corresponding to the menu you want to order: ";
        cin >> orderChoice;

        if (orderChoice >= 1 && orderChoice <= SIZE) {
            // Display the ordered item
            displayHeader();
            cout << left;
            cout << setw(10) << menuArray[orderChoice - 1].getFoodId() << " | "
                 << setw(21) << menuArray[orderChoice - 1].getName() << " | "
                 << setw(13) << menuArray[orderChoice - 1].getCategory() << " | "
                 << fixed << setprecision(2) << setw(4) << menuArray[orderChoice - 1].getPrice() << endl;

            // Add the ordered item to the cart
            orders.push_back(menuArray[orderChoice - 1]);
        } else {
            cout << "Invalid menu choice.\n";
        }
    }
};

void searchAndOrder(Menu menuArray[], vector<Menu>& orders) {
    string searchTerm;
    cout << "Enter the food name you want to search: ";
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    for (int i = 0; i < SIZE; ++i) {
        if (menuArray[i].getName().find(searchTerm) != string::npos) {
            if (!found) {
                // Display the header for searched items
                cout << left;
                cout << setw(10) << "ID" << " | "
                     << fixed << "PRICE" << endl;
                cout << "---------------------" << endl;
                found = true;
            }
            // Display the found item
            cout << left;
            cout << setw(10) << menuArray[i].getFoodId() << " | "
                 << fixed << setprecision(2) << setw(6) << menuArray[i].getPrice() << endl;

            // Ask the user if they want to add the order to the cart
            char addToCartChoice;
            cout << "Do you want to add this item to the cart? (Y/N): ";
            cin >> addToCartChoice;

            if (addToCartChoice == 'Y' || addToCartChoice == 'y') {
                // Add the ordered item to the cart
                orders.push_back(menuArray[i]);
                cout << "Item added to cart!" << endl;
            }
        }
    }
    if (!found) {
        cout << "No matching items found.\n";
    }
}

double calculateTotal(const vector<Menu>& orders) {
    double total = 0.0;
    for (const Menu& order : orders) {
        total += order.getPrice();
    }
    return total;
}

int main() {
    Menu menuArray[SIZE];
    char choice;
    int size = 0;
    fstream nameFile;
    string foodId, name, category;
    double price;
    vector<Menu> orders;

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
                nameFile >> price;
                nameFile.ignore();

                menuArray[size++] = Menu(foodId, name, category, price);
            }
            nameFile.close();

            Menu menu;
            menu.displayHeader();
            menu.displayMenu(menuArray);

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
                    menu.FoodIdASC(menuArray);
                    break;

                case 2:
                    menu.PriceASC(menuArray);
                    break;
                }
            } else if (choice == 'S' || choice == 's') {
                // Searching for a specific food and ordering
                searchAndOrder(menuArray, orders);
            } else {
                cout << "Invalid input. Please enter V or S.\n";
            }
        } else {
            cout << "Invalid input. Please enter Y or N.\n";
        }

    } while (true);

    // Check if any order is made
    if (!orders.empty()) {
        cout << "\nYour Orders:\n";
        menuArray[0].displayHeader();
        for (const Menu& order : orders) {
            cout << left;
            cout << setw(10) << order.getFoodId() << " | "
                 << setw(21) << order.getName() << " | "
                 << setw(13) << order.getCategory() << " | "
                 << fixed << setprecision(2) << setw(4) << order.getPrice() << endl;
        }

        double total = calculateTotal(orders); 
        cout << "\nTotal order amount: RM" << fixed << setprecision(2) << total << endl;
    } else {
        cout << "No orders made.\n";
    }

    return 0;
}
