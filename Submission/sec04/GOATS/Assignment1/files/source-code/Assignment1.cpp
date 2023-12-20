#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Doctor{
    private:
        string id;
        string name;
        int age;
        string position; 
        string department;
    public:
        Doctor(string i = "", string n = "", int a = 0, string p = "", string dept = ""){
            id = i;
            name = n;
            age = a;
            position = p;
            department = dept;
        }
        void display(){
            cout << "Id: " << id
                 << "\nName: " << name
                 << "\nAge: " << age
                 << "\nPosition: " << position
                 << "\nDepartment: " << department << "\n\n";
        }
        string getID() const{
        	return id;
		}
		string getName() const{
			return name;
		}
		int getAge() const{
			return age;
		}
		string getPosition() const{
			return position;
		}
		string getDepartment() const{
		return department;
		}
};

class Patient{
    private:
        string ic;
        string name;
        int age;
        string sickness;
        string docIncharge; // maybe change

    public:
        Patient(string icNum = "", string n = "", int a = 0, string sick="", string doc = "")
        {
            ic = icNum;
            name = n;
            age = a;
            sickness = sick;
            docIncharge = doc;
        }
        void display(){ // maybe will change to more better view
            cout << "Ic:" << ic
                 << "\nName: " << name
                 << "\nAge: " << age
                 << "\nSickness: " << sickness
                 << "\nDoctor In-Charge: " << docIncharge << "\n\n";
        }
        string getIC() const{
        	return ic;
		}
		string getName() const{
			return name;
		}
		int getAge() const{
			return age;
		}
		string getSickness() const{
			return sickness;
		}
		string getDoctorInCharge() const{
			return docIncharge;
		}
};
void getDataPatient(Patient p[], int const size){
    string name, ic;
    int age = 0;
    string sickness,doc;
    int i = 0;

    ifstream getdata("Patient.txt");
    char del;
    if(!getdata){
        cout << "Error in open File Patient.txt (check the path)\n";
        exit(0);
    }
    while(getline(getdata, ic,',')){

        getline(getdata, name,',');
        getdata >> age;
        //getdata >> del; // remove comma after age
        getline(getdata >> del, doc, ',');
        getline(getdata, sickness);
        p[i] = Patient(ic, name, age, sickness, doc);
        i++;
        
    }
}

void getDataDoc(Doctor d[], int size)
{
    string name, id;
    int age = 0;
    string position,department;
    int i = 0;

    ifstream getdata("Doctor.txt");
    char del;
    if(!getdata){
        cout << "Error in open File Doctor.txt (check the path)\n";
        exit(0);
    }
    while(getline(getdata, id,',')){

        getline(getdata, name,',');
        getdata >> age;
        //getdata >> del; // remove comma after age
        getline(getdata >> del, position, ',');
        getline(getdata, department);
        d[i] = Doctor(id, name, age, position, department);
        i++;
        
    }
}

class Sorter {
public:
    void sortDoctorsByName(Doctor d[], int size, int ascending) {
        for (int i = 1; i < size; i++) {
            Doctor key = d[i];
            int j = i - 1;

            while ((ascending == 1 && j >= 0 && d[j].getName() > key.getName()) ||
                   (ascending == 2 && j >= 0 && d[j].getName() < key.getName())) {
                d[j + 1] = d[j];
                j = j - 1;
            }
            d[j + 1] = key;
        }
    }

    void sortDoctorsByAge(Doctor d[], int size, int ascending) {
        for (int i = 1; i < size; i++) {
            Doctor key = d[i];
            int j = i - 1;

            while ((ascending == 1 && j >= 0 && d[j].getAge() > key.getAge()) ||
                   (ascending == 2 && j >= 0 && d[j].getAge() < key.getAge())) {
                d[j + 1] = d[j];
                j = j - 1;
            }
            d[j + 1] = key;
        }
    }

    void sortDoctorsByID(Doctor d[], int size, int ascending) {
        for (int i = 1; i < size; i++) {
            Doctor key = d[i];
            int j = i - 1;

            while ((ascending == 1 && j >= 0 && d[j].getID() > key.getID()) ||
                    (ascending == 2 && j >= 0 && d[j].getID() < key.getID())) {
                d[j + 1] = d[j];
                j = j - 1;
            }
            d[j + 1] = key;
        }
    }

    void sortPatientsByName(Patient p[], int size, int ascending) {
        for (int i = 1; i < size; i++) {
            Patient key = p[i];
            int j = i - 1;

            while ((ascending == 1 && j >= 0 && p[j].getName() > key.getName()) ||
                   (ascending == 2 && j >= 0 && p[j].getName() < key.getName())) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            p[j + 1] = key;
        }
    }

    void sortPatientsByAge(Patient p[], int size, int ascending) {
        for (int i = 1; i < size; i++) {
            Patient key = p[i];
            int j = i - 1;

            while ((ascending == 1 && j >= 0 && p[j].getAge() > key.getAge()) ||
                   (ascending == 2 && j >= 0 && p[j].getAge() < key.getAge())) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            p[j + 1] = key;
        }
    }
    
    void sortPatientsByIC(Patient p[], int size, int ascending) {
        for (int i = 1; i < size; i++) {
            Patient key = p[i];
            int j = i - 1;

            while ((ascending == 1 && j >= 0 && p[j].getIC() > key.getIC()) ||
                   (ascending == 2 && j >= 0 && p[j].getIC() < key.getIC())) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            p[j + 1] = key;
        }
    }
    
    void sortPatientsBySickness(Patient p[], int size, int ascending) {
        for (int i = 1; i < size; i++) {
            Patient key = p[i];
            int j = i - 1;

            while ((ascending == 1 && j >= 0 && p[j].getSickness() > key.getSickness()) ||
                   (ascending == 2 && j >= 0 && p[j].getSickness() < key.getSickness())) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            p[j + 1] = key;
        }
    }
    
    void sortPatientsByDoctorInCharge(Patient p[], int size, int ascending) {
        for (int i = 1; i < size; i++) {
            Patient key = p[i];
            int j = i - 1;

            while ((ascending == 1 && j >= 0 && p[j].getDoctorInCharge() > key.getDoctorInCharge()) ||
                   (ascending == 2 && j >= 0 && p[j].getDoctorInCharge() < key.getDoctorInCharge())) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            p[j + 1] = key;
        }
    }
};

int searchNamePatient(Patient p[], string search_key, int size){
    int idx;
    for (int i = 0; i < size; i++){
        cout << "fdsfsd\n";
        if ( search_key == p[i].getName()){
            idx = i;
            cout << "index: " << idx << "\n";
            return idx;
        }
    }
    return -1;
}

int searchNameDoctor(Doctor p[], string search_key, int size){
    int idx;
    for (int i = 0; i < size; i++){
        if ( search_key == p[i].getName()){
            idx = i;
            return idx;
        }
    }
    return -1;
}

int searchICPatient(Patient p[], string search_key, int size){

    int idx;
    for (int i = 0; i < size; i++){
        if ( search_key == p[i].getIC()){
            idx = i;
            return idx;
        }
    }
    return -1;
}

int searchIDDoctor(Doctor p[], string search_key, int size){
    int idx;
    for (int i = 0; i < size; i++){
        if ( search_key == p[i].getID()){
            idx = i;
            return idx;
        }
    }
    return -1;
}

int main(){
    const int size = 5;
    Patient pateint[size];
    Doctor doctor[size];

    // input from file
    getDataPatient(pateint, size);
    getDataDoc(doctor, size);

    Sorter sort;


    int processType;
    cout << "\n<<< Process Type >>>\n";
    cout << "[1] Sorting\n";
    cout << "[2] Searching\n";
    cout << "Enter user type: ";
    cin >> processType;

    int userType;
    cout << "\n<<< Sorting Process >>>\n";
    cout << "[1] Patients\n";
    cout << "[2] Doctors\n";
    cout << "Enter user type: ";
    cin >> userType;
    if(processType == 1){
	    int sortingOption;
	
	    cout << "Enter sorting option:\n";
	    cout << "[1] By name\n";
	    cout << "[2] By age\n";
	    cout << "[3] By IC/ID number\n";
	    cout << "[4] By sickness (Patients only)\n";
	    cout << "[5] By doctor in charge (Patients only)\n";
	    cout << "Enter sorting option: ";
	    cin >> sortingOption;
	
	    int ascending;
	    cout << "Sort in\n";
	    cout << "[1] Ascending\n";
	    cout << "[2] Descending\n";
	    cout << "Enter sorting order: ";
	    cin >> ascending;
	
	    if (userType == 1) { // Patients
	        switch (sortingOption) {
	            case 1:
	                sort.sortPatientsByName(pateint, size, ascending );
	                break;
	            case 2:
	                sort.sortPatientsByAge(pateint, size, ascending );
	                break;
	            case 3:
	                sort.sortPatientsByIC(pateint, size, ascending );
	                break;
	            case 4:
	                sort.sortPatientsBySickness(pateint, size, ascending );
	                break;
	            case 5:
	                sort.sortPatientsByDoctorInCharge(pateint, size, ascending );
	                break;
	            default:
	                cout << "Invalid option\n";
	                break;
	        }
	    } else if (userType == 2) { // Doctors
	        switch (sortingOption) {
	            case 1:
	                sort.sortDoctorsByName(doctor, size, ascending );
	                break;
	            case 2:
	                sort.sortDoctorsByAge(doctor, size, ascending );
	                break;
		    case 3:
	                sort.sortDoctorsByID(doctor, size, ascending );
	                break;
	            default:
	                cout << "Invalid option\n";
	                break;
	        }
	    } else {
	        cout << "Invalid user type\n";
	    }
	
	    // Display the sorted list
	    cout << "Sorted Information\n\n";
	    if (userType == 1) { // Patients
	        for (int i = 0; i < size; i++) {
	            cout << "Patient " << i + 1 << "\n";
	            pateint[i].display();
	        }
	    } else if (userType == 2) { // Doctors
	        for (int i = 0; i < size; i++) {
	            cout << "Doctor " << i + 1 << "\n";
	            doctor[i].display();
	        }
	    }
    }
	else {
        int searchingOption, ascending = 1;
        string search;
        int found;

        cout << "\nEnter searching option:\n";
        cout << "[1] By name\n";
        cout << "[2] By id\n";
        cout << "Enter searching option: ";
        cin >> searchingOption;

        if(searchingOption == 1){
            cout << "Enter Name: ";
            cin >> search;
            if(userType == 1){
                sort.sortPatientsByName(pateint, size, ascending);
                found = searchNamePatient(pateint, search, size);
            }
            else{
                sort.sortDoctorsByName(doctor, size, ascending);
                found = searchNameDoctor(doctor, search, size);
            }
        }
        else if (searchingOption == 2){
            cout << "Enter IC/ID: ";
            cin >> search;
            if(userType == 1){
                sort.sortPatientsByIC(pateint, size, ascending);
                found = searchICPatient(pateint, search, size);
            }
            else{
                sort.sortDoctorsByID(doctor, size, ascending);
                found = searchIDDoctor(doctor, search, size);
            }
        }
        if(found == -1)
            cout << "\nData cannot be found\n";
        else{
        cout << endl << "Found index : " << found << endl;
        pateint[found].display();
        }
    }
    
    return 0;
}
