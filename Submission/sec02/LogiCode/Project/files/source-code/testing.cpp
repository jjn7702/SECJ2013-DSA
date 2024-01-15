#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Define a basic structure for a user
class User {
  string name;
  string position;
  string username;
  string password;

public:
  User(){};
  User(string n, string p, string u, string pwd)
      : name(n), position(p), username(u), password(pwd){};

  // Getter methods for user attributes
  string getName() const { return name; }
  string getPosition() const { return position; }
  string getUsername() const { return username; }
  string getPassword() const { return password; }
};

class UserNode {
public:
  User user;
  UserNode *left;
  UserNode *right;

  UserNode()
      : user(), left(nullptr), right(nullptr){}; // Add default constructor
  UserNode(const User &u, UserNode *l, UserNode *r)
      : user(u), left(l),
        right(r){}; // Add constructor for const user, left, and right nodes
};

class UserAuthentication {
private:
  UserNode *root;

public:
  UserAuthentication() : root(nullptr) {}

  // Method to add a new user to the binary search tree
  void addUser(string n, string p, string u, string pwd) {
    root = addUserRecursive(root, User(n, p, u, pwd));
  }

  // Method to read users from a file and add them to the binary search tree
  void addUsersFromFile(const string &filename) {
    ifstream file(filename);
    if (file.is_open()) {
      string line;
      while (getline(file, line)) {
        // Assuming file format: name position username password
        string name, position, username, password;
        istringstream iss(line);
        if (iss >> name >> position >> username >> password) {
          addUser(name, position, username, password);
        }
      }
      file.close();
    } else {
      cout << "Error: Unable to open file." << endl;
    }
  }
