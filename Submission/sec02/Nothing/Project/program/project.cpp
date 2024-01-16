#include <iostream>
#include <fstream>

using namespace std;

class Inventory{
    private:
        int itemNumber;
        int quantity;
        double cost;
        double totalCost;
    public:
        Inventory();
        Inventory(int, int, double);
        void setItemNumber(int);
        void setQuantity(int);
        void setCost(double);
        void setTotalCost();
        int getItemNumber();
        int getQuantity();
        double getCost();
        double getTotalCost();
};
