// Assignment 1 - SECJ2013 - 23241 (Assg1.cpp)
// Group Members:
// 1. Muhammad Iman Firdaus Bin Baharuddin A22EC0216
// 2. Muhammad Ariff Danish Bin Hashnan A22EC0204
// 3. Che Marhumi Bin Che AB Rahim A22EC0147
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
        string name, destination, airlines; 
        int day,month,years;

    public:
        Cust(string x, int z,int c, int v, string d, string a){
        name=x;
        day=z;
        month=c;
        years=v;
        destination=d;
        airlines=a;
    }

    void printResult(){   
        cout<<left<<setw(15)<<name<<setw(2)<<day<< " / "<<setw(2)<<month<<" / "<<setw(15)<<years<<setw(15)<<destination<<setw(16)<<airlines<<endl;
    }

    int getdate(){
        return day+years*10000+month*100;
    }

    string getName(){
        return name;
    }

    string getDestination(){
        return destination;
    }

    string getAirlines(){
        return airlines;
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

void sortDestination(Cust* cl[], int size){ //bubble sort
    int pass; 
    Cust* tempValue;
    
    for (pass =1; pass < size; pass++){ // moves the largest element to the
    // end of the array
        for (int x = 0; x < size - pass; x++){ // compare adjacent elements
            if ( cl[x]-> getDestination() > cl[x+1] ->getDestination() ){ // swap elements
            tempValue = cl[x];
                cl[x] = cl[x + 1];
                cl[x + 1] = tempValue;
            }
        }  
    }
} // end Bubble Sort

void sortAirlines(Cust* cl[], int size){ //bubble sort
    int pass; 
    Cust* tempValue;
    
    for (pass =1; pass < size; pass++){ // moves the largest element to the
    // end of the array
        for (int x = 0; x < size - pass; x++){ // compare adjacent elements
            if ( cl[x]-> getAirlines() > cl[x+1] ->getAirlines() ){ // swap elements
            tempValue = cl[x];
                cl[x] = cl[x + 1];
                cl[x + 1] = tempValue;
            }
        }  
    }
} // end Bubble Sort


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

//Task function searching + file input (Che Marhumi)



// Task int main (Ariff)
// main function
int main() {
    const int LIST_SIZE = 10;
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
            string name, destination, airlines;
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
                ss >> destination >> airlines;
                custlist[idx] = new Cust(name, day, month, years, destination, airlines);
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
            cout << "\n4. List results (sort by destination)";
            cout << "\n5. List results (sort by airlines)";
            cout << "\n6. Exit\n\n";
            
            cout << "Enter your choice [1, 2, 3, 4]: ";
            cin >> opt;

            cout<<endl;
            
            if (opt == 1) {
                cout<<">>>>>>>>>>>>>>>>>>>>>>>>>> BOOKING DETAILS <<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
                cout<<"----------------------------------------------------------------------"<<endl;
                cout<<left<<setw(15)<<"Name"<<"Date of Booking"<<"\t\tDestination"<<"\tAirlines"<<endl;
                cout<<"----------------------------------------------------------------------"<<endl;
                listcust(custlist, idx);
                cout<<endl;
            }

            //sort by name
            if (opt == 2) {
                sortname(custlist, idx);
                cout<<"BOOKING DETAILS"<<endl;
                cout<<"----------------------------------------------------------------------"<<endl;
                cout<<left<<setw(15)<<"Name"<<"Date of Booking"<<"\t\tDestination"<<"\tAirlines"<<endl;
                cout<<"----------------------------------------------------------------------"<<endl;
                listcust(custlist, idx);
                cout<<endl;
            }

            //sort by grade
            if (opt == 3) {
                sortdate(custlist, idx);
                cout<<"BOOKING DETAILS"<<endl;
                cout<<"----------------------------------------------------------------------"<<endl;
                cout<<left<<setw(15)<<"Name"<<"Date of Booking"<<"\t\tDestination"<<"\tAirlines"<<endl;
                cout<<"----------------------------------------------------------------------"<<endl;
                listcust(custlist, idx);
                cout<<endl;
            }

            //sort by grade
            if (opt == 4) {
                sortDestination(custlist, idx);
                cout<<"BOOKING DETAILS"<<endl;
                cout<<"----------------------------------------------------------------------"<<endl;
                cout<<left<<setw(15)<<"Name"<<"Date of Booking"<<"\t\tDestination"<<"\tAirlines"<<endl;
                cout<<"----------------------------------------------------------------------"<<endl;
                listcust(custlist, idx);
                cout<<endl;
            }

            //sort by grade
            if (opt == 5) {
                sortAirlines(custlist, idx);
                cout<<"BOOKING DETAILS"<<endl;
                cout<<"----------------------------------------------------------------------"<<endl;
                cout<<left<<setw(15)<<"Name"<<"Date of Booking"<<"\t\tDestination"<<"\tAirlines"<<endl;
                cout<<"----------------------------------------------------------------------"<<endl;
                listcust(custlist, idx);
                cout<<endl;
            }

            

            if (opt != 6) system("pause");
        }

        fileIn.close();
         return 0;
    }
