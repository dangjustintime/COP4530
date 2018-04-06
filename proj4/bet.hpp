// default zero-parameter constructor
template <typename T>
BET<T>::BET() : root{nullptr} {}

template <typename T>
BET<T>::BET(std::string postfix) {}

// copy constructor
template <typename T>
BET<T>::BET(const BET& bet) {
  root = new BinaryNode(bet.root->data);
}

//insertions
