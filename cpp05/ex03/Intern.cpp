#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}


AForm* Intern::createShrubbery(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*creators[3])(const std::string &) const = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }

    std::cout << "Intern couldn’t create form because form name does not exist"
              << std::endl;
    return NULL;
}
