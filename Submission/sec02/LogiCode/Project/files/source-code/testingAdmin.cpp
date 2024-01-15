#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Assume Admin is similar to User
class Admin {
public:
  string adminID;
  string name;
  string position;
  string phoneNo;

  Admin() {}

  Admin(const string &adminID, const string &name, const string &position,
        const string &phoneNo)
      : adminID(adminID), name(name), position(position), phoneNo(phoneNo) {}
};

class User {
public:
  string name;
  string position;
  string username;
  string password;

  User() {}
  User(string n, string p, string u, string pwd)
      : name(n), position(p), username(u), password(pwd) {}

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

  UserNode() : user(), left(nullptr), right(nullptr) {}
  UserNode(const User &u, UserNode *l, UserNode *r)
      : user(u), left(l), right(r) {}
};

class UserAuthentication {
private:
  UserNode *root;

public:
  UserAuthentication() : root(nullptr) {}

  void addUser(string n, string p, string u, string pwd) {
    root = addUserRecursive(root, User(n, p, u, pwd));
  }

  bool authenticateUser(string enteredUsername, string enteredPassword) {
    return authenticateUserRecursive(root, enteredUsername, enteredPassword);
  }

private:
  UserNode *addUserRecursive(UserNode *node, const User &user) {
    if (node == nullptr) {
      return new UserNode(user, nullptr, nullptr);
    }

    if (user.getUsername() < node->user.getUsername()) {
      node->left = addUserRecursive(node->left, user);
    } else if (user.getUsername() > node->user.getUsername()) {
      node->right = addUserRecursive(node->right, user);
    }

    return node;
  }

  bool authenticateUserRecursive(UserNode *node, string enteredUsername,
                                 string enteredPassword) {
    if (node == nullptr) {
      return false;
    }

    if (enteredUsername == node->user.getUsername() &&
        enteredPassword == node->user.getPassword()) {
      return true;
    } else if (enteredUsername < node->user.getUsername()) {
      return authenticateUserRecursive(node->left, enteredUsername,
                                       enteredPassword);
    } else {
      return authenticateUserRecursive(node->right, enteredUsername,
                                       enteredPassword);
    }
  }
};

int main() {
  UserAuthentication auth;
  const int SIZE = 50;

  ifstream inFile("admin.txt");

  int count = 0;
  string name, position, username, password;
  while (count < SIZE && getline(inFile, name, ',')) {
    inFile >> position;
    inFile >> username;
    inFile >> password;
    inFile.ignore();

    // Add user to the binary search tree using the UserAuthentication instance
    auth.addUser(name, position, username, password);
    count++;
  }
  inFile.close();

  // Perform user authentication
  string enteredUsername, enteredPassword;
  cout << "Enter username: ";
  cin >> enteredUsername;
  cout << "Enter password: ";
  cin >> enteredPassword;

  if (auth.authenticateUser(enteredUsername, enteredPassword)) {
    cout << "Authentication successful!" << endl;
  } else {
    cout << "Invalid username or password." << endl;
  }

  return 0;
}
