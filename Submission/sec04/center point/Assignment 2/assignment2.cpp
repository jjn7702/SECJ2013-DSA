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

//get info for added inventory
void getInfo(string &code, string &name, string &type, int &quantity, float &price) {
    cout<<"\n----------New inventory Info----------"<<endl;
    cout << "Enter Inventory Code: ";
    cin >> code;

    cout << "Enter Inventory Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Inventory Type: ";
    getline(cin, type);

    cout << "Enter Quantity: ";
    cin >> quantity;

    cout << "Enter Price: ";
    cin >> price;
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
    void displayList()
    {
        cout << "\t\t\t:::::::Inventory List:::::::\n"<<endl;
        for(int i=0;i<84;i++){
            cout<<"-";
        }
        cout<<endl;
        cout << left << setw(20) << "Inventory Code"
             << setw(20) << "Inventory Name"
             << setw(20) << "Inventory Type"
             << setw(15) << "Quantity"
             << setw(10) << "Price" << endl;

        for(int i=0;i<84;i++){
            cout<<"-";
        }
        cout<<endl;


        Inventory *temp = head;
        while (temp != NULL)
        {
            cout << left << setw(20)<<temp->getCode()
             << setw(20) << temp->getName()
             << setw(20) << temp->getType()
             << setw(15) << temp->getQuantity()
             << setw(10) << fixed<<setprecision(2)<<temp->getPrice()<<endl;

            if (temp->next != NULL) cout << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    string code, name, type;
    int quantity, choice, mChoice, count = 0;
    int menuChoice;
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
        InvList.addEnd(inv);
        count++;
    }

    InvList.displayList();

    //menu
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~  WELCOME TO INVENTORY MANAGEMENT SYSTEM  ~~~~~~~~~~~~~~~~~~~~~\n\n";
    while (loop)
    {   
        cout<<"What do you need?"<<endl;

        cout << "1. Add Inventory\n";
        
        cout << "Enter your choice: ";
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            system("cls");
            int addchoice = AddChoice();
            if (addchoice == 1)
            {
                getInfo(code,name,type,quantity,price);
                Inventory *newInventory = new Inventory(code,name,type,quantity,price);
                InvList.addFront(newInventory);
                cout<<"New node has been successfully added to front.."<<endl<<endl;
            }

            else if (addchoice == 2)
            {
                int pos;
                cout << "Enter the position to add in the middle: ";
                cin >> pos;
                getInfo(code,name,type,quantity,price);
                Inventory *newInventory = new Inventory(code,name,type,quantity,price);
                InvList.addMiddle(newInventory, pos);
                cout<<"New node has been successfully added to position "<<pos<<".."<<endl<<endl;
            }

            else if (addchoice == 3)
            {
                getInfo(code,name,type,quantity,price);
                Inventory *newInventory = new Inventory(code,name,type,quantity,price);
                InvList.addEnd(newInventory);
                cout<<"New node has been successfully added to the end.."<<endl<<endl;
            }
            else
            {
                cout << "Invalid choice. Inventory will be added to the end by default.." << endl;
                Inventory *newInventory = new Inventory(code,name,type,quantity,price);
                InvList.addEnd(newInventory);
                cout<<"New node has been successfully added to the end.."<<endl<<endl;
            }

            break;

            //case2
            //case3
            //
        }
    }
    

    // close both files
    inp.close();
    out.close();
    system("pause");
    return 0;
}