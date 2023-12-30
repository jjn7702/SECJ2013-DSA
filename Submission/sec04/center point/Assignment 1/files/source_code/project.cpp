#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <istream>
#include <cctype>
#include <string>
#define SIZE 10
using namespace std;

class Inventory
{
private:
    string invCode, invName, invType;
    int quantity;
    float price;

public:
    Inventory()
    {
        invCode = invName = invType = "";
        quantity = 0;
        price = 0.0;
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
        cout << left << setw(20) << invCode
             << setw(20) << invName
             << setw(20) << invType
             << setw(15) << quantity
             << setw(10) << fixed << setprecision(2) << price;
    }
};

int mainMenu()
{
    int mchoice;
    cout << "Do you want to\n"
         << "[1] Sorting" << endl
         << "[2] Searching" << endl
         << "[3] Exit" << endl
         << "Option: ";
    cin >> mchoice;
    system("CLS");
    return mchoice;
}

int menu()
{
    int choice;
    cout << "[1] By Inventory Code" << endl
         << "[2] By Inventory Name" << endl
         << "[3] By Inventory Type" << endl
         << "[4] By Quantity" << endl
         << "[5] By Price" << endl
         << "Option: ";
    cin >> choice;
    if (choice < 1 || choice > 5)
        throw "Please enter valid sort choice!!!";
    system("CLS");
    return choice;
}

int menuSearch()
{
    int choice;
    cout << "[1] By Inventory Code" << endl
         << "[2] By Inventory Name" << endl
         << "Option: ";
    cin >> choice;
    if (choice != 1 && choice != 2)
        throw "Please enter valid search choice!!!";
    system("CLS");
    return choice;
}
int sortMenu()
{
    int orderChoice;
    cout << "You would like to sort by\n"
         << "[1] Ascending\n"
         << "[2] Descending\n"
         << "Your Option: ";
    cin >> orderChoice;
    if (orderChoice != 1 && orderChoice != 2)
        throw "Please enter valid order choice!!!";
    system("CLS");
    return orderChoice;
}

// Display list
void disList(Inventory inv[], int n)
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

    for (int i = 0; i < n; i++)
    {
        inv[i].display();
        cout << endl;
    }

    cout << endl;
}
// Improved Bubble Sort
void sort(Inventory data[], int n)
{
    int sortChoice, orderChoice;
    try
    {
        sortChoice = menu();
        orderChoice = sortMenu();
    }
    catch (const char *msg)
    {
        cout << "Error: " << msg << endl
             << endl;
        return;
    }
    bool sorted = false;
    string sortType;
    for (int p = 1; (p < n) && !sorted; ++p)
    {
        sorted = true;
        for (int x = 0; x < n - p; ++x)
        {
            switch (sortChoice)
            {
            case 1:
                sortType = "Inventory Code";
                if (orderChoice == 1)
                {
                    if (data[x].getCode() > data[x + 1].getCode())
                    {
                        Inventory temp = data[x];
                        data[x] = data[x + 1];
                        data[x + 1] = temp;
                        sorted = false;
                    }
                }
                else
                {
                    if (data[x].getCode() < data[x + 1].getCode())
                    {
                        Inventory temp = data[x];
                        data[x] = data[x + 1];
                        data[x + 1] = temp;
                        sorted = false;
                    }
                }
                break;
            case 2:
                sortType = "Inventory Name";
                if (orderChoice == 1)
                {
                    if (data[x].getName() > data[x + 1].getName())
                    {
                        Inventory temp = data[x];
                        data[x] = data[x + 1];
                        data[x + 1] = temp;
                        sorted = false;
                    }
                }
                else
                {
                    if (data[x].getName() < data[x + 1].getName())
                    {
                        Inventory temp = data[x];
                        data[x] = data[x + 1];
                        data[x + 1] = temp;
                        sorted = false;
                    }
                }
                break;

            case 3:
                sortType = "Inventory Type";
                if (orderChoice == 1)
                {
                    if (data[x].getType() > data[x + 1].getType())
                    {
                        Inventory temp = data[x];
                        data[x] = data[x + 1];
                        data[x + 1] = temp;
                        sorted = false;
                    }
                }
                else if (orderChoice == 2)
                {
                    if (data[x].getType() < data[x + 1].getType())
                    {
                        Inventory temp = data[x];
                        data[x] = data[x + 1];
                        data[x + 1] = temp;
                        sorted = false;
                    }
                }
                break;

            case 4:
                sortType = "Quantity";
                if (orderChoice == 1)
                {
                    if (data[x].getQuantity() > data[x + 1].getQuantity())
                    {
                        Inventory temp = data[x];
                        data[x] = data[x + 1];
                        data[x + 1] = temp;
                        sorted = false;
                    }
                }
                else
                {
                    if (data[x].getQuantity() < data[x + 1].getQuantity())
                    {
                        Inventory temp = data[x];
                        data[x] = data[x + 1];
                        data[x + 1] = temp;
                        sorted = false;
                    }
                }
                break;

            default:
                sortType = "Price";
                if (orderChoice == 1)
                {
                    if (data[x].getPrice() > data[x + 1].getPrice())
                    {
                        Inventory temp = data[x];
                        data[x] = data[x + 1];
                        data[x + 1] = temp;
                        sorted = false;
                    }
                }
                else
                {
                    if (data[x].getPrice() < data[x + 1].getPrice())
                    {
                        Inventory temp = data[x];
                        data[x] = data[x + 1];
                        data[x + 1] = temp;
                        sorted = false;
                    }
                }
            }
        }
    }
    cout << "::Sort By " << sortType;
    if (orderChoice == 1)
    {
        cout << " in Ascending Order\n";
    }
    else
    {
        cout << " in Descending Order\n";
    }
    cout << endl;
}

// Sequential Search
void seqSearch(Inventory data[], int n)
{
    bool found = false;
    int index = -1;
    string searchType, searchKey;

    int searchChoice;
    try
    {
        searchChoice = menuSearch();
    }
    catch (const char *msg)
    {
        cout << "Error: " << msg << endl
             << endl;
        return;
    }
    cout << "Enter your search key: ";
    cin.ignore();
    getline(cin, searchKey);

    // no case sensitive
    for (int j = 0; j < searchKey.size(); j++)
        searchKey[j] = tolower(searchKey[j]);

    switch (searchChoice)
    {
    case 1:
        searchType = "Inventory Code";
        for (int i = 0; i < n; i++)
        {
            // no case sensitive
            string temp = data[i].getCode();
            for (int j = 0; j < data[i].getCode().size(); j++)
                temp[j] = tolower(temp[j]);
            if (temp == searchKey)
            {
                index = i;
                found = true;
            }
        }
        break;
    default:
        searchType = "Inventory Name";
        for (int i = 0; i < n; i++)
        { // no case sensitive
            string temp = data[i].getName();
            for (int j = 0; j < data[i].getName().size(); j++)
                temp[j] = tolower(temp[j]);

            if (temp == searchKey)
            {
                index = i;
                found = true;
            }
        }
    }

    cout << "\n::Search By " << searchType << endl
         << endl
         << "\t\t\t:::::::Inventory List:::::::\n"
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

    if (found)
    {
        data[index].display();
        cout << endl;
    }
    else
    {
        cout << "Cannot Find!!!\n";
    }
    cout << endl;
}

int main()
{
    string code, name, type;
    int quantity, counter = 0, choice, mChoice;
    float price;
    Inventory inv[SIZE];
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

    cout << "\n~~~~~~~~~~~~~~~~~~~~~  WELCOME TO INVENTORY MANAGEMENT SYSTEM  ~~~~~~~~~~~~~~~~~~~~~\n\n";
    disList(inv, counter);
    while (loop)
    {
        mChoice = mainMenu();
        if (mChoice == 1)
        {
            cout << "<<< Sorting Process >>>" << endl;
            sort(inv, counter);
            disList(inv, counter);
        }
        else if (mChoice == 2)
        {
            cout << "<<< Searching Process >>>" << endl;
            seqSearch(inv, counter);
        }
        else if (mChoice == 3)
        {
            cout << "Bye Bye!!!\n";
            loop = false;
        }
        else
        {
            cout << "Please enter a valid choice! :)\n";
        }
    }

    // store the array into the output.txt file

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