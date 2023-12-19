#include<iostream>
#include<fstream>
using namespace std;

#define MAX 100

//class inventory, must be more than 6 attributes
class inventory{
  private:
        int itemNumber;
        string itemName;
        string description;
        int quantity;
        double cost;
        char[] itemLocation; //rack A01, B02, etc.
  public:
        inventory();
        inventory(int, string, string, int, double, char[]);
        void setItemNumber(int);
        void setItemName(string);
        void setDescription(string);
        void setQuantity(int);
        void setCost(double);
        void setItemLocation(char[]);
        int getItemNumber();
        string getItemName();
        string getDescription();
        int getQuantity();
        double getCost();
        char[] getItemLocation();
        void print();
};

//default constructor
inventory::inventory(){
    itemNumber = 0;
    itemName = "";
    description = "";
    quantity = 0;
    cost = 0.0;
    itemLocation = "";
}

//constructor
inventory::inventory(int itemNumber, string itemName, string description, int quantity, double cost, char[] itemLocation){
    this->itemNumber = itemNumber;
    this->itemName = itemName;
    this->description = description;
    this->quantity = quantity;
    this->cost = cost;
    this->itemLocation = itemLocation;
}

//setters
void inventory::setItemNumber(int itemNumber){
    this->itemNumber = itemNumber;
}

void inventory::setItemName(string itemName){
    this->itemName = itemName;
}

void inventory::setDescription(string description){
    this->description = description;
}

void inventorsy::setQuantity(int quantity){
    this->quantity = quantity;
}

void inventory::setCost(double cost){
    this->cost = cost;
}

void inventory::setItemLocation(char[] itemLocation){
    this->itemLocation = itemLocation;
}

//getters
int inventory::getItemNumber(){
    return itemNumber;
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

char[] inventory::getItemLocation(){
    return itemLocation;
}

//print function
void inventory::print(){
    cout << "Item Number: " << itemNumber << endl;
    cout << "Item Name: " << itemName << endl;
    cout << "Description: " << description << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Cost: " << cost << endl;
    cout << "Item Location: " << itemLocation << endl;
}

//mergesort accending
void mergeSort(inventory[], int, int);
void merge(inventory[], int, int, int);

//quicksort decending
void quickSort(inventory[], int, int);
int partition(inventory[], int, int);

//search
int SortedSeqSearch(inventory[], int, int);

int main(){
    inventory inv[MAX];
    //inventory from file
    ifstream fin;
    fin.open("inventory.txt");
    int i = 0;
    while(!fin.eof()){
        fin >> inv[i].itemNumber;
        fin >> inv[i].itemName;
        fin >> inv[i].description;
        fin >> inv[i].quantity;
        fin >> inv[i].cost;
        fin >> inv[i].itemLocation;
        i++;
    }
    fin.close();
    bool loop = true;
    while(loop){
            
    }
}

void mergeSort(inventory inv[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(inv, low, mid);
        mergeSort(inv, mid + 1, high);
        merge(inv, low, mid, high);
    }
}

void merge(inventory inv[], int low, int mid, int high){
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    inventory L[n1], R[n2];
    for(i = 0; i < n1; i++){
        L[i] = inv[low + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = inv[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = low;
    while(i < n1 && j < n2){
        if(L[i].getItemNumber() <= R[j].getItemNumber()){
            inv[k] = L[i];
            i++;
        }
        else{
            inv[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        inv[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        inv[k] = R[j];
        j++;
        k++;
    }
}

//quicksort decending
void quickSort(inventory inv[], int low, int high){
    if(low < high){
        int pi = partition(inv, low, high);
        quickSort(inv, low, pi - 1);
        quickSort(inv, pi + 1, high);
    }
}

int partition(inventory inv[], int low, int high){
    int pivot = inv[high].getItemNumber();
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if(inv[j].getItemNumber() > pivot){
            i++;
            inventory temp = inv[i];
            inv[i] = inv[j];
            inv[j] = temp;
        }
    }
    inventory temp = inv[i + 1];
    inv[i + 1] = inv[high];
    inv[high] = temp;
    return (i + 1);
}

//search
int SortedSeqSearch(inventory inv[], int n, int itemNumber){
    int i = 0;
    while(i < n && itemNumber > inv[i].getItemNumber()){
        i++;
    }
    if(i < n && itemNumber == inv[i].getItemNumber()){
        return i;
    }
    else{
        return -1;
    }
}
