#include <iostream>
#include <fstream>
#include <string>
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

    void deposit(double amount) { balance += amount; }

    bool withdraw(double amount, const std::string& enteredPassword) {
        // Verify password before withdrawal
        if (enteredPassword == password && amount <= balance) {
            balance -= amount;
            return true; // Withdrawal successful
        }
        return false; // Withdrawal failed
    }

    void transfer(double amount, BankAccount& receiver, const std::string& enteredPassword) {
        // Verify password before transfer
        if (enteredPassword == password && amount <= balance) {
            balance -= amount;
            receiver.deposit(amount);
        }
    }
};

int main()
{
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