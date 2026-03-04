#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
public:
    // OCF
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    // Getters
    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Actions
    void beSigned(const Bureaucrat &b);
    void execute(Bureaucrat const & executor) const;

    // Exceptions
    class GradeTooHighException : public std::exception {
    public: virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public: virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public: virtual const char* what() const throw();
    };

protected:
    // cada form concreta implementa su acción real
    virtual void executeAction() const = 0;

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

    void checkGrade(int grade) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
