#ifndef STACK_H
#define STACK_H

#include <list>
#include <iostream>
namespace COP4530 {

template <typename T>
class Stack {
		//friend functions
		//invokes the print() method to print
		template <typename T2>
		friend std::ostream& operator<<(std::ostream&, const Stack<T2>&);
		//returns true if the two compared stacks have the same elements, in the same order
		template <typename T2>
		friend bool operator==(const Stack<T2>& a, const Stack<T2>& b);
		//returns true if every element in stack a is less than stack b
		template <typename T2>
		friend bool operator<=(const Stack<T2>& a, const Stack<T2>& b);
		
	public:
		//zero-argument constructor
		Stack();
		//destructor
		~Stack();
		//copy constructor
		Stack(const Stack<T>&);
		//move constructor
		Stack(Stack<T>&&);
		//copy assignment operator
		Stack<T>& operator=(Stack<T>&);
		//move assignment operator
		Stack<T>& operator=(Stack<T>&&);
		//initialize stack	
		void init();
		//returns true if the Stack contains no elements, and false otherwise
		bool empty() const;
		//delete all elements from the stack
		void clear();
		//adds x to the stack (copy version)
		void push(const T& x);
		//adds x to the stack (move version)
		void push(T && x);
		//removes and discards the most recently added element of the stack
		void pop();
		//mutator that returns a reference to the most recently added element of the stack
		T& top();
		//accessor that returns the most recently added element of the stack
		const T& top() const;
		//returns the number of elements stored in the stack
		int size() const;
		//prints elements of stack with delimiter
		void print(std::ostream& os, char ofc = ' ') const;
		
	private:
		std::list<T> stackList;
		size_t theSize;
};

		#include "stack.hpp"

}
#endif
