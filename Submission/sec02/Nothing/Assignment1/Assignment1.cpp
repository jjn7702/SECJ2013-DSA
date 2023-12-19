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
}A
