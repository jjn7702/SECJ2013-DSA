#include <iostream>
#include <fstream>
<<<<<<< Updated upstream

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
=======
#include <string>

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
>>>>>>> Stashed changes
        string name;
        string category;
        double amount;
        double price;
};