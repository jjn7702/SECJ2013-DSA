#include <iostream>
#include <fstream>
#include <string>
#define N 5
using namespace std;

class TransactionHistory()
{
    char operation;
    double amount;
    string sender, receiver;

public:

    TransactionHistory() : default;

    char getOperation() const { return getOperation; }
    double getAmount() const { return amount; }
    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }


};

class BankAccount
{
    string username, password;
    double balance;
    TransactionHistory history;

public:
    BankAccount() = default;

    BankAccount(string& username, string& password, double initialBalance) : 
    username(username), password(password), balance(initialBalance) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; } 
    double getBalance() const { return balance; } 

    void setUsername(stirng name) { username = name; }
    void setPassword(string oldP, string newP)
    {
        if(password == oldP)
        {
            password = newP;
            cout << "Password is successfully updated!" << endl;
        }
        else 
            cout << "Old password is incorrect! Password is not updated."
    }
    
    void setBalance(double newBalance) { balance = newBalance; }

    void deposit(double amount) { balance += amount; }

    bool withdraw(double amount, string& enteredPassword) {
        // Verify password before withdrawal
        if (enteredPassword == password && amount <= balance) {
            balance -= amount;
            return true; // Withdrawal successful
        }
        return false; // Withdrawal failed
    }

    void transfer(double amount, BankAccount& receiver, string& enteredPassword) {
        // Verify password before transfer
        if (enteredPassword == password && amount <= balance) {
            balance -= amount;
            receiver.deposit(amount);
        }
    }
};


class BankingSystem {
private:
    BankAccount accounts[5];

public:
    // Load bank accounts from file
    void loadAccounts(const string& filename) {
        ifstream file(filename);
        string username, password;
        double balance;
        for(int i = 0; i < N; i++)
        {
            file >> username >> password >> balance;
            accounts.emplace_back(username, password, balance);
        }
        /**while (file >> username >> password >> balance) {
            accounts.emplace_back(username, password, balance);
        }*/
        file.close();
    }

};

int main()
{
    fstream
    int choice;

    cout << "<<<<<<<<WELCOME TO DACCrew ONLINE BANKING SYSTEM>>>>>>>" << endl;
    do
    {
        cout << "Please select an operation" << endl;
        cout << "[1] Deposit" << endl
             << "[2] Withdrawal" << endl
             << "[3] Instant Transfer" << endl
             << "[4] View Account" << endl
             << "[5] View Transaction History" << endl
             << "[6] Abort" << endl
             << "Choice:";
        
        cin >> choice;


    }while(choice != 6)
}