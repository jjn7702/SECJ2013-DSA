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
void dispItems (string foodData[], int first, int last) {
	for (int i = first; i <= last; i++)
		cout << foodData[i] << "\t";
	cout << endl;
}

void merge(string foodArray[], int first, int mid, int last) { 
    string tempArray[SIZE]; 
    int first1 = first; 
    int last1 = mid; 
    int first2 = mid + 1;
    int last2 = last; 
    int index = first1;


    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        if (foodArray[first1] < foodArray[first2]) { 
			foodArray[index] = foodArray[first1];
			++first1; 
        }
        else { 
			tempArray[index] = foodArray[first2];
            ++first2; 
        }
    } // end for
           
	for (; first1 <= last1; ++first1, ++index)
        tempArray[index] = foodArray[first1];
    
	for (; first2 <= last2; ++first2, ++index)
        tempArray[index] = foodArray[first2];
           
	// copy the result back into the original array
    for (index = first; index <= last; ++index)
        foodArray[index] = tempArray[index];
} // end merge function

    
void mergeSort(string foodArray[], int first, int last) { 
    if (first < last) { 
        int mid = (first + last)/2; 

        mergeSort(foodArray, first, mid);

        mergeSort(foodArray, mid+1, last);
 
        merge(foodArray, first, mid, last);
    } 
        dispItems(foodArray, first, last);
    cout << endl;
} 

int main(){

//testing
    Menu try[] = WE05,Thai Pasta,Western,12.00
                WE06,Chicken Pasta,Western,12.00
                WE07,Seafood Pasta,Western,12.00
                WE08,Chicken Lasagna,Western,10.00
                WE09,Beef Lasagna,Western,10.50
                DE01,Ice Cream,Dessert,1.50
                DE02,Cendol,Dessert,2.00
                DE03,ABC,Dessert,2.00
                WE10,Double Special Burger,Western,6.00
                DE04,Sagu Melaka,Dessert,2.00
                TR09,Tomyam,Traditional,6.00
                DE05,Chocolate Mousse,Dessert,5.00
                WE11,Benjo,Western,5.00; 
    int choiceSort;
    cout << "1 - ALPHABET ORDER | 2 - price => ";
    cin >> choiceSort;

    //choice sorting
    switch (choiceSort)
    {
    case 1:
        // mergeSort(); 
        break;
    
    case 2:
        /* code */
        break;
    
    default:
        break;
    }
}
