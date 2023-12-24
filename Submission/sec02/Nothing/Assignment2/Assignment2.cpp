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


//check if the input is a number
bool isNumber(string);




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




//other function
bool isNumber(string s){
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i]) == false){
            cout << "Invalid input, enter a numberic input!\n";
            system("pause");
            return false;
        }
    }
    return true;
}
