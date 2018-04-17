#include "hashtable.h"

int main() {
  std::pair<std::string, int> p1("blah", 2);
  cop4530::HashTable<std::string, int> a;

  std::cout << a.size() << std::endl;
  
  a.insert(p1);

  return 0;
}
