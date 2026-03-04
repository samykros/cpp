#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &t)
: AForm("ShrubberyCreationForm", 145, 137), _target(t) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &o)
: AForm(o), _target(o._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &o)
{
    if (this != &o)
    {
        AForm::operator=(o);
        _target = o._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream out((_target + "_shrubbery").c_str());
    out <<
"       _-_\n"
"    /~~   ~~\\\n"
" /~~         ~~\\\n"
"{               }\n"
" \\  _-     -_  /\n"
"   ~  \\\\ //  ~\n"
"_- -   | | _- _\n"
"  _ -  | |   -_\n"
"      // \\\\\n";
}
