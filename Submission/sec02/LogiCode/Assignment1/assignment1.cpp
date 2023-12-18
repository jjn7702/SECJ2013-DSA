#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define MAXSIZE 10
using namespace std;

class Admin
{   
    string adminID;
    string name;
    string position;
    string phoneNo;

    public:
        Admin(): adminID(""), name(""), position(""), phoneNo("") {};
        Admin(string id, string n, string p, string pn) : adminID(id), name(n), position(p), phoneNo(pn) {};
        string getadminID() const { return adminID; }
};

template <typename T>
void mergeSort(T r[], int first, int last) { 
    if (first < last) { 
        int mid = (first + last)/2;
        mergeSort(r, first, mid);
        mergeSort(r, mid+1, last);
        merge(r, first, mid, last);
    }
}

template <typename T>
void mergeSortDsc(T r[], int first, int last) { 
    if (first < last) { 
        int mid = (first + last)/2;
        mergeSortDsc(r, first, mid);
        mergeSortDsc(r, mid+1, last);
        mergeDsc(r, first, mid, last);
    }
}
void bookingMenu() {
	int input;
    Booking* booking = new Booking[MAXSIZE];
    readBookingData(booking, MAXSIZE);
do{
   	cout << "Sort bookings by " << endl;
    cout << "1. Room Type" << endl;
    cout << "2. Room Price (Low to High)" << endl;
    cout << "3. Room Price (High to Low)" << endl;
    cout << "4. Latest Check-In Date" << endl;
    cout << "5. Earliest Check-In Date" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your option: " << endl;
    cin >> input;

    switch(input) {
    	case 1:
    	{
            cout<<"Sort by Room Type:"<<endl;
            string roomType[MAXSIZE];
            for (int i = 0; i < MAXSIZE; ++i) {
                    roomType[i] = booking[i].getRoomType();
            }
            mergeSort(roomType, 0, MAXSIZE - 1);
            
            Booking sortedBooking[MAXSIZE];
            int sortedIndex = 0;
            for (int i = 0; i < MAXSIZE; ++i) {
		        for (int j = 0; j < MAXSIZE; ++j) {
		            if (roomType[i] == booking[j].getRoomType() && booking[j].getCheckInDate() != "") {
		                sortedBooking[sortedIndex] = booking[j];
		                booking[j] = Booking();
		                ++sortedIndex;
		                break;
		            }
		        }
		    }
		    dispItems(sortedBooking, 0, MAXSIZE - 1);
		    break;
		}

        case 2:
        {
            cout<<"Sort by Room Price (Low to High):"<<endl;
            double price[MAXSIZE];
            for (int i = 0; i < MAXSIZE; ++i) {
                    price[i] = booking[i].getTotalPrice();
            }
            mergeSort(price, 0, MAXSIZE - 1);
            
            Booking sortedBooking[MAXSIZE];
		    int sortedIndex = 0;
		
		    for (int i = 0; i < MAXSIZE; ++i) {
		        for (int j = 0; j < MAXSIZE; ++j) {
		            if (price[i] == booking[j].getTotalPrice() && booking[j].getCheckInDate() != "") {
		                sortedBooking[sortedIndex] = booking[j];
		                booking[j] = Booking();
		                ++sortedIndex;
		                break;
		            }
		        }
		    }
		    dispItems(sortedBooking, 0, MAXSIZE - 1);
		    break;
		}

        case 3:
        {
            cout<<"Sort by Room Price (High to Low):"<<endl;
            double price[MAXSIZE];
            for (int i = 0; i < MAXSIZE; ++i) {
                    price[i] = booking[i].getTotalPrice();
            }
            mergeSortDsc(price, 0, MAXSIZE - 1);
            
            Booking sortedBooking[MAXSIZE];
		    int sortedIndex = 0;
		
		    for (int i = 0; i < MAXSIZE; ++i) {
		        for (int j = 0; j < MAXSIZE; ++j) {
		            if (price[i] == booking[j].getTotalPrice() && booking[j].getCheckInDate() != "") {
		                sortedBooking[sortedIndex] = booking[j];
		                booking[j] = Booking();
		                ++sortedIndex;
		                break;
		            }
		        }
		    }
		    dispItems(sortedBooking, 0, MAXSIZE - 1);
		    break;
		}
            
        case 4:
        {
            cout<<"Sort by Latest Check-In Date:"<<endl;
            string date[MAXSIZE];
            for (int i = 0; i < MAXSIZE; ++i) {
                    date[i] = booking[i].getCheckInDate();
            }
            mergeSortDsc(date, 0, MAXSIZE - 1);
            
            Booking sortedBooking[MAXSIZE];
		    int sortedIndex = 0;
		
		    for (int i = 0; i < MAXSIZE; ++i) {
		        for (int j = 0; j < MAXSIZE; ++j) {
		            if (date[i] == booking[j].getCheckInDate() && booking[j].getCheckInDate() != "") {
		                sortedBooking[sortedIndex] = booking[j];
		                booking[j] = Booking();
		                ++sortedIndex;
		                break;
		            }
		        }
		    }
		    dispItems(sortedBooking, 0, MAXSIZE - 1);
		    break;
		}
            
        case 5:
        {
            cout << "Sort by Earliest Check-In Date:" << endl;
		    string checkinDate[MAXSIZE];
		    for (int i = 0; i < MAXSIZE; ++i) {
		        checkinDate[i] = booking[i].getCheckInDate();
		    }
		    mergeSort(checkinDate, 0, MAXSIZE - 1);
		
		    Booking sortedBooking[MAXSIZE];
		    int sortedIndex = 0; 
		
		    for (int i = 0; i < MAXSIZE; ++i) {
		        for (int j = 0; j < MAXSIZE; ++j) {
		            if (checkinDate[i] == booking[j].getCheckInDate() && booking[j].getCheckInDate() != "") {
		                sortedBooking[sortedIndex] = booking[j];
		                booking[j] = Booking();
		                ++sortedIndex;
		                break;
		            }
		        }
		    }
		    dispItems(sortedBooking, 0, MAXSIZE - 1);
		    break;
		}

        case 6:
            break;
    }
    
    } while (input!=6);
    delete [] booking;
}
