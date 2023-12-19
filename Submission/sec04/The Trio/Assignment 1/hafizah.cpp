// Sort customers based on name
void SortingName(Customer data[], int size)
{        
	Customer temp;
	bool sorted = false; 
		    
	for (int pass = 1 ; (pass < size) && !sorted ; ++pass)
	{
		sorted = true; // end the loop if all data is been sorted 
		for (int x = 0; x < size-pass; x++)
		{
		    if (data[x].getName() > data[x+1].getName())
		  	{
		        temp.setName(data[x].getName());
		        temp.setAge(data[x].getAge());
		        temp.setIC(data[x].getIC());
		        temp.setPhone(data[x].getPhone());
		        temp.setNum(data[x].getNum());
		        temp.setDate(data[x].getDate());
		        
		        data[x].setName(data[x+1].getName());
		        data[x].setAge(data[x+1].getAge());
		        data[x].setIC(data[x+1].getIC());
		        data[x].setPhone(data[x+1].getPhone());
		        data[x].setNum(data[x+1].getNum());
		        data[x].setDate(data[x+1].getDate());
		        
		        data[x+1].setName(temp.getName());
		        data[x+1].setAge(temp.getAge());
		        data[x+1].setIC(temp.getIC());
		        data[x+1].setPhone(temp.getPhone());
		        data[x+1].setNum(temp.getNum());
		        data[x+1].setDate(temp.getDate());
		        
		        sorted = false; // for control the loop
		    }
		}
	}
} // end of sort based on name

// Sort customers based on age
void SortingAge(Customer data[], int size)
{        
	Customer temp;
	bool sorted = false; 
		    
	for (int pass = 1 ; (pass < size) && !sorted ; ++pass)
	{
		sorted = true; // end the loop if all data is been sorted
		for (int x = 0; x < size-pass; x++)
		{
		    if (data[x].getAge() > data[x+1].getAge())
	  		{
		        temp.setName(data[x].getName());
		        temp.setAge(data[x].getAge());
		        temp.setIC(data[x].getIC());
		        temp.setPhone(data[x].getPhone());
		        temp.setNum(data[x].getNum());
		        temp.setDate(data[x].getDate());
		        
		        data[x].setName(data[x+1].getName());
		        data[x].setAge(data[x+1].getAge());
		        data[x].setIC(data[x+1].getIC());
		        data[x].setPhone(data[x+1].getPhone());
		        data[x].setNum(data[x+1].getNum());
		        data[x].setDate(data[x+1].getDate());
		        
		        data[x+1].setName(temp.getName());
		        data[x+1].setAge(temp.getAge());
		        data[x+1].setIC(temp.getIC());
		        data[x+1].setPhone(temp.getPhone());
		        data[x+1].setNum(temp.getNum());
		        data[x+1].setDate(temp.getDate());
		        
		        sorted = false; // for control the loop
		    }
		}
	}
} // end of sort based on age

// Sort customers based on IC number
void SortingIC(Customer data[], int size)
{        
	Customer temp;
	bool sorted = false;
		    
	for (int pass = 1 ; (pass < size) && !sorted ; ++pass)
	{
		sorted = true; // end the loop if all data is been sorted
		for (int x = 0; x < size-pass; x++)
		{	// Malaysian IC first 2 number can be counted as age
		    if (data[x].getAge() > data[x+1].getAge())
	  		{
		        temp.setName(data[x].getName());
		        temp.setAge(data[x].getAge());
		        temp.setIC(data[x].getIC());
		        temp.setPhone(data[x].getPhone());
		        temp.setNum(data[x].getNum());
		        temp.setDate(data[x].getDate());
		        
		        data[x].setName(data[x+1].getName());
		        data[x].setAge(data[x+1].getAge());
		        data[x].setIC(data[x+1].getIC());
		        data[x].setPhone(data[x+1].getPhone());
		        data[x].setNum(data[x+1].getNum());
		        data[x].setDate(data[x+1].getDate());
		        
		        data[x+1].setName(temp.getName());
		        data[x+1].setAge(temp.getAge());
		        data[x+1].setIC(temp.getIC());
		        data[x+1].setPhone(temp.getPhone());
		        data[x+1].setNum(temp.getNum());
		        data[x+1].setDate(temp.getDate());
		        
		        sorted = false; // for control the loop
		    }
		}
	}
} // end of sort based on IC number

// Search key based on name, IC number, phone number or check in date
void Search(string searchKey, Customer data[], int size)
{ 
	int index = -1 ; //-1 means record is not found
	for (int i = 0; i < size; i++)
	{ 
		if (searchKey == data[i].getName())
		{ 
			index = i; // assign current array index
			break; //terminate searching
		}
		else if(searchKey == data[i].getIC())
		{ 
			index = i; // assign current array index
			break; //terminate searching
		}
		else if(searchKey == data[i].getPhone())
		{ 
			index = i; // assign current array index
			break; //terminate searching
		}
		else if(searchKey == data[i].getDate())
		{ 
			index = i; // assign current array index
			break; //terminate searching
		}	
	} //end for
	
	if(index == -1) // If the key not found
		cout << "\nNot found..." << endl ;
	else
	{	// Display the information after searching if found
		cout << "\nName: " << data[index].getName() << endl
			 << "Age: " << data[index].getAge() << endl
	 		 << "IC Number: " << data[index].getIC() << endl
			 << "Phone Number: " << data[index].getPhone() << endl 
			 << "Room Number: " << data[index].getNum() << endl 
			 << "CheckInDate: " << data[index].getDate() << endl ;	
	}	
} //end of search for name, IC number, phone number, check in date
