#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Materia.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
    private:
        std::string name;  // nombre personaje
        AMateria* inventory[4];  // inventario (máximo 4 Materias)

    public:
        Character(std::string const & name);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
