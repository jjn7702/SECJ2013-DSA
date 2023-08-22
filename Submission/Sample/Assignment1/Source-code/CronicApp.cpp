#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent patient records
struct Patient {
    string name;
    int age;
    string disease;
};

// Function to display patient details
void displayPatient(const Patient& p) {
    cout << "Name: " << p.name << ", Age: " << p.age << ", Disease: " << p.disease << endl;
}

// Function to perform sorting based on patient names
bool sortByPatientName(const Patient& p1, const Patient& p2) {
    return p1.name < p2.name;
}

// Function to perform searching based on patient names
bool searchByPatientName(const Patient& p, const string& searchName) {
    return p.name == searchName;
}

int main() {
    vector<Patient> patients;
    
    // Sample data
    patients.push_back({"John", 45, "Diabetes"});
    patients.push_back({"Linda", 30, "Hypertension"});
    patients.push_back({"David", 55, "Heart Disease"});
    
    int choice;
    string searchName;
    
    do {
        cout << "Chronic Disease Management System Menu" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Display Patients" << endl;
        cout << "3. Search Patient by Name" << endl;
        cout << "4. Sort Patients by Name" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        
        switch (choice) {
            case 1: {
                Patient newPatient;
                cout << "Enter patient name: ";
                cin >> newPatient.name;
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
                cout << "Enter patient name to search: ";
                cin >> searchName;
                auto it = find_if(patients.begin(), patients.end(), [&](const Patient& p) {
                    return searchByPatientName(p, searchName);
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

