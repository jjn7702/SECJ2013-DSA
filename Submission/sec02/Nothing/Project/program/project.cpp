#include <iostream>
#include <fstream>
#include<iomanip>
#include <unistd.h>

using namespace std;

class goods{
    private:
        int id;
        string name;
        double price;
        string itemLocation;
    
    public:
        goods(int id = 0, string name = "", double price = 0, string itemLocation = "");
        int getId();
        string getName();
        double getPrice();
        string getItemLocation();
};

class historyNodeStack{
    public:
        goods item;
        char action;
        historyNodeStack *next;
};

class historyStack{
    private:
        historyNodeStack *top;
        historyNodeStack *bottom;
        int size;

    public:
        void createStack();
        bool isEmpty();
        void push(goods item, char action);
        void pop();
        char getAction();
        goods getItem();
};

class itemNodeQueue{
    public:
        goods item;
        itemNodeQueue *next;
        itemNodeQueue *prev;
};


class itemQueue{
    public:
        itemNodeQueue *front;
        itemNodeQueue *rear;
        int size;

        void createQueue();
        bool isEmpty();
        void enqueue(goods item);
        void dequeue();
        goods getItem();
        void display();
};

void welcomeScreen();
void displayHeader();
void menu();
bool isNumber(string);
bool isfloat(string);
itemQueue import();
goods *add();
void printHistory(historyStack);
void saveToFile(itemQueue);


int main(){
    displayHeader();
    welcomeScreen();
    itemQueue item;
    item.createQueue();
    historyStack history;
    history.createStack();
    string input;
    while(true){
        int choice;
        while(true){
            displayHeader();
            menu();
            cout << "Enter your choice: ";

            getline(cin, input);
            if(isNumber(input)){
                choice = stoi(input);
                if(choice >= 1 && choice <= 7){
                    break;
                }else{
                    cout << "Please enter a number between 1 and 7" << endl;
                    system ("pause");
                }
            }else{
                cout << "Invalid input, please enter a number between 1 and 7" << endl;
                system ("pause");
            }
        }
        switch(choice){
            case 1:
                item = import();
                break;
            case 2: {
                goods *newItem = add();
                item.enqueue(*newItem);
                history.push(*newItem, 'a');
                cout << "Item added!" << endl;
                system("pause");
                break;
            }
            case 3:
                if (item.isEmpty()) {
                    system("cls");
                    displayHeader();
                    cout << "No item in the inventory!" << endl;
                    system("pause");
                    break;
                }
                else {
                    displayHeader();
                    history.push(item.getItem(), 'r');
                    cout << "Item: " << item.getItem().getName() <<" id: "<< item.getItem().getId() << " has been taken out!" << endl;
                    item.dequeue();
                    system("pause");
                    system("cls");
                }
                break;
            case 4:
                if (item.isEmpty()) {
                    system("cls");
                    displayHeader();
                    cout << "No item in the inventory!" << endl;
                    system("pause");
                    break;
                }
                else {
                    system("cls");
                    displayHeader();
                    item.display();
                    system("pause");
                    break;
                }
                break;
            case 5:{
                system ("cls");
                displayHeader();
                cout << "Printing history..." << endl;
                printHistory(history);
                cout << "History saved into file" << endl;
                cout << "Saving inventory..." << endl;
                saveToFile(item);
                cout << "Inventory saved into file" << endl;
                system("pause");
                system("cls");
                cout << "Exiting..." << endl;
                cout << "Thank you for using the system!" << endl;
                sleep(2);
                system("cls");
                return 0;
            }
        }
    }
}

goods::goods(int id, string name, double price, string itemLocation){
    this->id = id;
    this->name = name;
    this->price = price;
    this->itemLocation = itemLocation;
}
int goods::getId(){
    return id;
}
string goods::getName(){
    return name;
}
double goods::getPrice(){
    return price;
}
string goods::getItemLocation(){
    return itemLocation;
}

void historyStack::createStack(){
    top = NULL;
    bottom = NULL;
    size = 0;
}
bool historyStack::isEmpty(){
    if(top == NULL)
        return true;
    else
        return false;
}
void historyStack::push(goods item, char action){
    historyNodeStack *newNode = new historyNodeStack;
    newNode->item = item;
    newNode->action = action;
    newNode->next = NULL;

    if(isEmpty()){
        top = newNode;
        bottom = newNode;
    }else{
        top->next = newNode;
        top = newNode;
    }
    size++;
}
void historyStack::pop(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
    }else{
        historyNodeStack *temp = bottom;
        historyNodeStack *prev = NULL;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        if(prev == NULL){
            top = NULL;
            bottom = NULL;
        }else{
            prev->next = NULL;
            top = prev;
        }
        delete temp;
        size--;
    }
}
char historyStack::getAction(){
    if(isEmpty())
        cout << "Stack is empty" << endl;
    else
        return top->action;
}
goods historyStack::getItem(){
    if(isEmpty())
        cout << "Stack is empty" << endl;
    else
        return top->item;
}

void itemQueue::createQueue(){
    front = NULL;
    rear = NULL;
    size = 0;
}
bool itemQueue::isEmpty(){
    if(front == NULL)
        return true;
    else
        return false;
}
void itemQueue::enqueue(goods item){
    itemNodeQueue *newNode = new itemNodeQueue;
    newNode->item = item;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(isEmpty()){
        front = newNode;
        rear = newNode;
    }else{
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    size++;
}
void itemQueue::dequeue(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
    }else{
        itemNodeQueue *temp = front;
        front = front->next;
        if(front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        delete temp;
        size--;
    }
}
goods itemQueue::getItem(){
    return front->item;
}
void itemQueue::display(){
    itemNodeQueue *temp = front;
    cout << "ID\tName\t\tPrice\t\tLocation" << endl;
    while(temp != NULL){
        cout << temp->item.getId() << "\t" << temp->item.getName() << "\t\t" << temp->item.getPrice() << "\t\t" << temp->item.getItemLocation() << endl;
        temp = temp->next;
    }
}

void welcomeScreen(){
    system("cls");
    cout << "Welcome to the warehouse inventory management system!\n";
    system("pause");
    system("cls");
}
void displayHeader() {
    system("cls");
    cout << "===================================================\n";
    cout << "|         Warehouse Inventory Management          |\n";
    cout << "|                     System                      |\n";
    cout << "===================================================\n";
}


void menu() {
    cout << "Please select an option:\n";
    cout << "1.  Import item from file\n";
    cout << "2.  Add item\n";
    cout << "3.  Remove item\n";
    cout << "4.  Display item\n";
    cout << "5.  Print history, save files, and exit\n";
}
bool isNumber(string input){
    for(int i = 0; i < input.length(); i++){
        if(!isdigit(input[i]))
            return false;
    }
    return true;
}
itemQueue import(){
    ifstream file("input.csv");
    int id;
    string name;
    double price;
    string itemLocation;
    itemQueue item;
    item.createQueue();
    goods *newItem;
    system("cls");
    displayHeader();
    if (!file.is_open()) {
        cout << "File not found" << endl;
    }else{
        cout << "Importing..." << endl;
        //each line is a goods
        while (!file.eof()) {
            file >> id;
            file.ignore();
            getline(file, name, ',');
            file >> price;
            file.ignore();
            getline(file, itemLocation);
            newItem = new goods(id, name, price, itemLocation);
            item.enqueue(*newItem);
        }
    }
    file.close();
    cout << "Import successful!" << endl;
    system("pause");
    return item;
}

goods *add(){
    int id;
    string name;
    double price;
    string itemLocation;
    goods *newItem;
    system("cls");
    displayHeader();
    string input;
    while(true){
        cout << "Enter item ID: ";
        getline(cin, input);
        if(isNumber(input)){
            id = stoi(input);
            break;
        }else{
            cout << "Invalid input, please enter a number!" << endl;
            system("pause");
            system("cls");
            displayHeader();
        }
    }
    cout << "Enter item name: ";
    getline(cin, name);
    while(true){
        cout << "Enter item price: ";
        getline(cin, input);
        if(isfloat(input)){
            price = stod(input);
            break;
        }else{
            cout << "Invalid input, please enter a number!" << endl;
            system("pause");
            system("cls");
            displayHeader();
        }
    }
    cout << "Enter item location: ";
    getline(cin, itemLocation);
    newItem = new goods(id, name, price, itemLocation);
    return newItem;
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
void printHistory(historyStack history){
    ofstream file("history.txt");
    if(file.is_open()){
        file <<setw(5)<< "ID" <<setw(15)<< "Name" <<setw(15)<< "Price" <<setw(15)<< "Location" <<setw(15)<< "Action" << endl;
        while(!history.isEmpty()){
            file <<setw(5)<< history.getItem().getId() <<setw(15)<< history.getItem().getName() <<setw(15)<< history.getItem().getPrice() <<setw(15)<< history.getItem().getItemLocation() <<setw(15)<< history.getAction() << endl;
            history.pop();
        }
    }
    file.close();
}
void saveToFile(itemQueue item){
    ofstream file("output.csv");
    if(file.is_open()){
        while(!item.isEmpty()){
            file << item.getItem().getId() << "," << item.getItem().getName() << "," << item.getItem().getPrice() << "," << item.getItem().getItemLocation() << endl;
            item.dequeue();
        }
    }
    file.close();
}
