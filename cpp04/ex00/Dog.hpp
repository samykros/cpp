#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

// La palabra clave override es opcional, pero es útil.
// Indica que estamos sobrescribiendo un método de la
// clase base. Si por error no coinciden los
// método (nombre, tipo de retorno, parámetros), el
// compilador te dará un error.

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        void makeSound() const;
};

#endif
