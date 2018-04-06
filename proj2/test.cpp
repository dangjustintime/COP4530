#include "List.h"


int main() {
	cop4530::List<int> list1;
	for(int i = 0; i < 10; i++) {
		list1.push_back(i);
	}
	std::cout << "***********push_back************\n";
	std::cout << "list1 " << list1 << std::endl;

	std::cout << "***********explicit constructor***********\n";
	cop4530::List<int> list2(3, 8);
	std::cout << "list2 " << list2 << std::endl;

	std::cout << "****pop_front****\n";
	list1.pop_front();
	std::cout << "list1 " << list1 << std::endl;
	
	std::cout << "****pop_back****\n";
	list1.pop_back();
	std::cout << "list1 " << list1 << std::endl;

	
	std::cout << "****push_front****\n";
	list1.push_front(7);
	std::cout << "list1 " << list1 << std::endl;


	std::cout << "****remove****\n";
	list1.remove(5);
	std::cout << "list1 " << list1 << std::endl;

	std::cout << "****size****\n";
	int num = list1.size();
	std::cout << "list1 " << num << std::endl;

	std::cout << "****empty****\n";
	std::cout << "list1 " << list1.empty() << std::endl;

	std::cout << "****reverse****\n";
	list1.reverse();
	std::cout << "list1 " << list1 << std::endl;

	std::cout << "****clear****\n";
	std::cout << "list1 " << list1.size() << std::endl;
	list1.clear();
	std::cout << "list1 " << list1.size() << std::endl;

	std::cout << "*****assignment operaotr********\n";
	cop4530::List<int> list3 = list2;
	std::cout << "list2 " << list2 << std::endl;
	std::cout << "list3 " << list3 << std::endl;


	std::cout << "******boolean operators*****\n";
	list1.push_front(77);	
	list1.push_front(7);
	list1.push_front(-19);
	list1.push_front(64);
	list1.push_front(0);
	std::cout << "list1 " << list1 << std::endl;
	std::cout << "list1 == list2 ";
	bool b = (list1 == list2); 
	std::cout << b << " " << std::endl;
	std::cout << "list3 == list2 ";
	b = (list3 == list2);
	std::cout << b << " " << std::endl;
	std::cout << "list1 != list2 ";
	b = (list1 != list2);
	std::cout << b << " " << std::endl;
	std::cout << "list3 != list2 ";
	b = (list3 != list2); 
	std::cout << b << " " << std::endl;

	std::cout << "*******print function*******\n";
	list1.print(std::cout, '$');
	
	return 0;
}
