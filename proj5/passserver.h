// TODO: test out all member functions
//   member functions:
//     constructor:
//     destructor:
//     load:
//     addUser:
//     addUser (move version):
//     removeUser:
//     changePassword:
//     find:
//     dump:
//     size:
//     write_to_file:
//     encrypt:

#ifndef PASSSERVER_H
#define PASSSERVER_H

#include "hashtable.h"

class PassServer {
  public:
    explicit PassServer(size_t size = 101);
    ~PassServer();
    bool load(const char * filename);
    bool addUser(std::pair<std::string, std::string> & kv);
    bool addUser(std::pair<std::string, std::string> && kv);
    bool removeUser(const std::string & K);
    bool changePassword(const std::pair<std::string, std::string> & p,
        const std::string & newpassword);
    bool find(const std::string & user);
    void dump();
    size_t size();
    bool write_to_file(const char * filename);

  private:
    std::string encrypt(const std::string & str);
    // member data
    cop4530::HashTable<std::string, std::string> hashtable;
}

#include "passserver.cpp"

#endif
