#include "hashtable.h"
//#include "passserver.h"

int main() {
  cop4530::HashTable<std::string, std::string> a;
  std::pair<std::string, std::string> p1("foo", "bar");
  std::pair<std::string, std::string> p2("moo", "tar");
  std::pair<std::string, std::string> p3("joo", "sar");
  std::pair<std::string, std::string> p4("roo", "car");
  std::pair<std::string, std::string> p5("zoo", "kar");

  a.insert(p1);
  a.insert(p2);
  a.insert(p3);
  a.insert(p4);
  a.insert(p5);

  a.dump();

  return 0;
}
