// Assignment 2 - SECJ2013 - 23241 (project.cpp)
// Group Members:
// 1. Muhammad Iman Firdaus Bin Baharuddin A22EC0216
// 2. Muhammad Ariff Danish Bin Hashnan A22EC0204
// 3. Che Marhumi Bin Che AB Rahim A22EC0147
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <conio.h> // For getch()

using namespace std;

class Cust
{
private:
   string name, destination, airline, Ic;
   int day, month, year;

public:
   Cust() : day(0), month(0), year(0), Ic("") {}

   Cust(string n, int d, int m, int y, string dest, string a, string icee)
       : name(n), day(d), month(m), year(y), destination(dest), airline(a), Ic(icee) {}

   void displayBookingInfo() const
   {
      cout << "\t\t" << left << setw(5) << setw(15) << name << setw(2) << day << " / " << setw(2) << month
           << " / " << setw(15) << year << setw(19) << destination << setw(19) << airline << setw(19) << Ic << endl;
   }

   string getName()
   {
      return name;
   }

   int getDay()
   {
      return day;
   }

   int getMonth()
   {
      return month;
   }

   int getYear()
   {
      return year;
   }

   string getDestination()
   {
      return destination;
   }

   string getAirline()
   {
      return airline;
   }

   string getIcNum()
   {
      return Ic;
   }
};

class BookingQueue
{
public:
   struct Node
   {
      Cust data;
      Node *next;
   };

private:
   Node *front;
   Node *rear;

public:
   BookingQueue() : front(nullptr), rear(nullptr) {}

   void enqueue(Cust &data)
   {
      Node *newNode = new Node{data, nullptr};
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

   void dequeue()
   {
      if (!isEmpty())
      {
         Node *temp = front;
         front = front->next;
         delete temp;
      }
   }

   bool isEmpty() const
   {
      return front == nullptr;
   }

   Cust &getFront() const
   {
      if (!isEmpty())
      {
         return front->data;
      }
      throw out_of_range("Queue is empty");
   }

   Node *getFrontNode() const
   {
      return front;
   }
};

class BookingSystem
{
private:
   BookingQueue doneBooking;
   BookingQueue reservationRequests;
   const string requestFileName = "request.txt";

   void loadRequestsFromFile()
   {
      string line;
      ifstream requestFile(requestFileName);

      if (requestFile.is_open())
      {
         while (getline(requestFile, line))
         {
            stringstream ss(line);
            string name, destination, airline, icee;
            int day, month, year;

            ss >> name >> day >> month >> year >> destination >> airline >> icee;

            if (!ss.fail())
            {
               Cust newBooking(name, day, month, year, destination, airline, icee);
               reservationRequests.enqueue(newBooking);
            }
         }

         requestFile.close();
      }
      else
      {
         cout << "\n\t\t\t\tError opening request.txt file for reading." << endl;
      }
   }

public:
   BookingSystem() { loadRequestsFromFile(); }

   ~BookingSystem() {}

   void addBooking(Cust &booking)
   {
      // all done bookings from booking.txt are initially added to the doneBooking
      doneBooking.enqueue(booking);
   }

   //<----------------------------- CUSTOMER FUNCTIONALITY------------------------------------>

   // <------------------------customer functionality to reserve booking------------->
   void reserveBooking(Cust &booking)
   {
      reservationRequests.enqueue(booking);

      // Write the reservation request to the request.txt file
      ofstream requestFile(requestFileName, ios::app);
      if (requestFile.is_open())
      {
         cout << endl;
         requestFile << booking.getName() << " "
                     << booking.getDay() << " "
                     << booking.getMonth() << " "
                     << booking.getYear() << " "
                     << booking.getDestination() << " "
                     << booking.getAirline() << " "
                     << booking.getIcNum() << endl;

         requestFile.close();
      }
      else
      {
         cout << "\n\t\t\t\tError opening request.txt file for writing." << endl;
      }
   }
   // <------------------------end customer functionality to reserve booking------------->

   // <------------------------customer functionality to cancel booking------------->
   bool cancelRecentReservation()
   {
      if (!reservationRequests.isEmpty())
      {
         reservationRequests.dequeue(); // Remove the most recent reservation
         cout << "\t\t\t\tMost previous reservation canceled successfully." << endl;
         return true;
      }
      else
      {
         cout << "\n\t\t\t\tNo reservation requests to cancel." << endl;
         return false;
      }
   }
   // <------------------------end customer functionality to cancel booking------------->

   //<-----------------------------END CUSTOMER FUNCTIONALITY------------------------------------>
