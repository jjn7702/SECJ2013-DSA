#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#define N 14
using namespace std;

class Menu{
	private:
		string code,name, foodtype;
		float price;
	public:
		Menu(string c = " ",string n = " ", string f = " ", float p =0.0 ){
			code = c;
			name = n;
			foodtype = f;
			price = p;
		}
		string getcode(){
			return code;
		}
		string getname(){
			return name;
		}
		string getfoodtype(){
			return foodtype;
		}
		float getprice(){
			return price;
		}
		void setcode(string c){
			code = c;
		}
		void setname(string n){
			name = n;
		}
		void settype(string f){
			foodtype = f;
		}
		void setprice(float p){
			price = p;
		}
		void printmenu(){
		cout << code << setw(20) << name << setw(20) << foodtype << setw(20) << price << endl;		
		}
};

class Order{
	Menu menu;
	string code,name, foodtype;
	float price;
		
	public:
		Order *next;
		Order(string c ,string n, string f ,float p){
			code = c;
			name = n;
			foodtype = f;
			price = p;
			next = NULL;
		}
		string getcode(){
			return code;
		}
		string getname(){
			return name;
		}
		string getfoodtype(){
			return foodtype;
		}
		float getprice(){
			return price;
		}
		void setcode(string c){
			code = c;
		}
		void setname(string n){
			name = n;
		}
		void settype(string f){
			foodtype = f;
		}
		void setprice(float p){
			price = p;
		}
};

class Cart{
	Order *head;
	public:
		Cart(){
			head = NULL;
		}
		
		bool CartEmpty(){
			return head == NULL;
		}
		
		void insert(Order *newNode,int w){
			if(w == 1){
				if(CartEmpty()){
					head = newNode;
				}
				else{
					newNode ->next = head;
					head = newNode;
				}
			}//insert the number in front
            else if (w == 2){
				if(CartEmpty()){
					head = newNode; 
				}
				else{
					int position;
					cout << "Enter the position that you want to key in:";
					cin >> position;
					Order *temp = head;
					for(int i =1; i<(position-1); i++){   // int count = 1;   while(temp->next!= NULL && count <loc){ temp = temp-> next; count ++
						temp = temp->next;
					}
					newNode->next = temp->next;
					temp->next = newNode;
				}
			}// insert the number at the middle which the user provide the location
			else if (w == 3){
				if(CartEmpty()){
					head = newNode;
				}
				else{
					Order *temp = head;
					while(temp->next != NULL){   // make it become null until the last
						temp = temp->next;
					}
					temp-> next = newNode;
				}
			}// insert the number at the last
		}
        void deleteNode(int w){
			Order *temp = head;
			if(w == 1){
				if(CartEmpty()){
					cout << "Does not have order can be delete" << endl; 
				}
				else{
					if(temp->next != NULL){
					head = head->next;
					temp ->next = NULL;
					}
					delete temp;
				}
			}// delete the first number
            else if (w == 2){
				if(CartEmpty()){
					cout << "Does not have order can be delete" << endl;
				}
				else{
					int position;
					cout << "Enter the position that you want to key in:";
					cin >> position;
					Order *temp1;
					for(int i =1; i<position; i++){   // int count = 1;   while(temp->next!= NULL && count <loc){ temp = temp-> next; count ++
						temp1 = temp;
						temp = temp->next;
					}
					temp1->next = temp->next;
					temp->next = NULL;
					delete temp;
				}
			}// delete the number at the middle which the user provide the location
				else if(w == 3){
				if(CartEmpty()){
					cout << "Does not have order can be delete" << endl;
				}
				else{
					Order *temp1;
					while(temp->next != NULL){
						temp1 = temp;
						temp = temp -> next;
					}
					temp1->next = NULL;
					delete temp;
				}
			}// delete the last
		}
		void displayCart(){
			Order *temp;
			temp = head;
			if(temp == NULL){
				cout << "Cart is empty" << endl;
				return;
			}
			cout << "************************* CART *******************************" << endl << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "Code" << setw(18) << "Name" << setw(20) << "Type" << setw(20) << "Price(RM)" << endl;
			cout << "--------------------------------------------------------------" << endl;
			while(temp){
				cout << temp->getcode() << setw(20) << temp->getname() << setw(20) << temp->getfoodtype() << setw(20) << temp->getprice() << endl;
				temp = temp -> next;
			}
			 cout << endl;
		}
        void displayReceipt(int order_num){
			fstream outfile("Receipt.txt",ios :: out);
			Order *temp;
			temp = head;
			float totalprice;
			if(temp == NULL){
				outfile << "Cart is empty" << endl;
				cout << "Cart is empty" << endl;
			}
			outfile << "Your Order Number is: " << order_num << endl;
			outfile << "********************** Receipt *******************************" << endl << endl;
			outfile << "--------------------------------------------------------------" << endl;
			outfile << "Code" << setw(18) << "Name" << setw(20) << "Type" << setw(20) << "Price(RM)" << endl;
			outfile << "--------------------------------------------------------------" << endl;
			cout << "********************** Receipt *******************************" << endl << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "Code" << setw(18) << "Name" << setw(20) << "Type" << setw(20) << "Price(RM)" << endl;
			cout << "--------------------------------------------------------------" << endl;
			while(temp){
				cout << temp->getcode() << setw(20) << temp->getname() << setw(20) << temp->getfoodtype() << setw(20) << temp->getprice() << endl;
				outfile << temp->getcode() << setw(20) << temp->getname() << setw(20) << temp->getfoodtype() << setw(20) << temp->getprice() << endl;
				totalprice += temp->getprice();
				temp = temp -> next;
			}
			outfile << "The Total Price is " << setw(43) << totalprice << endl;
			 cout << endl;
			 outfile << endl;
		}
        Order* find(string target,int n){
			Order *current = head;
			while(current){
				if(n == 1){
					if(current -> getcode() == target){
						return current;
					}
				}
				else if(n == 2){
					if(current -> getname() == target){
						return current;
					}
				}
				current = current ->next;
			}
			return NULL; 
		}
		void bubbleSort(){
        int swapped,way;
        Order *ptr1;
        Order *lptr = NULL;
        
        cout << "Select Receipt display type: " << endl;
    	cout << "1. Arrange the Receipt by following the code (ascending order)" << endl;
    	cout << "2. Arrange the Receipt by following the code (descending order)" << endl;
    	cout << "3. Arrange the Receipt by following the name (ascending order)" << endl;
    	cout << "4. Arrange the Receipt by following the name (descending order)" << endl;
    	cout << "5. Arrange the Receipt by following the foodtype (ascending order)" << endl;
    	cout << "6. Arrange the Receipt by following the foodtype (descending order)" << endl;
    	cout << "Your choice:";
    	cin >> way;
        // Checking for empty list
        if (head == NULL)
            return;
        if(way == 1){
        do {
            swapped = 0;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->getcode() > ptr1->next->getcode()) {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
        else if(way == 2){
        do {
            swapped = 0;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->getcode() < ptr1->next->getcode()) {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
     else if(way == 3){
        do {
            swapped = 0;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->getname() > ptr1->next->getname()) {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
        else if(way == 4){
        do {
            swapped = 0;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->getname() < ptr1->next->getname()) {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
	else if(way == 5){
        do {
            swapped = 0;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->getfoodtype() > ptr1->next->getfoodtype()) {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
            if(way == 6){
        do {
            swapped = 0;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->getfoodtype() < ptr1->next->getfoodtype()) {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
    }
        void swap(Order *a, Order *b) {
        string temp_code = a->getcode();
        string temp_name = a->getname();
        string temp_foodtype = a->getfoodtype();
        float temp_price = a->getprice();

        a->setcode(b->getcode());
        a->setname(b->getname());
        a->settype(b->getfoodtype());
        a->setprice(b->getprice());

        b->setcode(temp_code);
        b->setname(temp_name);
        b->settype(temp_foodtype);
        b->setprice(temp_price);
    }
    
        void clearCart(){
    	    while(head != NULL){
    		    Order * temp = head;
    		    head = head->next;
    		    delete temp;
		    }
	    }
	void order_list(int ordernum){
		Order *temp;
		temp = head;
		string number_as_string = to_string(ordernum);
		ofstream outputfile("Order_"+number_as_string+".txt");
		if(outputfile.is_open()){
		//cout << "File can open " << endl;
			while(temp){
				outputfile << temp->getname() << endl;
				temp = temp->next;
			//cout << "file can output" << endl;
			}
		}
		else{
			cout << "file cannot open" << endl;
		}
	}
    void display_order_list(){
	string name,number;
	cout << "Enter the Order Number :";
	cin >> number;
	ifstream inputfile("Order_"+number+".txt");
	cout << "The Order list :" << endl;
	if(inputfile.is_open()){
		while(getline(inputfile,name)){
			cout << name << endl;
		}
	}
	else{
		cout << "file cannot open" << endl;
	}
}
};

class Retaurant{
	int front;
	int back;
	int count;
	int customer_num; 
	int items[N];
	public:
		Retaurant(){
			front = 0;
			count = 0;
			back = N-1;
			customer_num = 0;
		}
		bool isEmpty(){
			return (count == 0);
		}
		bool isFull(){
			return (count == N);
		}
		void enQueue(int d){
			if(isFull()){
				cout << "Sorry, the queue is full" << endl;
			}
			else{
			    back = (back + 1) % N;
			    items[back] = d; // items[++ back] = d
			    count ++;
			    customer_num++;
		    }
		}
		void deQueue(){
			if(isEmpty()){
				cout << "Sorry, no item in the queue" << endl;
			}
			else{
				cout << "The customer Order "<< items[front] <<" has been done" << endl;
				front = (front + 1) % N;
				count --;
			}
		}
		int getFront(){
			return items[front];
		}
		int getBack(){
			return items[back];
		}
		int getcustomer_num(){
			return customer_num;
		}
		void print(){
			if(isEmpty()){
				cout << "No order is placed" << endl;
			}
			else{
			if(front > back){
				for(int i = front; i<N; i++){
					cout << "The Number Order " << items[i] << " is placed" << endl;
				}
				for(int i = 0; i <= back; i++){
					cout << "The Number Order " << items[i] << " is placed" << endl;
			    }
			}
			else{
				for(int i = front; i <= back; i++){
					cout << "The Number Order " << items[i] << " is placed" << endl;	
			    }
			}
		}
		cout << endl;
	}
	void checkStatus() {
	int expectedNumber;
	cout << "Enter Your Order Number: ";
	cin >> expectedNumber;
    bool orderFound = false;

    for (int i = front; i <= back; i++) {
        int currentNumber = items[i];
        if (currentNumber == expectedNumber) {
            orderFound = true;
            cout << "Order Number " << currentNumber << " is in progress." << endl;
            break;  // Exit the loop once the order is found
        }
    }

    if (!orderFound) {
        cout << "Order Number " << expectedNumber << " completed." << endl;
    }
}
};