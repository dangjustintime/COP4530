#include "hashtable.h"
//#include "passserver.h"

int main() {
  cop4530::HashTable<std::string, std::string> a;
  std::pair<std::string, std::string> p1("foo", "bar");

  a.insert(p1);

  a.dump();

  return 0;
}
