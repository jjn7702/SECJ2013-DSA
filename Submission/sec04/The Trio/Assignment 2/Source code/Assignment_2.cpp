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
		Customer *next; //Pointer to next customer
		
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


class CustomerList{
	private:
		Customer *head;  // Pointer to first customer in list
		
	public:
		CustomerList(){ head = NULL ; }

		// Check if the linked list is empty
		bool isEmpty(){ return (head == NULL) ; }
		
		// Function to add  customer at the middle of the list
	    // Cannot add at the first position and last position
	    void addCustAtMid(Customer *newCustomer, int pos)
	    {
	    	// Check if the position is valid or not
	    	if(pos <= 0)
	    	{
	    		cout << "\nThe position is not available...\n" << endl ;
				return ;
			}
	    	
	    	Customer *current = head, *prev = NULL;
			int i = 1 ; 
			
			//Count the number of customer current have
			while( (current != NULL) && (pos > i) )
			{
				prev = current ;
				current = current->next ;
				i++ ;
		    }
			
			// Reject if the position is the last one
			if(current == NULL)
			{
				cout << "\nThe position is not available...\n" << endl ;
				return ;
			}
			
			// Reject if the position is the first one
		    if (prev == NULL)
		    {
		    	cout << "\nCannot add at the first position...\n" << endl;
		        return;
		    }
		    else
		    {
		        newCustomer->next = current;
		        prev->next = newCustomer;
			}
		}

		// Deleting node at the front of the linked list
		void deleteFront()
		{
			if(isEmpty()) // Check if the linked list is empty
			{
				cout << "\nThe customer list is empty" << endl ;
				return ;
			}
			
			Customer *current = head ;
			
			if(current->next != NULL) // check if the head is no NULL before delete
			{
				head = current->next ;
				current->next = NULL ;
			}
			
			delete current ;
		}

		// Deleting node at the end of the linked list
		void deleteEnd()
		{
			if(isEmpty()) // Check if the linked list is empty
			{
				cout << "\nThe customer list is empty" << endl ;
				return ;
			}
			
			Customer *current = head, *delNode ;
			
			// Move to  last customer
			while(current->next != NULL)
			{
				delNode = current ;
				current = current->next ;
			}
			
			delete current ;
			delNode->next = NULL ;
		}

		// Find customer data
		void findCustomer()
		{
			if(isEmpty())
			{
				cout << "The customer list is empty. Unable to search ..." << endl ;
				return ;
			}
			
			int option ;
			
			findloop: // Loop if key in invalid option
			cout << "\n:: Find Customer Data Based On Option Chosen ::\n"
				 << "[1] Name\n"
				 << "[2] Age\n"
				 << "[3] IC Number\n"
				 << "[4] Phone Number\n"
				 << "[5] Room Number\n"
				 << "[6] Check In Date\n"
				 << "Please Choose The Option: " ;
			cin >> option ;
			
			Customer *current = head, *prev = NULL ;
			bool found = false ;
						
			switch (option)
		    {
		    	case 1: // Search by Name
		           		{
		           			string n ;
		           			cout << "\nPlease key in the name you want to search" << endl
		           				 << "Name -> " ;
		           			cin >> n ;	 
		           			
							while( (current != NULL) && (!found) ) 
							{
								if(current->getName() == n)
								{
									 found = true ;
								}
								
								prev = current ;
								current = current->next ;
							}
							
		            		break;
		            	}
		        case 2: // Search by Age
		            	{
		           			int a ;
		           			cout << "\nPlease key in the age you want to search" << endl
		           				 << "Age -> " ;
		           			cin >> a ;	 
		           			
							while( (current != NULL) && (!found) ) 
							{
								if(current->getAge() == a)
								{
									 found = true ;
								}
								
								prev = current ;
								current = current->next ;
							}
							
		            		break;
		            	}
		        case 3: // Search by IC Number
		            	{
		           			string ic ;
		           			cout << "\nPlease key in the IC number you want to search" << endl
		           				 << "Please include '-'" << endl 
		           				 << "IC Number -> " ;
		           			cin >> ic ;	 

							while( (current != NULL) && (!found) ) 
							{
								if(current->getIC() == ic)
								{
									 found = true ;
								}
								
								prev = current ;
								current = current->next ;
							}
							
		            		break;
		            	}
		        case 4: // Search by Phone Number
		            	{
		           			string p ;
		           			cout << "\nPlease key in the phone number you want to search" << endl
		           				 << "Please include '-'" << endl 
		           				 << "Phone Number -> " ;
		           			cin >> p ;	 
							
							while( (current != NULL) && (!found) ) 
							{
								if(current->getPhone() == p)
								{
									 found = true ;
								}
								
								prev = current ;
								current = current->next ;
							}
							
		            		break;
		            	}
		        case 5: // Search by Room Number
		                {
		           			int r ;
		           			cout << "\nPlease key in the room number you want to search" << endl
		           				 << "Room Number -> " ;
		           			cin >> r ;	 
							
							while( (current != NULL) && (!found) ) 
							{
								if(current->getNum() == r)
								{
									 found = true ;
								}
								
								prev = current ;
								current = current->next ;
							}
							
		            		break;
		            	}
		        case 6: // Search by Check In Date
		                {
		           			string d ;
		           			cout << "\nPlease key in the check in date you want to search" << endl
		           				 << "Please include '-'" << endl 
		           				 << "Check In Date -> " ;
		           			cin >> d ;	 
							
							while( (current != NULL) && (!found) ) 
							{
								if(current->getDate() == d)
								{
									 found = true ;
								}
								
								prev = current ;
								current = current->next ;
							}
							
		            		break;
		            	}
		        default:{
		        			cout << "\nInvalid option. Please choose a number between 1 and 6" << endl;
		                	goto findloop ;
							break;
						}    
		    }
		
			if(found)
			{
				cout << "\nCustomer Data" << endl 
					 << "Name: " << prev->getName() << endl
					 << "Age: " << prev->getAge() << endl
					 << "IC Number: " << prev->getIC() << endl
					 << "Phone Number: " << prev->getPhone() << endl
					 << "Room Number: " << prev->getNum() << endl
					 << "Check In Date: " << prev->getDate() << endl
					 << endl ;		 
			}
			else
				cout << "\nNo record found" << endl << endl ;							        	
		} 	
		
		// Sort the customer data
		void sorting()
		{
			if(isEmpty()) // Reject when it is empty
			{
				cout << "\nThe customer list is empty. Unable to sort ..." << endl ;
				return ;
			}
			
			Customer *current, *prev, *temp ; 
			int size = 1 ;
			
			// Count the number of customers current have
			for(current = head; current != NULL; current = current->next)
		    	size++ ;
		    
		    // Sorting process
		    for(int pass = 1 ; pass < size ; pass++)
		    {
		    	current = head ;
		    	prev = NULL ;
		    	
		    	for (int j = 0 ; j < size-pass ; j++)
		        {
		            // Compare names and swap if necessary
		            if ( (current != NULL) && (current->next != NULL) 
						 && (current->getName() > current->next->getName()) )
		            {
		                temp = current->next ;
		                current->next = temp->next ;
		                temp->next = current ;
		
		                if (prev == NULL)
		                    head = temp ; // Update head if swapping the first node
		                else
		                    prev->next = temp ;
		
		                prev = temp ; // Move prev to the swapped node
		            }
		            else
		            {
		                prev = current ;
		                current = current->next ;
		            }
        		}
			}
			
			cout << "\nThe data is sorted\n" << endl ;
		}
		
};	

// Provide option for add and delete
int Option()
{
	int opt ;
	
	optloop1: // Loop if key in invalid option
	cout << "\n:: Option For Adding/Delete Customer ::" << endl ;
	cout << "[1] Front" << endl
		 << "[2] Middle" << endl 
		 << "[3] End" << endl << endl 
		 << "Option = " ;
	cin >> opt ;
			
	if((opt < 1) || (opt > 3))
	{
		cout << "\nInvalid. Please choose again...\n" << endl ; 
		goto optloop1 ;				
	}	
			
	return opt ;	
}
	    
int Menu()
{
	int option ;
			
	optloop2: // Loop if key in invalid option
	cout << ":: What Can I Help You ::" << endl 
		 << "[1] Add Customer" << endl 
		 << "[2] Delete Customer" << endl 
		 << "[3] Find Customer" << endl 
		 << "[4] Sort Customer List" << endl
		 << "[5] Display Customer List" << endl 
		 << "[6] Quit" << endl ;
	cout << "OPTION >> " ;
	cin >> 	option ;
			
	if((option < 1) || (option > 6))
	{
		cout << "\nInvalid. Please choose again...\n" << endl ; 
		goto optloop2 ;				
	}	
			
	return option ;
}	

int main() 
{
	cout << "- Hotel Booking System -" << endl << endl ;
	
	MenuLoop: // Loop if key in invalid option
    int menu = Menu() ;
    
    switch(menu)
    {
    	case 1 : {	 // Add customer
    				int cusOpt ;
    				Customer *tempCust ;
    				
    				cout << "\nChoose the customer you want to add" << endl 
    					 << "Select from 1 to 10" << endl << endl 
    					 << "Customer -> " ;
    				cin >> cusOpt ;
    				
    				tempCust = &customer[cusOpt] ;
    				
    				int option = Option() ;
    				
    				if(option == 1)
					{	
						custList.addCustAtBegin(tempCust) ;
					} 
					else if(option == 2)
					{
						int position ;
						
						cout << "\nWhat position you want to add ?" << endl 
							 << "*The position started from 1, not 0*" << endl 
							 << "Position -> " ;
						cin >> position ;
						
						custList.addCustAtMid(tempCust, position) ;
					}
					else
					{
						custList.addCustAtEnd(tempCust) ;
					}
    				
					break;
				 }
		case 2 : { // Delete customer
					int option = Option() ;
    				
    				if(option == 1)
					{	
						custList.deleteFront() ;
					} 
					else if(option == 2)
					{
						int position ;
						
						cout << "\nWhat position you want to delete ?" << endl
							 << "*The position started from 1, not 0*" << endl 
							 << "Position -> " ;
						cin >> position ;
						
						custList.deleteMid(position) ;
					}
					else
					{
						custList.deleteEnd() ;
					}
						
					break;
				 }
		case 3 : {	// Find customer
					custList.findCustomer() ;
					break;
				 }
		case 4 : { // Sort customer
					custList.sorting() ; 
					break;
				 }
		case 5 : { // Display all customers data current have
					custList.displayList() ;
					break;
				 }
		default: { // Quit program
					cout << "\nBye" << endl ;
					return 1 ;
					break ;
				 }	
	}
    
    if(menu != 6)
    {
    	cout << endl ;
		goto MenuLoop ;
	}	

    return 0;	
}