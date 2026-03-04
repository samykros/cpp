#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>

static bool parseArgs(int argc, char** argv, std::vector<int>& v, std::deque<int>& d) {
	if (argc < 2)
		return false;

	for (int i = 1; i < argc; ++i) {
		std::string s(argv[i]);
		if (s.empty())
			return false;

		for (std::size_t j = 0; j < s.size(); ++j) {
			if (s[j] == '+' && j == 0 && s.size() > 1)
				continue;
			if (s[j] < '0' || s[j] > '9')
				return false;
		}

		long val = std::atol(s.c_str());
		if (val <= 0 || val > 2147483647L)
			return false;

		v.push_back(static_cast<int>(val));
		d.push_back(static_cast<int>(val));
	}

	return true;
}

template <typename Container>
static void printContainer(const std::string& prefix, const Container& c) {
	std::cout << prefix;
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
		std::cout << *it;
		if (it + 1 != c.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	std::vector<int> v;
	std::deque<int> d;

	if (!parseArgs(argc, argv, v, d)) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	printContainer("Before: ", v);

	std::vector<int> vCopy = v;
	std::deque<int> dCopy = d;

	std::clock_t startVec = std::clock();
	PmergeMe::sortVector(vCopy);
	std::clock_t endVec = std::clock();

	std::clock_t startDeq = std::clock();
	PmergeMe::sortDeque(dCopy);
	std::clock_t endDeq = std::clock();

	printContainer("After: ", vCopy);

	double timeVec = static_cast<double>(endVec - startVec) * 1e6 / CLOCKS_PER_SEC;
	double timeDeq = static_cast<double>(endDeq - startDeq) * 1e6 / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << v.size()
	          << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << d.size()
	          << " elements with std::deque : " << timeDeq << " us" << std::endl;

	return 0;
}

