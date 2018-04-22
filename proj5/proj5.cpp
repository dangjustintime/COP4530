#include "passserver.h"

#include <cctype>


void Menu() {
  std::cout << "\n\n";
  std::cout << "l - Load From File" << std::endl;
  std::cout << "a - Add User" << std::endl;
  std::cout << "r - Remove User" << std::endl;
  std::cout << "c - Change User Password" << std::endl;
  std::cout << "f - Find User" << std::endl;
  std::cout << "d - Dump HashTable" << std::endl;
  std::cout << "s - HashTable Size" << std::endl;
  std::cout << "w - Write to Password File" << std::endl;
  std::cout << "x - Exit program" << std::endl;
  std::cout << "\nEnter choice : ";
}

int main() {
  PassServer passserver;
  char menuChoice;
  std::string filename;
  std::string username;
  std::string password;
  std::string newPassword;


  while (1) {
    Menu();
    std::cin >> menuChoice;
    switch (tolower(menuChoice)) {
      case 'l':
        std::cout << "Enter file name: ";
        std::cin >> filename;
        if (passserver.load(filename.c_str())) {
          std::cout << "LOAD SUCCESSFUL" << std::endl;
        } else {
          std::cout << "LOAD FAILED" << std::endl;
        }
        break;
      case 'a':
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        if (passserver.addUser(std::make_pair(username, password))) {
          std::cout << "USER ADDED"<< std::endl;
        } else {
          std::cout << "USER NOT ADDED"<< std::endl;
        }
        break;
      case 'r':
        std::cout << "Enter username: ";
        std::cin >> username;
        if (passserver.removeUser(username)) {
          std::cout << "USER REMOVED"<< std::endl;
        } else {
          std::cout << "USER NOT REMOVED"<< std::endl;
        }
        break;
      case 'c': 
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter old password: ";
        std::cin >> password;
        std::cout << "Enter new password: ";
        std::cin >> newPassword;
        if (passserver.changePassword(std::make_pair(username, password),
              newPassword)) {
          std::cout << "PASSWORD CHANGED"<< std::endl;
        } else {
          std::cout << "PASSWORD NOT CHANGED"<< std::endl;
        }
        break;
      case 'f':
        std::cout << "Enter username: ";
        std::cin >> username;
        if (passserver.find(username)) {
          std::cout << "USER FOUND"<< std::endl;
        } else {
          std::cout << "USER NOT FOUND"<< std::endl;
        }
        break;
      case 'd':
        passserver.dump();
        break;
      case 's':
        std::cout << "Size = " << passserver.size() << std::endl;
        break;
      case 'w':
        std::cout << "Enter file name: ";
        std::cin >> filename;
        if (passserver.write_to_file(filename.c_str())) {
          std::cout << "FILE WRITTEN" << std::endl;
        } else {
          std::cout << "FILE NOT WRITTEN" << std::endl;
        }
        break;
      case 'x':
        std::cout << "EXITING PROGRAM" << std::endl;
        return 0;
      default:
        std::cout << "NOT A VALID CHOICE" << std::endl;
        break;
    }
  }

  return 0;
}
