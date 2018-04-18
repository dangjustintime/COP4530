#include "hashtable.h"

int main() {
  cop4530::HashTable<int, char> hash1;
  std::pair<int, char> pair1(1, 'c');
  std::cout << hash1.size() << std::endl;
  hash1.insert(pair1);
  return 0;
}
