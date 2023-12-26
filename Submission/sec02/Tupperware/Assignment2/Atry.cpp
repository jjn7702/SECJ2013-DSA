#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
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

class Node {
    public:
        Menu order;
        Node* next;

        Node(const Menu& order) : order(order), next(nullptr) {}
};

class OrderList {
private:
    Node* head;

public:
    OrderList() : head(nullptr) {}

    ~OrderList() {
        // Implement destructor to free allocated memory
        Node *current = head;
        Node *next;
        while (head != nullptr) {
            /*Node* temp = head;
            head = head->next;
            delete temp;*/
            next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to add a new node
    void addNode(const Menu& order, int position) {
        Node* newNode = new Node(order);

        if (head == nullptr || position == 0) {
            // Insert at the beginning
            newNode->next = head;
            head = newNode;
        } else {
            // Insert at the middle or end
            Node* current = head;
            for (int i = 0; i < position - 1 && current->next != nullptr; ++i) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    /*// Function to delete a node
    void deleteNode(int position) {
        if (head == nullptr) {
            return; // List is empty
        }

        Node* temp = head;

        if (position == 0) {
            // Delete the first node
            head = head->next;
        } else {
            // Delete a node in the middle or at the end
            Node* current = head;
            for (int i = 0; i < position - 1 && current->next != nullptr; ++i) {
                current = current->next;
            }

            if (current->next != nullptr) {
                temp = current->next;
                current->next = current->next->next;
            }
        }

        delete temp;
    }*/

    /*// Function to find a node based on a search key
    Node* findNode(const string& searchKey) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->order.getName() == searchKey) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Node not found
    }*/

    //choice 2
    /*Node* findNode(const string& searchKey) {
        Node* currNode = head;
        //int currIndex = 1;
        while (currNode && currNode->order.getName() != searchKey) {
            currNode = currNode->next;
        //    currIndex++;
        }
        return currNode;
        /*if (currNode)
            return currIndex;
        else 
            return 0;
    }*/

    Node* findNode(const string& searchKey) const {
        Node* current = head;
        while (current != nullptr && (current->order.getName() != searchKey)) {
                current = current->next;
            }
        return current;
    }
         

    // Function to sort the list (using bubble sort as an example)
    void sortList() {
        if (head == nullptr || head->next == nullptr) {
            return; // List is empty or has only one node
        }

        bool swapped;
        Node* last = nullptr;

        do {
            swapped = false;
            Node* current = head;

            while (current->next != last) {
                if (current->order.getName() > current->next->order.getName()) {
                    swap(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);
    }

    // Function to display all nodes
    void displayNodes() const {
        Node* current = head;
        while (current != nullptr) {
            displayOrder(current->order);
            current = current->next;
        }
    }

    // Display order details
    void displayOrder(const Menu& order) const {
        cout << left;
        cout << setw(10) << order.getFoodId() << " | "
             << setw(21) << order.getName() << " | "
             << setw(13) << order.getCategory() << " | "
             << fixed << setprecision(2) << setw(4) << order.getPrice() << endl;
    }
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

int main() {
    // ... (Menu class and other functions remain unchanged)
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

            int menuread = 0;

            while (!nameFile.eof() && size < SIZE) {
                getline(nameFile, foodId, ',');
                getline(nameFile, name, ',');
                getline(nameFile, category, ',');
                nameFile >> price;
                nameFile.ignore();

                menuArray[size++] = Menu(foodId, name, category, price);
                menuread++;
            }
            cout << "Number of menu: " << menuread << endl;
            nameFile.close();
            displayHeader();
            displayMenu(menuArray);
            
    OrderList orderList;

    // Example usage:
    orderList.addNode(menuArray[0], 0);
    orderList.addNode(menuArray[1], 1);
    orderList.addNode(menuArray[2], 1);

    cout << "\nOriginal List:\n";
    orderList.displayNodes();

    string searchKey; // Replace with the actual food name you want to search for
    cout << "\nFinding a node: ";
    cin.ignore();
    getline(cin, searchKey);
    Node* foundNode = orderList.findNode(searchKey);

    if (foundNode != nullptr) {
        cout << "\nNode Found:\n";
        orderList.displayOrder(foundNode->order);
    } else {
        cout << "\nNode Not Found.\n";
    }

    //orderList.sortList();

    //cout << "\nAfter sorting:\n";
    //orderList.displayNodes();

    return 0;
}
