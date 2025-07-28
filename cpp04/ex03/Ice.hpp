#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria
{
    public:
        Ice() : AMateria("ice") {}

        AMateria* clone() const
        {
            return new Ice();
        }

        void use(ICharacter& target)
        {
            std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
        }
};

#endif
