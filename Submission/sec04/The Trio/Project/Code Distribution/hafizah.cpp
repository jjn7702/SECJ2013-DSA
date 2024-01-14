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
	public:
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
};
