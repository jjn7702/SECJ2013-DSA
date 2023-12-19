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