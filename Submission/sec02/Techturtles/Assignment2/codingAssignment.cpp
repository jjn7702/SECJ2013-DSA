#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class courier
{
private:
    string trackNum;
    string senderName;
    string receiverName;
    string deliveryStatus;

public:
    courier(string track, string sender, string receiver, string status) : trackNum(track), senderName(sender), receiverName(receiver), deliveryStatus(status) {}

    string getTrackingNumber()
    {
        return trackNum;
    }
    string getSenderName()
    {
        return senderName;
    }
    string getReceiverName()
    {
        return receiverName;
    }
    string getDeliveryStatus()
    {
        return deliveryStatus;
    }
};

class Node
{
public:
    Node *next;
    Courier data;

    Node(Courier &courier) : data(courier), next(nullptr) {}
};
class CourierServiceSystem
{
private:
    Node *head;

public:
    CourierServiceSystem() : head(nullptr) {}
    ~CourierServiceSystem()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};