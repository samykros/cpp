#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* f;

    f = someRandomIntern.makeForm("robotomy request", "Bender");
    delete f;

    f = someRandomIntern.makeForm("shrubbery creation", "home");
    delete f;

    f = someRandomIntern.makeForm("does not exist", "test");
    delete f;
}
