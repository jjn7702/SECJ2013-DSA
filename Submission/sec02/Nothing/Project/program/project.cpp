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
        historyNodeStack *prev;
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
            newNode->prev = NULL;

            if(isEmpty()){
                top = newNode;
                bottom = newNode;
            }else{
                newNode->prev = top;
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
                top = top->prev;
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
        }

        goods getItem(){
            if(isEmpty())
                cout << "Queue is empty" << endl;
            else
                return front->item;
        }
};

void welcomeScreen();
void displayHeader();
void menu();
bool isNumber(string);
itemQueue import();
goods *add();

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
            cin >> input;
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
                break;
            case 4:
                break;
            case 7:
                system("cls");
                cout << "Thank you for using the system!" << endl;
                system("pause");
                system("cls");
                return 0;
        }
    }
    return 0;
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
    cout << "5.  Undo\n";
    cout << "6.  Display history\n";
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
    cout << "Enter item ID: ";
    cin >> id;
    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter item price: ";
    cin >> price;
    cout << "Enter item location: ";
    cin >> itemLocation;
    newItem = new goods(id, name, price, itemLocation);
    return newItem;
}
