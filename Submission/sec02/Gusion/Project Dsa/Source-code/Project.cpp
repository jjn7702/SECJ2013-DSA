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

 //<----------------------------- ADMIN FUNCTIONALITY------------------------------------>

   // <------------------------start admin functionality to approve reserve booking------------->
   void approveReservation()
   {
      displayRequestedBookings();

      int numToApprove;
      cout << "\n\t\t\t\tEnter the number of reservations to approve (0 to cancel): ";
      cin >> numToApprove;

      if (numToApprove > 0)
      {
         int count = 0;

         // Open request.txt for reading and writing
         ifstream requestFile(requestFileName);
         ofstream tempFile("temp.txt");

         if (requestFile.is_open() && tempFile.is_open())
         {
            // Read and process existing reservations in request.txt
            string name, destination, airline, ic;
            int day, month, year;

            while (requestFile >> name >> day >> month >> year >> destination >> airline >> ic)
            {
               if (!requestFile.fail())
               {
                  if (count < numToApprove)
                  {
                     // Approve reservations from request.txt
                     Cust newBooking(name, day, month, year, destination, airline, ic);
                     doneBooking.enqueue(newBooking);
                     updateBookingFile();

                     count++;
                  }
                  else
                  {
                     // Convert date values to strings before writing to tempFile
                     tempFile << name << " " << to_string(day) << " " << to_string(month) << " " << to_string(year) << " "
                              << destination << " " << airline << " " << ic << "\n";
                  }
               }
               else
               {
                  break; // Stop reading if there are no more reservations in the file
               }
            }

            requestFile.close();
            tempFile.close();

            // Rename tempFile to request.txt to overwrite the original file
            if (remove(requestFileName.c_str()) != 0)
               perror("Error deleting file");
            else
            {
               if (rename("temp.txt", requestFileName.c_str()) != 0)
                  perror("Error renaming file");
            }

            // Clear the doneBooking queue after processing approvals
            while (!reservationRequests.isEmpty())
            {
               reservationRequests.dequeue();
            }

            // Display a message for successful approvals
            cout << "\n\t\t\t\t" << count << " reservation(s) approved and removed from request.txt." << endl;
         }
         else
         {
            cout << "\n\t\t\t\tError opening files for reading/writing." << endl;
         }
      }
      else
      {
         cout << "\n\t\t\t\tReservations not approved." << endl;
      }
   }

   // <------------------------end admin functionality to approve reserve booking------------->

// <------------------------admin functionality to search for booking------------->
   void searchByICNumber(string icNumber) const
   {
      cout << "\n\t\t\t\tBooking details for IC Number " << icNumber << ":" << endl;
      bool found = false;

      BookingQueue::Node *current = doneBooking.getFrontNode();
      while (current != nullptr)
      {
         if (current->data.getIcNum() == icNumber)
         {
            cout << "\t\t---------------------------------------------------------------------------------------" << endl;
            cout << left << setw(5) << "\t" << setw(15) << "  \tName"
                 << "  Date of Booking"
                 << "\t     Destination"
                 << "\t   Airlines"
                    "\t   IC Number"
                 << endl;
            cout << "\t\t---------------------------------------------------------------------------------------" << endl;

            current->data.displayBookingInfo();
            cout << "\t\t---------------------------------------------------------------------------------------" << endl;

            found = true;
         }

         current = current->next;
      }

      if (!found)
      {
         cout << "\n\t\t\t\tNo bookings found for IC Number " << icNumber << "." << endl;
      }
   }
   // <------------------------end admin functionality to search for booking------------->

      bool removeBookingByIC(string icNumber)
   {
      BookingQueue::Node *current = doneBooking.getFrontNode();
      BookingQueue::Node *previous = nullptr;

      while (current != nullptr)
      {
         if (current->data.getIcNum() == icNumber)
         {
            // Found the booking with the specified IC number
            if (previous != nullptr)
            {
               // If the node to be removed is not the first node
               previous->next = current->next;
            }
            else
            {
               // If the node to be removed is the first node
               doneBooking.dequeue();
            }

            delete current;
            cout << "\n\t\t\t\tBooking for IC Number " << icNumber << " removed successfully." << endl;
            return true;
         }

         // Move to the next node
         previous = current;
         current = current->next;
      }

      cout << "\n\t\t\t\tBooking for IC Number " << icNumber << " not found." << endl;
      return false;
   }
   // <------------------------end admin functionality to remove for booking------------->

   //<----------------------------- END ADMIN FUNCTIONALITY------------------------------------>