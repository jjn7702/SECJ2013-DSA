#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cctype>
#include <cstring>

using namespace std;

// Constraints
// convert character to upper case
string changeToUpper(string value)
{
    for (int i = 0; i < value.length(); i++)
    {
        value[i] = toupper(value[i]);
    }

    return value;
}

// quantity cannot be < 0
bool checkQuantity(int q)
{
    return q > 0;
}

// Code format should be in IXXX (where X should be digit)
bool checkCode(string iCode)
{

    if (iCode.length() > 4)
        return false; // If length is more than 4 characters, it's invalid

    if (iCode[0] != 'I')
        return false; // The first character should be 'I'

    for (int i = 1; i < iCode.length(); i++)
    {
        if (!isdigit(iCode[i]))
        {
            return false;
        }
    }

    return true;
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
         << "5. Display Inventory List based on Category\n"
         << "6. Display Full Inventory List\n"
         << "7. Update an Inventory\n"
         << "8. Check Low Stock Inventory\n"
         << "9. Exit\n"
         << "Enter your choice: ";
    cin >> menuChoice;
    system("CLS");
    return menuChoice;
}

// Find menu
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

// update menu
int updateMenu()
{
    int choice;
    cout << "Choose the part you would like to update\n"
         << "[1] Inventory Name\n"
         << "[2] Inventory Type\n"
         << "[3] Quantity\n"
         << "[4] Price\n"
         << "[5] Exit\n"
         << "Your choice is: ";
    cin >> choice;
    system("CLS");
    return choice;
}

// Class Inventory
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

class Queue
{
private:
    Inventory *back;

public:
    // create an empty queue
    Queue() { back = NULL; }
    // check is empty
    bool isEmpty() { return back == NULL; }

    // Add Inventory
    void enQueue(Inventory *newInventory)
    {

        // case 1: queue is empty
        if (isEmpty())
        {
            back = newInventory;
            newInventory->next = back;
        }

        // case 2 : queue have thing inside
        else
        {
            newInventory->next = back->next;
            back->next = newInventory;
            back = newInventory;
        }
    }

    // Delete Inventory
    void deQueue()
    {

        // is empty
        if (isEmpty())
        {
            cout << "No nodes left!!" << endl;
        }

        else
        {
            Inventory *temp = back->next;

            if (back->next != back)
            { // more than 1 nodes
                back->next = temp->next;
            }

            else
            { // left only 1 nodes
                back = NULL;
            }

            temp->next = NULL;
            delete temp;
        }
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

    // Sort the Inventory
    void sort()
    {
        // case 1: The queue is empty
        if (isEmpty())
            cout << "The queue is empty\n";
        else
        {
            Inventory *first = back->next;                      // to point to the first node of original node as the back address is renewed afterward
            Inventory *curr = back->next;                       // point to current node of original queue, at first, point to the first node
            Inventory *sBack = new Inventory("", "", "", 0, 0); // to store the sortedQueue back pointer
            sBack->next = sBack;                                // to make it circular

            do
            {
                Inventory *Next = curr->next;
                // add at the front
                if (curr->getCode() < sBack->next->getCode())
                {
                    curr->next = sBack->next;
                    sBack->next = curr;
                }
                else // add at middle or end
                {
                    Inventory *temp = sBack->next->next; // point to the current node of sorted queue
                    Inventory *prev = sBack->next;

                    // to find the position where to put the current node of oriQ to sortedQ
                    while (temp != sBack->next && curr->getCode() > temp->getCode())
                    {
                        prev = temp;
                        temp = temp->next;
                    }

                    // add at end of sortedQ
                    if (temp == sBack->next)
                    {
                        curr->next = sBack->next;
                        sBack->next = curr;
                        sBack = curr;
                    }
                    // add at middle of sortedQ
                    else
                    {
                        prev->next = curr;
                        curr->next = temp;
                    }
                }
                curr = Next;
            } while (curr != first);
            // delete first node - the zero data
            sBack->next = sBack->next->next;
            // to link sortedQueue back to original queue
            back = sBack;
        }
        cout << "Inventory List is sorted by Inventory Code in Ascending\n";
        displayList();
    }

    // Find an inventory
    void find()
    {
        Inventory *temp = back->next;
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
            do
            {
                if (temp->getCode() == sKey)
                {
                    found = true;
                    printDetail(temp);
                }
                temp = temp->next;
            } while (temp != back->next && found == false);
        }
        else if (fChoice == 2)
        {
            cout << "Inventory Name: ";
            cin.ignore();
            getline(cin, sKey);
            sKey = changeToUpper(sKey);
            do
            {
                if (temp->getName() == sKey)
                {
                    found = true;
                    printDetail(temp);
                }
                temp = temp->next;
            } while (temp != back->next && found == false);
        }
        else
        {
            return;
        }

        if (found == false)
        {
            cout << "\nThe entered value is invalid!\n\n";
        }
    }

    // Display Inventory List based on category
    void dispCat()
    {
        string cat;
        cout << "Pls enter the category you wish to find: ";
        cin >> cat;
        cat = changeToUpper(cat);

        cout << "\n\t\t:::::::INVENTORY LIST IN CATEGORY " << cat << ":::::::\n"
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

        bool found = false;
        Inventory *temp = back->next;
        do
        {
            if (temp->getType() == cat)
            {
                cout << left << setw(20) << temp->getCode()
                     << setw(20) << temp->getName()
                     << setw(20) << temp->getType()
                     << setw(15) << temp->getQuantity()
                     << setw(10) << fixed << setprecision(2) << temp->getPrice() << endl
                     << endl;
                found = true;
            }
            temp = temp->next;
        } while (temp != back->next);

        if (!found)
        {
            cout << "There is no such category in inventory list. Pls try again\n\n";
        }
    }

    // Display Full Inventory List
    void
    displayList()
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

        Inventory *temp = back->next;

        do
        {
            cout << left << setw(20) << temp->getCode()
                 << setw(20) << temp->getName()
                 << setw(20) << temp->getType()
                 << setw(15) << temp->getQuantity()
                 << setw(10) << fixed << setprecision(2) << temp->getPrice() << endl
                 << endl;

            temp = temp->next;

        } while (temp != back->next);
    }

    // Update an Inventory
    void updateInventory()
    {
        string iCode, iName, iType;
        Inventory *temp = back->next;
        bool found = false;
        int choice, iQuantity;
        float iPrice;
        cout << "----------Update Inventory Info----------" << endl
             << "Enter the Inventory Code: ";
        cin >> iCode;
        iCode = changeToUpper(iCode);

        do
        {
            if (temp->getCode() == iCode)
            {
                found = true;
                printDetail(temp);
                break;
            }
            temp = temp->next;
        } while (temp != back->next);

        if (found == false)
        {
            cout << "The entered inventory code is invalid!\n\n";
            return;
        }

        choice = updateMenu();
        switch (choice)
        {
        case 1:
        {
            cout << "Enter a new inventory name: ";
            cin.ignore();
            getline(cin, iName);
            iName = changeToUpper(iName);

            // check duplicate
            bool dup = false;
            Inventory *findDup = back->next;
            do
            {
                if (iName == findDup->getName())
                {
                    dup = true;
                    break;
                }
                findDup = findDup->next;
            } while (findDup != back->next);

            if (dup == true)
            {
                cout << "The entered inventory name is duplicate!\n"
                     << "Unsuccessfully update!\n\n";
            }
            else
            {
                temp->putName(iName);
                system("CLS");
                cout << "The inventory with code [" << iCode << "] is updated!\n";
                printDetail(temp);
            }
            break;
        }

        case 2:
            cout << "Enter a new inventory type: ";
            cin.ignore();
            getline(cin, iType);
            iType = changeToUpper(iType);
            temp->putType(iType);
            system("CLS");
            cout << "The inventory with code [" << iCode << "] is updated!\n";
            printDetail(temp);
            break;

        case 3:
            cout << "Enter a new quantity: ";
            cin.ignore();
            cin >> iQuantity;
            if (checkQuantity(iQuantity))
            {
                temp->putQuantity(iQuantity);
                system("CLS");
                cout << "The inventory with code [" << iCode << "] is updated!\n";
                printDetail(temp);
            }
            else
            {
                cout << "The entered quantity is negative value!\n"
                     << "Unsuccessfully update!\n\n";
            }
            break;

        case 4:
            cout << "Enter a new price: ";
            cin >> iPrice;
            temp->putPrice(iPrice);
            system("CLS");
            cout << "The inventory with code [" << iCode << "] is updated!\n";
            printDetail(temp);
            break;

        default:
            return;
        }
    }

    // Check Low Stock Inventory
    void checkLowStock()
    {
        int min = 10;
        Inventory *temp = back->next;

        cout << "\t\t\t:::::::Low Stock Inventory:::::::\n"
             << "\n ***Please remember to buy the new inventory!!!***\n"
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

        do
        {
            if (temp->getQuantity() < min)
            {
                cout << left << setw(20) << temp->getCode()
                     << setw(20) << temp->getName()
                     << setw(20) << temp->getType()
                     << setw(15) << temp->getQuantity()
                     << setw(10) << fixed << setprecision(2) << temp->getPrice() << endl
                     << endl;
            }
            temp = temp->next;
        } while (temp != back->next);
    }

    // Store into database
    void storeData(ofstream &out)
    {
        Inventory *temp = back->next;
        do
        {
            out << temp->getCode() << ","
                << temp->getName() << ","
                << temp->getType() << ","
                << temp->getQuantity() << ","
                << fixed << setprecision(2) << temp->getPrice();

            if (temp->next != back->next)
                out << endl;
            temp = temp->next;
        } while (temp != back->next);
    }

    // check duplicate code
    bool checkDuplicateCode(string code)
    {
        if (isEmpty())
        {
            return false;
        }

        Inventory *temp = back->next;

        do
        {
            if (temp->getCode() == code)
                return true;
            temp = temp->next;

        } while (temp != back->next);

        return false;
    }

    bool checkDuplicateName(string name)
    {

        if (isEmpty())
        {
            return false;
        }

        Inventory *temp = back->next;

        do
        {
            if (temp->getName() == name)
                return true;
            temp = temp->next;

        } while (temp != back->next);

        return false;
    }
};

// get info for added inventory
void getInfo(Queue &InvList, string &code, string &name, string &type, int &quantity, float &price)
{
    cout << "----------New inventory Info----------" << endl;

    while (true)
    {
        cout << "Enter Inventory Code: ";
        cin >> code;

        // Check code format
        bool checkc = checkCode(code);
        // Check duplicate
        bool checkd = InvList.checkDuplicateCode(code);

        if (checkc && !checkd)
            break; // both condition meet only can out the loop

        else
        {
            cout << "Invalid code!";
            if (!checkc)
            {
                cout << " Re-enter your code (IXXX) where X should be a digit." << endl;
            }
            else if (checkd)
            {
                cout << " The code already exists." << endl;
            }
        }
    }
    code = changeToUpper(code);

    while (true)
    {
        cout << "Enter Inventory Name: ";
        cin.ignore();
        getline(cin, name);
        name = changeToUpper(name);

        // Check duplicate name
        bool checkDuplicateName = InvList.checkDuplicateName(name);

        if (!checkDuplicateName)
        {
            break; // Break the loop if no duplicate name is found
        }
        else
        {
            cout << "Invalid name! The name already exists. Re-enter." << endl;
        }
    }

    cout << "Enter Inventory Type: ";
    getline(cin, type);
    type = changeToUpper(type);

    cout << "Enter Quantity: ";
    cin >> quantity;
    // check quantity must >0
    bool checkq = checkQuantity(quantity);
    while (!checkq)
    {
        cout << "Invalid quantity! Reenter! " << endl;
        cout << "Enter Quantity: ";
        cin >> quantity;
        checkq = checkQuantity(quantity);
    }

    cout << "Enter Price: ";
    cin >> price;
}

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
        InvList.enQueue(inv);
    }

    inp.close();

    // Menu
    cout << "~~~~~~~~~~~~~~~~~~~~~  WELCOME TO INVENTORY MANAGEMENT SYSTEM  ~~~~~~~~~~~~~~~~~~~~~\n\n";
    while (loop)
    {
        menuChoice = mainMenu();
        switch (menuChoice)
        {
        case 1:
        {
            getInfo(InvList, code, name, type, quantity, price);
            Inventory *newInventory = new Inventory(code, name, type, quantity, price);
            InvList.enQueue(newInventory);
            cout << "Congrats! You inventory has been added!" << endl
                 << endl;
            break;
        }

        case 2:
        {
            InvList.deQueue();
            cout << "Congrats! Your first inventory has been deleted!" << endl
                 << endl;
            break;
        }

        case 3:
            InvList.sort();
            break;
        case 4:
            InvList.find();
            break;
        case 5:
            InvList.dispCat();
            break;
        case 6:
            InvList.displayList();
            break;
        case 7:
            InvList.updateInventory();
            break;
        case 8:
            InvList.checkLowStock();
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
    InvList.storeData(out);
    //  close both files
    out.close();
    system("pause");
    return 0;
}