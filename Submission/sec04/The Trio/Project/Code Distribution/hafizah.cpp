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
