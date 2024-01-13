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

};