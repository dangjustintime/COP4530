#include "stack.h"
#include <iostream>

using namespace COP4530;

int main() {
	//default constructor
	std::cout << "\n---------DEFAULT CONSTRUCTOR---------" << std::endl;
	Stack<int> a;
	Stack<int> b;
	Stack<int> c;
	Stack<int> d;	
	a.print(std::cout);	
	b.print(std::cout);
	c.print(std::cout);
	d.print(std::cout);

	std::cout << "a.theSize = " <<a.size() << std::endl;	
	std::cout << "b.top() = " << b.top() << std::endl;
	//****************CONSTUCTOR WORKS************
	
	//destructor
	std::cout << "\n---------DESTRUCTOR---------" << std::endl;
	for(int i = 0; i < 3; i++) {
		Stack<int> e;
		e.push(i);
	}
	//e.print(std::cout);
	//******************DESTRUCTOR WORKS***********************

	//copy constructor
	std::cout << "\n---------COPY CONSTRUCTOR---------" << std::endl;
	for(int i = 0; i < 15; i++) {
		a.push(i);
	}
	Stack<int> e(a);
	a.print(std::cout);
	e.print(std::cout);
	//**********************COPY CONSTRUCTOR WORKS**************

	//move constructor	
	std::cout << "\n---------MOVE CONSTRUCTOR---------" << std::endl;
	Stack<int> f(std::move(e));
	std::cout << "stack e = ";
	e.print(std::cout);
	std::cout << "stack f = ";
	f.print(std::cout);
	//***********************MOVE CONSTRUCTOR WORKS*********************

	//copy assignment operator	
	std::cout << "\n--------COPY ASSIGNMENT OPERATOR---------" << std::endl;
	std::cout << "stack e = ";
	e.print(std::cout);
	e = a;
	std::cout << "stack a = ";
	a.print(std::cout);	
	std::cout << "stack e = ";
	e.print(std::cout);
	//************************COPY ASSIGNMENT OPERATOR WORLKS**************

	//move assignment operator	
	std::cout << "\n---------MOVE ASSIGNMENT OPERATOR---------" << std::endl;
	for(int i = 0; i < 8; i++) {
		int i2 = i -3;
		b.push(i2);
	}
	std::cout << "stack a = ";
	a.print(std::cout);
	std::cout << "stack b = ";
	b.print(std::cout);
	b = std::move(a);
	std::cout << "stack a = ";
	a.print(std::cout);
	std::cout << "stack b = ";
	b.print(std::cout);
	//************************MOVE ASSIGNMENT OPERATOR WORKS********************

	//empty()	
	std::cout << "\n---------EMPTY---------" << std::endl;
	std::cout << "is a empty? " << a.empty() << std::endl;
	std::cout << "is d empty? " << d.empty() << std::endl;
	///**************************EMPTY WORKS***********************
	
	//clear()
	std::cout << "\n---------CLEAR---------" << std::endl;
	std::cout << "stack a = ";
	a.print(std::cout);
	std::cout << "a.theSize = " << a.size() << std::endl;
	a.clear();
	std::cout << "stack a = ";
	a.print(std::cout);
	std::cout << "a.theSize = " << a.size() << std::endl;
	//**************************CLEAR WORKSS********************

	//push(const T& x)
	std::cout << "\n---------PUSH---------" << std::endl;
	a.print(std::cout);
	b.print(std::cout);
	c.print(std::cout);
	d.print(std::cout);
	std::cout << "a.theSize = " << a.size() << std::endl;
	std::cout << "b.theSize = " << b.size() << std::endl;
	std::cout << "c.theSize = " << c.size() << std::endl;
	std::cout << "d.theSize = " << d.size() << std::endl;
	for(int i = 0; i < 10; i++) {
		int i2 = i + 1;
		int i3 = i + 2;
		int i4 = i + 3;
		a.push(i);
		b.push(i2);
		c.push(i3);
		d.push(i4);
	}
	a.print(std::cout);	
	std::cout << "a.theSize = " << a.size() << std::endl;
	b.print(std::cout);
	std::cout << "b.theSize = " << b.size() << std::endl;
	c.print(std::cout);
	std::cout << "c.theSize = " << c.size() << std::endl;
	d.print(std::cout);
	std::cout << "d.theSize = " << d.size() << std::endl;
	//***************************PUSH WORKS**************************

	//push(T && x)
	std::cout << "\n---------PUSH MOVE VERSION---------" << std::endl;
	std::cout << "stack c = ";
	c.print(std::cout);
	std::cout << "c.theSize = " << c.size() << std::endl;
	std::list<int> theList = {-1, -1, -1};
	std::cout << "the list = ";
	for(auto i = theList.begin(); i != theList.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	
	for(auto i = theList.begin(); i != theList.end(); i++) {
		c.push(std::move(*i));
	}

	std::cout << "stack c = ";
	c.print(std::cout);
	std::cout << "c.theSize = " << c.size() << std::endl;
	std::cout << "the list = ";
	for(auto i = theList.begin(); i != theList.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	//************************push move works******************
	
	//pop()
	std::cout << "\n---------POP---------" << std::endl;
	std::cout << "stack a = ";
	a.print(std::cout);
	std::cout << "a.theSize = " << a.size() << std::endl;
	for(int i = 0; i < 2; i++) {
		a.pop();
	}
	std::cout << "stack a = ";
	a.print(std::cout);
	std::cout << "a.theSize = " << a.size() << std::endl;
	//**************************POP WORKS*****************************	

	//top()
	std::cout << "\n---------TOP---------" << std::endl;
	std::cout << "stack a = ";
	a.print(std::cout);
	std::cout << "top of a = " << a.top() << std::endl;
	std::cout << "stack b = ";
	b.print(std::cout);
	std::cout << "top of b = " << b.top() << std::endl;
	std::cout << "stack c = ";
	c.print(std::cout);
	std::cout << "top of c = " << c.top() << std::endl;
	std::cout << "stack c = ";
	c.pop();
	c.pop();
	c.pop();
	c.pop();
	c.pop();
	c.pop();
	c.print(std::cout);
	std::cout << "top of c = " << c.top() << std::endl;
	//****************************TOP WORKS*********************
	
	//const top()
	std::cout << "\n---------CONST TOP---------" << std::endl;
	const Stack<int> g(c);
	std::cout << "stack g = ";
	g.print(std::cout);
	std::cout << "top of g = " << g.top() << std::endl;
	//***************************CONST TOP WORKS*******************
	
	//size()
	std::cout << "\n---------SIZE---------" << std::endl;
	std::cout << "stack b = ";
	b.print(std::cout);
	std::cout << "b.theSize = " << b.size() << std::endl;
	//************************SIZE WORKS*****************	

	//print()
	std::cout << "\n---------PRINT---------" << std::endl;
	a.print(std::cout);	
	b.print(std::cout, '+');
	c.print(std::cout, '#');
	d.print(std::cout, '*');
	//*****************PRINT WORKS************************
	
	//operator<<
	std::cout << "\n---------OPERATOR<<---------" << std::endl;
	std::cout << d;
	//***********************OPERATOR<< WORKS************************

	//operator==
	std::cout << "\n---------OPERATOR==---------" << std::endl;
	a = b;
	std::cout << "stack a = ";
	a.print(std::cout);
	std::cout << "stack b = ";
	b.print(std::cout);
	std::cout << "stack c = ";
	c.print(std::cout);
	std::cout << "a == b? " << (a == b) << std::endl;
	std::cout << "a == c? " << (a == c) << std::endl;
	//**********************OPERATOR== WORKS*********************
	
	//operator!=
	std::cout << "\n---------OPERATOR!=---------" << std::endl;
	std::cout << "a != b? " << (a != b) << std::endl;
	std::cout << "a != c? " << (a != c) << std::endl;
	//**********************OPERATOR!= WORKS*********************
	

	//operator<=
	std::cout << "\n---------OPERATOR<=---------" << std::endl;
	c = a;
	d = a;
	c.pop();
	c.push(99);
	d.pop();
	d.push(-1);
	std::cout << "stack a = ";
	a.print(std::cout);
	std::cout << "stack b = ";
	b.print(std::cout);
	std::cout << "stack c = ";
	c.print(std::cout);
	std::cout << "stack d = ";
	d.print(std::cout);
	std::cout << " a <= b?" << (a <= b) << std::endl;
	std::cout << " a <= c?" << (a <= c) << std::endl;
	std::cout << " a <= d?" << (a <= d) << std::endl;
	//*******************************OPERATOR<= WORKS*********************
	
	
	return 0;
};
