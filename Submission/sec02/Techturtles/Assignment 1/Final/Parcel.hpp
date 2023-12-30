#pragma once
#include <iostream>
#include <string>
using namespace std;

class Parcel
{
private:
    string trackingNumber, address, nameSender, nameReceiver;
    char category;
    int status;

public:
    Parcel();

    Parcel(string tracking, string addr, string nameS, string nameR, char categ, int stat);

    string getTrackingNumber();

    string getAddress();

    string getNameSender();

    string getNameReceiver();

    char getCategory();

    int getStatus();

    void displayShippingCategory();

    void displayStatus_Delivery();

    void displayParcelDetails();
};