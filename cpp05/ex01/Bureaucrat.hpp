#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form; // nuevo

class Bureaucrat
{
public:
    void signForm(Form &form) const; // nuevo

    // Orthodox Canonical Form
    Bureaucrat();                              // opcionalmente lo puedes hacer private si no quieres que se use
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    // Getters
    const std::string &getName() const;
    int getGrade() const;

    // Modificadores
    void incrementGrade(); // 3 -> 2
    void decrementGrade(); // 3 -> 4

    // Excepciones anidadas
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

private:
    const std::string _name;
    int _grade;

    void checkGrade(int grade); // helper interno
};

// Operator de inserción
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
