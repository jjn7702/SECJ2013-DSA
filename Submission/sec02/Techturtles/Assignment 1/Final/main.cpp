#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Parcel.hpp"
#include "function.hpp"
using namespace std;

int main()
{
    int option, size = 1, choice, count = 0;
    char category;
    string userKey;
    Parcel *parcel[ARRAY_SIZE];
    inputFile(parcel, count);
    cout << endl;
    cout << "Before Sort : " << endl;

    dispItems(parcel, count);
    do
    {
        cout << endl;
        displayMenu();
        cin >> choice;
        cin.ignore();
        cout << endl;

        switch (choice)
        {
        case 1:
        { // add new parcel
            addNewParcel(parcel, count);
            break;
        }
        case 2:
        {

            cout << endl;
            cout << "Enter parcel tracking number to search for parcel : ";
            cin >> userKey;
            mergeSortAsc(parcel, 0, count - 1);
            int parcelIndex = binarySearch(parcel, userKey, count);
            parcel[parcelIndex]->displayParcelDetails();
            break;
        }
        case 3:
        {
            cout << "Enter '1' to sort parcel by status in Ascending Order" << endl;
            cout << "Enter '2' to sort parcel by status in Descending Order" << endl;
            cout << "Option: ";
            cin >> option;
            displayBubbleSortMenu(option, parcel, count);
            break;
        }
        case 4:
        {
            cout << "Enter 'A' to sort parcel by shipping category in Ascending Order" << endl;
            cout << "Enter 'B' to sort parcel by shipping category in Descending Order" << endl;
            cout << "Category: ";
            cin >> category;
            displaySelectionSortMenu(category, parcel, count);
            break;
        }
        case 5:
        {
            cout << "Enter '1' to sort parcel by tracking number in Ascending Order" << endl;
            cout << "Enter '2' to sort parcel by tracking number in Descending Order" << endl;
            cout << "Option: ";
            cin >> option;
            displayMergeSortMenu(option, parcel, count);
            break;
        }

        case 0:
        {
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 0);

    system("pause");
    return 0;
}