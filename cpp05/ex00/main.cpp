#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        std::cout << "Incrementing grade..." << std::endl;
        a.incrementGrade(); // 2 -> 1
        std::cout << a << std::endl;

        std::cout << "Incrementing grade again (should throw)..." << std::endl;
        a.incrementGrade(); // 1 -> error
        std::cout << a << std::endl; // no se ejecuta
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----" << std::endl;

    try
    {
        std::cout << "Trying to create Bob with grade 151..." << std::endl;
        Bureaucrat b("Bob", 151); // debe lanzar Low
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught while creating Bob: " << e.what() << std::endl;
    }

    std::cout << "-----" << std::endl;

    try
    {
        Bureaucrat c("Charlie", 149);
        std::cout << c << std::endl;

        std::cout << "Decrementing grade..." << std::endl;
        c.decrementGrade(); // 149 -> 150
        std::cout << c << std::endl;

        std::cout << "Decrementing grade again (should throw)..." << std::endl;
        c.decrementGrade(); // 150 -> error
        std::cout << c << std::endl; // no se ejecuta
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught with Charlie: " << e.what() << std::endl;
    }

    return 0;
}
