#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

// virtual es una palabra clave en C++ que
// permite la sobrescritura de métodos (funciones, 
// makeSound) en clases derivadas. Si no usas virtual,
// el compilador siempre usará la versión de makeSound()
// de la clase base Animal, incluso si se llama a través
// de un puntero de tipo Animal* que en realidad apunta
// a un objeto Dog. Usando virtual, C++ sabe que en realidad
// debe llamar a la versión de makeSound() en la clase Dog,
// no en Animal.

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        virtual ~Animal();
        virtual void makeSound() const = 0;
        std::string getType() const;
        Brain* brain;  // Puntero a un cerebro
};

#endif
