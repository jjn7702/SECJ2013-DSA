//Testing
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Structure to represent patient records
struct Patient {
    string name;
    int age;
    string disease;
};

// Function to display main menu
void displayMenu() {
    cout << "Chronic Disease Management System Menu" << endl;
    cout << "1. Add Patient" << endl;
    cout << "2. Display Patients" << endl;
    cout << "3. Search Patient by Name" << endl;
    cout << "4. Sort Patients by Name" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to display search menu
void dispSearchMenu() {
    cout << "Choose key to search: " << endl;
    cout << "1. Name" << endl;
    cout << "2. Age" << endl;
    cout << "3. Disease" << endl;
    cout << "Enter your choice: ";
}

// Function to display patient details
void displayPatient(const Patient& p) {
    cout << "Name: " << p.name << ", Age: " << p.age << ", Disease: " << p.disease << endl;
}

// Function to perform sorting based on patient names
bool sortByPatientName(const Patient& p1, const Patient& p2) {
    return p1.name < p2.name;
}

// Function to perform searching based on patient keys
bool searchPatient (const Patient& p, int opt, string searchKey) {
     switch (opt) {
         case 1: return p.name == searchKey;
         case 2: return p.age == stoi(searchKey);
         case 3: return p.disease == searchKey;
         default: return false;
    }
}

int main() {
    vector<Patient> patients;
    
    // Sample data
    patients.push_back({"John", 45, "Diabetes"});
    patients.push_back({"Linda", 30, "Hypertension"});
    patients.push_back({"David", 55, "Heart Disease"});
    
    int choice, searchOpt;
    string searchKey;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        cout << endl;

        
        switch (choice) {
            case 1: {
                Patient newPatient;
                cout << "Enter patient name: ";
                getline(cin, newPatient.name); 
                cout << "Enter patient age: ";
                cin >> newPatient.age;
                cout << "Enter patient disease: ";
                cin >> newPatient.disease;
                patients.push_back(newPatient);
                cout << "Patient added successfully." << endl << endl;
                break;
            }
            case 2: {
                cout << "Patient Details:" << endl;
                for (const Patient& p : patients) {
                    displayPatient(p);
                }
                cout << endl;
                break;
            }
            case 3: {
                dispSearchMenu();
                cin >> searchOpt;
                cin.ignore();
                cout << "Enter your searching value: ";
                getline(cin, searchKey);

                auto it = find_if(patients.begin(), patients.end(), [&](const Patient& p) {
                    return searchPatient(p, searchOpt, searchKey);
                });

                if (it != patients.end()) {
                    cout << "Patient found:" << endl;
                    displayPatient(*it);
                } else {
                    cout << "Patient not found." << endl;
                }
                cout << endl;
                break;
            }
            case 4: {
                sort(patients.begin(), patients.end(), sortByPatientName);
                cout << "Patients sorted by name." << endl << endl;
                break;
            }
            case 0: {
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}

