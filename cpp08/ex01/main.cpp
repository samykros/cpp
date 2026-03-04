#include "Span.hpp"

#include <iostream>
#include <cstdlib>

int main() {
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		Span big(10000);
		for (int i = 0; i < 10000; ++i)
			big.addNumber(i);
		std::cout << "Big shortest: " << big.shortestSpan() << std::endl;
		std::cout << "Big longest: " << big.longestSpan() << std::endl;
	}

	return 0;
}


