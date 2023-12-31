#include <iostream>

#include <string>

#include <fstream>

using namespace std;

class Doctor {
    private: 
    string idDoctor;
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
    string getposition(){
        return positionDoctor;
    }
    string getdept(){
        return departmentDoctor;
    }
    void setID(string id) { idDoctor = id; }
    void setname(string name) { nameDoctor = name; }
    void setage(int age) { ageDoctor = age; }
    void setposition(string position) { positionDoctor = position; }
    void setdept(string dept) { departmentDoctor = dept;}

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
    private: 
    string icPatient;
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
    void setIC(string ic) { icPatient = ic; }
    void setname(string name) { namePatient = name; }
    void setage(int age) { agePatient = age; }
    void setsick(string sick) { sicknessPatient = sick; }
    void setdoc(string doc) { docInchargePatient = doc; }

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
        void addnewUser(int user, int add){
            string icNum, name, sp, d; // sp = sickness / position && d = docincharge / department
            int age;

            // get input from user
            cout << "\n<< New User information >>\n"
                 << "IC : ";
            cin >> icNum;
            cout << "Name : ";
            cin.ignore();
            getline(cin, name);
            cout << "Age : ";
            cin >> age;
            if (user == 1){ // patient
                cin.ignore();
                cout << "Sickness : ";
                getline(cin, sp);
                cout << "Doctor In-Charge : ";
                getline(cin, d);
            }
            else {  // Doctor
                cout << "Position : ";
                cin.ignore();
                getline(cin, sp);
                cout << "Department : ";
                cin.ignore();
                getline(cin, d);
            }
            switch (add)
            {
            case 1:
                insertFront(icNum, name, age, sp, d, user);
                break;
            case 2:
                int position;
                cout << "Which position to insert :";
                cin >> position;
                insertMiddle(icNum, name, age, sp, d, position, user);
                break;
            case 3:
                insertBack(icNum, name, age, sp, d, user);
                break;
            default:
                cout << "Error: Invalid Adding function option\n";
                break;
            }
        }

        bool isEmpty(int user){
            if (user == 1)
                return p_head == NULL;
            else    
                return d_head == NULL;
        }

        void insertFront(string icNum, string n, int a, string sick, string doc, int user ){
            if(user  == 1){
                Patient *newNode = new Patient(icNum, n, a, sick, doc);
                if(isEmpty(user))
                    p_head = newNode;
                else{
                    newNode->setNext(p_head);
                    p_head->setPrev(newNode);
                    p_head = newNode;
                }
            }
            else if(user == 2){
                Doctor *newNode = new Doctor(icNum, n, a, sick, doc);
                if(isEmpty(user))
                    d_head = newNode;
                else{
                    newNode->setNext(d_head);
                    d_head->setPrev(newNode);
                    d_head = newNode;
                }
            }
        }

        void insertBack(string icNum, string n, int a, string sick, string doc, int user){
            
            if (user == 1){
                Patient *newNode = new Patient(icNum, n, a, sick, doc);
                Patient *temp = p_head;
                if(isEmpty(user))
                    p_head = newNode;
                else{
                    while (temp->getNext() != NULL){
                        temp = temp->getNext();
                    }
                    temp->setNext(newNode);
                    newNode->setPrev(temp);
                }
            }
            else{
                Doctor *newDoctor = new Doctor(icNum, n, a, sick, doc);
                Doctor *temp = d_head;

                if(isEmpty(user))
                    d_head = newDoctor;
                else{
                    while (temp->getNext() != NULL){
                        temp = temp->getNext();
                    }
                    temp->setNext(newDoctor);
                    newDoctor->setPrev(temp);
                }
            }
        }

        void insertMiddle(string icNum, string n, int a, string sick, string doc, int position, int user ){
            int count = 1;

            if(user == 1){
                Patient *newNode = new Patient(icNum, n, a, sick, doc);
                Patient *temp = p_head;

                if(isEmpty(user))
                    p_head = newNode;
                else{
                    if(position == 1){          // first position is insert from front
                        insertFront(icNum, n, a, sick, doc, user);
                        return;
                    }
                    while (temp->getNext() != NULL && count < position){
                        temp = temp->getNext();
                        count++;
                    }
                    cout << "count : " << count << "\n";
                    if(count+1 < position && temp->getNext() == NULL){  // check position > number of node in link
                        cout << "Invalid position\n";
                        return;
                    }
                    else if(count+1  == position && temp->getNext() == NULL){ // last position is insert from back
                        cout << "Insert back\n";
                        insertBack(icNum, n, a, sick, doc, user);
                        return;
                    }
                    else{
                        newNode->setNext(temp);
                        newNode->setPrev(temp->getPrev());
                        temp->getPrev()->setNext(newNode);
                        temp->setPrev(newNode);
                    }
                }
            }
            else if(user == 2){
                Doctor *newNode = new Doctor(icNum, n, a, sick, doc);
                Doctor *temp = d_head;

                if(isEmpty(user))
                    d_head = newNode;
                else{
                    if(position == 1){          // first position is insert from front
                        insertFront(icNum, n, a, sick, doc, user);
                        return;
                    }
                    while (temp->getNext() != NULL && count < position){
                        temp = temp->getNext();
                        count++;
                    }
                    cout << "count : " << count << "\n";
                    if(count+1 < position && temp->getNext() == NULL){  // check position > number of node in link
                        cout << "Invalid position\n";
                        return;
                    }
                    else if(count+1  == position && temp->getNext() == NULL){ // last position is insert from back
                        cout << "Insert back\n";
                        insertBack(icNum, n, a, sick, doc, user);
                        return;
                    }
                    else{
                        newNode->setNext(temp);
                        newNode->setPrev(temp->getPrev());
                        temp->getPrev()->setNext(newNode);
                        temp->setPrev(newNode);
                    }
                }
            }
        }

        int deleteNode(string x, int y) {
        //for Patient
        if (y == 1) {
            Patient* current = p_head;
            Patient* previous = NULL;

            while (current != NULL && current->getICPatient() != x) {
                previous = current;
                current = current->getNext();
            }
            
            // Node not found
            if (current == NULL) return 0;  

            if (previous == NULL) {
                p_head = current->getNext();
            } 
            
            else {
                previous->setNext(current->getNext());
                if (current->getNext() != NULL) {
                    current->getNext()->setPrev(previous);
                }
            }

            delete current;
            return 1;
        
        }
        //for Doctor
        else if (y == 2) {
            Doctor* current = d_head;
            Doctor* previous = NULL;

            while (current != NULL && current->getIDDoctor() != x) {
                previous = current;
                current = current->getNext();
            }

            if (current == NULL) return 0; 

            if (previous == NULL) {
                d_head = current->getNext();
            } 
            
            else {
                previous->setNext(current->getNext());
                if (current->getNext() != NULL) {
                    current->getNext()->setPrev(previous);
                }
            }

            delete current;
            return 1;
        }
        //when y invalid
        return 0;  
        }   
        
        
        void findNode(string searchKey, int user) {
		    if (user == 1) {
		        Patient *tempPatient = p_head;
		        while (tempPatient != NULL) {
		            if (tempPatient->getNamePatient() == searchKey || tempPatient->getICPatient() == searchKey) {
		                cout << "\nPatient found:\n";
		                tempPatient->display();
		                return;
		            }
		            tempPatient = tempPatient->getNext();
		        }
		    } else if (user == 2) {
		        Doctor *tempDoctor = d_head;
		        while (tempDoctor != NULL) {
		            if (tempDoctor->getNameDoctor() == searchKey || tempDoctor->getIDDoctor() == searchKey) {
		                cout << "\nDoctor found:\n";
		                tempDoctor->display();
		                return;
		            }
		            tempDoctor = tempDoctor->getNext();
		        }
		    } else {
		        cout << "Invalid user type\n";
		    }
		    cout << "Node with key '" << searchKey << "' not found.\n";
		}

        void displayAll(int user){
            
            if(isEmpty(user)){
                cout << endl << "No node in the list\n";
                return;
            }
            if (user == 1){
                Patient *temp = p_head;
                cout << "\n<< Display Patients >>\n";
                cout << "--------------------------------\n";
                while (temp != NULL) {
                    temp->display();
                    temp = temp->getNext();
                }
            }
            else if(user == 2){
                Doctor *temp = d_head;
                cout << "\n<< Display Doctors >>\n";
                cout << "--------------------------------\n";
                while (temp != NULL) {
                    temp->display();
                    temp = temp->getNext();
                }
            }
        }

        void displayNode(int user,string keyIC){
            
            if(isEmpty(user)){
                cout << endl << "No node in the list\n";
                return;
            }
            if (user == 1){
                Patient *temp = p_head;
                cout << "\n<< Display selected node >>\n";
                cout << "--------------------------------\n";
                while (temp != NULL) {
                    if (temp->getICPatient() == keyIC){
                        temp->display();
                        return;
                    }
                    temp = temp->getNext();
                }
            }
            else if(user == 2){
                Doctor *temp = d_head;
                cout << "\n<< Display all node >>\n";
                cout << "--------------------------------\n";
                while (temp != NULL) {
                    if (temp->getIDDoctor() == keyIC){
                        temp->display();
                        return;
                    }
                    temp = temp->getNext();
                }
            }
        }


        void swap(Patient* &large, Patient* &small){
            string icPatient = small->getICPatient();
            string namePatient = small->getNamePatient();
            int agePatient = small->getAgePatient();
            string sicknessPatient = small->getSickness() ;
            string docInchargePatient = small->getDoctorInCharge();

            small->setIC(large->getICPatient());
            small->setname(large->getNamePatient());
            small->setage(large->getAgePatient());
            small->setsick(large->getSickness());
            small->setdoc(large->getDoctorInCharge());

            large->setIC(icPatient);
            large->setname(namePatient);
            large->setage(agePatient);
            large->setsick(sicknessPatient);
            large->setdoc(docInchargePatient);

        }
        void swapDoctor(Doctor* &large, Doctor* &small){
            string icPatient = small->getIDDoctor();
            string namePatient = small->getNameDoctor();
            int agePatient = small->getAgeDoctor();
            string position = small->getposition();
            string department = small->getdept();

            small->setID(large->getIDDoctor());
            small->setname(large->getNameDoctor());
            small->setage(large->getAgeDoctor());
            small->setposition(large->getposition());
            small->setdept(large->getdept());

            large->setID(icPatient);
            large->setname(namePatient);
            large->setage(agePatient);
            large->setposition(position);
            large->setdept(department);

        }

        void sorting(int type, int user){
            if (isEmpty(user)) {
                // List is empty or has only one element, no need to sort
                cout << "Sorting Error : List is Empty\n";
                return;
            }

            bool swapped;
            do {
                swapped = false;
                if(user == 1){
                    Patient* current = p_head;
                    while (current->getNext() != nullptr) {
                        if (type == 1){
                            if (current->getICPatient() > current->getNext()->getICPatient()) {
                                Patient *temp;
                                temp = current->getNext();
                                swap(current, temp);
                                swapped = true;
                            }
                        }
                        else {
                            if (current->getNamePatient() > current->getNext()->getNamePatient()) {
                                Patient *temp;
                                temp = current->getNext();
                                swap(current, temp);
                                swapped = true;
                            }
                        }
                        current = current->getNext();
                    }
                }
                else if(user == 2){
                    Doctor* current = d_head;
                    while (current->getNext() != nullptr) {
                        if (type == 1){
                            if (current->getIDDoctor() > current->getNext()->getIDDoctor()) {
                                Doctor *temp;
                                temp = current->getNext();
                                swapDoctor(current, temp);
                                swapped = true;
                            }
                        }
                        else {
                            if (current->getNameDoctor() > current->getNext()->getNameDoctor()) {
                                Doctor *temp;
                                temp = current->getNext();
                                swapDoctor(current, temp);
                                swapped = true;
                            }
                        }
                        current = current->getNext();
                    }
                }
                
                
            } while (swapped);
        }
        
        void import(){
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
                insertFront(ic, name, age, sickness, doc, 1);
                i++;

            }
            getdata.close();

            getdata.open("\\Users\\haziq\\Desktop\\SECJ2013\\Project\\Asg 1\\Doctor.txt");
            del;
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
                insertFront(ic, name, age, sickness, doc, 2);
                i++;
            }
            getdata.close();
        }
};

void getDataPatient(Patient p[], int const size) {
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
    getdata.close();
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
    getdata.close();
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

void assignment1(){
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

void assignment2 (List &node, int user){ // user  = patient/ doctor
    int option;
    string searchKey;
    bool loop = 1;

    while (loop){
        if (user == 1){
            cout << "\n<< Linked list operation >>\n"
            << "1. Add new Patient\n"
            << "2. Delete Patient\n"
            << "3. Find Patient\n"
            << "4. Display Patients\n"
            << "5. Sorting List\n"
            << "6. Back\n"
            << "Choose one of the function : ";
        
        }

        else if (user == 2){
            cout << "\n<< Linked list operation >>\n"
            << "1. Add new Doctor\n"
            << "2. Delete Doctor\n"
            << "3. Find Doctor\n"
            << "4. Display Doctors\n"
            << "5. Sorting List\n"
            << "6. Back\n"
            << "Choose one of the function : ";
        }
        
        cin >> option;
        switch (option)
        {
        case 1:
            int add;
            cout << "\n<< Adding Function >>\n"
                << "1. Add from Front\n"
                << "2. Add from Middle (specific position)\n"
                << "3. Add from Back\n"
                << "Choose where do you want to add: ";
            cin >> add;
            node.addnewUser(user, add);
            break;
        case 2:
            cout << "\n<< Delete Node Function >>\n"
                << "Enter IC : ";
            cin >> searchKey;
            cout << endl << "Node that was deleted :" << endl;
            node.displayNode(user,searchKey);
            node.deleteNode(searchKey,user);
            // add menu delete
            break;
        case 3:
                cout << "\nEnter the name or ID to find: ";
                cin >> searchKey;
                node.findNode(searchKey, user);
                break;
            break;
        case 4:
            node.displayAll(user);
            break;
        case 5:
            int type;
            cout << "\n<< Sorting menu >> \n"
                 << "1. Sort by IC/ID\n"
                 << "2. Sort by Name\n"
                 << "Choose your sorting key: ";

            cin >> type;
            node.sorting(type,user);
            node.displayAll(user);
            break;
        case 6 :
            return;
        default:
            cout << "\nError : Invalid linked list operation option\n";
            assignment2(node, user);
        }
    }
}

int main() {
    List node;
	//test function to find node later
	// node.insertFront("11","Sarah",40,"Cardiologist","Cardiology", 2);
	// node.insertFront("44","James",38,"Pediatrician","Pediatrics", 2);
	// node.insertFront("77","Linda",55,"Orthopedic Surgeon","Orthopedics", 2);
    // node.insertFront("888777666","David",50, "Arthritis", "Dr. Johnson", 1);
	// node.insertFront("987654321","Bob",45, "Diabetes", "Dr. Jones", 1);
	// node.insertFront("333222111","Emily",60, "Cardiovascular Disease", "Dr. Wilson", 1);
    node.import();
    node.displayAll(2);
    node.displayAll(1);

    int choice = start();   // Choose program
    int user; // patient or doctor
	
    while (choice != 3){
        if(choice == 1){
            assignment1();
        }
        else if (choice == 2){
            repeat:
            cout << "\n<< Assignment 2 >> \n"
            << "1. Patient\n"
            << "2. Doctor\n"
            << "3. End program\n"
            << "Choose one of the option: ";
            cin >> user;
            if(user == 3){
                return 0;
            }
            else if(user != 1 && user != 2){
                goto repeat;
            }
            assignment2(node, user);
        }
        else if (choice == 3)
            return 0;
        else{
            cout << "Invalid input\n";
            start();
        }
    }

    return 0;
}
