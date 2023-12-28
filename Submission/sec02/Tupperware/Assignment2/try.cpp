#include <iostream>
using namespace std;

class Menu {
private:
    string foodId;
    string name;
    string category;
    double price;

public:
    Menu *next;
    Menu() {
        foodId = "";
        name = "";
        category = "";
        price = 0.0;
    }
    Menu(string foodId, string name, string category, double price)
        : foodId(foodId), name(name), category(category), price(price) {}

    	string getFoodId() const { return foodId; }
        string getName() const { return name; }
        string getCategory() const { return category; }
        double getPrice() const { return price; }

        void setFoodId(string foodId) { this->foodId = foodId; }
        void setName(string name) { this->name = name; }
        void setCategory(string category) { this->category = category; }
        void setPrice(double price) { this->price = price; }
};

class List
{
    Menu *head;

    public:
        List() {head = NULL;} // create empty list first
        bool isEmtpy() {return head == NULL;} // specify that the list is emtpy

        void dispList(){ // requires pointer(loop) to move the node
            Menu *temp = head;

            while (temp) //(temp != NULL)
            {
                cout << temp->getData() << "\t"; // display node
                temp = temp->next; // to move the pointer to the next node
            }
            cout << endl;
        }

//ADDITION OF NODE

//at the first
        void insert(Menu *arr[]){
            Menu *newNode = new Menu(d);//pass value d into the first node
            if(!isEmtpy())
                newNode->next = head;
            head = newNode;
        }     

//at the end
        void insertEndArray(Menu *&head, Menu *arr[], int size) {
            for (int i = 0; i < size; i++) {
                Menu *newNode = new Menu(arr[i]);
                Menu *temp = head;
                if (head == NULL)
                    head = newNode;
                else {
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newNode;
                }
            }
        }

//at the middle
        void insertMiddleArray(Node *&head, Menu *arr[], int size, int middle) {
            for (int i = 0; i < size; i++) {
                Menu *newNode = new Menu(arr[i]);
                Menu *temp = head;
                if (head->getData() == middle)
                    head = newNode;
                else {
                    while (temp->getData() != middle) {
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


