#include "base.hpp"

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        Base* obj = generate();
        std::cout << "Using pointer: ";
        identify(obj);
        std::cout << "Using reference: ";
        identify(*obj);
        delete obj; // liberar memoria
        std::cout << "\n";
    }
    return 0;
}
