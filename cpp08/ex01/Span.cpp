#include "Span.hpp"

#include <algorithm>
#include <limits>

Span::Span(unsigned int n) : _numbers(), _maxSize(n) {}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_numbers = other._numbers;
		_maxSize = other._maxSize;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_numbers.push_back(value);
}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (std::size_t i = 1; i < tmp.size(); ++i) {
		unsigned int diff = static_cast<unsigned int>(tmp[i] - tmp[i - 1]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(*maxIt - *minIt);
}


