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


