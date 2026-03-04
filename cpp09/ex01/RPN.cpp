#include "RPN.hpp"

#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string& expression) const {
	std::stack<int> st;

	for (std::size_t i = 0; i < expression.size(); ++i) {
		char c = expression[i];
		if (c == ' ' || c == '\t')
			continue;

		if (c >= '0' && c <= '9') {
			st.push(c - '0');
		} else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (st.size() < 2)
				throw std::runtime_error("Error");
			int b = st.top(); st.pop();
			int a = st.top(); st.pop();
			int res = 0;
			if (c == '+')
				res = a + b;
			else if (c == '-')
				res = a - b;
			else if (c == '*')
				res = a * b;
			else if (c == '/') {
				if (b == 0)
					throw std::runtime_error("Error");
				res = a / b;
			}
			st.push(res);
		} else {
			throw std::runtime_error("Error");
		}
	}

	if (st.size() != 1)
		throw std::runtime_error("Error");

	return st.top();
}

