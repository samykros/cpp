#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
// declarado asi para evitar la mierda circular de headers
class ICharacter;

class AMateria
{
    protected:
        std::string type;  // ice o cure

    public:
        AMateria(std::string const & type) : type(type) {}
        virtual ~AMateria() {}

        std::string const & getType() const { return type; }

        // Métodos virtuales puros que las clases derivadas deben implementar
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0;
};

#endif
