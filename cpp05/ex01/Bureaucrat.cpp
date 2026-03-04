#include "Bureaucrat.hpp"
#include "Form.hpp" // nuevo

// ===================
//  Constructors
// ===================

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    // Opcional: asegurar que el grade es válido
    // checkGrade(_grade);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade)
{
    checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade)
{
    // Nada extra
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        // _name es const, no se puede reasignar
        // sólo copiamos el grade
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    // Nada especial
}

// ===================
//  Private helpers
// ===================

void Bureaucrat::checkGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

// ===================
//  Getters
// ===================

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

// ===================
//  Grade modifiers
// ===================

void Bureaucrat::incrementGrade()
{
    // 1 es el máximo → si restamos 1 desde 1, nos pasamos
    checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    // 150 es el mínimo → si sumamos 1 desde 150, nos pasamos
    checkGrade(_grade + 1);
    _grade++;
}

// ===================
//  Exceptions
// ===================

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low";
}

// ===================
//  Operator<<
// ===================

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << getName() << " couldn’t sign " << form.getName()
                  << " because " << e.what() << "." << std::endl;
    }
}
