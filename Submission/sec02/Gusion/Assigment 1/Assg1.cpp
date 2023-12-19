// Assignment 1 - SECJ2013 - 23241 (Assg1.cpp)
// Group Members:
// 1. Muhammad Iman Firdaus Bin Baharuddin
// 2. Muhammad Ariff Danish Bin Hashnan
// 3. Che Marhumi 
#include <iostream>
#include <string>
#include<sstream>
#include <fstream>
#include<iomanip>
using namespace std;

// Task Create Class (Iman)
class Cust
{
    private:
    string name; int day,month,years;
    public:
    Cust(string x, int z,int c, int v)
    {
        name=x;
        day=z;
        month=c;
        years=v;
    }
    void printResult()
    {   cout<<left<<setw(15)<<name<<setw(2)<<day<< " / "<<setw(2)<<month<<" / "<<setw(2)<<years<<endl;
        
    }
    int getdate()
   {
    return day+years*10000+month*100;
   }

    string getName()
    {
        return name;
    }
};

// function implementation
void listcust(Cust* cl[], int size) {
    for (int i = 0; i < size; i++) {
        cl[i]->printResult();
    }
}

void sortname(Cust* cl[], int size){ //bubble sort
    int pass; 
    Cust* tempValue;
    
    for (pass =1; pass < size; pass++){ // moves the largest element to the
    // end of the array
        for (int x = 0; x < size - pass; x++){ // compare adjacent elements
            if ( cl[x]-> getName() > cl[x+1] ->getName() ){ // swap elements
            tempValue = cl[x];
                cl[x] = cl[x + 1];
                cl[x + 1] = tempValue;
            }
        }  
    }
} // end Bubble Sort


void sortdate(Cust* cl[], int size){ //bubble sort
    int pass; 
    Cust* tempValue;
    
    for (pass =1; pass < size; pass++){ // moves the largest element to the
    // end of the array
        for (int x = 0; x < size - pass; x++){ // compare adjacent elements
            if ( cl[x]-> getdate() > cl[x+1] ->getdate() ){ // swap elements
                tempValue = cl[x];
                cl[x] = cl[x + 1];
                cl[x + 1] = tempValue;
            }
        }  
    }
}


// Task int main (Ariff)
// main function
int main() {
    const int LIST_SIZE = 5;
    string line;
    int idx = 0;
    Cust* custlist[LIST_SIZE];

    fstream fileIn("booking.txt", ios::in);

    if (!fileIn) {
        cout << "File input/output error!\n";
        return 1;

    } 
    else {
        while (getline(fileIn, line)) {
            // Use stringstream to parse the line
            stringstream ss(line);
            string name;
            int day, month, years;
            
            ss >> name >> day;
            // Ensure the next character is a dot (.)
            if (ss.peek() == '.') {
                ss.ignore();
                ss >> month;
            } 
             if (ss.peek() == '.') {
                ss.ignore();
                ss >> years;
                custlist[idx] = new Cust(name, day, month, years);
                idx++;
            }else {
                cout << "Invalid date format in line: " << line << endl;
            }
        }
    }
    
        
        int opt = 0;

        while (opt != 4) {
            cout << "\n1. List results (original list)";
            cout << "\n2. List results (sort by name)";
            cout << "\n3. List results (sort by date of booking)";
            cout << "\n4. Exit\n\n";
            
            cout << "Enter your choice [1, 2, 3, 4]: ";
            cin >> opt;
            
            if (opt == 1) {
                cout<<left<<setw(15)<<"Name"<<"Date of Booking"<<endl;
                listcust(custlist, idx);
            }

            //sort by name
            if (opt == 2) {
                sortname(custlist, idx);
                cout<<left<<setw(15)<<"Name"<<"Date of Booking"<<endl;
                listcust(custlist, idx);
            }

            //sort by grade
            if (opt == 3) {
                sortdate(custlist, idx);
                cout<<left<<setw(15)<<"Name"<<"Date of Booking"<<endl;
                listcust(custlist, idx);
            }

            
            if (opt != 4) system("pause");
        }

        fileIn.close();
         return 0;
    }

