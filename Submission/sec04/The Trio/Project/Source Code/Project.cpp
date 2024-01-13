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

        
};