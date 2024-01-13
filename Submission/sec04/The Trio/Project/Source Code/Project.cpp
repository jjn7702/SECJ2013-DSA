#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std ;

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

