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
