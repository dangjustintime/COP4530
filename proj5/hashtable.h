// TODO: test out all member functions
//   member functions
//      constructor:          WORKS
//      destructor:
//      contains:
//      match:
//      insert:
//      insert(move version):
//      remove:
//      clear:
//      load:
//      dump:
//      size:                 WORKS
//      write_to_file:
//      makeEmpty:
//      rehash:
//      myhash:

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>

namespace cop4530 {
// maux_prime is used by the helpful functions provided
// tlo you.
static const unsigned int max_prime = 1301081;
// the default_capacity is used if the initial capacity 
// of the underlying vector of the hash table is zero. 
static const unsigned int default_capacity = 11;
  
template <typename K>
class HashObj {
  public:
    size_t operator()(const K & k) const;
};

template <typename K, typename V>
class HashTable {
  public:
    explicit HashTable(size_t size = 101);
    ~HashTable();
    bool contains(const K & k);
    bool match(const std::pair<K,V> & kv) const;
    bool insert(const std::pair<K,V> & kv);
    bool insert(std::pair<K,V> && kv);
    bool remove(const K & k);
    void clear();
    bool load(const char * filename);
    void dump();
    size_t size();
    bool write_to_file(const char * filename);
  
  private:
    void makeEmpty();
    void rehash();
    size_t myhash(const K & k) const;
    unsigned long prime_below(unsigned long n);
    void setPrimes(std::vector<unsigned long> & vprimes);
    // member data
    std::vector<std::list<std::pair<K,V>>> theLists;
    size_t currentSize;
};

#include "hashtable.hpp"

}


#endif
