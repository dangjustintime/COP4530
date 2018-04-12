// private interface
// makeEmpty
// delete all elements in the hash table. The public interface
// clear() will call this function.
template <typename K, typename V>
void HashTable<K, V>::makeEmpty() {
  for(auto & thisList: theLists) {
    thisList.clear();
  }
}
// rehash
// Called when the number of elements in the hash table is greater
// than the size of the vector.
template <typename K, typename V>
void HashTable<K, V>::rehash() {
  std::vector<std::list<V>> oldLists = theLists;
  theLists.resize(prime_below(2 * theLists.size()));
  for (auto & thisList : theLists) {
    thisList.clear();
  }
  currentSize = 0;
  for (auto thisList : oldLists) {
    for (auto & x : thisList) {
      insert(std::move(x));
    }
  }
}
// myhash
// return the index of the vector entry where k should be stored.
template <typename K, typename V>
size_t HashTable<K, V>::myhash(const K & k) {
  static std::hash<K> hf;
  return hf(k) % this->theList.size();
}
// prime_below
// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below (unsigned long n)
{
  if (n > max_prime)
    {
      std::cerr << "** input too large for prime_below()\n";
      return 0;
    }
  if (n == max_prime)
    {
      return max_prime;
    }
  if (n <= 1)
    {
		std::cerr << "** input too small \n";
      return 0;
    }

  // now: 2 <= n < max_prime
  std::vector <unsigned long> v (n+1);
  setPrimes(v);
  while (n > 2)
    {
      if (v[n] == 1)
	return n;
      --n;
    }

  return 2;
}
// setPrimes
// Sets all prime number indexes to 1. Called by method prime_below(n) 
template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes)
{
  int i = 0;
  int j = 0;

  vprimes[0] = 0;
  vprimes[1] = 0;
  int n = vprimes.capacity();

  for (i = 2; i < n; ++i)
    vprimes[i] = 1;

  for( i = 2; i*i < n; ++i)
    {
      if (vprimes[i] == 1)
        for(j = i + i ; j < n; j += i)
          vprimes[j] = 0;
    }
}
// public interface
// constructor
// Create a hash table, where the size of the vector is set to
// prime_below(size) (where size is default  to 101), where
// prime_below() is a private member function of the HashTable and
// provided to you.)))
template <typename K, typename V>
HashTable<K, V>::HashTable(size_t size) : currentSize{size} {
  theLists(size);
}
// destructor
// Delete all elements in hash table.
template <typename K, typename V>
HashTable<K, V>::~HashTable() {}
// contains
// check if key k is in the hash table.
template <typename K, typename V>
bool HashTable<K, V>::contains(const K & k) {
  auto & whichList = theLists[myhash(k)];
  return find(begin(whichList), end(whichList), k) != end(whichList);
}
// match
// check if key-value pair is in the hash table.
template<typename K, typename V>
bool HashTable<K, V>::match(const std::pair<K, V> & kv) const {}
// insert
// add  the key-value pair kv into the hash table. Don't add if kv
// is already in the hash table. If the key is the hash table but
// with a different value, the value should be updated to the new one
// with kv. Return true if kv is inserted or the value is updated;
// return false otherwise (i.e., if kv is in the hash table).)
template <typename K, typename V>
bool HashTable<K, V>::insert(const std::pair<K, V> & kv) {}
// insert (move version)
template <typename K, typename V>
bool HashTable<K, V>::insert(std::pair<K, V> && kv) {}
// remove
// delete the key k and the corresponding value if it is in the hash
// table. Return true if k is deleted, return false otherwise (i.e.,
// if key k is not in the hash table).)
template <typename K, typename V>
bool HashTable<K, V>::remove(const K & k) {}
// clear
// delete all elements in the hash table
template <typename K, typename V>
void HashTable<K, V>::clear() {}
// load
// load the content of the file with name filename into the hash
// table. In the file, each line contains a single pair of key and
// value, separated by a white space.
template <typename K, typename V>
bool HashTable<K, V>::load(const char * filename) {}
// dump
// display all entries in the hash table. If an entry contains
// multiple key-value pairs, separate them by a semicolon character (:)
// (see the provided executable for the exact output format).))
template <typename K, typename V>
void HashTable<K, V>::dump() {}
// size
// return the number of elements in the hash table
template <typename K, typename V>
size_t HashTable<K, V>::size() {}
// write to file
// write all elements in the hash table into a file with name filename.
// Similar to the file format in the load function, each line contains
// a pair of key-value pair, separated by a white space.
template <typename K, typename V>
bool HashTable<K, V>::write_to_file(const char * filename) {}
