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

class Booking
{
    string checkInDate;
    string checkOutDate;
    int roomNo;
    string roomType;
    string ic;
    double totalPrice;

    public:
        Booking(): checkInDate(""), checkOutDate(""), roomNo(0), roomType(""), ic(""), totalPrice(0.0) {};
        Booking(string i, string o, int n, string t, string ic_, double p) : checkInDate(i), checkOutDate(o), roomNo(n), roomType(t), ic(ic_), totalPrice(p) {};
        string getCheckInDate() const { return checkInDate; }
        string getCheckOutDate() const { return checkOutDate; }
        int getRoomNo() const { return roomNo; }
        string getRoomType() const { return roomType; }
        string getIC() const { return ic; }
        double getTotalPrice() const { return totalPrice; }
};

void readBookingData(Booking b[], int size) {
    ifstream bookinginpFile("booking.txt");
    if (!bookinginpFile.is_open()) {
        cout << "Unable to open file!" << endl;
        return;
    }

    int count = 0;

    string checkInDate;
    string checkOutDate;
    int roomNo;
    string roomType;
    string ic;
    double totalPrice;

    while (bookinginpFile >> checkInDate >> checkOutDate >> roomNo >> roomType >> ic >> totalPrice && count < size) {
        b[count] = Booking(checkInDate, checkOutDate, roomNo, roomType, ic, totalPrice);
        count++;
    }

    bookinginpFile.close();
}

template <typename H>
void dispItems(H r[], int first, int last) {
	cout<<"______________________________________________________________________________"<<endl;
    cout << left << setw(14) << "|  Check-in  |" << setw(13) << "  Check-out |" << setw(10) << " Room No |"
         << setw(12) << " Room Type |" << setw(15) << " Customer  IC |" << setw(10) << " Total Price |" << endl;
	for (int i = first; i <= last; i++) {
		cout << "| "<<setw(10) << r[i].getCheckInDate() <<" | "<< setw(10) << r[i].getCheckOutDate()
             <<" |   "<< setw(4) << r[i].getRoomNo() <<"  |   "<< setw(6) << r[i].getRoomType()
             <<"  | "<< setw(12) << r[i].getIC() <<" |    "<< fixed << setprecision(2) << setw(5) << r[i].getTotalPrice()
			 <<"   |" << endl;
	}
	cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<endl;
}

template <typename K>
void merge(K r[], int first, int mid, int last) { 
    K tempArray[MAXSIZE];
    int first1 = first; 
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    
    for (;(first1 <= last1) && (first2 <= last2); ++index) {
        if (r[first1] < r[first2]) { 
            tempArray[index] = r[first1];
            ++first1; 
        }
        else { 
            tempArray[index] = r[first2];
            ++first2; 
        }
    }
            
    for (; first1 <= last1; ++first1, ++index)
        tempArray[index] = r[first1];
        
    for (; first2 <= last2; ++first2, ++index)
        tempArray[index] = r[first2];
            
    for (index = first; index <= last; ++index)
        r[index] = tempArray[index];
}

template <typename K>
void mergeDsc(K r[], int first, int mid, int last) { 
    K tempArray[MAXSIZE];
    int first1 = first; 
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    
    for (;(first1 <= last1) && (first2 <= last2); ++index) {
        if (r[first1] >= r[first2]) { 
            tempArray[index] = r[first1];
            ++first1; 
        }
        else { 
            tempArray[index] = r[first2];
            ++first2; 
        }
    }
            
    for (; first1 <= last1; ++first1, ++index)
        tempArray[index] = r[first1];
        
    for (; first2 <= last2; ++first2, ++index)
        tempArray[index] = r[first2];
            
    for (index = first; index <= last; ++index)
        r[index] = tempArray[index];
}

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
    do{
        readBookingData(booking, MAXSIZE);
	    
        cout << "Sort bookings by " << endl;
        cout << "1. Room Type" << endl;
        cout << "2. Room Price (Low to High)" << endl;
        cout << "3. Room Price (High to Low)" << endl;
        cout << "4. Latest Check-In Date" << endl;
        cout << "5. Earliest Check-In Date" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your option: ";
        cin >> input;
		cout<<endl;
		
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
                cout<<"\nSort by Room Price (High to Low):"<<endl;
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
                cout<<"\nSort by Latest Check-In Date:"<<endl;
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
                cout << "\nSort by Earliest Check-In Date:" << endl;
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

void adminMenu() {
    int option;
    cout << "Admin Menu" << endl;
    cout << "1. Check Booking Data" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your option: ";
    cin >> option;
    cout<<endl;

    switch (option) {
        case 1:
            bookingMenu();
            break;

        case 2:
            break;
            
        default:
            cout << "Enter a valid option." << endl;
            adminMenu();
            break;
    }
}

int SequenceSearch(const string& search_key, Admin a[], int array_size) {
    int index = -1;
    for (int p = 0; p < array_size; p++) {
        if (search_key == a[p].getadminID()) {
            index = p;
            break;
        }
    }
    return index;
}

int main()
{
    int role;
    string input;
    Booking b[MAXSIZE];

    //Admin information file
    const int SIZE = 50;
    Admin a[SIZE];
    ifstream inFile("admin.txt");

    int count = 0;
    string adminID, name, position, phoneNo;
    while (count < SIZE && !inFile.eof()) {
        inFile >> adminID;
        getline(inFile, name, ',');
        inFile >> position;
        inFile >> phoneNo;
        inFile.ignore();
        a[count] = Admin(adminID, name, position, phoneNo);
        count++;
    }
    inFile.close();
    
    //Menu for Admin
    cout <<"---------------------------------" <<endl;
    cout <<"LogiCode Hotel Management System" <<endl;
    cout <<"---------------------------------" <<endl;
    bool existence = false;
    cout << "Admin ID: ";
    cin >> input;

    int found = SequenceSearch(input, a, SIZE);
    while (!existence) {
        if (found != -1) {
            existence = true;
            cout << "\nSuccessfully verified!" << endl;
            adminMenu();
        } 
        else {
            cout << "Admin ID not found. Please enter a valid ID: ";
            cin >> input;
            found = SequenceSearch(input, a, SIZE);
        }
}
    return 0;
}
