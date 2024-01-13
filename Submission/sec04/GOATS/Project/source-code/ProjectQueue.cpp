#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int waitingNumber;  // Added waitingNumber field
    string name;
    string contactInfo;
    string reason;
    Node* next;

    Node(int number, string n, string contact, string r) : waitingNumber(number), name(n), contactInfo(contact), reason(r), next(nullptr) {}
};

class Doctor {
public:
    string name;

    Doctor(string n) : name(n) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    int counter;  // Added a counter for waiting numbers

public:
    Queue() : front(nullptr), rear(nullptr), counter(0) {}

    ~Queue() {
        destroyQueue();
    }

    void createQueue() {
        front = nullptr;
        rear = nullptr;
        counter = 0;
    }

    void destroyQueue() {
        while (!isEmpty()) {
            deQueue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    bool isFull() {
        return false; // Assuming linked list, so it won't be full
    }

    void enQueue(Node* newNode) {
        newNode->waitingNumber = ++counter;  // Assigning waiting number
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Node* deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return nullptr;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
            counter = 0;  // Reset counter when the queue is empty
        }

        return temp;
    }

    Node* getFront() {
        return front;
    }
};

class HospitalSystem {
private:
    Queue appointmentQueue;
    Queue checkInQueue;
    Queue prescriptionQueue;
    Queue availableDoctors;

public:
    void displayLists() {
        cout << "\nNot checked-in List:\n";
        displayQueue(appointmentQueue);

        cout << "\nChecked-in List:\n";
        displayQueue(checkInQueue);

        cout << "\nPrescription waiting List:\n";
        displayQueue(prescriptionQueue);
    }

    void displayQueue(Queue& queue) {
        if (queue.isEmpty()) {
            cout << "Empty\n";
            return;
        }

        Node* current = queue.getFront();
        while (current != nullptr) {
            cout << "Waiting Number: " << current->waitingNumber << "\t Name: " << current->name << "\t Contact: " << current->contactInfo << "\t Reason: " << current->reason << endl;
            current = current->next;
        }
    }

    void requestAppointment() {
        string name, contact, reason;

        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter your contact information: ";
        getline(cin, contact);

        cout << "Enter reason for the appointment: ";
        getline(cin, reason);

        Node* patientNode = new Node(0, name, contact, reason);  // 0 is a placeholder for waiting number
        appointmentQueue.enQueue(patientNode);

        cout << "Appointment request submitted successfully. Your waiting number is: " << patientNode->waitingNumber << endl;
    }

    void checkInPatient() {
        if (appointmentQueue.isEmpty()) {
            cout << "No pending appointments. Cannot check-in.\n";
            return;
        }

        Node* patientNode = appointmentQueue.deQueue();
        checkInQueue.enQueue(patientNode);

        cout << "Check-in successful. You are now in the waiting list.\n";
    }

    void prescribeMedication() {
        if (checkInQueue.isEmpty()) {
            cout << "No patients in the waiting list. Cannot prescribe medication.\n";
            return;
        }

        Node* patientNode = checkInQueue.deQueue();
        prescriptionQueue.enQueue(patientNode);

        cout << "Prescription requested for patient " << patientNode->name << ".\n";
    }

    void addDoctor(Doctor doctor) {
        Node* doctorNode = new Node(0, doctor.name, "", "");  // 0 is a placeholder for waiting number
        availableDoctors.enQueue(doctorNode);
        cout << "Doctor " << doctor.name << " is now available.\n";
    }

};

int main() {
    HospitalSystem hospital;

    Doctor doctor1("Dr. Smith");
    Doctor doctor2("Dr. Johnson");

    hospital.addDoctor(doctor1);
    hospital.addDoctor(doctor2);

    int option;

    do {
        cout << "\nMenu:\n";
        cout << "1. Request Appointment\n";
        cout << "2. Check-in\n";
        cout << "3. Prescribe Medication\n";
        cout << "4. Display Lists\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;
        cin.ignore();  // Consume the newline character left in the buffer

        switch (option) {
            case 1:
                hospital.requestAppointment();
                break;
            case 2:
                hospital.checkInPatient();
                break;
            case 3:
                hospital.prescribeMedication();
                break;
            case 4:
                hospital.displayLists();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }


    } while (option != 5);

    return 0;
}
