#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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

// Menu for Sorting
int menuSort()
{
	int option ;
	
	cout << ":: SORTING ORDER BASED ON OPTION CHOSEN ::" << endl 
		 << "[1] Sort by name" << endl 
		 << "[2] Sort by age" << endl 
		 << "[3] Sort by IC number" << endl 
		 << "[4] Sort by phone number" << endl 
		 << "[5] Sort by room number" << endl
		 << "[6] Sort by check in date" << endl
		 << "[7] Quit" << endl ;
	cout << "OPTION >> " ;
	cin >> 	option ;
	
	return option ;
}

// Display result after sorting
void display(Customer data[], int size, string option) 
{
	cout << "\nSorted data based on " << option << endl << endl ;
	cout << left ;
	cout << setw(15) << "Name" << " |"
		 << setw(3) << " Age" << " | "
		 << setw(15) << "IC Number" << " |"
		 << setw(13) << " Phone Number" << " | "
		 << setw(10) << "Room Number" << " | "
		 << setw(15) << "Check In Date" << endl ;
	
	for(int x = 0 ; x <= 27 ; x++)
		cout << "---" ;
	cout << endl ;
	
	for(int i = 0 ; i <= size-1 ; i++)
	{
		cout << setw(15) ;
		cout << data[i].getName() << " | "  ;
		cout << setw(3) ;
		cout << data[i].getAge() << " | "  ;
		cout << setw(15) ;
		cout << data[i].getIC() << " | "  ;
		cout << setw(12) ;
		cout << data[i].getPhone() << " |  "  ;
		cout << setw(10) ;
		cout << data[i].getNum() << " |  "  ;
		cout << setw(15) ;
		cout << data[i].getDate() << endl ;
	}
}

// Sort customers based on name
void SortingName(Customer data[], int size)
{        
	Customer temp;
	bool sorted = false; 
		    
	for(int pass = 1 ; (pass < size) && !sorted ; ++pass)
	{
		sorted = true; // end the loop if all data is been sorted 
		for(int x = 0; x < size-pass; x++)
		{
		    if(data[x].getName() > data[x+1].getName())
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
} // end of sort based on name

// Sort customers based on age
void SortingAge(Customer data[], int size)
{        
	Customer temp;
	bool sorted = false; 
		    
	for(int pass = 1 ; (pass < size) && !sorted ; ++pass)
	{
		sorted = true; // end the loop if all data is been sorted
		for(int x = 0; x < size-pass; x++)
		{
		    if(data[x].getAge() > data[x+1].getAge())
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
} // end of sort based on age

// Sort customers based on IC number
void SortingIC(Customer data[], int size)
{        
	Customer temp;
	bool sorted = false;
		    
	for(int pass = 1 ; (pass < size) && !sorted ; ++pass)
	{
		sorted = true; // end the loop if all data is been sorted
		for(int x = 0; x < size-pass; x++)
		{	// Malaysian IC first 2 number can be counted as age
		    if(data[x].getAge() > data[x+1].getAge())
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
} // end of sort based on IC number

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

// Sort customers based on check in date
void SortingDate(Customer data[], int size)
{        
	Customer temp;
	bool sorted = false;
		    
	for(int pass = 1 ; (pass < size) && !sorted ; ++pass)
	{
		sorted = true; // end the loop if all data is been sorted
		for(int x = 0; x < size-pass; x++)
		{
		    if(data[x].getDate() > data[x+1].getDate())
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
		        
		        sorted = false; // end the loop if all data is been sorted
		    }
		}
	}
} // end of sort based on check in date

// Menu for Searching
int menuSearch()
{
	int option ;
	
	cout << "\n:: SEARCH BASED ON OPTION CHOSEN ::" << endl 
		 << "[1] Search name" << endl 
		 << "[2] Search age" << endl 
		 << "[3] Search IC number" << endl 
		 << "[4] Search phone number" << endl
		 << "[5] Search room number" << endl 
		 << "[6] Search check in date" << endl 
		 << "[7] Quit" << endl ;
	cout << "OPTION >> " ;
	cin >> 	option ;
	
	return option ;
}

// Search key based on name, IC number, phone number or check in date
void Search(string searchKey, Customer data[], int size)
{ 
	int index = -1 ; //-1 means record is not found
	for(int i = 0; i < size; i++)
	{ 
		if(searchKey == data[i].getName())
		{ 
			index = i; // assign current array index
			break; //terminate searching
		}
		else if(searchKey == data[i].getIC())
		{ 
			index = i; // assign current array index
			break; //terminate searching
		}
		else if(searchKey == data[i].getPhone())
		{ 
			index = i; // assign current array index
			break; //terminate searching
		}
		else if(searchKey == data[i].getDate())
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
			 << "CheckInDate: " << data[index].getDate() << endl ;	
	}	
} //end of search for name, IC number, phone number, check in date

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

	MenuLoop1: // For looping if key in invalid option
    int option = menuSort() ;
    
    if(option == 1) // Sort by name
	{
		SortingName(customer, custNum);
        display(customer, custNum, "Name");
	}	
	else if(option == 2) // Sort by age
	{
		SortingAge(customer, custNum);
        display(customer, custNum, "Age");
	}	
	else if(option == 3) // Sort by IC number
	{
		SortingIC(customer, custNum);
        display(customer, custNum, "IC Number");
	}	
	else if(option == 4) // Sort by phone number
	{
		SortingPhone(customer, custNum);
        display(customer, custNum, "Phone Number");
	}	
	else if(option == 5)
	{
		SortingNum(customer, custNum); // Sort by room number
        display(customer, custNum, "Room Number");
	}
	else if(option == 6) // Sort by check in date
	{
		SortingDate(customer, custNum);
        display(customer, custNum, "Check In Date");
	}
	else if(option == 7) // Quit
	{ 
		return 1 ;	
	}		
	else // Looping if in key in invalid option
	{
		cout << "\nPlease key in valid option\n" << endl ;
		goto MenuLoop1 ;
	}
	
	MenuLoop2: // For looping if key in invalid option
    option = menuSearch() ;
    
    // Search key based on name, IC number, phone number or check in date
    if(option == 1 || option == 3 || option == 4 || option == 6)
	{
		string key ;
		cout << "\nIf search for IC number, phone number or check in date, please include '-' ";  
		cout << "\nPlease enter the key: " ;
		cin >> key ;
		Search(key, customer, custNum) ; 
	}
	// Search key based on age or room number	
	else if(option == 2 || option == 5)
	{
		int key ;
		cout << "\nPlease enter the key: " ;
		cin >> key ;
		SearchAge(key, customer, custNum) ; 
	}	
	else if(option == 7) // Quit
	{
		return 1 ;		
	}			
	else // Looping if key in invalid option
	{
		cout << "\nPlease key in valid option\n" << endl ;
		goto MenuLoop2 ;
	}
	
	return 0 ;
}
