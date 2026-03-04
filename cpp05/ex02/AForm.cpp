#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
: _name("DefaultAForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gs, int ge)
: _name(name), _isSigned(false), _gradeToSign(gs), _gradeToExecute(ge)
{
    checkGrade(_gradeToSign);
    checkGrade(_gradeToExecute);
}

AForm::AForm(const AForm &o)
: _name(o._name), _isSigned(o._isSigned), _gradeToSign(o._gradeToSign), _gradeToExecute(o._gradeToExecute) {}

AForm &AForm::operator=(const AForm &o)
{
    if (this != &o) _isSigned = o._isSigned;
    return *this;
}

AForm::~AForm() {}

void AForm::checkGrade(int grade) const
{
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
}

const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= _gradeToSign) _isSigned = true;
    else throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned) throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute) throw GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() { return "AForm grade is too high"; }
const char* AForm::GradeTooLowException::what() const throw() { return "AForm grade is too low"; }
const char* AForm::FormNotSignedException::what() const throw() { return "AForm is not signed"; }

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "AForm \"" << f.getName()
       << "\" | signed: " << (f.isSigned() ? "true" : "false")
       << " | grade to sign: " << f.getGradeToSign()
       << " | grade to execute: " << f.getGradeToExecute();
    return os;
}
