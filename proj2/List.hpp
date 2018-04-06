#include "List.h"

//const_iterator
template <typename T>
List<T>::const_iterator::const_iterator() : current{nullptr} {}

template <typename T>
const T & List<T>::const_iterator::operator*() const {
	return retrieve();
}

template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++() {
	current = current->next;
	return *this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int) {
	const_iterator old = *this;
	++(*this);
	return old;
}

template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator--() {
	current = current->prev;
	return *this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int) {
	const_iterator old = *this;
	--(*this);
	return old;
}

template <typename T>
bool List<T>::const_iterator::operator==(const const_iterator &rhs) const {
	return current == rhs.current;
}

template <typename T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const {
	return !(*this == rhs);
}

template <typename T>
List<T>::const_iterator::const_iterator(Node *p) : current{p} {}

// retrieve the element refers to
template <typename T>
T & List<T>::const_iterator::retrieve() const {
	return current->data;
}

template <typename T>
T & List<T>::iterator::operator*() {
	return const_iterator::retrieve();
}

template <typename T>
const T & List<T>::iterator::operator*() const {
	return const_iterator::operator*();
}

template <typename T>
typename List<T>::iterator & List<T>::iterator::operator++() {
	this->current = this->current->next;
	return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int) {
	iterator old = *this;
	++(*this);
	return old;
}

template <typename T>
typename List<T>::iterator & List<T>::iterator::operator--() {
	this->current = this->current->prev;
	return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator--(int) {
	iterator old = *this;
	--(*this);
	return old;
}

template <typename T>
List<T>::iterator::iterator(Node *p) : const_iterator{p} {}


// default zero parameter constructor
template <typename T>
List<T>::List() {
	init();
}

//copy constructor
template <typename T>
List<T>::List(const List & rhs) {
	init();
	for(auto x : rhs) {
		push_back(x);
	}
}

//move constructor
template <typename T>
List<T>::List(List && rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail} {
	rhs.theSize = 0;
	rhs.head = nullptr;
	rhs.tail = nullptr;
}


// num elements with value of val
template <typename T>
List<T>::List(int num, const T& val) {
	init();
	for(int i = 0; i < num; i++) {
		push_back(val);
	}
}

// constructs with elements [start, end)
template <typename T>
List<T>::List(const_iterator start, const_iterator end) {
	init();
	for(auto itr = start; itr != end; itr++) {
		push_back(*itr);
	}
}

//destructor
template <typename T>
List<T>::~List() {
	clear();
	delete head;
	delete tail;
}

// copy assignment operator
template <typename T>
const List<T> & List<T>::operator=(const List & rhs) {
	return *this;
}

//move assignment operator
template <typename T>
List<T> & List<T>::operator=(List && rhs) {
	std::swap(theSize, rhs.theSize);
	std::swap(head, rhs.head);
	std::swap(tail, rhs.tail);
	return *this;
}

// reference to the first element
template <typename T>
T & List<T>::front() {
	return *begin();
}

//  const refrence to the first element
template <typename T>
const T & List<T>::front() const {
	return *begin();
}

// reference to the last element
template <typename T>
T & List<T>::back() {
	return *--end();
}

// const reference to the last element
template <typename T>
const T & List<T>::back() const {
	return *--end();
} 


//return size
template <typename T>
int List<T>::size() const {
	return theSize;
}

//check if empty
template <typename T>
bool List<T>::empty() const {
	return size() == 0;
}

// insert to the beginning
template <typename T>
void List<T>::push_front(const T & val) {
	insert(begin(), val);
}

// move version of insert
template <typename T>
void List<T>::push_front(T && val) {
	insert(begin(), std::move(val));
}

// insert to the end
template <typename T>
void List<T>::push_back(const T & val) {
	insert(end(), val);
}

// move version of insert
template <typename T>
void List<T>::push_back(T && val) {
	insert(end(), std::move(val));
}

// delete first element
template <typename T>
void List<T>::pop_front() {
	erase(begin());
}

// delete last element
template <typename T>
void List<T>::pop_back() {
	erase(--end());
}

// remove all elements with value = val
template <typename T>
void List<T>::remove(const T &val) {
	for(auto itr = begin(); itr != end(); itr++) {
		if(val == *itr) erase(itr);
	}
}

// print out all elements. ofc is deliminitor
template <typename T>
void List<T>::print(std::ostream& os, char ofc) const {
	for(auto itr = this->begin(); itr != this->end(); itr++) {
		os << *itr << ofc;
	}
	os << std::endl;
}

//clears elements in list
template <typename T>
void List<T>::clear() {
	while(!empty()) {
		pop_front();
	}
}

// reverse the order of the elements
template <typename T>
void List<T>::reverse() {
	List<T> reverseList;
	reverseList.init();
	while(!this->empty()) {
		reverseList.push_front(this->back());
		this->pop_back();
	}
	while(!reverseList.empty()) {
		this->push_front(reverseList.front());
		reverseList.pop_front();
	}
}

//initialize list
template <typename T>
void List<T>::init() {
	theSize = 0;
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
}

// iterator to first element
template <typename T>
typename List<T>::iterator List<T>::begin() {
	return iterator(head->next);
}

// const_iterator to first element
template <typename T>
typename List<T>::const_iterator List<T>::begin() const {
	return const_iterator(head->next);
}

// end marker iterator
template <typename T>
typename List<T>::iterator List<T>::end() {
	return iterator(tail);
}

// end marker const_iterator
template <typename T>
typename List<T>::const_iterator List<T>::end() const {
	return const_iterator(tail);
}

// insert val ahead of itr
template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, const T& val) {
	Node *p = itr.current;
	++theSize;
	return iterator(p->prev = p->prev->next = new Node{val, p->prev, p});
}

// move version of insert
template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, T && val) {
	Node * p = itr.current;
	++theSize;
	return iterator(p->prev = p->prev->next = new Node{std::move(val), p->prev, p});
}

// erase one element
template <typename T>
typename List<T>::iterator List<T>::erase(iterator itr) {
	Node *p = itr.current;
	iterator retVal(p->next);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	--theSize;
	return retVal;
}

// erase [start, end)
template <typename T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end) {
	for(iterator itr = start; itr != end; ) {
		itr = erase(itr);
	}
	return end;
}

// overloading comparison operators
template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs) {
	if(lhs.size() == rhs.size()) {
		auto rItr = rhs.begin();
		for(auto lItr = lhs.begin(); lItr != lhs.end(); lItr++) {
			if(*lItr != *rItr) return false;
			rItr++;
		}
		return true;
	} else {
		return false;
	}
}

template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs) {
	return !(lhs == rhs);
}

// overloading output operator
template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &l) {
	for(auto itr = l.begin(); itr != l.end(); itr++) {
		os << *itr << " ";
	}
	os << std::endl;
	return os;
}
