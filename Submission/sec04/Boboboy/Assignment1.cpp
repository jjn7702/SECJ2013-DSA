#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#define N 100

using namespace std;

class Menu{
	private:
		string code,name, foodtype;
		float price;
	public:
		Menu(string c = " ", string n = " ", string f = " ", float p =0.0 ){
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
		void settype(string t){
			foodtype = t;
		}
		void setprice(float p){
			price = p;
		}
		void printmenu(){
		cout << code << setw(20) << name << setw(20) << foodtype << setw(20) << price << endl;		
		}
};

void merge(Menu theArray[], int first, int mid, int last,int o) {
    Menu tempArray[N];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    if(o == 1){
    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        if (theArray[first1].getcode() < theArray[first2].getcode()) {
            tempArray[index] = theArray[first1];
            ++first1;
        } else {
            tempArray[index] = theArray[first2];
            ++first2;
        }
    }
	}
	else if(o == 2){
	for (; (first1 <= last1) && (first2 <= last2); ++index) {
        if (theArray[first1].getcode() > theArray[first2].getcode()) {
            tempArray[index] = theArray[first1];
            ++first1;
        } else {
            tempArray[index] = theArray[first2];
            ++first2;
        }
    }
	}
	else if(o == 3){
	for (; (first1 <= last1) && (first2 <= last2); ++index) {
        if (theArray[first1].getname() < theArray[first2].getname()) {
            tempArray[index] = theArray[first1];
            ++first1;
        } else {
            tempArray[index] = theArray[first2];
            ++first2;
        }
    }
	}
	
	else if(o == 4){
	for (; (first1 <= last1) && (first2 <= last2); ++index) {
        if (theArray[first1].getname() > theArray[first2].getname()) {
            tempArray[index] = theArray[first1];
            ++first1;
        } else {
            tempArray[index] = theArray[first2];
            ++first2;
        }
    }
	}
    for (; first1 <= last1; ++first1, ++index)
        tempArray[index] = theArray[first1];

    for (; first2 <= last2; ++first2, ++index)
        tempArray[index] = theArray[first2];

    for (index = first; index <= last; ++index)
        theArray[index] = tempArray[index];
    }

void mergeSort(Menu theArray[], int first, int last,int o) {
    if (first < last){
        int mid = (first + last) / 2;
        mergeSort(theArray, first, mid,o);
        mergeSort(theArray, mid+1, last,o);
        merge(theArray, first, mid, last, o);
    }
}

int Search(string target,Menu theArray[],int size,int key){
	int counter;
	int index = -1;
	if(key == 1 ){
		for(counter = 0;  counter < size; counter++){
			if(target == theArray[counter].getcode()){
				index = counter;
				break;
			}
		}
	}
	else if(key == 2){
		for(counter = 0;  counter < size; counter++){
			if(target == theArray[counter].getname()){
				index = counter;
				break;
			}
		}
	}
	return index;
}

int main(){
    string menu_code, menu_name, menu_type;
	float menu_price;
	Menu a [N];
	int i = 0, option;
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
	cout << "************ Welcome to BOBOBOY Restaurant's Ordering System ************" << endl << endl;
	
	int answer;
	cout << "Select menu display type: " << endl;
	cout << "1. Arrange the Menu by following the code (ascending order)" << endl;
	cout << "2. Arrange the Menu by following the code (descending order)" << endl;
	cout << "3. Arrange the Menu by following the name (ascending order)" << endl;
	cout << "4. Arrange the Menu by following the name (descending order)" << endl;
	cout << "Your choice: ";
	cin >> answer;
	cout << "-------------------------------------------------------------" << endl;
	cout << "Code" << setw(17) << "Name" << setw(20) << "Type" << setw(20) << "Price(RM)" << endl;
	cout << "-------------------------------------------------------------" << endl;
}
    switch(answer){
		case 1: mergeSort(a,0,6,answer);
		        for(int i=0; i <7; i++){
		        	a[i].printmenu();
				}
				break;
		case 2: mergeSort(a,0,6,answer);
		        for(int i=0; i <7; i++){
		        	a[i].printmenu();
				}	
				break;
		case 3: mergeSort(a,0,6,answer);
		        for(int i=0; i <7; i++){
		        	a[i].printmenu();
		        }
		        break;
		case 4: mergeSort(a,0,6,answer);
		        for(int i=0; i <7; i++){
		        	a[i].printmenu();
		        }
		        break;
		default:mergeSort(a,0,6,1);
		        for(int i=0; i <7; i++){
		        	a[i].printmenu();
				}
				break;
	}