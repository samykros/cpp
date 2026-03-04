#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &t)
: AForm("PresidentialPardonForm", 25, 5), _target(t) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &o)
: AForm(o), _target(o._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &o)
{
    if (this != &o)
    {
        AForm::operator=(o);
        _target = o._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}
