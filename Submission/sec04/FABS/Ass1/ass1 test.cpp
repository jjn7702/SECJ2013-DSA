#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Courier {
private:
    string name, parcelType, source, destination, status;
    int trackingNum;

public:
    Courier(string n = " ", string p = " ", string s = " ", string d = " ", string st = " ", int t = 0)
        : name(n), parcelType(p), source(s), destination(d), status(st), trackingNum(t) {}

    void setName(string n) { name = n; }
    void setType(string p) { parcelType = p; }
    void setSource(string s) { source = s; }
    void setDest(string d) { destination = d; }
    void setStat(string st) { status = st; }
    void setTrackNum(int t) { trackingNum = t; }

    string getName() const { return name; }
    string getType() const { return parcelType; }
    string getSource() const { return source; }
    string getDest() const { return destination; }
    string getStat() const { return status; }
    int getTrackNum() const { return trackingNum; }

 	int readFile(ifstream& file, Courier couriers[]) {
    	if (!file.is_open()) {
        	cout << "Error: Unable to open the file\n";
        	return 0;
  		}
		int m = 0;
    	while (getline(file, couriers[m].name, ',')){
           getline(file, couriers[m].parcelType, ',') ;
           getline(file, couriers[m].source, ',');
           getline(file, couriers[m].destination, ',') ;
           getline(file, couriers[m].status, ',');
		   file >> couriers[m].trackingNum;  
      	   file.ignore();
       	   ++m;
   		}
    return m;
}

	void writeFile(string filename, Courier arr[]) {
    	ofstream outFile(filename);

    	if (!outFile.is_open()) {
        	cout << "Error: Unable to open the file for writing\n";
        	return;
   		}

    	for (int i = 0; i < size; ++i) {
        	outFile << arr[i].getName() << ',' << arr[i].getType() << ',' << arr[i].getSource() << ',' 
                	<< arr[i].getDest() << ',' << arr[i].getStat() << ',' << arr[i].getTrackNum() << '\n';
    	}

   		outFile.close();
}

    void display() const {
        cout << left << setw(25) << name
             << setw(15) << parcelType
             << setw(15) << source
             << setw(18) << dest
             << setw(16) << stat
             << setw(15) << trackNum << endl;
    }
};


int searchString(string key, Courier arr[], int size) {
    for (int i = 0; i < size; i++) {
	if (arr[i].getName() == key || arr[i].getType() == key || arr[i].getSource() == key ||
	    arr[i].getDest() == key || arr[i].getStat() == key) {
	    return i;
	}
    }
return -1;
}

int SearchInt(int key, Courier arr[], int size) {
    for (int i = 0; i < size; ++i) {
	if (arr[i].getTrackNum() == key) {
	    return i;
	}
    }
return -1;
}

bool compareStrByName(Courier& a, Courier& b) {
     return a.getName() < b.getName();
}

bool compareStryByType(Courier& a, courier& b) {
     return a.getType() < b.getType();
}

void swap(Courier& a, Courier& b) {
     Courier temp = a;
     a = b;
     b = temp;
}

int partitionInt(Courier arr[], int first, int last) {
    int pivot = arr[last].getTrackNum();
    int bottom = first - 1, top = last;

    while (true) {
	while (arr[--top].getTrackNum() > pivot);
	while (arr[++bottom].getTrackNum() < pivot);
	if (bottom < top) {
		swap(arr[bottom], arr[top]);
    	}
	else {
	  break;
	}
    }  
    swap(arr[bottom], arr[last]);
    return bottom;
}

int partitionSortByName(Courier arr[], int first, int last) {
    Courier pivot = arr[last];
    int bottom = first - 1, top = last;

    while (true) {
	while (arr[--top].getName() > pivot.getName());
	while (arr[++bottom].getName() < pivot.getName());
	if (bottom < top){
		swap(arr[bottom], arr[top]);
   	 }
	else {
	  break;
	}
    } 
    swap(arr[bottom], arr[last]);
    return bottom;
}

int partitionSortByType(Courier arr[], int first, int last) {
	Courier pivot = arr[last];
	int bottom = first - 1; top = last;

	while(true) {
		while (arr[--top].getName() > pivot.getName());
	while (arr[++bottom].getName() < pivot.getName());
	if (bottom < top){
		swap(arr[bottom], arr[top]);
   	 }
	else {
	  break;
	}
    } 
    swap(arr[bottom], arr[last]);
    return bottom;
}

void quickSortInt(Courier arr[], int first, int last) {
	if (first < last) {
		int pivot = partitionInt(arr, first, last);

	quickSortInt(arr, first, pivot - 1);
	quickSortInt(arr, pivot + 1, last);
	}
}

void quickSortStr(Courier arr[], int first, int last, bool sortByType) {
	if (first < last) {
		int pivotIndex;
		if (sortByType) {
			pivotIndex = partitionStrByType(arr, first, last);
		}
		else {
			pivotIndex = partitionStrByName(arr, first, last);
		}

	quickSortStr(arr, first, pivotIndex - 1, sortByType);
	quickSortStr(arr, pivotIndex + 1, last, sortByType);
	}
}

int main() {
	
    Courier couriers[size];
    ifstream file("customer.txt");

    for(int i = 0; i < size; i++){
    couriers[i].readFile(file, couriers);
    }

    int choice, index, intKey;;
    string key;
    int index = -1; // Move the declaration outside the switch statement

    do {
        cout << "Menu:\n"
	     << "[1] View all couriers\n"
             << "[2] Sort couriers(ascending)\n"
             << "[3] Search courier\n"
             << "[4] Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
 		cout << "\n| Name              | Parcel Type   | Source         | Destination    | Status          | Tracking Number |\n"
                     << "---------------------------------------------------------------------------------------------------------------------\n";
                for (int i = 0; i < size; ++i) {
                    couriers[i].display();
                }
                cout << endl;
                break;

            case 2:
                cout << "\nSorting options:\n"
                     << "[1] Sort by Name\n"
                     << "[2] Sort by Parcel Type\n"
                     << "[3] Sort by Tracking Number\n"
                     << "Enter your sorting choice: ";
                int sortingChoice;
		cin >> sortingChoice;

		switch (sortingChoice) {
                }                
                break;

            case 3:
                cout << "\nChoose search type:\n"
      		     << "[1] Search by string\n"
                     << "[2] Search by integer\n"
                     << "Enter your choice: ";
                int searchType;
                cin >> searchType;

		switch (searchType) {
                break;

            case 4:
                for(int i = 0; i < size; i++)
                couriers[i].writeFile("sorted_couriers.txt", couriers);

                cout << "\nData has been written to sorted_couriers.txt\n";
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
