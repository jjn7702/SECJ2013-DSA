#include <iostream>
#include <fstream>
#include <iomanip>
#define N 10
using namespace std;

void header() {
	cout << "List of Books in the Library:\n" << endl;
	cout << left 
		 << setw(9) << "ID" 
		 << setw(31) << "BOOK TITLE" 
		 << setw(29) << "BOOK AUTHOR"
		 << setw(9) << "YEAR" 
		 << setw(8) << "GENRE" 
		 << endl
		 <<"---------------------------------------------------------------------------------------------------"
		 << endl << endl;
}
void mainOption() {
	cout << "\nMain Menu" << endl
		 << "[1] Sorting" << endl
		 << "[2] Searching" << endl
		 << "[3] Exit" << endl
		 << "\nOption: ";
}

void sortingOption() {
	cout << "\nSelect Sorting Type" << endl
		 << "[1] By Book ID" << endl
		 << "[2] By Title" << endl
		 << "[3] By Author" << endl
		 << "[4] By Genre" << endl
		 << "[5] By Year" << endl
		 << "\nOption: ";
}

void sortOrderOption() {
	cout << "\nSelect Sorting Order" << endl
		 << "[1] Ascending Order" << endl
		 << "[2] Descending Order" << endl
		 << "\nOption: ";
}

void searchingOption() {
	cout << "\nSelect Searching Type" << endl
		 << "[1] By Book ID" << endl
		 << "[2] By Title" << endl
		 << "[3] By Author" << endl
		 << "[4] By Genre" << endl
		 << "[5] By Year" << endl
		 << "\nOption: ";
}

class Book {
	string id, name, author, genre;
	int year;
	public:
		Book(string _id = "", string _name = "", string _author = "", int _year = 0, string _genre = "") {
			id = _id;
			name = _name;
			author = _author;
			year = _year;
			genre = _genre;
		}
		void setID(string _id) {
			id = _id;
		}
		void setName(string _name) {
			name = _name;
		}
		void setAuthor(string _author) {
			author = _author;
		}
		void setYear(int _year) {
			year = _year;
		}
		void setGenre(string _genre) {
			genre = _genre;
		}
		string getID() {
			return id;
		}
		string getName() {
			return name;
		}
		string getAuthor() {
			return author;
		}
		int getYear() {
			return year;
		}
		string getGenre() {
			return genre;
		}
		void printBooks() {
			cout << left 
				 << setw(8) << id << " " 
				 << setw(30) << name << " " 
				 << setw(28) << author << " "
				 << setw(8) << year << " " 
				 << setw(10) << genre << endl;
		}
};

void swap(Book& x, Book& y)
{
	Book temp = x;
	x = y;
	y = temp;
}

void selection(Book list[], int n, int op, int opt)
{
	for (int last = n-1; last >=1; --last) {
		int largest = 0;
		int smallest = 0;
		
		switch (op) {
		case 1: //Sort by Book ID
			//Ascending
			if (opt == 1) {
				for (int p = 1; p <= last; ++p) {
            		if (list[p].getID() > list[largest].getID())
                		largest = p;
        		}
        		swap(list[largest], list[last]);
        	break;
			}
			//Descending
			else {
				for(int p = 1; p <= last; ++p) {
					if (list[p].getID() < list[smallest].getID())
						smallest = p;
				}
				swap(list[smallest], list[last]);
			break;
			}

		case 2: //Sort by Title
			if (opt == 1) {
				for (int p = 1; p <= last; ++p) {
            		if (list[p].getName() > list[largest].getName())
				largest = p;
        		}
        		swap(list[largest], list[last]);
        		break;
			}
			
			else {
				for(int p = 1; p <= last; ++p) {
					if (list[p].getName() < list[smallest].getName())
						smallest = p;
				}
				swap(list[smallest], list[last]);
			break;
			}

		case 3: //Sort by Author
			if (opt == 1) {
				for (int p = 1; p <= last; ++p) {
            		if (list[p].getAuthor() > list[largest].getAuthor())
                		largest = p;
        		}
        		swap(list[largest], list[last]);
        	break;
			}
			
			else {
				for(int p = 1; p <= last; ++p) {
					if (list[p].getAuthor() < list[smallest].getAuthor())
						smallest = p;
				}
				swap(list[smallest], list[last]);
			break;
			}

		case 4: //Sort by Genre
			if (opt == 1) {
				for (int p = 1; p <= last; ++p) {
            		if (list[p].getGenre() > list[largest].getGenre())
                		largest = p;
        		}
        		swap(list[largest], list[last]);
        	break;
			}
			
			else {
				for(int p = 1; p <= last; ++p) {
					if (list[p].getGenre() < list[smallest].getGenre())
						smallest = p;
				}
				swap(list[smallest], list[last]);
			break;
			}

		case 5: //Sort by Year
			if (opt == 1) {
				for(int p = 1; p <= last; ++p) {
					if (list[p].getYear() > list[largest].getYear())
						largest = p;
				}
				swap(list[largest], list[last]);
			break;
			}
			
			else {
				for(int p = 1; p <= last; ++p) {
					if (list[p].getYear() < list[smallest].getYear())
						smallest = p;
				}
				swap(list[smallest], list[last]);
			break;
			}
		}
	
	}
	cout << "\nSorted Book List: " << endl;
	header();
	for (int j = 0; j < N; j++) {
		list[j].printBooks();
	}
}

void searchId(Book b[]){
	int i;
	string id;
	bool found = false;
	cout << "Enter the book ID: ";
	cin >> id;
	
	for(i=0; i<N; i++){
		if(id == b[i].getID()){
			found = true;
			break;
		}
	}
	if(found == true){
		cout << "\nThis is the book you are looking for:\n";
		header();
		b[i].printBooks();
	}
	else
		cout << "Invalid Id";
}

void searchName(Book b[]){
	int i;
	string name;
	bool found = false;
	cout << "Enter the book Title: ";
	cin.ignore();
	getline(cin, name);
	
	for(i=0; i<N; i++){
		if(name == b[i].getName()){
			found = true;
			break;
		}
	}
	if(found == true){
		cout << "\nThis is the book you are looking for:\n";
		header();
		b[i].printBooks();
	}
	else
		cout << "Invalid Book Title";
}

void searchAuthor(Book b[]){
	int i;
	string author;
	bool found = false;
	cout << "Enter the book Author: ";
	cin.ignore();
	getline(cin, author);
	
	for(i=0; i<N; i++){
		if(author == b[i].getAuthor()){
			found = true;
			break;
		}
	}
	if(found == true){
		cout << "\nThis is the book you are looking for:\n";
		header();
		b[i].printBooks();
	}
	else
		cout << "Invalid Book Genre";
}
