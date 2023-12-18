#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Food {
    string foodId;
    string foodName;
    string category;
    double price;
};

class Menu {
private:
    Food menuArray[50];
    int menuSize;

public:
    Menu() : menuSize(0) {}

    /*void loadMenuFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        while (file >> menuArray[menuSize].foodId >> menuArray[menuSize].foodName
                      >> menuArray[menuSize].category >> menuArray[menuSize].price) {
            ++menuSize;
            if (menuSize >= 50) {
                std::cerr << "Warning: Maximum menu size reached." << std::endl;
                break;
            }
        }

        file.close();
        std::cout << "Menu loaded successfully. Size: " << menuSize << std::endl;
    }*/

    void displayMenu() const {
        cout << "Food ID | Food Name | Category | Price\n";
        cout << "------------------------------------------\n";
        for (int i = 0; i < menuSize; ++i) {
            cout << menuArray[i].foodId << " | " << menuArray[i].foodName << " | "
                << menuArray[i].category << " | " << menuArray[i].price << '\n';
        }
    }

    // Bubble sort
    void sortByFoodId() {
        for (int i = 0; i < menuSize - 1; ++i) {
            for (int j = 0; j < menuSize - i - 1; ++j) {
                if (menuArray[j].foodId > menuArray[j + 1].foodId) {
                    swap(menuArray[j], menuArray[j + 1]);
                }
            }
        }
    }

    // Manual search
    bool searchByFoodId(const std::string& targetFoodId) const {
        for (int i = 0; i < menuSize; ++i) {
            if (menuArray[i].foodId == targetFoodId) {
                return true;
            }
        }
        return false;
    }
};

class Order {
private:
    string foodId;
    int amount;

public:
    Order(const string& id, int count) : foodId(id), amount(count) {}

    // Getter functions
    string getFoodId() const {
        return foodId;
    }

    int getAmount() const {
        return amount;
    }
};

int main() {
    // Display the menu initially
    Menu menu;
    fstream nameFile;
    string input;
    string foodId, foodName, category;
    double price;
    //menu.loadMenuFromFile("menu.txt");

    nameFile.open("menu.txt", ios::in);

    if (!nameFile){
        cout << "ERROR: Cannot open file." << endl;
        return 0;
    }

    getline(nameFile, input);
    //menu.displayMenu();

    while (!nameFile.eof()){
        //cout << input << endl;
        //getline(nameFile, input);
        getline(nameFile, foodId, ',');
        //cout << foodId ;
        getline(nameFile, foodName, ',');
        //cout << foodName;
        getline(nameFile, category, ',');
        nameFile >> price;
    }


    // Ordering process
    char choice;
    do {
        cout << "\nDo you want to (C)hoose, (V)iew in a new way, or (S)earch? ";
        cin >> choice;

        if (choice == 'C' || choice == 'c') {
            // Choose order
            string chosenFoodId;
            int amount;
            cout << "Enter the Food ID you want to order: ";
            cin >> chosenFoodId;
            cout << "Enter the amount: ";
            cin >> amount;

            // Create an Order object and save it
            Order order(chosenFoodId, amount);

            // Save the order to a file or another data structure
            // ...

        } else if (choice == 'V' || choice == 'v') {
            // View in a new way (sorting)
            cout << "Sort by (F)ood ID, (C)ategory, or (P)rice? ";
            cin >> choice;
            if (choice == 'F' || choice == 'f') {
                menu.sortByFoodId();
            }

            menu.displayMenu();

        } else if (choice == 'S' || choice == 's') {
            // Searching for a specific food
            string targetFoodId;
            cout << "Enter the Food ID you want to search: ";
            cin >> targetFoodId;

            if (menu.searchByFoodId(targetFoodId)) {
                cout << "Food ID found!\n";
            } else {
                cout << "Food ID not found.\n";
            }
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}