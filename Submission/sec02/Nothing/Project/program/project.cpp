#include <iostream>
#include <fstream>

using namespace std;

class goods{
    private:
        int id;
        string name;
        int price;
        string itemLocation;
    
    public:
        goods(int id, string name, int price, string itemLocation){
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

class itemNodeQueue{
    public:
        goods item;
        itemNodeQueue *next;
        itemNodeQueue *prev;
}

class itemQueue{
    public:
        itemNodeQueue *front;
        itemNodeQueue *rear;

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
}

class historyNodeStack{
    public:
        goods item;
        char action;
        historyNodeStack *next;
        historyNodeStack *prev;
        
}

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
}
