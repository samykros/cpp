#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &o);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &o);
    ~PresidentialPardonForm();

private:
    std::string _target;
    virtual void executeAction() const;
};

#endif
