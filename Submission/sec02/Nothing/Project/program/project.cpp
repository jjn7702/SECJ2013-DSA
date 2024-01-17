#include <iostream>
#include <fstream>
#include<iomanip>

using namespace std;

class goods{
    private:
        int id;
        string name;
        int price;
        string itemLocation;
    
    public:
        goods(int id = 0, string name = "", int price = 0, string itemLocation = ""){
            this->id = id;
            this->name = name;
            this->price = price;
            this->itemLocation = itemLocation;
        }

        int getId(){
            return id;
        }

        string getName(){
            return name;
        }

        int getPrice(){
            return price;
        }

        string getItemLocation(){
            return itemLocation;
        }
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
        void createStack(){
            top = NULL;
            bottom = NULL;
            size = 0;
        }

        bool isEmpty(){
            if(top == NULL)
                return true;
            else
                return false;
        }

        void push(goods item, char action){
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

        void pop(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
            }else{
                historyNodeStack *temp = top;
                top->next = NULL;
                delete temp;
                size--;
            }
        }

        char getAction(){
            if(isEmpty())
                cout << "Stack is empty" << endl;
            else
                return top->action;
        }

        goods getItem(){
            if(isEmpty())
                cout << "Stack is empty" << endl;
            else
                return top->item;
        }
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

        void createQueue(){
            front = NULL;
            rear = NULL;
            size = 0;
        }

        bool isEmpty(){
            if(front == NULL)
                return true;
            else
                return false;
        }

        void enqueue(goods item){
            itemNodeQueue *newNode = new itemNodeQueue;
            newNode->item = item;
            newNode->next = NULL;
            newNode->prev = NULL;

            if(isEmpty()){
                front = newNode;
                rear = newNode;
            }else{
                newNode->prev = rear;
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
            }else{
                itemNodeQueue *temp = front;
                front = front->next;
                front->prev = NULL;
                delete temp;
                size--;
            }
            cout << "Item " << front->item.getId() << " removed!" << endl;
        }

        goods getItem(){
            if(isEmpty())
                cout << "Queue is empty" << endl;
            else
                return front->item;
        }

        void display(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
            }else{
                itemNodeQueue *temp = front;
                //display in table
                cout << "ID" << setw(10) << "Name" << setw(10) << "Price" << setw(10) << "Location" << endl;
                while(temp != NULL){
                    cout << temp->item.getId() << setw(10) << temp->item.getName() << setw(10) << temp->item.getPrice() << setw(10) << temp->item.getItemLocation() << endl;
                    temp = temp->next;
                }
            }
        }
};

void welcomeScreen();
void displayHeader();
void menu();
bool isNumber(string);
bool isfloat(string);
itemQueue import();
goods *add();
void printHistory(historyStack);

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
                    history.push(item.getItem(), 'r');
                    item.dequeue();
                    displayHeader();
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
                system("pause");
                system("cls");
                cout << "Exiting..." << endl;
                cout << "Thank you for using the system!" << endl;
                return 0;
            }
        }
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
    cout << "=========================================\n";
    cout << "|    Warehouse Inventory Management     |\n";
    cout << "|                System                 |\n";
    cout << "=========================================\n";
}

void menu() {
    cout << "Please select an option:\n";
    cout << "1.  Import item from file\n";
    cout << "2.  Add item\n";
    cout << "3.  Remove item\n";
    cout << "4.  Display item\n";
    cout << "5.  Print history and exit\n";
}

bool isNumber(string input){
    for(int i = 0; i < input.length(); i++){
        if(!isdigit(input[i]))
            return false;
    }
    return true;
}

itemQueue import(){
    ifstream file("input.txt");
    int id;
    string name;
    int price;
    string itemLocation;
    itemQueue item;
    item.createQueue();
    goods *newItem;
    if (!file.is_open()) {
        cout << "File not found" << endl;
    }else{
        cout << "Importing..." << endl;
        //each line is a goods
        while (file >> id >> name >> price >> itemLocation) {
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
    int price;
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
            price = stof(input);
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
        while(!history.isEmpty()){
            file << history.getItem().getId() << " " << history.getItem().getName() << " " << history.getItem().getPrice() << " " << history.getItem().getItemLocation() << " " << history.getAction() << endl;
            history.pop();
        }
    }
    file.close();
}
