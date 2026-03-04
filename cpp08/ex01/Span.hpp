#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int value);

	template <typename Iterator>
	void addNumber(Iterator first, Iterator last) {
		for (Iterator it = first; it != last; ++it) {
			if (_numbers.size() >= _maxSize)
				throw std::runtime_error("Span is full");
			_numbers.push_back(*it);
		}
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

private:
	std::vector<int> _numbers;
	unsigned int     _maxSize;
};

#endif


