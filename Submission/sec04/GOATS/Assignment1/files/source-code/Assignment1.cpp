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

int main(){
    const int size = 5;
    Patient pateint[size];
    Doctor doctor[size];

    // input from file
    getDataPatient(pateint, size);
    getDataDoc(doctor, size);

    // Display
    cout << "Patient Information\n\n";
    for (int i = 0; i < size; i++){
        cout << "Patient " << i + 1 << "\n";
        pateint[i].display();
        
    }
    cout << "Doctor Information\n\n";
    for (int i = 0; i < size; i++){
        cout << "Doctor " << i + 1 << "\n";
        doctor[i].display();
    }
    // Patient patient1("303","Ali",12,"heat wave");
    // patient1.display();
    return 0;
}
