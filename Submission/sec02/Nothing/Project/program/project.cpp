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
