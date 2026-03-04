#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &o);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &o);
    ~ShrubberyCreationForm();

private:
    std::string _target;
    virtual void executeAction() const;
};

#endif
