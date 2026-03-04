#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

int main() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);

	try {
		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	try {
		std::list<int>::iterator it = easyfind(l, 42);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}


