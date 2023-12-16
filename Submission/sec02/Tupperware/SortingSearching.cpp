#include <iostream>
#include <fstream>

using namespace std;

class Customer {
    private:
        int tableNum;
        int numberOfOrders;
        int pax;
        double bill;
};

class Menu {
    private:
        string menuId;
        string name;
        string category;
        double amount;
        double price;
};