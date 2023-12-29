#include <iostream>
#include <iomanip>
#include <string>
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

        // Display order details
        void displayOrder() const {
            cout << left;
            cout << setw(10) << foodId << " | "
                << setw(21) << name << " | "
                << setw(13) << category << " | "
                << fixed << setprecision(2) << setw(4) << price << endl;
    }

};

class Node {
    public:
        Menu order;
        Node* next;
        //Menu getOrder() { return order; }
        //Node(const Menu& order) : order(order), next(nullptr) {}
        Node(Menu m) : menu(m), next(nullptr){}
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
        while (current != nullptr) {
            /*Node* temp = head;
            head = head->next;
            delete temp;*/
            next = current->next;
            delete current;
            current = next;
        }
    }

    // Functions to add a new node
    // Insert at the first
    void insertFront(Menu arr) {
        Node* newHead = new Node(arr); // pass value into the first node
        if (!isEmpty())
            newHead->next = head;
        head = newHead;
    }

    // Insert at the end
    void insertEnd(Menu arr) {
        Node* temp = head;
        Node* newEnd = new Node(arr);
        if (head == nullptr)
            head = newEnd;
        else {
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newEnd;
        }
    }

    // Insert at the middle
    void insertMiddle(Menu newOne, string middle) {
        Node* newNode = new Node(newOne);
        Node* temp = head;
        int count = 1;

        while(temp->menu.getFoodId() != middle){
            temp = temp->next;
            count++;
        }

            newNode->next = temp->next;
            temp->next = newNode;
    }

    // Insert at the specified position
    void insertSpecified(Menu newOne, string specified) {
        Node* newNode = new Node(newOne);
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->menu.getFoodId() != specified) {
            prev = temp;
            temp = temp->next;
        }

            newNode->next = temp->next;
            prev->next = newNode;
    }

    // Function to delete a node
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
    }

    //Function to find node by name
    Node* findNodeName(const string& searchName) const {
        Node* current = head;
        while (current != nullptr && (current->order.getName() != searchName)) {
                current = current->next;
            }
        return current;
    }

    //Function to find node by category
    Node* findNodeCategory(const string& searchCategory) const {
        Node* current = head;
        Node* foundNode = nullptr;

        while (current != nullptr) {
            if (current->order.getCategory() == searchCategory) {
                if (foundNode == nullptr) {
                    foundNode = current;
                }
                else {
                    current->order.displayOrder();
                }
            }
            current = current->next;
        }
        return foundNode;
    }

    //Function to find node by foodId
    Node* findNodeFoodId(const string& searchFoodId) const {
        Node* current = head;
        while (current != nullptr && (current->order.getFoodId() != searchFoodId)) {
                current = current->next;
            }
        return current;
    }
         

    /*// Function to sort the list (using bubble sort as an example)
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
    }*/

    // Function to display all nodes
    void displayNodes() const {
        system("cls");
        cout << left;
        cout << setw(10) << "ID" << " | "
             << setw(21) << "NAME" << " | "
             << setw(13) << "TYPE" << " | "
             << fixed << "PRICE" << endl;
        cout << "---------------------------------------------------------" << endl;
        Node* current = head;
        while (current != nullptr) {
            current->order.displayOrder();
            current = current->next;
        }
    }
};

void displayHeader() {
    cout << left;
    cout << setw(10) << "ID" << " | "
         << setw(21) << "NAME" << " | "
         << setw(13) << "TYPE" << " | "
         << fixed << "PRICE" << endl;
    cout << "---------------------------------------------------------" << endl;
}

int main() {
    char choice;
    int opt, size = 0;
    string foodId, name, category;
    double price;
    OrderList orderList;

    system("cls");
    cout << "WELCOME TO TUPPERWARE!" << endl;

    ifstream nameFile("menu.txt");

    if (!nameFile.is_open()) {
        cout << "ERROR: Cannot open file." << endl;
        return 1;
    }

    int menuread = 0;

    while (!nameFile.eof()) {
        getline(nameFile, foodId, ',');
        getline(nameFile, name, ',');
        getline(nameFile, category, ',');
        nameFile >> price;
        nameFile.ignore();
        Menu newmenu;
        newmenu.setFoodId(foodId);
        newmenu.setName(name);
        newmenu.setCategory(category);
        newmenu.setPrice(price);
        orderList.addNode(newmenu);

        menuread++;
    }

    nameFile.close();

    do {
        cout << endl;
        cout << setw(5) << "[1] Add Menu" << endl;
        cout << setw(5) << "[2] Delete Menu" << endl;
        cout << setw(5) << "[3] Find Menu" << endl;
        cout << setw(5) << "[4] Sort Menu" << endl;
        cout << setw(5) << "[5] Display Menu" << endl;
        cout << setw(5) << "[6] Exit" << endl;
        cout << "\nEnter your choice: " ;
        cin >> opt;

        switch (opt) {
            case 1:

            case 2:

            case 3:
            {
                cout << "\nDo you want to seach by (N)ame, (C)ategory or (F)oodId?: ";
                cin >> choice;

                if (choice == 'N' || choice == 'n') {
                    string searchName; 
                    cout << "\nEnter name to find: ";
                    cin.ignore();
                    getline(cin, searchName);
                    Node* foundNode = orderList.findNodeName(searchName);

                    if (foundNode != nullptr) {
                        cout << "\nNode Found:\n";
                        displayHeader();
                        foundNode->order.displayOrder();
                    } else {
                        cout << "\nNode Not Found.\n";
                    }
                }

                else if (choice == 'C' || choice == 'c') {
                    string searchCategory;
                    cout << "\nEnter category to find: ";
                    cin.ignore();
                    getline(cin, searchCategory);
                    Node* foundNode = orderList.findNodeCategory(searchCategory);

                    if (foundNode == nullptr) {
                        cout << "\nNode Not Found.\n";
                    }
                }

                else if (choice == 'F' || choice == 'f') {
                    string searchFoodId; 
                    cout << "\nEnter food id to find: ";
                    cin.ignore();
                    getline(cin, searchFoodId);
                    Node* foundNode = orderList.findNodeFoodId(searchFoodId);

                    if (foundNode != nullptr) {
                        cout << "\nNode Found:\n";
                        displayHeader();
                        foundNode->order.displayOrder();
                    } else {
                        cout << "\nNode Not Found.\n";
                    }
                }

                break;
            }

            case 4:

            case 5:
            {
                system("cls");
                orderList.displayNodes();
                break;
            }

            case 6:
            {
                cout << "Thank you, see you again!" << endl;
                break;
            }
        }

    } while (opt != 6);


    /*// Example usage:
    orderList.addNode(menuArray[0], 0);
    orderList.addNode(menuArray[1], 1);
    orderList.addNode(menuArray[2], 1);

    cout << "\nOriginal List:\n";
    orderList.displayNodes();*/

    //orderList.sortList();

    //cout << "\nAfter sorting:\n";
    //orderList.displayNodes();

    return 0;
}
