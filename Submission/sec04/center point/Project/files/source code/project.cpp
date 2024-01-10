#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cctype>
#include <cstring>
using namespace std;

// Constraints
//convert character to upper case
string changeToUpper(string value)
{
    for (int i = 0; i < value.length(); i++)
    {
        value[i] = toupper(value[i]);
    }

    return value;
}

//quantity cannot be < 0
bool checkQuantity(int q){
    return q >= 0;
}

//Code format should be in IXXX (where X should be digit)
bool checkCode(string iCode){
    bool result = true;
    int count = 0;

    while(count < iCode.length()){
        char c = iCode[count];

        if(count == 0){
            if(c != 'I')
                result = false;
        }else{
            if(!isdigit(c))
                result = false;
        }
    }

    if(iCode.length() > 4){
        result = false;
    }

    return result;
}



// Main Menu
int mainMenu()
{
    int menuChoice;
    cout << "What do you need?\n"
         << "1. Add Inventory\n"
         << "2. Delete Inventory\n"
         << "3. Sort the Inventory\n"
         << "4. Find an Inventory\n"
         << "5. Display Inventory List based on category\n"
         << "6. Display Full Inventory List\n"
         << "7. Update an Inventory\n"
         << "8. Check Low Stock Inventory\n"
         << "9. Exit\n"
         << "Enter your choice: ";
    cin >> menuChoice;
    system("CLS");
    return menuChoice;
}

//Class Inventory
class Inventory
{
private:
    string invCode, invName, invType;
    int quantity;
    float price;

public:
    Inventory *next;

    Inventory(string c, string n, string t, int q, float p)
    {
        invCode = c;
        invName = n;
        invType = t;
        quantity = q;
        price = p;
        next = NULL;
    }

    void putCode(string c) { invCode = c; }
    void putName(string n) { invName = n; }
    void putType(string t) { invType = t; }
    void putQuantity(int q) { quantity = q; }
    void putPrice(float p) { price = p; }

    string getCode() { return invCode; }
    string getName() { return invName; }
    string getType() { return invType; }
    int getQuantity() { return quantity; }
    float getPrice() { return price; }
};

class Queue{
    private:
        Inventory *back; 

    public:
        Queue(){back = NULL;}
        bool isEmpty(){
            return back==NULL;
        }
        //Add Inventory
        void enQueue(){};
        //Delete Inventory
        //Sort the Inventory
        //Find an inventory
        //Display Inventory List based on category
        //Display Full Inventory List
        //Update an Inventory
        //Check Low Stock Inventory
        //Store into database
};

int main()
{
    string code, name, type;
    int quantity, menuChoice, addChoice;
    float price;
    Queue InvList;
    ifstream inp;
    ofstream out;
    bool loop = true;
    inp.open("input.txt");

    // Check input file
    if (!inp)
    {
        cout << "Cannot open the input file\n";
        return 0;
    }

    // retrieve the data from input.txt file and store them into linkedlist
    while (!inp.eof())
    {
        getline(inp, code, ',');
        getline(inp, name, ',');
        getline(inp, type, ',');
        inp >> quantity;
        inp.ignore();
        inp >> price;
        inp.ignore();
        Inventory *inv = new Inventory(code, name, type, quantity, price);
        //InvList.enQueue(inv);
    }

    inp.close();

    //Menu
    cout << "~~~~~~~~~~~~~~~~~~~~~  WELCOME TO INVENTORY MANAGEMENT SYSTEM  ~~~~~~~~~~~~~~~~~~~~~\n\n";
    while (loop)
    {
        menuChoice = mainMenu();
        switch (menuChoice)
        {
        case 1:
            break;   
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            loop = false;
            break;
        default:
            cout << "Please enter a valid choice! :)\n";
            break;
        }
    }

    out.open("input.txt");
    //InvList.storeData(out);
    // close both files
    out.close();
    system("pause");
    return 0;
}