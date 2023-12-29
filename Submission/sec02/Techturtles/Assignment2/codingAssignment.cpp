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
    courier data;

    Node(courier &courier) : data(courier), next(nullptr) {}
};
class CourierServiceSystem
{
private:
    Node *head;

public:
    Node *head;
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
void addNode(const courier &newCourier, const string &position = "end")
{
    Node *newNode = new Node(newCourier);

    if (position == "beginning")
    {
        newNode->next = head;
        head = newNode;
    }
    else if (position == "middle")
    {
        if (head != nullptr)
        {
            Node *slow = head;
            Node *fast = head->next;
            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            newNode->next = slow->next;
            slow->next = newNode;
        }
        else
        {
            head = newNode;
        }
    }
    else
    {
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}