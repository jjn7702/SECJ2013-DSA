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

    	string getFoodId() { return foodId; }
        string getName() { return name; }
        string getCategory() { return category; }
        double getPrice() { return price; }

//        void setFoodId(string foodId) { this->foodId = foodId; }
//        void setName(string name) { this->name = name; }
//        void setCategory(string category) { this->category = category; }
//        void setPrice(double price) { this->price = price; }
};

class Node{
    Menu menu;
    Node *next;

    Node(Menu m){
        Menu = m;
        next = NULL;
    }
};

class List
{
    Menu *head;

    public:
        List() {head = NULL;} // create empty list first
        bool isEmtpy() {return head == NULL;} // specify that the list is emtpy

//display list of menu
        void dispList(){ // requires pointer(loop) to move the node
            Menu *temp = head;

            while (temp) //(temp != NULL)
            {
                temp->getFoodId(); // display node
                temp = temp->next; // to move the pointer to the next node
            }
            cout << endl;
        }

//ADDITION OF NODE

//at the first
        void insert(Menu *arr[]){
            Menu *newHead = new Menu(arr);//pass value d into the first node
            if(!isEmtpy())
                newHead->next = head;
            head = newHead;
        }     

//at the end
        void insertEndArray(Menu *&head, Menu *arr[], int size) {
            for (int i = 0; i < size; i++) {
                Menu *newEnd = new Menu(arr[i]);
                Menu *temp = head;
                if (head == NULL)
                    head = newEnd;
                else {
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newEnd;
                }
            }
        }

//at the middle
        void insertMiddleArray(Menu *&head, Menu *arr[], int size, int middle) {
            for (int i = 0; i < size; i++) {
                Menu *newNode = new Menu(arr[i]);
                Menu *temp = head;
                if (head->getFoodId() == middle)
                    head = newNode;
                else {
                    while (temp->getFoodId() != middle) {
                        temp = temp->next;
                    }
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
            }
        }

//at the specified
/*
        void insertSpecifiedArray(Node *&head, Menu *arr[], int size, int middle) {
            for (int i = 0; i < size; i++) {
                Menu *newNode = new Menu(arr[i]);
                Menu *temp = head, *prev;

                while (temp->getData() != middle){
                    prev = temp;
                    temp = temp->next;
                }

                newNode->next = temp->next;
                prev->next = newNode;
            }
}*/


};


