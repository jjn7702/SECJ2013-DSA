// Assignment 1 - SECJ2013 - 23241 (Assg1.cpp)
// Group Members:
// 1. Muhammad Iman Firdaus Bin Baharuddin
// 2. Muhammad Ariff Danish Bin Hashnan
// 3. Che Marhumi 
#include <iostream>
#include <string>
#include<sstream>
#include <fstream>
#include<iomanip>
using namespace std;

// Task Create Class (Iman)
class Cust
{
    private:
    string name; int day,month,years;
    public:
    Cust(string x, int z,int c, int v)
    {
        name=x;
        day=z;
        month=c;
        years=v;
    }
    void printResult()
    {   cout<<left<<setw(15)<<name<<setw(2)<<day<< " / "<<setw(2)<<month<<" / "<<setw(2)<<years<<endl;
        
    }
    int getdate()
   {
    return day+years*10000+month*100;
   }

    string getName()
    {
        return name;
    }
};

// function implementation
void listcust(Cust* cl[], int size) {
    for (int i = 0; i < size; i++) {
        cl[i]->printResult();
    }
}

void sortname(Cust* cl[], int size){ //bubble sort
    int pass; 
    Cust* tempValue;
    
    for (pass =1; pass < size; pass++){ // moves the largest element to the
    // end of the array
        for (int x = 0; x < size - pass; x++){ // compare adjacent elements
            if ( cl[x]-> getName() > cl[x+1] ->getName() ){ // swap elements
            tempValue = cl[x];
                cl[x] = cl[x + 1];
                cl[x + 1] = tempValue;
            }
        }  
    }
} // end Bubble Sort


void sortdate(Cust* cl[], int size){ //bubble sort
    int pass; 
    Cust* tempValue;
    
    for (pass =1; pass < size; pass++){ // moves the largest element to the
    // end of the array
        for (int x = 0; x < size - pass; x++){ // compare adjacent elements
            if ( cl[x]-> getdate() > cl[x+1] ->getdate() ){ // swap elements
                tempValue = cl[x];
                cl[x] = cl[x + 1];
                cl[x + 1] = tempValue;
            }
        }  
    }
}


// Task int main (Ariff)


