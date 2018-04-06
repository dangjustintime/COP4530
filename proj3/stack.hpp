//zero-argument constructor
template <typename T>
Stack<T>::Stack() {
	init();
};

//destrucletor
template <typename T>
Stack<T>::~Stack() {
	clear();	
};

//copy constructor
template <typename T>
Stack<T>::Stack(const Stack<T>& stack) {
	init();
	for(auto i = stack.stackList.begin(); i != stack.stackList.end(); i++) {
		push(*i);
	}
};

//move constructor
template <typename T>
Stack<T>::Stack(Stack<T>&& stack) : theSize{stack.theSize} {
	std::swap(stackList, stack.stackList);
	stack.theSize = 0;	
}

//copy assignment operator
template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>& stack) {
	stackList = stack.stackList;
	theSize = stack.theSize;
	return * this;
};

//move assignment operator
template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& stack) {
	std::swap(theSize, stack.theSize);
	std::swap(stackList, stack.stackList);
	return * this;
};

//initualize stack
template <typename T>
void Stack<T>::init() {
	theSize = 0;
};

//returns true if the Stack contains no elements, and false otherwise
template <typename T>
bool Stack<T>::empty() const {
	return theSize == 0;
};

//delete all elements from the stack
template <typename T>
void Stack<T>::clear() {
	for(int i = 0; i < theSize; i++) {
		stackList.pop_back();
	}
	theSize = 0;
}

//adds x to the stack (copy version)
template <typename T>
void Stack<T>::push(const T& x) {
	stackList.push_back(x);
	theSize++;
	std::cout << x << std::endl;
};

//adds x to the stack (move version)
template <typename T>
void Stack<T>::push(T && x) {
	stackList.push_back(std::move(x));
	theSize++;
	std::cout << x << std::endl;
};

//removes and discards the most recently added element of the stack
template <typename T>
void Stack<T>::pop() {
	if(theSize > 0) {
		stackList.pop_back();
		theSize--;
	}
};

//mutator that returns a reference to the most recently added element of the stack
template <typename T>
T& Stack<T>::top() {
	return stackList.back();	
};

//accessor that returns the most recently added element of the stack
template <typename T>
const T& Stack<T>::top() const {
	return stackList.back();
};

//returns the number of elements stored in the stack
template <typename T>
int Stack<T>::size() const {
	return theSize;
};

//prints elements of stack with delimiter
template <typename T>
void Stack<T>::print(std::ostream& os, char ofc) const {
	for(auto i = stackList.begin(); i != stackList.end(); i++) {
		os << *i << ofc;
	}
	os << std::endl;
};

//invokes the print() method to print
template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& a) {
	for(auto i = a.stackList.begin(); i != a.stackList.end(); i++) {
		os << *i << " ";
	}
		os << std::endl;
	return os;
};

//returns true if the two compared stacks have the same elements, in the same order
template <typename T>
bool operator==(const Stack<T>& a, const Stack<T>& b) {
	if(a.size() == b.size()) {
		auto bItr = b.stackList.begin();
		for(auto aItr = a.stackList.begin(); aItr != a.stackList.end(); aItr++) {
			if(*aItr != *bItr) return false;
			bItr++;
		}
		return true;
	} else {
		return false;
	}
};

//opposite of operator==()
template <typename T>
bool operator!=(const Stack<T>& a, const Stack<T>& b) {
	return !(a == b);
};

//returns true if every element in stack a is less than stack b
template <typename T>
bool operator<=(const Stack<T>& a, const Stack<T>& b) {
	auto bItr = b.stackList.begin();
	for(auto aItr = a.stackList.begin(); aItr != a.stackList.end(); aItr++) {
		if(*aItr > *bItr) return false;
		bItr++;
	}
	return true;
}
