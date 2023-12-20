#include "Parcel.hpp"

Parcel ::Parcel() {}

Parcel ::Parcel(string tracking, string addr, string nameS, string nameR, char categ, int stat)
{
    trackingNumber = tracking;
    address = addr;
    nameSender = nameS;
    nameReceiver = nameR;
    category = categ;
    status = stat;
}

string Parcel ::getTrackingNumber()
{

    return trackingNumber;
}

string Parcel ::getAddress()
{
    return address;
}

string Parcel ::getNameSender()
{
    return nameSender;
}

string Parcel ::getNameReceiver()
{
    return nameReceiver;
}

char Parcel ::getCategory()
{

    return category;
}

int Parcel ::getStatus()
{
    return status;
}

void Parcel ::displayShippingCategory()
{
    if (category == 'A' || category == 'a')
    {
        cout << "Bulky & Heavy Delivery";
    }
    else
        cout << "Standard Delivery";
    cout << endl;
}
void Parcel ::displayStatus_Delivery()
{
    if (status == 0)
    {
        cout << "COMPLETE";
    }
    else
        cout << "INCOMPLETE";
    cout << endl;
}

void Parcel ::displayParcelDetails()
{
    cout << "Tracking No. : " << trackingNumber << endl;
    cout << "Address : " << address << endl;
    cout << "Sender : " << nameSender << endl;
    cout << "Receiver : " << nameReceiver << endl;
    cout << "Shipping category : ";
    displayShippingCategory();
    cout << "Parcel status : ";
    displayStatus_Delivery();
}