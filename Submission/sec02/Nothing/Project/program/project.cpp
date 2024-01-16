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
