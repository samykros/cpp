#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // forward declaration (para evitar include circular)

class Form
{
public:
    // OCF
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    // Getters
    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Acción
    void beSigned(const Bureaucrat &b);

    // Excepciones
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
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

    void checkGrade(int grade) const;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
