#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Inventory
{
private:
    string invCode, invName, invType;
    int quantity;
    float price;

public:
    Inventory *next;
    Inventory()
    {
        invCode = invName = invType = "";
        quantity = 0;
        price = 0.0;
        next = NULL;
    }

    /*Inventory(string c, string n, string t, int q, float p)
    {
        invCode = c;
        invName = n;
        invType = t;
        quantity = q;
        price = p;
    }*/

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

    void display()
    {
        cout << left << setw(15) << invCode
             << setw(15) << invName
             << setw(15) << invType
             << setw(10) << quantity
             << setw(5) << fixed << setprecision(2) << price;
    }
};

class List
{
    Inventory *head;

public:
    List() { head = NULL; }
    bool isEmpty() { return head == NULL; }

    //-Adding new inventory-
    // Add in front
    // Add in middle
    // Add in the end

    //-Delete inventory-
    // Delete in front
    // Delete at the middle
    // Delete at the end

    // Auto Sort the node before display

    // Finding a node based in sKey

    // Display all the node
};

int main()
{
    string code, name, type;
    int quantity, counter = 0, choice, mChoice;
    float price;
    Inventory inv[5];
    ifstream inp;
    ofstream out;
    bool loop = true;
    inp.open("input.txt");
    out.open("output.txt");

    // Check input file
    if (!inp)
    {
        cout << "Cannot open the input file]\n";
        return 0;
    }

    // retrieve the data from input.txt file and store them into array
    while (!inp.eof())
    {
        getline(inp, code, ',');
        getline(inp, name, ',');
        getline(inp, type, ',');
        inp >> quantity;
        inp.ignore();
        inp >> price;
        inp.ignore();
        inv[counter].putCode(code);
        inv[counter].putName(name);
        inv[counter].putType(type);
        inv[counter].putQuantity(quantity);
        inv[counter].putPrice(price);
        counter++;
    }

    for (int i = 0; i < counter; i++)
    {
        out << inv[i].getCode() << ","
            << inv[i].getName() << ","
            << inv[i].getType() << ","
            << inv[i].getQuantity() << ","
            << inv[i].getPrice();

        if (i != counter - 1)
        {
            out << endl;
        }
    }

    // close both files
    inp.close();
    out.close();
    system("pause");
    return 0;
}