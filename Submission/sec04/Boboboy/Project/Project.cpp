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