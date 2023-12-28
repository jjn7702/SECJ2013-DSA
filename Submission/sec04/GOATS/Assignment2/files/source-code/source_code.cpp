#include <iostream>

#include <string>

#include <fstream>

using namespace std;

class Doctor {
    private: string idDoctor;
    string nameDoctor;
    int ageDoctor;
    string positionDoctor;
    string departmentDoctor;
    Doctor* next;
    Doctor* prev;

public:
    Doctor(string i = "", string n = "", int a = 0, string p = "", string dept = "")
    {
        idDoctor = i;
        nameDoctor = n;
        ageDoctor = a;
        positionDoctor = p;
        departmentDoctor = dept;
        next = NULL;
        prev = NULL;
    }
    void display() {
        cout << "Id: " << idDoctor <<
            "\nName: " << nameDoctor <<
            "\nAge: " << ageDoctor <<
            "\nPosition: " << positionDoctor <<
            "\nDepartment: " << departmentDoctor << "\n\n";
    }
    string getIDDoctor() const {
        return idDoctor;
    }
    string getNameDoctor() const {
        return nameDoctor;
    }
    int getAgeDoctor() const {
        return ageDoctor;
    }
    // Linked list
    Doctor* getNext(){
        return next;
    }
    void setNext(Doctor* newNext){
        next = newNext;
    }
    Doctor* getPrev(){
        return prev;
    }
    void setPrev(Doctor* newPrev){
        prev = newPrev;
    }
};

class Patient {
    private: string icPatient;
    string namePatient;
    int agePatient;
    string sicknessPatient;
    string docInchargePatient; // maybe change
    Patient *next;
    Patient *prev;

public:
    Patient(string icNum = "", string n = "", int a = 0, string sick = "", string doc = "")
    {
        icPatient = icNum;
        namePatient = n;
        agePatient = a;
        sicknessPatient = sick;
        docInchargePatient = doc;
        next = NULL;
        prev = NULL;
    }
    void display() { // maybe will change to more better view
        cout << "Ic:" << icPatient <<
            "\nName: " << namePatient <<
            "\nAge: " << agePatient <<
            "\nSickness: " << sicknessPatient <<
            "\nDoctor In-Charge: " << docInchargePatient << "\n\n";
    }
    string getICPatient() const {
        return icPatient;
    }
    string getNamePatient() const {
        return namePatient;
    }
    int getAgePatient() const {
        return agePatient;
    }
    string getSickness() const {
        return sicknessPatient;
    }
    string getDoctorInCharge() const {
        return docInchargePatient;
    }
    // Linked list
    Patient* getNext(){
        return next;
    }
    void setNext(Patient* newNext){
        next = newNext;
    }
    Patient* getPrev(){
        return prev;
    }
    void setPrev(Patient* newPrev){
        prev = newPrev;
    }
};

class List{
    private:
        Patient *p_head;
        Doctor *d_head;
    public:
        List(){
            d_head = NULL;
            p_head = NULL;
        }
        // add more function here
        bool isEmpty(){
            return p_head == NULL;
        }
        void insertFront(string icNum, string n, int a, string sick, string doc ){
            Patient *newNode = new Patient(icNum, n, a, sick, doc);
            if(isEmpty())
                p_head = newNode;
            else{
                newNode->setNext(p_head);
                p_head->setPrev(newNode);
                p_head = newNode;
            }
        }
        
        void findNode(string searchKey) {
        Patient *tempPatient = p_head;
        Doctor *tempDoctor = d_head;
		
		//patients
        while (tempPatient != NULL) {
            if (tempPatient->getNamePatient() == searchKey || tempPatient->getICPatient() == searchKey) {
                cout << "Patient found:\n";
                tempPatient->display();
                return;
            }
            tempPatient = tempPatient->getNext();
        }
        
        //doctors
        while (tempDoctor != NULL) {
            if (tempDoctor->getNameDoctor() == searchKey || tempDoctor->getIDDoctor() == searchKey) {
                cout << "Doctor found:\n";
                tempDoctor->display();
                return;
            }
            tempDoctor = tempDoctor->getNext();
        }
        
        cout << "Node with key '" << searchKey << "' not found.\n";
    	}

        void display(){
            Patient *temp = p_head;
            if(isEmpty()){
                cout << "No node in the list\n";
                return;
            }
            cout << "\n<< Display all node >>\n";
            cout << "--------------------------------\n";
            while (temp != NULL) {
            temp->display();
            temp = temp->getNext();
            }
        }
};

void getDataPatient(Patient p[], int
    const size) {
    string name, ic;
    int age = 0;
    string sickness, doc;
    int i = 0;

    ifstream getdata("\\Users\\haziq\\Desktop\\SECJ2013\\Project\\Asg 1\\Patient.txt");
    char del;
    if (!getdata) {
        cout << "Error in open File Patient.txt (check the path)\n";
        exit(0);
    }
    while (getline(getdata, ic, ',')) {

        getline(getdata, name, ',');
        getdata >> age;
        //getdata >> del; // remove comma after age
        getline(getdata >> del, doc, ',');
        getline(getdata, sickness);
        p[i] = Patient(ic, name, age, sickness, doc);
        i++;

    }
}

void getDataDoc(Doctor d[], int size) {
    string name, id;
    int age = 0;
    string position, department;
    int i = 0;

    ifstream getdata("\\Users\\haziq\\Desktop\\SECJ2013\\Project\\Asg 1\\Doctor.txt");
    char del;
    if (!getdata) {
        cout << "Error in open File Doctor.txt (check the path)\n";
        exit(0);
    }
    while (getline(getdata, id, ',')) {

        getline(getdata, name, ',');
        getdata >> age;
        //getdata >> del; // remove comma after age
        getline(getdata >> del, position, ',');
        getline(getdata, department);
        d[i] = Doctor(id, name, age, position, department);
        i++;

    }
}

class Sorting {
    public:

        void sortDoctorsByName(Doctor d[], int size, int menaik) {
            for (int i = 1; i < size; i++) {
                Doctor key = d[i];
                int j = i - 1;

                while (menaik == 1 && j >= 0 && d[j].getNameDoctor() > key.getNameDoctor()) {
                    d[j + 1] = d[j];
                    j = j - 1;
                }
                while (menaik == 2 && j >= 0 && d[j].getNameDoctor() < key.getNameDoctor()) {
                    d[j + 1] = d[j];
                    j = j - 1;
                }
                d[j + 1] = key;
            }
        }

    void sortDoctorsByAge(Doctor d[], int size, int menaik) {
        for (int i = 1; i < size; i++) {
            Doctor key = d[i];
            int j = i - 1;

            while (menaik == 1 && j >= 0 && d[j].getAgeDoctor() > key.getAgeDoctor()) {
                d[j + 1] = d[j];
                j = j - 1;
            }
            while (menaik == 2 && j >= 0 && d[j].getAgeDoctor() < key.getAgeDoctor()) {
                d[j + 1] = d[j];
                j = j - 1;
            }
            d[j + 1] = key;
        }
    }

    void sortDoctorsByID(Doctor d[], int size, int menaik) {
        for (int i = 1; i < size; i++) {
            Doctor key = d[i];
            int j = i - 1;

            while (menaik == 1 && j >= 0 && d[j].getIDDoctor() > key.getIDDoctor()) {
                d[j + 1] = d[j];
                j = j - 1;
            }
            while (menaik == 2 && j >= 0 && d[j].getIDDoctor() < key.getIDDoctor()) {
                d[j + 1] = d[j];
                j = j - 1;
            }
            d[j + 1] = key;
        }
    }

    void sortPatientsByName(Patient p[], int size, int menaik) {
        for (int i = 1; i < size; i++) {
            Patient key = p[i];
            int j = i - 1;

            while (menaik == 1 && j >= 0 && p[j].getNamePatient() > key.getNamePatient()) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            while (menaik == 2 && j >= 0 && p[j].getNamePatient() < key.getNamePatient()) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            p[j + 1] = key;
        }
    }

    void sortPatientsByAge(Patient p[], int size, int menaik) {
        for (int i = 1; i < size; i++) {
            Patient key = p[i];
            int j = i - 1;

            while (menaik == 1 && j >= 0 && p[j].getAgePatient() > key.getAgePatient()) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            while (menaik == 2 && j >= 0 && p[j].getAgePatient() < key.getAgePatient()) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            p[j + 1] = key;
        }
    }

    void sortPatientsByIC(Patient p[], int size, int menaik) {
        for (int i = 1; i < size; i++) {
            Patient key = p[i];
            int j = i - 1;

            while (menaik == 1 && j >= 0 && p[j].getICPatient() > key.getICPatient()) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            while (menaik == 2 && j >= 0 && p[j].getICPatient() < key.getICPatient()) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            p[j + 1] = key;
        }
    }

    void sortPatientsBySickness(Patient p[], int size, int menaik) {
        for (int i = 1; i < size; i++) {
            Patient key = p[i];
            int j = i - 1;

            while (menaik == 1 && j >= 0 && p[j].getSickness() > key.getSickness()) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            while (menaik == 2 && j >= 0 && p[j].getSickness() < key.getSickness()) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            p[j + 1] = key;
        }
    }

    void sortPatientsByDoctorInCharge(Patient p[], int size, int menaik) {
        for (int i = 1; i < size; i++) {
            Patient key = p[i];
            int j = i - 1;

            while (menaik == 1 && j >= 0 && p[j].getDoctorInCharge() > key.getDoctorInCharge()) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            while (menaik == 2 && j >= 0 && p[j].getDoctorInCharge() < key.getDoctorInCharge()) {
                p[j + 1] = p[j];
                j = j - 1;
            }
            p[j + 1] = key;
        }
    }
};

int searchNamePatient(Patient p[], string search_key, int size) {
    int idx;
    for (int i = 0; i < size; i++) {
        if (search_key == p[i].getNamePatient()) {
            idx = i;
            cout << "index: " << idx << "\n";
            return idx;
        }
    }
    return -1;
}

int searchNameDoctor(Doctor p[], string search_key, int size) {
    int idx;
    for (int i = 0; i < size; i++) {
        if (search_key == p[i].getNameDoctor()) {
            idx = i;
            return idx;
        }
    }
    return -1;
}

int searchICPatient(Patient p[], string search_key, int size) {

    int idx;
    for (int i = 0; i < size; i++) {
        if (search_key == p[i].getICPatient()) {
            idx = i;
            return idx;
        }
    }
    return -1;
}

int searchIDDoctor(Doctor p[], string search_key, int size) {
    int idx;
    for (int i = 0; i < size; i++) {
        if (search_key == p[i].getIDDoctor()) {
            idx = i;
            return idx;
        }
    }
    return -1;
}

void assigment1(){
    const int size = 5;
    Patient pateint[size];
    Doctor doctor[size];

    // input from file
    getDataPatient(pateint, size);
    getDataDoc(doctor, size);

    Sorting sort;

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
    if (processType == 1) {
        int sortingOption;

        cout << "Enter sorting option:\n";
        cout << "[1] By name\n";
        cout << "[2] By age\n";
        cout << "[3] By IC/ID number\n";
        cout << "[4] By sickness (Patients only)\n";
        cout << "[5] By doctor in charge (Patients only)\n";
        cout << "Enter sorting option: ";
        cin >> sortingOption;

        int menaik;
        cout << "Sort in\n";
        cout << "[1] Ascending\n";
        cout << "[2] Descending\n";
        cout << "Enter sorting order: ";
        cin >> menaik;

        if (userType == 1) { // Patients
            switch (sortingOption) {
            case 1:
                sort.sortPatientsByName(pateint, size, menaik);
                break;
            case 2:
                sort.sortPatientsByAge(pateint, size, menaik);
                break;
            case 3:
                sort.sortPatientsByIC(pateint, size, menaik);
                break;
            case 4:
                sort.sortPatientsBySickness(pateint, size, menaik);
                break;
            case 5:
                sort.sortPatientsByDoctorInCharge(pateint, size, menaik);
                break;
            default:
                cout << "Invalid option\n";
                break;
            }
        } else if (userType == 2) { // Doctors
            switch (sortingOption) {
            case 1:
                sort.sortDoctorsByName(doctor, size, menaik);
                break;
            case 2:
                sort.sortDoctorsByAge(doctor, size, menaik);
                break;
            case 3:
                sort.sortDoctorsByID(doctor, size, menaik);
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
    } else {
        int searchingOption, menaik = 1;
        string search;
        int found;

        cout << "\nEnter searching option:\n";
        cout << "[1] By name\n";
        cout << "[2] By id\n";
        cout << "Enter searching option: ";
        cin >> searchingOption;

        if (searchingOption == 1) {
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, search);
            
            if (userType == 1) {
                sort.sortPatientsByName(pateint, size, menaik);
                found = searchNamePatient(pateint, search, size);
            } else {
                sort.sortDoctorsByName(doctor, size, menaik);
                found = searchNameDoctor(doctor, search, size);
            }
        } else if (searchingOption == 2) {
            cout << "Enter IC/ID: ";
            cin >> search;
            if (userType == 1) {
                sort.sortPatientsByIC(pateint, size, menaik);
                found = searchICPatient(pateint, search, size);
            } else {
                sort.sortDoctorsByID(doctor, size, menaik);
                found = searchIDDoctor(doctor, search, size);
            }
        }
        if (found == -1)
            cout << "\nData cannot be found\n";
        else {
            cout << endl << "Found index : " << found << endl;
            pateint[found].display();
        }
    }
}

int start(){
    int choice;
    cout << "<< Choose Program >>\n"
         << "1. Assignment 1\n"
         << "2. Assignment 2\n"
         << "3. End program\n"
         << "Your Choice: ";
    cin >> choice;
    return choice;
}

int main() {
    int choice = start();   // Choose program 
    
    if(choice == 1)
        assigment1();
    else if (choice == 2)
        cout << "Assignement 2\n";
    else if (choice = 3)
        return 0;
    else{
        cout << "Invalid input\n";
        start();
    }

    List node;
    node.display(); // test if node is empty

    // try insert node in from the front
    node.insertFront("888777666", "David", 50, "Arthritis", "Dr. Johnson");
    node.display();

    node.insertFront("88877766s", "avid", 50, "Arthritis", "Dr. Johnson");
    node.display();
    
    //try search node
    node.findNode("88877766s");
    cout << endl;
    node.findNode("David");
    cout << endl;

    return 0;
}
