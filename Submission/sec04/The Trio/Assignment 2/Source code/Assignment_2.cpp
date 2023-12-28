#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std ;

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