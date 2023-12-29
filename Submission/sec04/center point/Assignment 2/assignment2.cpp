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

    Inventory(string c, string n, string t, int q, float p)
    {
        invCode = c;
        invName = n;
        invType = t;
        quantity = q;
        price = p;
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
    void addFront(Inventory d){
        Inventory *newInventory= new Inventory(d);
        if(head==NULL){head=newInventory;}
        else{
            Inventory* temp;
            temp=newInventory;
            temp->next=head;
            
        }
    }
    
    // Add in middle
    void addMiddle(Inventory d, int position){
        Inventory *newInventory= new Inventory(d);
        Inventory*temp=head;
        int count=1;

        while(temp->next!=NULL && count<position-1){
            temp=temp->next;
            count++;
        }
        newInventory->next=temp->next;
        temp->next =newInventory;
    }
    

    // Add in the end 
    void addEnd(Inventory d){
        Inventory *newInventory= new Inventory(d);
        Inventory *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next= newInventory;
        newInventory->next=NULL;

    }

    //write the added Inventory list to file
    void writeListToFile(string filename){
        ofstream outFile;
        outFile.open(filename);

        if(!outFile){
            cout<<"Error while opening output file..."<<endl;
            return;
        }

        Inventory* temp = head;

        while (temp != NULL) {
            outFile << temp->getCode() << ","
                    << temp->getName() << ","
                    << temp->getType() << ","
                    << temp->getQuantity() << ","
                    << temp->getPrice();

            if (temp->next != NULL) {
                outFile << endl;
            }

            temp = temp->next;
        }
        outFile.close();
    }

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
    //Inventory inv[5];

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
    /*while (!inp.eof())
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
    } */

    //create an inventory list
    List myList;

    //add Inventory
    //add front
    myList.addFront(Inventory("ADD001","Clock","Accessories",3,18.90));
    //add middle (exp:add at 3th position)
    myList.addMiddle(Inventory("ADD002", "Watch", "Accessories", 1, 29.99), 3);
    //add End
    myList.addEnd(Inventory("ADD003","Mirror","LifeNeeds",2,5.80));

    myList.writeListToFile("Output.txt");
    

    // close both files
    inp.close();
    out.close();
    system("pause");
    return 0;
}