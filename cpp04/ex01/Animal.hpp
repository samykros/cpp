#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;
        Brain* brain;  // Puntero a un cerebro
};

#endif
