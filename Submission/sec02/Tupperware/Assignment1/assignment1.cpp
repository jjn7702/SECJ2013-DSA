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

};

void displayHeader() {
    cout << left;
    cout << setw(5) << "NO" << " | "
         << setw(10) << "ID" << " | "
         << setw(21) << "NAME" << " | "
         << setw(13) << "TYPE" << " | "
         << fixed << "PRICE" << endl;
    cout << "---------------------------------------------------------" << endl;
}

void displayMenu(Menu menuArray[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << left;
        cout << setw(5) << (i+1) << " | "
             << setw(10) << menuArray[i].getFoodId() << " | "
             << setw(21) << menuArray[i].getName() << " | "
             << setw(13) << menuArray[i].getCategory() << " | "
             << fixed << setprecision(2) << setw(6) << menuArray[i].getPrice() << endl;
    }
}

void printSortedResult(Menu menuArray[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << left;
        cout << setw(5) << (i+1) << " | "
             << setw(10) << menuArray[i].getFoodId() << " | "
             << setw(21) << menuArray[i].getName() << " | "
             << setw(13) << menuArray[i].getCategory() << " | "
             << fixed << setprecision(2) << setw(4) << menuArray[i].getPrice() << endl;
    }
}

// SORTING(SELECTION) SECTION 
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

//SEARCHING SECTION 
void searchAndOrder(Menu menuArray[], vector<Menu>& orders) {
    string searchTerm;
    cout << "Enter the food name you want to search: ";
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    for (int i = 0; i < SIZE; ++i) {
        if (menuArray[i].getName().find(searchTerm) != string::npos) {
            if (!found) {
            displayHeader();
            cout << left;
            cout << setw(5) << (i+1) << " | " 
                 << setw(10) << menuArray[i].getFoodId() << " | " 
                 << setw(21) << menuArray[i].getName() << " | " 
                 << setw(13) << menuArray[i].getCategory() << " | " 
                 << fixed << setprecision(2) << setw(4) << menuArray[i].getPrice() << endl;
                 found = true;
            }
            char addToCartChoice;
            cout << "Do you want to add this item to the cart? (Y/N): ";
            cin >> addToCartChoice;

            if (addToCartChoice == 'Y' || addToCartChoice == 'y') {
                orders.push_back(menuArray[i]);
                cout << "Item added to cart!" << endl;
            }
        }
    }
    if (!found) {
        cout << "No matching items found.\n";
    }
}

// MAKEORDER SECTION
void makeOrder(Menu menuArray[], vector<Menu>& orders){
    int orderChoice;
    cout << "Enter the number corresponding to the menu you want to order: ";
    cin >> orderChoice;

    if (orderChoice >= 1 && orderChoice <= SIZE) {
        cout << "You ordered:\n";
        displayHeader();
        cout << left;
        cout << setw(5) << orderChoice << " | "
             << setw(10) << menuArray[orderChoice - 1].getFoodId() << " | " 
             << setw(21) << menuArray[orderChoice - 1].getName() << " | " 
             << setw(13) << menuArray[orderChoice - 1].getCategory() << " | " 
             << fixed << setprecision(2) << setw(4) << menuArray[orderChoice - 1].getPrice() << endl;

             orders.push_back(menuArray[orderChoice - 1]);
    }
    else {
        cout << "Invalid menu choice.\n";
    }
}

// CALCULATE ORDER SECTION
double calculateTotal(const vector<Menu>& orders){
    double total = 0.0;
    for (const Menu& order : orders) {
        total += order.getPrice();
    }
    return total;
}


// GENERATE RECEIPT SECTION
void generateReceipt(const vector<Menu>& orders, double total) {
    cout << "\nReceipt:\n";
    cout << "+------------------------------------------------------------+" << endl;
    cout << left;
    cout << setw(10) << "ID" 
         << setw(21) << "NAME" 
         << setw(13) << "TYPE" 
         << setw(13) << "QUANTITY" 
         << fixed << "PRICE" << endl;
    cout << "+------------------------------------------------------------+" << endl;

    for (int i = 0; i < orders.size(); ++i) {
        int count = 1;
        for (int j = i + 1; j < orders.size(); ++j) {
            if (orders[i].getFoodId() == orders[j].getFoodId()) {
                ++count;
            }
        }

        if (count > 0) {
            cout << setw(10) << orders[i].getFoodId() 
                 << setw(21) << orders[i].getName() 
                 << setw(13) << orders[i].getCategory() 
                 << setw(13) << count 
                 << fixed << setprecision(2) << setw(4) << orders[i].getPrice() << endl;
        }

        for (int j = i + 1; j < orders.size(); ++j) {
            if (orders[i].getFoodId() == orders[j].getFoodId()) {
                i = j;
            }
        }
    }

    cout << "\n+-------------------------------------------------------------+" << endl;
    cout << right << "Total amount: " << fixed << setprecision(2) << setw(4) << total << endl;
    cout << "+-------------------------------------------------------------+" << endl;
}



int main() {
    Menu menuArray[SIZE];
    char choice;
    int size = 0;
    fstream nameFile;
    string foodId, name, category;
    double price;
    bool condition = true;
    vector<Menu> orders;

        system("cls");
        cout << "WELCOME TO TUPPERWARE!" << endl;
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
            displayHeader();
            displayMenu(menuArray);

            cout << "\nDo you want to (V)iew in a new way, or (S)earch? ";
            cin >> choice;

            if (choice == 'V' || choice == 'v') {
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

                default:
                    break;
                }
            } else if (choice == 'S' || choice == 's') {
                searchAndOrder(menuArray, orders);
            } else {
                cout << "Invalid input. Please enter V or S.\n";
            }

do{
    cout << "\nDo you want to make order? (Y/N): ";
    cin >> choice;

    if (choice == 'N' || choice == 'n') 
        break;
    
    else if (choice == 'Y' || choice == 'y'){
        makeOrder(menuArray, orders);
    }
} while(true);

    if (!orders.empty()) {
        cout << "\nYour Orders:\n";
        cout << left;
        cout << setw(10) << "ID" << " | "
             << setw(21) << "NAME" << " | "
             << setw(13) << "TYPE" << " | "
             << fixed << "PRICE" << endl;
        cout << "---------------------------------------------------------" << endl;
        for (const Menu& order : orders) {
            cout << left;
            cout << setw(10) << order.getFoodId() << " | "
                 << setw(21) << order.getName() << " | "
                 << setw(13) << order.getCategory() << " | "
                 << fixed << setprecision(2) << setw(4) << order.getPrice() << endl;
        }

        double total = calculateTotal(orders); 
        cout << "\nTotal order amount: RM" << fixed << setprecision(2) << total << endl;
        generateReceipt(orders, calculateTotal(orders));
    } else {
        cout << "No orders made.\n";
    }


    return 0;
}
