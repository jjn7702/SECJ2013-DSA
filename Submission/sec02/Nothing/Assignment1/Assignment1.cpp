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

//mergesort for accending
void mergeSort(inventory[], int, int);
void merge(inventory[], int, int, int);

//quicksort for decending
void quickSort(inventory[], int, int);
int partition(inventory[], int, int);

//binarySearch for itemNumber(int)
int binarySearch(inventory[], int, int, int);
//sequentialSearch for itemName and itemLocation(string)
int SeqSearch(inventory[], int, const string&, bool);

//check if the input is a number
bool isNumber(string);


int main(){
    inventory inv[MAX];
    string inp;
    //read inventory from file
    ifstream fin;
    fin.open("inventory.txt");
    if (!fin.is_open()) {
        cout << "Error opening the file.\n";
        system("pause");
        return 0;
    }
    int i = 0;
    while(!fin.eof()){
        int itemNumber;
        string itemName;
        string description;
        int quantity;
        double cost;
        string itemLocation;
        fin >> itemNumber >> itemName >> description >> quantity >> cost >> itemLocation;
        inv[i].setItemNumber(itemNumber);
        inv[i].setItemName(itemName);
        inv[i].setDescription(description);
        inv[i].setQuantity(quantity);
        inv[i].setCost(cost);
        inv[i].setItemLocation(itemLocation);
        i++;
    }
    fin.close();

    //welcome screen
    system("cls");
    cout << "Inventory Management System\n\nWelcome...\n\n";
    //delay half second
    this_thread::sleep_for(chrono::milliseconds(500));

    while (true) {
        int choice;
        while(true){
            system("cls");
            cout << "Inventory Management System\n\nMain Menu:\n1. Sort\n2. Search\n3. Exit\n\nSelect an option: ";
            getline(cin, inp);
            if(isNumber(inp)){
                choice = stoi(inp);
                break;
            } 
        }
        if (choice == 1) {
            int sortChoice = 0;
            int orderChoice = 0;
            while(true){
                system("cls");
                cout << "Inventory Management System\n\nSort by:\n1. Item Number\n2. Item Name\n3. Quantity\n4. Cost\n5. Item Location\n6. Back to menu\n\nSelect an option: ";
                getline(cin, inp);
                if(isNumber(inp)){
                    sortChoice = stoi(inp);
                    if(sortChoice>0 && sortChoice <6){
                        while(true){
                            system("cls");
                            cout << "Inventory Management System\n\nSort by " 
                                << (sortChoice == 1 ? "Item Number" : sortChoice == 2 ? "Item Name" : sortChoice == 3 ? "Quantity" : sortChoice == 4 ? "Cost" : "Item Location")
                                <<" in:\n1. Ascending\n2. Descending\n3. Back\n4. Back to menu\n\nSelect an option: ";
                            getline(cin, inp);
                            if(isNumber(inp)){
                                orderChoice = stoi(inp);
                                if(orderChoice >0 && orderChoice <5) break;
                            }
                        }
                        if(orderChoice == 4) sortChoice = 6;
                        if(orderChoice != 3) break;
                    }
                    else if(sortChoice == 6) break;
                    else{
                        cout<< "Enter a valid input(1-6)\n";
                        system("pause");
                        system("cls");
                    }
                }
            }

            if (sortChoice == 1) {
                if (orderChoice == 1) {
                    mergeSort(inv, 0, i - 1);
                } 
                else if (orderChoice == 2) {
                    quickSort(inv, 0, i - 1);
                }
            } 
            else if (sortChoice == 2) {
                if (orderChoice == 1) {
                    mergeSort(inv, 0, i - 1);
                } 
                else if (orderChoice == 2) {
                    quickSort(inv, 0, i - 1);
                }
            } 
            else if (sortChoice == 3) {
                if (orderChoice == 1) {
                    mergeSort(inv, 0, i - 1);
                } 
                else if (orderChoice == 2) {
                    quickSort(inv, 0, i - 1);
                }
            } 
            else if (sortChoice == 4) {
                if (orderChoice == 1) {
                    mergeSort(inv, 0, i - 1);
                } 
                else if (orderChoice == 2) {
                    quickSort(inv, 0, i - 1);
                }
            } 
            else if (sortChoice == 5) {
                if (orderChoice == 1) {
                    mergeSort(inv, 0, i - 1);
                } 
                else if (orderChoice == 2) {
                    quickSort(inv, 0, i - 1);
                }
            } 
            else continue;

            //print th output in a table format
            system("cls");
            cout << "Inventory Management System\n\nInventory:\n"
                << setw(15) << left << "Item Number" 
                << setw(15) << left << "Item Name" 
                << setw(30) << left << "Description" 
                << setw(15) << left << "Quantity" 
                << setw(15) << left << "Cost" 
                << setw(15) << left << "Item Location" << endl;
            for (int j = 0; j < i; j++) {
                inv[j].print();
            }
            cout<<endl<<endl;
            system("pause");
        } 
        else if (choice == 2) {
            int searchChoice;
            while(true){
                system("cls");
                cout << "Inventory Management System\n\nSearch by:\n1. Item Number\n2. Item Name\n3. Item Location\n4. Back to menu\n\nSelect an option: ";
                getline(cin, inp);
                if(isNumber(inp)){
                    searchChoice = stoi(inp);
                    if(searchChoice>0 && searchChoice <5) break;
                }
            }
                if (searchChoice == 1) {
                    system("cls");
                    cout << "Inventory Management System\n\nEnter item number: ";
                    int itemNumber;
                    cin >> itemNumber;
                    //sort the list for binary search
                    mergeSort(inv, 0, i - 1);
                    int index = binarySearch(inv, 0, i - 1, itemNumber);
                    if (index == -1) {
                        system("cls");
                        cout << "Inventory Management System\n\nItem with item number "
                            << itemNumber
                            <<" not found\n\n";
                        system("pause");
                    } 
                    else {
                        system("cls");
                        cout << "Inventory Management System\n\nInventory:\n"
                            << setw(15) << left << "Item Number" 
                            << setw(15) << left << "Item Name" 
                            << setw(30) << left << "Description" 
                            << setw(15) << left << "Quantity" 
                            << setw(15) << left << "Cost" 
                            << setw(15) << left << "Item Location" << endl;
                        inv[index].print();
                        cout<<endl<<endl;
                        system("pause");
                    }
                } 
                else if (searchChoice == 2) {
                    system("cls");
                    cout << "Enter item name: ";
                    string itemName;
                    cin >> itemName;
                    int index = SeqSearch(inv, i, itemName, false);
                    if (index == -1) {
                        system("cls");
                        cout << "Inventory Management System\n\nItem with item name "
                            << itemName
                            <<" not found\n\n";
                        system("pause");
                    } 
                    else {
                        system("cls");
                        cout << "Inventory:\n"
                            << setw(15) << left << "Item Number" 
                            << setw(15) << left << "Item Name" 
                            << setw(30) << left << "Description" 
                            << setw(15) << left << "Quantity" 
                            << setw(15) << left << "Cost" 
                            << setw(15) << left << "Item Location" << endl;
                        inv[index].print();
                        cout<<endl<<endl;
                        system("pause");
                    }
                } 
                else if (searchChoice == 3) {
                    system("cls");
                    cout << "Inventory Management System\n\nEnter item location: ";
                    string itemLocation;
                    cin >> itemLocation;
                    int index = SeqSearch(inv, i, itemLocation, true);
                    if (index == -1) {
                        system("cls");
                        cout << "Inventory Management System\n\nItem with item location "
                            << itemLocation
                            <<" not found\n\n";
                        system("pause");
                    }
                    else {
                        system("cls");
                        cout << "Inventory:\n"
                            << setw(15) << left << "Item Number" 
                            << setw(15) << left << "Item Name" 
                            << setw(30) << left << "Description" 
                            << setw(15) << left << "Quantity" 
                            << setw(15) << left << "Cost" 
                            << setw(15) << left << "Item Location" << endl;
                        inv[index].print();
                        cout<<endl<<endl;
                        system("pause");
                    }
                }
                else continue;
                cin.ignore();
        } 
        else if (choice == 3) {
            break;
        } 
        else {
            cout << "Invalid choice, enter input in the range 1-3 only!\n";
            system("pause");
        }
    }
    system("cls");
    cout << "Inventory Management System\n\nThank you for using the system!\nExiting...\n";
    sleep(1);
    system("cls");
    return 0;
}


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


//sorting
//accending
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

//decending
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
int SeqSearch(inventory inv[], int n, const string& target, bool isLocation){
    for(int i = 0; i < n; i++){
        if(isLocation){
            if(inv[i].getItemLocation() == target){
                return i;
            }
        }
        else{
            if(inv[i].getItemName() == target){
                return i;
            }
        }
    }
    return -1;
}

int binarySearch(inventory inv[], int low, int high, int target){
    if(low > high){
        return -1;
    }
    int mid = (low + high) / 2;
    if(inv[mid].getItemNumber() == target){
        return mid;
    }
    else if(inv[mid].getItemNumber() > target){
        return binarySearch(inv, low, mid - 1, target);
    }
    else{
        return binarySearch(inv, mid + 1, high, target);
    }
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
