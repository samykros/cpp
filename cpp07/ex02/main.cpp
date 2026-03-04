#include "Array.hpp"

int main()
{
	Array<int> a(5);

	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = static_cast<int>(i);

	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << a[i] << std::endl;

	return 0;
}
