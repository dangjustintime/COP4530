// TODO: implement rehash function

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

//Sets all prime number indexes to 1. Called by method prime_below(n) 
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

// private interface
// myhash
template <typename K, typename V>
size_t HashTable<K, V>::myhash(const K & k) {
  static std::hash<K> hf;
  return hf(k) % this->theList.size();
}
// makeEmpty
template <typename K, typename V>
void HashTable<K, V>::makeEmpty() {
  for(auto & thisList: theLists) {
    thisList.clear();
  }
}
// contains
template <typename K, typename V>
bool HashTable<K, V>::contains(const K & k) {
  auto & whichList = theLists[myhash(k)];
  return find(begin(whichList), end(whichList), k) != end(whichList);
}
// rehash
template <typename K, typename V>
void HashTable<K, V>::rehash() {
  
}

// public interface
// constructor
template <typename K, typename V>
HashTable<K, V>::HashTable(size_t size) : currentSize{size} {
  theLists(size);
}
