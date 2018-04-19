PassServer::PassServer(size_t size = 101) {};
PassServer::~PassServer() {};
PassServer::bool load(const char * filename) {};
PassServer::bool addUser(std::pair<std::string, std::string> & kv) {};
PassServer::bool addUser(std::pair<std::string, std::string> && kv) {};
PassServer::bool removeUser(const std::string & K) {};
PassServer::bool changePassword(const std::pair<std::string, std::string> & p,
    const std::string & newpassword) {};
PassServer::bool find(const std::string & user) {};
PassServer::void dump() {};
PassServer::size_t size() {};
  PassServer::bool write_to_file(const char * filename) {};
PassServer::std::string encrypt(const std::string & str) {};
