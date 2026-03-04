#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 50);
    Bureaucrat low("Low", 150);

    ShrubberyCreationForm s("home");
    RobotomyRequestForm r("Bender");
    PresidentialPardonForm p("Arthur Dent");

    // Intentar ejecutar sin firmar
    boss.executeForm(s);

    // Firmar y ejecutar
    boss.signForm(s);
    boss.executeForm(s);

    mid.signForm(r);        // debería poder firmar (50 <= 72)
    mid.executeForm(r);     // no debería poder ejecutar (50 > 45) -> fail
    boss.executeForm(r);    // boss sí ejecuta

    low.signForm(p);        // fail (150 > 25)
    boss.signForm(p);       // ok
    boss.executeForm(p);    // ok

    return 0;
}
