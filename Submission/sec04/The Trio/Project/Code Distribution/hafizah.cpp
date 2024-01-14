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
