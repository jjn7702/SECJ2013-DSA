#include <iostream>
#include <fstream>
#include <string>
#define D "Deposit"
#define W "Withdraw"
#define T "Transfer"
using namespace std;

class Transaction()
{
    string senderAcc, receiverAcc;
    double amount;
    char type;

public:
    // For D & W
    Transaction(string s, double a, char t) : 
    senderAcc(s), receiverAcc(NULL), amount(a), type(t) {}

    // For T
    Transaction(string s, string r, double a, char t) : 
    senderAcc(s), receiverAcc(r), amount(a), type(t) {}

    void setSenderAcc(stirng s) { senderAcc = s; }
    void setReceiverAcc(stirng r) { receiverAcc = r; }
    void setAmount(double a) { amount = a; }
    void setType(char t) { type= t; }

    string getSenderAcc() const { return senderAcc; }
    string getReceiverAcc() const { return receiverAcc; }
    double getAmount() const { return amount; }
    char getType() const
    {
        if(type == D)
            return "Deposit";
        else if(type == W)
            return "Withdraw";
        else 
            return "Transfer";
    }

};