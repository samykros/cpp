#include "AMateria.hpp"
#include "Materia.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

// Una interfaz es una clase abstracta que contiene
// solo las declaraciones de los métodos (sin
// implementación) y no puede ser instanciada directamente.
// Por eso no tiene constructor

// El propósito de una interfaz es asegurar que todas
// las clases que la implementen proporcionen un conjunto
// común de funcionalidades, pero con su propia implementación
// específica.

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}