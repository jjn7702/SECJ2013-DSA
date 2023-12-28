#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include <unistd.h>
#include<chrono>
#include<thread>
using namespace std;

#define MAX 1000

//class
class inventory{
    private:
        int itemNumber;
        string itemName;
        string description;
        int quantity;
        double cost;
        string itemLocation; //rack A01, B02, etc.
    public:
        inventory();
        inventory(int, string, string, int, double, string);
        void setItemNumber(int);
        void setItemName(string);
        void setDescription(string);
        void setQuantity(int);
        void setCost(double);
        void setItemLocation(string);
        int getItemNumber();
        string getItemName();
        string getDescription();
        int getQuantity();
        double getCost();
        string getItemLocation();
        void print();
};

//linked list classes
//node
class Node{
    public:
        inventory item;
        Node *next;
};
//list
class List{
    private:
        Node *head;
    public:
        List();
        ~List();
        bool isEmpty();
        Node* insertNode(inventory, int);
        int findNodeNum(int);
        int findNodeName(string);
        int findNodeLocation(string);
        void deleteNode(int);
        int count();
        void displayList();
        void SortbyNumber();
        void SortbyName();
        void SortbyLocation();
};

//check if the input is a number
bool isNumber(string);
bool isfloat(string);

int main(){
    List list;
    string inp;
    int choice;
    inventory* item;
    
    system("cls");
    cout << "Welcome to the inventory management system!\n";
    //delay 500 ms
    this_thread::sleep_for(chrono::milliseconds(500));
    system("cls");
    while(true){
        while(true){
            cout << "1. Add item\n2. Delete item\n3. Search item\n4. Sort the items\n5. Display all items\n6. Exit\n\nEnter your choice: ";
            cin >> inp;
            if(isNumber(inp)){
                choice = stoi(inp);
                if(inp.length() == 1 && choice >= 1 && choice <= 6){
                    system("cls");
                    break;
                }
                cout << "Invalid input, enter a number from 1 to 6!\n";
                system("pause");
                system("cls");
            }
        }
        if(choice == 1){
            int choice1;
            while(true){
                cout << "1. Add item at the beginning\n2. Add item at the end\n3. Add item at a specific position\n4. Back\n5. Display all items\n\nEnter your choice: ";
                cin >> inp;
                if(isNumber(inp)){
                    choice1 = stoi(inp);
                    if(inp.length() == 1 && choice1 >= 1 && choice1 <= 4){
                        system("cls");
                        break;
                    }
                    cout << "Invalid input, enter a number from 1 to 4!\n";
                    system("pause");
                    system("cls");
                }
            }
            if(choice1 == 4) continue;
            int itemNumber, quantity;
            string itemName, description, itemLocation;
            double cost;
            while(true){
                cout << "Enter item number: ";
                cin >> inp;
                if(isNumber(inp)){
                    itemNumber = stoi(inp);
                    if(!list.findNodeNum(itemNumber)){
                        system("cls");
                        break;
                    }
                    cout << "Item number already exists!\n";
                    system("pause");
                    system("cls");                
                }
            }
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, itemName);
            system("cls");
            cout << "Enter description: ";
            getline(cin, description);
            system("cls");
            while(true){
                cout << "Enter quantity: ";
                cin >> inp;
                if(isNumber(inp)){
                    quantity = stoi(inp);
                    if(quantity >= 0){
                        system("cls");
                        break;
                    }
                    cout << "Invalid input, enter a number greater than or equal to 0!\n";
                    system("pause");
                    system("cls");
                }
            }
            while(true){
                cout << "Enter cost: ";
                cin >> inp;
                if(isNumber(inp)){
                    cost = stod(inp);
                    if(cost >= 0){
                        system("cls");
                        break;
                    }
                    cout << "Invalid input, enter a number greater than or equal to 0!\n";
                    system("pause");
                    system("cls");
                }
            }
            cout << "Enter item location: ";
            cin.ignore();
            getline(cin, itemLocation);
            system("cls");
            item = new inventory(itemNumber, itemName, description, quantity, cost, itemLocation);
            
            if(choice1 == 1){
                list.insertNode(*item, 0);
            }
            else if(choice1 == 2){
                list.insertNode(*item, list.count());
            }
            else if(choice1 == 3){
                int index;
                while(true){
                    cout << "Enter the position to insert: ";
                    cin >> inp;
                    if(isNumber(inp)){
                        index = stoi(inp);
                        if(index >= 0 && index <= list.count()){
                            system("cls");
                            break;
                        }
                        cout << "Invalid input, enter a number from 0 to " << list.count() << "!\n";
                        system("pause");
                        system("cls");
                    }
                }
                list.insertNode(*item, index);
            }
            cout << "Item added successfully!\n";
            system("cls");
        }
        else if(choice == 2){
            if(list.isEmpty()){
                cout << "The list is empty!\n";
                system("pause");
                system("cls");
                continue;
            }
            else{
                while(true){
                    cout << "1. Delete first item\n2. Delete last item\n3. Delete item at a specific position\n4. Back\n\nEnter your choice: ";
                    cin >> inp;
                    if(isNumber(inp)){
                        choice = stoi(inp);
                        if(inp.length() == 1 && choice >= 1 && choice <= 4){
                            system("cls");
                            break;
                        }
                        cout << "Invalid input, enter a number from 1 to 4!\n";
                        system("pause");
                        system("cls");
                    }
                }
                if(choice == 4) continue;
                if(choice == 1){
                    list.deleteNode(0);
                    cout << "Item deleted successfully!\n";
                }
                else if(choice == 2){
                    list.deleteNode(list.count() - 1);
                    cout << "Item deleted successfully!\n";
                }
                else if(choice == 3){
                    int index;
                    while(true){
                        cout << "Enter the position to delete: ";
                        cin >> inp;
                        if(isNumber(inp)){
                            index = stoi(inp);
                            if(index >= 0 && index < list.count()){
                                system("cls");
                                break;
                            }
                            cout << "Invalid input, enter a number from 0 to " << list.count() - 1 << "!\n";
                            system("pause");
                            system("cls");
                        }
                    }
                    list.deleteNode(index);
                    cout << "Item deleted successfully!\n";
                }
            }
        }
        else if(choice == 3){
            if(list.isEmpty()){
                cout << "The list is empty!\n";
                system("pause");
                system("cls");
                continue;
            }
            else{
                while(true){
                    cout << "1. Search by item number\n2. Search by item name\n3. Search by item location\n4. Back\n\nEnter your choice: ";
                    cin >> inp;
                    if(isNumber(inp)){
                        choice = stoi(inp);
                        if(inp.length() == 1 && choice >= 1 && choice <= 4){
                            system("cls");
                            break;
                        }
                        cout << "Invalid input, enter a number from 1 to 4!\n";
                        system("pause");
                        system("cls");
                    }
                }
                if(choice == 4) continue;
                if(choice == 1){
                    int itemNumber;
                    while(true){
                        cout << "Enter item number: ";
                        cin >> inp;
                        if(isNumber(inp)){
                            itemNumber = stoi(inp);
                            if(list.findNodeNum(itemNumber)){
                                system("cls");
                                break;
                            }
                            cout << "Item number does not exist!\n";
                            system("pause");
                            system("cls");
                        }
                    }
                    cout << setw(15) << left << "Item number" 
                    << setw(15) << left << "Item name" 
                    << setw(30) << left << "Description" 
                    << setw(15) << left << "Quantity" 
                    << setw(15) << left << "Cost" 
                    << setw(15) << left << "Item location" << endl;
                    list.insertNode(*item, list.findNodeNum(itemNumber) - 1)->item.print();
                }
                else if(choice == 2){
                    string itemName;
                    cout << "Enter item name: ";
                    cin.ignore();
                    getline(cin, itemName);
                    cout << setw(15) << left << "Item number" 
                    << setw(15) << left << "Item name" 
                    << setw(30) << left << "Description" 
                    << setw(15) << left << "Quantity" 
                    << setw(15) << left << "Cost" 
                    << setw(15) << left << "Item location" << endl;
                    list.insertNode(*item, list.findNodeName(itemName) - 1)->item.print();
                }
                else if(choice == 3){
                    string itemLocation;
                    cout << "Enter item location: ";
                    cin.ignore();
                    getline(cin, itemLocation);
                    cout << setw(15) << left << "Item number" 
                    << setw(15) << left << "Item name" 
                    << setw(30) << left << "Description" 
                    << setw(15) << left << "Quantity" 
                    << setw(15) << left << "Cost" 
                    << setw(15) << left << "Item location" << endl;
                    list.insertNode(*item, list.findNodeLocation(itemLocation) - 1)->item.print();
                }
            }
        }
        else if(choice == 4){
            if(list.isEmpty()){
                cout << "The list is empty!\n";
                system("pause");
                system("cls");
                continue;
            }
            else{
                while(true){
                    cout << "1. Sort by item number\n2. Sort by item name\n3. Sort by item location\n4. Back\n\nEnter your choice: ";
                    cin >> inp;
                    if(isNumber(inp)){
                        choice = stoi(inp);
                        if(inp.length() == 1 && choice >= 1 && choice <= 4){
                            system("cls");
                            break;
                        }
                        cout << "Invalid input, enter a number from 1 to 4!\n";
                        system("pause");
                        system("cls");
                    }
                }
                if(choice == 4) continue;
                if(choice == 1)     list.SortbyNumber();
                else if(choice == 2)    list.SortbyName();
                else if(choice == 3)    list.SortbyLocation();
                cout << "List sorted successfully!\n";
                system("pause");
                system("cls");
            }
        }
        else if(choice == 5){
            if(list.isEmpty()){
                cout << "The list is empty!\n";
                system("pause");
                system("cls");
                continue;
            }
            else{
                cout << setw(15) << left << "Item number" 
                << setw(15) << left << "Item name" 
                << setw(30) << left << "Description" 
                << setw(15) << left << "Quantity" 
                << setw(15) << left << "Cost" 
                << setw(15) << left << "Item location" << endl;
                list.displayList();
            }
        }
        else break;
    }
    cout << "Thank you for using the inventory management system!\n";
    sleep(1);
    return 0;
}


//constructor
inventory::inventory(){
    itemNumber = 0;
    itemName = "";
    description = "";
    quantity = 0;
    cost = 0.0;
    itemLocation = "";
}
inventory::inventory(int itemNumber, string itemName, string description, int quantity, double cost, string itemLocation){
    this->itemNumber = itemNumber;
    this->itemName = itemName;
    this->description = description;
    this->quantity = quantity;
    this->cost = cost;
    this->itemLocation = itemLocation;
}

//setter
void inventory::setItemNumber(int itemNumber){
    this->itemNumber = itemNumber;
}

void inventory::setItemName(string itemName){
    this->itemName = itemName;
}

void inventory::setDescription(string description){
    this->description = description;
}

void inventory::setQuantity(int quantity){
    this->quantity = quantity;
}

void inventory::setCost(double cost){
    this->cost = cost;
}

void inventory::setItemLocation(string itemLocation){
    this->itemLocation = itemLocation;
}

//getters
int inventory::getItemNumber(){
    return itemNumber;
}
string inventory::getItemLocation(){
    return itemLocation;
}

string inventory::getItemName(){
    return itemName;
}

string inventory::getDescription(){
    return description;
}

int inventory::getQuantity(){
    return quantity;
}

double inventory::getCost(){
    return cost;
}

void inventory::print(){
    cout << setw(15) << left << itemNumber 
    << setw(15) << left << itemName 
    << setw(30) << left << description 
    << setw(15) << left << quantity 
    << fixed << setprecision(2) << setw(15) << left << cost 
    << setw(15) << left << itemLocation << endl;
}

List::List(){
    head = NULL;
}

List::~List(){
    Node* currNode = head, *nextNode = NULL;
    while (currNode != NULL){
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
    head = NULL;
}
bool List::isEmpty(){
    return head == NULL;
}
Node* List::insertNode(inventory item, int index){
    if (index < 0)
        return NULL;
    int currIndex = 1;
    Node *currNode = head;
    while (currNode && index > currIndex){
        currNode = currNode->next;
        currIndex++;
    }
    if (index > 0 && currNode == NULL)
        return NULL;
    Node *newNode = new Node;
    newNode->item = item;
    if (index == 0){
        newNode->next = head;
        head = newNode;
    }
    else{
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    return newNode;
}
int List::findNodeNum(int itemNumber){
    Node *currNode = head;
    int currIndex = 1;
    while (currNode && currNode->item.getItemNumber() != itemNumber){
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode)
        return currIndex;
    return 0;
}
int List::findNodeName(string itemName){
    Node *currNode = head;
    int currIndex = 1;
    while (currNode && currNode->item.getItemName() != itemName){
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode)
        return currIndex;
    return 0;
}
int List::findNodeLocation(string itemLocation){
    Node *currNode = head;
    int currIndex = 1;
    while (currNode && currNode->item.getItemLocation() != itemLocation){
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode)
        return currIndex;
    return 0;
}
void List::displayList(){
    Node *currNode = head;
    while (currNode){
        currNode->item.print();
        currNode = currNode->next;
    }
}
void List::deleteNode(int index){
    if (index < 0)
        return;
    Node *currNode = head, *prevNode = NULL;
    int currIndex = 1;
    while (currNode && index > currIndex){
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode == NULL)
        return;
    if (index == 0)
        head = currNode->next;
    else
        prevNode->next = currNode->next;
    delete currNode;
}
int List::count(){
    Node *currNode = head;
    int count = 0;
    while (currNode){
        count++;
        currNode = currNode->next;
    }
    return count;
}
//bubblesort
void List::SortbyNumber() {
    if (head == NULL)
        return;

    bool swapped;
    Node* currNode;
    Node* lastNode = NULL;

    int count = this->count(); // Get the count of nodes in the list

    for (int i = 0; i < count - 1; i++) {
        swapped = false;
        currNode = head;

        for (int j = 0; j < count - i - 1; j++) {
            if (currNode->item.getItemNumber() > currNode->next->item.getItemNumber()) {
                if (currNode->item.getItemNumber() != currNode->next->item.getItemNumber()) {
                    inventory temp = currNode->item;
                    currNode->item = currNode->next->item;
                    currNode->next->item = temp;
                    swapped = true;
                }
            }
            currNode = currNode->next;
        }

        if (!swapped)
            break;
    }
}

void List::SortbyName() {
    if (head == NULL)
        return;

    Node* currNode = head;
    Node* sortedNode = NULL;

    while (currNode != NULL) {
        Node* minNode = currNode;
        Node* tempNode = currNode->next;

        while (tempNode != NULL) {
            if (tempNode->item.getItemName() < minNode->item.getItemName()) {
                if (tempNode->item.getItemName() != minNode->item.getItemName()) {
                    minNode = tempNode;
                }
            }
            tempNode = tempNode->next;
        }

        if (minNode != currNode) {
            if (currNode == head) {
                head = minNode;
            } else {
                Node* prevNode = head;
                while (prevNode->next != currNode) {
                    prevNode = prevNode->next;
                }
                prevNode->next = minNode;
            }

            Node* temp = minNode->next;
            minNode->next = currNode->next;
            currNode->next = temp;

            currNode = minNode;
        }

        if (sortedNode == NULL) {
            sortedNode = currNode;
        }

        currNode = currNode->next;
    }
}

void List::SortbyLocation() {
    if (head == NULL)
        return;

    bool swapped;
    Node* currNode;
    Node* lastNode = NULL;

    int count = this->count(); // Get the count of nodes in the list

    for (int i = 0; i < count - 1; i++) {
        swapped = false;
        currNode = head;

        for (int j = 0; j < count - i - 1; j++) {
            if (currNode->item.getItemLocation() > currNode->next->item.getItemLocation()) {
                if (currNode->item.getItemLocation() != currNode->next->item.getItemLocation()) {
                    inventory temp = currNode->item;
                    currNode->item = currNode->next->item;
                    currNode->next->item = temp;
                    swapped = true;
                }
            }
            currNode = currNode->next;
        }

        if (!swapped)
            break;
    }
}

//other functionl
bool isNumber(string s){
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i]) == false){
            cout << "Invalid input, enter a numberic input!\n";
            system("pause");
            system("cls");
            return false;
        }
    }
    return true;
}
bool isfloat(string s){
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '.') count++;
        if(isdigit(s[i]) == false && s[i] != '.'){
            cout << "Invalid input, enter a numberic input!\n";
            system("pause");
            system("cls");
            return false;
        }
    }
    if(count > 1){
        cout << "Invalid input, enter a numberic input!\n";
        system("pause");
        system("cls");
        return false;
    }
    return true;
}
