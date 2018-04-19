// constructor
// create a hash table of the specified size. You just need to pass this size
// parameter to the constructor of the HashTable. Therefore, the real hash
// table size could be different from the parameter size (because prime_below()
// will be called in the constructor of the HashTable).)
PassServer::PassServer(size_t size = 101) { hashtable(size); };

// destructor
// you need to decide what you should do based on your design of PassServer
// (how you developer the adaptor class based on the adaptee hashtable).
// In essence, we do not want to have a memory leak.
PassServer::~PassServer() { ~hashtable(); };


bool PassServer::load(const char * filename) {
  return hashtable.load(filename);
};

bool PassServer::addUser(std::pair<std::string, std::string> & kv) {
  return hashtable.insert(kv);
};

bool PassServer::addUser(std::pair<std::string, std::string> && kv) {
  return hashtable.insert(std::move(kv));
};

bool PassServer::removeUser(const std::string & K) {
  return hashtable.remove(K); 
};

bool PassServer::changePassword(const std::pair<std::string, std::string> & p,
    const std::string & newpassword) {
  std::pair<std:string, std::string> newPair(p.first, newpassword);
  return hashtable.insert(newPair);
};

bool PassServer::find(const std::string & user) {
  return hashtable.contains(user);
};

void PassServer::dump() { return hashtable.dump(); };

size_t PassServer::size() { return hashtable.size(); };

bool PassServer::write_to_file(const char * filename) {
  return hashtable.write_to_file(filename);
};

std::string PassServer::encrypt(const std::string & str) {

};
