#include <iostream>
#include <iomanip>
using namespace std ;

int menuSort()
{
	int option ;
	
	cout << ":: SORTING ORDER BASED ON OPTION CHOSEN ::" << endl 
		 << "[1] Sort by name" << endl 
		 << "[2] Sort by age" << endl 
		 << "[3] Sort by IC number" << endl 
		 << "[4] Sort by phone number" << endl 
		 << "[5] Quit" << endl ;
	cout << "OPTION >> " ;
	cin >> 	option ;
	
	return option ;
}

void display(Customer data[], int size, string option) 
{
	cout << "\nSorted data based on " << option << endl << endl ;
	cout << left ;
	cout << setw(15) << "Name" << " |"
		 << setw(3) << " Age" << " | "
		 << setw(15) << "IC number" << " |"
		 << setw(15) << " Phone Number" << endl ;
	cout << "-------------------------------------" << endl ;
	
	for(int i = 0 ; i <= size-1 ; i++)
	{
		cout << setw(15) ;
		cout << data[i].getName() << " | "  ;
		cout << setw(3) ;
		cout << data[i].getAge() << " | "  ;
		cout << setw(15) ;
		cout << data[i].getIC() << " | "  ;
		cout << setw(15) ;
		cout << data[i].getPhone() << endl ;
	}
}

int menuSearch()
{
	int option ;
	
	cout << "\n:: SEARCH BASED ON OPTION CHOSEN ::" << endl 
		 << "[1] Search name" << endl 
		 << "[2] Search age" << endl 
		 << "[3] Search IC number" << endl 
		 << "[4] Search phone number" << endl 
		 << "[5] Quit" << endl ;
	cout << "OPTION >> " ;
	cin >> 	option ;
	
	return option ;
}

int main()
{


	MenuLoop1:
    int option = menuSort() ;
    
    if(option == 1)
	{
		SortingName(customer, custNum);
        display(customer, custNum, "Name");
	}	
	else if(option == 2)
	{
		SortingAge(customer, custNum);
        display(customer, custNum, "Age");
	}	
	else if(option == 3)
	{
		SortingIC(customer, custNum);
        display(customer, custNum, "IC Number");
	}	
	else if(option == 4)
	{
		SortingPhone(customer, custNum);
        display(customer, custNum, "Phone Number");
	}	
	else if(option == 5)
	{ 
		return 1 ;	
	}		
	else
	{
		cout << "\nPlease key in valid option\n" << endl ;
		goto MenuLoop1 ;
	}

	MenuLoop2:
    option = menuSearch() ;
    
    if(option == 1 || option == 3 || option == 4)
	{
		string key ;
		cout << "\nIf search for IC number or phone number, please include '-' ";  
		cout << "\nPlease enter the key: " ;
		cin >> key ;
		Search(key, customer, custNum) ;
	}	
	else if(option == 2)
	{
		int key ;
		cout << "\nPlease enter the key: " ;
		cin >> key ;
		SearchAge(key, customer, custNum) ;
	}	
	else if(option == 5) 
	{
		return 1 ;		
	}			
	else
	{
		cout << "\nPlease key in valid option\n" << endl ;
		goto MenuLoop2 ;
	}
	
    system("pause") ;
	return 0 ;	
}