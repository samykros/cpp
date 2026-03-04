#include "Form.hpp"
#include "Bureaucrat.hpp"

// ===================
//  Constructors
// ===================

Form::Form() : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    checkGrade(_gradeToSign);
    checkGrade(_gradeToExecute);
}

Form::Form(const Form &other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        // const fields no se pueden reasignar
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
}

// ===================
//  Private helper
// ===================

void Form::checkGrade(int grade) const
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

// ===================
//  Getters
// ===================

const std::string &Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

// ===================
//  beSigned
// ===================

void Form::beSigned(const Bureaucrat &b)
{
    // OJO: grade 1 es mejor. Para firmar: grade <= required
    if (b.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

// ===================
//  Exceptions
// ===================

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

// ===================
//  Operator<<
// ===================

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form \"" << f.getName() << "\""
       << " | signed: " << (f.isSigned() ? "true" : "false")
       << " | grade to sign: " << f.getGradeToSign()
       << " | grade to execute: " << f.getGradeToExecute();
    return os;
}
