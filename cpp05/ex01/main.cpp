#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== OK signing ===" << std::endl;
    {
        Bureaucrat boss("Boss", 1);
        Form tax("Tax", 10, 50);

        std::cout << boss << std::endl;
        std::cout << tax << std::endl;

        boss.signForm(tax);
        std::cout << tax << std::endl;
    }

    std::cout << "\n=== Too low to sign ===" << std::endl;
    {
        Bureaucrat intern("Intern", 150);
        Form secret("Secret", 42, 42);

        std::cout << intern << std::endl;
        std::cout << secret << std::endl;

        intern.signForm(secret);
        std::cout << secret << std::endl;
    }

    std::cout << "\n=== Invalid Form grades ===" << std::endl;
    try
    {
        Form bad("Bad", 0, 10);
        std::cout << bad << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    try
    {
        Form bad2("Bad2", 10, 151);
        std::cout << bad2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
