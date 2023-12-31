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
    
    // Function to delete a node at the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node at the front deleted successfully." << endl;
    }

    // Function to delete a node at the end
    void deleteEnd() {
        if (isEmpty()) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        if (prev != nullptr) {
            prev->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
        cout << "Node at the end deleted successfully." << endl;
    }

    // Function to delete a node at the middle
    void deleteMiddle(string middle) {
        if (isEmpty()) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->order.getFoodId() != middle) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with specified ID not found." << endl;
            return;
        }

        if (prev != nullptr) {
            prev->next = temp->next;
        } else {
            head = temp->next;
        }

        delete temp;
        cout << "Node in the middle deleted successfully." << endl;
    }

    void sortFoodId (bool asc) {
        Node* current = head;

        while (current != nullptr) {
        Node* minMaxNode = current;
        Node* temp = current->next;

        while (temp != nullptr) {
            if ((asc && temp->order.getFoodId() < minMaxNode->order.getFoodId()) || (!asc && temp->order.getFoodId() > minMaxNode->order.getFoodId())) {
                minMaxNode = temp;
            }
            temp = temp->next;
        }

        // Swap data of minMaxNode and current
        Menu tempMenu = current->order;
        current->order = minMaxNode->order;
        minMaxNode->order = tempMenu;

        current = current->next;
        }  
    }

    void sortPrice (bool asc) {
        Node* current = head;

    while (current != nullptr) {
        Node* minMaxNode = current;
        Node* temp = current->next;

        while (temp != nullptr) {
            if ((asc && temp->order.getPrice() < minMaxNode->order.getPrice()) || (!asc && temp->order.getPrice() > minMaxNode->order.getPrice())) {
                minMaxNode = temp;
            }
            temp = temp->next;
        }

        // Swap data of minMaxNode and current
        Menu tempMenu = current->order;
        current->order = minMaxNode->order;
        minMaxNode->order = tempMenu;

        current = current->next;
        }
    }

    void swapNodes(Node* a, Node* b, Node* prev) {
        if (prev != nullptr) {
            prev->next = b;
        }
        else {
            head = b;
        }

        a->next = b->next;
        b->next = a;
    }

    // Function to display all nodes
    void displayNodes() const {
        system("cls");
        cout << endl;
        cout << left;
        cout << "-----------------------------------------------------------------" << endl;
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


int main() {
    char choice;
    int opt, ins, sortBy, sortIn, size = 0;
    string foodId, name, category, middle, specified;
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
                    default:
                        break;
                }  
                orderList.displayNodes();
            } break;

            case 2: {
                cout << "\nChoose the deletion option:" << endl;
                cout << "[1] Delete at Front" << endl;
                cout << "[2] Delete at End" << endl;
                cout << "[3] Delete in the Middle" << endl;
                cout << "\nEnter your choice: ";
                cin >> ins;

                switch (ins) {
                    case 1:
                        orderList.deleteFront();
                        break;
                    case 2:
                        orderList.deleteEnd();
                        break;
                    case 3: {
                        cout << "\nEnter food ID in the middle to delete: ";
                        cin >> middle;
                        orderList.deleteMiddle(middle);
                        break;
                    }
                    default:
                        cout << "Invalid choice for deletion option." << endl;
                }
                orderList.displayNodes();
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
                        foundNode->order.displayMenu();
                    } else {
                        cout << "\nNode Not Found.\n";
                    }
                }

            } break;

            case 4:{
                cout << endl;
                cout << "Sort by" << endl;
                cout << "[1] Food ID" << endl;
                cout << "[2] Price" << endl;
                cout << "\nEnter your choice: " ;
                cin >> sortBy;

                switch (sortBy){
                    case 1:{
                        cout << endl;
                        cout << "Sort in" << endl;
                        cout << "[1] Ascending Order" << endl;
                        cout << "[2] Descending Order" << endl;
                        cout << "\nEnter your choice: " ;
                        cin >> sortIn;

                        switch (sortIn)
                        {
                        case 1:{
                            orderList.sortFoodId(true);
                            cout << "\nSorted by Food ID in Ascending Order." << endl;
                            break;
                        } 
                        case 2:{
                            orderList.sortFoodId(false);
                            cout << "\nSorted by Food ID in Descending Order." << endl;
                            break;
                        } 
                        default:
                            cout << "Invalid choice for sorting order." << endl;
                        }
                        break;
                    } 
                    case 2:{
                        cout << endl;
                        cout << "Sort in" << endl;
                        cout << "[1] Ascending Order" << endl;
                        cout << "[2] Descending Order" << endl;
                        cout << "\nEnter your choice: " ;
                        cin >> sortIn;

                        switch(sortIn){
                        case 1: {
                            orderList.sortPrice(true);
                            cout << "\nSorted by Price in Ascending Order." << endl;
                            break;
                        } 
                        case 2: {
                        	orderList.sortPrice(false);
                            cout << "\nSorted by Price in Descending Order." << endl;
                            break;
                        } 
                        default:
                            cout << "Invalid choice for sorting order." << endl;
                        }
                        break;
                    } 
                    default:
                        cout << "Invalid choice for sorting type." << endl;
                }

                orderList.displayNodes();
                break;
            } 

            case 5: {
                orderList.displayNodes();
    		} break;

            default:
                cout << "Invalid option. Please try again." << endl;
	
        }

        cout << "\nDo you want to continue? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y') ;

    cout << "\nThank you, see you again!" << endl;

    return 0;
}
