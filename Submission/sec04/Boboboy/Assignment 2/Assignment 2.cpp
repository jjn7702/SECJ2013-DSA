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
        }
		Order* find(string target,int n){
			Order *current = head;
			while(current){
				if(n == 1){
					if(current -> getcode() == target){
						return current;
					}
				}
			}
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

                while (ptr1->next != lptr){
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
                }while (swapped);
            }
			else if(way == 3){
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
                }while (swapped);
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
                }while (swapped);
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
};

int main(){
	string menu_code, menu_name, menu_type,order;
	float menu_price;
	Menu a [N];
	int i = 0, option,answer,cus_action,proses;
	Cart b;
	ifstream file("input.txt.txt");
	if(!file){
		cout << " Error opening file" << endl;
	}
	else{
		cout << "File can run" << endl; // use for testing the file
	}
	while(getline(file,menu_code,',')){
		getline(file,menu_name,',');
		getline(file,menu_type,',');
		file >> menu_price;
		file.ignore();
		a[i].setcode(menu_code);
		a[i].setname(menu_name);
		a[i].settype(menu_type);
		a[i].setprice(menu_price);
		i++;
	}
	
}