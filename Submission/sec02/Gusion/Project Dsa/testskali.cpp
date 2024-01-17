// Assignment 2 - SECJ2013 - 23241 (project.cpp)
// Group Members:
// 1. Muhammad Iman Firdaus Bin Baharuddin A22EC0216
// 2. Muhammad Ariff Danish Bin Hashnan A22EC0204
// 3. Che Marhumi Bin Che AB Rahim A22EC0147
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Cust
{
private:
   string name, destination, airline;
   int day, month, year, Ic;

public:
   Cust() : day(0), month(0), year(0), Ic(0) {}

   Cust(string n, int d, int m, int y, string dest, string a, int icee)
       : name(n), day(d), month(m), year(y), destination(dest), airline(a), Ic(icee) {}

   void displayBookingInfo() const
   {
      cout << "\t\t" << left << setw(5) << setw(15) << name << setw(2) << day << " / " << setw(2) << month
           << " / " << setw(15) << year << setw(19) << destination << setw(19) << airline << setw(19) << Ic << endl;
   }

   int getIcNum()
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

public:
   BookingSystem() {}

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

   //---------------------------------------------------------------------------------------------------------

   //<----------------------------- ADMIN FUNCTIONALITY------------------------------------>

   // <------------------------start admin functionality to approve reserve booking------------->
   void approveReservation()
   {
      if (!reservationRequests.isEmpty())
      {
         displayRequestedBookings();

         cout << "\n\t\t\t\tDo you want to approve all reservations? (1 for Yes, 0 for No): ";
         int decision;
         cin >> decision;

         if (decision == 1)
         {
            while (!reservationRequests.isEmpty())
            {
               Cust booking = reservationRequests.getFront();
               reservationRequests.dequeue();
               doneBooking.enqueue(booking);
            }
            cout << "\n\t\t\t\tAll reservations approved." << endl;
         }
         else
         {
            cout << "\n\t\t\t\tReservations not approved." << endl;
         }
      }
      else
      {
         cout << "\n\t\t\t\tNo reservation requests to approve." << endl;
      }
   }
   // <------------------------end admin functionality to approve reserve booking------------->

   // <------------------------admin functionality to search for booking------------->
   void searchByICNumber(int icNumber) const
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

   // <------------------------admin functionality to remove for booking------------->
   bool removeBookingByIC(int icNumber)
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

   //<---------------------------------------DISPLAY INFORMATION FUNCTION-------------------------->
   void displayAllBookings() const
   {
      cout << "\t\t---------------------------------------------------------------------------------------" << endl;
      cout << left << setw(5) << "\t" << setw(15) << "  \tName"
           << "  Date of Booking"
           << "\t     Destination"
           << "\t   Airlines"
              "\t   IC Number"
           << endl;
      cout << "\t\t---------------------------------------------------------------------------------------" << endl;

      displayQueueBookings(doneBooking);

      cout << "\t\t---------------------------------------------------------------------------------------" << endl;
   }

   void displayRequestedBookings() const
   {
      cout << "\t\t---------------------------------------------------------------------------------------" << endl;
      cout << left << setw(5) << "\t" << setw(15) << "  \tName"
           << "  Date of Booking"
           << "\t     Destination"
           << "\t   Airlines"
              "\t   IC Number"
           << endl;
      cout << "\t\t---------------------------------------------------------------------------------------" << endl;

      displayQueueBookings(reservationRequests);

      cout << "\t\t---------------------------------------------------------------------------------------" << endl;
   }

   void displayQueueBookings(const BookingQueue &queue) const
   {
      BookingQueue::Node *current = queue.getFrontNode(); // Use the public method to get the front node

      while (current != nullptr)
      {
         current->data.displayBookingInfo(); // Display the booking info
         current = current->next;            // Move to the next node
      }
   }
   //<---------------------------------------END OF DISPLAY INFORMATION FUNCTION-------------------------->
};

// <------------------------extract data from booking.txt------------->
void extractData(BookingSystem &bookingSystem)
{
   string line;
   fstream readFile("booking.txt", ios::in);

   if (!readFile)
   {
      cout << "Cannot open file, something went wrong?\n";
      return;
   }
   else
   {
      while (getline(readFile, line))
      {
         stringstream ss(line);
         string name, destination, airline;
         int day, month, year, icee;

         ss >> name;
         while (ss >> ws && !isdigit(ss.peek()))
         {
            string word;
            ss >> word;
            name += ' ' + word;
         }

         ss >> day;
         ss.ignore();
         ss >> month;
         ss.ignore();
         ss >> year;

         ss >> destination >> airline >> icee;

         if (!ss.fail())
         {
            Cust newBooking(name, day, month, year, destination, airline, icee);
            bookingSystem.addBooking(newBooking);
         }
         else
         {
            cout << "Invalid data format in line: \n"
                 << endl;
         }
      }

      // close file
      readFile.close();
   }
}
// <------------------------end extract data from booking.txt------------->

// <------------------------start customer menu------------->
void customerMenu(BookingSystem &bookingSystem)
{
   int choice;
   do
   {
      cout << "\n\t\t\t\t   +================== CUSTOMER MENU ===================+" << endl;
      cout << "\t\t\t\t   +1. \t\tRequest Reservation"
           << "\t\t\t+" << endl;
      cout << "\t\t\t\t   +2. \t\tCancel Reservation (Undo)"
           << "\t\t+" << endl;
      cout << "\t\t\t\t   +3. \t\tBack to Main Menu"
           << "\t\t\t+" << endl;
      cout << "\t\t\t\t   +====================================================+" << endl;
      cout << "\n\n\t\t\t\t\t\tEnter your choice: ";

      cin >> choice;

      switch (choice)
      {
      case 1:
      {
         // Request Reservation
         string name, destination, airline;
         int day, month, year, ic;

         cout << "\t\t\t\tEnter customer name: ";
         cin.ignore();
         getline(cin, name);

         cout << "\n\t\t\t\tEnter date (day month year): " << endl;
         cout << "\t\t\t\tDay : ";
         cin >> day;
         cout << "\t\t\t\tMonth :";
         cin >> month;
         cout << "\t\t\t\tYear :";
         cin >> year;

         cout << "\n\t\t\t\tEnter destination: ";
         cin.ignore();
         getline(cin, destination);

         cout << "\n\t\t\t\tEnter airline: ";
         getline(cin, airline);

         cout << "\n\t\t\t\tEnter IC number: ";
         cin >> ic;

         // Create a Cust object with the provided details
         Cust newBooking(name, day, month, year, destination, airline, ic);

         // Enqueue the booking into reservationRequests
         bookingSystem.reserveBooking(newBooking);

         cout << "\n\t\t\t\tReservation request sent successfully." << endl;
         break;
      }
      case 2:
      {
         // Cancel Reservation (Undo)
         int icNumber;
         cout << "\n\t\t\t\tEnter the IC Number you want to undo: ";
         cin >> icNumber;
         bookingSystem.cancelRecentReservation();
         break;
      }
      case 3:
         cout << "\t\t\t\tReturning to the main menu." << endl;
         break;
      default:
         cout << "\t\t\t\tInvalid choice. Please try again." << endl;
      }
   } while (choice != 3);
}
// <------------------------end customer menu------------->

// <------------------------start admin menu------------->
void adminMenu(BookingSystem &bookingSystem)
{
   int choice;
   do
   {
      cout << "\n\t\t\t\t   +================== ADMIN MENU ===================+" << endl;
      cout << "\t\t\t\t   +1. \t\tApprove Reservation"
           << "\t\t     +" << endl;
      cout << "\t\t\t\t   +2. \t\tDisplay All Bookings"
           << "\t\t     +" << endl;
      cout << "\t\t\t\t   +3. \t\tBack to Main Menu"
           << "\t\t     +" << endl;
      cout << "\t\t\t\t   +4. \t\tSearch Customer"
           << "\t\t\t     +" << endl;
      cout << "\t\t\t\t   +5. \t\tRemove Booking"
           << "\t\t\t     +" << endl;
      cout << "\t\t\t\t   +=================================================+" << endl;
      cout << "\n\n\t\t\t\t\t\tEnter your choice: ";
      cin.ignore();
      cin >> choice;

      switch (choice)
      {
      case 1:
         // Approve Reservation (Dequeue)
         // ...
         bookingSystem.approveReservation();
         break;
      case 2:
         // Display All Bookings
         bookingSystem.displayAllBookings();
         break;
      case 3:
         cout << "\t\t\t\tReturning to the main menu." << endl;
         break;
      case 4:
         int icToSearch;
         cout << "\n\t\t\t\tEnter customer IC number to search: ";
         cin >> icToSearch;
         bookingSystem.searchByICNumber(icToSearch);
         break;
      case 5:
         int icNumToRemove;
         cout << "\t\t\t\tEnter customer IC number to remove from booking: ";
         cin >> icNumToRemove;
         bookingSystem.removeBookingByIC(icNumToRemove);
         break;
      default:
         cout << "\t\t\t\tInvalid choice. Please try again." << endl;
      }
   } while (choice != 3);
}
// <------------------------end admin menu------------->

int main()
{
   BookingSystem bookingSystem;
   extractData(bookingSystem);

   int userType;
   do
   {
      cout << "\n\t\t\t\t   +================================================+" << endl;
      cout << "\n\t\t\t\t   +     WELCOME TO AIRLINE RESERVATION SYSTEM      +" << endl;
      cout << "\n\t\t\t\t   +================== MAIN MENU ===================+" << endl;
      cout << "\t\t\t\t   +1. \t\t\tADMIN/STAFF"
           << "\t\t    +" << endl;
      cout << "\t\t\t\t   +2. \t\t\tCUSTOMER"
           << "\t\t    +" << endl;
      cout << "\t\t\t\t   +3. \t\t\tExit"
           << "\t\t\t    +" << endl;
      cout << "\t\t\t\t   +================================================+" << endl;
      cout << "\n\n\t\t\t\t\t\tEnter your choice: ";
      cin >> userType;

      switch (userType)
      {
      case 1:
         // Admin
         adminMenu(bookingSystem);
         break;
      case 2:
         // Customer
         customerMenu(bookingSystem);
         break;
      case 3:
         cout << "\n\t\t\t\tExiting the program." << endl;
         break;
      default:
         cout << "\n\t\t\t\tInvalid choice. Please try again." << endl;
      }
   } while (userType != 3);
   system("pause");
   return 0;
}
