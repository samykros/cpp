#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
class AMateria;

// Interfaaz no tiene constructor
class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;  // Obtener el nombre del personaje
        virtual void equip(AMateria* m) = 0;  // Equipar una Materia
        virtual void unequip(int idx) = 0;  // Desequipar una Materia
        virtual void use(int idx, ICharacter& target) = 0;  // Usar una Materia en otro personaje
};

#endif
