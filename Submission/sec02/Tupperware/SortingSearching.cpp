#include <iostream>
#include <fstream>
#include <string>
#define SIZE 30
using namespace std;


class Customer{
    private:
        int tableNumber;
        int numOfOrder;
        int pax;
        double payment;

    public:
        Customer();
        Customer(int tn, int orders, int people, double pay){
            tableNumber = tn;
            numOfOrder = orders;
            pax = people;
            payment = pay;
        }
};

class Menu{
    private:
        string foodId;
        string name;
        string category;
        double amount;
        double price;
};

//PART WANO
void merge(string menuArray[], string str1, string str2){

    string tempArray[SIZE];
    string

}