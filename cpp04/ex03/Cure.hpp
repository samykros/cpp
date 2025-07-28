#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria
{
    public:
        Cure() : AMateria("cure") {}

        AMateria* clone() const
        {
            return new Cure();
        }

        void use(ICharacter& target)
        {
            std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
        }
};

#endif
