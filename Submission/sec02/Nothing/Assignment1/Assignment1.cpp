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


