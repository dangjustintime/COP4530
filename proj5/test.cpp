#include "passserver.h"

int main() { 
  PassServer a;
  std::pair<std::string, std::string> p1("goo", "haa");
  std::pair<std::string, std::string> p2("too", "xaa");
  std::pair<std::string, std::string> p3("hoo", "zaa");
  std::pair<std::string, std::string> p4("koo", "qaa");

  a.addUser(p1);
  a.addUser(p2);
  a.addUser(p3);
  a.addUser(p4);
  
  a.write_to_file("test2");

  a.dump();

  std::cout << a.size() << std::endl;
}
