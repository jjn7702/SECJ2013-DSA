#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

// toUpper
string changeToUpper(string value)
{
    for (int i = 0; i < value.length(); i++)
    {
        value[i] = toupper(value[i]);
    }

    return value;
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
         << "5. Display Inventory List\n"
         << "6. Exit\n"
         << "Enter your choice: ";
    cin >> menuChoice;
    system("CLS");
    return menuChoice;
}

// Adding user choice
int AddChoice()
{
    int choice;

    cout << "Please choose where to add the new inventory:\n"
         << "[1] Add to the front\n"
         << "[2] Add to the middle\n"
         << "[3] Add to the end\n"
         << "[4] Exit\n"
         << "Enter your choice: ";
    cin >> choice;

    while (choice < 1 || choice > 4) // check user input
    {
        cout << "Invalid choice. Please enter 1, 2, 3 or 4: ";
        cin >> choice;
    }
    system("CLS");
    return choice;
}

// Delete node choice
int delMenu()
{
    int choice;

    cout << "Please choose where to delete the inventory item:\n"
         << "[1] Delete at the front\n"
         << "[2] Delete at the middle\n"
         << "[3] Delete at the end\n"
         << "[4] Exit\n"
         << "Enter your choice: ";
    cin >> choice;

    if (choice < 1 || choice > 4)
        throw "Pls enter valid delete choice!!!\n";

    system("CLS");
    return choice;
}

// Finding user choice
int menuFinding()
{
    int fchoice;
    cout << "Do you want to find the inventory details based on\n"
         << "[1] Inventory Code" << endl
         << "[2] Inventory Name" << endl
         << "[3] Exit" << endl
         << "Option: ";
    cin >> fchoice;
    system("CLS");
    return fchoice;
}

// get info for added inventory
void getInfo(string &code, string &name, string &type, int &quantity, float &price)
{
    cout << "----------New inventory Info----------" << endl;
    cout << "Enter Inventory Code: ";
    cin >> code;
    code = changeToUpper(code);

    cout << "Enter Inventory Name: ";
    cin.ignore();
    getline(cin, name);
    name = changeToUpper(name);

    cout << "Enter Inventory Type: ";
    getline(cin, type);
    type = changeToUpper(type);

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

class List
{
    Inventory *head;

public:
    List() { head = NULL; }
    bool isEmpty() { return head == NULL; }

    //-Adding new inventory-
    // Add in front
    void addFront(Inventory *newInventory)
    {
        if (isEmpty())
        {
            head = newInventory;
        }
        else
        {
            newInventory->next = head;
            head = newInventory;
        }
    }

    // Add in the end
    void addEnd(Inventory *newInventory)
    {
        Inventory *temp = head;
        if (isEmpty())
            head = newInventory;
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
    void addMiddle(Inventory *newInventory, int position)
    {
        Inventory *temp = head;
        int count = 1;
        bool found = false;

        if (isEmpty())
        {
            head = newInventory;
            found = true;
        }

        if (position == 1)
        {
            addFront(newInventory);
            found = true;
        }

        while (temp->next != NULL && count < position - 1 && !found)
        {
            temp = temp->next;
            count++;
        }

        if (!found)
        {
            newInventory->next = temp->next;
            temp->next = newInventory;
            found = true;
        }
    }

    // Display all the node
    void displayList()
    {
        cout << "\t\t\t:::::::Inventory List:::::::\n"
             << endl;
        for (int i = 0; i < 84; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << left << setw(20) << "Inventory Code"
             << setw(20) << "Inventory Name"
             << setw(20) << "Inventory Type"
             << setw(15) << "Quantity"
             << setw(10) << "Price" << endl;

        for (int i = 0; i < 84; i++)
        {
            cout << "-";
        }
        cout << endl;

        Inventory *temp = head;
        while (temp != NULL)
        {
            cout << left << setw(20) << temp->getCode()
                 << setw(20) << temp->getName()
                 << setw(20) << temp->getType()
                 << setw(15) << temp->getQuantity()
                 << setw(10) << fixed << setprecision(2) << temp->getPrice() << endl
                 << endl;

            temp = temp->next;
        }
    }

    //-Delete inventory-
    // Delete in front
    void delFront()
    {
        Inventory *temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at the middle
    void delMid(int pos)
    {
        if (pos == 1)
            delFront();
        else
        {
            Inventory *temp = head;
            // to let temp point to the previous node to be deleted
            for (int i = 1; (i < (pos - 1)) && temp; i++)
            {
                {
                    temp = temp->next;
                }
            }
            // if temp=NULL (the delete position is bigger than the current amount of nodes in list)
            if (!temp)
            {
                cout << "Error: Your entered position of node that to be deleted is out of the range of current list. \n\n";
                return;
            }
            // if the temp->next (node to be deleted) = last node => DELETE AT THE END
            else if (temp->next->next == NULL)
            {
                delete temp->next;
                temp->next = NULL;
            }
            else
            {
                Inventory *prev = temp;
                temp = temp->next;
                prev->next = temp->next;
                delete temp;
            }
        }
    }

    // Delete at the end
    void delEnd()
    {
        Inventory *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    // main delete function
    void del()
    {
        if (isEmpty())
        {
            cout << "Error: The inventory list is empty. Cannot delete any inventory anymore\n";
            return;
        }
        int delOpt;
        try
        {
            delOpt = delMenu();
        }
        catch (const char *msg)
        {
            cout << "Error: " << msg << endl
                 << endl;
            return;
        }
        switch (delOpt)
        {
        case 1:
            delFront();
            break;
        case 2:
            int delPos;
            cout << "Pls enter the position of inventory node you wish to delete: (eg. 1,2,3,...)\n";
            cin >> delPos;
            delMid(delPos);
            break;
        case 3:
            delEnd();
            break;
        default:
            return;
        }
        cout << "The current inventory list after your delete operation be like: \n";
        displayList();
    }

    // Sorting the inventory
    void sorting()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        Inventory *sortedList = NULL;
        Inventory *curr = head;

        while (curr)
        {
            Inventory *next = curr->next;

            if (sortedList == NULL || curr->getCode() < sortedList->getCode())
            {
                curr->next = sortedList;
                sortedList = curr;
            }
            else
            {
                Inventory *temp = sortedList;
                while (temp->next != NULL && temp->next->getCode() < curr->getCode())
                {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = next;
        }

        head = sortedList;

        cout << "Inventory List is sorted by Inventory Code in Ascending\n";
        displayList();
    }

    // Print detail of certain inventory
    void printDetail(Inventory *inv)
    {
        cout << "\n---Inventory Detail---\n"
             << "Inventory Code: " << inv->getCode() << endl
             << "Inventory Name: " << inv->getName() << endl
             << "Inventory Type: " << inv->getType() << endl
             << "Quantity:       " << inv->getQuantity() << endl
             << "Price:          " << inv->getPrice() << endl
             << endl;
    }

    // Finding a node based in sKey
    void find()
    {
        Inventory *temp = head;
        bool found = 0;
        int fChoice = menuFinding();
        string sKey;

        cout << "--Find the Inventory--\n\n"
             << "Please enter the value of ";

        if (fChoice == 1)
        {
            cout << "Inventory Code: ";
            cin >> sKey;
            sKey = changeToUpper(sKey);
            while (temp->next != NULL && found == false)
            {
                if (temp->getCode() == sKey)
                {
                    found = true;
                    printDetail(temp);
                }
                temp = temp->next;
            }
        }
        else if (fChoice == 2)
        {
            cout << "Inventory Name: ";
            cin.ignore();
            getline(cin, sKey);
            sKey = changeToUpper(sKey);
            while (temp->next != NULL && found == false)
            {
                if (temp->getName() == sKey)
                {
                    found = true;
                    printDetail(temp);
                }
                temp = temp->next;
            }
        }
        else
        {
            return;
        }

        if (found == false)
        {
            cout << "\nThe entered value is invalid!\n";
        }
    }

    // Store into database
    void storeData(ofstream &out)
    {
        Inventory *temp = head;
        while (temp != NULL)
        {
            out << temp->getCode() << ","
                << temp->getName() << ","
                << temp->getType() << ","
                << temp->getQuantity() << ","
                << fixed << setprecision(2) << temp->getPrice();

            if (temp->next != NULL)
                out << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    string code, name, type;
    int quantity, menuChoice, addChoice;
    float price;
    List InvList;
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
        InvList.addEnd(inv);
    }
    inp.close();

    // menu
    cout << "~~~~~~~~~~~~~~~~~~~~~  WELCOME TO INVENTORY MANAGEMENT SYSTEM  ~~~~~~~~~~~~~~~~~~~~~\n\n";
    InvList.displayList();
    while (loop)
    {
        menuChoice = mainMenu();
        switch (menuChoice)
        {
        case 1:
        {
            addChoice = AddChoice();
            Inventory *newInventory = new Inventory(code, name, type, quantity, price);
            switch (addChoice)
            {
            case 1:
                getInfo(code, name, type, quantity, price);
                InvList.addFront(newInventory);
                system("CLS");
                cout << "New node has been successfully added to front.." << endl
                     << endl;
                break;
            case 2:
                getInfo(code, name, type, quantity, price);
                int pos;
                cout << "\n***If the position entered is invalid, it'll automatically insert at the end.***\n"
                     << "Enter the position to add in the middle: ";
                cin >> pos;
                InvList.addMiddle(newInventory, pos);
                cout << "New node has been successfully added to position " << pos << ".." << endl
                     << endl;
                break;
            case 3:
                getInfo(code, name, type, quantity, price);
                InvList.addEnd(newInventory);
                cout << "New node has been successfully added to the end.." << endl
                     << endl;
                break;
            case 4:
                break;

            default:
                break;
            }
        }
        case 2:
            InvList.del();
            break;
        case 3:
            InvList.sorting();
            break;
        case 4:
            InvList.find();
            break;
        case 5:
            InvList.displayList();
            break;
        case 6:
            loop = false;
            break;
        default:
            cout << "Please enter a valid choice! :)\n";
            break;
        }
    }

    out.open("input.txt");
    InvList.storeData(out);
    // close both files
    out.close();
    system("pause");
    return 0;
}