// TODO: implement encrypt member function with crypt() from GNU library 

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

// load
// load a password file into the HashTable object. Each line contains a pair of
// username and encrypted password
bool PassServer::load(const char * filename) {
  return hashtable.load(filename);
};


// addUser
// add a new username and password. The password passed in is in plaintext, it
// should be encrypted before insertion. The pair should not be added if the
// username already exists in the hash table
bool PassServer::addUser(std::pair<std::string, std::string> & kv) {

  return hashtable.insert(kv);
};


// addUser (move version)
bool PassServer::addUser(std::pair<std::string, std::string> && kv) {
  return hashtable.insert(std::move(kv));
};

// removeUser
// delete an existing user with username k
bool PassServer::removeUser(const std::string & K) {
  return hashtable.remove(K); 
};

// changePassword
// change an existing user's password. Note that both passwords passed in are
// in plaintext. They should be encrypted before you interact with the hash
// table. If the user is not in the hash table, return false. If p.second does
// not match the current password, return false. Also return false if the new
// password and the old password are the same (i.e., we cannot update the
// password)
bool PassServer::changePassword(const std::pair<std::string, std::string> & p,
    const std::string & newpassword) {
  std::pair<std:string, std::string> newPair(p.first, newpassword);
  return hashtable.insert(newPair);
};

// find
// check if a user exists (if user is in the hash table).
bool PassServer::find(const std::string & user) {
  return hashtable.contains(user);
};

// dump
// show the structure and contents of the HashTable object to the screen. Same
// format as the dump() function in the HashTable class template
void PassServer::dump() { return hashtable.dump(); };

// size
// return the size of the HashTable (the number of username/password pairs
// in the table).
size_t PassServer::size() { return hashtable.size(); };

// write_to_file
// save the username and password combination into a file. Same format as the
// write_to_file() function in the HashTable class template
bool PassServer::write_to_file(const char * filename) {
  return hashtable.write_to_file(filename);
};

// encrypt
// encrypt the parameter str and return the encrypted string.
std::string PassServer::encrypt(const std::string & str) {
};
