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

    Node(const Menu& m) : menu(m), next(nullptr) {}
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

    // Insert at the front
    void insertFront(const Menu& arr) {
        Node* newHead = new Node(arr); // pass value into the first node
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

        while (temp->menu.getFoodId() != middle && temp->next != nullptr) {
            temp = temp->next;
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

    // Delete the first node
    void deleteFirst() {
        if (!isEmpty()) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Delete a node in the middle
    void deleteMiddle(const string& middle) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->menu.getFoodId() != middle) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != nullptr) {
            prev->next = temp->next;
            delete temp;
        }
    }

    // Delete the last node
    void deleteEnd() {
        if (!isEmpty()) {
            Node* temp = head;
            Node* prev = nullptr;

            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }

            if (prev != nullptr) {
                prev->next = nullptr;
                delete temp;
            } else {
                // Only one node in the list
                delete temp;
                head = nullptr;
            }
        }
    }

    // Function to find a node by foodId
    Node* findNode(const string& searchFoodId) const {
        Node* current = head;
        while (current != nullptr && current->menu.getFoodId() != searchFoodId) {
            current = current->next;
        }
        return current;
    }

    // Function to sort the list in ascending order based on foodId
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
                if (current->menu.getFoodId() > current->next->menu.getFoodId()) {
                    swap(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);
    }

    // Function to swap two nodes
    void swap(Node* a, Node* b) {
        Menu temp = a->menu;
        a->menu = b->menu;
        b->menu = temp;
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

    // Delete the first node
    menuList.deleteFirst();
    menuList.dispList();

    // Delete a node in the middle
    menuList.deleteMiddle("ID003");
    menuList.dispList();

    // Delete the last node
    menuList.deleteEnd();
    menuList.dispList();

    // Find a node by foodId
    Node* foundNode = menuList.findNode("ID002");
    if (foundNode != nullptr) {
        cout << "Node Found:\n";
        cout << "Food ID: " << foundNode->menu.getFoodId() << ", Name: " << foundNode->menu.getName()
             << ", Category: " << foundNode->menu.getCategory() << ", Price: " << foundNode->menu.getPrice() << endl;
    } else {
        cout << "Node Not Found.\n";
    }

    // Sort the list in ascending order based on foodId
    menuList.sortList();
    menuList.dispList();

    return 0;
}
