#include <iostream>
#include <iomanip> // to use put_time
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

class Node
{
public:
    int waitingNumber; // Added waitingNumber field
    string name;
    string contactInfo;
    string reason;
    time_t appointmentTime;
    Node *next;

    // tree
    Node *left;
    Node *right;

    Node(int number, string n, string contact, string r, time_t time) : waitingNumber(number), name(n), contactInfo(contact), reason(r), appointmentTime(time), next(nullptr) {}
    Node(string n) : name(n), left(nullptr), right(nullptr), next(nullptr) {} // for tree
};

class Tree
{
private:
    Node *root;

public:
    Tree() : root(nullptr) {}

    void insertNode(Node *newNode)
    {
        insert(root, newNode);
    }

    void insert(Node *&tree, Node *newNode)
    {
        if (tree == nullptr)
        {
            tree = newNode;
        }
        else if (newNode->name < tree->name)
        {
            insert(tree->left, newNode);
        }
        else if (newNode->name >= tree->name)
        {
            insert(tree->right, newNode);
        }
    }

    void InOrderTraversal(Node *tree) const
    {

        if (tree != nullptr)
        {

            InOrderTraversal(tree->left);
            cout << "Patient Name: " << tree->name << "\t Contact: " << tree->contactInfo << "\t Reason: " << tree->reason << endl;
            InOrderTraversal(tree->right);
        }
    }

    bool search(Node *tree, string item)
    {
        if (tree == NULL)
        {
            return false;
        }
        else if (item < tree->name)
        {
            return search(tree->left, item);
        }
        else if (item > tree->name)
        {
            return search(tree->right, item);
        }
        else
        {
            return true;
        }
    }

    void destroyTree(Node *node)
    {
        if (node)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    bool isEmpty() const
    {
        if (root == NULL)
            return 1;
        else
            return 0;
    }

    void displayTree() const
    {
        InOrderTraversal(root);
    }

    bool searchTree(string item)
    {
        return search(root, item);
    }

    void deleteNode(string item)
    {
        root = deleteNodeHelper(root, item);
    }

    Node *deleteNodeHelper(Node *root, string key)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (key < root->name)
        {
            root->left = deleteNodeHelper(root->left, key);
        }

        else if (key > root->name)
        {
            root->right = deleteNodeHelper(root->right, key);
        }

        else
        {
            // Node with only one child or no child
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            Node *temp = findMin(root->right);
            root->name = temp->name;
            root->right = deleteNodeHelper(root->right, temp->name);
        }
        return root;
    }

    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
};

class Doctor
{
public:
    string name;

    Doctor(string n) : name(n) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(NULL) {}

    ~Stack()
    {
        destroyStack();
    }

    void push(Node *newNode)
    {
        if (isEmpty())
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    Node *pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop.\n";
            return NULL;
        }

        Node *temp = top;
        top = top->next;
        temp->next = NULL;
        return temp;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void destroyStack()
    {
        while (!isEmpty())
        {
            Node *temp = pop();
            delete temp; // Add this line to free the memory
        }
        top = NULL;
    }

    Node *getTop()
    {
        return top;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int counter; // Added a counter for waiting numbers

public:
    Queue() : front(nullptr), rear(nullptr), counter(0) {}

    ~Queue()
    {
        destroyQueue();
    }

    void createQueue()
    {
        front = nullptr;
        rear = nullptr;
        counter = 0;
    }

    void destroyQueue()
    {
        while (!isEmpty())
        {
            deQueue();
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    bool isFull()
    {
        return false; // Assuming linked list, so it won't be full
    }

    void enQueue(Node *newNode)
    {
        newNode->waitingNumber = ++counter; // Assigning waiting number
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Node *deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return nullptr;
        }

        Node *temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
            counter = 0; // Reset counter when the queue is empty
        }
        temp->next = nullptr;
        return temp;
    }

    Node *getFront()
    {
        return front;
    }
};

class HospitalSystem
{
private:
    Queue appointmentQueue;
    Queue checkInQueue;
    Queue prescriptionQueue;
    Queue availableDoctors;
    Stack prescriptionHistoryStack;
    Tree patientTree;

public:
    void displayLists()
    {
        cout << "\nNot checked-in List:\n";
        displayQueue(appointmentQueue);

        cout << "\nChecked-in List:\n";
        displayQueue(checkInQueue);

        cout << "\nPrescription waiting List:\n";
        displayQueue(prescriptionQueue);
    }

    void displayQueue(Queue &queue)
    {
        if (queue.isEmpty())
        {
            cout << "Empty\n";
            return;
        }

        Node *current = queue.getFront();
        while (current != nullptr)
        {
            cout << "Waiting Number: " << current->waitingNumber << "\t Name: " << current->name << "\t Contact: " << current->contactInfo << "\t Reason: " << current->reason << endl;
            current = current->next;
        }
    }

    void requestAppointment()
    {
        string name, contact, reason;

        // Get the current system time
        time_t currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());

        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter your contact information: ";
        getline(cin, contact);

        cout << "Enter reason for the appointment: ";
        getline(cin, reason);

        Node *patientNode = new Node(0, name, contact, reason, currentTime); // 0 is a placeholder for waiting number
        appointmentQueue.enQueue(patientNode);
        patientTree.insertNode(patientNode);

        cout << "Appointment request submitted successfully. Your waiting number is: " << patientNode->waitingNumber << endl;
    }

    void checkInPatient()
    {
        if (appointmentQueue.isEmpty())
        {
            cout << "No pending appointments. Cannot check-in.\n";
            return;
        }

        Node *patientNode = appointmentQueue.deQueue();
        checkInQueue.enQueue(patientNode);

        cout << "Check-in successful. You are now in the waiting list.\n";
    }

    void prescribeMedication()
    {
        if (checkInQueue.isEmpty())
        {
            cout << "No patients in the waiting list. Cannot prescribe medication.\n";
            return;
        }
        Node *patientNode = checkInQueue.deQueue();
        prescriptionQueue.enQueue(patientNode);

        cout << "Prescription requested for patient " << patientNode->name << ".\n";

        // After prescribing medication, dequeue the patient from the prescription queue
        Node *prescribedPatient = prescriptionQueue.deQueue();
        cout << "Medication prescribed for patient " << prescribedPatient->name << ".\n";

        // Record the patient in the prescription history stack
        prescriptionHistoryStack.push(prescribedPatient);
    }

    void addDoctor(Doctor doctor)
    {
        time_t currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        Node *doctorNode = new Node(0, doctor.name, "", "", currentTime); // 0 is a placeholder for waiting number
        availableDoctors.enQueue(doctorNode);
        cout << "Doctor " << doctor.name << " is now available.\n";
    }

    void displayPrescriptionHistory()
    {
        cout << "\nPrescription History:\n";

        if (prescriptionHistoryStack.isEmpty())
        {
            cout << "Empty\n";
            return;
        }
        ofstream exportHistory("\\HistoryMedication.txt");
        if (!exportHistory)
        {
            cout << "Failed to export data! please check the path\n\n";
            Node *current = prescriptionHistoryStack.getTop();
            while (current != NULL)
            {
                cout << "Patient Name: " << current->name << "\t Contact: " << current->contactInfo << "\t Reason: " << current->reason << endl;
                current = current->next;
            }
            return;
        }
        Node *current = prescriptionHistoryStack.getTop();
        exportHistory << "\t\t\t<< Hospital Mediacation Prescription History >>" << endl
                      << "-------------------------------------------------------------------------------------------" << endl;
        while (current != NULL)
        {
            cout << "Patient Name: " << current->name << "\t Contact: " << current->contactInfo << "\t Reason: " << current->reason << endl;
            exportHistory << "Patient Name: " << current->name << "\t Contact: " << current->contactInfo << "\t Reason: " << current->reason << "\t Time: "
                          << put_time(localtime(&current->appointmentTime), "%Y-%m-%d %H:%M:%S") << endl;
            current = current->next;
        }

        exportHistory.close();
    }

    void displayPrescriptionHistoryA()
    {
        if (patientTree.isEmpty())
        {
            cout << "No Patients in the system.\n";
        }
        else
        {
            cout << "\nList of Patients (Sorted by Alphabetical Order):\n";
            patientTree.displayTree();
        }
    }

    void deletePrescriptionHistoryA()
    {
        string patientName;
        cout << "Enter the name of the patient to delete: ";
        getline(cin, patientName);

        // Search for the patient in the patient tree
        bool patientFound = patientTree.searchTree(patientName);

        if (patientFound)
        {

            patientTree.deleteNode(patientName);
            cout << "Patient " << patientName << "'s history deleted successfully.\n";
        }
        else
        {
            cout << "Patient " << patientName << " not found in the system.\n";
        }
    }
};

int main()
{
    HospitalSystem hospital;

    Doctor doctor1("Dr. Smith");
    Doctor doctor2("Dr. Johnson");

    hospital.addDoctor(doctor1);
    hospital.addDoctor(doctor2);

    int option;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Request Appointment\n";
        cout << "2. Check-in\n";
        cout << "3. Prescribe Medication\n";
        cout << "4. Display Lists\n";
        cout << "5. Display Prescription History\n";
        cout << "6. Display Prescription History (Sorted by Alphabetical Order)\n";
        cout << "7. Delete Prescription History\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;
        cin.ignore(); // Consume the newline character left in the buffer

        switch (option)
        {
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
            hospital.displayPrescriptionHistory();
            break;
        case 6:
            hospital.displayPrescriptionHistoryA();
            break;
        case 7:
            hospital.deletePrescriptionHistoryA();
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }

    } while (option != 8);

    return 0;
}
