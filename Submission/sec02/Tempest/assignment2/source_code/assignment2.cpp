#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class task//node
{
private:
    string tasks;
    string day;
    string month;
    string year;
    string status;

public:
    task *next;
    void display();
    void settask(string t) { tasks = t; }
    void setday(string d) { day = d; }
    void setmonth(string m) { month = m; }
    void setyear(string y) { year = y; }
    void setstatus(string s) { status = s; }
    string gettask() const { return tasks; }
    string getday() const { return day; }
    string getmonth() const { return month; }
    string getyear() const { return year; }
    string getstatus() const { return status; }

    // Standalone search functions
    bool searchByName(const string &key) const;
    bool searchByDate(const string &key) const;
    bool searchByStatus(const string &key) const;
};

class list
{

public:
    task *head;
    task *tail; // Tail pointer
    list()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insert(task d)
    { 
        task* newNode= new task(d);

        if(isEmpty())
        {
            head=newNode;
        }

        else
        {
            newNode->next=head;
            head=newNode;
        }
        
    }

    void insertrand(int c, task d)
    {
        task* newNode= new task (d);
        task* temp= head;
        int count=1;

        while(temp->next != NULL && count<c)
        {
            temp=temp->next;
            count++;

        }

        newNode->next=temp->next;
        temp->next=newNode;
        
    }

    void insertend(task d)
    {
        task* newNode= new task (d);
        task * temp=head;

        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=new task(d);

    }

    void removebeginning() //remove first node
    { 
        if(isEmpty())
        {
            cout<<"List is empty.No task to remove. "<<endl;
            return;

        }
        task* temp=head;
        head=head->next;
        delete temp;
    }

    void removelast()//remove last node
    {
        if(isEmpty())
        {
            cout<<"List is empty. Nothing to be remove. "<<endl;
            return;
        }

        if(head->next==nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        task* temp=head;
        while(temp->next->next != nullptr)
        {
            temp=temp->next;
        }

        delete temp->next;
        temp->next=nullptr;
    }

    void removemiddle(int c) //remove middle node(specific node)
    {
        if(isEmpty())
        {
            cout<<"List is empty.No task to remove. "<<endl;
            return;
        }

        task* prev = nullptr;
        task* current = head;
        int count=1;

        while (current != nullptr && count<c)
        {
            prev=current;
            current=current->next;
            count++;

        }
        
        if(current==nullptr)
        {
            cout<<"Position out of range.No task to remove. "<<endl;
            return;
        }

        if(prev==nullptr) //remove first node
        {
            head=current->next;
        }
        else
        {
            prev->next=current->next;
        }

        delete current;
    }

    void displist()
    {
        task *temp = head;
        while (temp)
        {
            cout << left << setw(40) << temp->gettask();
            cout << left << setw(2) << "|";
            cout << left << setw(20) << temp->getday() + "-" + temp->getmonth() + "-" + temp->getyear();
            cout << left << setw(2) << "|";
            cout << left << setw(10) << temp->getstatus() << endl;

            temp = temp->next; // move pointer to the next node
        }

        cout << endl;
    }

    // Standalone search functions
    vector<int> searchByName(const list &lst, const string &key);
    vector<int> searchByDate(const list &lst, const string &key);
    vector<int> searchByStatus(const list &lst, const string &key);
    void displayTask(int index) const;
};

void task::display()
{
    cout << left << setw(40) << tasks;
    cout << left << setw(2) << "|";
    cout << left << setw(20) << day + "-" + month + "-" + year;
    cout << left << setw(2) << "|";
    cout << left << setw(10) << status << endl;
}

bool task::searchByName(const string &key) const
{
    return tasks == key;
}

bool task::searchByDate(const string &key) const
{
    string dateInTask = day + "-" + month + "-" + year;
    return dateInTask == key;
}

bool task::searchByStatus(const string &key) const
{
    return status == key;
}

vector<int> list::searchByName(const list &lst, const string &key)
{
    vector<int> indices;
    task *temp = lst.head;
    int position = 0;

    while (temp)
    {
        if (temp->searchByName(key))
        {
            indices.push_back(position);
        }
        temp = temp->next;
        position++;
    }

    return indices;
}

vector<int> list::searchByDate(const list &lst, const string &key)
{
    vector<int> indices;
    task *temp = lst.head;
    int position = 0;

    while (temp)
    {
        if (temp->searchByDate(key))
        {
            indices.push_back(position);
        }
        temp = temp->next;
        position++;
    }

    return indices;
}

vector<int> list::searchByStatus(const list &lst, const string &key)
{
    vector<int> indices;
    task *temp = lst.head;
    int position = 0;

    while (temp)
    {
        if (temp->searchByStatus(key))
        {
            indices.push_back(position);
        }
        temp = temp->next;
        position++;
    }

    return indices;
}

// Additional function to display a task at a specific index
void list::displayTask(int index) const
{
    task *temp = head;
    int position = 0;

    while (temp && position != index)
    {
        temp = temp->next;
        position++;
    }

    if (temp)
    {
        temp->display();
    }
}

// Function to convert status to numeric value for sorting
int statusToNumeric(const string &status)
{
    if (status == "todo")
    {
        return 1;
    }
    else if (status == "doing")
    {
        return 2;
    }
    else if (status == "completed")
    {
        return 3;
    }
    return 0; // Default for unknown status
}

// Function to partition the list by task in ascending order
task *partitionByTaskasc(list &tk, task *first, task *last)
{
    string pivot_task = first->gettask();

    task *bottom = first;
    task *top = last;
    task *temp;

    while (1)
    {
        while (top != nullptr && top->gettask() > pivot_task)
        {
            top = top->next;
        }

        while (bottom != nullptr && bottom->gettask() < pivot_task)
        {
            bottom = bottom->next;
        }

        if (bottom != nullptr && top != nullptr && bottom != top)
        {
            // Swap the data
            string tempTask = bottom->gettask();
            bottom->settask(top->gettask());
            top->settask(tempTask);

            string tempDay = bottom->getday();
            bottom->setday(top->getday());
            top->setday(tempDay);

            string tempMonth = bottom->getmonth();
            bottom->setmonth(top->getmonth());
            top->setmonth(tempMonth);

            string tempYear = bottom->getyear();
            bottom->setyear(top->getyear());
            top->setyear(tempYear);

            string tempStatus = bottom->getstatus();
            bottom->setstatus(top->getstatus());
            top->setstatus(tempStatus);
        }
        else
        {
            temp = bottom;
            return temp;
        }
    }
}

// Function to perform quicksort by task in ascending alphabetical order
void quicksortByTaskasc(list &tk, task *first, task *last)
{
    if (first != last && first != nullptr && last != nullptr)
    {
        task *cut = partitionByTaskasc(tk, first, last);
        quicksortByTaskasc(tk, first, cut);
        quicksortByTaskasc(tk, cut->next, last);
    }
}

// Function to partition the list by task in descending order
task *partitionByTaskdesc(list &tk, task *first, task *last)
{
    string pivot_task = first->gettask();

    task *bottom = first;
    task *top = last;
    task *temp;

    while (1)
    {
        while (top != nullptr && top->gettask() < pivot_task)
        {
            top = top->next;
        }

        while (bottom != nullptr && bottom->gettask() > pivot_task)
        {
            bottom = bottom->next;
        }

        if (bottom != nullptr && top != nullptr && bottom != top)
        {
            // Swap the data
            string tempTask = bottom->gettask();
            bottom->settask(top->gettask());
            top->settask(tempTask);

            string tempDay = bottom->getday();
            bottom->setday(top->getday());
            top->setday(tempDay);

            string tempMonth = bottom->getmonth();
            bottom->setmonth(top->getmonth());
            top->setmonth(tempMonth);

            string tempYear = bottom->getyear();
            bottom->setyear(top->getyear());
            top->setyear(tempYear);

            string tempStatus = bottom->getstatus();
            bottom->setstatus(top->getstatus());
            top->setstatus(tempStatus);
        }
        else
        {
            temp = bottom;
            return temp;
        }
    }
}

// Function to perform quicksort by task in descending alphabetical order
void quicksortByTaskdesc(list &tk, task *first, task *last)
{
    if (first != last && first != nullptr && last != nullptr)
    {
        task *cut = partitionByTaskdesc(tk, first, last);
        quicksortByTaskdesc(tk, first, cut);
        quicksortByTaskdesc(tk, cut->next, last);
    }
}

// Function to partition the list by date in ascending order
task *partitionByDateasc(list &tk, task *first, task *last)
{
    string pivot_date = (first->getyear() + first->getmonth() + first->getday());

    task *bottom = first;
    task *top = last;
    task *temp;

    while (1)
    {
        while (top != nullptr && (top->getyear() + top->getmonth() + top->getday() > pivot_date))
        {
            top = top->next;
        }

        while (bottom != nullptr && (bottom->getyear() + bottom->getmonth() + bottom->getday() < pivot_date))
        {
            bottom = bottom->next;
        }

        if (bottom != nullptr && top != nullptr && bottom != top)
        {
            // Swap the data
            string tempTask = bottom->gettask();
            bottom->settask(top->gettask());
            top->settask(tempTask);

            string tempDay = bottom->getday();
            bottom->setday(top->getday());
            top->setday(tempDay);

            string tempMonth = bottom->getmonth();
            bottom->setmonth(top->getmonth());
            top->setmonth(tempMonth);

            string tempYear = bottom->getyear();
            bottom->setyear(top->getyear());
            top->setyear(tempYear);

            string tempStatus = bottom->getstatus();
            bottom->setstatus(top->getstatus());
            top->setstatus(tempStatus);
        }
        else
        {
            temp = bottom;
            return temp;
        }
    }
}

// Function to perform quicksort by date in ascending order
void quicksortByDateasc(list &tk, task *first, task *last)
{
    if (first != nullptr && last != nullptr && first != last)
    {
        task *cut = partitionByDateasc(tk, first, last);
        quicksortByDateasc(tk, first, cut);
        quicksortByDateasc(tk, cut->next, last);
    }
}

// Function to partition the list by date in descending order
task *partitionByDatedesc(list &tk, task *first, task *last)
{
    string pivot_date = (first->getyear() + first->getmonth() + first->getday());

    task *bottom = first;
    task *top = last;
    task *temp;

    while (1)
    {
        while (top != nullptr && (top->getyear() + top->getmonth() + top->getday() < pivot_date))
        {
            top = top->next;
        }

        while (bottom != nullptr && (bottom->getyear() + bottom->getmonth() + bottom->getday() > pivot_date))
        {
            bottom = bottom->next;
        }

        if (bottom != nullptr && top != nullptr && bottom != top)
        {
            // Swap the data
            string tempTask = bottom->gettask();
            bottom->settask(top->gettask());
            top->settask(tempTask);

            string tempDay = bottom->getday();
            bottom->setday(top->getday());
            top->setday(tempDay);

            string tempMonth = bottom->getmonth();
            bottom->setmonth(top->getmonth());
            top->setmonth(tempMonth);

            string tempYear = bottom->getyear();
            bottom->setyear(top->getyear());
            top->setyear(tempYear);

            string tempStatus = bottom->getstatus();
            bottom->setstatus(top->getstatus());
            top->setstatus(tempStatus);
        }
        else
        {
            temp = bottom;
            return temp;
        }
    }
}

// Function to perform quicksort by date in descending order
void quicksortByDatedesc(list &tk, task *first, task *last)
{
    if (first != nullptr && last != nullptr && first != last)
    {
        task *cut = partitionByDatedesc(tk, first, last);
        quicksortByDatedesc(tk, first, cut);
        quicksortByDatedesc(tk, cut->next, last);
    }
}

// Function to partition the list by status in ascending order
// Function to partition the list by status in ascending order
task *partitionByStatusasc(list &tk, task *first, task *last)
{
    string pivot_status = first->getstatus();

    task *bottom = first;
    task *top = last;
    task *temp;

    while (1)
    {
        while (top != nullptr && (top->getstatus() > pivot_status ||
                                  (top->getstatus() == pivot_status && top->gettask() < bottom->gettask())))
        {
            top = top->next;
        }

        while (bottom != nullptr && (bottom->getstatus() < pivot_status ||
                                     (bottom->getstatus() == pivot_status && bottom->gettask() > top->gettask())))
        {
            bottom = bottom->next;
        }

        if (bottom != nullptr && top != nullptr && bottom != top)
        {
            // Swap the data
            string tempTask = bottom->gettask();
            bottom->settask(top->gettask());
            top->settask(tempTask);

            string tempDay = bottom->getday();
            bottom->setday(top->getday());
            top->setday(tempDay);

            string tempMonth = bottom->getmonth();
            bottom->setmonth(top->getmonth());
            top->setmonth(tempMonth);

            string tempYear = bottom->getyear();
            bottom->setyear(top->getyear());
            top->setyear(tempYear);

            string tempStatus = bottom->getstatus();
            bottom->setstatus(top->getstatus());
            top->setstatus(tempStatus);
        }
        else
        {
            temp = bottom;
            return temp;
        }
    }
}

// Function to perform quicksort by status in ascending order
void quicksortByStatusasc(list &tk, task *first, task *last)
{
    if (first != nullptr && last != nullptr && first != last)
    {
        task *cut = partitionByStatusasc(tk, first, last);
        quicksortByStatusasc(tk, first, cut);
        quicksortByStatusasc(tk, cut->next, last);
    }
}

// Function to partition the list by status in descending order
task *partitionByStatusdesc(list &tk, task *first, task *last)
{
    string pivot_status = first->getstatus();

    task *bottom = first;
    task *top = last;
    task *temp;

    while (1)
    {
        while (top != nullptr && (top->getstatus() > pivot_status ||
                                  (top->getstatus() == pivot_status && top->gettask() > bottom->gettask())))
        {
            top = top->next;
        }

        while (bottom != nullptr && (bottom->getstatus() < pivot_status ||
                                     (bottom->getstatus() == pivot_status && bottom->gettask() < top->gettask())))
        {
            bottom = bottom->next;
        }

        if (bottom != nullptr && top != nullptr && bottom != top)
        {
            // Swap the data
            string tempTask = bottom->gettask();
            bottom->settask(top->gettask());
            top->settask(tempTask);

            string tempDay = bottom->getday();
            bottom->setday(top->getday());
            top->setday(tempDay);

            string tempMonth = bottom->getmonth();
            bottom->setmonth(top->getmonth());
            top->setmonth(tempMonth);

            string tempYear = bottom->getyear();
            bottom->setyear(top->getyear());
            top->setyear(tempYear);

            string tempStatus = bottom->getstatus();
            bottom->setstatus(top->getstatus());
            top->setstatus(tempStatus);
        }
        else
        {
            temp = bottom;
            return temp;
        }
    }
}

// Function to perform quicksort by status in descending order
void quicksortByStatusdesc(list &tk, task *first, task *last)
{
    if (first != last && first != nullptr && last != nullptr)
    {
        task *cut = partitionByStatusdesc(tk, first, last);
        quicksortByStatusdesc(tk, first, cut);
        quicksortByStatusdesc(tk, cut->next, last);
    }
}

int main()
{
    fstream input("task.txt", ios::in);
    if (!input.is_open())
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string tasks, status, date;
    string day, month, year;
    list tk;

    // Reading tasks from the file
    while (getline(input >> ws, tasks, '/'))
    {
        getline(input >> ws, day, '-');
        getline(input >> ws, month, '-');
        getline(input >> ws, year, '(');
        getline(input >> ws, status, ')');

        task newTask;
        newTask.settask(tasks);
        newTask.setday(day);
        newTask.setmonth(month);
        newTask.setyear(year);
        newTask.setstatus(status);

        tk.insertend(newTask);
    }

    input.close();

    // Display the original list
    cout << "\n<<TASK MANAGEMENT SYSTEM>>" << endl
         << endl;
    cout << left << setw(40) << "TASK";
    cout << left << setw(2) << "|";
    cout << left << setw(20) << "DATE";
    cout << left << setw(2) << "|";
    cout << left << setw(10) << "STATUS" << endl
         << endl;
    tk.displist();
    cout << endl
         << endl;

    int choice;

    while (true)
    {
        cout << "<<OPERATION PROCESS>>" << endl;
        cout << "[1] ADD A TASK" << endl;
        cout << "[2] REMOVE A TASK" << endl;
        cout << "[3] SEARCH A TASK" << endl;
        cout << "[4] SORT THE LIST" << endl; // New option for sorting
        cout << "[5] EXIT" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 5)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            // Add a new task
            {
                int addChoice;
                cout << "<<POSITION TO ADD>>" << endl;
                cout << "[1] BEGINNING" << endl;
                cout << "[2] MIDDLE (ANY POSITION BETWEEN BEGINNING AND LAST)" << endl;
                cout << "[3] LAST" << endl
                     << endl;
                cout << "Enter your choice: ";
                cin >> addChoice;
                cout << endl;

                switch (addChoice)
                {
                case 1:
                { // add beginning
                    task newTask;
                    cout << "Enter task details:" << endl;
                    cin.ignore(); // Clear the input buffer
                    cout << "Task: ";
                    getline(cin, tasks);
                    cout << "Day: ";
                    cin >> day;
                    cout << "Month: ";
                    cin >> month;
                    cout << "Year: ";
                    cin >> year;
                    cout << "Status: ";
                    cin >> status;

                    //set node data
                    //insert node
                    newTask.settask(tasks);
                    newTask.setday(day);
                    
                    cout << "\n\nTask added at the beginning." << endl;
                }
                break;

                case 2:
                { // add middle
                    task newTask;
                    cout << "Enter task details:" << endl;
                    cin.ignore(); // Clear the input buffer
                    cout << "Task: ";
                    getline(cin, tasks);
                    cout << "Day: ";
                    cin >> day;
                    cout << "Month: ";
                    cin >> month;
                    cout << "Year: ";
                    cin >> year;
                    cout << "Status: ";
                    cin >> status;

                    int position;
                    cout << "Enter the position to add the new task: ";
                    cin >> position;
                    //insert position and new data
                    cout << "/n/nTask added in the middle." << endl;
                }
                break;

                case 3:
                { // add last
                    task newTask;
                    cout << "Enter task details:" << endl;
                    cin.ignore(); // Clear the input buffer
                    cout << "Task: ";
                    getline(cin, tasks);
                    cout << "Day: ";
                    cin >> day;
                    cout << "Month: ";
                    cin >> month;
                    cout << "Year: ";
                    cin >> year;
                    cout << "Status: ";
                    cin >> status;

                    //set task
                    //insert data into node
                    cout << "\n\nTask added at the end." << endl;
                }
                break;

                default:
                    cout << "Invalid choice" << endl;
                    break;
                }

                cout << left << setw(40) << "TASK";
                cout << left << setw(2) << "|";
                cout << left << setw(20) << "DATE";
                cout << left << setw(2) << "|";
                cout << left << setw(10) << "STATUS" << endl
                     << endl;
                tk.displist();
                cout << endl
                     << endl;
            }
            break;

        case 2:
            // Remove a task (existing code)
            {
                int removeChoice;
                cout << "<<POSITION TO REMOVE>>" << endl;
                cout << "[1] BEGINNING" << endl;
                cout << "[2] MIDDLE (ANY POSITION BETWEEN BEGINNING AND LAST)" << endl;
                cout << "[3] LAST" << endl
                     << endl;
                cout << "Enter your choice: ";
                cin >> removeChoice;

                switch (removeChoice)
                {
                case 1:
                    //remove beginning
                    tk.removebeginning();
                    cout << "\n\nTask removed from the beginning." << endl;
                    break;

                case 2:
                {
                    int position;
                    cout << "Enter the position to remove the task from the middle: ";
                    cin >> position;
                    //remove middle
                    tk.removemiddle(position);
                    cout << "\n\nTask removed from the middle." << endl;
                }
                break;

                case 3:
                    //remove last
                    tk.removelast();
                    cout << "\n\nTask removed from the end." << endl;
                    break;

                default:
                    cout << "Invalid choice" << endl;
                    break;
                }

                cout << left << setw(40) << "TASK";
                cout << left << setw(2) << "|";
                cout << left << setw(20) << "DATE";
                cout << left << setw(2) << "|";
                cout << left << setw(10) << "STATUS" << endl
                     << endl;
                tk.displist();
                cout << endl
                     << endl;
            }
            break;

        case 3:
            // Search for a task
            {
                int searchChoice;
                cout << "<<SEARCH A TASK>>" << endl;
                cout << "[1] BY TASK NAME" << endl;
                cout << "[2] BY DATE" << endl;
                cout << "[3] BY STATUS" << endl
                     << endl;
                cout << "Enter your choice: ";
                cin >> searchChoice;

                string key;
                vector<int> resultIndices;

                switch (searchChoice)
                {
                case 1:
                    cout << "Enter the task name to search: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, key);
                    resultIndices = tk.searchByName(tk, key);
                    break;

                case 2:
                    cout << "Enter the date to search (DD-MM-YYYY): ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, key);
                    resultIndices = tk.searchByDate(tk, key);
                    break;

                case 3:
                    cout << "Enter the status to search: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, key);
                    resultIndices = tk.searchByStatus(tk, key);
                    break;

                default:
                    cout << "Invalid choice" << endl;
                    break;
                }

                // Display the search results
                cout << "\nSearch Results:" << endl;
                if (resultIndices.empty())
                {
                    cout << "No matching tasks found." << endl;
                }
                else
                {
                    cout << left << setw(40) << "TASK";
                    cout << left << setw(2) << "|";
                    cout << left << setw(20) << "DATE";
                    cout << left << setw(2) << "|";
                    cout << left << setw(10) << "STATUS" << endl
                         << endl;

                    for (int index : resultIndices)
                    {
                        tk.displayTask(index);
                    }

                    cout << endl;
                }
            }

            break;

        case 4:
            // Sort the list
            {
                int sortChoice;
                cout << "<<< SORTING >>>" << endl;
                cout << "[1] BY ASCENDING ALPHABET \n"
                     << "[2] BY DESCENDING ALPHABET \n"
                     << "[3] BY ASCENDING DATE \n"
                     << "[4] BY DESCENDING DATE \n"
                     << "[5] BY ASCENDING STATUS \n"
                     << "[6] BY DESCENDING STATUS \n"
                     << "[7] EXIT \n"
                     << endl;
                cout << "Enter your choice: ";
                cin >> sortChoice;

                switch (sortChoice)
                {
                case 1:
                    quicksortByTaskasc(tk, tk.head, tk.tail);
                    cout << "List sorted in Ascending Alphabetical Order." << endl;
                    break;

                case 2:
                    quicksortByTaskdesc(tk, tk.head, tk.tail);
                    cout << "List sorted in Descending Alphabetical Order." << endl;
                    break;

                case 3:
                    quicksortByDateasc(tk, tk.head, tk.tail);
                    cout << "List sorted in Ascending Date Order." << endl;
                    break;

                case 4:
                    quicksortByDatedesc(tk, tk.head, tk.tail);
                    cout << "List sorted in Descending Date Order." << endl;
                    break;

                case 5:
                    quicksortByStatusasc(tk, tk.head, tk.tail);
                    cout << "List sorted in Ascending Status Order." << endl;
                    break;

                case 6:
                    quicksortByStatusdesc(tk, tk.head, tk.tail);
                    cout << "List sorted in Descending Status Order." << endl;
                    break;

                default:
                    cout << "Invalid choice" << endl;
                    break;
                }

                // Display the entire sorted list
                cout << left << setw(40) << "TASK";
                cout << left << setw(2) << "|";
                cout << left << setw(20) << "DATE";
                cout << left << setw(2) << "|";
                cout << left << setw(10) << "STATUS" << endl
                     << endl;
                tk.displist(); // Display the entire sorted list
                cout << endl
                     << endl;
            }
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}
