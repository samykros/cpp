#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &o);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &o);
    ~RobotomyRequestForm();

private:
    std::string _target;
    virtual void executeAction() const;
};

#endif
