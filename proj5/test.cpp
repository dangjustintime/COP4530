#include "passserver.h"

int main() {
  cop4530::HashTable<std::string, std::string> hash1;
  std::pair<std::string, std::string> pair1("foo", "bar");
  std::cout << hash1.size() << std::endl;
  hash1.insert(pair1);
  return 0;
}
