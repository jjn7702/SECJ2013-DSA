#include <iostream>
#include <fstream>
#include <string>
using namespace std ;

class Customer{
	private:
		// Attributes
		string name ;
		int age ;
		string IC ;
		string phoneNum ;
		int roomNum ; 
		string checkInDate ;
		
	public:
		// Mutator
		void setName(string n){ name = n ; }
		void setAge(int a){ age = a ; }
		void setIC(string ic){ IC = ic ; }
		void setPhone(string p){ phoneNum = p ; }
		void setNum(int r){ roomNum = r ; }
		void setDate(string d){ checkInDate = d ; }
		
		// Accessor
		string getName(){ return name ; }
		int getAge(){ return age ; }
		string getIC(){ return IC ; }
		string getPhone(){ return phoneNum ; }
		int getNum(){ return roomNum ; }
		string getDate(){ return checkInDate ; }
};

// Sort customers based on phone number
void SortingPhone(Customer data[], int size)
{        
	Customer temp;
	bool sorted = false;
		    
	for(int pass = 1 ; (pass < size) && !sorted ; ++pass)
	{
		sorted = true; // end the loop if all data is been sorted
		for(int x = 0; x < size-pass; x++)
		{
		    if(data[x].getPhone() > data[x+1].getPhone())
			{
		        temp.setName(data[x].getName()) ;
		        temp.setAge(data[x].getAge()) ;
		        temp.setIC(data[x].getIC()) ;
		        temp.setPhone(data[x].getPhone()) ;
		        temp.setNum(data[x].getNum()) ;
		        temp.setDate(data[x].getDate()) ;
		        
		        data[x].setName(data[x+1].getName()) ;
		        data[x].setAge(data[x+1].getAge()) ;
		        data[x].setIC(data[x+1].getIC()) ;
		        data[x].setPhone(data[x+1].getPhone()) ;
		        data[x].setNum(data[x+1].getNum()) ;
		        data[x].setDate(data[x+1].getDate()) ;
		        
		        data[x+1].setName(temp.getName()) ;
		        data[x+1].setAge(temp.getAge()) ;
		        data[x+1].setIC(temp.getIC()) ;
		        data[x+1].setPhone(temp.getPhone()) ;
		        data[x+1].setNum(temp.getNum()) ;
		        data[x+1].setDate(temp.getDate()) ;
		        
		        sorted = false; // for control the loop
		    }
		}
	}
} // end of sort based on phone number

// Sort customers based on room number
void SortingNum(Customer data[], int size)
{        
	Customer temp;
	bool sorted = false;
		    
	for(int pass = 1 ; (pass < size) && !sorted ; ++pass)
	{
		sorted = true; // end the loop if all data is been sorted
		for(int x = 0; x < size-pass; x++)
		{
		    if(data[x].getNum() > data[x+1].getNum())
			{
		        temp.setName(data[x].getName()) ;
		        temp.setAge(data[x].getAge()) ;
		        temp.setIC(data[x].getIC()) ;
		        temp.setPhone(data[x].getPhone()) ;
		        temp.setNum(data[x].getNum()) ;
		        temp.setDate(data[x].getDate()) ;
		        
		        data[x].setName(data[x+1].getName()) ;
		        data[x].setAge(data[x+1].getAge()) ;
		        data[x].setIC(data[x+1].getIC()) ;
		        data[x].setPhone(data[x+1].getPhone()) ;
		        data[x].setNum(data[x+1].getNum()) ;
		        data[x].setDate(data[x+1].getDate()) ;
		        
		        data[x+1].setName(temp.getName()) ;
		        data[x+1].setAge(temp.getAge()) ;
		        data[x+1].setIC(temp.getIC()) ;
		        data[x+1].setPhone(temp.getPhone()) ;
		        data[x+1].setNum(temp.getNum()) ;
		        data[x+1].setDate(temp.getDate()) ;
		        
		        sorted = false; // for control the loop
		    }
		}
	}
} // end of sort based on room number

// Search key based on age or room number
void Search2(int searchKey, Customer data[], int size)
{ 
	int index = -1 ; //-1 means record is not found
	for(int i = 0; i < size; i++)
	{ 
		if(searchKey == data[i].getAge())
		{ 
			index = i; // assign current array index
			break; //terminate searching
		}
		else if(searchKey == data[i].getNum())
		{ 
			index = i; // assign current array index
			break; //terminate searching
		}
	} //end for
	
	if(index == -1) // If the key not found
		cout << "\nNot found..." << endl ;
	else
	{	// Display the information after searching if found
		cout << "\nName: " << data[index].getName() << endl
			 << "Age: " << data[index].getAge() << endl
	 		 << "IC Number: " << data[index].getIC() << endl
			 << "Phone Number: " << data[index].getPhone() << endl 
			 << "Room Number: " << data[index].getNum() << endl 
			 << "Check In Date: " << data[index].getDate() << endl ;	
	}	
} //end of search for age or room number

int main()
{
	Customer customer[100] ;
	int custNum = 0 ;
	string name, IC, phoneNum, date ;
	int age, room ; 
	
	// file as database
	ifstream input("Assignment_1.txt") ;

    if(!input) 
	{
        cout << "Cannot open the file\n" ;
        return 1;
    }
	// Get input
    while(getline(input, name, '/'))
	{
		input >> age ;
		input.ignore() ;
		getline(input, IC, '/') ;
		getline(input, phoneNum, '/') ;
		input >> room ;
		input.ignore() ;
		input >> date ;
		input.ignore() ;
		
		customer[custNum].setName(name) ;
		customer[custNum].setAge(age) ;
		customer[custNum].setIC(IC) ;
		customer[custNum].setPhone(phoneNum) ;
		customer[custNum].setNum(room) ;
		customer[custNum].setDate(date) ;
				        
		custNum++ ;
    }

    input.close() ; // close the input file
}
