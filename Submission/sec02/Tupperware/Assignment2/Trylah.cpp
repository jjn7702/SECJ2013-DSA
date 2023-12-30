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

        // Display order details
        void displayMenu() const {
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
        Node(Menu m) : order(m), next(nullptr){}
};

class OrderList {
private:
    Node* head;

public:
    OrderList() : head(nullptr) {}
    bool isEmpty() {return head == NULL;}

    ~OrderList() {
        // Implement destructor to free allocated memory
        Node *current = head;
        Node *next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    // Functions to add a new node
    // Insert at the front
    void insertFront(OrderList& orderList, Menu arr) {
        Node* newHead = new Node(arr); // pass value into the first node
        if (!orderList.isEmpty())
            newHead->next = orderList.head;
        orderList.head = newHead;
    }

    // Insert at the end
    void insertEnd(OrderList& orderList, Menu arr) {
        Node* temp = orderList.head;
        Node* newEnd = new Node(arr);
        if (orderList.head == nullptr)
            orderList.head = newEnd;
        else {
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newEnd;
        }
    }

    // Insert at the middle
    void insertMiddle(OrderList& orderList, Menu newOne, string middle) {
        Node* newNode = new Node(newOne);
        Node* temp = orderList.head;
        Node* prev = nullptr;

        // If the list is empty, insert at the front
        if (orderList.isEmpty()) {
            orderList.insertFront(orderList, newOne);
            return;
        }

        while (temp != nullptr && temp->order.getFoodId() != middle) {
            prev = temp;
            temp = temp->next;
        }

        // If the specified node is the head, insert at the front
        if (temp == orderList.head) {
            newNode->next = orderList.head;
            orderList.head = newNode; // Update the head
        } else {
            newNode->next = temp;
            prev->next = newNode;
        }
    }

    // Insert at the specified position
    void insertSpecified(OrderList& orderList, Menu newOne, string specified) {
        Node* newNode = new Node(newOne);
        Node* temp = orderList.head;
        Node* prev = nullptr;

        // If the list is empty, insert at the front
        if (orderList.isEmpty()) {
            orderList.insertFront(orderList, newOne);
            return;
        }

        while (temp != nullptr && temp->order.getFoodId() != specified) {
            prev = temp;
            temp = temp->next;
        }

        // If the specified node is the head, insert at the front
        if (temp == orderList.head) {
            newNode->next = orderList.head;
            orderList.head = newNode; // Update the head
        } else {
            newNode->next = temp;
            prev->next = newNode;
        }
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
                    current->order.displayMenu();
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
    
    // Function to delete a node by foodId
    void deleteNode(const string& deleteFoodId) {
    Node* current = head;
    Node* prev = nullptr;

    if (current != nullptr && current->order.getFoodId() == deleteFoodId) {
        head = current->next;
        delete current;
        return;
    }

    while (current != nullptr && current->order.getFoodId() != deleteFoodId) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Node Not Found." << endl;
        return;
    }

    if (prev != nullptr) {
        prev->next = current->next;
    } else {
        head = current->next;
    }

    delete current;
    cout << "Node Deleted Successfully." << endl;
}

    // Function to display all nodes
    void displayNodes() const {
        system("cls");
        cout << left;
        cout << setw(10) << "ID" << " | "
             << setw(21) << "NAME" << " | "
             << setw(13) << "TYPE" << " | "
             << fixed << "PRICE" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        Node* current = head;
        while (current != nullptr) {
            current->order.displayMenu();
            current = current->next;
        }
    }
};

void displayHeader() {
    cout << left;
    cout << setw(6) << "#" << "|"
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

    // Function to sort the list (using bubble sort as an example)
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

void FoodIdDSC(Menu menuArray[]) {
    string fI[SIZE];
    for (int last = SIZE - 1; last >= 1; --last) {
        fI[last] = menuArray[last].getFoodId();
        int smallestIndex = 0;
        for (int p = 1; p <= last; ++p) {
            if (menuArray[p].getFoodId() < menuArray[smallestIndex].getFoodId())
                smallestIndex = p;
        }
        swap(menuArray[smallestIndex], menuArray[last]);
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

void PriceDSC(Menu menuArray[]) {
    string fI[SIZE];
    for (int last = SIZE - 1; last >= 1; --last) {
        fI[last] = menuArray[last].getPrice();
        int smallestIndex = 0;
        for (int p = 1; p <= last; ++p) {
            if (menuArray[p].getPrice() < menuArray[smallestIndex].getPrice())
                smallestIndex = p;
        }
        swap(menuArray[smallestIndex], menuArray[last]);
    }
    displayHeader();
    printSortedResult(menuArray);
}

int main() {
    char choice;
    int opt, ins, sortBy, sortIn, size = 0;
    string foodId, name, category, middle;
    double price;
    OrderList orderList;
    Menu menuArray[SIZE];

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
        orderList.insertFront(orderList, newmenu);

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
        cout << "\nEnter your choice: " ;
        cin >> opt;

        switch (opt) {
            case 1:{
                cout << "Enter the food ID : ";
                getline(cin >> ws, foodId);
                cout << "Enter the food Name : ";
                getline(cin, name);
                cout << "Enter the category : ";
                getline(cin >> ws, category);
                cout << "Enter the price : ";
                cin >> price;

                cout << "\n[1] At front" << endl;
                cout << "[2] At Middle" << endl;
                cout << "[3] At End" << endl;
                cout << "[4] Replace" << endl;
                cout << "\nEnter your choice: ";
                cin >> ins;

                switch (ins)
                {
                    case 1:
                        orderList.insertFront(orderList, Menu(foodId, name, category, price));
                        break;
                    case 2:{
                        cout << "\nGive food ID existed in the Menu list : ";
                        cin >> middle;
                        orderList.insertMiddle(orderList, Menu(foodId, name, category, price), middle);
                        } break;
                    case 3:
                        orderList.insertEnd(orderList,Menu(foodId, name, category, price));
                        break;
                    case 4:{
                        cout << "\nGive food ID existed in the Menu list : ";
                        cin >> middle;
                        orderList.insertSpecified(orderList, Menu(foodId, name, category, price), middle);
                        } break;
                    default:
                        break;
                }            
                } break;

            case 2:{
                cout << "Enter the food ID to delete: ";
                cin >> foodId;
                orderList.deleteNode(foodId);
            } break;
            
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
                        foundNode->order.displayMenu();
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
                        foundNode->order.displayMenu();
                    } else {
                        cout << "\nNode Not Found.\n";
                    }
                }

            } break;

            case 4:{
                cout << "Sort by" << endl;
                cout << "[1] Food ID" << endl;
                cout << "[2] Price" << endl;
                cout << "\nEnter your choice: " ;
                cin >> sortBy;

                switch (sortBy){
                    case 1:{
                        cout << "Sort in" << endl;
                        cout << "[1] Ascending Order" << endl;
                        cout << "[2] Decending Order" << endl;
                        cin >> sortIn;

                        switch (sortIn)
                        {
                        case 1:{
                            FoodIdASC(menuArray);
                            cout << "Sorted by Food ID in Ascending Order." << endl;
                        } break;
                        case 2:{
                            FoodIdDSC(menuArray);
                            cout << "Sorted by Food ID in Descending Order." << endl;
                        } break;
                        default:
                            break;
                        }
                    }
                    case 2:{
                        cout << "Sort in" << endl;
                        cout << "[1] Ascending Order" << endl;
                        cout << "[2] Decending Order" << endl;
                        cin >> sortIn;

                        switch(sortIn){
                        case 1: {
                            PriceASC(menuArray);
                            cout << "Sorted by Price in Ascending Order." << endl;
                        } break;
                        case 2: {
                        	PriceDSC(menuArray);
                            cout << "Sorted by Price in Descending Order." << endl;
                        } break;
                        default:
                            break;
                        }
                    }
                }
            } break;

            case 5: {
        		cout << "Display Menu: " << endl;
    		} break;
	
        }

    } while (opt != 5);

    system("cls");
    displayHeader();
    orderList.displayNodes();

    cout << "\nDo you want to continue? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
        main();
    else    
        cout << "\nThank you, see you again!" << endl;

    return 0;
}
