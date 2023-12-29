#include <iostream>
#include <string>
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
};

class Node {
public:
    Menu menu;
    Node* next;

    Node(Menu m) : menu(m), next(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    bool isEmpty() const { return head == nullptr; }

    // Display list of menu
    void dispList() const {
        Node* temp = head;

        while (temp) {
            cout << "Food ID: " << temp->menu.getFoodId() << ", Name: " << temp->menu.getName()
                 << ", Category: " << temp->menu.getCategory() << ", Price: " << temp->menu.getPrice() << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    // Insert at the first
    void insertFront(const Menu& arr) {
        Node* newHead = new Node(arr);
        if (!isEmpty())
            newHead->next = head;
        head = newHead;
    }

    // Insert at the end
    void insertEnd(const Menu& arr) {
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
    void insertMiddle(const Menu& newOne, const string& middle) {
        Node* newNode = new Node(newOne);
        Node* temp = head;
        int count = 1;

        while (temp->menu.getFoodId() != middle && temp->next != nullptr) {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Insert at the specified position
    void insertSpecified(const Menu& newOne, const string& specified) {
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

    // Delete a node
    void deleteNode(const string& key) {
        Node* temp = head;
        Node* prev = nullptr;

        // If the key matches the first node
        if (temp != nullptr && temp->menu.getFoodId() == key) {
            head = temp->next;
            delete temp;
            return;
        }

        // Search for the key to be deleted
        while (temp != nullptr && temp->menu.getFoodId() != key) {
            prev = temp;
            temp = temp->next;
        }

        // If the key is not present
        if (temp == nullptr) {
            cout << "Key not found. Deletion failed." << endl;
            return;
        }

        // Unlink the node from linked list
        prev->next = temp->next;

        // Free memory
        delete temp;
    }

    // Find a node based on the search key
    Node* findNode(const string& searchKey) const {
        Node* current = head;
        while (current != nullptr && current->menu.getFoodId() != searchKey) {
            current = current->next;
        }
        return current;
    }

    // Sorting the list (bubble sort)
    void sortList(const string& sortBy) {
        if (isEmpty() || head->next == nullptr) {
            cout << "List is empty or has only one node. No need to sort." << endl;
            return;
        }

        bool swapped;
        Node* last = nullptr;

        do {
            swapped = false;
            Node* current = head;

            while (current->next != last) {
                if (compareNodes(current, current->next, sortBy)) {
                    swapNodes(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);
    }

private:
    // Compare two nodes based on the specified attribute for sorting
    bool compareNodes(Node* node1, Node* node2, const string& sortBy) const {
        if (sortBy == "foodId")
            return node1->menu.getFoodId() > node2->menu.getFoodId();
        else if (sortBy == "name")
            return node1->menu.getName() > node2->menu.getName();
        else if (sortBy == "category")
            return node1->menu.getCategory() > node2->menu.getCategory();
        else if (sortBy == "price")
            return node1->menu.getPrice() > node2->menu.getPrice();
        else {
            cout << "Invalid sorting attribute. No sorting performed." << endl;
            return false;
        }
    }

    // Swap the data of two nodes
    void swapNodes(Node* node1, Node* node2) const {
        Menu temp = node1->menu;
        node1->menu = node2->menu;
        node2->menu = temp;
    }
};

int main() {
    List menuList;

    // Insert at the front
    menuList.insertFront(Menu("ID001", "Burger", "Fast Food", 5.99));
    menuList.dispList();

    menuList.insertFront(Menu("ID002", "Pizza", "Italian", 8.99));
    menuList.dispList();

    // Insert at the end
    menuList.insertEnd(Menu("ID003", "Pasta", "Italian", 6.99));
    menuList.dispList();

    menuList.insertEnd(Menu("ID004", "Salad", "Healthy", 4.99));
    menuList.dispList();

    // Insert at the middle
    menuList.insertMiddle(Menu("ID005", "Sandwich", "Fast Food", 7.99), "ID002");
    menuList.dispList();

    // Insert at the specified position
    menuList.insertSpecified(Menu("ID006", "Sushi", "Japanese", 12.99), "ID003");
    menuList.dispList();

    // Delete a node
    menuList.deleteNode("ID002");
    menuList.dispList();

    // Find a node
    Node* foundNode = menuList.findNode("ID004");
    if (foundNode != nullptr) {
        cout << "Node Found:\n";
        cout << "Food ID: " << foundNode->menu.getFoodId() << ", Name: " << foundNode->menu.getName()
             << ", Category: " << foundNode->menu.getCategory() << ", Price: " << foundNode->menu.getPrice() << endl;
    } else {
        cout << "Node Not Found." << endl;
    }

    // Sort the list by price
    menuList.sortList("price");
    menuList.dispList();

    return 0;
}
