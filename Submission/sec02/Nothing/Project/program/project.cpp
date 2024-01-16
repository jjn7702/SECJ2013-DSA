#include <iostream>
#include <fstream>
#include<iomanip>
#include<chrono>
#include<thread>

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
itemQueue import();

int main(){
    displayHeader();
    welcomeScreen();
    itemQueue item;
    while(true){
        displayHeader();
        menu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    return 0;
}

void welcomeScreen(){
    system("cls");
    cout << "Welcome to the warehouse inventory management system!\n";
    this_thread::sleep_for(chrono::milliseconds(500));
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
    cout << "1.  Add item\n";
    cout << "2.  Remove item\n";
    cout << "3.  Search item\n";
    cout << "4.  Display item\n";
    cout << "5.  Undo\n";
    cout << "6.  Redo\n";
    cout << "7.  Exit\n";
}

itemQueue import(){
    ifstream file;
    int id;
    string name;
    int price;
    string itemLocation;
    itemQueue item;
    goods newItem;
    file.open("input.txt");
    if(!file){
        cout << "File not found" << endl;
    }else{
        //each line is a goods
        while(file >> id >> name >> price >> itemLocation){
            newItem = goods(id, name, price, itemLocation);
            //insert into item
            item.enqueue(newItem);
        }
    }
    file.close();
    return item;
}
