#include <iostream>
#include <fstream>
#include <string>
#define SIZE 30
using namespace std;


class Customer{
    private:
        int tableNumber;
        int numOfOrder;
        int pax;
        double payment;

    public:
        Customer();
        Customer(int tn, int orders, int people, double pay){
            tableNumber = tn;
            numOfOrder = orders;
            pax = people;
            payment = pay;
        }
};

class Menu{
    private:
        string foodId;
        string name;
        string category;
        double amount;
        double price;
};

//PART WANO
void dispItems (int data[], int first, int last) {
	for (int i = first; i <= last; i++)
		cout << data[i] << "\t";
	cout << endl;
}

void merge(int theArray[], int first, int mid, int last) { 
    int tempArray[SIZE]; // temp array
    int first1 = first; // first subarray begin
    int last1 = mid; // end of first subarray
    int first2 = mid + 1; // secnd subarry begin
    int last2 = last; // end of secnd subarry
    int index = first1;
    // next available location in tempArray
    cout << "merge(arr, " << first << ", " << mid << ", " << last << ")\n";
    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        if (theArray[first1] < theArray[first2]) { 
			tempArray[index] = theArray[first1];
			++first1; 
        }
        else { 
			tempArray[index] = theArray[first2];
            ++first2; 
        }
    } // end for
           
	for (; first1 <= last1; ++first1, ++index)
        tempArray[index] = theArray[first1];
    
	for (; first2 <= last2; ++first2, ++index)
        tempArray[index] = theArray[first2];
           
	// copy the result back into the original array
    for (index = first; index <= last; ++index)
        theArray[index] = tempArray[index];
} // end merge function

    
void mergeSort(string foodArray[], int first, int last) { 
    if (first < last) { 
        // sort each half
        int mid = (first + last)/2; // index of midpoint

        // sort left half theArray[first..mid]
        mergeSort(foodArray, first, mid);

        // sort right half theArray[mid+1..last]
        mergeSort(foodArray, mid+1, last);
 
        // merge the two halves
        merge(foodArray, first, mid, last);
    } // end if
    dispItems(foodArray, first, last);
    cout << endl;
} // end mergesort
