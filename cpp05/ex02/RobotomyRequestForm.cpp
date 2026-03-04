#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &t)
: AForm("RobotomyRequestForm", 72, 45), _target(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &o)
: AForm(o), _target(o._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &o)
{
    if (this != &o)
    {
        AForm::operator=(o);
        _target = o._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* DRILLING NOISES * bzzzzzz...\n";
    static bool seeded = false;
    if (!seeded) { std::srand(std::time(NULL)); seeded = true; }

    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed on " << _target << ".\n";
}
