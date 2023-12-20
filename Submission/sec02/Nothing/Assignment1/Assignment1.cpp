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
void mergeSort(inventory[], int, int, int);
void merge(inventory[], int, int, int, int);

//quicksort for decending
void quickSort(inventory[], int, int, int);
int partition(inventory[], int, int, int);

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
                    mergeSort(inv, 0, i - 1, sortChoice);
                } 
                else if (orderChoice == 2) {
                    quickSort(inv, 0, i - 1, sortChoice);
                } 
                else continue;
            }
            else if(sortChoice == 2){
                if (orderChoice == 1) {
                    mergeSort(inv, 0, i - 1, sortChoice);
                } 
                else if (orderChoice == 2) {
                    quickSort(inv, 0, i - 1, sortChoice);
                } 
                else continue;
            }
            else if(sortChoice == 3){
                if (orderChoice == 1) {
                    mergeSort(inv, 0, i - 1, sortChoice);
                } 
                else if (orderChoice == 2) {
                    quickSort(inv, 0, i - 1, sortChoice);
                } 
                else continue;
            }
            else if(sortChoice == 4){
                if (orderChoice == 1) {
                    mergeSort(inv, 0, i - 1, sortChoice);
                } 
                else if (orderChoice == 2) {
                    quickSort(inv, 0, i - 1, sortChoice);
                } 
                else continue;
            }
            else if(sortChoice == 5){
                if (orderChoice == 1) {
                    mergeSort(inv, 0, i - 1, sortChoice);
                } 
                else if (orderChoice == 2) {
                    quickSort(inv, 0, i - 1, sortChoice);
                } 
                else continue;
            }
            else if(sortChoice == 6) continue;
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
                    mergeSort(inv, 0, i - 1, 1);
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
void mergeSort(inventory inv[], int low, int high, int choice){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(inv, low, mid, choice);
        mergeSort(inv, mid + 1, high, choice);
        merge(inv, low, mid, high, choice);
    }
}
void merge(inventory inv[], int first, int mid, int last, int choice){
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    inventory temp[MAX];
    if(choice == 1){
        while((first1 <= last1) && (first2 <= last2)){
            if(inv[first1].getItemNumber() <= inv[first2].getItemNumber()){
                temp[index] = inv[first1];
                first1++;
            }
            else{
                temp[index] = inv[first2];
                first2++;
            }
            index++;
        }
    }
    else if(choice == 2){
        while((first1 <= last1) && (first2 <= last2)){
            if(inv[first1].getItemName() <= inv[first2].getItemName()){
                temp[index] = inv[first1];
                first1++;
            }
            else{
                temp[index] = inv[first2];
                first2++;
            }
            index++;
        }
    }
    else if(choice == 3){
        while((first1 <= last1) && (first2 <= last2)){
            if(inv[first1].getQuantity() <= inv[first2].getQuantity()){
                temp[index] = inv[first1];
                first1++;
            }
            else{
                temp[index] = inv[first2];
                first2++;
            }
            index++;
        }
    }
    else if(choice == 4){
        while((first1 <= last1) && (first2 <= last2)){
            if(inv[first1].getCost() <= inv[first2].getCost()){
                temp[index] = inv[first1];
                first1++;
            }
            else{
                temp[index] = inv[first2];
                first2++;
            }
            index++;
        }
    }
    else if(choice == 5){
        while((first1 <= last1) && (first2 <= last2)){
            if(inv[first1].getItemLocation() <= inv[first2].getItemLocation()){
                temp[index] = inv[first1];
                first1++;
            }
            else{
                temp[index] = inv[first2];
                first2++;
            }
            index++;
        }
    }
    for(; first1 <= last1; ++first1, ++index){
        temp[index] = inv[first1];
    }
    for(; first2 <= last2; ++first2, ++index){
        temp[index] = inv[first2];
    }
    for(index = first; index <= last; ++index){
        inv[index] = temp[index];
    }
}

//decending
void quickSort(inventory inv[], int first, int last, int choice){
    int cut;
    if(first < last){
        cut = partition(inv, first, last, choice);
        quickSort(inv, first, cut, choice);
        quickSort(inv, cut + 1, last, choice);
    }
}
int partition(inventory inv[], int first, int last, int choice){
    int cutPoint, bottom = first, top = last;
    inventory temp;
    if(choice == 1){
        int pivot = inv[first].getItemNumber();
        while(true){
            while(inv[bottom].getItemNumber() > pivot){
                bottom++;
            }
            while(inv[top].getItemNumber() < pivot){
                top--;
            }
            if(bottom < top){
                temp = inv[bottom];
                inv[bottom] = inv[top];
                inv[top] = temp;
                bottom++;
                top--;
            }
            else{
                cutPoint = top;
                break;
            }
        }
    }
    else if(choice == 2){
        string pivot = inv[first].getItemName();
        while(true){
            //decending
            while(inv[bottom].getItemName() > pivot){
                bottom++;
            }
            while(inv[top].getItemName() < pivot){
                top--;
            }
            if(bottom < top){
                temp = inv[bottom];
                inv[bottom] = inv[top];
                inv[top] = temp;
                bottom++;
                top--;
            }
            else{
                cutPoint = top;
                break;
            }
        }
    }
    else if(choice == 3){
        int pivot = inv[first].getQuantity();
        while(true){
            //decending
            while(inv[bottom].getQuantity() > pivot){
                bottom++;
            }
            while(inv[top].getQuantity() < pivot){
                top--;
            }
            if(bottom < top){
                temp = inv[bottom];
                inv[bottom] = inv[top];
                inv[top] = temp;
                bottom++;
                top--;
            }
            else{
                cutPoint = top;
                break;
            }
        }
    }
    else if(choice == 4){
        double pivot = inv[first].getCost();
        while(true){
            //decending
            while(inv[bottom].getCost() > pivot){
                bottom++;
            }
            while(inv[top].getCost() < pivot){
                top--;
            }
            if(bottom < top){
                temp = inv[bottom];
                inv[bottom] = inv[top];
                inv[top] = temp;
                bottom++;
                top--;
            }
            else{
                cutPoint = top;
                break;
            }
        }
    }
    else if(choice == 5){
        string pivot = inv[first].getItemLocation();
        while(true){
            //decending
            while(inv[bottom].getItemLocation() > pivot){
                bottom++;
            }
            while(inv[top].getItemLocation() < pivot){
                top--;
            }
            if(bottom < top){
                temp = inv[bottom];
                inv[bottom] = inv[top];
                inv[top] = temp;
                bottom++;
                top--;
            }
            else{
                cutPoint = top;
                break;
            }
        }
    }
    return cutPoint;
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
