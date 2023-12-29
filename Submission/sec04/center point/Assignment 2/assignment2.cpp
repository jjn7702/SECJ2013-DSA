#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Adding user choice
int AddChoice(){
    int choice;

    cout << "Please choose where to add the new inventory:\n";
    cout << "1. Add to the front\n";
    cout << "2. Add to the middle\n";
    cout << "3. Add to the end\n";
    cout << "Enter your choice (1/2/3): ";
    cin >> choice;

    while (choice<1 || choice>3) // check user input
    {
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
        cin >> choice;
    }

    return choice;
}



class Inventory
{
private:
    string invCode, invName, invType;
    int quantity;
    float price;

public:
    Inventory *next;
    /*Inventory()
    {
        invCode = invName = invType = "";
        quantity = 0;
        price = 0.0;
        next = NULL;
    }*/

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
    void addFront(Inventory *newInventory){
        if(isEmpty()){head=newInventory;}
        else{
            newInventory->next=head;
            head=newInventory;
        }
    }

    // Add in the end
    void addEnd(Inventory *newInventory)
    {
        Inventory *temp = head;
        if (isEmpty()) head = newInventory;
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newInventory->next = NULL;
            temp->next = newInventory;
        }
    }


    // Add in middle
    void addMiddle(Inventory *newInventory, int position){
        if(isEmpty()){head=newInventory;}
        if(position>=1){addFront(newInventory);}

        Inventory *temp=head;
        int count=1;

        while(temp->next!=NULL && count<position-1){
            temp=temp->next;
            count++;
        }

        if (count == position - 1){
            newInventory->next = temp->next;
            temp->next = newInventory;
        }

        else
        { 
          cout << "Invalid position..Automatically add to end..."<<endl;
          addEnd(newInventory);
        }

    }

    //-Delete inventory-
    // Delete in front
    // Delete at the middle
    // Delete at the end

    // Auto Sort the node before display

    // Finding a node based in sKey

    // Display all the node
    void print()
    {
        Inventory *temp = head;
        while (temp != NULL)
        {
            cout << temp->getCode() << ","
                 << temp->getName() << ","
                 << temp->getType() << ","
                 << temp->getQuantity() << ","
                 << temp->getPrice();

            if (temp->next != NULL) cout << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    string code, name, type;
    int quantity, choice, mChoice, count = 0;
    float price;
    List InvList;
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
        Inventory *inv = new Inventory(code, name, type, quantity, price);
        InvList.addEnd(inv);
        count++;
    }

    InvList.print();

    // close both files
    inp.close();
    out.close();
    system("pause");
    return 0;
}