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

class Queue{  // used by agent
	private:
		Customer *front, *back ;
	
	public:
		Queue(){ front = NULL ; back = NULL ; }
		bool isEmpty(){ return ( (front == NULL) && (back == NULL) ) ; }
		
		Customer* getFirstReservation() // Get the first customer in the reservation list
		{ 
			if(isEmpty())
			{
				cout << "\nThe reservation list is empty" << endl ;
				return NULL ;
			}
			else
				return front ; 
		}

		void makeReservation(Customer *newCustomer) // enQueue
		{
			if(isEmpty())
			{
				front = newCustomer ;
				back = newCustomer ;
			}
			else
			{
				back->next = newCustomer ;	
				back = newCustomer ;
			}
				
			cout << "\nThe agent has helped "  << newCustomer->getName() << " made the reservation" << endl ;
		}

				// Find customer data
		void findCustReserveList()
		{
			if(isEmpty())
			{
				cout << "\nThe reservation list is empty. Unable to search ..." << endl ;
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
			
			Customer *current = front, *prev = NULL ;
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

		void DoneBooking() // deQueue by hotel manager  //only available by hotel manager
		{
			if(isEmpty())	
				cout << "\nNo reservation in the list" << endl ;
			else
			{
				Customer *delcust = front ;
				
				if(delcust != back)
				{
					front = front->next ;
					delcust->next = NULL ; // to break the line
				}
				else // front = back - only one item in queue
				{
					front = NULL ;
					back = NULL ;
				}

				delcust = NULL ;
				//delete delcust ;
			}
		}

		void displayReservationList()  // Display the reservation list
		{
			Customer *temp = front ;
			Customer *prev ;
			
			if(isEmpty())	
				cout << "\nThe reservation list is empty" << endl ;
			else
			{
				cout << "\nThe Reservation List" << endl ;
				while(temp != NULL) 
				{   
					prev = temp ;
					cout << left ;
			        cout << "Name: " << setw(10) << prev->getName() 
						 << ", Age: " << setw(3) << prev->getAge() 
						 << ", IC: " << setw(15) << prev->getIC()
			             << ", Phone Number: " << setw(12) << prev->getPhone() 
			             << ", Room: " << setw(4) << prev->getNum() 
						 << ", Date: " << prev->getDate() << endl;
			        temp = temp->next;  // Move to next customer	
		        }
	    	}
			cout << endl ;
		}
};

class Stack{  // used by hotel manager
	private:
		Customer cust[100] ;
		int top ;
	
	public:
		Stack(){ top = -1 ; }	// set Top to NULL
		bool isEmpty(){ return top == -1 ; } // check whether stack is empty
		bool isFull(){ return top == 99 ; } // check whether stack is full

        void processBookingRequest(Queue& queue) // push
		{	
			Customer* firstCust = queue.getFirstReservation() ;  // get the fist customer for reservation list
			
			if(firstCust == NULL)
			{
				cout << "\nNo reservation available to process" << endl ;
			}
			else
			{
				Customer *reserveList = new Customer(*firstCust);
				
				if(isFull())
					cout << "The hotel booking request is full" << endl ;
				else
				{
					top++ ;
					cust[top].setName(reserveList->getName()) ;
					cust[top].setAge(reserveList->getAge()) ;
					cust[top].setIC(reserveList->getIC()) ;
					cust[top].setPhone(reserveList->getPhone()) ;
					cust[top].setNum(reserveList->getNum()) ;
					cust[top].setDate(reserveList->getDate()) ;
					
					cout << "\nYou have accepted " << reserveList->getName() << "'s booking request" << endl ;
				
					queue.DoneBooking() ;
				}	

			}
		}

        void cancelBookingRequest() // pop out
		{	
			if(isEmpty())
				cout << "\nNo booking request in the queue" << endl ;
			else
			{
				cout << "\nYou have cancel " << cust[top].getName() << "'s booking request" << endl ;
				top-- ;	
			}				
		}

// Find customer data from accepted booking request list
		void findCustAcceptList()
		{
			if(isEmpty())
			{
				cout << "\nThe booking request list is empty. Unable to search ..." << endl ;
				return ;
			}
			
			int option, i ;
			
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
			
			bool found = false ; 

			switch (option)
		    {
		    	case 1: // Search by Name
		           		{
		           			string n ;
		           			cout << "\nPlease key in the name you want to search" << endl
		           				 << "Name -> " ;
		           			cin >> n ;	 
		           			
		           			for(i = top ; i >= 0 ; i--)
		           			{
		           				if(cust[i].getName() == n)
								{
									 found = true ;
									 break ;
								}
							}
							
		            		break;
		            	}
		        case 2: // Search by Age
		            	{
		           			int a ;
		           			cout << "\nPlease key in the age you want to search" << endl
		           				 << "Age -> " ;
		           			cin >> a ;	 
		           			
							for(i = top ; i >= 0 ; i--)
		           			{
		           				if(cust[i].getAge() == a)
								{
									 found = true ;
									 break ;
								}
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

							for(i = top ; i >= 0 ; i--)
		           			{
		           				if(cust[i].getIC()  == ic)
								{
									 found = true ;
									 break ;
								}
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
							
							for(i = top ; i >= 0 ; i--)
		           			{
		           				if(cust[i].getPhone() == p)
								{
									 found = true ;
									 break ;
								}
							}
							
		            		break;
		            	}
		        case 5: // Search by Room Number
		                {
		           			int r ;
		           			cout << "\nPlease key in the room number you want to search" << endl
		           				 << "Room Number -> " ;
		           			cin >> r ;	 
							
							for(i = top ; i >= 0 ; i--)
		           			{
		           				if(cust[i].getNum()   == r)
								{
									 found = true ;
									 break ;
								}
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
							
							for(i = top ; i >= 0 ; i--)
		           			{
		           				if(cust[i].getDate() == d)
								{
									 found = true ;
									 break ;
								}
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
					 << "Name: " << cust[i].getName() << endl
					 << "Age: " << cust[i].getAge() << endl
					 << "IC Number: " << cust[i].getIC() << endl
					 << "Phone Number: " << cust[i].getPhone() << endl
					 << "Room Number: " << cust[i].getNum() << endl
					 << "Check In Date: " << cust[i].getDate() << endl
					 << endl ;		 
			}
			else
				cout << "\nNo record found" << endl << endl ;							        	
		}    

        void displayRequestList()  // Display the accepted booking request list
		{
			if(isEmpty())
				cout << "\nThe request list is empty" << endl ; 
			else
			{
				cout << "\nThe Accepted Booking Request List" << endl ;
				cout << left ;
				
				for(int i = top ; i >= 0 ; i--)
				{
					cout << "Name: " << setw(10) << cust[i].getName() 
						 << ", Age: " << setw(3) << cust[i].getAge() 
						 << ", IC: " << setw(15) << cust[i].getIC()
		                 << ", Phone Number: " << setw(12) << cust[i].getPhone() 
		                 << ", Room: " << setw(4) << cust[i].getNum() 
						 << ", Date: " << cust[i].getDate() << endl;
				}
				
				cout << endl ;
			}

		}   
};

int User()  //Choose the character
{
	int user ;
	
	UserLoop: // Loop if key in invalid option
	cout << "--- User Menu --- " << endl ;
	cout << "1. Agent" << endl 
		 << "2. Hotel Manager" << endl 
		 << "3. Exit\n" << endl 
		 << "Option: " ;
	
	cin >> user ;
	
	if(user < 1 || user > 3)
	{
		cout << "Please choose a valid option\n" << endl ;
		goto UserLoop ;
	}
	
	return user ;
}

int agentMenu()  // Agent Menu
{
	int option ;
			
	agentloop: // Loop if key in invalid option
	cout << "\n:: What Can I Help You ::" << endl 
		 << "[1] Help Customer Make Reservation" << endl  
		 << "[2] Find Customer Data" << endl 
		 << "[3] Display Customer Reservation List" << endl 
		 << "[4] Quit" << endl ;
	cout << "OPTION >> " ;
	cin >> 	option ;
			
	if((option < 1) || (option > 4))
	{
		cout << "\nInvalid. Please choose again...\n" << endl ; 
		goto agentloop ;				
	}	
			
	return option ;
}

int managerMenu()  // Hotel Manager Menu
{
	int option ;
			
	managerloop: // Loop if key in invalid option
	cout << "\n:: What Do You Want To Do ::" << endl 
		 << "[1] Accept Customer's Booking Request" << endl 
		 << "[2] Cancel Customer's Booking Request" << endl 
		 << "[3] Display Customer Booking Request List" << endl 
		 << "[4] Find Customer Data From Accepted List" << endl
		 << "[5] Display Accepted List" << endl
		 << "[6] Quit" << endl ;
	cout << "OPTION >> " ;
	cin >> 	option ;
			
	if((option < 1) || (option > 6))
	{
		cout << "\nInvalid. Please choose again...\n" << endl ; 
		goto managerloop ;				
	}	
			
	return option ;
}

int main()
{
	Customer customer[100] ;
	Stack s ;
	Queue q ;
	int custNum = 0 ;

	string name, IC, phoneNum, date ;
	int age, room ; 
	
	// file as database
	ifstream input("Project.txt") ;

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
	
	cout << "- Agent-Based Hotel Booking System -" << endl << endl ;
	
	userLoop:
	int user = User() ;
	
	switch(user)
    {
    	case 1 : {	
    				int agent ;
    				repeatAgent:
					agent = agentMenu() ;
					
					switch(agent)
					{
						case 1 : {  // Add customer to reservation list
									Customer *tempCust ;
    								int cusOpt ;
    					
				    				cout << "\nChoose the customer you want to add" << endl 
				    					 << "Select from 1 to 10" << endl << endl 
				    					 << "Customer -> " ;
				    				cin >> cusOpt ;
				    				
				    				tempCust = &customer[cusOpt-1] ;
				    				
				    				q.makeReservation(tempCust) ;
									break;
								 }
						case 2 : {	// Find customer from reservation list
									q.findCustReserveList() ;
									break;
								 }
						case 3 : {	// Display the reservation list
									q.displayReservationList() ;
									break;
								 }
						default: {  // Quit
									break;
								 }
					}
					
					if(agent != 4) // Loop if user no select to quit
					{
						cout << endl ;
						goto repeatAgent ;
					}
					
					break ;
				 }
				 
		case 2 : {	
					int manager ;
					repeatManager:
					manager = managerMenu() ;
					switch(manager)
					{
						case 1 : {  // Accept customer from reservation list
									s.processBookingRequest(q) ; 
									break;
								 }
						case 2 : {  // Cancel customer data from accepted request list
									s.cancelBookingRequest() ;
									break;
								 }
						case 3 : {	// Display the reservation list
									q.displayReservationList() ;
									break;
								 }
						case 4 : {  // Find customer from accepted request list
									s.findCustAcceptList() ;
									break;
								 }
						case 5 : {	// Display accepted request list
									s.displayRequestList() ;
									break;
								 }
						default: {  // Quit
									break;
								 }
					}
					
					if(manager != 6)  // Loop if user no select to quit
					{
						cout << endl ;
						goto repeatManager ;
					}
					
					break ;
				 }
				 
		default: {	// Quit program
					cout << "\nBye" << endl ;
					return 1 ;
					break;
				 }
	}
	
	if(user != 3)  // Loop if user does not select exit
    {
    	cout << endl ;
		goto userLoop ;
	}
	
	return 0 ;
}
